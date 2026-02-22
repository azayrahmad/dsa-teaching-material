document.addEventListener('DOMContentLoaded', () => {
    const memorySvg = document.getElementById('memory-svg');
    const memoryGrid = document.getElementById('memory-grid');
    const stepBtn = document.getElementById('step-btn');
    const resetBtn = document.getElementById('reset-btn');
    const statusMsg = document.getElementById('status-msg');
    const tabBtns = document.querySelectorAll('.tab-btn');
    const tabContents = document.querySelectorAll('.tab-content');

    // Configuration
    const MEMORY_SIZE = 64; // 64 bytes
    const INT_SIZE = 4;
    const PTR_SIZE = 4;
    const START_ADDR = 0x1000;

    let currentStep = 0;

    // Memory state: Uint8Array for bytes
    let memoryBytes = new Uint8Array(MEMORY_SIZE);

    // Variable metadata
    let variables = {}; // { name: { addr, size, colorClass, isPointer, isArray, length } }

    // Helper: Get hex string for address
    const toHex = (addr) => '0x' + addr.toString(16).toUpperCase().padStart(4, '0');
    const toHexByte = (val) => val.toString(16).toUpperCase().padStart(2, '0');

    // Helper: Set multi-byte value (Little Endian)
    function setMemoryValue(addr, value, size) {
        const offset = addr - START_ADDR;
        for (let i = 0; i < size; i++) {
            memoryBytes[offset + i] = (value >> (i * 8)) & 0xFF;
        }
    }

    // Helper: Get multi-byte value (Little Endian)
    function getMemoryValue(addr, size) {
        const offset = addr - START_ADDR;
        let value = 0;
        for (let i = 0; i < size; i++) {
            value |= (memoryBytes[offset + i] << (i * 8));
        }
        return value;
    }

    const steps = [
        {
            line: 2,
            msg: 'Declaring integer "a" (4 bytes) and initializing it to 10.',
            action: () => {
                const addr = START_ADDR + 4;
                variables['a'] = { addr, size: INT_SIZE, colorClass: 'var-a', isPointer: false };
                setMemoryValue(addr, 10, INT_SIZE);
            }
        },
        {
            line: 3,
            msg: 'Declaring integer pointer "p" (4 bytes) and assigning it the address of "a".',
            action: () => {
                const addr = START_ADDR + 12;
                variables['p'] = { addr, size: PTR_SIZE, colorClass: 'var-p', isPointer: true };
                setMemoryValue(addr, variables['a'].addr, PTR_SIZE);
            }
        },
        {
            line: 4,
            msg: 'Declaring integer array "arr" of 3 elements (12 bytes total).',
            action: () => {
                const addr = START_ADDR + 24;
                variables['arr'] = { addr, size: INT_SIZE * 3, colorClass: 'var-arr', isArray: true, length: 3 };
                setMemoryValue(addr, 1, INT_SIZE);
                setMemoryValue(addr + 4, 2, INT_SIZE);
                setMemoryValue(addr + 8, 3, INT_SIZE);
            }
        },
        {
            line: 5,
            msg: 'Dereferencing "p" (*p) to change the value of "a" to 100.',
            action: () => {
                const pAddr = variables['p'].addr;
                const targetAddr = getMemoryValue(pAddr, PTR_SIZE);
                setMemoryValue(targetAddr, 100, INT_SIZE);
            }
        },
        {
            line: 6,
            msg: 'Changing the second element of the array "arr[1]" to 50.',
            action: () => {
                const arrBase = variables['arr'].addr;
                setMemoryValue(arrBase + 4, 50, INT_SIZE);
            }
        },
        {
            line: 7,
            msg: 'Updating pointer "p" to point to the address of "arr[2]".',
            action: () => {
                const pAddr = variables['p'].addr;
                const arrBase = variables['arr'].addr;
                setMemoryValue(pAddr, arrBase + 8, PTR_SIZE);
            }
        },
        {
            line: 8,
            msg: 'Dereferencing "p" (*p) to change the value of "arr[2]" to 99.',
            action: () => {
                const pAddr = variables['p'].addr;
                const targetAddr = getMemoryValue(pAddr, PTR_SIZE);
                setMemoryValue(targetAddr, 99, INT_SIZE);
            }
        },
        {
            line: 9,
            msg: 'Function returns 0. Program ends.',
            action: () => {}
        }
    ];

    function init() {
        currentStep = 0;
        memoryBytes.fill(0);
        variables = {};
        updateUI();
    }

    // Tab Switching
    tabBtns.forEach(btn => {
        btn.addEventListener('click', () => {
            tabBtns.forEach(b => b.classList.remove('active'));
            tabContents.forEach(c => c.classList.remove('active'));
            btn.classList.add('active');
            document.getElementById(btn.dataset.tab).classList.add('active');
            updateUI();
        });
    });

    function updateUI() {
        // Update Code Highlight
        document.querySelectorAll('#cpp-code span').forEach(span => {
            span.classList.remove('highlight');
        });
        if (currentStep > 0 && currentStep <= steps.length) {
            const step = steps[currentStep - 1];
            const lineEl = document.getElementById(`line-${step.line}`);
            if (lineEl) lineEl.classList.add('highlight');
            statusMsg.textContent = step.msg;
        } else if (currentStep === 0) {
            statusMsg.textContent = 'Click "Next Step" to begin.';
        }

        renderSimplified();
        renderGrid();

        stepBtn.disabled = currentStep >= steps.length;
    }

    function renderSimplified() {
        memorySvg.innerHTML = `
            <defs>
                <marker id="arrowhead" markerWidth="10" markerHeight="7"
                refX="9" refY="3.5" orient="auto">
                    <polygon points="0 0, 10 3.5, 0 7" fill="#e74c3c" />
                </marker>
            </defs>
        `;

        const startX = 60;
        const startY = 40;
        const cellWidth = 120;
        const cellHeight = 50;
        const gap = 15;

        // Flatten variables for simplified view (treat array elements as individual rows)
        let rows = [];
        Object.keys(variables).forEach(name => {
            const varInfo = variables[name];
            if (varInfo.isArray) {
                for (let i = 0; i < varInfo.length; i++) {
                    const addr = varInfo.addr + (i * INT_SIZE);
                    rows.push({
                        name: `${name}[${i}]`,
                        addr: addr,
                        value: getMemoryValue(addr, INT_SIZE),
                        isPointer: false
                    });
                }
            } else {
                rows.push({
                    name: name,
                    addr: varInfo.addr,
                    value: getMemoryValue(varInfo.addr, varInfo.size),
                    isPointer: varInfo.isPointer
                });
            }
        });

        rows.forEach((data, index) => {
            const x = startX;
            const y = startY + index * (cellHeight + gap);

            // Draw Box
            const rect = document.createElementNS("http://www.w3.org/2000/svg", "rect");
            rect.setAttribute("x", x);
            rect.setAttribute("y", y);
            rect.setAttribute("width", cellWidth);
            rect.setAttribute("height", cellHeight);
            rect.setAttribute("class", "memory-cell");
            memorySvg.appendChild(rect);

            // Label
            const label = document.createElementNS("http://www.w3.org/2000/svg", "text");
            label.setAttribute("x", x - 10);
            label.setAttribute("y", y + cellHeight/2 + 5);
            label.setAttribute("text-anchor", "end");
            label.setAttribute("class", "memory-label");
            label.textContent = data.name;
            memorySvg.appendChild(label);

            // Address
            const addrText = document.createElementNS("http://www.w3.org/2000/svg", "text");
            addrText.setAttribute("x", x + cellWidth + 5);
            addrText.setAttribute("y", y + 15);
            addrText.setAttribute("class", "memory-address");
            addrText.textContent = toHex(data.addr);
            memorySvg.appendChild(addrText);

            // Value
            const valText = document.createElementNS("http://www.w3.org/2000/svg", "text");
            valText.setAttribute("x", x + cellWidth/2);
            valText.setAttribute("y", y + cellHeight/2 + 7);
            valText.setAttribute("text-anchor", "middle");
            valText.setAttribute("class", "memory-value");

            if (data.isPointer) {
                valText.textContent = toHex(data.value);
                // Draw Arrow
                const targetAddr = data.value;
                const targetIdx = rows.findIndex(r => r.addr === targetAddr);
                if (targetIdx !== -1) {
                    drawArrow(x + cellWidth, y + cellHeight/2, targetIdx, rows.length);
                }
            } else {
                valText.textContent = data.value;
            }
            memorySvg.appendChild(valText);
        });
    }

    function drawArrow(fromX, fromY, targetIdx, totalRows) {
        const startX = 60;
        const startY = 40;
        const cellWidth = 120;
        const cellHeight = 50;
        const gap = 15;

        const toX = startX + cellWidth;
        const toY = startY + targetIdx * (cellHeight + gap) + cellHeight/2;

        const path = document.createElementNS("http://www.w3.org/2000/svg", "path");
        const cp1X = fromX + 40;
        const cp1Y = fromY;
        const cp2X = toX + 40;
        const cp2Y = toY;

        path.setAttribute("d", `M ${fromX} ${fromY} C ${cp1X} ${cp1Y}, ${cp2X} ${cp2Y}, ${toX} ${toY}`);
        path.setAttribute("class", "pointer-arrow");
        memorySvg.appendChild(path);
    }

    function renderGrid() {
        memoryGrid.innerHTML = '';
        for (let i = 0; i < MEMORY_SIZE; i++) {
            const addr = START_ADDR + i;
            const cell = document.createElement('div');
            cell.className = 'grid-cell';

            // Check if this byte belongs to any variable
            Object.keys(variables).forEach(name => {
                const varInfo = variables[name];
                if (addr >= varInfo.addr && addr < varInfo.addr + varInfo.size) {
                    cell.classList.add(varInfo.colorClass);
                }
            });

            cell.innerHTML = `
                <span class="addr">${toHex(addr)}</span>
                <span class="val">${toHexByte(memoryBytes[i])}</span>
            `;
            memoryGrid.appendChild(cell);
        }
    }

    stepBtn.addEventListener('click', () => {
        if (currentStep < steps.length) {
            steps[currentStep].action();
            currentStep++;
            updateUI();
        }
    });

    resetBtn.addEventListener('click', () => {
        init();
    });

    init();
});
