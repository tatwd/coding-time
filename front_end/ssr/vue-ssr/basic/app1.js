const Vue = require('vue');
const server = require('express')();
const renderer = require('vue-server-renderer').createRenderer();

server.get('*', (req, res) => {
  const app = new Vue({
    data: {
      url: req.url
    },
    template: `<div>访问的 URL 是：{{ url }}</div>`
  });
  renderer.renderToString(app, (err, html) => {
    if (err) {
      res.status(500).end('Internal Server Error');
      return;
    }
    console.log(html)
    res.end(`
      <!DOCTYPE html>
      <html lang="en">
        <head>
          <meta charset="UTF-8">
          <title>Vue SSR Demo</title>
        </head>
        <body>${html}</body>
      </html>
    `);
  })
})

server.listen(8080, () => console.log('Serve on http://loacalhost:8080 ...'));
