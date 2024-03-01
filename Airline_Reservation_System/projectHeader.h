#ifndef _PROJECTHEADER.H _
#define _PROJECTHEADER.H _
#define MAX_FLIGHTS 100
#define MAX_PASSENGERS 100

// System data structure
struct flight{
    int flightNumber;
    int availableSeats;
    char flightDate[20]; // DD/MM/YYYY
    char departureTime[20]; // HH:MM
    char departureCity[50];
    char arrivalTime[20]; // HH:MM
    char arrivalCity[50];

};

struct passenger{
    int ID;
    char Name[20];
    char Address[100];
    int phoneNumber;

};

struct ticket{
    int number;
    int passengerID;
    int flightNumber;
    char resDate[20]; // DD/MM/YYYY

};

// Global Variables, Arrays & Objects
struct flight trip[MAX_FLIGHTS];
struct passenger pasngr[MAX_PASSENGERS];
struct ticket tkt[MAX_PASSENGERS];
int flightsExist = 0;
int passengersExist = 0;
int TicketExist = 0;




//Prototype Functions
void admin_Settings();
void passenger_Settings();
int loginSignup();

#endif // _PROJECTHEADER
