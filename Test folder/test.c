
#include<stdio.h>
//#include "validator.h"

 /* clear empties input buffer */ 
 void clear_buffer (void)
 {
     char c;
     while ((c=getchar()) != '\n'&&c!=EOF);
 }

char getChar(char msg[], char limit[])
 {
     int count=0;
     while(limit[count] != '\0') count++; 

     int keeptrying = 1;

     char value;
     do
     {
        printf("%s", msg);
        value = getchar();
        {
            for(int i=0; i<count; i++)
            {
                if(value == limit[i])
                {
                    if(getchar() == '\n') keeptrying==0;
                    else clear_buffer();
                }
            }
        }
     } while (keeptrying == 1);

     return value;
 }

int main()
{   
    char c;
    printf("Input char: %c", c=getChar("Input char: ", "abcdefgABCDEFG"));
    return 0;
}