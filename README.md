# Minitalk
*This project has been created as part of the 42 curriculum by olmatske*

## Description
Minitalk is a small data exchange program using UNIX signals. The project consists of two programs:

- **Server**: Displays its PID on launch and waits for incoming messages. When a message is received, it prints the message to the standard output.
- **Client**: Takes the server PID and a string as arguments, then sends the string bitwise to the server using only `SIGUSR1` and `SIGUSR2` signals.

The goal is to understand inter-process communication (IPC) through signals, bitwise operations, and how to encode/decode data at the binary level.

## Instructions

### Compilation
1. clone this project into a new directory
2. run `make re`
3. Start the server in one terminal:
   ```bash
   ./server
   ```
   The server will display its PID.
4. In another terminal, send a message using the client:
   ```bash
   ./client <server_pid> "Your message here"
   ```

### Example
```bash
# Terminal 1
./server
Server PID: 12345

# Terminal 2
./client 12345 "Hello, World!"

# Terminal 1 output
Hello, World!
```

## Resources

### Documentation
- Help of my Peers
- [signal(7) - Linux manual page](https://man7.org/linux/man-pages/man7/signal.7.html)
- [kill(2) - Linux manual page](https://man7.org/linux/man-pages/man2/kill.2.html)
- [Bitwise Operators in C](https://www.geeksforgeeks.org/bitwise-operators-in-c-cpp/)
- [Oceano's guide to Minitalk](https://youtu.be/XqhY9WHahJQ?si=i5v8JiIfECXnKniY)
- [42 Gitbook](https://42-cursus.gitbook.io/guide/2-rank-02/minitalk/understand-minitalk)

### AI Usage
AI (GitHub Copilot and PerplexityAI) was used during this project for:
- **Debugging**: Identifying issues with signal handling, memory management, and race conditions
- **Code review**: Analyzing the logic of bit manipulation and signal transmission
- **Explaining concepts**: Understanding why signals can be lost under certain conditions (e.g., when using Valgrind)
- **Makefile troubleshooting**: Fixing library linking issues

The core implementation logic (bit conversion, signal handlers, message reconstruction) was written by myself.


## Checklist
The following is my personal checklist I used to work through the project.

```
- [X] understand these functions
		◦ sigaction
		◦ kill
		◦ getpid
		◦ sleep
		◦ usleep

Server

	- [X] define SIGUSR1 as 0 and SIGUSR2 as 1
	- [X] show PID upon start
	- [X] write into buffer char by char
	- [-] binary to ascii converter (not needed)
	- [X] stop after recieving 8x0 byte
	- [X] print ascii

Client

	- [X] get PID of server and string as args
	- [X] convert string into binary and send

General

	- [X] add ft_printf
	- [X] write solid readme
	- [X] test it out
	- [X] tweak makefile?

```

## Fixes
	- [ ] Dynamic allocation instead of static!
	- [ ] implement handshake (aka bonus)
	- [ ] fix Makefile