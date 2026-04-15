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
        array_2d_slides: resolve(__dirname, 'slides/array-2d.html'),
        struct_topic: resolve(__dirname, 'topics/struct.html'),
        struct_slides: resolve(__dirname, 'slides/struct.html'),
        linked_list_topic: resolve(__dirname, 'topics/linked-list.html'),
        linked_list_slides: resolve(__dirname, 'slides/linked-list-1.html'),
        linked_list_slides_2: resolve(__dirname, 'slides/linked-list-2.html'),
        searching_topic: resolve(__dirname, 'topics/searching.html'),
        searching_slides: resolve(__dirname, 'slides/searching.html'),
        searching_advanced_slides: resolve(__dirname, 'slides/searching-advanced.html'),
        sorting_topic: resolve(__dirname, 'topics/sorting.html'),
        sorting_basic_slides: resolve(__dirname, 'slides/sorting-basic.html'),
        sorting_advanced_slides: resolve(__dirname, 'slides/sorting-advanced.html'),
        visualizer: resolve(__dirname, 'visualizer.html'),
        coming_soon: resolve(__dirname, 'topics/coming-soon.html'),
      },
    },
  },
})
