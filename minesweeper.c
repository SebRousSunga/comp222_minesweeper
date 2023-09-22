#include <stdio.h>
#include <string.h>


// for new 10 20 50

int main(void){
     char cmd[20]; 
     char token[10][80];
     char * ptr;
     int r,c,m;
     int tcount = 0;


  while(1){

     printf(">> ");
     fgets(cmd,80,stdin);
     cmd[strlen(cmd)-1] = '\0';
     printf("Entered %s\n", cmd);

     ptr = strtok(cmd," "); // first argu is string to token, second call is NULL, to distinguished
     while( ptr != NULL){
         strcpy(token[tcount],ptr);
         tcount++;
         ptr = strtok(NULL, " ");
     }
       for(int i = 0 ; i<tcount; i++){
       	printf("token %d = %s\n", i, token[i]);
       }
      
     

      //if(strcpy(cmd, "quit") == 0)
      	// scanf has no error catching

        if(strcpy(token[0],"new") == 0)
        	 printf("ERROR");
     }
    system("pause");
	return 0;
}