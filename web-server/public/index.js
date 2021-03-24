const socket = io.connect(); //load socket.io-client and connect to the host

const info = document.getElementById("info");

const light = document.getElementById("customSwitch3");
light.addEventListener("click", (e) => {
  const data = { led: e.target.checked };
  fetch("/led", {
    method: "POST",
    headers: { "Content-Type": "application/json;charset=utf-8" },
    body: JSON.stringify(data),
  })
    .then((res) => res.text())
    .then((msg) => logg(msg));
});

const form = document.forms.namedItem("toArduino");
form.addEventListener("submit", function (e) {
  e.preventDefault();
  sendCommand(form.command.value);
  form.reset();
});

function logg(msg) {
  info.value += msg + "\n";
  info.scrollTop = info.scrollHeight;
}

function sendCommand(str) {
  socket.emit("command", str);
}

socket.on("log", function (msg) {
  logg(msg);
});
