#include <stdio.h>

void str_compare(char *a, char *b)
{
  size_t i = 0;
  while (a[i] != '\0' && b[i] != '\0' && a[i] == b[i]) {
    i++;
  }

  if (a[i] < b[i]) {
    printf("\"%s\" is smaller than \"%s\".\n", a, b);
  }
  else if (a[i] > b[i]) {
    printf("\"%s\" is greater than \"%s\".\n", a, b);
  }
  else {
    printf("\"%s\" is equal to \"%s\".\n", a, b);
  }
}

int main()
{
  char str1[] = "Pointer";
  char str2[] = "Pointing";
  str_compare(str1, str2);

  char str3[] = "Some string";
  char str4[] = "Some string";
  str_compare(str3, str4);
  
  return 0;
}

