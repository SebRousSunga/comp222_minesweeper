#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>



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

        int mined;

        int covered;

     }; typedef struct Cell cell;

     cell **board;
     int rows;
     int cols;
     int mines;
     int m_r; 
     int m_c;

     int curr_row;
     int curr_col;

    int neighbors = 8; // eight neighbors of cell
    int row_neigh[] = {-1,-1,0,1,1,1,0,-1};
    int col_neigh[] = { 0, 1,1,1,0,-1,-1,-1};






 /// Functions  

 int get_rand(int range){
    return ((int)floor((float)range*rand()/RAND_MAX))%range;
 }    

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
         if(c->covered == 1) printf("%2s","/");
         else if(c->mined == 1) printf("%2s", "*");
         else if (c->flagged == 1) printf("%2s", "P");
         else if(c->adjcount > 0) printf("%2s", c->adjcount);
         else printf("%2s", ".");
         
         
    }

  

// Get adjacency count of cell
int get_adj_count(int r, int c){
    
    int minecount = 0;
    for(int i = 0; i < neighbors ; i++){
        int rn = r + row_neigh[i];
        int cn = c + col_neigh[i];
      if(rn >= 0 && rn < rows && cn >= 0 && cn < rows){
         if(board[rn][cn].mined == 1)
            minecount++;
      }  
    }
     return minecount;
};  

void init_cell(cell * cell, int p){
    cell->position = p;
    cell->mined = 0;
    cell->covered = 1;
    cell->flagged = 0;
    cell->adjcount = 0;
}
  void coverall(){  //test function to cover entire board. 
    for(int i = 0 ; i < rows ; i++){
        for(int j = 0 ; j < cols; j++)
            board[i][j].covered = 1 ;
    }
  }

   void showall(){
    for(int i = 0 ; i < rows ; i++){
        for(int j = 0 ; j < cols; j++)
            board[i][j].covered = 0 ;
    }

   }

// Initizlize board 

 void command_new(int r, int c, int m){  // Make board, 

    board = (cell **) malloc(sizeof(cell *) * r);

    for(int i = 0 ; i < r; i++){
        board[i] = (cell *) malloc(sizeof(cell) * c);
    }

      for(int i = 0 ; i< rows; i++){
        for(int j = 0 ; j <cols; j++){
            int position = i * cols + j;
            init_cell(&board[i][j], position);

           
        }
      } //Start mine laying
        for(int m = 0; m < mines; m++){
            m_r = get_rand(r);
            m_c = get_rand(c);
            while(board[m_r][m_c].mined == 1){
                m_r = get_rand(r);
                m_c = get_rand(c);
            }
            board[m_r][m_c].mined = 1;
        }
      for(int a_rr = 0 ; a_rr < r ; a_rr++){
        for(int a_cc = 0; a_cc < c ; a_cc++){
       board[a_rr][a_cc].adjcount = get_adj_count(a_rr,a_cc); // set cell's adjacency count
         }
     }

        
     }

///////      
  void command_show(){
        for(int i = 0 ; i < rows; i++){
            for(int j = 0 ; j<cols; j++){
                display_cell(&board[i][j]);
            }
            printf("\n");
        }
       }

      void uncover_recursion(int r, int c){

      }

    void command_uncover(int r, int c){
          //Some form of error checking so that user input is within bounds of game
          if(r <= rows && c <= cols){
            if(board[r][c].mined == 1)
                printf("MINED. GAME OVER");
            
            else if(board[r][c].adjcount != 0){
                board[r][c].covered = 0;
                return;

            }
        }
        else
            printf("Input outside of board range. Try another. \n");
    }

    void command_flag(int r, int c){
        if(r <= rows && c <= cols){
        board[r][c].flagged = 1;
        board[r][c].mined = 0;
        board[r][c].covered = 0;
      }
      else
       printf("Input outside of board range. Try another. \n");  
    }

    void command_unflag(int r, int c){
        if(r <=rows && c <= cols)
            board[r][c].flagged = 0;
        else
            printf("Input outside of board range. \n");
        
    }
  




  int processcommand(char tokens[MAXTOKENCOUNT][MAXTOKENLENGTH], int * tokencount){
    if(strcmp(tokens[0],"new") == 0 ){
              
        rows = atoi(tokens[1]);
        cols = atoi(tokens[2]);
        mines = atoi(tokens[3]);
        command_new(rows,cols,mines); // Create game board using a cell** board, a pointer to pointers essentailly
    }
    else if(strcmp(tokens[0],"show") == 0){
        printf("\n");
        command_show();
    }

    else if (strcmp(tokens[0], "uncover") == 0){
        
          int r_g = atoi(tokens[1]); //- 1;
          int c_g = atoi(tokens[2]); //- 1 ;
          r_g = r_g - 1;
          c_g = c_g - 1;
          command_uncover(r_g,c_g);

    }

    else if (strcmp(tokens[0], "flag") == 0){
        int r_f = atoi(tokens[1]) - 1 ;
        int c_f = atoi(tokens[2]) - 1;
        command_flag(r_f, c_f);
    }

    else if (strcmp(tokens[0],"quit") == 0){
        
        return 0;
    }

    else if (strcmp(tokens[0], "showall") == 0){
        showall();
    }
   
    return 1;
 }

 
   
 // Game state function

void rungame(){

     /* Initialized values for simple input collecting */
     char cmd[MAXLINELENGTH];   // array of char to take in input
     char token[MAXTOKENCOUNT][MAXTOKENLENGTH];  // matrix to take in tokenized strings
     srand(time(0));

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
   adjacentcy count shows how many of the 
   
    if uncovered cell is not mined, then show adjacency count, which is how many neighbors are mined.Assume neighbors are 0,2,3,..,8 is for each direction



*/