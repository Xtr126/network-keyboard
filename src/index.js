import Keyboard from "simple-keyboard";

import "simple-keyboard/build/css/index.css";
import "./index.css";

let commonKeyboardOptions = {
  onKeyPress: button => onKeyPress(button),
  onKeyReleased: button => onKeyRelease(button),
  theme: "simple-keyboard hg-theme-default hg-layout-default",
  syncInstanceInputs: true,
  mergeDisplay: true,
  useTouchEvents: true
};

let keyboard = new Keyboard(".simple-keyboard-main", {
  ...commonKeyboardOptions,
  layout: {
    'default': [
      "esc f1 f2 f3 f4 f5 f6 f7 f8 f9 f10 f11 f12",
      "` 1 2 3 4 5 6 7 8 9 0 - = {backspace}",
      "{tab} Q W E R T Y U I O P { } |",
      '{capslock} A S D F G H J K L : " {enter}',
      "{shiftleft} Z X C V B N M < > ? {shiftright}",
      "{controlleft} {meta} {altleft} {space} {altright} {controlleft}"
    ],
  },
  display: {
    "{tab}": "tab <>",
    "{backspace}": "<- backspace",
    "{enter}": "<- enter",
    "{capslock}": "caps lock ^",
    "{shiftleft}": "shift ^",
    "{shiftright}": "shift ^",
    "{controlleft}": "ctrl",
    "{controlright}": "ctrl",
    "{altleft}": "alt",
    "{altright}": "alt",
    "{meta}": "win",
    "{space}": "space"
  }
});

let keyboardControlPad = new Keyboard(".simple-keyboard-control", {
  ...commonKeyboardOptions,
  layout: {
    default: [
      "{prtscr} {scrolllock} {pause}",
      "{insert} {home} {pageup}",
      "{delete} {end} {pagedown}"
    ]
  }
});

let keyboardArrows = new Keyboard(".simple-keyboard-arrows", {
  ...commonKeyboardOptions,
  layout: {
    default: ["{arrowup}", "{arrowleft} {arrowdown} {arrowright}"]
  },
  display: {
    "{arrowup}": "^",
    "{arrowleft}": "<",
    "{arrowdown}": "v",
    "{arrowright}": ">"
  }
});

console.log(keyboard);

let url = 'ws' + (window.location.protocol === 'https:' ? 's' : '')  + '://' +
          window.location.host + '/websocket';
let socket = new WebSocket(url);
socket.binaryType = 'arraybuffer';

let keysPressed = new Set()

function onKeyPress(button) {
  if (!keysPressed.has(button)) {
    console.log("Button pressed", button);
    socket.send(`${button} down`);
  } else {
    console.log("Button repeat", button);
    socket.send(`${button} repeat`);
  }
  keysPressed.add(button);
}

function onKeyRelease(button) {
  console.log("Button released", button);
  socket.send(`${button} up`);
  keysPressed.delete(button);
}
