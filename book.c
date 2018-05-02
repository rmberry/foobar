#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "book.h"

Book * createBook(const char * title,
                  const char * authorFirstName,
                  const char * authorLastName,
                  int releaseYear,
                  double rating) {
  Book * book = malloc(sizeof(Book));
  book->title = title;
  book->authorFirstName = authorFirstName;
  book->authorLastName = authorLastName;
  book->releaseYear = releaseYear;
  book->rating = rating;
  return book;
}

//code that figures out the size and then allocates memory for the string and returns it
char * bookToString(const Book *b) {
  const char *format = "title: %s\nauthor's name: %s, %s\nrelease year: %d\nrating: %f\n";
  size_t len = 0;
  //figuring out the size with a dummy run
  len = snprintf(NULL, len, format, s->title, s->authorFirstName, s->authorLastName, s->releaseYear, s->rating);
  char *str = malloc(sizeof(char) * len + 1);
  if(snprintf(str, len + 1, format, s->title, s->authorFirstName, s->authorLastName, s->releaseYear, s->rating) > len + 1) {
    return NULL;
  }
  return str;
}

int cmpByAuthorYear(const void *a, const void *b) {
  int i = strcmp(((const Book*)s1)->lastName, ((const Book*)s2)->lastName);
  if(i == 0) {
    i = strcmp(((const Book*)s1)->firstName, ((const Book*)s2)->firstName);
    if(i == 0) {
      i = ((const Book*)s1)->releaseYear - ((const Book*)s2)->releaseYear;
  }
  return i;
}

int cmpByTitle(const void *a, const void *b) {
  return strcmp(((const Book*)s1)->title, ((const Book*)s2)->title);
}

int cmpByRating(const void *a, const void *b) {
  return ((const Book*)s2)->rating - ((const Book*)s1)->rating;
}


/* utility functions -- these have been done for you */
char * deepCopy(const char *s) {
    char *copy = (char *) malloc( (strlen(s) + 1) * sizeof(char) );
    strcpy(copy, s);
    return copy;
}

char ** split(const char *str, char delimiter, int *n) {

    int i, numDelimiters = 0;
    char delimit[] = {delimiter, '\0'};
    char *s = deepCopy(str);
    for(i=0; i<strlen(str); i++) {
      if(str[i] == delimiter) {
      numDelimiters++;
      }
    }

    char **result = (char **) malloc(sizeof(char**) * (numDelimiters+1));
    char *token = strtok(s, delimit);
    i = 0;
    while(token != NULL) {
      result[i] = deepCopy(token);
      token = strtok(NULL, delimit);
      i++;
    }

    free(s);
    *n = (numDelimiters+1);
    return result;
}

void freeStringArray(char **stringArray, int n) {
    int i;
    for(i=0; i<n; i++) {
      free(stringArray[i]);
    }
    free(stringArray);
    return;
}

void printBookArray(Book *b, int n) {
    int i;
    for(i=0; i<n; i++) {
      char *s = bookToString(&b[i]);
      printf("%s\n", s);
      free(s);
    }
}
