#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int i = 0;
    float cash;
    do {
        cash = get_float("Change Owned: ");
    } while (cash < 0);
    int cash2 = cash * 100;
    while(cash2 >= 25) {
        cash2 -= 25;
        i++;
    }
    while(cash2 >= 10) {
        cash2 -= 10;
        i++;
    }
    while(cash2 >= 5) {
        cash2 -= 5;
        i++;
    }
    while(cash2 >= 1) {
        cash2 -= 1;
        i++;
    }
    printf("%i\n", i);
}
