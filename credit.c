// Write a program that prompts the user for a credit card number and then reports
// (via printf) whether it is a valid American Express, MasterCard, or Visa card
// number, per the definitions of each’s format herein.
//
// All American Express numbers start with 34 or 37; and
// most MasterCard numbers start with 51, 52, 53, 54, or 55 (they also have some
// other potential starting numbers which we won’t concern ourselves with for this
// problem); and
// all Visa numbers start with 4.
//
// American Express uses 15-digit numbers, MasterCard uses 16-digit numbers, and
// Visa uses 13- and 16-digit numbers.
//
// Most cards use an algorithm invented by Hans Peter Luhn of IBM.
// According to Luhn’s algorithm, you can determine if a credit card number is
// (syntactically) valid as follows:
//
// Multiply every other digit by 2, starting with the number’s second-to-last digit,
// and then add those products’ digits together.
// Add the sum to the sum of the digits that weren’t multiplied by 2.
// If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is
// congruent to 0), the number is valid!


#include <math.h> //for using pow command in line 40 and
#include <stdio.h>
#include <cs50.h> //for using get_long command//

int main(void)
{   //long can store upto more digits as compared to integers, hence its better to use in case of credit card numbers//
    /* get_long automatically re-prompts the user for input if there are non-numeric values in the input.
        However, it includes both positive and negative integers */
    long c = get_long("Number:"); //prompts the user for input (credit card number)//

    //declaring 4 variables to store input value ensuring that the input value stays intact and can be re-used in multiple loops//
    long n1 = c;
    long n2 = c;
    long n3 = c;
    long n4 = c;

    int r1, m1, a1 = 0;
    int r2, a2 = 0;
    int d = 0;

    while (n1 != 0) //as long stores integers it would not include decimal values and eventually the number would become zero through while loop//
    {
        n1 = n1 / 10; //modifes by removing the last digit (moves number by one decimal point) allowing you to reach the 2nd last digit//
        r1 = n1 % 10;//stores the last digit of the modified number//
        n1 = n1 / 10;//removes the last digit of the modified number //
        m1 = r1 * 2;//multiplies the stored last digit of the modified number with 2 (max value of m1 can be 18//
        a1 = a1 + (m1 / 10) + (m1 % 10); /*increments the value of a1 in every loop.
                                           The formulas within bracket ensures if m1 is greater than 9 the digits are added individually*/
    }
    //printf("%i\n",a1)

    //adding the remaining the digits of the user input//
    while (n2 != 0)
    {
        r2 = n2 % 10;
        n2 = n2 / 100;
        a2 = a2 + r2;
    }
    //printf("%i\n",a2)

    int f = (a1 + a2) % 10; // f should be zero if its a valid card number//;
    //printf("%i\n",f)

    //calculating the total digits in the user input, the initial value of d has been set at zero at the begining//
    while (n3 != 0)
    {
        n3 = n3 / 10;
        d = d + 1;
    }
    //printf("%i\n", d)

    //calculating the first two digits of the user input
    int x = n4 / (pow (10, (d - 2)));
    //printf("%i\n", x)

    //calculating the first digit of the user input
    int y = n4 / (pow (10, (d - 1)));
    //printf("%i\n",y)

    if (f == 0 && (x==35 || x==37) && d == 15)
    {
        printf("AMEX\n");
    }
    else if (f == 0 && (x == 51 || x == 52 || x == 53 || x == 54 || x == 55) && d == 16)
    {
        printf("MASTERCARD\n");
    }
    else if (f == 0 && y == 4 && (d == 13 || d == 16))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
