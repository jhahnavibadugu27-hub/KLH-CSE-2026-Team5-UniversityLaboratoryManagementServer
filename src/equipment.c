#include <stdio.h>
#include "equipment.h"

#define EQUIPMENT_FILE "data/equipment.txt"

void addEquipment()
{
    FILE *fp;

    int id;
    int quantity;

    char name[50];
    char status[30];

    fp = fopen(EQUIPMENT_FILE, "a");

    if (fp == NULL)
    {
        printf("Unable to open equipment file.\n");
        return;
    }

    printf("\nEnter Equipment ID: ");
    scanf("%d", &id);

    printf("Enter Equipment Name: ");
    scanf(" %[^\n]", name);

    printf("Enter Quantity: ");
    scanf("%d", &quantity);

    printf("Enter Status: ");
    scanf(" %[^\n]", status);

    fprintf(
        fp,
        "%d|%s|%d|%s\n",
        id,
        name,
        quantity,
        status
    );

    fclose(fp);

    printf("\nEquipment added successfully!\n");
}

void viewEquipment()
{
    FILE *fp;

    char line[200];

    fp = fopen(EQUIPMENT_FILE, "r");

    if (fp == NULL)
    {
        printf("\nNo equipment records found.\n");
        return;
    }

    printf("\n============== EQUIPMENT ==============\n");

    while (fgets(line, sizeof(line), fp))
    {
        printf("%s", line);
    }

    fclose(fp);
}