# Reverse Engineering 101

## Reverse Engineering -- 25 points

### Description

Reverse engineering can definitely be intimidating so we have a simple [RE101](./RE101) with which you can start. If you don't know where to start, check out the hints where we'll walk you through two different ways to solve this problem.

### Hints

* **Static analysis**: Static analysis is a process for examining a program without having a computer execute any code.

	+ From a command line on Linux, executing objdump -d RE101 will display the assembly code for the executable sections of the program (assumes you downloaded the file to the same folder).
	+ Flow of this program starts at \_start and proceeds 'down' the code.
	+ objdump -t RE101 will print all of the 'symbols' in the program. These are human-readable names for specific spots in memory. Symbols in the '.text' section tend to be function names and symbols in '.bss', '.data', and '.rodata' tend to be variable names.
	+ You should be able to see that the address of the 'flag' symbol (second command) appears in the first instruction of the '\_start' (first command).
	+ The hex values that are moved look like they are in the printable ASCII range.


* **Dynamic analysis**: Dynamic analysis is a method of examining the program as it is running to learn more about what it does. A common tool to help with this is a "debugger" like gdb.

	1. gdb RE101 will launch GDB and prepare it to debug our target, the RE101 executable. You may need to change the permissions on the downloaded file in order to make it executable (chmod a+x RE101).
	2. break \_exit will add a "breakpoint" which will pause the program's execution when we reach this point in the code. We're able to use '\_exit' here as a convenience and could have also specified a memory address instead.
	3. run will start execution and keep running until we hit the breakpoint we specified above.
	4. x /s &flag tells GDB to 'examine' a 'string' located at the address of the 'flag' symbol ('&' is the C symbol for 'address of').


* Instead of the dynamic analysis above, we could have also continued our static analysis by studying the assembly code we produced earlier. In particular, we can observe that the code is moving a pointer to the 'flag' variable into the EDI register in the first line. It then 'moves' a series of byte-constants into the memory location to which EDI points, 'incrementing' EDI in between each move. The final three lines in '\_exit' execute a Linux system call to 'exit', but that is relevant for this problem.
* When doing reverse engineering of x86 and x86-64 programs, Intel's [instruction set reference](https://www.intel.com/content/dam/www/public/us/en/documents/manuals/64-ia-32-architectures-software-developer-instruction-set-reference-manual-325383.pdf) can be very helpful. It can be intimidating to look at, but looking up the assembly instruction in this document will tell you exactly what it does.


### Write-up

- [Video Walk-through by Tim Nosco](https://www.youtube.com/watch?v=9dQFM5O4KFk&list=PL-nPhof8EyrGKytps3g582KNiJyIAOtBG)
- [Write-up by starkindustries](https://github.com/starkindustries/CyberStakes2020#reverse-engineering-101---points-25)
