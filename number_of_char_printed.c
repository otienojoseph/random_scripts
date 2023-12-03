#include <stdio.h>
#include <unistd.h>

int main(void)
{
    int number, printed_chars;

    number = 42;

    printed_chars = printf("Number is: %d\n", number);
    printf("Printed characters: %d\n", printed_chars);
    write(1, &number, 1);

    return (0);
}
