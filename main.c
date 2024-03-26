#include "railcipher.h"

int parseCommandLineArguments(int argc, char *argv[], int *key)
{
    if (argc < 3)
    {
        fprintf(stderr, "Usage: %s <length of key> <key numbers...>\n", argv[0]);
        return 1;
    }

    char *endptr;
    long m = strtol(argv[1], &endptr, 10);
    if (*endptr != '\0' || endptr == argv[1] || m <= 0 || m > 26)
    {
        fprintf(stderr, "Error: The first argument must be a positive integer less than or equal to 26.\n");
        return 1;
    }

    if (argc != m + 2)
    {
        fprintf(stderr, "Error: Key length does not match number of keys provided.\n");
        return 1;
    }

    for (int i = 0; i < m; i++)
    {
        key[i] = atoi(argv[i + 2]);
        if (key[i] <= 0 || key[i] > m)
        {
            fprintf(stderr, "Error: Invalid key number %d\n", key[i]);
            return 1;
        }
        for (int j = 0; j < i; j++)
        {
            if (key[j] == key[i])
            {
                fprintf(stderr, "Error: Duplicate key number %d\n", key[i]);
                return 1;
            }
        }
    }
    return 0;
}

int main(int argc, char *argv[])
{
    int m = atoi(argv[1]);
    int key[m];
    if (parseCommandLineArguments(argc, argv, key) != 0)
        return 1;

    char command[10];
    char input[1024];
    while (1)
    {
        scanf("%s", command);
        if (strcmp(command, "encrypt") == 0)
        {
            scanf(" %[^\n]s", input);
            encrypt(input, key, m);
        }
        else if (strcmp(command, "decrypt") == 0)
        {
            scanf(" %[^\n]s", input);
            decrypt(input, key, m);
        }
        else if (strcmp(command, "quit") == 0)
            break;
        else
            fprintf(stderr, "Invalid command.\n");
    }

    return 0;
}