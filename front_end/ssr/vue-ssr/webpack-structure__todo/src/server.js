const createApp = require('/path/to/bundle.js')

server.get('*', (req, res) => {
  const context = { url: req.url }
  createApp(context).then(app => {
    renderer.renderToString(app, (err, html) => {
      if (!err) res.end(html)
      if (err.code === 404) res.status(404).end('Page not found!')
      else res.status(500).end('Internal server error!')
    })
  })
})
