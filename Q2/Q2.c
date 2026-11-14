/****

1. Attempy all questions
2. Proogram must be written in C language and excuted on a Linux enviroment.
3. student must demostrate:
	a)source code
	b)successful compilation
	c)program execution
	d) Expected output 
4.for each task, include observationand a short explaination of what the resilt demostrate
5.include screenshots or terminal output wherever they help demostrate the result
6. Proper error handling should be implementated for all system calls and library functions
7. Approprite comment should be included in the source code
8. All IPC and sychronisation resources created during excution must beproperly cleaned before program terination
9.compilation warning should be avoided as far as possible
10. Evalution will be based on:
	a) program correctness
	b)successful execution 
	c)use of aproprite IPC and sychronization mechanisms
	d)code quality
	e)understanding demostrated during viva examination

note:

a) partial marks may be awarded for correct program design, flowchart,logic and implementation approach evan if the program is not fully functional
b) Any assumption made during implememntation should be clearly documentated.
c) ensure all generated files(eg. output.txt)and outputs are available for evalution
	
Q2. write a c program that: 
  a) create a child process using fork()
  b)The child process creates two threads:
  	i.Reader thread 
  	ii. Processor thread
  c)Reader thred generates 10 logs IDs(1-10) and stores them in a shared buffer
  d) processor thread retrives the log IDs and displays:
  	Example-
  		Log ID: 5 Processed
  e)Use POSIX mutex
  f) the parent process should send the message "START" to the child thourgh aFIFO before proocessing begins.
  g)Ensure all threads amnd processes terminates gracefully
  
shows:
	a) compilation
	b)excution
	c) output
	


****/

#include <stdio.h>
int main ()
{
return 0;
}
