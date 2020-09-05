// Here’s how the program might work if the user inputs 8 when prompted:
//
// $ ./mario
// Height: 8
//        #  #
//       ##  ##
//      ###  ###
//     ####  ####
//    #####  #####
//   ######  ######
//  #######  #######
// ########  ########


#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //declaring integer variables to be used later on//
    int h, n, r, sp, p;

    do
    {
        h = get_int("Height:"); //asks user for input//
        n = h; // we need to keep the user input intact for it to be re-used, hence we assign it to another variable where we can modify its value//
    }
    while (h < 1 || h > 8);  // a do while loop to ensure that the user input is between 1 and 8 inclusive //

    /*for(init; condition; increment) init is the initial value for the loop to begin, condition compares the init value with other
    given value and if true it executes it, increment increases the initial value before starting the next loop, if the condition still holds true
    the loop is again executed. The loop is repeated as long as the condition holds true*/

    /*outer most for loop that moves the output to new line basically deciding the total number of rows/ We need input intact
                            for this loop  */

    for (r = 1; r <= h; r++)
    {
        //the first nested for loop that decides the number of blank spaces to be printed before the appearance of first # symbol//
        for (sp = 1; sp < n ; sp++)
        {
            printf(" ");
        }
        n--; //for each increase in the row number(height) the blank space decreases by 1.We need to modify the input for the above loop//

        //the second nested loop that decides the number of first set of # symbol(s) to be printed after the blank spaces in a row//
        for (p = 1; p <= r ; p++)
        {
            printf("#");
        }

        //the two blank spaces to be printed after first set of # symbol(s) in a row//
        printf("  ");

        //the 3rd nested loop that decides the number of second set of # symbol(s) to be printed after the two blank spaces in a row//
        for (p = 1; p <= r; p++)
        {
            printf("#");
        }

        //the new line command that corresponds to the outer most loop which takes the pattern to the next line//
        printf("\n");
    }
}
