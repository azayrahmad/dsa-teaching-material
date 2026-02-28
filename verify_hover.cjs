const { chromium } = require('playwright');

(async () => {
  const browser = await chromium.launch();
  const page = await browser.newPage();

  // Test desktop slides
  await page.setViewportSize({ width: 1280, height: 720 });
  await page.goto('http://localhost:5173/slides/pointer.html');

  // Verify nav is hidden initially
  const isNavVisible = await page.evaluate(() => {
    const nav = document.querySelector('.nav-slides');
    return window.getComputedStyle(nav).opacity === '1';
  });
  console.log('Is nav visible initially?', isNavVisible);
  await page.screenshot({ path: 'verification/slides_hidden_nav.png' });

  // Hover over bottom right to show nav
  await page.mouse.move(1200, 700);
  await page.waitForTimeout(500);
  await page.screenshot({ path: 'verification/slides_hover_nav.png' });

  // Hover over top left to show back link
  await page.mouse.move(50, 50);
  await page.waitForTimeout(500);
  await page.screenshot({ path: 'verification/slides_hover_back.png' });

  // Test mobile slides (should be always visible)
  await page.setViewportSize({ width: 390, height: 844 }); // iPhone 13
  await page.goto('http://localhost:5173/slides/pointer.html');
  const isMobileNavVisible = await page.evaluate(() => {
    const nav = document.querySelector('.nav-slides');
    return window.getComputedStyle(nav).opacity === '1';
  });
  console.log('Is mobile nav visible?', isMobileNavVisible);
  await page.screenshot({ path: 'verification/slides_mobile_nav_visible.png' });

  await browser.close();
})();
