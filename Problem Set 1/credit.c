//Made by siraponte

//Libraries
#include <stdio.h>
#include <cs50.h>
#include <math.h>

//Main function
int main(void)
{
    
    int long n = get_long("Credit Card Number : ");
    int long c, c2, d1 = 1, d10 = 10;
    
    int l = 1 + log10(n);
    int s = 0;
    
    //Function to take 16 digits cards
    if (l % 2 == 0)
    {
        //Loop to sum odd digits
        for (int i = 0 ; i < l / 2 ; i++)
        {
            c = ((n / d1) % 10);
            
            s += c;
            
            d1 *= 100;
        }
        //Loop to sum even digits
        for (int i2 = 0 ; i2 < l / 2 ; i2++)
        {
            c2 = (((n / d10) % 10) * 2);
            
            //Function to separate double digits numbers
            if (c2 > 9)
            {
                s += ((c2 % 10) + ((c2 / 10) % 10));
            }
            else
            {
                s += c2;
            }
            d10 *= 100;
        }
    }
    //Function to take 13 and 15 digits cards
    else
    {
        //Loop to sum odd digits
        for (int i3 = 0 ; i3 < l / 2 + 1 ; i3++)
        {
            c = ((n / d1) % 10);
            
            s += c;
            
            d1 *= 100;
        }
        //Loop to sum even digits numbers
        for (int i4 = 0 ; i4 < l / 2 ; i4++)
        {
            c2 = (((n / d10) % 10) * 2);
            
            //Function to separate double digits
            if (c2 > 9)
            {
                s += ((c2 % 10) + ((c2 / 10) % 10));
            }
            else
            {
                s += c2;
            }
            d10 *= 100;
        }
    }
    
    int long d12 = 1000000000000, d13 = 10000000000000, d14 = 100000000000000, d15 = 1000000000000000;
    
    int g12 = (n / d12), g13 = (n / d13), g14 = (n / d14), g15 = (n / d15);
    
    //Function to print the right cards' names
    if ((s % 10) == 0)
    {
        if (l == 13)
        {
            if (g12 == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (l == 15)
        {
            if ((g13 == 34) || (g13 == 37))
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (l == 16)
        {
            if (g15 == 4)
            {
                printf("VISA\n");
            }
            else if ((g14 == 51) || (g14 == 52) || (g14 == 53) || (g14 == 54) || (g14 == 55))
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
            
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
