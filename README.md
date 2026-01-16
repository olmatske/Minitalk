# Minitalk

Checklist



- [ ] understand these functions
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
	- [ ] write solid readme
	- [ ] test it out
	- [X] tweak makefile?