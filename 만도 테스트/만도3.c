#include <stdio.h>
int main(void) 
{

   int i, n, k;
   scanf("%d", &n);

   for ( i = 1; i <= n; i++) {
      for (int k = 0; k < n - i; k++)
         printf(" ");
      for (int k = 0; k < i + (i - 1); k++)
         printf("*");

      printf("\n");
   }

   for (i = n - 1; i > 0; i--) {
      for ( k = 0; k < n - i; k++)
         printf(" ");
      for ( k = 0; k < i + (i - 1); k++)
         printf("*");

      printf("\n");
   }

   return 0;
}