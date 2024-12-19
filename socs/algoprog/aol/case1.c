/**
* Copyright (c) 2024-2025 Muhammad Nizwa.
* AOL Algorithm & Programming
* Class LM01
* NIM 2802401833
*
* ------
* CASE 1
* ------
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void by_nizwa() {
 printf("\n");
 printf("\n");
 printf("  NNN    NN   NNNN   NNNNNNN   NN      NN    NNNNN    \n");
 printf("  NNNN   NN    NN        NNN   NN      NN   NN   NN   \n");
 printf("  NN NN  NN    NN       NN     NN  NN  NN   NNNNNNN   \n");
 printf("  NN  NN NN    NN     NNN      NN  NN  NN   NN   NN   \n");
 printf("  NN   NNNN   NNNN   NNNNNNN    NN NN NN    NN   NN   \n");
 printf("\n");
 printf("\n");
}

int main() {
 by_nizwa();
 char str[100];
 // input
 printf("input any sentence: ");
 scanf("%s", str);
 // get length
 const int len = strlen(str);
 // result
 char result[len];
 // reverse loop
 int idx = 0;
 for (int i = len - 1; i >= 0; i--) {
  // convert letter case
  if (isupper(str[i])) {
   result[idx] = tolower(str[i]);
  } else {
   result[idx] = toupper(str[i]);
  }
  idx++;
 }
 // output
 printf("result: %s\n", result);
 return 0;
}

