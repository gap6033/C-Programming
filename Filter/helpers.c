#include "helpers.h"

#include<stdio.h>
#include <math.h>
#include <string.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int colour = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = colour;
            image[i][j].rgbtGreen = colour;
            image[i][j].rgbtRed = colour;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            int sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
            if (sepiaRed > 255)
            {
                image[i][j].rgbtRed = 255 ;
            }
            else
            {
                image[i][j].rgbtRed = sepiaRed;
            }
            if (sepiaGreen > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = sepiaGreen;
            }
            if (sepiaBlue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = sepiaBlue;
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        int n = width - 1;
        while (n >= round(width / 2.0))
        {
            for(int j = 0; j < round((width - 1)/2.0); j++)
            {
                RGBTRIPLE temp = image[i][j];
                image[i][j] = image[i][n];
                image[i][n] = temp;
                n--;
            }
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE dup_image[height][width];
     memcpy(dup_image, image, height * width * sizeof(RGBTRIPLE));


    for(int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == 0 && j == 0)
            {

                image[i][j].rgbtRed = round((dup_image[i][j].rgbtRed
                                            + dup_image[i + 1][j].rgbtRed
                                            + dup_image[i][j + 1].rgbtRed
                                            + dup_image[i + 1][j + 1].rgbtRed)/4.0);
                image[i][j].rgbtGreen = round((dup_image[i][j].rgbtGreen + dup_image[i + 1][j].rgbtGreen + dup_image[i][j + 1].rgbtGreen + dup_image[i + 1][j + 1].rgbtGreen)/4.0);
                image[i][j].rgbtBlue = round((dup_image[i][j].rgbtBlue + dup_image[i + 1][j].rgbtBlue + dup_image[i][j + 1].rgbtBlue + dup_image[i + 1][j + 1].rgbtBlue)/4.0);
            }
          else if (i == 0 && j == width - 1)
            {
                image[i][j].rgbtRed = round((dup_image[i][j].rgbtRed + dup_image[i + 1][j].rgbtRed + dup_image[i + 1][j - 1].rgbtRed + dup_image[i][j - 1].rgbtRed)/4.0);
                image[i][j].rgbtGreen = round((dup_image[i][j].rgbtGreen + dup_image[i + 1][j].rgbtGreen + dup_image[i + 1][j - 1].rgbtGreen + dup_image[i][j - 1].rgbtGreen)/4.0);
                image[i][j].rgbtBlue = round((dup_image[i][j].rgbtBlue + dup_image[i + 1][j].rgbtBlue + dup_image[i + 1][j - 1].rgbtBlue + dup_image[i][j - 1].rgbtBlue)/4.0);
            }
           else if (i == height - 1 && j == 0)
            {
                image[i][j].rgbtRed = round((dup_image[i][j].rgbtRed + dup_image[i][j + 1].rgbtRed + dup_image[i - 1][j].rgbtRed + dup_image[i - 1][j + 1].rgbtRed)/4.0);
                image[i][j].rgbtGreen = round((dup_image[i][j].rgbtGreen + dup_image[i][j + 1].rgbtGreen + dup_image[i - 1][j].rgbtGreen + dup_image[i - 1][j + 1].rgbtGreen)/4.0);
                image[i][j].rgbtBlue = round((dup_image[i][j].rgbtBlue + dup_image[i][j + 1].rgbtBlue + dup_image[i - 1][j].rgbtBlue + dup_image[i - 1][j + 1].rgbtBlue)/4.0);
            }
          else if (i == height - 1 && j == width - 1)
            {
                image[i][j].rgbtRed = round((dup_image[i][j].rgbtRed + dup_image[i][j - 1].rgbtRed + dup_image[i - 1][j].rgbtRed + dup_image[i - 1][j - 1].rgbtRed)/4.0);
                image[i][j].rgbtGreen = round((dup_image[i][j].rgbtGreen + dup_image[i][j - 1].rgbtGreen + dup_image[i - 1][j].rgbtGreen + dup_image[i - 1][j - 1].rgbtGreen)/4.0);
                image[i][j].rgbtBlue = round((dup_image[i][j].rgbtBlue + dup_image[i][j - 1].rgbtBlue + dup_image[i - 1][j].rgbtBlue + dup_image[i - 1][j - 1].rgbtBlue)/4.0);
            }
          else if (i == 0 && j != 0 && j != width - 1)
            {
                image[i][j].rgbtRed = round((dup_image[i][j].rgbtRed + dup_image[i][j - 1].rgbtRed + dup_image[i][j + 1].rgbtRed + dup_image[i + 1][j].rgbtRed + dup_image[i + 1][j - 1].rgbtRed + dup_image[i + 1][j + 1].rgbtRed)/6.0);
                image[i][j].rgbtGreen = round((dup_image[i][j].rgbtGreen + dup_image[i][j - 1].rgbtGreen + dup_image[i][j + 1].rgbtGreen + dup_image[i + 1][j].rgbtGreen + dup_image[i + 1][j - 1].rgbtGreen + dup_image[i + 1][j + 1].rgbtGreen)/6.0);
                image[i][j].rgbtBlue = round((dup_image[i][j].rgbtBlue + dup_image[i][j - 1].rgbtBlue + dup_image[i][j + 1].rgbtBlue + dup_image[i + 1][j].rgbtBlue + dup_image[i + 1][j - 1].rgbtBlue + dup_image[i + 1][j + 1].rgbtBlue)/6.0);
            }
          else if (i == height - 1 && j != 0 && j != width - 1)
            {
                image[i][j].rgbtRed = round((dup_image[i][j].rgbtRed + dup_image[i][j + 1].rgbtRed + dup_image[i][j - 1].rgbtRed + dup_image[i - 1][j].rgbtRed + dup_image[i - 1][j - 1].rgbtRed + dup_image[i - 1][j + 1].rgbtRed)/6.0);
                image[i][j].rgbtGreen = round((dup_image[i][j].rgbtGreen + dup_image[i][j + 1].rgbtGreen + dup_image[i][j - 1].rgbtGreen + dup_image[i - 1][j].rgbtGreen + dup_image[i - 1][j - 1].rgbtGreen + dup_image[i - 1][j + 1].rgbtGreen)/6.0);
                image[i][j].rgbtBlue = round((dup_image[i][j].rgbtBlue + dup_image[i][j + 1].rgbtBlue + dup_image[i][j - 1].rgbtBlue + dup_image[i - 1][j].rgbtBlue + dup_image[i - 1][j - 1].rgbtBlue + dup_image[i - 1][j + 1].rgbtBlue)/6.0);
            }
          else if (j == 0 && i != 0 && i != height - 1)
            {
                image[i][j].rgbtRed = round((dup_image[i][j].rgbtRed + dup_image[i][j + 1].rgbtRed + dup_image[i - 1][j + 1].rgbtRed + dup_image[i - 1][j].rgbtRed + dup_image[i + 1][j + 1].rgbtRed + dup_image[i + 1][j].rgbtRed)/6.0);
                image[i][j].rgbtGreen = round((dup_image[i][j].rgbtGreen + dup_image[i][j + 1].rgbtGreen + dup_image[i - 1][j + 1].rgbtGreen + dup_image[i - 1][j].rgbtGreen + dup_image[i + 1][j + 1].rgbtGreen + dup_image[i + 1][j].rgbtGreen)/6.0);
                image[i][j].rgbtBlue = round((dup_image[i][j].rgbtBlue + dup_image[i][j + 1].rgbtBlue + dup_image[i - 1][j + 1].rgbtBlue + dup_image[i - 1][j].rgbtBlue + dup_image[i + 1][j + 1].rgbtBlue + dup_image[i + 1][j].rgbtBlue)/6.0);
            }
           else if (j == width - 1 && i != 0 && i != height - 1)
            {
                image[i][j].rgbtRed = round((dup_image[i][j].rgbtRed + dup_image[i][j - 1].rgbtRed + dup_image[i + 1][j - 1].rgbtRed + dup_image[i + 1][j].rgbtRed + dup_image[i - 1][j - 1].rgbtRed + dup_image[i - 1][j].rgbtRed)/6.0);
                image[i][j].rgbtGreen = round((dup_image[i][j].rgbtGreen + dup_image[i][j - 1].rgbtGreen + dup_image[i + 1][j - 1].rgbtGreen + dup_image[i + 1][j].rgbtGreen + dup_image[i - 1][j - 1].rgbtGreen + dup_image[i - 1][j].rgbtGreen)/6.0);
                image[i][j].rgbtBlue = round((dup_image[i][j].rgbtBlue + dup_image[i][j - 1].rgbtBlue + dup_image[i + 1][j - 1].rgbtBlue + dup_image[i + 1][j].rgbtBlue + dup_image[i - 1][j - 1].rgbtBlue + dup_image[i - 1][j].rgbtBlue)/6.0);
            }
            else
            {
                image[i][j].rgbtRed = round((dup_image[i][j].rgbtRed
                                          + dup_image[i][j - 1].rgbtRed
                                          + dup_image[i][j + 1].rgbtRed
                                          + dup_image[i + 1][j].rgbtRed
                                          + dup_image[i - 1][j].rgbtRed
                                          + dup_image[i + 1][j - 1].rgbtRed
                                          + dup_image[i + 1][j + 1].rgbtRed
                                          + dup_image[i - 1][j - 1].rgbtRed
                                          + dup_image[i - 1][j + 1].rgbtRed)/9.0);
                image[i][j].rgbtGreen = round((dup_image[i][j].rgbtGreen + dup_image[i][j - 1].rgbtGreen + dup_image[i][j + 1].rgbtGreen + dup_image[i + 1][j].rgbtGreen + dup_image[i + 1][j - 1].rgbtGreen + dup_image[i + 1][j + 1].rgbtGreen + dup_image[i - 1][j].rgbtGreen + dup_image[i - 1][j - 1].rgbtGreen + dup_image[i - 1][j + 1].rgbtGreen)/9.0);
                image[i][j].rgbtBlue = round((dup_image[i][j].rgbtBlue + dup_image[i][j - 1].rgbtBlue + dup_image[i][j + 1].rgbtBlue + dup_image[i + 1][j].rgbtBlue + dup_image[i + 1][j - 1].rgbtBlue + dup_image[i + 1][j + 1].rgbtBlue + dup_image[i - 1][j].rgbtBlue + dup_image[i - 1][j - 1].rgbtBlue + dup_image[i - 1][j + 1].rgbtBlue)/9.0);
            }
        }

    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE dup_image[height][width];
    memcpy(dup_image, image, height * width * sizeof(RGBTRIPLE));

    float gxred;
    float gxgreen;
    float gxblue;
    float gyred;
    float gygreen;
    float gyblue;

    for(int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == 0 && j == 0)
            {
                gxred = pow((dup_image[i][j + 1].rgbtRed * 2 + dup_image[i + 1][j + 1].rgbtRed * 1), 2);
                gyred = pow((dup_image[i + 1][j].rgbtRed * 2 + dup_image[i + 1][j + 1].rgbtRed * 1), 2);
                gxgreen = pow((dup_image[i][j + 1].rgbtGreen * 2 + dup_image[i + 1][j + 1].rgbtGreen * 1), 2);
                gygreen = pow((dup_image[i + 1][j].rgbtGreen * 2 + dup_image[i + 1][j + 1].rgbtGreen * 1), 2);
                gxblue = pow((dup_image[i][j + 1].rgbtBlue * 2 + dup_image[i + 1][j + 1].rgbtBlue * 1), 2);
                gyblue = pow((dup_image[i + 1][j].rgbtBlue * 2 + dup_image[i + 1][j + 1].rgbtBlue * 1), 2);

                image[i][j].rgbtRed = fmin(255, round(sqrt(gxred + gyred)));
                image[i][j].rgbtGreen = fmin(255, round(sqrt(gxgreen + gygreen)));
                image[i][j].rgbtBlue = fmin(255, round(sqrt(gxblue + gyblue)));

            }
          else if (i == 0 && j == width - 1)
            {
                gxred = pow((dup_image[i][j - 1].rgbtRed * -2 + dup_image[i + 1][j - 1].rgbtRed * -1), 2);
                gyred = pow((dup_image[i + 1][j - 1].rgbtRed * 1 + dup_image[i + 1][j].rgbtRed * 2), 2);
                gxgreen = pow((dup_image[i][j - 1].rgbtGreen * -2 + dup_image[i + 1][j - 1].rgbtGreen * -1), 2);
                gygreen = pow((dup_image[i + 1][j - 1].rgbtGreen * 1 + dup_image[i + 1][j].rgbtGreen * 2), 2);
                gxblue = pow((dup_image[i][j - 1].rgbtBlue * -2 + dup_image[i + 1][j - 1].rgbtBlue * -1), 2);
                gyblue = pow((dup_image[i + 1][j - 1].rgbtBlue * 1 + dup_image[i + 1][j].rgbtBlue * 2), 2);

                image[i][j].rgbtRed = fmin(255, round(sqrt(gxred + gyred)));
                image[i][j].rgbtGreen = fmin(255, round(sqrt(gxgreen + gygreen)));
                image[i][j].rgbtBlue = fmin(255, round(sqrt(gxblue + gyblue)));
            }
           else if (i == height - 1 && j == 0)
            {
                gxred = pow((dup_image[i][j + 1].rgbtRed * 2 + dup_image[i - 1][j + 1].rgbtRed * 1), 2);
                gyred = pow((dup_image[i - 1][j].rgbtRed * -2 + dup_image[i - 1][j + 1].rgbtRed * -1), 2);
                gxgreen = pow((dup_image[i][j + 1].rgbtGreen * 2 + dup_image[i - 1][j + 1].rgbtGreen * 1), 2);
                gygreen = pow((dup_image[i - 1][j].rgbtGreen * -2 + dup_image[i - 1][j + 1].rgbtGreen * -1), 2);
                gxblue = pow((dup_image[i][j + 1].rgbtBlue * 2 + dup_image[i - 1][j + 1].rgbtBlue * 1), 2);
                gyblue = pow((dup_image[i - 1][j].rgbtBlue * -2 + dup_image[i - 1][j + 1].rgbtBlue * -1), 2);

                image[i][j].rgbtRed = fmin(255, round(sqrt(gxred + gyred)));
                image[i][j].rgbtGreen = fmin(255, round(sqrt(gxgreen + gygreen)));
                image[i][j].rgbtBlue = fmin(255, round(sqrt(gxblue + gyblue)));

            }
          else if (i == height - 1 && j == width - 1)
            {
                gxred = pow((dup_image[i][j - 1].rgbtRed * -2 + dup_image[i - 1][j - 1].rgbtRed * -1), 2);
                gyred = pow((dup_image[i - 1][j].rgbtRed * -2 + dup_image[i - 1][j - 1].rgbtRed * -1), 2);
                gxgreen = pow((dup_image[i][j - 1].rgbtGreen * -2 + dup_image[i - 1][j - 1].rgbtGreen * -1), 2);
                gygreen = pow((dup_image[i - 1][j].rgbtGreen * -2 + dup_image[i - 1][j - 1].rgbtGreen * -1), 2);
                gxblue = pow((dup_image[i][j - 1].rgbtBlue * -2 + dup_image[i - 1][j - 1].rgbtBlue * -1), 2);
                gyblue = pow((dup_image[i - 1][j].rgbtBlue * -2 + dup_image[i - 1][j - 1].rgbtBlue * -1), 2);

                image[i][j].rgbtRed = fmin(255, round(sqrt(gxred + gyred)));
                image[i][j].rgbtGreen = fmin(255, round(sqrt(gxgreen + gygreen)));
                image[i][j].rgbtBlue = fmin(255, round(sqrt(gxblue + gyblue)));

            }
          else if (i == 0 && j != 0 && j != width - 1)
            {
                gxred = pow((dup_image[i][j - 1].rgbtRed * -2 + dup_image[i][j + 1].rgbtRed * 2 + dup_image[i + 1][j - 1].rgbtRed * - 1 + dup_image[i + 1][j + 1].rgbtRed * 1), 2);
                gyred = pow((dup_image[i + 1][j].rgbtRed * 2 + dup_image[i + 1][j - 1].rgbtRed * 1 + dup_image[i + 1][j + 1].rgbtRed * 1), 2);
                gxgreen = pow((dup_image[i][j - 1].rgbtGreen * -2 + dup_image[i][j + 1].rgbtGreen * 2 + dup_image[i + 1][j - 1].rgbtGreen * - 1 + dup_image[i + 1][j + 1].rgbtGreen * 1), 2);
                gygreen = pow((dup_image[i + 1][j].rgbtGreen * 2 + dup_image[i + 1][j - 1].rgbtGreen * 1 + dup_image[i + 1][j + 1].rgbtGreen * 1), 2);
                gxblue = pow((dup_image[i][j - 1].rgbtBlue * -2 + dup_image[i][j + 1].rgbtBlue * 2 + dup_image[i + 1][j - 1].rgbtBlue * - 1 + dup_image[i + 1][j + 1].rgbtBlue * 1), 2);
                gyblue = pow((dup_image[i + 1][j].rgbtBlue * 2 + dup_image[i + 1][j - 1].rgbtBlue * 1 + dup_image[i + 1][j + 1].rgbtBlue * 1), 2);

                image[i][j].rgbtRed = fmin(255, round(sqrt(gxred + gyred)));
                image[i][j].rgbtGreen = fmin(255, round(sqrt(gxgreen + gygreen)));
                image[i][j].rgbtBlue = fmin(255, round(sqrt(gxblue + gyblue)));

            }
          else if (i == height - 1 && j != 0 && j != width - 1)
            {
                gxred = pow((dup_image[i][j - 1].rgbtRed * -2 + dup_image[i][j + 1].rgbtRed * 2 + dup_image[i - 1][j - 1].rgbtRed * - 1 + dup_image[i - 1][j + 1].rgbtRed * 1), 2);
                gyred = pow((dup_image[i - 1][j].rgbtRed * -2 + dup_image[i - 1][j - 1].rgbtRed * -1 + dup_image[i - 1][j + 1].rgbtRed * -1), 2);
                gxgreen = pow((dup_image[i][j - 1].rgbtGreen * -2 + dup_image[i][j + 1].rgbtGreen * 2 + dup_image[i - 1][j - 1].rgbtGreen * - 1 + dup_image[i - 1][j + 1].rgbtGreen * 1), 2);
                gygreen = pow((dup_image[i - 1][j].rgbtGreen * -2 + dup_image[i - 1][j - 1].rgbtGreen * -1 + dup_image[i - 1][j + 1].rgbtGreen * -1), 2);
                gxblue = pow((dup_image[i][j - 1].rgbtBlue * -2 + dup_image[i][j + 1].rgbtBlue * 2 + dup_image[i - 1][j - 1].rgbtBlue * - 1 + dup_image[i - 1][j + 1].rgbtBlue * 1), 2);
                gyblue = pow((dup_image[i - 1][j].rgbtBlue * -2 + dup_image[i - 1][j - 1].rgbtBlue * -1 + dup_image[i - 1][j + 1].rgbtBlue * -1), 2);

                image[i][j].rgbtRed = fmin(255, round(sqrt(gxred + gyred)));
                image[i][j].rgbtGreen = fmin(255, round(sqrt(gxgreen + gygreen)));
                image[i][j].rgbtBlue = fmin(255, round(sqrt(gxblue + gyblue)));

            }
          else if (j == 0 && i != 0 && i != height - 1)
            {
                gxred = pow((dup_image[i][j + 1].rgbtRed * 2 + dup_image[i - 1][j + 1].rgbtRed * 1 + dup_image[i + 1][j + 1].rgbtRed * 1), 2);
                gyred = pow((dup_image[i - 1][j].rgbtRed * -2 + dup_image[i - 1][j + 1].rgbtRed * -1 + dup_image[i + 1][j].rgbtRed * 2 + dup_image[i + 1][j + 1].rgbtRed * 1), 2);
                gxgreen = pow((dup_image[i][j + 1].rgbtGreen * 2 + dup_image[i - 1][j + 1].rgbtGreen * 1 + dup_image[i + 1][j + 1].rgbtGreen * 1), 2);
                gygreen = pow((dup_image[i - 1][j].rgbtGreen * -2 + dup_image[i - 1][j + 1].rgbtGreen * -1 + dup_image[i + 1][j].rgbtGreen * 2 + dup_image[i + 1][j + 1].rgbtGreen * 1), 2);
                gxblue = pow((dup_image[i][j + 1].rgbtBlue * 2 + dup_image[i - 1][j + 1].rgbtBlue * 1 + dup_image[i + 1][j + 1].rgbtBlue * 1), 2);
                gyblue = pow((dup_image[i - 1][j].rgbtBlue * -2 + dup_image[i - 1][j + 1].rgbtBlue * -1 + dup_image[i + 1][j].rgbtBlue * 2 + dup_image[i + 1][j + 1].rgbtBlue * 1), 2);

                image[i][j].rgbtRed = fmin(255, round(sqrt(gxred + gyred)));
                image[i][j].rgbtGreen = fmin(255, round(sqrt(gxgreen + gygreen)));
                image[i][j].rgbtBlue = fmin(255, round(sqrt(gxblue + gyblue)));

            }
           else if (j == width - 1 && i != 0 && i != height - 1)
            {
                gxred = pow((dup_image[i][j - 1].rgbtRed * -2 + dup_image[i - 1][j - 1].rgbtRed * -1 + dup_image[i + 1][j - 1].rgbtRed * -1), 2);
                gyred = pow((dup_image[i - 1][j].rgbtRed * -2 + dup_image[i - 1][j - 1].rgbtRed * -1 + dup_image[i + 1][j].rgbtRed * 2 + dup_image[i + 1][j - 1].rgbtRed * 1), 2);
                gxgreen = pow((dup_image[i][j - 1].rgbtGreen * -2 + dup_image[i - 1][j - 1].rgbtGreen * -1 + dup_image[i + 1][j - 1].rgbtGreen * -1), 2);
                gygreen = pow((dup_image[i - 1][j].rgbtGreen * -2 + dup_image[i - 1][j - 1].rgbtGreen * -1 + dup_image[i + 1][j].rgbtGreen * 2 + dup_image[i + 1][j - 1].rgbtGreen * 1), 2);
                gxblue = pow((dup_image[i][j - 1].rgbtBlue * -2 + dup_image[i - 1][j - 1].rgbtBlue * -1 + dup_image[i + 1][j - 1].rgbtBlue * -1), 2);
                gyblue = pow((dup_image[i - 1][j].rgbtBlue * -2 + dup_image[i - 1][j - 1].rgbtBlue * -1 + dup_image[i + 1][j].rgbtBlue * 2 + dup_image[i + 1][j - 1].rgbtBlue * 1), 2);

                image[i][j].rgbtRed = fmin(255, round(sqrt(gxred + gyred)));
                image[i][j].rgbtGreen = fmin(255, round(sqrt(gxgreen + gygreen)));
                image[i][j].rgbtBlue = fmin(255, round(sqrt(gxblue + gyblue)));
            }
            else
            {
                gxred = pow((dup_image[i][j - 1].rgbtRed * -2 + dup_image[i - 1][j - 1].rgbtRed * -1 + dup_image[i + 1][j - 1].rgbtRed * -1 + dup_image[i][j + 1].rgbtRed * 2 + dup_image[i - 1][j + 1].rgbtRed * 1 + dup_image[i + 1][j + 1].rgbtRed * 1), 2);
                gyred = pow((dup_image[i - 1][j].rgbtRed * -2 + dup_image[i - 1][j - 1].rgbtRed * -1 + dup_image[i - 1][j + 1].rgbtRed * -1 + dup_image[i + 1][j - 1].rgbtRed * 1 + dup_image[i + 1][j].rgbtRed * 2 + dup_image[i + 1][j + 1].rgbtRed * 1), 2);
                gxgreen = pow((dup_image[i][j - 1].rgbtGreen * -2 + dup_image[i - 1][j - 1].rgbtGreen * -1 + dup_image[i + 1][j - 1].rgbtGreen * -1 + dup_image[i][j + 1].rgbtGreen * 2 + dup_image[i - 1][j + 1].rgbtGreen * 1 + dup_image[i + 1][j + 1].rgbtGreen * 1), 2);
                gygreen = pow((dup_image[i - 1][j].rgbtGreen * -2 + dup_image[i - 1][j - 1].rgbtGreen * -1 + dup_image[i - 1][j + 1].rgbtGreen * -1 + dup_image[i + 1][j - 1].rgbtGreen * 1 + dup_image[i + 1][j].rgbtGreen * 2 + dup_image[i + 1][j + 1].rgbtGreen * 1), 2);
                gxblue = pow((dup_image[i][j - 1].rgbtBlue * -2 + dup_image[i - 1][j - 1].rgbtBlue * -1 + dup_image[i + 1][j - 1].rgbtBlue * -1 + dup_image[i][j + 1].rgbtBlue * 2 + dup_image[i - 1][j + 1].rgbtBlue * 1 + dup_image[i + 1][j + 1].rgbtBlue * 1), 2);
                gyblue = pow((dup_image[i - 1][j].rgbtBlue * -2 + dup_image[i - 1][j - 1].rgbtBlue * -1 + dup_image[i - 1][j + 1].rgbtBlue * -1 + dup_image[i + 1][j - 1].rgbtBlue * 1 + dup_image[i + 1][j].rgbtBlue * 2 + dup_image[i + 1][j + 1].rgbtBlue * 1), 2);

                image[i][j].rgbtRed = fmin(255, round(sqrt(gxred + gyred)));
                image[i][j].rgbtGreen = fmin(255, round(sqrt(gxgreen + gygreen)));
                image[i][j].rgbtBlue = fmin(255, round(sqrt(gxblue + gyblue)));

            }
        }

    }
    return;
}
