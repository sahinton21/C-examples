/**
    @file style.c
    @author Sean Hinton (sahinto2)
    This program generates a random paragraph of text.
    
 */
#include <stdio.h>
#include <stdlib.h>

/** The maximum length of a line printed by printLine*/
#define LINE_LENGTH_LIMIT 72

/**
    Prints a random lowercase letter x number of time
    @param x the number of times a random character is printed  
*/
void printWord( int x )
{
  for ( int i = 0; i < x; i++ ){
    // Print a random lower-case letter.
    printf( "%c", 97 + rand() % 26 );
  }
}

/**
    Prints a line of words up to a limited number of charcater
    defined by LINE_LENGTH_LIMIT.
    Returns the number of words printed in the line
    @return count the number of words printed on the line 
*/
int printLine()
{
  int count = 0, pos = 0, space = 0;
  int len = 1 + rand() % 10;
  // Print a line of words up to a limited length.
  while ( pos + len + space < LINE_LENGTH_LIMIT ) {
    if ( space > 0 ) {
      printf( " " );
    }

    printWord( len );
    pos += len + space;
    len = 1 + rand() % 10;
    space = 1;
    count += 1;
  }

  printf( "\n" );
  return count;
}

/**
    Prints a paragraph with n number of lines and returns the total word count.
    @param n the number of lines to be printed in the paragraph
    @total the total number of words printed by the printLine methods
*/
int printParagraph( int n )
{
  int total = 0;
  for ( int i = 0; i < n; i++ ){
  
    total += printLine();
  }
  return total;
}

/**
    Prints a paragraph with 10 lines of randomly generated words
    and prints out the total word count of the paragraph.
    @return program exit status
*/
int main()
{
  int w = printParagraph(10);
  printf("Words: %d\n",w);
  return 0;
}
