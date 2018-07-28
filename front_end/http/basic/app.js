var http = require('http');
var fs = require('fs');

// http server config
var hostname = '127.0.0.1';
var port = '3030';

/*
// create a server
var server = http.createServer(function(req, res) {
  res.statusCode = 200;
  res.setHeader('Content-Type', 'text/html');
  res.end('Hell world');
});

server.listen(port, hostname, function() {
  console.log(`Server listening on http://${hostname}:${port}`);
});
*/

// read html file and send to client
fs.readFile('index.html', function(err, html) {
  if (err) {
    throw err;
  }

  var server = http.createServer(function(req, res) {
    res.statusCode = 200;
    res.setHeader('Content-Type', 'text/html');
    res.write(html);
    res.end();
  });

  server.listen(port, hostname, function() {
    console.log(`Server listening on http://${hostname}:${port}`);
  });
});
