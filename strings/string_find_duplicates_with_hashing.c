#include <stdio.h>

void str_find_duplicates_with_hashing(char *str)
{
  int count[26] = {};

  for (size_t i = 0; str[i] != '\0'; ++i) {
    if (str[i] > 64 && str[i] < 91) {
      count[str[i] - 65]++;
    }
    else if (str[i] > 96 && str[i] < 123) {
      count[str[i] - 97]++;
    }
  }

  int duplicates = 0;
  for (size_t i = 0; i < 26; ++i) {
    if (count[i] == 0) {
      continue;
    }

    duplicates += count[i] - 1;
  }

  printf("\"%s\" has %d duplicate letters.\n", str, duplicates);
}

int main()
{
  char str1[] = "No duplicates.";
  str_find_duplicates_with_hashing(str1);

  char str2[] = "This string may contain some duplicates.";
  str_find_duplicates_with_hashing(str2);

  return 0;
}

