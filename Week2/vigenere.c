#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int checkKey(int argnum, string key);
int shift(char c);

int main(int argc, string argv[])
{
    string key = argv[1];
    bool check = checkKey(argc, key);
    if (check == false) {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    } 
    
    string plaintext = get_string("plaintext:  ");
    printf("ciphertext: ");
    int sizeKey = strlen(key), j = 0;
    for(int i=0, n=strlen(plaintext); i<n; i++) {
        if ( isalpha(plaintext[i]) ) { // If its alpha
            j = j % sizeKey;
            int asci = plaintext[i];
            asci = asci + shift(key[j]); 
            if ( isupper(plaintext[i]) && asci >= 91) { // If its greater than "Z"
                asci = asci % 91; // The remaining to add
                printf("%c", asci + 65); // reset to "A"
            } else if ( islower(plaintext[i]) && asci >= 123) { // If its greater than "z"
                asci = asci % 91; // The remaining to add
                printf("%c", asci + 65); // reset to "A"
            } else {
                printf("%c", asci); 
            } j++;  
        } else {
            printf("%c", plaintext[i]);
        } 
    }
    printf("\n");
}

int shift(char c)
{
    int to_add = tolower(c) - 97;
    return to_add;
}

int checkKey(int argnum, string key){
    bool check = true;
    if (argnum == 2){
        // check for each character if number
        for (int i=0; i < strlen(key); i++) {
            if (isalpha(key[i]) == false) {
                check = false;
            }
        }
    } else {
        check = false;
    }
    return check;
}
