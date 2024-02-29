#include <stdio.h>

#define MAX_FLIGHTS 100
#define MAX_PASSENGERS 100

// System data structure
struct flight{
    int flightNumber;
    int availableSeats;
    char flightDate[20]; // DD/MM/YYYY
    char departyreTime[20]; // HH:MM
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




//Prototype Functions
void admin_Settings();
void passenger_Settings();
void loginSignup();
void update_flight();
//Testing Area



//Testing Area

/////////////////////////////////////////////////////////Functions' Code

int main()
{
    unsigned int choice;

    printf(" _ _______ _______ _______    _______ _       _______ _______ _     _ _______ ______  \n");
    printf("| (_______|_______|_______)  (_______|_)     (_______|_______|_)   (_|_______|_____ \\ \n");
    printf("| |_____   _____   _____      _____   _ _____ _______   __    _______ _______ _____) )\n");
    printf("| |  ___) |  ___) |  ___)    |  ___) | (_____)  ___  | / /   |  ___  |  ___  |  __  / \n");
    printf("| | |_____| |_____| |_____   | |_____| |_____| |   | |/ /____| |   | | |   | | |  \\ \\ \n");
    printf("|_|_______)_______)_______)  |_______)_______)_|   |_(_______)_|   |_|_|   |_|_|   |_|\n");

    printf("Airline Reservation System\n\n");
    printf("1. Admin settings\n");
    printf("2. Passenger settings\n");
    printf("3. Quit");

    invalid:
    printf("\n");
    printf("Enter a Number: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
        admin_Settings();
        break;
    case 2:
        passenger_Settings();
        break;
    case 3:
        printf("Exiting Program...");
        return 0;
    default:
        printf("Invalid Input!");
        goto invalid;
    }

    return 0;
}

//////////////////////////////////////////////////////////Functions' Code
void admin_Settings(){
    unsigned int choice;
    unsigned int flight_num;//number of flight which will add or update or delete (mahmoud);

    printf("1. Add new flight\n");
    printf("2. Delete existing flight schedule\n");
    printf("3. Update existing flight schedule\n");
    printf("4. Main Menu\n");

    invalid:
    printf("\n");
    printf("Enter a Number: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
        printf("Enter The Flight Exist To The System\n");
        scanf("%i",&flightsExist);
        New_Flight_Schedule(trip[MAX_FLIGHTS]);
        break;
    case 2:

        break;
    case 3:
        printf("\n\nEnter flight number to UPDATE: ");
        scanf("%d",&flight_num);
        update_flight(flight_num);
        break;
    case 4:
        main();
        break;
    default:
        printf("Invalid Input!");
        goto invalid;
    }

}

void passenger_Settings(){
    unsigned int choice;

    printf("1. Login / Sign up\n");
    printf("2. Search Available Flights\n");
    printf("3. Add new reservation\n");
    printf("4. Cancel reservation\n");
    printf("5. Modify reservation\n");
    printf("6. Show reservation log\n");
    printf("7. Main Menu\n");

    invalid:
    printf("\n");
    printf("Enter a Number: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:

        break;
    case 2:

        break;
    case 3:

        break;
    case 4:

        break;
    case 5:

        break;
    case 6:

        break;
    case 7:
        main();
        break;
    default:
        printf("Invalid Input!");
        goto invalid;
    }

}

void loginSignup(){
    unsigned int ID;
    printf("Enter your ID: ");
    scanf("%d", &ID);

}
//////////////////////////////New Flight Schedule
void New_Flight_Schedule(flight New_Flight)
{
    static int Numbers=0;
    Numbers=flightsExist;
    
    if(flightsExist<=MaxFlight)
    {
         printf("Enter The Flight Number:   \n");
         scanf("%i",&New_Flight.flightNumber  );

         printf("Enter The Number of Seats: \n");
         scanf("%i",&New_Flight.vailableSeats);
         fflush(stdin);

         printf("Enter The Flight Date:     \n");
         gets(New_Flight.flightDate[20]         );

         printf("Enter The Departure_city:  \n");
         gets(New_Flight.departureCity[50]     );

         printf("Enter The Departure_Time   \n");
         gets(New_Flight.departyreTime[20]     );

         printf("Enter The Arrival_city     \n");
         gets(New_Flight.arrivalCity[50]       );
        
         printf("Enter The Arrival_Time     \n");
         gets(New_Flight.arrivalTime[20]       );
         fflush(stdin);
        
         Numbers++;
         printf("You Add New Flight Schedule Successfully...\n");
    }
    else
    {
        printf("Sorry, You can't Add Anew_Flight. The System Is Full !!!\n");
    }
}

//////////////////////////////updating flight
void update_flight(int flight_num){
    int flag = 0;


    for(int i = 0 ; i < flightsExist ; i++){
        if(trip[i].flightNumber == flight_num){
            flag = 1;

            printf("Enter new departure city: ");
            scanf("%s",&trip[i].departureCity);

            printf("Enter new departure time: ");
            scanf("%s",&trip[i].departureTime);

            printf("Enter new arrival city: ");
            scanf("%s",&trip[i].arrivalCity);

            printf("Enter new arrival time: ");
            scanf("%s",&trip[i].arrivalTime);

            printf("Enter new flight date: ");
            scanf("%s",&trip[i].flightDate);

            printf("Enter new available seats: ");
            scanf("%s",&trip[i].availableSeats);

            printf("Flight schedule updated successfully!\n");
            break;

        }

        }
        if(!flag) {
        printf("\nFlight schedule not found!\n\n");
        admin_Settings();
    }
}

