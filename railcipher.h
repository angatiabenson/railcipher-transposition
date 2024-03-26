#ifndef RAILCIPHER_H
#define RAILCIPHER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void preprocessText(const char *text, char *processedText);
void getColumnOrder(int *key, int m, int *colOrder);

void encrypt(const char *text, int *key, int m);
void decrypt(const char *ciphertext, int *key, int m);

#endif // RAILCIPHER_H
