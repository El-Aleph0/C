/*Arrays*/
#include <stdio.h>

/*COunts digits, spaces*/

int main(int argc, char const *argv[])
{
    int c, i, nwhite, nother;
    int ndigit[10]; /*array of counters*/
    nwhite = nother = 0; /*initialize counts*/
    for (i = 0; i < 10; i++)
        ndigit[i] = 0; /*initialize digit counters*/
    while ((c = getchar()) != EOF)/*Remeber that the char is now represented in ASCII*/
        if (c >= '0' && c <= '9')   /* */
            ndigit[c - '0']++; /*increment the counter for this digit*/
            /*Why subtract '0'?
            To convert the character code to the correct array index (0–9).
            If you didn't subtract '0', you'd try to access ndigit[48] for '0', which is out of bounds.
            This works because in the ASCII table, the characters '0' to '9' are sequentially ordered.
            Subtracting '0' converts the character digit to its integer value, so you can use it as an array index.
            For example, if c is '48' (the ASCII code for '0'), then c - '0' is 48 - 48, which equals 0.
            If c is '49' (the ASCII code for '1'), then c - '0' is 49 - 48, which equals 1, and so on.
            */
        else if (c == ' ' || c == '\n' || c == '\t')
            nwhite++;
        else
            nother++;
    printf("digits =");
    for (i = 0; i < 10; i++)/**/
        printf(" %d", ndigit[i]);
    printf(", white space = %d, other = %d\n", nwhite, nother);
    /*4 4 4  will print at ndigit[3]//and also in the second position
     = 3 for there are 3 values of four and also three values of three*/
    return 0;
}
