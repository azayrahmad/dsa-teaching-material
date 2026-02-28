// Language data
const translations = {
  id: {
    welcome: "Selamat Datang di Materi Struktur Data & Algoritma",
    subtitle: "Materi kuliah, slide interaktif, dan contoh kode C++.",
    topics: "Daftar Topik",
    viewSlides: "Lihat Slide",
    downloadCode: "Unduh Kode",
    home: "Beranda",
    language: "Bahasa",
    theme: "Tema",
    back: "Kembali",
    comingSoon: "Segera Hadir",
    comingSoonDesc: "Materi untuk topik ini sedang dalam proses penyusunan.",
    backHome: "Kembali ke Beranda"
  },
  en: {
    welcome: "Welcome to Data Structures & Algorithms Materials",
    subtitle: "Lecture materials, interactive slides, and C++ code examples.",
    topics: "Topic List",
    viewSlides: "View Slides",
    downloadCode: "Download Code",
    home: "Home",
    language: "Language",
    theme: "Theme",
    back: "Back",
    comingSoon: "Coming Soon",
    comingSoonDesc: "Material for this topic is currently being prepared.",
    backHome: "Back to Home"
  }
};

// State
let currentLang = localStorage.getItem('lang') || 'id';
let currentTheme = localStorage.getItem('theme') || 'dark';

export function initApp() {
  applyTheme(currentTheme);
  applyLanguage(currentLang);

  const themeToggle = document.getElementById('theme-toggle');
  if (themeToggle) {
    themeToggle.addEventListener('click', () => {
      currentTheme = currentTheme === 'dark' ? 'light' : 'dark';
      applyTheme(currentTheme);
    });
  }

  const langToggle = document.getElementById('lang-toggle');
  if (langToggle) {
    langToggle.addEventListener('click', () => {
      currentLang = currentLang === 'id' ? 'en' : 'id';
      applyLanguage(currentLang);
    });
  }
}

function applyTheme(theme) {
  document.documentElement.setAttribute('data-theme', theme);
  localStorage.setItem('theme', theme);
}

function applyLanguage(lang) {
  localStorage.setItem('lang', lang);
  document.querySelectorAll('[data-i18n]').forEach(el => {
    const key = el.getAttribute('data-i18n');
    if (translations[lang] && translations[lang][key]) {
      el.textContent = translations[lang][key];
    }
  });
}
