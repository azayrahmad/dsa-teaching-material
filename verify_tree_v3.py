import asyncio
from playwright.async_api import async_playwright
import os

async def verify_tree_v3():
    async with async_playwright() as p:
        browser = await p.chromium.launch()
        page = await browser.new_page(viewport={'width': 1280, 'height': 720})

        # Navigate to the tree slides
        await page.goto('http://localhost:5173/slides/tree.html')
        await asyncio.sleep(2)

        # 1. Slide 6: Multi-tree visuals
        await page.goto('http://localhost:5173/slides/tree.html#6')
        await asyncio.sleep(1)
        await page.screenshot(path='/home/jules/verification/screenshots/v3_slide_6.png')

        # 2. Slide 19: Preorder Simulator
        await page.goto('http://localhost:5173/slides/tree.html#19')
        await asyncio.sleep(1)
        # Use more specific selector to avoid interception/multiple matches
        await page.click('#slide-18 >> text=Mulai')
        await page.click('#next-pre')
        await asyncio.sleep(0.5)
        await page.click('#next-pre')
        await asyncio.sleep(0.5)
        await page.screenshot(path='/home/jules/verification/screenshots/v3_slide_19_sim.png')

        # 3. Slide 20: Inorder Simulator
        await page.goto('http://localhost:5173/slides/tree.html#20')
        await asyncio.sleep(1)
        await page.click('#slide-19 >> text=Mulai')
        await page.click('#next-in')
        await asyncio.sleep(0.5)
        await page.screenshot(path='/home/jules/verification/screenshots/v3_slide_20_sim.png')

        # 4. Slide 21: Postorder Simulator
        await page.goto('http://localhost:5173/slides/tree.html#21')
        await asyncio.sleep(1)
        await page.click('#slide-20 >> text=Mulai')
        await page.click('#next-post')
        await asyncio.sleep(0.5)
        await page.screenshot(path='/home/jules/verification/screenshots/v3_slide_21_sim.png')

        await browser.close()

if __name__ == "__main__":
    if not os.path.exists('/home/jules/verification/screenshots'):
        os.makedirs('/home/jules/verification/screenshots')
    asyncio.run(verify_tree_v3())
