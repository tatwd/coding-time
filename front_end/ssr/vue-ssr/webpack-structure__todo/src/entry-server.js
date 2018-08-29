import { createApp } from './app'

export default const context => {
  const { app } = createApp()
  return app
}
