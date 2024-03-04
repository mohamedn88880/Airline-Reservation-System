#include <stdio.h>
#include <string.h>
#include "projectHeader.h"
flightsExist=0;
void update_flight(int flight_num){
    int flag = 0;
    int choice,confirm;
    char check[20];


    for(int i = 0 ; i < flightsExist ; i++){
        if(trip[i].flightNumber == flight_num){
            flag = 1;
            invalid:
            all:
            printf("\n1. update departure city\n");
            printf("2. update departure time\n");
            printf("3. update arrival city\n");
            printf("4. update arrival time\n");
            printf("5. update flight date\n");
            printf("6. update all\n");
            printf("7. back\n");
            printf("\n\nEnter your choice: ");

            scanf("%d",&choice);

            fflush(stdin);
            switch (choice) {
            case 1:

                printf("Enter new departure city: ");
                gets(check);
                Invalid1 :
                printf("(1). confirm\n");
                printf("(2). back\n");
                printf("\nEnter your choice: ");
                scanf("%d",& confirm);
                switch(confirm){
                case 1:
                    strcpy(trip[i].departureCity , check);
                    printf("\n******updated successfully******\n\n");
                    goto all;

                case 2:
                    printf("\n***NO changes occurred***\n");
                    goto all;
                default :
                    printf("Invalid choice!!!");
                    goto Invalid1;
                }





            case 2:
                printf("Enter new departure time: ");
                gets(check);
                Invalid2 :
                printf("(1). confirm\n");
                printf("(2). back\n");
                printf("\nEnter your choice: ");
                scanf("%d",& confirm);
                switch(confirm){
                case 1:
                    strcpy(trip[i].departureTime , check);
                    printf("\n******updated successfully******\n\n");
                    goto all;

                case 2:
                    printf("\n***NO changes occurred***\n");
                    goto all;
                default :
                    printf("Invalid choice!!!");
                    goto Invalid2;
                }

            case 3:
                printf("Enter new arrival city: ");
                gets(check);
                Invalid3 :
                printf("(1). confirm\n");
                printf("(2). back\n");
                printf("\nEnter your choice: ");
                scanf("%d",& confirm);
                switch(confirm){
                case 1:
                    strcpy(trip[i].arrivalCity , check);
                    printf("\n******updated successfully******\n\n");
                    goto all;

                case 2:
                    printf("\n***NO changes occurred***\n");
                    goto all;
                    break;
                 default :
                    printf("Invalid choice!!!");
                    goto Invalid3;
                }


            case 4:
                printf("Enter new arrival time: ");
                gets(check);
                Invalid4:
                printf("(1). confirm\n");
                printf("(2). back\n");
                printf("\nEnter your choice: ");
                scanf("%d",& confirm);
                switch(confirm){
                case 1:
                    strcpy(trip[i].arrivalTime , check);
                    printf("\n******updated successfully******\n\n");
                    goto all;

                case 2:
                    printf("\n***NO changes occurred***\n");
                    goto all;
                    break;
                 default :
                    printf("Invalid choice!!!");
                    goto Invalid4;
                }



            case 5:
                printf("Enter new flight date: ");
                gets(check);
                Invalid5:
                printf("(1). confirm\n");
                printf("(2). back\n");
                printf("\nEnter your choice: ");
                scanf("%d",& confirm);
                switch(confirm){
                case 1:
                    strcpy(trip[i].flightDate , check);
                    printf("\n******updated successfully******\n\n");
                    goto all;

                case 2:
                    printf("\n***NO changes occurred***\n");
                    goto all;
                    break;
                 default :
                    printf("Invalid choice!!!");
                    goto Invalid5;
                }


            case 6:
            printf("\n\nEnter new departure city: ");
            gets(trip[i].departureCity        );

            printf("Enter new departure time: ");
            gets(trip[i].departureTime        );
            printf("Enter new arrival city: ");
            gets(trip[i].arrivalCity          );

            printf("Enter new arrival time: ");
            gets(trip[i].arrivalTime          );

            printf("Enter new flight date: ");
            gets(trip[i].flightDate           );

            printf("\n\n***Flight schedule updated successfully!***\n\n");
            goto all;

                case 7:
                admin_Settings();
                break;


            default:
                printf("Invalid Input!");
                goto all;

        }
        }



    }
     if(!flag) {
        printf("\nFlight schedule not found!\n\n");
        admin_Settings();
    }



}
//////////////////////////////Add New flight
void New_Flight_Schedule(void)
{
    if((flightsExist<MAX_FLIGHTS))
    {
         int choice=0,choice1,count,Flight_Number;
         for(count=0;count<=flightsExist;count++)
         {
             invalid:
             printf("\nEnter The Flight Number:");
             if (scanf("%i", &Flight_Number) != 1)
            {
             printf("Invalid Input!");
             scanf("%*[^\n]");
             goto invalid;
             }
             if((trip[count].flightNumber)!=Flight_Number)
             {
                 trip[flightsExist].flightNumber=Flight_Number;
                 break;
             }
             else
             {
                 printf("Invalid!!!Thers is another Flight With This Number\n");
                 New_Flight_Schedule();
             }
         }
         invalid1 :
         printf("Enter The Number of Seats:");
         if (scanf("%i", &trip[flightsExist].availableSeats)!= 1){
             printf("Invalid Input\n!");
             scanf("%*[^\n]");
             goto invalid1;
         }
         fflush(stdin);

         printf("Enter The Flight Date:");
         gets(trip[flightsExist].flightDate);

         printf("Enter The Departure_city:");
         gets(trip[flightsExist].departureCity );

         printf("Enter The Departure_Time:");
         gets(trip[flightsExist].departureTime);

         printf("Enter The Arrival_city:");
         gets(trip[flightsExist].arrivalCity);

         printf("Enter The Arrival_Time:");
         gets(trip[flightsExist].arrivalTime);
          Invalid2:
          printf("1. Save The Informatiom\n");
          printf("2. To change \n");
                    printf("Enter your choice: ");
                    scanf("%i",&choice1);
                    switch(choice1)
                    {
                          case 2 :
                              New_Flight_Schedule();
                              break;
                          case 1 :
                                printf("\n...You Add New Flight Schedule Successfully...\n");
                                flightsExist++;
                                break;
                         default :
                         printf("Invalid choice!!!");
                         goto Invalid2;
                    }
         Invalid3:
         printf("\n(1) To Go To Admin Setting\n");
         printf("(2) To Quit                 \n");
         printf("Enter your choice: ");
         scanf("%i",&choice);
         switch(choice)
         {
               case 1 :
                  admin_Settings();
               case 2 :
                   return (0);
                   break;
                 default :
                    printf("Invalid choice!!!");
                    goto Invalid3;
         }
    }
    else
    {
        int choice=0;
        printf("\nSorry, You can't add a new_Flight. The System Is Full !!!\n");
        Invalid:
        printf("\n(1) to Admin Setting\n");
        printf("(2) to Quit           \n");
        printf("Enter your choice: ");
        scanf("%i",&choice);
        switch(choice)
        {
            case 1 :
                 admin_Settings();
                 break;
            case 2 :
                return(0);
                break;
            default:
            printf("Invalid Input!");
            goto invalid;
        }

    }
}
////////////////////////////////////////////////////////////////////// Search Available Flights

