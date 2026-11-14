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


Q1.
Write a c application that simulates data sharing between two processes.
Requirement:
	a)Create a parent process and a child process.
	b)Create a system v shred memory segment
	c)the parent process generates 10 temperatire readings(amy int values)
	d)store readings in the shared memory
	e)the child process reads the values and calculates:
		i.maximum tempreture
		ii. minimum temperature
		iii.Average tempreture
	f)USE POSIX semaphores to ensure the child reads data only after the parent has completed writing.
	g)display the calculated results.
	h) perform proper cleanup of all resources. 

shows:
	a) compilation
	b)excution
	c) output


****/





#include <stdio.h>

int main()
{


}
