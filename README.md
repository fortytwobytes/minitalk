<h1>Minitalk</h1>

<h2>Project Description</h2>

<p>Minitalk is a project developed as part of the 42 curriculum. It aims to implement a simple client-server communication system using the concept of signals in Unix-like operating systems. The project focuses on establishing a reliable and efficient data transfer mechanism between the client and server processes.</p>

<h2>Problem Statement</h2>

<p>The main challenge in Minitalk is to implement a communication protocol that allows reliable transmission of messages between the client and server. This involves handling potential issues such as signal losses, synchronization, and data corruption.</p>

<h2>Usage</h2>

<p>To use Minitalk, follow these steps:</p>

<ol>
  <li>Clone the project repository: <code>git clone https://github.com/fortytwobytes/minitalk.git</code></li>

  <img src="https://github.com/fortytwobytes/minitalk/assets/65725801/3ff0bfd6-9a7a-4df1-b0c6-5a3b7fcaf1cf" alt="Step 1" width="600">

  <li>Navigate to the project directory: <code>cd minitalk</code></li>
  
  <li>Build the executable files:</li>
  <ul>
    <li>For the client: <code>make client</code></li>
    <li>For the server: <code>make server</code></li>
    <li>Or both with: <code>make</code></li>
  </ul>

  <img src="https://github.com/Anarbb/minitalk/assets/65725801/bea38945-9b26-483c-bba6-da2bce515ce0" alt="Step 2" width="600">

  <li>Start the server process: <code>./server</code></li>

  <img src="https://github.com/Anarbb/minitalk/assets/65725801/8f291b6c-87e4-4ea2-8123-a47a40e2e5c0" alt="Step 3" width="600">

  <li>In a separate terminal, start the client process: <code>./client [server_pid] [message]</code></li>
  <ul>
    <li>Replace <code>[server_pid]</code> with the process ID of the server.</li>
    <li>Replace <code>[message]</code> with the message you want to send.</li>
  </ul>

  <img src="https://github.com/Anarbb/minitalk/assets/65725801/4dc16a76-2c43-49ef-9d50-dba53fd12ed8" alt="Step 4" width="600">

  <li>The client will send the message to the server, and the server will display the received message.</li>

  <img src="https://github.com/Anarbb/minitalk/assets/65725801/89c5c2fa-3613-4ccd-b9c5-a53a13ced76f" alt="Step 5" width="600">
</ol>

<h2>Tester</h2>

<p>To use the tester script, follow these steps:</p>

<ol>
  <li>Ensure the tester script (<code>tester.sh</code>) is present in the project directory.</li>
  <li>Set the execution permissions for the tester script: <code>chmod +x ./tester.sh</code></li>
  <li>Run the tester script with the server PID and options:</li>
  <ul>
    <li>For mandatory part testing: <code>./tester.sh [server_pid] -m</code></li>
    <li>For bonus part testing: <code>./tester.sh [server_pid] -b</code></li>
  </ul>
  <li>Replace <code>[server_pid]</code> with the process ID of the server.</li>
  <li><strong>Note:</strong> You can use both options <code>-m</code> and <code>-b</code> together to test both mandatory and bonus parts.</li>
  <li>The tester script will execute various test cases to validate the functionality of your implementation.</li>
</ol>

<h2>Copyright</h2>

<p>Copyright (C) 2007 Free Software Foundation, Inc. <a href="https://fsf.org/">https://fsf.org/</a><br>
Everyone is permitted to copy and distribute verbatim copies of this license document, but changing it is not allowed.</p>
