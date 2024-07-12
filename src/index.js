import Keyboard from "simple-keyboard";

import "simple-keyboard/build/css/index.css";
import "./index.css";

let keyboard = new Keyboard({
  onKeyPress: button => onKeyPress(button)
});

document.querySelector(".input").addEventListener("input", event => {
  keyboard.setInput(event.target.value);
});

console.log(keyboard);

let url = 'ws' + (window.location.protocol === 'https:' ? 's' : '')  + '://' +
          window.location.host + '/websocket';
let socket = new WebSocket(url);
socket.binaryType = 'arraybuffer';

function onKeyPress(button) {
  console.log("Button pressed", button);
  socket.send(button);
}