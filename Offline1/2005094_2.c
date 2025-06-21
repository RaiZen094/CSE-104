#include<stdio.h>

int digit(int n)
{

    int count=0;

    while(n>=1)
    {

        n=n/10;
        count++;
    }

    return count;



}
int datechecker(int n,int j,int i)
{

    int m,y,p,t,h;


    if(j==1||j==2)
    {

        m=12+j;
        y=i-1;
    }

    else
    {
        m=j;
        y=i;

    }
    p=(26*(m+1))/10;
    t=n+p+y+(y/4)+(6*(y/100))+(y/400);
    h=t%7;
    if (h==0)
        return 7;
    return h;
}
int main()
{


    int i,j,n=1,date,y,m;
    printf("Enter the year:");
    scanf("%d",&y);
    printf("Enter month(1-12):");
    scanf("%d",&m);
    printf("Calender for:\n\n");
    if(m==1)
    {


        printf("JANUARY,%d \n",y);
    }
    else if(m==2)
    {


        printf("FEBRUARY,%d \n",y);
    }
    else if(m==3)
    {


        printf("MARCH,%d \n",y);
    }
    else if(m==4)
    {


        printf("APRIL,%d \n",y);
    }
    else if(m==5)
    {


        printf("MAY,%d \n",y);
    }
    else if(m==6)
    {


        printf("JUNE,%d \n",y);
    }
    else if(m==7)
    {


        printf("JULY,%d \n",y);
    }
    else if(m==8)
    {


        printf("AUGUST,%d \n",y);
    }
    else if(m==9)
    {


        printf("SEPTEMBER,%d \n",y);
    }
    else if(m==10)
    {


        printf("OCTOBER,%d \n",y);
    }
    else if(m==11)
    {


        printf("NOVEMBER,%d \n",y);
    }
    else
    {
        printf("DECEMBER,%d \n",y);
    }
    printf("SUN MON TUE WED THU FRI SAT\n");
    if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
    {
        date=32;
    }
    else if(m==2)
    {
        date=29;
    }
    else
    {
        date=31;
    }

    for(i=1; i<=6; i++)
    {

        for(j=1; j<=7; j++)
        {
            if((datechecker(n,m,y))==j)
            {
                if(i<=3&&digit(n)==1)
                {
                    printf("  %d ",n);
                }
                else
                {
                    printf(" %d ",n);
                }
                n++;
            }
            else
            {
                printf("    ");
            }
            if(n>=date)
            {
                break;
            }

        }
        printf("\n");




    }


}
