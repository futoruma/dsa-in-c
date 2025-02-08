#include <stdio.h>

void str_find_duplicates_with_bitmap(char *str)
{
  int duplicates = 0;
  int bitmap = 0;

  for (size_t i = 0; str[i] != '\0'; ++i) {
    int shifts = 0;
    if (str[i] > 64 && str[i] < 91) {
      shifts += (str[i] - 65);
    }
    else if (str[i] > 96 && str[i] < 123) {
      shifts += (str[i] - 97);
    }
    else {
      continue;
    }

    int x = 1;
    x <<= shifts;

    if ((bitmap & x) > 0) {
      duplicates++;
    }
    else {
      bitmap |= x;
    }
  }

  printf("\"%s\" has %d duplicate letters.\n", str, duplicates);
}

int main()
{
  char str1[] = "No duplicates.";
  str_find_duplicates_with_bitmap(str1);

  char str2[] = "This string may contain some duplicates.";
  str_find_duplicates_with_bitmap(str2);

  return 0;
}

