#include "clinic.h"
#include <stdio.h>
#include <stdlib.h>

// Global variables
struct Patient* patients = NULL;
struct Appointment* appointments = NULL;
int patientCount = 0;
int appointmentCount = 0;

void displayMenu() {
    printf("\n=== Clinic Management System ===\n");
    printf("1. Add Patient\n");
    printf("2. View Patients\n");
    printf("3. Add Appointment\n");
    printf("4. View Appointments\n");
    printf("5. Cancel Appointment\n");
    printf("6. Exit\n");
}

void addPatient()
{
    struct Patient newPatient;
    printf("Enter patient name: ");
    scanf("%s", newPatient.name);
    printf("Enter patient address: ");
    scanf("%s", newPatient.address);
    printf("Enter patient phone number: ");
    scanf("%s", newPatient.phone);

    newPatient.id = ++patientCount;

    // Allocate memory for a new patient
    patients = (struct Patient*)realloc(patients, patientCount * sizeof(struct Patient));

    // Check if memory allocation was successful
    if (patients == NULL) {
        printf("Memory allocation failed. Exiting the program.\n");
        exit(EXIT_FAILURE);
    }

    patients[patientCount - 1] = newPatient;

    printf("Patient added successfully with ID ===> : %d", newPatient.id);
}

void viewPatients()
{
    printf("\n=== Patients List ===\n");
    printf("ID\tName\tAddress\t\tPhone\n");

    for (int i = 0; i < patientCount; i++) {
        printf("%d\t%s\t%s\t%s\n", patients[i].id, patients[i].name, patients[i].address, patients[i].phone);
    }
}

void addAppointment()
{
    struct Appointment newAppointment;
    printf("Enter patient ID for appointment: ");
    scanf("%d", &newAppointment.patientId);
    printf("Enter appointment date: ");
    scanf("%s", newAppointment.date);
    printf("Enter appointment time: ");
    scanf("%s", newAppointment.time);

    newAppointment.id = ++appointmentCount;

    // Allocate memory for a new appointment
    appointments = (struct Appointment*)realloc(appointments, appointmentCount * sizeof(struct Appointment));

    // Check if memory allocation was successful
    if (appointments == NULL) {
        printf("Memory allocation failed. Exiting the program.\n");
        exit(EXIT_FAILURE);
    }

    appointments[appointmentCount - 1] = newAppointment;

    printf("Appointment added successfully. ID: %d\n", newAppointment.id);
}

void viewAppointments()
{
    printf("\n=== Appointments List ===\n");
    printf("ID\tPatient ID\tDate\t\tTime\n");

    for (int i = 0; i < appointmentCount; i++) {
        printf("%d\t%d\t\t%s\t%s\n", appointments[i].id, appointments[i].patientId, appointments[i].date, appointments[i].time);
    }

}

void cancelAppointment()
{
    int appointmentId;
    printf("Enter the ID of the appointment to cancel: ");
    scanf("%d", &appointmentId);

    int index = -1;

    for (int i = 0; i < appointmentCount; i++) {
        if (appointments[i].id == appointmentId) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        // Shift the elements after the canceled appointment to fill the gap
        for (int i = index; i < appointmentCount - 1; i++) {
            appointments[i] = appointments[i + 1];
        }

        // Decrease the appointment count
        appointmentCount--;

        // Resize the appointments array
        appointments = (struct Appointment*)realloc(appointments, appointmentCount * sizeof(struct Appointment));

        printf("Appointment canceled successfully. ID: %d\n", appointmentId);
    } else {
        printf("Appointment with ID %d not found.\n", appointmentId);
    }
}

void cleanupMemory()
{
    // Free allocated memory before exiting
    free(patients);
    free(appointments);
}
