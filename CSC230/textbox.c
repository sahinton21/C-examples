/**
    @file textbox.c
    @author Sean Hinton (sahinto2)
    Creates a textbox around around some given text   
  */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/** Width of each line of text in the box. */
#define LINE_WIDTH 60

/** Symbol used to draw the border around the box. */
#define BORDER '*'

/**
    Prints one line of text with a BORDER character at the start and end of the     line.
    The line of text must be 60 characters between the borders.
    If there are less than 60 characters spaces are added. If there are more        than 60 characters characters are read but omitted after 60 characters.
    @return true if the line is successfully read and printed false if the
    end of the file is reached.    
  */
bool paddedLine()
{
  
  int chToPrint;
  chToPrint = getchar();
  if(chToPrint == EOF){
    return false;
  }
  putchar(BORDER);
  
  int counter = 0;
  
  while(chToPrint != '\n'){
    
    if(counter < 60){
      putchar(chToPrint);
    }
    
    chToPrint = getchar();
    counter++;
  }
    
  //Adds extra spaces if necessary
  if(counter < LINE_WIDTH){
    for(int i = counter; i < LINE_WIDTH; i++){
      putchar(' ');
    }
  }
  // else if(counter == LINE_WIDTH){
  //   chToPrint = getchar();
  //   while(chToPrint != '\n'){
  //     chToPrint = getchar();
      
  //   }
  // }


  putchar(BORDER);

  //Read the remaining characters if necessary

  //Returns true if there is still another line
  
  
  
  if(chToPrint == '\n'){
    return true;
  }
  
  return false;
  
}

/**
    Prints a given character an amount of times equal to count.
    Used to print the top and bottom border for the box around the text.
    @param ch the character to be printed
    @param count the number of times to print ch
  */
void lineOfChars( char ch, int count )
{
  for(int i = 0; i < count; i++){
    putchar(ch);
  }
  putchar('\n');
}

/**
    Prints the top border for the textbox then surrounds the text with a border
    and finally prints the bottoms border for the textbox.
    @return 0 if the program successfully creates a textbox for the text.
  */
int main()
{
  //Prints the top border
  lineOfChars(BORDER, LINE_WIDTH + 2);
  
  while(paddedLine()){
    putchar('\n');
  }
  
  
  
 
  //Prints the bottom border
  lineOfChars(BORDER, LINE_WIDTH + 2);
  return EXIT_SUCCESS;
}
