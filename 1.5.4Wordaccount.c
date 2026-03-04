/*Word account*/
#include <stdio.h>

#define IN 1 /*in one word*/
#define OUT 0 /*out of a word*/

int main() {
    int c, state = OUT, word_count = 0, other_count = 0;

    while ((c = getchar()) != EOF) {/*getchar translates word to ascii*/
        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT; /*we are out of a word*/
            other_count++;
            

            
        } else if (state == OUT) {
            state = IN; /*we are in a word*/
            ++word_count;
            printf("\nASCII: %d =",c); // Print ASCII value
            putchar(c); // Output the first character of the word also print its ASCII value 
        }else {
            printf("\nASCII: %d =", c); // Print ASCII value
            putchar(c); // Output the character if we are already in a word also print its ASCII value
        }
    }

    printf("\nWord count: %d\n", word_count);
    return 0;
}

/* Note: The program counts words based on spaces, newlines, and tabs.
 * It also counts other characters and prints their ASCII values.
 * The program will continue reading until EOF is encountered.
 */

