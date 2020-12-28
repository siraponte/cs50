//Made by siraponte

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>

//Block size
#define BLOCK 512

//Byte size
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    //Check if usage is correct
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }
    
    //Create pointers to input ed output files
    //Open the input file
    FILE *input = fopen(argv[1], "r");
    FILE *output = NULL;
    
    //Check if input files in empty
    if (input == NULL)
    {
        printf("Could not open\n");
        return 2;
    }
    
    //Buffer array with block size
    BYTE buffer[512];
    
    //Image counter
    int jpg_count = 0;
    
    //Create a string for filename saves (***.jpg\0)
    char filename[8];
    
    //To finish the saving of images's blocks
    int conclude = 0;
    
    //To check if it's first image
    int first = 0;
    
    //Loop through input file (Until end)
    while (fread(buffer, sizeof(BYTE), BLOCK, input) != 0)
    {
        //Check if block is the start of a jpg
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer [2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //Increases after first jpg
            if (jpg_count > 0)
            {
                jpg_count++;
            }
            
            //To check if it's first jpg
            first++;
            if (first == 2)
            {
                jpg_count++;
            }
            
            //Create a new jpg file
            sprintf(filename, "%03i.jpg", jpg_count);
            
            //Open the output file in writing mode
            output = fopen(filename, "w");
            
            //Write the first block into the output file
            fwrite(buffer, sizeof(BYTE), BLOCK, output);
            
            //Close output file
            fclose(output);
            
            //To finish the saving of images's blocks
            conclude = 0;
            conclude++;
        }
        //Finish the saving of image's blocks
        else if (conclude == 1)
        {
            //Reopen the old jpg file
            sprintf(filename, "%03i.jpg", jpg_count);
            
            //Open the output file in append mode (To not overwrite)
            output = fopen(filename, "a");
            
            //Write other blocks after first into the output file
            fwrite(buffer, sizeof(BYTE), BLOCK, output);
            
            //Close output file
            fclose(output);
        }
        //Check if there are some data before first jpg , and jumps them
        else 
        {
            continue;
        }
    }
    
    //Close input file
    fclose(input);
    
    return 0;
}