void Search_Available_Flights (int passengerID) {

        char DepartureCity[50], ArrivalCity[50], FlightDate[20] ;
        fflush(stdin);
        all:
     printf("Enter The Departure city: ");
     fflush(stdin);
     gets( DepartureCity) ;

     printf("Enter The Arrival city: ");
     fflush(stdin);
     gets(ArrivalCity) ;

     printf("Enter The Flight Date: ");
     gets(FlightDate) ;


    int flag = 0, choice ;

    for(int i = 0 ; i < flightsExist ; i++){

        if(strcmp(trip[i].departureCity , DepartureCity) ==0 && strcmp(trip[i].arrivalCity, ArrivalCity)==0 &&
            strcmp(trip[i].flightDate , FlightDate)==0){
            flag ++ ;
            printf("\n\n*****Available*****\n\n") ;
            printf("\nDeparture time: %s", trip[i].departureTime);
            printf("\nArrival time: %s\n\n", trip[i].arrivalTime);

        }

    }

       if(flag != 0){

            Invalid:
            printf("1. Search for other flight\n");
            printf("2. back\n");
            printf("\nEnter your choice: ");

            scanf("%d", &choice);

            switch (choice){

            case 1 :
                goto all ;

            case 2 :
                passenger_Settings() ;
                break;
             default :
                    printf("Invalid choice!!!");
                    goto Invalid;
            }
       }

        else {
            printf("\n\nUnavailable\n\n") ;
            printf("1. Search for other flight\n");
            printf("2. back\n");
            printf("\nEnter your choice: ");

            scanf("%d", &choice);

            switch (choice){
            case 1 :
                goto all ;

            case 2 :
                passenger_Settings() ;
                break;

            }
        }

}


//////////////display flights
void display_Flights() {
    int miny;
    printf("\n\n\nFlight Schedules:\n");
    printf("------------------------------------------------------------------------------------------------\n");
   printf("%-15s%-20s%-20s%-15s%-15s%-15s\n","Flight number", "Departure City", "Arrival City", "Departure Time", "Arrival Time", "Flight Date");
    printf("-------------------------------------------------------------------------------------------------\n");

   for (int i = 0; i < flightsExist; i++) {
        printf("%-15d%-20s%-20s%-15s%-15s%-15s\n",
               trip[i].flightNumber,trip[i].departureCity,
               trip[i].arrivalCity, trip[i].departureTime,
               trip[i].arrivalTime, trip[i].flightDate);
    }

    printf("--------------------------------------------------------------------------------------------------\n\n\n");
    printf("1. admin settings\n");
    printf("2. passenger settings\n");
    printf("Enter your choice: ");
    scanf("%d",&miny);
    switch(miny){
case 1:
    admin_Settings();
    break;

case 2:
    passenger_Settings();
    break;
    }

}
/////////////////////////////
int deleteFlight(){
        unsigned int choice;
        int flightID;
        reenter:
        printf ("please enter the flight\nNumber you want to delete: ");
                scanf("%d",&flightID);

               for (int i=0;i<flightsExist;i++){
                if(trip[i].flightNumber==flightID){
                     trip[i] = trip[i+1];

                    printf("Flight schedule %d delete successfully.\n",flightID);
                    flightsExist--;
                    Invalid:
                    printf("\n1. to Admin Setting\n");
                    printf("2. to Quit           \n");
                    printf("Enter your choice: ");
                    scanf("%i",&choice);

                    switch(choice)
                    {
                        case 1 :
                        admin_Settings();
                             break;
                        case 2 :
                            return(0);
                    }

                }
                else{
                    printf("Flight %s not found.\n\n",flightID);
                    printf("\n(1) to Admin Setting\n");
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
                           printf("Invalid choice!!!");
                           goto Invalid;
                    }


     }


}
}

