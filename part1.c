#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  FILE *fp;
  int total = 0;
  int max = 0;
  int numLine = 0;
  int elf = 1;
  int first;
  size_t length = 10;
  char *line = malloc(10);
  ssize_t read;
  fp = fopen("input.txt", "r");
  while ((read = getline(&line, &length, fp)) != -1) {
    if (strcmp(line, "\n") == 0) {
      if (total > max) {
        max = total;
        first = elf;
      }
      total = 0;
      elf++;
    }
    sscanf(line, "%d", &numLine);
    total += numLine;
    numLine = 0;
  }
  printf("Elf #%d is carrying %d pounds\n", first, max);
  return 0;
}