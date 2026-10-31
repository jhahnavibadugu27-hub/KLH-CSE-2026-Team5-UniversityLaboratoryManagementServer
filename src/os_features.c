#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <string.h>

#include "os_features.h"

#define LOG_FILE "logs/system.log"


/* =====================================================
   CO1 - SYSTEM CALLS
   ===================================================== */

void demonstrateSystemCalls()
{
    int fd;

    fd = open(
        LOG_FILE,
        O_WRONLY | O_CREAT | O_APPEND,
        0644
    );

    if (fd == -1)
    {
        printf("Unable to open system log.\n");
        return;
    }

    char message[] =
        "CO1: System call demonstration completed.";

    write(
        fd,
        message,
        strlen(message)
    );

    write(
        fd,
        "\n",
        1
    );

    close(fd);
}


/* =====================================================
   SYSTEM INITIALIZATION
   ===================================================== */

void initializeSystem()
{
    demonstrateSystemCalls();

    printf("\nSystem initialized successfully.\n");
}


/* =====================================================
   CO2 - PROCESS MANAGEMENT
   ===================================================== */

void demonstrateProcess()
{
    pid_t pid;

    pid = fork();

    if (pid < 0)
    {
        printf("Process creation failed.\n");
        return;
    }

    if (pid == 0)
    {
        printf(
            "CO2: Child process created. PID = %d\n",
            getpid()
        );

        exit(0);
    }

    else
    {
        wait(NULL);

        printf(
            "CO2: Parent process synchronized with child.\n"
        );
    }
}


/* =====================================================
   CO3 - IPC USING PIPE
   ===================================================== */

void demonstrateIPC()
{
    int pipefd[2];

    if (pipe(pipefd) == -1)
    {
        printf("Pipe creation failed.\n");
        return;
    }

    pid_t pid = fork();

    if (pid < 0)
    {
        printf("Process creation failed.\n");

        close(pipefd[0]);
        close(pipefd[1]);

        return;
    }


    /* CHILD PROCESS */

    if (pid == 0)
    {
        char message[100];

        close(pipefd[1]);

        ssize_t bytesRead;

        bytesRead = read(
            pipefd[0],
            message,
            sizeof(message) - 1
        );

        if (bytesRead > 0)
        {
            message[bytesRead] = '\0';

            printf(
                "CO3: Child received through pipe: %s\n",
                message
            );
        }

        close(pipefd[0]);

        exit(0);
    }


    /* PARENT PROCESS */

    else
    {
        char message[] =
            "Laboratory equipment booking information";

        close(pipefd[0]);

        write(
            pipefd[1],
            message,
            strlen(message)
        );

        close(pipefd[1]);

        wait(NULL);

        printf(
            "CO3: Parent sent information through IPC pipe.\n"
        );
    }
}


/* =====================================================
   CO4 - MEMORY MANAGEMENT
   ===================================================== */

void demonstrateMemory()
{
    printf("\n");
    printf("==============================================\n");
    printf("       CO4 MEMORY MANAGEMENT DEMO\n");
    printf("==============================================\n");


    /* ---------------------------------------------
       PART 1: DYNAMIC MEMORY ALLOCATION
       --------------------------------------------- */

    int *numbers;

    numbers = (int *)malloc(
        5 * sizeof(int)
    );

    if (numbers == NULL)
    {
        printf("Dynamic memory allocation failed.\n");
        return;
    }

    for (int i = 0; i < 5; i++)
    {
        numbers[i] = (i + 1) * 10;
    }

    printf(
        "Dynamically allocated values: "
    );

    for (int i = 0; i < 5; i++)
    {
        printf(
            "%d ",
            numbers[i]
        );
    }

    printf("\n");

    free(numbers);

    printf(
        "Dynamic memory released using free().\n"
    );


    /* ---------------------------------------------
       PART 2: MEMORY MAPPING
       --------------------------------------------- */

    int *mappedMemory;

    mappedMemory = mmap(
        NULL,
        sizeof(int),
        PROT_READ | PROT_WRITE,
        MAP_PRIVATE | MAP_ANONYMOUS,
        -1,
        0
    );

    if (mappedMemory == MAP_FAILED)
    {
        printf("mmap failed.\n");
        return;
    }

    *mappedMemory = 100;

    printf(
        "Value stored in mapped memory: %d\n",
        *mappedMemory
    );

    munmap(
        mappedMemory,
        sizeof(int)
    );

    printf(
        "Mapped memory released using munmap().\n"
    );


    printf(
        "CO4 memory demonstration completed.\n"
    );
}