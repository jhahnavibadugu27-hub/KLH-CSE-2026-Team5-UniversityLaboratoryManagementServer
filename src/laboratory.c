#include <stdio.h>
#include "laboratory.h"

#define LAB_FILE "data/laboratories.txt"

void addLaboratory()
{
    FILE *fp;

    int id;
    int capacity;

    char name[50];
    char department[50];

    fp = fopen(LAB_FILE, "a");

    if (fp == NULL)
    {
        printf("Unable to open laboratory file.\n");
        return;
    }

    printf("\nEnter Laboratory ID: ");
    scanf("%d", &id);

    printf("Enter Laboratory Name: ");
    scanf(" %[^\n]", name);

    printf("Enter Department: ");
    scanf(" %[^\n]", department);

    printf("Enter Capacity: ");
    scanf("%d", &capacity);

    fprintf(
        fp,
        "%d|%s|%s|%d\n",
        id,
        name,
        department,
        capacity
    );

    fclose(fp);

    printf("\nLaboratory added successfully!\n");
}

void viewLaboratories()
{
    FILE *fp;

    char line[200];

    fp = fopen(LAB_FILE, "r");

    if (fp == NULL)
    {
        printf("\nNo laboratory records found.\n");
        return;
    }

    printf("\n=========== LABORATORIES ===========\n");

    while (fgets(line, sizeof(line), fp))
    {
        printf("%s", line);
    }

    fclose(fp);
}