#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define gets_s(x, len) fgets((x), (len) + 1, stdin)

int parseName(char *name){
  char loginName[20];
  size_t nameLength = strlen(name);
  uint8_t testVar = nameLength+0x1;
  if( testVar > 20)
    return 0;  
	 
  memcpy((char *) loginName, name, nameLength);
  return 1;

}

/*We will delete later I don't have time to delete it*/

void systemCheck(){
  system("/bin/cat flag");

}

int main( int argc, char *argv[] )  {
	
	char username[300];
  	int parsed;
	
	setuid(1000);
	printf("The real user ID is %d\n", getuid());	
	printf("Enter you name: ");
	gets_s((char *)&username, 300);
			
  	printf("Parsing the username \n");

  	parsed = parseName((char *) &username);
	
  	if(parsed){
    		printf("Name meets standards. Bye :)\n");
 	 }	
  	else{
    		printf("Name failed to meet standards. Bye:)\n");
 	 }
  

	return 0;

}