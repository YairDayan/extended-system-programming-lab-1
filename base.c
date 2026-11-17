#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *map(char *array, int array_length, char (*f)(char))
{
  char *mapped_array = (char *)(malloc(array_length * sizeof(char)));
  for (int i = 0; i < array_length; i++)
    mapped_array[i] = f(array[i]);
  return mapped_array;
}

char dprt(char c)
{
  printf("%d\n", c);
  return c;
}

char cxprt(char c)
{
  if (c >= 0x20 && c <= 0x7E)
    printf("%c", c);
  else
    printf(".");
  printf(" %02x\n", (unsigned char)c);
  return c;
}

char my_get(char c)
{
  return fgetc(stdin);
}

char encrypt(char c)
{
  if (c >= 0x1F && c <= 0x7E)
    return c + 1;
  return c;
}

char decrypt(char c)
{
  if (c >= 0x21 && c <= 0x7F)
    return c - 1;
  return c;
}

int main(int argc, char **argv)
{
  int base_len = 5;
  char arr1[base_len];
  char *arr2 = map(arr1, base_len, my_get);
  char *arr3 = map(arr2, base_len, dprt);
  char *arr4 = map(arr3, base_len, cxprt);
  char *arr5 = map(arr4, base_len, encrypt);
  char *arr6 = map(arr5, base_len, cxprt);
  char *arr7 = map(arr6, base_len, decrypt);
  char *arr8 = map(arr7, base_len, cxprt);
  free(arr2);
  free(arr3);
  free(arr4);
  free(arr5);
  free(arr6);
  free(arr7);
  free(arr8);
  return 0;
}
