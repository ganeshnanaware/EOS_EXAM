#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define FIFO_NAME "/tmp/log_fifo"

int buffer[10];
int written = 0;
int processed = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *reader(void *arg)
{
    int i;

    for (i = 1; i <= 10; i++)
    {
        pthread_mutex_lock(&lock);
        buffer[written] = i;
        written++;
        pthread_mutex_unlock(&lock);
        usleep(100000);
    }
    return NULL;
}

void *processor(void *arg)
{
    int id;

    while (processed < 10)
    {
        pthread_mutex_lock(&lock);
        if (processed < written)
        {
            id = buffer[processed];
            processed++;
            pthread_mutex_unlock(&lock);
            printf("Log ID: %d Processed\n", id);
        }
        else
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
    int fd;
    char msg[10];
    pthread_t t1, t2;

    mkfifo(FIFO_NAME, 0666);

    pid = fork();

    if (pid == 0)
    {
        fd = open(FIFO_NAME, O_RDONLY);
        memset(msg, 0, sizeof(msg));
        read(fd, msg, sizeof(msg));
        close(fd);
        printf("Child: Message received from parent = %s\n", msg);

        pthread_create(&t1, NULL, reader, NULL);
        pthread_create(&t2, NULL, processor, NULL);

        pthread_join(t1, NULL);
        pthread_join(t2, NULL);

        pthread_mutex_destroy(&lock);
        printf("Child: All logs processed\n");
    }
    else
    {
        fd = open(FIFO_NAME, O_WRONLY);
        write(fd, "START", 6);
        close(fd);
        printf("Parent: START message sent\n");

        wait(NULL);

        unlink(FIFO_NAME);
        printf("Parent: Child finished\n");
    }

    return 0;
}
