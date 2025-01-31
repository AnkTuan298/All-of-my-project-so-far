/****************************************************************
╰（‵□′）╯ I CAN'T BELIVE HOW THE TEACHER MADE US DO THIS
Referring code made by SFMSupersanta.
Program: PRF101
version #
****************************************************************/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double slope(double arrx[], double arry[], int n, double Mx, double My)     //function to caculate slope
{
    double nominator = 0,denominator = 0;
    for (int i = 0; i <= n; i++)
    {
        nominator += (arrx[i]-Mx)*(arry[i]-My);
        denominator += (arrx[i]-Mx)*(arrx[i]-Mx);
    }
    return nominator/(denominator);
}
//correlation coefficient
double corco(double arrx[], double arry[], int n, double Mx, double My, double Dx, double Dy)
{
    double tpros;//total product sum
    for (int i = 0; i <= n;i++)
    {
        tpros += arrx[i]*arry[i];
    }
    return (((tpros/(n+1))-(Mx*My))/(Dx*Dy));
}

double deviation(double Sx, int n, double MxS)    
{
    return sqrt((Sx/(n+1))-MxS);
}

int deviationi(int Sx, int n, int MxS)    
{
    return sqrt((Sx/(n+1))-MxS);
}

double mean(double data[], int size)
{
    double sum=0;
    for (int i = 0; i <= size;i++)
    {
        sum += data[i];
        
    }
    sum /= (size+1);
    return sum;
}

double Ssum(double data[], int size)     //sum of squares
{
    double Ssum=0;                        //squared sum variable
    for (int i = 0; i <= size;i++)
    {
        Ssum += data[i]*data[i];
    }
    
    return Ssum;
}

int main()
{
    char filename[100];
    printf("Regression Analysis\n===================\nEnter the name of the data file : ");
    gets (filename);
    FILE *fileP = NULL;                                                          //initialize file pointer variable
    fileP = fopen (filename,"r");
    if (fileP != NULL)
    {
        double x_val[100];
        double y_val[100];
        char c;
        int rec_count = 0;                                                           //seprate variable to count in while function
        do
        {
            c = fgetc (fileP);
            if (c == '\n') rec_count++;
        }while(!feof (fileP));
        //printf ("rec_count: %d\n", rec_count);

        rewind (fileP);

        for (int i = 0; i <= rec_count; i++)
        {
            fscanf(fileP, "%lf", &x_val[i]);
            fscanf(fileP, "%lf", &y_val[i]);
        }
        
        printf("\nThe number of data values read from this file was %d\n",rec_count+1);

        //test code:
        for(int i = 0; i <= rec_count; i++)
        {
            printf("x%d: %.2lf, y%d: %.2lf", i+1, x_val[i], i+1, y_val[i]);
            printf("\n");
        }
        //test code end.
        //caculations and assing
        double Mx = mean(x_val,rec_count);
        double My = mean(y_val,rec_count);
        double Sx = Ssum(x_val,rec_count);
        double Sy = Ssum(y_val,rec_count);
        double Dx = deviation(Sx, rec_count, Mx*Mx);
        double Dy = deviation(Sy, rec_count, My*My);
        //caculations ends.
        
        //print caculations value
        printf("Their statistical mean of the abscissa values is %.2lf\n",Mx);
        printf("Their standard deviation of the abscissa values is %.2lf\n",Dx);
        printf("Their statistical mean of the ordinate values is %.2lf\n",My);
        printf("Their standard deviation of the ordinate values is %.2lf\n",Dy);
        
        //print slope, y-intercept, cc
        double t=slope(x_val,y_val,rec_count,Mx,My);
        printf("\nThe slope of the least squares fit is %.2lf\n",t);
        printf("The y-intercept of the least squares fit is  %.2lf\n", My-t*Mx);
        printf("The correlation coefficient is %.2lf\n", corco(x_val,y_val,rec_count,Mx,My,Dx,Dy));
        
        //FML how can i do this while the "learning website can't even tell how it works"
        printf("\nWhat is the age of your car in months ? ");
        int age;
        scanf("%d",&age);
        printf("You can expect a stopping distance of %.2lf meters", (t*age)+(My-t*Mx));

        fclose(fileP);
    }
    else printf("Failed to open the file for reading");
    return 0;
}

/*###########################################################
###################
#TEST CASE(ctrc+v)#
###################
text file: sample_2.dat
 9 28.4
15 29.3
24 37.6
30 36.2 
38 36.5
46 35.3
53 36.2 
60 44.1
64 44.8
76 47.2 
###################
#   EXAMPLE:      #
###################
 Regression Analysis
 ===================
 Enter the name of the data file : sample_2.dat

 The number of data values read from this file was 10
 Their statistical mean of the abscissa values is 41.50
 Their standard deviation of the abscissa values is 20.98 
 Their statistical mean of the ordinate values is 37.56
 Their standard deviation of the ordinate values is 5.92

 The slope of the least squares fit is 0.26
 The y-intercept of the least squares fit is 26.94
 The correlation coefficient is 0.91

 What is the age of your car in months ? 32
 You can expect a stopping distance of 35.13 metres
###########################################################*/