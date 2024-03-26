#include "railcipher.h"

void preprocessText(const char *text, char *processedText)
{
    int l = 0; // Count of letters after preprocessing
    for (int i = 0; text[i] != '\0'; ++i)
        if (isalpha((unsigned char)text[i]))
            processedText[l++] = tolower((unsigned char)text[i]);

    processedText[l] = '\0'; // Null-terminate the processed string
}

void getColumnOrder(int *key, int m, int *colOrder)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (key[j] == i + 1)
            {
                colOrder[i] = j;
                break;
            }
        }
    }
}

void encrypt(const char *text, int *key, int m)
{
    int len = strlen(text);
    char processedText[len + 1];
    preprocessText(text, processedText);

    int l = strlen(processedText);
    int n = (l + m - 1) / m;
    char grid[n][m];
    memset(grid, '\0', sizeof(grid));

    int emptySpaces = (n * m) - l;
    char nextChar = 123 - emptySpaces;
    for (int i = 0, k = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (k < l)
                grid[i][j] = processedText[k++];
            else
                grid[i][j] = nextChar++;

    int colOrder[m];
    getColumnOrder(key, m, colOrder);

    // Read the columns in the order specified by the key
    for (int i = 0; i < m; i++)
    {
        int col = colOrder[i];
        for (int j = 0; j < n; j++)
            if (grid[j][col] != '\0')
                printf("%c", toupper(grid[j][col]));
    }

    printf("\n");

    free(grid); // Free allocated memory
}

void decrypt(const char *ciphertext, int *key, int m)
{
    int len = strlen(ciphertext);
    int n = len / m; // Number of rows

    char grid[n][m];
    memset(grid, '\0', sizeof(grid));

    int colOrder[m];
    getColumnOrder(key, m, colOrder);

    for (int i = 0, k = 0; i < m; i++)
    {
        int col = colOrder[i];
        for (int j = 0; j < n; j++)
            grid[j][col] = ciphertext[k++];
    }

    // Read the grid row-major and print the plaintext
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            printf("%c", tolower(grid[i][j]));

    printf("\n");
}
