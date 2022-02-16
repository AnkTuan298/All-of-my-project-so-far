/****************************************************************
(▀̿Ĺ̯▀̿ ̿)
Referring code made by SFMSupersanta.
Program: Input validation
version #
****************************************************************/

#include <stdio.h>
#include <stdbool.h>

//\input stream clear function\*
void clear()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}


//GetDouble(char str[], double, double)  returns double from min to max
double GetDouble(char msg[], double min, double max)
{
    double value;
    int rc;

    while (true) 
    {
        printf("%s", msg);
        printf("in the range [%.2lf,%.2lf] : ",min, max);
        rc = scanf("%lf",&value);
        if(rc == 0)
        {
            printf("**No input accepted!**\n");
            clear();
        }
        else if(getchar() != '\n')
        {
            printf("**Trailing characters!**\n");
            clear();
        }
        else if(value < min || value > max)
        {
            printf("**Out of range!**\n");
        }
        else break;
    }
    return value;
}

//GetInt(char str[], long long min, long long max) returns long long from min to max
long long  GetInt(char msg[], long long  min, long long max)
{
    long long value;
    int rc;

    while (true) 
    {
        printf("%s", msg);
        printf("in the range [%lld,%lld] : ",min, max);
        rc = scanf("%lld",&value);
        if(rc == 0)
        {
            printf("**No input accepted!**\n");
            clear();
        }
        else if(getchar() != '\n')
        {
            printf("**Trailing characters!**\n");
            clear();
        }
        else if(value < min || value > max)
        {
            printf("**Out of range!**\n");
        }
        else break;
    }
    return value;
}

//GetChar

int main()
{
    double input = GetDouble("Enter the number\n",10,20);
    long long Int = GetInt("Enter the integer\n",1,10000000);
    printf("\nProgram accepted %.2lf %lld\n",input,Int);
    return 0;
}