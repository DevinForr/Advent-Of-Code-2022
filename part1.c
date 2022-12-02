#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int result(char elf, char you) {
  int score = 0;
  int win = 6;
  int draw = 3;
  int rock = 1, paper = 2, scissors = 3;
  if (elf == 'A') {
    if (you == 'X') {
      score += rock+draw;
    } else if (you == 'Y') {
      score += paper+win;
    } else if (you == 'Z') {
      score += scissors;
    }
  } else if (elf == 'B') {
    if (you == 'X') {
      score += rock;
    } else if (you == 'Y') {
      score += paper+draw;
    } else if (you == 'Z') {
      score += scissors+win;
    }
  } else if (elf == 'C') {
    if (you == 'X') {
      score += rock+win;
    } else if (you == 'Y') {
      score += paper;
    } else if (you == 'Z') {
      score += scissors+draw;
    }
  }
  return score;
}

int main(void) {
  FILE *fp;
  fp = fopen("input.txt", "r");
  ssize_t read;
  size_t length = 10;
  char *line = malloc(10);
  int score = 0;
  char you, elf;
  while ((read = getline(&line, &length, fp)) != -1) {
     sscanf(line, "%c %c", &elf, &you);
     score += result(elf, you);
  }
  printf("Total Score: %d", score);
  free(line);
  return 0;
} 