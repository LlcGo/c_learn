#include <stdio.h>

int main() {
  for (const char *s = "Hello, OS World!\n"; *s; s++) {
    putchar(*s);
  }
  return 0;
}
