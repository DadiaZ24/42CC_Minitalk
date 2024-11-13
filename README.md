# 🗣️ Minitalk

A simple messaging program in C for the 42 School curriculum, using UNIX signals to facilitate client-server communication.

![](https://imgur.com/zRR1ufC](https://imgur.com/QFN3qv9](https://github.com/DadiaZ24/42CC_Minitalk/blob/main/preview.gif?raw=true)

## 📄 Project Overview

The Minitalk project consists of two programs: a server and a client. The client sends a message to the server by transmitting characters as binary data via UNIX signals (SIGUSR1 and SIGUSR2). This project simulates a minimalistic messaging protocol between processes.
## ✨ Features

    Signal-based communication: The server and client communicate using UNIX signals.
    Message encoding: Transforms and sends messages one bit at a time.
    ASCII compatibility: Supports sending ASCII characters.
    Error handling: Includes basic error handling to ensure message reliability.

## 📁 Project Structure

    .
    ├── libft                # The folder with the libft library
    ├── Makefile             # Compiles the project
    ├── server.c             # Server implementation
    ├── client.c             # Client implementation
    └── README.md            # Project documentation

## 🚀 Getting Started
### Prerequisites

    GNU Make: Required to compile the project.
    CC: GNU Compiler Collection for compiling C code.
    UNIX-based system: The project relies on UNIX signals, so it is best suited for UNIX-like operating systems (Linux, macOS).

### Compilation

    To compile the project, run:

    * make

    This command generates two executables: server and client.
### Usage

    Start the server:

    ./server

    This command will start the server and display its Process ID (PID). Note the PID, as you'll need it to connect the client.

### Run the client:

    ./client [server_PID] [message]

    Replace [server_PID] with the PID of the server process and [message] with the message you want to send.

### Example

    In one terminal, start the server:

    $ ./server
    Server PID: 12345

    In another terminal, send a message using the client:

    $ ./client 12345 "Hello, Minitalk!"

After executing the client, the server will display:

    Hello, Minitalk!

## ⚙️ Implementation Details

    Signal Handling: Uses SIGUSR1 and SIGUSR2 for binary transmission of data from client to server.
    Binary Encoding: Each character in the message is transmitted bit by bit.

## 📝 Notes

    Error Handling: Ensure proper error checking for invalid PIDs, message length, and signal interruptions.
    Signal Limitations: Signals have limitations on speed and reliability. This project serves as a learning exercise in low-level signal handling rather than a robust messaging system.

## 🏆 Credits

Project by Diogo Ferreira as part of the curriculum at 42 Porto School.
