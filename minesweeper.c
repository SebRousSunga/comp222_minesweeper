#include <stdio.h>
#include <string.h>
vi


#define MAXTOKENCOUNT 20
#define MAXTOKENLENGTH 20
#define MAXLINELENGTH 400

// for new 10 20 50

void getinput(char line[],int linelen){
  fgets(line,linelen,stdin);
    int len = strlen(linelen);
    if(line[len-1] = '\n') line[len-1] = '\0';

    printf("Returned : %s", line);


}

void gettokens(char line[], char tokens[MAXTOKENCOUNT][MAXTOKENLENGTH],int * count){
    char linecpy = line[MAXLINELENGTH];
    strcpy(linecpy,line);

    char * ptr;

    ptr = strtok(linecpy," ");
    
   
     while(ptr != NULL){
        strcpy(tokens[*count],ptr);

         ptr = strtok(NULL, " ");
         *count++;
     }
}

 int processcommand(char tokens[][MAXTOKENLENGTH], int tokencount){
    if(strcmp(tokens[0],"new") == 0 ){
        printf("NEW COMMAND CHOSEN");
    }
    else if(strcmp(tokens[0],"show") == 0){
        printf(" SHOW COMMAND CHOSEN");
    }
    else if (strcmp(tokens[0],"quit" == 0)){
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
     int r,c,m; // values for rows column,
     int tcount = 0; // how many tokens there are, so we can place into proper

   // GAME STATE

  while(1){

     printf(">> ");
     getinput(cmd,MAXLINELENGTH);
     gettokens(cmd, token, &tcount);
    result = processcommand(tokens,tcount);

     if(result == 0) break;
    


     
      
     }

     //END OF GAME STATE

}

int main(void){

    rungame();
    system("pause");
	return 0;
}