//Made by siraponte

#include <stdio.h>
#include <cs50.h>
#include <math.h>

#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //Loop through pixels 
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float gray = 0;
            
            //Average of all colors of a pixel
            gray = ((((float)image[i][j].rgbtRed + (float)image[i][j].rgbtGreen + (float)image[i][j].rgbtBlue) / 3));
            
            //Put the average into each color
            image[i][j].rgbtRed = round(gray);
            image[i][j].rgbtGreen = round(gray);
            image[i][j].rgbtBlue = round(gray);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //Loop through pixels
    for (int i = 0; i < height; i++)
    {
        //Temporary integer to store colors
        int tempimg[3];
        
        for (int j = 0; j < (width / 2); j++)
        {
            //Reverse pixel of a row using a temporary integer
            //If row is odd , ignore central pixel
            tempimg[0] = image[i][j].rgbtRed;
            tempimg[1] = image[i][j].rgbtGreen;
            tempimg[2] = image[i][j].rgbtBlue;
           
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;  
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
          
            image[i][width - j - 1].rgbtRed = tempimg[0];
            image[i][width - j - 1].rgbtGreen = tempimg[1];
            image[i][width - j - 1].rgbtBlue = tempimg[2];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //Temporary pixel
    RGBTRIPLE tempixel[height][width];
    
    //Loop through pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //Integer to store box pixels' colors
            int tempred = 0; 
            int tempgreen = 0; 
            int tempblue = 0;
            
            //Divider of average
            int av = 0;
            
            //Loop to create a 3x3 box around each pixel
            for (int x = i - 1; x < (i + 2); x++)
            {
                for (int y = j - 1; y < (j + 2); y++)
                {
                    //Check if box goes beyond edges
                    if (x >= 0 && y >= 0 && x < height && y < width)
                    {
                        //Add each color into temporary integer 
                        tempred += image[x][y].rgbtRed;
                        tempgreen += image[x][y].rgbtGreen;
                        tempblue += image[x][y].rgbtBlue;
                        
                        av++;
                    }
                }
            }
            
            //Divider to make colors average
            tempred = ((float)tempred / (float)av) + 0.5;
            tempgreen = (float)tempgreen / (float)av + 0.5;
            tempblue = (float)tempblue / (float)av + 0.5;
            
            //Store colors into a temporary pixel
            tempixel[i][j].rgbtRed = round(tempred);
            tempixel[i][j].rgbtGreen = round(tempgreen);
            tempixel[i][j].rgbtBlue = round(tempblue);
        }
    }
    
    //Loop through pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //Store temporary pixels colors into image pixels
            image[i][j].rgbtRed = tempixel[i][j].rgbtRed;
            image[i][j].rgbtGreen = tempixel[i][j].rgbtGreen;
            image[i][j].rgbtBlue = tempixel[i][j].rgbtBlue;
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    //Temporary pixel
    RGBTRIPLE tempixel[height][width];
    
    //Arrays for Sobel Operator
    int Gx[3][3] = 
    { 
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };
    int Gy[3][3] = 
    {
        {-1, -2, -1},
        {0, 0, 0},
        {1, 2, 1}
    };
        
    //Loop through candidates
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //Arrays to make 3x3 box
            int xx[] = {i - 1, i, i + 1};
            int yy[] = {j - 1, j, j + 1};
            
            //Float to store box pixels' colors
            float Gxred = 0, Gxgreen = 0, Gxblue = 0;
            float Gyred = 0, Gygreen = 0, Gyblue = 0;
            
            //Loop through box
            for (int x = 0; x < 3; x++)
            {
                for (int y = 0; y < 3; y++)
                {
                    //To call pixels position from box arrays
                    int cx = xx[x];
                    int cy = yy[y];
                    
                    //Check if box goes beyond edges
                    if (cx >= 0 && cy >= 0 && cx < height && cy < width)
                    {
                        //Add each box pixel's color into Gx and Gy and multiply
                        Gxred += (Gx[x][y] * image[cx][cy].rgbtRed);
                        Gxgreen += (Gx[x][y] * image[cx][cy].rgbtGreen);
                        Gxblue += (Gx[x][y] * image[cx][cy].rgbtBlue);
                        
                        Gyred += (Gy[x][y] * image[cx][cy].rgbtRed);
                        Gygreen += (Gy[x][y] * image[cx][cy].rgbtGreen);
                        Gyblue += (Gy[x][y] * image[cx][cy].rgbtBlue);
                    }
                }
            }
            //Square root
            int pixred = round(sqrt(Gxred * Gxred + Gyred * Gyred));
            int pixgreen = round(sqrt(Gxgreen * Gxgreen + Gygreen * Gygreen));
            int pixblue = round(sqrt(Gxblue * Gxblue + Gyblue * Gyblue));
            
            //Store colors into a temporay pixel
            //And check if color's byte goes beyond 255
            tempixel[i][j].rgbtRed = pixred > 255 ? 255 : pixred;
            tempixel[i][j].rgbtGreen = pixgreen > 255 ? 255 : pixgreen;
            tempixel[i][j].rgbtBlue = pixblue > 255 ? 255 : pixblue;
        }
            
    }
    //Loop through pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //Store temporary pixels into image pixels
            image[i][j].rgbtRed = tempixel[i][j].rgbtRed;
            image[i][j].rgbtGreen = tempixel[i][j].rgbtGreen;
            image[i][j].rgbtBlue = tempixel[i][j].rgbtBlue;
        }
    }
    return;
}
