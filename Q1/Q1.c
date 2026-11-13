/*
Write a C application that simulates data transfer between two components of an embeddded system 
Requirements:
1. Create two child processes using fork().
2. The first child process acts as a sensor module. The Sensor Module generates 10 sensor reading with values from 10 to 100.
3. Send the sensor readings to the second child process using a System V message queue.
4. The second child process acts as a Monitoring module and receives sensor readings. For each received reading, display:
	Example
	1. Received sensor value : 25
	2. Received sensor value : 42
5. After receiving all readings, display:

	Example
	1. Total sensor Readings Received : 10
6. The parent process must wait for both child processes to terminate.
7. Remove the message queue before program termination.

Demonstrate:
1. Successful compilation
2. Program execution
3. Output showing transmitted and received sensor readings
4. Proper Cleanup of the message queue
*/
	





















