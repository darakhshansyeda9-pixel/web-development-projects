const port = process.env.PORT;

if (port) {
    console.log("Port: " + port);
} else {
    console.log("Default Port: 3000");
}