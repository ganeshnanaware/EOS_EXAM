#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/wait.h>
 
// structure for the message
struct message
{
    long type;
    int value;
};
 
int main()
{
    int msgid, i, count = 0;
    pid_t pid1, pid2;
    struct message msg;
 
    // create the message queue
    msgid = msgget(IPC_PRIVATE, IPC_CREAT | 0666);
 
    pid1 = fork();
 
    if (pid1 == 0)
    {
        // first child - sensor module
        srand(getpid());
        for (i = 0; i < 10; i++)
        {
            msg.type = 1;
            msg.value = 10 + rand() % 91;   // value from 10 to 100
            msgsnd(msgid, &msg, sizeof(int), 0);
            printf("Sent sensor value : %d\n", msg.value);
            usleep(100000);
        }
        exit(0);
    }
 
    pid2 = fork();
 
    if (pid2 == 0)
    {
        // second child - monitoring module
        for (i = 0; i < 10; i++)
        {
            msgrcv(msgid, &msg, sizeof(int), 1, 0);
            printf("Received sensor value : %d\n", msg.value);
            count++;
        }
        printf("Total sensor Readings Received : %d\n", count);
        exit(0);
    }
 
    // parent waits for both children
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
 
    // remove the message queue
    msgctl(msgid, IPC_RMID, NULL);
    printf("Parent: message queue removed\n");
 
    return 0;
}
 




















