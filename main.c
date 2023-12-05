#include <stdio.h>
#include "clinic.h"

int main() {
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPatient();
                break;
            case 2:
                viewPatients();
                break;
            case 3:
                addAppointment();
                break;
            case 4:
                viewAppointments();
                break;
            case 5:
                cancelAppointment();
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    // Cleanup allocated memory before exiting
    cleanupMemory();

    return 0;
}
