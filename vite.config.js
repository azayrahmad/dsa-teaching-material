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
        array_topic: resolve(__dirname, 'topics/array.html'),
        array_1d_slides: resolve(__dirname, 'slides/array-1d.html'),
        coming_soon: resolve(__dirname, 'topics/coming-soon.html'),
      },
    },
  },
})
