#include <stdio.h>

#include "student.h"
#include "faculty.h"
#include "laboratory.h"
#include "equipment.h"
#include "booking.h"
#include "os_features.h"


/* =====================================================
   REPORT GENERATION
   ===================================================== */

void generateReports()
{
    printf("\n");
    printf("==============================================\n");
    printf("       UNIVERSITY LABORATORY REPORTS\n");
    printf("==============================================\n");

    printf("\nStudent records\n");
    printf("Faculty records\n");
    printf("Laboratory records\n");
    printf("Equipment records\n");
    printf("Booking records\n");

    printf("\nReport generation completed.\n");
}


/* =====================================================
   MAIN FUNCTION
   ===================================================== */

int main()
{
    int choice;


    /* ---------------------------------------------
       OS CONCEPTS INITIALIZATION
       --------------------------------------------- */

    /* CO1 - System Calls */
    initializeSystem();

    /* CO2 - Process Management */
    demonstrateProcess();

    /* CO3 - Inter Process Communication */
    demonstrateIPC();

    /* CO4 - Memory Management */
    demonstrateMemory();


    /* ---------------------------------------------
       UNIVERSITY LAB MANAGEMENT MENU
       --------------------------------------------- */

    while (1)
    {
        printf("\n\n");

        printf("=================================================\n");
        printf("     UNIVERSITY LABORATORY MANAGEMENT SYSTEM\n");
        printf("=================================================\n");

        printf("1. Add Student\n");
        printf("2. View Students\n");

        printf("3. Add Faculty\n");
        printf("4. View Faculty\n");

        printf("5. Add Laboratory\n");
        printf("6. View Laboratories\n");

        printf("7. Add Equipment\n");
        printf("8. View Equipment\n");

        printf("9. Book Equipment\n");
        printf("10. View Bookings\n");

        printf("11. Generate Reports\n");

        printf("12. Exit\n");

        printf("-------------------------------------------------\n");

        printf("Enter your choice: ");

        scanf("%d", &choice);


        switch (choice)
        {
            case 1:

                addStudent();

                break;


            case 2:

                viewStudents();

                break;


            case 3:

                addFaculty();

                break;


            case 4:

                viewFaculty();

                break;


            case 5:

                addLaboratory();

                break;


            case 6:

                viewLaboratories();

                break;


            case 7:

                addEquipment();

                break;


            case 8:

                viewEquipment();

                break;


            case 9:

                bookEquipment();

                break;


            case 10:

                viewBookings();

                break;


            case 11:

                generateReports();

                break;


            case 12:

                printf(
                    "\nThank you for using the system!\n"
                );

                return 0;


            default:

                printf(
                    "\nInvalid choice. Please try again.\n"
                );
        }
    }


    return 0;
}