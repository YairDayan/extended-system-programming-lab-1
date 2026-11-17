#include <stdio.h>
#include <stdlib.h>
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

struct fun_desc {
  char *name;
  char (*fun)(char);
};

struct fun_desc menu[] = {{"Get String", my_get},        {"Print Decimal", dprt},
                          {"Print Char and Hex", cxprt}, {"Encrypt", encrypt},
                          {"Decrypt", decrypt},          {NULL, NULL}};

int main(int argc, char **argv)
{
  char line[256];
  char *carray = (char *)malloc(5);
  int carray_allocated = 0;
  int bound = 0;

  if (carray == NULL)
    return 1;
  memset(carray, 0, 5);
  carray_allocated = 1;

  while (menu[bound].name != NULL)
    bound++;

  while (1) {
    printf("Select operation from the following menu:\n");
    for (int i = 0; menu[i].name != NULL; i++)
      printf("%d) %s\n", i, menu[i].name);
    printf("Option: ");
    if (fgets(line, sizeof(line), stdin) == NULL)
      break;

    int choice = atoi(line);
    if (choice < 0 || choice >= bound) {
      printf("Not within bounds\n");
      break;
    }
    printf("Within bounds\n");
    char *new_carray = map(carray, 5, menu[choice].fun);
    if (carray_allocated)
      free(carray);
    carray = new_carray;
    carray_allocated = 1;
  }

  if (carray_allocated)
    free(carray);

  return 0;
}
