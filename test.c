// toi da~ lam' qua' nhieu' game nhan pham^ roi'
/****************************************************************
(▀̿Ĺ̯▀̿ ̿)
Referring code made by SFMSupersanta.
Program: PRF101
version #
****************************************************************/

#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>

int compare_arr(char a[], char b[])
{
    for(int i = 0; i <2;i++)
    {
        if (a[i] != b[i]) return 0;
    }
    return 1;
}

char rank_gen()
{  
    int temp = (rand()%13) +1; //randnum 0-12
    char rank;
    if(temp == 1) rank = 'A';
    else if (temp == 10) rank = '10';
    else if(temp ==11) rank = 'J';
    else if(temp == 12) rank = 'Q';
    else if(temp == 13) rank = 'K';
    else rank = temp+'0';
    printf("rank: %d\n", temp);
    return rank;
}

char suit_gen()
{
    int temp = (rand() % 4) + 1;
    char suit;
    if(temp==1) suit='H';
    else if(temp==2) suit='D';
    else if(temp==3) suit = 'S';
    else if(temp == 4) suit = 'C';
    printf("suit: %d\n", temp);
    return suit;
}


int main()
{
  for(int i = 0; i <30;i++)
  {
    char draw[2] = {suit_gen(),rank_gen(),};
    printf("Generated %d : ",i);
    for (int j = 0; j < 2; j++) printf("%c",draw[j]);
    printf("\n");
  }
  return 0;
}