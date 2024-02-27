#include <stdio.h>

#define MAX_FLIGHTS 100
#define MAX_PASSENGERS 100

int flights[MAX_FLIGHTS][3]; //flight number, no of seats, flight date

int passenger[MAX_PASSENGERS][4]; //ID, Name, Address, Phone number

void admin_Settings();

void passenger_Settings();

void loginSignup();

int main()
{
    unsigned int choice;

    printf("Airline Reservation System\n\n");
    printf("1. Admin settings\n");
    printf("2. Passenger settings\n");

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
    default:
        printf("Invalid Input!");
        goto invalid;
    }

    return 0;
}

void admin_Settings(){
    unsigned int choice;

    printf("1. Add new flight\n");
    printf("2. Delete existing flight schedule\n");
    printf("3. Update existing flight schedule\n");

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
