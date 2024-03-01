#include <stdio.h>
#include <string.h>

struct passenger{
    int passengerID;
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

struct passenger pasngr[MAX_PASSENGERS];
struct ticket tkt[MAX_PASSENGERS];
int TicketExist = 0;
int passengersExist = 0;

void modify_reservation(){
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

            switch(choice){
            case 1:
                printf("Enter new passenger name: ");
                scanf("%s",& check);
                printf("1. confirm\n");
                printf("2. back\n");
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
                scanf("%s",& check);
                printf("1. confirm\n");
                printf("2. back\n");
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
                printf("1. confirm\n");
                printf("2. back\n");
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
                printf("1. confirm\n");
                printf("2. back\n");
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
                printf("1. confirm\n");
                printf("2. back\n");
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
                scanf("%s",&pasngr[i].Name);

                printf("Enter new passenger address: ");
                scanf("%s",&pasngr[i].Address);

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
        if(!flag){
                printf("\nReservation not exist!\n\n");

                passenger_Settings();
            }
    }

}
///////////////////////////////////////////////////////////////
int New_Passenger_Resservation(void)
{
    int Erorr_State=0;
    int Numbers=passengersExist;
    int ID;
    char Name[20];
    char Address[100];
    char phoneNumber[20];
    char Departure_City[20];
    char Arrival_City  [20];
    char Travilling_Date[50];
    int count;
        fflush(stdin  );

        printf("Enter Your Name:        \n");
        gets(Name     );


        printf("Enter your Adress:      \n");
        gets(Address  );

        printf("Enter you IDE:          \n");
        scanf("%i",&ID);

        fflush(stdin  );
        printf("Enter Your Phone Number:\n");
        scanf("%c",&phoneNumber);

        Invalid :
        fflush(stdin);
        printf("Enter The Departure City:  \n");
        gets(Departure_City);
        printf("Enter The Arrival City :   \n");
        gets(Arrival_City  );
        printf("Enter The Date for Travel: \n");
        gets(Travilling_Date);
        for(count=0;count<flightsExist;count++)
        {
            if((trip[count].departureCity==Departure_City)&&
               (trip[count].arrivalCity  ==Arrival_City  )&&
               (trip[count].flightDate   ==Travilling_Date))
            {
                      if(passengersExist<MAX_PASSENGERS)
                {
                    int choice = 0;
                    Erorr_State=1;

                    strcpy(pasngr[passengersExist+1].Name       ,Name                     );
                    strcpy(pasngr[passengersExist+1].ID         ,ID                       );
                    strcpy(pasngr[passengersExist+1].Address    ,Address                  );
                    strcpy(pasngr[passengersExist+1].phoneNumber,phoneNumber              );


                    printf("There is Avalible Ticket For you                                  \n");
                    printf("\nThe Number of Your Flight is = %i      \n",trip[count].flightNumber);
                    printf("The Number of Your Ticket is = %i\n",tkt[TicketExist+1].number       );
                    printf("The Date For Your flight is = %c\n",trip[count].flightDate           );
                    printf("The Departure City is = %c      \n ",trip[count].departureCity       );
                    printf("The Arrival City is = %c        \n",trip[count].arrivalCity          );
                    printf("The Departure Time is = %c      \n",trip[count].departureTime        );
                    printf("The Arrival Time is = %c        \n",trip[count].arrivalTime          );
                    printf("Enter The Date of your Reservation:                               \n");
                    gets(tkt[TicketExist+1].resDate                                              );

                    printf("\n****Your Reservation is Accepted !!****1\n");
                    TicketExist++;
                    Numbers++;

                    printf("\n(1) To Passenger Seeting\n");
                    printf("(2) To Quit             \n");
                    scanf("%i",choice);

                    switch(choice)
                    {
                        case 1 :
                              passenger_Settings();
                        case 2 :
                              return (0);
                    }
                    break;
                }

            }
        }
        if(Erorr_State==0)
        {
            int choice=0;
            printf("\nSorry,There Is Not Avalible Reservation for This Place!!!\n");
            printf("\n(1) To Try Again\n");
            printf("(2) To Quit     \n");
            scanf("%i",&choice);
            switch(choice)
            {
                case 1 :
                     goto Invalid;
                     break;
                case 2 :
                    return (0);
            }
        }
    return(Numbers);
}
