#ifndef CLINIC_H
#define CLINIC_H



// Define structures for patient and appointment
struct Patient {
    int id;
    char name[50];
    char address[100];
    char phone[15];
};

struct Appointment {
    int id;
    int patientId;
    char date[20];
    char time[10];
};

// Function prototypes
void displayMenu();
void addPatient();
void viewPatients();
void addAppointment();
void viewAppointments();
void cancelAppointment();
void cleanupMemory();

#endif // CLINIC_H
