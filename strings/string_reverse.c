#include <stdio.h>

void str_reverse(char *str)
{
  size_t j = 0;
  while (str[j] != '\0') {
    j++;
  }
  j--;

  char tmp;

  size_t i = 0;
  while (i < j) {
    tmp = str[i];
    str[i] = str[j];
    str[j] = tmp;

    i++;
    j--;
  }
}

int main()
{
  char str[] = "string for reversal";

  printf("%s\n", str);

  str_reverse(str);
  printf("%s\n", str);
  
  return 0;
}

