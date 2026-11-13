#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <semaphore.h>
#include <sys/shm.h>
#include <sys/wait.h>

int main()
{
    int shmid, i;
    int *temp;
    sem_t *sem;
    pid_t pid;

    shmid = shmget(IPC_PRIVATE, 10 * sizeof(int), IPC_CREAT | 0666);
    sem = sem_open("/tempsem", O_CREAT, 0666, 0);

    pid = fork();

    if (pid == 0)
    {
        int max, min, sum = 0;

        temp = (int *)shmat(shmid, NULL, 0);

        sem_wait(sem);

        max = temp[0];
        min = temp[0];
        for (i = 0; i < 10; i++)
        {
            if (temp[i] > max)
                max = temp[i];
            if (temp[i] < min)
                min = temp[i];
            sum = sum + temp[i];
        }

        printf("Child: Maximum temperature = %d\n", max);
        printf("Child: Minimum temperature = %d\n", min);
        printf("Child: Average temperature = %.2f\n", sum / 10.0);

        shmdt(temp);
        sem_close(sem);
    }
    else
    {
        temp = (int *)shmat(shmid, NULL, 0);

        srand(getpid());
        printf("Parent: Temperature readings are:\n");
        for (i = 0; i < 10; i++)
        {
            temp[i] = 20 + rand() % 21;
            printf("%d ", temp[i]);
        }
        printf("\n");

        sem_post(sem);

        wait(NULL);

        shmdt(temp);
        shmctl(shmid, IPC_RMID, NULL);
        sem_close(sem);
        sem_unlink("/tempsem");
    }

    return 0;
}
