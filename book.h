/**
   * This structure models a book.
    */
typedef struct {
  const char *title;
  const char *authorFirstName;
  const char *authorLastName;
  int releaseYear;
  double rating;
} Book;

/**
   * A function that creates a new Book instance.
    */
Book * createBook(const char *title,
                  const char *authorFirstName,
                  const char *authorLastName,
                  int releaseYear,
                  double rating);

/**
   * A function that produces a human-readable
    * string of the given book.
     */
char * bookToString(const Book *b);

/**
   * A comparator function that orders books first
    * by author (last name/first name) and then by
     * year oldest to newest
      */
int cmpByAuthorYear(const void *a, const void *b);

/**
   * A comparator function that orders books by title
    */
int cmpByTitle(const void *a, const void *b);

/**
   * A comparator function that orders books by
    * rating, highest to lowest
     */
int cmpByRating(const void *a, const void *b);

/**
   * Utility function that performs a deep copy of a string
    * This function has been implemented for you.
     */
char * deepCopy(const char *s);

/**
   * Utility function that splits a string into an array
    * of strings along the provided (single character) delimiter.  The last
     * parameter is used to inform the calling function of
      * how many tokens it found and thus the size of the
       * returned string array.
        *
         */
char ** split(const char *str, char delimiter, int *n);

/**
   * Utility function that frees an array of strings
    * that has n strings in it.
     */
void freeStringArray(char **stringArray, int n);

/**
   * This function prints an entire array of Books
    * to the standard output.
     */
void printBookArray(Book *b, int n);
