//Made by siraponte

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#define MAX 9

//Candidates list
typedef struct
{
    string name;
    int votes;
}
candidate;

//Candidates array
candidate candidates[MAX];

//Candidates counter
int candidate_count;

//Functions prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    candidate_count = argc - 1;
    
    //Put argv into candidates
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }
    
    //Get number of voters
    int votes = get_int("Number of voters: ");

    //Loop to add votes
    for (int y = 0; y < votes ; y++)
    {
        string name = get_string("Vote: ");
        
        //Check if votes are invalid
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }
    
    //Print winner(s)
    print_winner();
}

bool vote(string name)
{
    //To return easly
    bool votation = false;
    
    int namelen = strlen(name);
    int count = 0;
        
    //Comparate string name with candidates names
    for (int i = 0 ; i < candidate_count ; i++)
    {
        int j = 0;
        
        //Skip different names
        if (name[j] != candidates[i].name[j])
        {
            continue;
        }
        //Control if every letter is right
        else
        {
            //"
            while (name[j] == candidates[i].name[j])
            {
                //Stop to not print garbage data
                if (count == namelen)
                {
                    break;
                }
                //To continue loop until end of the string
                else
                {
                    count++;
                    j++;
                }
            }
        }
        //Count votes and return true
        if (count == namelen)
        {
            candidates[i].votes++;
            votation = true;
            break;
        }
    }
    //Return
    return votation;
}

void print_winner(void)
{
    int win = 0;
    
    //Check for the candidate with more votes
    for (int i = 0; i < MAX; i++)
    {
        if (candidates[i].votes != 0)
        {
            if (candidates[i].votes > candidates[win].votes)
            {
                win = i;
            }
        }
    }
    //Printf all candidates with the same amount of vote of the first
    for (int i = 0; i < candidate_count ; i++)
    {
        if (candidates[i].votes == candidates[win].votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
    return;
}
