#include<stdio.h>
int main()
{


    int m,y,q,i,j,h,p,t;
    printf("Enter the year:");
    scanf("%d",&i);
    printf("Enter the month(1-12):");
    scanf("%d",&j);
    printf("Enter the date:");
    scanf("%d",&q);
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
    t=q+p+y+(y/4)+(6*(y/100))+(y/400);
    h=t%7;
    if(j==1)
    {
        if(h==0)
        {
            printf("JANUARY %d,%d  is SATURDAY.",q,i);
        }
        if(h==1)
        {
            printf("JANUARY %d,%d  SUNDAY.",q,i);
        }
        if(h==2)
        {
            printf("JANUARY %d,%d is MONDAY.",q,i);
        }
        if(h==3)
        {
            printf("JANUARY %d,%d is TUESDAY.",q,i);
        }
        if(h==4)
        {
            printf("JANUARY %d,%d is WEDNESDAY.",q,i);
        }
        if(h==5)
        {
            printf("JANUARY %d,%d is THURSDAY.",q,i);
        }
        if(h==6)
        {
            printf("JANUARY %d,%d is FRIDAY.",q,i);
        }

    }
    else if(j==2)
    {
        if(h==0)
        {
            printf("FEBRUARY %d,%d  is SATURDAY.",q,i);
        }
        if(h==1)
        {
            printf("FEBRUARY %d,%d  SUNDAY.",q,i);
        }
        if(h==2)
        {
            printf("FEBRUARY %d,%d is MONDAY.",q,i);
        }
        if(h==3)
        {
            printf("FEBRUARY %d,%d is TUESDAY.",q,i);
        }
        if(h==4)
        {
            printf("FEBRUARY %d,%d is WEDNESDAY.",q,i);
        }
        if(h==5)
        {
            printf("FEBRUARY %d,%d is THURSDAY.",q,i);
        }
        if(h==6)
        {
            printf("FEBRUARY %d,%d is FRIDAY.",q,i);
        }
    }
    else if(j==3)
    {
        if(h==0)
        {
            printf("MARCH %d,%d  is SATURDAY.",q,i);
        }
        if(h==1)
        {
            printf("MARCH %d,%d  SUNDAY.",q,i);
        }
        if(h==2)
        {
            printf("MARCH %d,%d is MONDAY.",q,i);
        }
        if(h==3)
        {
            printf("MARCH %d,%d is TUESDAY.",q,i);
        }
        if(h==4)
        {
            printf("MARCH %d,%d is WEDNESDAY.",q,i);
        }
        if(h==5)
        {
            printf("MARCH %d,%d is THURSDAY.",q,i);
        }
        if(h==6)
        {
            printf("MARCH %d,%d is FRIDAY.",q,i);
        }
    }

    else if(j==4)
    {
        if(h==0)
        {
            printf("APRIL %d,%d  is SATURDAY.",q,i);
        }
        if(h==1)
        {
            printf("APRIL %d,%d  SUNDAY.",q,i);
        }
        if(h==2)
        {
            printf("APRIL %d,%d is MONDAY.",q,i);
        }
        if(h==3)
        {
            printf("APRIL %d,%d is TUESDAY.",q,i);
        }
        if(h==4)
        {
            printf("APRIL %d,%d is WEDNESDAY.",q,i);
        }
        if(h==5)
        {
            printf("APRIL %d,%d is THURSDAY.",q,i);
        }
        if(h==6)
        {
            printf("APRIL %d,%d is FRIDAY.",q,i);
        }
    }

    else if(j==5)
    {
        if(h==0)
        {
            printf("MAY %d,%d  is SATURDAY.",q,i);
        }
        if(h==1)
        {
            printf("MAY %d,%d  SUNDAY.",q,i);
        }
        if(h==2)
        {
            printf("MAY %d,%d is MONDAY.",q,i);
        }
        if(h==3)
        {
            printf("MAY %d,%d is TUESDAY.",q,i);
        }
        if(h==4)
        {
            printf("MAY %d,%d is WEDNESDAY.",q,i);
        }
        if(h==5)
        {
            printf("MAY %d,%d is THURSDAY.",q,i);
        }
        if(h==6)
        {
            printf("MAY %d,%d is FRIDAY.",q,i);
        }
    }

    else if(j==6)
    {
        if(h==0)
        {
            printf("JUNE %d,%d  is SATURDAY.",q,i);
        }
        if(h==1)
        {
            printf("JUNE %d,%d  SUNDAY.",q,i);
        }
        if(h==2)
        {
            printf("JUNE %d,%d is MONDAY.",q,i);
        }
        if(h==3)
        {
            printf("JUNE %d,%d is TUESDAY.",q,i);
        }
        if(h==4)
        {
            printf("JUNE %d,%d is WEDNESDAY.",q,i);
        }
        if(h==5)
        {
            printf("JUNE %d,%d is THURSDAY.",q,i);
        }
        if(h==6)
        {
            printf("JUNE %d,%d is FRIDAY.",q,i);
        }
    }

    else if(j==7)
    {
        if(h==0)
        {
            printf("JULY %d,%d  is SATURDAY.",q,i);
        }
        if(h==1)
        {
            printf("JULY %d,%d  SUNDAY.",q,i);
        }
        if(h==2)
        {
            printf("JULY %d,%d is MONDAY.",q,i);
        }
        if(h==3)
        {
            printf("JULY %d,%d is TUESDAY.",q,i);
        }
        if(h==4)
        {
            printf("JULY %d,%d is WEDNESDAY.",q,i);
        }
        if(h==5)
        {
            printf("JULY %d,%d is THURSDAY.",q,i);
        }
        if(h==6)
        {
            printf("JULY %d,%d is FRIDAY.",q,i);
        }
    }
    else if(j==8)
    {
        if(h==0)
        {
            printf("AUGUST %d,%d  is SATURDAY.",q,i);
        }
        if(h==1)
        {
            printf("AUGUST %d,%d  SUNDAY.",q,i);
        }
        if(h==2)
        {
            printf("AUGUST %d,%d is MONDAY.",q,i);
        }
        if(h==3)
        {
            printf("AUGUST %d,%d is TUESDAY.",q,i);
        }
        if(h==4)
        {
            printf("AUGUST %d,%d is WEDNESDAY.",q,i);
        }
        if(h==5)
        {
            printf("AUGUST %d,%d is THURSDAY.",q,i);
        }
        if(h==6)
        {
            printf("AUGUST %d,%d is FRIDAY.",q,i);
        }
    }
    else if(j==9)
    {
        if(h==0)
        {
            printf("SEPTEMBER %d,%d  is SATURDAY.",q,i);
        }
        if(h==1)
        {
            printf("SEPTEMBER %d,%d  SUNDAY.",q,i);
        }
        if(h==2)
        {
            printf("SEPTEMBER %d,%d is MONDAY.",q,i);
        }
        if(h==3)
        {
            printf("SEPTEMBER %d,%d is TUESDAY.",q,i);
        }
        if(h==4)
        {
            printf("SEPTEMBER %d,%d is WEDNESDAY.",q,i);
        }
        if(h==5)
        {
            printf("SEPTEMBER %d,%d is THURSDAY.",q,i);
        }
        if(h==6)
        {
            printf("SEPTEMBER %d,%d is FRIDAY.",q,i);
        } ;
    }
    else if(j==10)
    {
        if(h==0)
        {
            printf("OCTOBER %d,%d  is SATURDAY.",q,i);
        }
        if(h==1)
        {
            printf("OCTOBER %d,%d  SUNDAY.",q,i);
        }
        if(h==2)
        {
            printf("OCTOBER %d,%d is MONDAY.",q,i);
        }
        if(h==3)
        {
            printf("OCTOBER %d,%d is TUESDAY.",q,i);
        }
        if(h==4)
        {
            printf("OCTOBER %d,%d is WEDNESDAY.",q,i);
        }
        if(h==5)
        {
            printf("OCTOBER %d,%d is THURSDAY.",q,i);
        }
        if(h==6)
        {
            printf("OCTOBER %d,%d is FRIDAY.",q,i);
        };
    }

    else if(j==11)
    {
        if(h==0)
        {
            printf("NOVEMBER %d,%d  is SATURDAY.",q,i);
        }
        if(h==1)
        {
            printf("NOVEMBER %d,%d  SUNDAY.",q,i);
        }
        if(h==2)
        {
            printf("NOVEMBER %d,%d is MONDAY.",q,i);
        }
        if(h==3)
        {
            printf("NOVEMBER %d,%d is TUESDAY.",q,i);
        }
        if(h==4)
        {
            printf("NOVEMBER %d,%d is WEDNESDAY.",q,i);
        }
        if(h==5)
        {
            printf("NOVEMBER %d,%d is THURSDAY.",q,i);
        }
        if(h==6)
        {
            printf("NOVEMBER %d,%d is FRIDAY.",q,i);
        } ;
    }
    else if(j==12)
    {
        if(h==0)
        {
            printf("DECEMBER%d,%d  is SATURDAY.",q,i);
        }
        if(h==1)
        {
            printf("DECEMBER%d,%d  SUNDAY.",q,i);
        }
        if(h==2)
        {
            printf("DECEMBER%d,%d is MONDAY.",q,i);
        }
        if(h==3)
        {
            printf("DECEMBER%d,%d is TUESDAY.",q,i);
        }
        if(h==4)
        {
            printf("DECEMBER%d,%d is WEDNESDAY.",q,i);
        }
        if(h==5)
        {
            printf("DECEMBER%d,%d is THURSDAY.",q,i);
        }
        if(h==6)
        {
            printf("DECEMBER%d,%d is FRIDAY.",q,i);
        }
    }





}
