#include <stdio.h>
#include <string.h>
#include <stdlib.h>



#define MAXTOKENCOUNT 20
#define MAXTOKENLENGTH 20
#define MAXLINELENGTH 400



// Global Cell struct
 
   

  struct Cell {
        int position;

        int flagged;

        int adjcount;

        int mine;

        int covered;

     }; typedef struct Cell cell;

     cell **board;
     int rows;
     int cols;
     int mines;


 // Functions  

void getinput(char line[],int linelen){
  fgets(line,linelen,stdin);
    int len = strlen(line);
    if(line[len-1] = '\n') line[len-1] = '\0';

    printf("Returned : %s", line);


}

  void gettokens(char line[], char tokens[MAXTOKENCOUNT][MAXTOKENLENGTH],int * count){
      char linecpy[MAXLINELENGTH];
      strcpy(linecpy,line);

    char * ptr;

    ptr = strtok(linecpy," ");
    
   
     while(ptr != NULL){
        strcpy(tokens[*count],ptr);

        ptr = strtok(NULL, " ");
         (*count)++;
     }
}

     void display_cell(cell * c){
         // printf("%4d",c->position);
        printf("3s","/");
    }

 

 void command_new(int r, int c, int m){  // Make board, 

    board = (cell **) malloc(sizeof(cell *) * r);

    for(int i = 0 ; i < r; i++){
        board[i] = (cell *) malloc(sizeof(cell) * c);
    }

      for(int i = 0 ; i< rows; i++){
        for(int j = 0 ; j <cols; j++){
            board[i][j].position = i * cols + j;
        }
      }

        
     }
  void command_show(){
        for(int i = 0 ; i < rows; i++){
            for(int j = 0 ; j<cols; j++){
                display_cell(&board[i][j]);
            }
            printf("\n");
        }
       }
  




  int processcommand(char tokens[MAXTOKENCOUNT][MAXTOKENLENGTH], int * tokencount){
    if(strcmp(tokens[0],"new") == 0 ){
        printf("NEW COMMAND CHOSEN");       
        rows = atoi(tokens[1]);
        cols = atoi(tokens[2]);
        mines = atoi(tokens[3]);
        command_new(rows,cols,mines);
    }
    else if(strcmp(tokens[0],"show") == 0){
        printf(" SHOW COMMAND CHOSEN");
        command_show();
    }
    else if (strcmp(tokens[0],"quit") == 0){
        printf(" QUIT COMMAND CHOSEN");
        return 0;
    }
   
    return 1;
 }

 
   
 

void rungame(){

     /* Initialized values for simple input collecting */
     char cmd[MAXLINELENGTH];   // array of char to take in input
     char token[MAXTOKENCOUNT][MAXTOKENLENGTH];  // matrix to take in tokenized strings

     int result;


     char * ptr;  // pointer for strtok and travel through tokenization
     
      // how many tokens there are, so we can place into proper

      



   // GAME STATE

  while(1){
     int tcount = 0;
     printf(">> ");
     getinput(cmd,MAXLINELENGTH);
     gettokens(cmd, token, &tcount);
     result = processcommand(token,&tcount);
 
    // printf("%d", result);
    


     
      
     }

     //END OF GAME STATE

}

int main(void){

    rungame();
	return 0;
}


/* Things to do
   Need to implement board

   Figure out the why. I persume it's a seg fault




*/