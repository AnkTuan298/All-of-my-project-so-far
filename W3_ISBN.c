/****************************************************************
(▀̿Ĺ̯▀̿ ̿)
Referring code made by SFMSupersanta.
Program: PRF101
version #
****************************************************************/

#include <stdio.h>
#include <stdlib.h>

int numcheck(int num)
{
    int check_digit = num % 10;
    num /= 10;
    int weighted_sum = 0;
    int total_sum;
    for(int i = 2; i <= 10; i++) 
    {
        int product = i * (num % 10);
        num /= 10;
        weighted_sum += product;
        //printf("%d\n", product);   for debugging only
    }
    total_sum = weighted_sum + check_digit;
    if(total_sum % 11 == 0) 
        return 1;
    else
        return 0;
}

int main()
{
    int num;
    printf("ISBN Validator\n=============\n");
    do
    {
        printf("ISBN (0 to quit): ");
        scanf("%d", &num);
        if(num == 0)
        { 
            printf("Have a Nice Day!");
            break;                           //thoát khỏi vòng do-for         
        }
        if(numcheck(num)==1)
        { 
            printf("This is a valid ISBN.\n");
        }
        else printf("This is not a valid ISBN.\n");
    }
    while(num != 0);
}