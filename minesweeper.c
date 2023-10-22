#include <stdio.h>
#include <string.h>
#include <stdlib.h>



#define MAXTOKENCOUNT 20
#define MAXTOKENLENGTH 20
#define MAXLINELENGTH 400

// ******************* PART 1 **************************** \\
// Part 1 of minesweeper project for COMP 222
// Abilty to tokenize and read in user input and implement a system to output based on user input



// Global Cell struct
 
   
// Cell struct that contains all cell information 
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




 /// Functions  

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

    ptr = strtok(linecpy," "); // Go through string, separate when reaching divisor
    
   
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

// Initizlize board 

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
        printf("NEW COMMAND CHOSEN\n");       
        rows = atoi(tokens[1]);
        cols = atoi(tokens[2]);
        mines = atoi(tokens[3]);
        command_new(rows,cols,mines); // Create game board using a cell** board, a pointer to pointers essentailly
    }
    else if(strcmp(tokens[0],"show") == 0){
        printf(" SHOW COMMAND CHOSEN\n");
        command_show();
    }
    else if (strcmp(tokens[0],"quit") == 0){
        printf(" QUIT COMMAND CHOSEN\n");
        return 0;
    }
   
    return 1;
 }

 
   
 // Game state function

void rungame(){

     /* Initialized values for simple input collecting */
     char cmd[MAXLINELENGTH];   // array of char to take in input
     char token[MAXTOKENCOUNT][MAXTOKENLENGTH];  // matrix to take in tokenized strings

     int result; // 


     char * ptr;  // pointer for strtok and travel through tokenization
     
      // how many tokens there are, so we can place into proper

      



   // GAME STATE

  while(1){
     int tcount = 0;
     printf(">> ");
     getinput(cmd,MAXLINELENGTH); //read user input and puts them into cmd and token arrays
     gettokens(cmd, token, &tcount); // takes input into cpy to separate commands into separate parts ot token array
     result = processcommand(token,&tcount);
     if(result == 0){ // quit command returns zero to exit gamestate
        break;
     }
   
    


     
      
     }

     //END OF GAME STATE

}

///End of functions

int main(void){

    rungame();
	return 0; 
}


/* Things to do
   Create command_new and command_show function <--- DONE
   Set up mine laying algorithim and adjacency count for game logic setup <--- IN-PROGRESS
   Create full game logic for player usage <--- N/A
   Error handling of User-input <--- N/A

   




*/