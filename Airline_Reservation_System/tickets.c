#include <stdio.h>
#include <string.h>
#include "projectHeader.h"
TicketExist=0;
passengersExist=0;
void New_Passenger_Resservation(void)
{
    int Erorr_State=0;
    int ID,Flight_Number;
    char Name[20];
    char Address[100];
    long long phoneNumber;
    char Departure_City[50];
    char Arrival_City  [50];
    char Travilling_Date[20];
    int count;

        fflush(stdin );
        printf("Enter Your Name:        \n");
        gets(Name    );

        printf("Enter your Adress:      \n");
        gets(Address );

        printf("Enter you IDE:          \n");
        scanf("%i",&ID);
        printf("Enter Your Phone Number:\n");
        scanf("%lli",&phoneNumber);

        Invalid :
        display_Flights();
        fflush(stdin );
        printf("Enter The Number of Flight:\n");
        scanf("%i",&Flight_Number);
        for(count=0;count<=flightsExist;count++)
        {
            if((trip[count].flightNumber)==Flight_Number)
            {
                      if(TicketExist<MAX_PASSENGERS)
                {
                    int choice = 0;
                    Erorr_State=1;

                    strcpy(pasngr[passengersExist].Name   ,Name                 );
                    strcpy(pasngr[passengersExist].Address,Address              );
                    pasngr[passengersExist].ID          =ID                      ;
                    pasngr[passengersExist].phoneNumber = phoneNumber            ;
                    tkt   [TicketExist].passengerID     =ID                      ;
                    tkt   [TicketExist].number          =TicketExist             ;
                    tkt   [TicketExist].flightNumber     =trip[count].flightNumber;

                    printf("There is Avalible Ticket For you                                   \n");
                    printf("The Date For Your flight is = %s\n",trip[count].flightDate);
                    printf("The Number of Your Ticketis =%i \n" ,tkt[TicketExist].number);
                    fflush(stdin);
                    printf("Enter The Date of your Reservation:                         \n");
                    gets(tkt[TicketExist].resDate                                        );

                    printf("\n*Your Reservation is Accepted !!*\n");
                    TicketExist++;
                    passengersExist++;

                    printf("\n(1) To Passenger Seeting\n");
                    printf("(2) To Quit             \n");
                    scanf("%i",&choice);

                    switch(choice)
                    {
                        case 1 :
                              passenger_Settings();
                        case 2 :
                              return (0);
                    }
                }
                else
                {
                    int choice;
                    printf("Sorry The Tickets Are Full!!!\n");
                    printf("\n(1) To Try Again\n");
                    printf("(2) To Passenger Seeting\n");
                    printf("(3) To Quit     \n");
                    scanf("%i",&choice);
                    switch(choice)
                    {
                         case 1 :
                             goto Invalid;

                          case 2 :
                             passenger_Settings();
                          case 3 :
                             return (0);
                    }
                }
        }
        }
        if(Erorr_State==0)
        {
            int choice=0;
            printf("\nSorry,There Is Not Avalible Reservation for This Place!!!\n");
            printf("\n(1) To Try Again\n");
            printf("(2) To Passenger Seeting\n");
            printf("(3) To Quit     \n");
            scanf("%i",&choice);
            switch(choice)
            {
                case 1 :
                     goto Invalid;

                case 2 :
                    passenger_Settings();
                case 3 :
                    return (0);
            }
        }
}


////////////////////////////////////////////////////////////////////////////




////////////////////////////////////////////////////////////////////////////
void modify_reservation(void){
    unsigned int flag = 0,choice,confirm ,ticket_num;
    char check[100];
    long long checkint;
    printf("\n\nEnter the number of ticket: ");
        scanf("%d",&ticket_num);
    for(int i = 0 ; i < passengersExist ; i++){
        if(tkt[i].number == ticket_num){
            flag = 1;
            all:

            printf("\n1. update passenger name\n");
            printf("2. update passenger address\n");
            printf("3. update phoneNumber\n");
            printf("4. update passenger ID\n");
            printf("5. update flight number\n");
            printf("6. update ALL\n");
            printf("7. Back\n");
            printf("\nEnter your choice: ");
            scanf("%d",&choice);
            fflush(stdin );
            switch(choice){
            case 1:
                printf("Enter new passenger name: ");
                gets(check);
                printf("(1). confirm\n");
                printf("(2). back\n");
                printf("\nEnter your choice: ");
                scanf("%d",& confirm);
                switch(confirm){
                case 1:
                    strcpy(pasngr[i].Name , check);
                    printf("\n******updated successfully******\n\n");
                    goto all;

                case 2:
                    printf("\n***NO changes occurred***\n");
                    goto all;
                }



            case 2:
                printf("Enter new passenger address: ");
                gets(check);
                printf("(1). confirm\n");
                printf("(2). back\n");
                printf("\nEnter your choice: ");
                scanf("%d",& confirm);
                switch(confirm){
                case 1:
                    strcpy(pasngr[i].Address , check);
                    printf("\n******updated successfully******\n\n");
                    goto all;

                case 2:
                    printf("\n***NO changes occurred***\n");
                    goto all;
                }

            case 3:
                printf("Enter new phone number: ");

                scanf("%d",& checkint);
                printf("(1). confirm\n");
                printf("(2). back\n");
                printf("\nEnter your choice: ");
                scanf("%d",& confirm);
                switch(confirm){
                case 1:
                    pasngr[i].phoneNumber = checkint;
                    printf("\n******updated successfully******\n\n");
                    goto all;

                case 2:
                    printf("\n***NO changes occurred***\n");
                    goto all;
                }


            case 4:
                printf("Enter new passenger ID: ");
                scanf("%lld",& checkint);
                printf("(1). confirm\n");
                printf("(2). back\n");
                printf("\nEnter your choice: ");
                scanf("%d",& confirm);
                switch(confirm){
                case 1:
                    pasngr[i].ID = checkint;
                    printf("\n******updated successfully******\n\n");
                    goto all;

                case 2:
                    printf("\n***NO changes occurred***\n");
                    goto all;
                }



            case 5:
                printf("Enter new flight number: ");

                scanf("%d",& checkint);
                printf("(1). confirm\n");
                printf("(2). back\n");
                printf("\nEnter your choice: ");
                scanf("%d",& confirm);
                switch(confirm){
                case 1:
                    tkt[i].flightNumber = checkint;
                    printf("\n******updated successfully******\n\n");
                    goto all;

                case 2:
                    printf("\n***NO changes occurred***\n");
                    goto all;
                }




            case 6:
                printf("\nEnter new passenger name: ");
                gets(pasngr[i].Name);

                printf("Enter new passenger address: ");
                gets(pasngr[i].Address);

                printf("Enter new phone number: ");
                scanf("%d",&pasngr[i].phoneNumber);

                printf("Enter new passenger ID: ");
                scanf("%lld",&pasngr[i].ID);

                printf("Enter new flight number: ");
                scanf("%d",&tkt[i].flightNumber);
                printf("\n\n***updated successfully!***\n\n");
                goto all;

            case 7:
                passenger_Settings();

            }

        }
        
    }
    if(!flag){
                printf("\nReservation not exist!\n\n");

                passenger_Settings();
            }

}

