const express = require("express");
const app = express();
const server = require('http').createServer(app);
const io = require('socket.io')(server);

const bodyParser = require("body-parser");
const gpiop = require("rpi-gpio").promise;


//GPIO
gpiop.setup(37, gpiop.DIR_OUT);
gpiop.setup(40, gpiop.DIR_OUT);

//HTTP SERVER
const port = 3141;
app.use(express.static("public"));
app.use(bodyParser.urlencoded({ extended: false }));
app.use(bodyParser.json());
server.listen(port);

app.post("/led", function (req, res) {
  const turn = req.body.led;
  gpiop.write(37, turn);
  res.send(turn ? "ВКЛ" : "ВЫКЛ");
});

let command = "";
app.get("/cell", function (req, res) {
	res.send(command);
	command = "";
});
app.post("/cell", function (req, res) {
  if(req.body.status == ""){
    res.send("ok");
    io.emit('log', "Ячейка номер " + req.body.num + " у клиента " + req.body.clientID + " активирована!")  
  } else {
    res.send("fail");
    io.emit('log', req.body.status)
  }
});

// WEBSOCKET
io.sockets.on('connection', function (socket) {

  socket.on('command', function (msg) {
    console.log(msg);
    command = msg;
    socket.emit('log', msg);
  });

  socket.on('error', (error) => { console.log(error) })
});
