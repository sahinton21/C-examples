#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** Maximum length for strings in this exercise (not counting the null
    terminator). */
#define STRING_LIMIT 80

/** Report that the input is invalid and exit unsuccessfully. */
static void invalid()
{
  fprintf( stderr, "Invalid input\n" );
  exit( EXIT_FAILURE );
}

int main()
{
  // Read the filename from standard input.
  char filename[ STRING_LIMIT + 1 ];
  scanf( "%s", filename );

  // Open an input file with the given name.
  FILE *openedFile = fopen(filename, "r");

  // This is the representation of the string we're creating.  It starts out
  // as an empty string.
  char str[ STRING_LIMIT + 1 ] = "";

  // Current length of the string.  We could use strlen(), but it's convenient
  // to aslo have a variable for this.
  int len = 0;

  // Read the word at the start of each command.
  char command[STRING_LIMIT + 1] = "";
  while (1 == fscanf(openedFile, "%s", command)) {
  
    // Read the operands for the operation.  Make sure it's valid and
    // modify the string if it is.
    //Compares if asking for a compare
    if(strcmp(command, "insert") == 0){
      //error check
      if(len > STRING_LIMIT){
        invalid();
      }
      int index;
      fscanf(openedFile, "%d", &index);
      char newCh;
      //Skip white spaces
      fscanf(openedFile, " %c", &newCh);
      //Shift over the required elements
      for(int i = len; i > index; i--){
        str[i] = str[i - 1];

      }

      //Put the new character in
      str[index] = newCh;
      len++;
    }
    
    
    //Deletes if asking for a deletion
    //Shift left
    else if(strcmp(command, "delete") == 0){
      int index;
      fscanf(openedFile, "%d", &index);
      for(int i = index; i < len - 1; i++){
        str[i] = str[i + 1];

      }
      //Add the terminator character
      str[len - 1] = '\0';
      len--;
    }
    else{
      invalid();
    }
    // Print out the current state of the string.
    printf( "%s\n", str );
  }

  // Close the input file.
  fclose(openedFile);

  return EXIT_SUCCESS;
}
