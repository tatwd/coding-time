const WebSocket = require('ws');

// use Server class
const WebSocketServer = WebSocket.Server;

// init a server
const wss = new WebSocketServer({
  port: 3000
});

// connection event
wss.on('connection', ws => {
  console.log(`[SERVER] connection()`);
  ws.on('message', message => {
    console.log(`[SERVER] Recevied: ${message}`);
    /*ws.send(`ECHO: ${message}`, err => {
      if (err) {
        console.log(`[SERVER] error: ${err}`);
      }
    });*/
    setTimeout(() => {
      ws.send(`What's your name?`, err => {
        if (err) {
          console.log(`[SERVER] error: ${err}`);
        }
      });
    }, 1000);
  });
});

console.log('ws server started at port 3000...');

// client test:
let count = 0;
let ws = new WebSocket('ws://localhost:3000/ws/chat');

ws.on('open', () => {
  console.log(`[CLIENT] open()`);
  ws.send('Hello!');
});

ws.on('message', message => {
  console.log(`[CLIENT] Received: ${message}`);
  count++;
  if (count > 3) {
    ws.send('Goodbye!');
    ws.close();
  } else {
    setTimeout(() => {
      ws.send(`Hello, I'm Mr No.${count}!`);
    }, 1000);
  }
});
