#include <stdio.h>
#include <string.h>
#include "projectHeader.h"
TicketExist=0;
passengersExist=0;
void New_Passenger_Resservation(int passengerID)
{
    int Erorr_State=0;
    int Flight_Number;
    char Name[20];
    char Address[100];
    long long phoneNumber;
    char Departure_City[50];
    char Arrival_City  [50];
    char Travilling_Date[20];
    int count;

        fflush(stdin );
        printf("Enter Your Name:");
        gets(Name    );

        printf("Enter your Adress:");
        gets(Address );
        reenter :
        printf("Enter Your Phone Number:");
        if ( scanf("%lli",&phoneNumber)!= 1){
                printf("Invalid Input!\n");
                scanf("%*[^\n]");
                goto reenter;
            }

        Invalid :
        fflush(stdin );
        printf("Enter The Number of Flight:");
         if (scanf("%i",&Flight_Number)!= 1){
                printf("Invalid Input!\n");
                scanf("%*[^\n]");
                goto Invalid;
            }

        for(count=0;count<=flightsExist;count++)
        {
            if((trip[count].flightNumber)==Flight_Number)
            {
                      if(TicketExist<MAX_PASSENGERS)
                {
                    int choice = 0,choice1;
                    Erorr_State=1;
                    printf("Enter (1) To Save The Informatiom\n");
                    printf("Enter (0) To change \n");
                    scanf("%i",&choice1);
                    switch(choice1)
                    {
                    case 1 :
                         memcpy(pasngr[passengersExist].Name   ,Name,20              );
                         strcpy(pasngr[passengersExist].Address,Address              );
                         pasngr[passengersExist].phoneNumber = phoneNumber            ;
                         tkt   [TicketExist].passengerID     = passengerID;
                         tkt   [TicketExist].number          =TicketExist+1             ;
                         tkt   [TicketExist].flightNumber     =trip[count].flightNumber;
                         break;
                    case 0 :
                        New_Passenger_Resservation(passengerID);

                    }
                    printf("There is Avalible Ticket For you                                   \n");
                    printf("The Date For Your flight is = %s\n",trip[count].flightDate);
                    printf("The Number of Your Ticketis =%i \n" ,tkt[TicketExist].number);
                    fflush(stdin);
                    printf("Enter The Date of your Reservation:                         \n");
                    gets(tkt[TicketExist].resDate                                        );

                    printf("\n*Your Reservation is Accepted !!*\n");
                    TicketExist++;
                    passengersExist++;
                    Invalid1 :
                    printf("\n(1) To Passenger Seeting\n");
                    printf("(2) To Quit             \n");
                    printf("Enter your choice: ");
                    scanf("%i",&choice);

                    switch(choice)
                    {
                        case 1 :
                              passenger_Settings();
                        case 2 :
                              return (0);
                              break;
                        default :
                            printf("Invalid Choise !!!\n");
                            goto Invalid1;
                    }
                }
                else
                {
                    int choice;
                    printf("Sorry The Tickets Are Full!!!\n\n");
                    All:
                    printf("\n(1) To Try Again\n");
                    printf("(2) To Passenger Seeting\n");
                    printf("(3) To Quit     \n");
                    printf("Enter Your Choise:");
                    scanf("%i",&choice);
                    switch(choice)
                    {
                         case 1 :
                             goto Invalid;

                          case 2 :
                             passenger_Settings();
                          case 3 :
                             return (0);
                             break;
                          default :
                            printf("Invalid Choise !!!\n");
                            goto All;
                    }
                }
        }
        }
        if(Erorr_State==0)
        {
            int choice=0;
            printf("\nSorry,There Is Not Avalible Reservation for This Place!!!\n");
            All1:
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
                    break;
                default :
                    printf("Invalid Choise !!!\n");
                    goto All1;
            }
        }
}


////////////////////////////////////////////////////////////////////////////




////////////////////////////////////////////////////////////////////////////
void modify_reservation(int passengerID){
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
                Invalid1:
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
                  default :
                            printf("Invalid Choise !!!\n");
                            goto Invalid1;
                }



            case 2:
                printf("Enter new passenger address: ");
                gets(check);
                Invalid:
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
                     default :
                            printf("Invalid Choise !!!\n");
                            goto Invalid;
                }

            case 3:
                printf("Enter new phone number: ");

                scanf("%d",& checkint);
                Invalid2:
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
                  default :
                    printf("Invalid Choise !!!\n");
                    goto Invalid2;
                }


            case 4:
                printf("Enter new passenger ID: ");
                scanf("%lld",& checkint);
                Invalid3:
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
                     default :
                            printf("Invalid Choise !!!\n");
                            goto Invalid3;
                }



            case 5:
                printf("Enter new flight number: ");

                scanf("%d",& checkint);
                Invalid4:
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
                     default :
                            printf("Invalid Choise !!!\n");
                            goto Invalid4;
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
////////////////////////////////////////////////////////////////////// Show reservation log
void Show_Reservation_Log(void){

    int flag = -1, choice ;
    long long passengerID;
    printf("Enter your ID: ");
    scanf("%lld",&passengerID);
    for(int i = 0; i < TicketExist; i++){
        if(tkt[i].passengerID == passengerID )
            flag = i ;
            break;
    }

    if(flag != -1){
    printf("\nYour Flight Schedules:\n");
    printf("-----------------------------------------------------------------------------------------------------------------\n");
    printf("%-20s%-20s%-20s%-20s\n","flight number", "passenger ID",  "passenger Name", "Flight Date");
    printf("-----------------------------------------------------------------------------------------------------------------\n");
   for (int j = flag; j < flightsExist; j++) {
        printf("%-20d%-20d%-20s%-20s\n",
               trip[j].flightNumber,tkt[j].passengerID,
               pasngr[j].Name,
               trip[j].flightDate);
    }

    printf("--------------------------------------------------------------------------------------------------------------------\n");
    passenger_Settings();
    }

    else{
        printf("THERE IS NO RESERVATION");
    }


     passenger_Settings() ;

}

/////////////////////////
int reservationcancel()
{
    unsigned int choice;
    int numberreservation;

    reenter:
    printf("please enter your ticket number:\n");
    scanf("%d",&numberreservation);
    int i;
    for ( i; i < TicketExist; i++)
    {
        if(tkt[i].number==numberreservation)
        {
            for(int j = i;j < TicketExist;j++){
                tkt[j] = tkt[j+1];
            printf("the number cancelled successfully");
            TicketExist--;
            Invalid :
            printf("\n(1) to Passenger Setting\n");
            printf("(2) to Quit           \n");
            scanf("%i",&choice);

            switch(choice)
                {
                    case 1 :
                        passenger_Settings();
                        break;
                    case 2 :
                        return(0);
                        break;
                     default :
                            printf("Invalid Choise !!!\n");
                            goto Invalid;
                }

        }
        }
        else
        {
            printf("the number reservation not found\n\n");
            Invalid1:
            printf("\n(1) to Try again\n");
            printf("(2) to Quit           \n");
            scanf("%i",&choice);

            switch(choice)
                {
                    case 1 :
                        goto reenter;
                        break;
                    case 2 :
                        return(0);
                        break;
                       default :
                            printf("Invalid Choise !!!\n");
                            goto Invalid1;
                }

        }


    }
}
