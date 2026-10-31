#include <stdio.h>
#include "student.h"

#define STUDENT_FILE "data/students.txt"

void addStudent()
{
    FILE *fp;

    int id;
    int year;

    char name[50];
    char department[50];

    fp = fopen(STUDENT_FILE, "a");

    if (fp == NULL)
    {
        printf("Unable to open student file.\n");
        return;
    }

    printf("\nEnter Student ID: ");
    scanf("%d", &id);

    printf("Enter Student Name: ");
    scanf(" %[^\n]", name);

    printf("Enter Department: ");
    scanf(" %[^\n]", department);

    printf("Enter Year: ");
    scanf("%d", &year);

    fprintf(
        fp,
        "%d|%s|%s|%d\n",
        id,
        name,
        department,
        year
    );

    fclose(fp);

    printf("\nStudent added successfully!\n");
}

void viewStudents()
{
    FILE *fp;

    char line[200];

    fp = fopen(STUDENT_FILE, "r");

    if (fp == NULL)
    {
        printf("\nNo student records found.\n");
        return;
    }

    printf("\n============== STUDENTS ==============\n");

    while (fgets(line, sizeof(line), fp))
    {
        printf("%s", line);
    }

    fclose(fp);
}