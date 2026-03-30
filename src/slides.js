export function initSlides() {
  const slides = document.querySelectorAll('.slide');
  const total = slides.length;
  let current = 0;

  function updateUI() {
    const counterEl = document.getElementById('counter');
    if (counterEl) {
      counterEl.textContent = (current + 1) + ' / ' + total;
    }
    const progressEl = document.getElementById('progress');
    if (progressEl) {
      progressEl.style.width = ((current + 1) / total * 100) + '%';
    }
  }

  function updateHash() {
    window.location.hash = (current + 1).toString();
  }

  function goToSlide(index, updateURL = true) {
    if (index < 0 || index >= total) return;

    slides.forEach((slide, i) => {
      if (i < index) {
        slide.className = 'slide prev';
      } else if (i === index) {
        slide.className = 'slide active';
      } else {
        slide.className = 'slide';
      }
    });

    current = index;
    updateUI();
    if (updateURL) {
      updateHash();
    }
  }

  function navigate(dir) {
    goToSlide(current + dir);
  }

  // Event Listeners
  const prevBtn = document.getElementById('prevBtn');
  const nextBtn = document.getElementById('nextBtn');

  if (prevBtn) prevBtn.addEventListener('click', () => navigate(-1));
  if (nextBtn) nextBtn.addEventListener('click', () => navigate(1));

  document.querySelectorAll('.toc-item').forEach(item => {
    item.addEventListener('click', () => {
      const slideIdx = parseInt(item.getAttribute('data-slide'));
      goToSlide(slideIdx);
    });
  });

  // Keyboard support
  document.addEventListener('keydown', e => {
    if (e.key === 'ArrowRight' || e.key === ' ') navigate(1);
    if (e.key === 'ArrowLeft') navigate(-1);
  });

  // Touch support
  let touchStartX = 0;
  document.addEventListener('touchstart', e => {
    touchStartX = e.touches[0].clientX;
  }, { passive: true });

  document.addEventListener('touchend', e => {
    const touchEndX = e.changedTouches[0].clientX;
    const diff = touchStartX - touchEndX;
    if (Math.abs(diff) > 50) {
      navigate(diff > 0 ? 1 : -1);
    }
  }, { passive: true });

  // Hash change support
  window.addEventListener('hashchange', () => {
    const hash = parseInt(window.location.hash.substring(1));
    if (!isNaN(hash) && hash > 0 && hash <= total) {
      goToSlide(hash - 1, false);
    }
  });

  // Initial slide from hash
  const initialHash = parseInt(window.location.hash.substring(1));
  if (!isNaN(initialHash) && initialHash > 0 && initialHash <= total) {
    goToSlide(initialHash - 1, false);
  } else {
    updateUI();
  }

  // Return goToSlide for any slide-specific needs
  return { goToSlide, navigate };
}
