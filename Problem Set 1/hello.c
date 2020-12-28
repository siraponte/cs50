//Made by siaponte

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Get string from user
    string name = get_string("What's your name?\n");
    
    //Print hello , user's name
    printf("hello , %s\n", name);
}
