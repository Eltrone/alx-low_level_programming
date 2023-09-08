#include <stdio.h>

/**
 * main - Prints all possible different combinations of three digits
 * Description: Digits must be separated by commas and a space
 * Return: Always 0 (Success)
 */
int main(void)
{
int first_digit = 0;
int second_digit, third_digit;

while (first_digit <= 9)
{
second_digit = 0;
while (second_digit <= 9)
{
third_digit = 0;
while (third_digit <= 9)
{
if (first_digit < second_digit &&
second_digit < third_digit)
{
putchar(first_digit + '0');
putchar(second_digit + '0');
putchar(third_digit + '0');

if (first_digit * 100 + second_digit * 10 + third_digit != 789)
{
putchar(',');
putchar(' ');
}
}
third_digit++;
}
second_digit++;
}
first_digit++;
}
putchar('\n');
return (0);
}
