# Minitalk

## Project Description

Minitalk is a project developed as part of the 42 curriculum. It aims to implement a simple client-server communication system using the concept of signals in Unix-like operating systems. The project focuses on establishing a reliable and efficient data transfer mechanism between the client and server processes.

## Problem Statement

The main challenge in Minitalk is to implement a communication protocol that allows reliable transmission of messages between the client and server. This involves handling potential issues such as signal losses, synchronization, and data corruption.

## Usage

To use Minitalk, follow these steps:

1.  Clone the project repository: `git clone https://github.com/fortytwobytes/minitalk.git`

![0](https://github.com/fortytwobytes/minitalk/assets/65725801/3ff0bfd6-9a7a-4df1-b0c6-5a3b7fcaf1cf)

2.  Navigate to the project directory: `cd minitalk`
    
3.  Build the executable files:
    
    -   For the client: `make client`
    -   For the server: `make server`
    -   Or both with: `make`

![1](https://github.com/Anarbb/minitalk/assets/65725801/bea38945-9b26-483c-bba6-da2bce515ce0)

4.  Start the server process: `./server`

![2](https://github.com/Anarbb/minitalk/assets/65725801/8f291b6c-87e4-4ea2-8123-a47a40e2e5c0)

5.  In a separate terminal, start the client process: `./client [server_pid] [message]`
    
    -   Replace `[server_pid]` with the process ID of the server.
    -   Replace `[message]` with the message you want to send.

![3](https://github.com/Anarbb/minitalk/assets/65725801/4dc16a76-2c43-49ef-9d50-dba53fd12ed8)

6.  The client will send the message to the server, and the server will display the received message.

![5](https://github.com/Anarbb/minitalk/assets/65725801/89c5c2fa-3613-4ccd-b9c5-a53a13ced76f)

Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
 Everyone is permitted to copy and distribute verbatim copies
 of this license document, but changing it is not allowed.
