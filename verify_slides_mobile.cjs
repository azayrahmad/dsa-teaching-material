const { chromium, devices } = require('playwright');

(async () => {
  const browser = await chromium.launch();
  const context = await browser.newContext(devices['iPhone 13']);
  const page = await context.newPage();

  // Need to serve the files or use a local path if Vite is running
  // Since I don't have a server running, I'll assume I can use the built files or just point to the file if it doesn't need a server for simple CSS check.
  // Actually, it needs a server for Vite-style imports like /src/main.js

  // Let's start a quick server
  const http = require('http');
  const fs = require('fs');
  const path = require('path');

  const server = http.createServer((req, res) => {
    let filePath = '.' + req.url;
    if (filePath === './') filePath = './index.html';

    // Basic static server
    const extname = String(path.extname(filePath)).toLowerCase();
    const mimeTypes = {
      '.html': 'text/html',
      '.js': 'text/javascript',
      '.css': 'text/css',
      '.json': 'application/json',
      '.png': 'image/png',
      '.jpg': 'image/jpg',
      '.gif': 'image/gif',
      '.svg': 'image/svg+xml',
    };

    const contentType = mimeTypes[extname] || 'application/octet-stream';

    fs.readFile(filePath, (error, content) => {
      if (error) {
        if(error.code == 'ENOENT') {
          res.writeHead(404);
          res.end('File not found');
        } else {
          res.writeHead(500);
          res.end('Sorry, check with the site admin for error: '+error.code+' ..\n');
        }
      } else {
        res.writeHead(200, { 'Content-Type': contentType });
        res.end(content, 'utf-8');
      }
    });
  }).listen(8081);

  try {
    await page.goto('http://localhost:8081/slides/pointer.html');
    await page.waitForTimeout(1000); // Wait for animations
    await page.screenshot({ path: 'verification/slides_mobile_new.png' });
    console.log('Mobile slide screenshot saved.');
  } catch (e) {
    console.error(e);
  } finally {
    await browser.close();
    server.close();
  }
})();
