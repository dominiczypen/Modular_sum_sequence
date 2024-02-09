/* Author: Dominic van der Zypen
 * Goal: generate first 16 members of modular sum sequence
 * defined by a_0 = 0, a_1 = 1 and 
 * a_n = (\sum_{i = 0}^{n-1} a_i) mod n.
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
  int k = 0;
  int my_sum = 0;
  int* array;
  array = (int*)malloc(16 * sizeof(int)); // some pointer arithmetic later
  *(array) = 0;
  *(array + 1) = 1;

  int i = 2; // start recursive calc for i == 2

  printf("0, 1, "); // print array[0], array[1] == *(array), *(array+1)
                    // because loop below starts at i == 2

  while (i < 16)
  {
    k = 0;
    my_sum = 0;
    while (k < i)  // sum loop for *(array+i)
    {
      my_sum = (my_sum + *(array + k)) % i; // * : dereferencing!
      k++;
    }
    *(array+i) = my_sum;
    printf("%d, ",*(array+i));
    i++;
  }
  return 0;
}
