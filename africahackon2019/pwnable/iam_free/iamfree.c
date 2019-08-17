#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>

 #define gets_s(x, len) fgets((x), (len) + 1, stdin)

struct moves_t  {
  unsigned int king;
  unsigned int queen;
  unsigned int  pawn;
  unsigned int checkmate;

};

int main( int argc, char *argv[] ) {

  setuid(1007);  
  struct moves_t *myMove;
  int size = sizeof(struct moves_t);

  struct moves_t *play = malloc(size);
  printf("Let play a game of chess\n");
  
  
  while(1){
    
    printf("Make your move : ");
    gets_s(play,size);

    if(play->king == 0x46524545 && play->queen == 0x71756565 && play->pawn == 0x6e333e3a){


        free(myMove);
        printf("Nice move. I can't catchup\n");
    }
    else if(play->king == 0x4e455721 && play->queen == 0x4b494e47 && (unsigned char)((play->pawn   ) * sizeof(int) + 5) == 0x1){
      
        myMove = malloc(size);
        myMove->checkmate = play->checkmate;

        printf("King placed in order\n");
      
    }
    else if(play->king == 0x75733334 && play->queen == 0x66743352 && play->pawn == 0x66523333){

        printf("Brilliant. One last Move\n");

        if ((unsigned char)myMove->checkmate == (unsigned char)0x6d343137)
        {
          system("/bin/cat flag");

          return 0;
        }
    }


    else{

      printf("Wrong move\n");
    }
  

  }
  

  return 0;

}