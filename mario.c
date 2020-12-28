// Made by siraponte

//Libraries
#include <stdio.h>
#include <cs50.h>

//Main Function
int main(void)
{
    //Getting string from users (n stands for height)
    int n = get_int("Height : ");
    
    //Loop to make sure the input is between 1 and 8
    for (; n > 8 || n < 1 ;)
    {
        n = get_int("Height : ");
    }
    
    // Loop to print spaces and hastags (c stands for columns)
    for (int c = 0 ; c < n ; c++)
    {
        
        // Loop to print spaces (s stands for spaces)
        for (int s = 0 ; s < n - c - 1  ; s++)
        {
            printf(" ");
        }
        
        // Loop to print the left hastags (h stans for hastags)
        for (int h = 0 ; h <= c ; h++)
        {
            printf("#");
        }
        
        // Function to print the spaces between the columns 
        printf("  ");
        
        // Loop to print the right hastags 
        for (int h = 0 ; h <= c ; h++)
        {
            printf("#");
        }
        
        // Funciotn to print new lines between rows
        printf("\n");
    }
}
