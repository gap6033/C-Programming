// a program that first asks the user how much change is owed and then prints the minimum number
// of coins with which that change can be made.

int main(void)
{
    float change; //declaring a floating point (to include decimal values) variable change//
    do
    {
        /*using the previously declared variable to store the input (the change owed) from the user.
        Assumption that user input is in dollars */
        change = get_float("Change owed: ");
    }
    while (change < 0); // do-while loop to ensure that input by the user is positive and a numerical value//
    int cents = round(change * 100); //converting dollar input into cents//

    //calculating total number of coins to be given as change//
    int c25 = cents / 25; //no. of coins of 25 cents to be given//
    int c10 = (cents % 25) / 10; //no. of coins of 10 cents to be given//
    int c5 = ((cents % 25) % 10) / 5; //no. of coins of 5 cents to be given//
    int c1 = (((cents % 25) % 10) % 5) / 1; //no. of coins of 1 cents to be given//
    int ans = c25 + c10 + c5 + c1; //adding all the coins//
    printf("%i\n", ans); //printing out the total no. of coins//
}
