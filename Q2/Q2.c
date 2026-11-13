#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/wait.h>
 
int arr[10];        // shared array
int produced = 0;   // how many numbers producer has stored
int written = 0;    // how many numbers writer has written
FILE *fp;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
 
// producer thread stores 1 to 10 in the array
void *producer(void *arg)
{
    int i;
 
    for (i = 1; i <= 10; i++)
    {
        pthread_mutex_lock(&lock);
        arr[produced] = i;
        produced++;
        pthread_mutex_unlock(&lock);
        usleep(100000);
    }
    return NULL;
}
 
// writer thread takes number from array, finds cube and writes in file
void *writer(void *arg)
{
    int num;
 
    while (written < 10)
    {
        pthread_mutex_lock(&lock);
        if (written < produced)     // new number is available
        {
            num = arr[written];
            written++;
            fprintf(fp, "Number : %d Cube : %d\n", num, num * num * num);
            pthread_mutex_unlock(&lock);
        }
        else                        // nothing new, wait a little
        {
            pthread_mutex_unlock(&lock);
            usleep(50000);
        }
    }
    return NULL;
}
 
int main()
{
    pid_t pid;
    int status;
    pthread_t t1, t2;
 
    pid = fork();
 
    if (pid == 0)
    {
        // child process
        fp = fopen("results.txt", "w");
 
        pthread_create(&t1, NULL, producer, NULL);
        pthread_create(&t2, NULL, writer, NULL);
 
        // wait for both threads to finish
        pthread_join(t1, NULL);
        pthread_join(t2, NULL);
 
        // close file and destroy mutex
        fclose(fp);
        pthread_mutex_destroy(&lock);
        printf("Child: results written to results.txt\n");
    }
    else
    {
        // parent waits for child
        waitpid(pid, &status, 0);
        printf("Parent: child finished\n");
    }
 
    return 0;
}
