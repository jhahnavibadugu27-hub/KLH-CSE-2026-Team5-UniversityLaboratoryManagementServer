#include <stdio.h>
#include "faculty.h"

#define FACULTY_FILE "data/faculty.txt"

void addFaculty()
{
    FILE *fp;

    int id;

    char name[50];
    char department[50];

    fp = fopen(FACULTY_FILE, "a");

    if (fp == NULL)
    {
        printf("Unable to open faculty file.\n");
        return;
    }

    printf("\nEnter Faculty ID: ");
    scanf("%d", &id);

    printf("Enter Faculty Name: ");
    scanf(" %[^\n]", name);

    printf("Enter Department: ");
    scanf(" %[^\n]", department);

    fprintf(
        fp,
        "%d|%s|%s\n",
        id,
        name,
        department
    );

    fclose(fp);

    printf("\nFaculty added successfully!\n");
}

void viewFaculty()
{
    FILE *fp;

    char line[200];

    fp = fopen(FACULTY_FILE, "r");

    if (fp == NULL)
    {
        printf("\nNo faculty records found.\n");
        return;
    }

    printf("\n============== FACULTY ==============\n");

    while (fgets(line, sizeof(line), fp))
    {
        printf("%s", line);
    }

    fclose(fp);
}