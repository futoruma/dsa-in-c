#include <stdio.h>

void str_get_permutations(char *str, int k)
{
  static int used[10] = {};
  static char res[10];

  if (str[k] == '\0') {
    res[k] = '\0';
    printf("%s\n", res);
    return;
  }

  for (size_t i = 0; str[i] != '\0'; ++i) {
    if (used[i] == 1) {
      continue;
    }

    res[k] = str[i];
    used[i] = 1;
    
    str_get_permutations(str, k + 1);
    
    used[i] = 0;
  }
}

int main()
{
  char str1[] = "abc";
  printf("Permutations of \"%s\":\n", str1);
  str_get_permutations(str1, 0);
  printf("\n");
  
  char str2[] = "abcd";
  printf("Permutations of \"%s\":\n", str2);
  str_get_permutations(str2, 0);
  printf("\n");
  
  return 0;
}

