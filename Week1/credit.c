#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int odd, even2, evenx, sumodd = 0, sumeven = 0, total, digits=0;
    long ccnum, credit;
    do {
        ccnum = get_long("Number: ");
    } while (ccnum< 0);
    credit = ccnum;
    while (credit != 0) {
        odd = credit % 10;
        sumodd += odd;
        credit /= 10;
        digits++;
        if(credit == 0) {
            break;
        }
        even2 = (credit % 10) *2;
        if (even2 >= 10) {
            evenx =0;
            while(even2 != 0) {
                evenx = evenx + even2 % 10;
                even2 /= 10;
            } even2 = evenx;
        }
        sumeven += even2;
        credit/=10;
        digits++;
    }
    total = sumodd + sumeven;
    /*
    printf("sumodd: %i; sumeven2: %i; total:%i; digits: %i\n", sumodd, sumeven, total, digits); 
    */
    if (total % 10 == 0) {
        if(digits == 15) {
            if(ccnum / 10000000000000 == 34 || ccnum / 10000000000000 == 37) {
                printf("AMEX\n");
            }
        } else if (digits == 16 & ccnum / 1000000000000000 == 4) {
                printf("VISA\n");
        } else if (digits == 13 & ccnum / 1000000000000 == 4) {
                printf("VISA\n");
        } else if (digits == 16){
            switch (ccnum / 100000000000000) {
                case 51:
                case 52:
                case 53:
                case 54:
                case 55:
                    printf("MASTERCARD\n");
            }
        }
    } else {
        printf("INVALID\n");
    }
}
