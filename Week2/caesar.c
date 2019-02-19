#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int checkKey(int argnum, string key);

int main(int argc, string argv[])
{
    string key =  argv[1];
    // call function
    bool check = checkKey(argc, key);
    if (check == false) {
        printf("./caesar key\n");
        return 1;
    } 
    
    int numKey = atoi(key);
    // So numKey is less than 26
    numKey = numKey % 26;
    
    string plaintext = get_string("plaintext:  ");
    printf("ciphertext: ");
    
    // Iterate through plaintext
    for(int i=0, n=strlen(plaintext); i<n; i++) {
        if ( isalpha(plaintext[i]) ) { // If its alpha
            int asci = plaintext[i];
            asci = asci + numKey; 
            if ( isupper(plaintext[i]) && asci >= 91) { // If its greater than "Z"
                asci = asci % 91; // The remaining to add
                printf("%c", asci + 65); // reset to "A"
            } else if ( islower(plaintext[i]) && asci >= 123) { // If its greater than "z"
                asci = asci % 123; // The remaining to add
                printf("%c", asci + 97); // reset to "a"
            } else {
                printf("%c", asci); 
            }
        } else {
            printf("%c", plaintext[i]);
        }   
    }
    printf("\n");
}

int checkKey(int argnum, string key){
    bool check = true;
    if (argnum == 2){
        // check for each character if number
        for (int i=0; i < strlen(key); i++) {
            if (isdigit(key[i]) == false) {
                check = false;
            }
        }
    } else {
        check = false;
    }
    return check;
}
