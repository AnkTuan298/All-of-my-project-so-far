/****************************************************************
(〃￣︶￣)人(￣︶￣〃))
Referring code made by SFMSupersanta.
Program: EAN
version #
****************************************************************/

#include <stdio.h>
#include <stdlib.h>

void clear_buffer (void);

long long getInt(char msg[], long long min, long long max) ;

int check_digit(long long ean);

int main()
{
    long long isbn = getInt("Enter the ISBN:",0,9999999999);
    long long EAN = 9780000000000 + isbn;
    printf("EAN: %lld\n",(EAN-(EAN%10))+check_digit(EAN));
    return 0;
}

int check_digit(long long ean)
{
    ean/=10;
    int sum=0;  
    for(int i=0; i<13;i++)
    {
        if(i%2==0) 
        {
            sum += (ean%10)*3;
            ean /=10;
        }
        else
        {
            sum += ean %10;
            ean/=10;
        }
        //printf("sum: %d\n",sum);
    }
    //printf("%d\n",sum);
    return 10-(sum%10);
}

 /* clear empties input buffer */ 
 void clear_buffer (void)
 {
     char c;
     while ((c=getchar()) != '\n'&&c!=EOF);
 }

 long long getInt(char msg[], long long min, long long max) 
{
     char val[20];           //input value
     long long intval;
     int count,rc;      //int value and count value
     while(1)
     {
         printf("%s", msg);
         count = 0;
         rc =0;
         fgets(val,20,stdin);

         if(val[0]!='\n')
         {
             if(0<max&&0>min) if(val[0]=='0' && val[1] == '\n') return 0;
             for(int i=0; i< 20; i++) 
             {
                 if(val[i]=='\n') rc = 1;
             } 
             if(rc==0) clear_buffer();
             char *ovf;

             intval = strtoll(val,&ovf,10);
             
 
             if(intval<=0) count++;

             long long intvaldup = intval;
 
             while(intvaldup!=0)
             {
                 intvaldup/=10;
                 count++;
             }

             if (val[count] != '\n')  printf("**Trailing Character(s)**\n");
             else if(min<intval&&intval<max)
             {
                 return intval;
             }else printf("**OUT OF RANGE**\n");
         } else printf("**No input**\n");
     }
 }
