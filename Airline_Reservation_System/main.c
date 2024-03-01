#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "projectHeader.h"

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
    if (scanf("%d", &choice) != 1){
        printf("Invalid Input!");
    }

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
    printf("Enter a Number: \n");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
        New_Flight_Schedule();
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
    int passengerID = 0;
    bool loggedin = false; // true for testing //////////////////////////////////////////////////////////////
    begin:
    printf("You're ");
    printf(loggedin ? "logged in (ID:%d)\n":"not logged in.\n", passengerID);

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
    if (scanf("%d", &choice) != 1){
        printf("Invalid Input!");
        scanf("%*[^\n]");
        goto invalid;
    } else if (!loggedin && choice != 1 && choice != 7){
        printf("Please login the system first!\n");
        goto invalid;
    }

    switch (choice) {
    case 1:

        passengerID = loginSignup();
        loggedin = passengerID;
        printf("%d \n", loggedin);
        goto begin;
        break;
    case 2:

        break;
    case 3:
        New_Passenger_Resservation();
        break;
    case 4:

        break;
    case 5:
        modify_reservation();
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

int loginSignup(){
    unsigned int choice;
    unsigned int ID = 0;

    printf("1. Login\n");
    printf("2. Signup\n");
    printf("3. Back\n");

    invalid:
    printf("Enter your choice: ");

    if (scanf("%d", &choice) != 1){
        printf("Invalid Input!\n");
        scanf("%*[^\n]");
        goto invalid;
    }

    reenter:
    switch (choice) {
        case 1: // Login
            printf("Note: enter '0' to go back.\n");
            printf("Enter the ID number: ");

            if (scanf("%d", &ID) != 1){
                printf("Invalid Input!\n");
                scanf("%*[^\n]");
                goto reenter;
            }else if(ID == 0){goto invalid;}

            for (int i = 0;i <= MAX_PASSENGERS;i++){ //searching
                if(pasngr[i].ID == ID){
                    printf("Logged in successfully!");
                   return ID;
                }
            }
            ID = 0;
            if(!ID){
                printf("Your ID isn't found.\nPlease, reenter your ID or signup.\n");
                goto reenter;
            }

            break;
        case 2: // Signup
            printf("Note: enter '0' to go back.\n");
            printf("Enter the ID number: ");
            if (scanf("%d", &ID) != 1){
                printf("Invalid Input!\n");
                scanf("%*[^\n]");
                goto reenter;
            }else if(ID == 0){goto invalid;}

            for (int i = 0;i <= MAX_PASSENGERS;i++){ //searching
                if(pasngr[i].ID == ID){
                   printf("Your account already exists. Please, enter an absent ID.\n");
                   goto reenter;
                }
            }
            pasngr[passengersExist++].ID = ID;
            printf("Your account is created successfully!\n");
            return ID;
        case 3: // Back
            passenger_Settings();
            break;
        default:
            printf("Invalid Input!\n");
            goto invalid;
    }
};

