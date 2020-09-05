#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc == 1)
    {
        printf("Usage: ./substitution argv[1]\n");
        return 1;
    }
    int c = 0;
    for (int z = 0; z < strlen(argv[1]); z++)
    {
        if (isalpha(argv[1][z]) == 0)
        {
            c = c + 1;
        }
    }
    if (argc == 2 && c != 0)
    {
        printf("argv[1] must only contain alphabetic characters\n");
        return 1;
    }
    if (argc == 2 && c == 0 && strlen(argv[1]) != 26)
    {
        printf("argv[1] must contain 26 characters.\n");
        return 1;
    }
    for (int x = 0; x < strlen(argv[1]); x++)
    {
        for (int y = x+1; y < strlen(argv[1]); y++)
        {
           //printf("Comparing x: %c & y: %c\n", argv[1][x], argv[1][y])//
           if (argv[1][x] == argv[1][y])
            {
                printf("argv[1] must not contain repeated characters\n");
                return 1;
            }
            if (argv[1][x] == tolower(argv[1][y]))
            {
                printf("argv[1] must not contain repeated characters\n");
                return 1;
            }
            if (argv[1][x] == toupper(argv[1][y]))
            {
                printf("argv[1] must not contain repeated characters\n");
                return 1;
            }

        }
    }
    string input = get_string("plaintext: ");
    string alphabet_upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string alphabet_lower = "abcdefghijklmnopqrstuvwxyz";
    printf("ciphertext: ");
    for (int i = 0; i < strlen(input); i++)
    {
        if (isalpha(input[i]) == 0)
        {
            printf("%c", input[i]);
        }
        else if(isupper(input[i]) != 0)
        {
            int u = 0;
            while (input[i] != alphabet_upper[u] && u <= 25)
            {
                u = u + 1;
                // printf("u: %i\n", u);//
            }
            printf("%c", toupper(argv[1][u]));
        }
        else if(islower(input[i]) != 0)
        {
            int l = 0;
            while (input[i] != alphabet_lower[l] && l <= 25)
            {
                l = l + 1;
            }
            printf("%c", tolower(argv[1][l]));
        }
    }
    printf("\n");
    return 0;
}
