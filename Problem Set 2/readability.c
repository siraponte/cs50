//Made by siraponte

//Libraries
#include <stdio.h>
#include <cs50.h>
#include <string.h>

//Main Function
int main(void)
{
    string txt = get_string("Text : ");
    
    //l = letters , w = words , s = sentences
    float l = 0, w = 1, s = 0;
    float g;
    
    //Loop to count letters , words and sentences
    for (int i = 0 ; i < strlen(txt) ; i++)
    {
        if ((txt[i] >= 'a' && txt[i] <= 'z') || (txt[i] >= 'A' && txt[i] <= 'Z')) 
        {
            l++;
        }
        
        else if (txt[i] == ' ')
        {
            w++;
        }
        
        else if (txt[i] == '.' || txt[i] == '?' || txt[i] == '!')
        {
            s++;
        }
    }
    
    float L = ((100 * l) / w), S = ((100 * s) / w);
    
    //Coleman-Lieau index (Why +0.5? ... I don't know , but i tried and in worked :))
    g = ((0.0588 * L) - (0.296 * S) - 15.8 + 0.5);
    
    //Function to print the right grade
    if (g < 16 && g >= 1)
    {
        printf("Grade %d\n", (int) g);
    }
    
    else if (g >= 16)
    {
        printf("Grade 16+\n");
    }
    
    else if (g < 1)
    {
        printf("Before Grade 1\n");
    }
}
