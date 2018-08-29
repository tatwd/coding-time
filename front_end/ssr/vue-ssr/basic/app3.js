const fs = require('fs');
const Vue = require('vue');
const server = require('express')();
const vueServerRenderer = require('vue-server-renderer')

// create a vue ssr
const renderer = vueServerRenderer.createRenderer({
  template: fs.readFileSync('./app3.template.html', 'utf-8')
});

let count = 0;
server.get('*', (req, res) => {
  const app = new Vue({
    data: {
      url: req.url
    },
    template: `<div>访问的 URL 是：{{ url }}</div>`
  });

  const context = {
    title: `app3 title ${++count}`,
    meta: `
      <meta charset="utf-8">
    `
  }
  renderer.renderToString(app, context, (err, html) => {
    if (err) {
      res.status(500).end('Internal Server Error');
      return;
    }
    console.log(html)
    res.end(html);
  })
})

server.listen(8080, () => console.log('Serve on http://loacalhost:8080 ...'));
