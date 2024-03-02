#include <stdio.h>
#include <string.h>

#define MAX_FLIGHTS100



   int deleteFlight(int flightID,int numflight[500]);

     int main ( ){
      int x= flightID;
      int y=numflight[500];
    deleteFlight(x,y);

       }
   int deleteFlight(int flightID,int numflight[100]){




      printf ("please enter the flightID you want to delete");
               scanf("%d",&flightID);
               for (int i=0;i<numflight[500];i++){
                if(numflight[500].flightID==flightID){
                     numflight[i]= numflight[i+1];

               printf("Flight schedule %d delete successfully.\n",flightID);
               return true;
                }
                     else{
                 printf("Flight %s not found.\n",flightID);
                 return false;

     }


               }

   }
