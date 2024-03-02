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
                }





            case 2:
                printf("Enter new departure time: ");
                gets(check);
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
                }




            case 3:
                printf("Enter new arrival city: ");
                gets(check);
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
                }


            case 4:
                printf("Enter new arrival time: ");
                gets(check);
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
                }



            case 5:
                printf("Enter new flight date: ");
                gets(check);
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


        if(!flag) {
        printf("\nFlight schedule not found!\n\n");
        admin_Settings();
    }
    }



}
//////////////////////////////Add New flight
void New_Flight_Schedule(void)
{
    if((flightsExist<MAX_FLIGHTS))
    {
         int choice=0;
         printf("\nEnter The Flight Number:  \n");
         scanf("%i",&trip[flightsExist].flightNumber );

         printf("Enter The Number of Seats:\n");
         scanf("%i",&trip[flightsExist].availableSeats);
         fflush(stdin);

         printf("Enter The Flight Date:   \n");
         gets(trip[flightsExist].flightDate           );

         printf("Enter The Departure_city:\n");
         gets(trip[flightsExist].departureCity        );

         printf("Enter The Departure_Time:\n");
         gets(trip[flightsExist].departureTime        );

         printf("Enter The Arrival_city:  \n");
         gets(trip[flightsExist].arrivalCity          );

         printf("Enter The Arrival_Time:  \n");
         gets(trip[flightsExist].arrivalTime          );

         printf("\n...You Add New Flight Schedule Successfully...\n");
         flightsExist++;

         printf("\n(1) To Go To Admin Setting\n");
         printf("(2) To Quit                 \n");
         scanf("%i",&choice);
         switch(choice)
         {
               case 1 :
                  admin_Settings();
               case 2 :
                   return (0)   ;
         }
    }
    else
    {
        int choice=0;
        printf("\nSorry, You can't Add Anew_Flight. The System Is Full !!!\n");

        printf("\n(1) to Admin Setting\n");
        printf("(2) to Quit           \n");
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
}

//////////////display flights
void display_Flights() {
    printf("\nFlight Schedules:\n");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("| Flight Number | departure city           | Departure Time   | arrival city      | arrival time  | available seats    \n");
    printf("------------------------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < flightsExist ; i++) {
        printf("| %d             | %s               |           %s   |             %s|             %s|             %d|            %s|\n", trip[i].flightNumber, trip[i].departureCity, trip[i].departureTime, trip[i].arrivalCity, trip[i].arrivalTime, trip[i].availableSeats ,trip[i].flightDate);
    }

    printf("------------------------------------------------------------------------------------------------------------------------\n");
}

