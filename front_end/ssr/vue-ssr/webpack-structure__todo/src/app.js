import Vue from 'vue'
import App from './App.vue'
import { createRouter } from './router'

// 导出一个工厂函数，用于创建新的
// 应用程序、router 和 store 实例
export function createApp() {
  // create a router instance
  const router = createRouter()

  const app = new Vue({
    // inject router into root Vue instance
    router,

    // 根实例简单的渲染应用程序组件。
    render: h => h.render(App)
  })
  return { app, router }
}
