#include <stdio.h>

void str_check_if_anagram(char *a, char *b)
{
  int count[26] = {};

  size_t i = 0;
  while (a[i] != '\0') {
    count[a[i] - 97]++;
    i++;
  }

  size_t j = 0;
  while (b[j] != '\0') {
    count[b[j] - 97]--;
    if (count[b[j] - 97] == -1) {
      printf("\"%s\" and \"%s\" are not anagrams.\n", a, b);
      return;
    }
    j++;
  }

  if (i != j) {
    printf("\"%s\" and \"%s\" are not anagrams.\n", a, b);
  }

  printf("\"%s\" and \"%s\" are anagrams.\n", a, b);
}

int main()
{
  char str1[] = "medical";
  char str2[] = "decimal";
  str_check_if_anagram(str1, str2);
  
  char str3[] = "decimal";
  char str4[] = "method";
  str_check_if_anagram(str3, str4);
  
  char str5[] = "major";
  char str6[] = "minor";
  str_check_if_anagram(str5, str6);
  
  return 0;
}

