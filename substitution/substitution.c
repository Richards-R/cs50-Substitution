// A program to encrypt messages using a substitution cipher

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    char crypt_str[100];

    // Check for only one argument (= the key)
    if (argc != 2)
    {
        printf("Usage: ./substitition key\n");
        return 1;
    }

    int key_len = strlen(argv[1]);

    // Check exactly 26 characters　
    if (key_len != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    int alpha_checkA = 0;
    int alpha_checka = 0;
    string alphabeta = "abcdefghijklmnopqrstuvwxyz";
    string alphabetA = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int i = 0; i < key_len; i++)
    {
        // Check unique values only in key
        for (int j = i + 1; j < key_len; j++)
        {
            if (argv[1][i] == argv[1][j])
            {
                printf("Unique key values only.\n");
                return 1;
            }
        }

        // Check only alphanumeric
        if (argv[1][i] >= 65 && argv[1][i] <= 90)
        {
            alpha_checkA++;
        }

        if (argv[1][i] >= 97 && argv[1][i] <= 122)
        {
            alpha_checka++;
        }
    }

    if (alpha_checkA + alpha_checka != 26)
    {
        printf("Key must contain only alphabetic characters.\n");
        return 1;
    }
    else
    {
        char crypt_char;
        string key = argv[1];
        string input_str = get_string("plaintext:  ");

        for (int i = 0, n = strlen(input_str); i < n; i++)
        {
            crypt_char = input_str[i];

            for (int j = 0, m = strlen(alphabeta); j < m; j++)
            {
                if (input_str[i] == alphabeta[j])
                {
                    crypt_char = tolower(key[j]);
                }

                if (input_str[i] == alphabetA[j])
                {
                    crypt_char = toupper(key[j]);
                }
            }

            // Append to array & print string
            crypt_str[i] = (char) crypt_char;
        }
    }
    printf("ciphertext: %s\n", crypt_str);
    return 0;
}
