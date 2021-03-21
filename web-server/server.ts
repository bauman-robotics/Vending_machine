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
// app.listen(port);
server.listen(port);
app.post("/led", function (req, res) {
  const turn = req.body.led;
  gpiop.write(37, turn);
  res.send(turn ? "ВКЛ" : "ВЫКЛ");
});
app.post("/init", function (req, res) {
  const serial = req.body.serial;
  res.send("Serial is " + (serial ? "open" : "close"));
});

app.post("/serial", function (req, res) {
  const turn = req.body.command;
  res.send(turn);
});

let command = "";
app.get("/cell", function (req, res) {
	res.send(command);
	command = "";
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
