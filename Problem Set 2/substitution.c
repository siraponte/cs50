//Made by siraponte

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    //Check if the key is 1
    if (argc == 2)
    {
        string key = argv[1];
        int keylen = strlen(key);
        
        //Check is the lenght of the key is right
        if (keylen == 26)
        {
            int count = 0;
            
            //Check if there are all the letters
            for (int a = 'a' ; a <= 'z' ; a++)
            {
                for (int i = 0 ; i < 26 ; i++)
                {
                    if (a == tolower(key[i]))
                    {
                        count++;
                        break;
                    }
                }
            }
            if (count == 26)
            {
                //Check if there are some duplicates
                for (int i = 0 ; i < 26 ; i++)
                {
                    for (int j = i + 1 ; j < 26 ; j++)
                    {
                        if (tolower(key[i]) == tolower(key[j]))
                        {
                            return 1;
                        }
                    }
                }
                
                string alphabeth = "abcdefghijklmnopqrstuvwxyz";

                string plain = get_string("plaintext : ");
                int plainlen = strlen(plain);

                char cipher[plainlen];
                
                //Convert plain into cipher
                for (int i = 0 ; i < plainlen ; i++)
                {
                    //Check if plain is over
                    if (plain[i] != 0)
                    {
                        //Check if a char is alpha
                        if (isalpha(plain[i]))
                        {
                            for (int j = 0 ; j < 26 ; j++)
                            {
                                //Convert a char...
                                if (tolower(plain[i]) == alphabeth[j])
                                {
                                    //...If in lowercase
                                    if ((plain[i]) >= 'a' && (plain[i]) <= 'z')
                                    {
                                        cipher[i] = tolower(key[j]);
                                        continue;
                                    }
                                    //...If in uppercase
                                    else if ((plain[i]) >= 'A' && (plain[i]) <= 'Z')
                                    {
                                        cipher[i] = toupper(key[j]);
                                        continue;
                                    }
                                } 
                            }
                        }
                        //Convert other char
                        else
                        {
                            cipher[i] = plain[i];
                        }   
                    } 
                }
                //Print chiper without possible garbage data...
                //If plainetext lenght is 1
                if (plainlen == 1)
                {
                    cipher[1] = '\0';
                    printf("ciphertext: %s\n", cipher);
                    return 0;
                }
                //If plaintext lenght is 3
                else if (plainlen == 3)
                {
                    cipher[3] = '\0';
                    printf("ciphertext: %s\n", cipher);
                    return 0;
                }
                //Other cases
                else
                {
                    printf("ciphertext: %s\n", cipher);
                    return 0;
                }
            }
            else
            {
                return 1;
            }
        }
        else
        {
            printf("Key must contain 26 characters.\n");
            
            return 1;
        }
    }
    else if (argc == 1)
    {
        printf("Usage: ./substitution key\n");
        
        return 1;
    }
    else 
    {
        printf("Usage: ./substitution key\n");
        
        return 1;
    }
}
