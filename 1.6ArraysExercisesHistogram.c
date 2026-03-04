/*Count length

prints histogram of the length of the word*/
#include <stdio.h>

#define MAX_WORD_LENGTH 5 /*max word length*/
int main()
{
    int c, i, nwhite, nother;
    int histogram[20]= {0};
    int valueforlength=0;
    nwhite = nother = 0;
    
    printf("\nWord length histogram:\n");
    
    printf("\n");
    
    while ((c = getchar()) != EOF)
    {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            printf("*"); // To visualize input processing, c is a letter
            histogram[valueforlength]++;
            //printf("\n");
        }
        else if (c == ' ' || c == '\n' || c == '\t'){//end of a word
            printf("\n");
            valueforlength++;
            nwhite++;
        }else{
            nother++;
            }
    }
    printf("\nWord length horizontal histogram:");//print header
    for (i = 0; i < MAX_WORD_LENGTH; i++){//for each possible word length
        printf("\nLength %2d: %d\t", i + 1, histogram[i]);//print length and its count
        int length = histogram[i];//get the count for this length
        for (int j = 0; j < length; j++) {//print stars for the count
            printf("*");
        }
        
    
    }
    printf("\nWord length vertical histogram:\n");//print header
    for (i = 0; i < MAX_WORD_LENGTH; i++){//for each possible word length
        //printf("%2d\t", i + 1);//print length and its count
    }
    printf("\n");
    for (i = 0; i < MAX_WORD_LENGTH; i++){//for each possible word length
        printf("%d\t", histogram[i]);//print length and its count
               
    }
    //Printing stars vertically
    printf("\n");   

    for (i = 0; i < MAX_WORD_LENGTH; i++){//for each possible word length
        int length = histogram[i];//get the count for this length
        printf("\n");   
        
        for (int j = 0; j < MAX_WORD_LENGTH; j++) {//print stars for the count
            if (length > 0)
            {
                printf("*\t");/* code */
                length--;
                //roi++;
                //histogram[i+1];
                
            }
            if (length <= 0)
            {
                printf("\t");
            }
            histogram[i+1];
            
        }
        //printf("\n");
    }


    // Find the maximum value in histogram to know the height of the histogram
    int max = 0;
    for (i = 0; i < MAX_WORD_LENGTH; i++) {
        if (histogram[i] > max)
            max = histogram[i];
    }

printf("\nWord length vertical histogram:\n");

// Print histogram row by row (from top row down to 1)
for (int row = max; row > 0; row--) {
    for (i = 0; i < MAX_WORD_LENGTH; i++) {
        if (histogram[i] >= row)
            printf("*\t");  // print bar
        else
            printf(" \t");  // empty space
    }
    printf("\n");
}

// Print labels (word lengths) at bottom
for (i = 0; i < MAX_WORD_LENGTH; i++) {
    printf("%d\t", i + 1);
}
printf("\n");

    return 0;
}
