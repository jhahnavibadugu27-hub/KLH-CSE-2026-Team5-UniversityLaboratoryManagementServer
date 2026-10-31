#include <stdio.h>
#include "booking.h"

#define BOOKING_FILE "data/bookings.txt"

typedef struct
{
    int studentID;
    int equipmentID;
    char date[30];

} Booking;


void bookEquipment()
{
    Booking booking;

    FILE *fp;

    printf("\nEnter Student ID: ");
    scanf("%d", &booking.studentID);

    printf("Enter Equipment ID: ");
    scanf("%d", &booking.equipmentID);

    printf("Enter Booking Date: ");
    scanf(" %[^\n]", booking.date);

    fp = fopen(BOOKING_FILE, "a");

    if (fp == NULL)
    {
        printf("Unable to open booking file.\n");
        return;
    }

    fprintf(
        fp,
        "%d|%d|%s|BOOKED\n",
        booking.studentID,
        booking.equipmentID,
        booking.date
    );

    fclose(fp);

    printf("\nEquipment booking completed successfully!\n");
}


void viewBookings()
{
    FILE *fp;

    char line[200];

    fp = fopen(BOOKING_FILE, "r");

    if (fp == NULL)
    {
        printf("\nNo booking records found.\n");
        return;
    }

    printf("\n============== BOOKINGS ==============\n");

    while (fgets(line, sizeof(line), fp))
    {
        printf("%s", line);
    }

    fclose(fp);
}