#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(void)
{
    string text = get_string("Text: ");
    float space = 0;
    for(int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ' )
        {
            space++;
        }
    }

    float words = space + 1;//else the last word will not be included//
    //printf("words: %f\n", words);//

    float letters = 0;
    for(int x = 0; x < strlen(text); x++)
    {
        if(isalpha(text[x]) != 0)
        {
            letters++;
        }
    }
   // printf("letters: %f\n", letters);//

    /* words and letters also need to be of the type float even though their values themselves are
    integers but the division may lead to a floating point value which needs to be accounted for and
    an integer divided by an integer would always result in an integer output. Hence we need to assign beforehand.*/
    float L = (letters / words) * 100;
    //printf("L: %f\n", L);//

    float sentence = 0;
    for(int y = 0; y < strlen(text); y++)
    {
        if(text[y] == '.' || text[y] == '!' || text[y] == '?')
        {
            sentence++;
        }
    }
    //printf("sentence: %f\n", sentence);//
    float S = (sentence/words) * 100;
    //printf("S: %f\n", S);//

    float index = 0.0588 * L - 0.296 * S - 15.8;

    // round it to the nearest whole number and to remove decimal point we store it in integer variable//
    int grade = round(index);
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}
