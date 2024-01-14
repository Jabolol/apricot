import cowsay from "npm:cowsay";
import { Server } from "npm:socket.io";

const io = new Server();

io.on("connection", (socket) => {
  console.log(`>> ${socket.id} connected`);

  socket.on("echo", (message) => {
    console.log(`>> ${socket.id}: ${message}`);
    switch (message) {
      case "ping": {
        socket.emit("echo", "pong");
        break;
      }
      case "whoami": {
        socket.emit("echo", socket.id);
        break;
      }
      case "cowsay": {
        socket.emit("echo", `\n${cowsay.say({ text: "Moo!" })}`);
        break;
      }
      case "help": {
        socket.emit("echo", "ping, whoami, cowsay, help");
        break;
      }
      default: {
        socket.emit("echo", message);
      }
    }
  });

  socket.on("disconnect", (reason) => {
    console.log(`<< ${socket.id} disconnected: ${reason}`);
  });
});

io.listen(3000);
