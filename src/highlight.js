import Prism from 'prismjs';
import 'prismjs/components/prism-c.js';
import 'prismjs/components/prism-cpp.js';

export function initHighlighting() {
  // Run Prism on all code blocks
  Prism.highlightAll();

  // Add copy buttons
  const codeBlocks = document.querySelectorAll('pre');
  codeBlocks.forEach((block) => {
    // Only add if it contains a code element with language class
    const code = block.querySelector('code');
    if (!code) return;

    // Create wrapper for relative positioning if not already there
    if (getComputedStyle(block).position === 'static') {
      block.style.position = 'relative';
    }

    const copyBtn = document.createElement('button');
    copyBtn.className = 'copy-btn';
    copyBtn.setAttribute('aria-label', 'Copy code');
    copyBtn.innerHTML = `
      <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round">
        <rect x="9" y="9" width="13" height="13" rx="2" ry="2"></rect>
        <path d="M5 15H4a2 2 0 0 1-2-2V4a2 2 0 0 1 2-2h9a2 2 0 0 1 2 2v1"></path>
      </svg>
      <span class="copy-tooltip">Salin</span>
    `;

    copyBtn.addEventListener('click', async () => {
      const text = code.innerText;
      try {
        await navigator.clipboard.writeText(text);

        // Success feedback
        const tooltip = copyBtn.querySelector('.copy-tooltip');
        const originalText = tooltip.innerText;
        tooltip.innerText = 'Tersalin!';
        copyBtn.classList.add('copied');

        setTimeout(() => {
          tooltip.innerText = originalText;
          copyBtn.classList.remove('copied');
        }, 2000);
      } catch (err) {
        console.error('Failed to copy: ', err);
      }
    });

    block.appendChild(copyBtn);
  });
}
