const express = require('express');

// create server app
const app = express();

app.get('/', function(req, res) {
  res.send('<h2>Hello Express!</h2>');
});

// use static assets
app.use('/static', express.static('public'));

// listening on port 300
app.listen(3000, function() {
  console.log('Server listening on http://localhost:3000 ...');
});
