/****************************************************************
[]~(￣▽￣)~*]
Referring code made by SFMSupersanta.
Program: PRF101
version #
****************************************************************/
#include <stdio.h>
#include <math.h>

void time_cal(double velocity, double height, double delta, double *pt1, double *pt2)
{   
    //printf("\ndelta: %lf\nvelocity: %lf\nheight: %lf", delta,velocity,height);
    double g = 9.8;
    if (delta > 0)
    {
        *pt1 = (- velocity + sqrt(delta)) / (2 * g);
        *pt2 = (- velocity - sqrt(delta)) / (2 * g);
    }
    else if (delta == 0)
    {
        *pt1 =  (- velocity + sqrt(delta)) / (2 * g);
    }
    
}

int main()
{
    printf("Fireworks\n=========\n");

    double velocity;
    double height, t1,t2;
    do
    {
        printf("Initial vertical velocity (m/sec) (0 to quit) : ");
        scanf("%lf", &velocity);

        if (velocity == 0) 
        {
            printf("\nHave a nice day!\n");  
        }
        else
        {
            double g = 9.8;
            printf("Desired height (m):                             ");
            scanf("%lf", &height);
            double height_that_never_can_be_reached = height;
            //times 2 for how the equation works
            velocity *= 2;
            height *= 2;
            //also because of the equation
            velocity = -velocity;
            double delta = velocity*velocity - 4*(g*height);
        
            time_cal(velocity, height, delta, &t1,&t2);
            if(delta >0)
            {
                printf("\nYour firework will reach the desired height at times:\n");
                printf("  %.2lf sec\n  %.2lf sec\n", t1,t2);
            }
            else if (delta == 0)
            {
                printf("\nYour firework will reach the desired height at times:\n");
                printf("  %.2lf sec\n", t1);
            }
            else if (delta < 0)
            {
                printf("\nYour firework will never reach %.2lf m\n",height_that_never_can_be_reached);
            }
            printf("\n");
        }

    }while(velocity != 0);

    return 0;
}
/*#######################
###################
#TEST CASE(ctrc+v)#
###################
20 10
20 20.408163265306122
20 21
0

###################
#   EXAMPLE:      #
###################
 Fireworks
 =========
 Initial vertical velocity (m/sec) (0 to quit) : 20
 Desired Height (m):                             10

 Your firework will reach the desired height at times:
   0.58 sec
   3.50 sec

 Initial vertical velocity (m/sec) (0 to quit) : 20
 Desired Height (m):                             20.408163265306122 

 Your firework will reach the desired height at time:
   2.04 sec

 Initial vertical velocity (m/sec) (0 to quit) : 20
 Desired Height (m):                             21

 Your firework will never reach 21.00 m

 Initial vertical velocity (m/sec) (0 to quit) : 0

 Have a Nice Day!
#########################*/