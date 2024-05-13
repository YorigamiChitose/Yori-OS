#include <sbi/sbi.h>

void _putchar(char character) {
  sbi_console_putchar(character);
}

