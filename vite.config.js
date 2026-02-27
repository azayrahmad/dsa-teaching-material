import { resolve } from 'path'
import { defineConfig } from 'vite'

export default defineConfig({
  base: './',
  build: {
    rollupOptions: {
      input: {
        main: resolve(__dirname, 'index.html'),
        pointer_topic: resolve(__dirname, 'topics/pointer.html'),
        pointer_slides: resolve(__dirname, 'slides/pointer.html'),
        coming_soon: resolve(__dirname, 'topics/coming-soon.html'),
      },
    },
  },
})
