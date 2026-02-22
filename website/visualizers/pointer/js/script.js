document.addEventListener('DOMContentLoaded', () => {
    const memorySvg = document.getElementById('memory-svg');
    const stepBtn = document.getElementById('step-btn');
    const resetBtn = document.getElementById('reset-btn');
    const statusMsg = document.getElementById('status-msg');

    let currentStep = 0;
    let memory = {}; // { address: { name, value, isPointer } }
    let variables = {}; // { name: address }

    const steps = [
        {
            line: 2,
            msg: 'Declaring integer "a" and initializing it to 10.',
            action: () => {
                const addr = '0x7ffd';
                variables['a'] = addr;
                memory[addr] = { name: 'a', value: 10, isPointer: false };
            }
        },
        {
            line: 3,
            msg: 'Declaring integer "b" and initializing it to 20.',
            action: () => {
                const addr = '0x7ffe';
                variables['b'] = addr;
                memory[addr] = { name: 'b', value: 20, isPointer: false };
            }
        },
        {
            line: 4,
            msg: 'Declaring integer pointer "p". It currently points to nowhere (uninitialized).',
            action: () => {
                const addr = '0x8000';
                variables['p'] = addr;
                memory[addr] = { name: 'p', value: null, isPointer: true };
            }
        },
        {
            line: 5,
            msg: 'Assigning the address of "a" (&a) to pointer "p".',
            action: () => {
                const pAddr = variables['p'];
                memory[pAddr].value = variables['a'];
            }
        },
        {
            line: 6,
            msg: 'Dereferencing "p" (*p) to change the value at the address it points to (a) to 100.',
            action: () => {
                const pAddr = variables['p'];
                const targetAddr = memory[pAddr].value;
                memory[targetAddr].value = 100;
            }
        },
        {
            line: 7,
            msg: 'Assigning the address of "b" (&b) to pointer "p".',
            action: () => {
                const pAddr = variables['p'];
                memory[pAddr].value = variables['b'];
            }
        },
        {
            line: 8,
            msg: 'Dereferencing "p" (*p) to change the value at the address it points to (b) to 200.',
            action: () => {
                const pAddr = variables['p'];
                const targetAddr = memory[pAddr].value;
                memory[targetAddr].value = 200;
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
        memory = {};
        variables = {};
        updateUI();
    }

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

        // Update SVG
        renderMemory();

        if (currentStep >= steps.length) {
            stepBtn.disabled = true;
        } else {
            stepBtn.disabled = false;
        }
    }

    function renderMemory() {
        memorySvg.innerHTML = `
            <defs>
                <marker id="arrowhead" markerWidth="10" markerHeight="7"
                refX="9" refY="3.5" orient="auto">
                    <polygon points="0 0, 10 3.5, 0 7" fill="#e74c3c" />
                </marker>
            </defs>
        `;

        const startX = 50;
        const startY = 50;
        const cellWidth = 120;
        const cellHeight = 60;
        const gap = 20;

        const sortedAddresses = Object.keys(memory).sort();

        sortedAddresses.forEach((addr, index) => {
            const x = startX;
            const y = startY + index * (cellHeight + gap);
            const data = memory[addr];

            // Draw Box
            const rect = document.createElementNS("http://www.w3.org/2000/svg", "rect");
            rect.setAttribute("x", x);
            rect.setAttribute("y", y);
            rect.setAttribute("width", cellWidth);
            rect.setAttribute("height", cellHeight);
            rect.setAttribute("class", "memory-cell");
            memorySvg.appendChild(rect);

            // Draw Label (Variable Name)
            const label = document.createElementNS("http://www.w3.org/2000/svg", "text");
            label.setAttribute("x", x - 10);
            label.setAttribute("y", y + cellHeight/2);
            label.setAttribute("text-anchor", "end");
            label.setAttribute("class", "memory-label");
            label.textContent = data.name;
            memorySvg.appendChild(label);

            // Draw Address
            const addrText = document.createElementNS("http://www.w3.org/2000/svg", "text");
            addrText.setAttribute("x", x + cellWidth + 5);
            addrText.setAttribute("y", y + 15);
            addrText.setAttribute("class", "memory-address");
            addrText.textContent = addr;
            memorySvg.appendChild(addrText);

            // Draw Value
            const valText = document.createElementNS("http://www.w3.org/2000/svg", "text");
            valText.setAttribute("x", x + cellWidth/2);
            valText.setAttribute("y", y + cellHeight/2 + 5);
            valText.setAttribute("text-anchor", "middle");
            valText.setAttribute("class", "memory-value");

            if (data.isPointer) {
                valText.textContent = data.value ? data.value : 'NULL';

                // Draw Arrow if pointing to something
                if (data.value && memory[data.value]) {
                    const targetIdx = sortedAddresses.indexOf(data.value);
                    if (targetIdx !== -1) {
                        drawArrow(x + cellWidth, y + cellHeight/2, targetIdx, sortedAddresses.length);
                    }
                }
            } else {
                valText.textContent = data.value;
            }
            memorySvg.appendChild(valText);
        });
    }

    function drawArrow(fromX, fromY, targetIdx, totalCells) {
        const startX = 50;
        const startY = 50;
        const cellWidth = 120;
        const cellHeight = 60;
        const gap = 20;

        const toX = startX + cellWidth;
        const toY = startY + targetIdx * (cellHeight + gap) + cellHeight/2;

        const path = document.createElementNS("http://www.w3.org/2000/svg", "path");
        // Create a curved path to avoid overlapping with boxes too much
        const cp1X = fromX + 50;
        const cp1Y = fromY;
        const cp2X = toX + 50;
        const cp2Y = toY;

        path.setAttribute("d", `M ${fromX} ${fromY} C ${cp1X} ${cp1Y}, ${cp2X} ${cp2Y}, ${toX} ${toY}`);
        path.setAttribute("class", "pointer-arrow");
        memorySvg.appendChild(path);
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
