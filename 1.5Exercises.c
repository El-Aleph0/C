/*Exercise Program counts blank spaces */
#include <stdio.h>

int main() {

    int blank_space_count = 0, newline_count = 0;
    char b;
    while ((b = getchar()) != EOF) { // Read characters until EOF
        if (b == ' ') {
            blank_space_count++; // Increment count for each blank space
        } else if(b == '\n') {
            newline_count++; // Reset count for the next line
        } 
    }
    putchar(b); // Output the last character read (EOF)
    printf("Total blank spaces: %d\n", blank_space_count); // Output the total count of blank spaces
    printf("Total newlines: %d\n", newline_count); // Output the total count of newlines
    printf("End of input.\n"); // Indicate the end of input
}
    // Read characters until newline or EOF
    // This will also consume the newline character from the previous input
    // and allow for continuous input