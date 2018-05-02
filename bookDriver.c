#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "book.h"

int main(int argc, char **argv) {
    
    if(argc != 2) {
      printf("Usage: %s filename.csv\n", argv[0]);
      exit(1);
    }
      
    char *fileName = argv[1];

    deepCopy(argv[1]);

    int n = 0;
    int i, j;
    //i < 20 is to run for the number of lines in the csv file
    for(i = 0; i < 20; i ++) {
      split(copy[i], ',', n);
      //j < 5 is to run for the number of strings that will now exist
      //due to four delimeters per line
        for(j = 0; j < 5; j++) {
          createBook;
          book[i] = copy[i][j];
        }
    }

    //sort by book title
    qsort(books, n, sizeof(Book), cmpByTitle);
    printBookArray(books, n);

    //sort by author(last, first)
    qsort(books, n, sizeof(Book), cmpByAuthorYear);
    printBookArray(books, n);

    //sort by rating
    qsort(books, n, sizeof(Book), cmpByRating);
    printBookArray(books, n);

    //making sure to free memory before returning
    freeStringArray(books, n);

    return 0;
}
