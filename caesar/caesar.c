#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    int key = get_int("key: ");

    string input = get_string("plaintext: ");

    printf("ciphertext: ");
    for (int i = 0; i < strlen(input); i++)
    {
        if (isalpha(input[i]) == 0)
        {
            printf("%c", input[i]);
        }
        else if(isupper(input[i]) != 0)
        {
            printf("%c", ((int)input[i] - 'A' + key) % 26 + 'A');
        }
        else if(islower(input[i]) != 0)
        {
            printf("%c", ((int)input[i] - 'a' + key) % 26 + 'a');
        }
    }
}
/*
string alphabet_upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string alphabet_lower = "abcdefghijklmnopqrstuvwxyz";
int a = 0;
            while(input[i] != alphabet_upper[a])
            {
                a++;
            }
            printf("%c", alphabet_upper[(a + key) % 26]);
        }
        else if(islower(input[i]) != 0)
        {
            int b = 0;
            while(input[i] != alphabet_lower[b])
            {
                b++;
            }
            printf("%c", alphabet_lower[(b + key) % 26]);
        }
    }
}
*/
