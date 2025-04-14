/**
    @file trig.c
    @author Sean Hinton (sahinto2)
    Receives an angle in radians then prints out increasingly accurate approximations
    of the sine, cosine, and tangent of the angle.
  */
#include <stdio.h>
#include <stdlib.h>

/** Approximation of PI.  For now, we're using our own constant for
    this. There's also one provided by the gnu math library, once we
    learn about that. */
#define PI 3.14159265358979323846

/**
    Scans for a double the user inputs and checks that it is a valid input.
    Valid inputs are less than or equal to PI, greater than or equal to negative PI.
    If the value is invalid "Invalid Input" is printed and the program ends.
    @return the double the user input 
*/
double getAngle()
{
  double angle = 10.0;
  scanf("%lf", &angle);
  if(angle > PI || angle < -1 * (PI)){
    printf( "Invalid input\n" );
  }
  

  return angle;
}

/**
    Gets the difference between a and b so the program knows how 
    accurate its estimate of sine and cosine are.
    @param a the previous table entry
    @param b the current table entry
    @return the difference between the two as a positive number
*/
double difference( double a, double b )
{
  if(b > a){
    return b - a; 
  }else{
    return a - b;
  }
}

/**
    Prints out the two lines at the beginning of the output that label the table.
*/
void tableHeader()
{
  printf( "terms |         sin |         cos |         tan \n------+-------------+-------------+-------------\n" );
}

/** 
    Prints out the values of each of the labelled values.
    The number of terms of the Taylor Series, sine value, cosine value, tangent value.
*/
void tableRow( int terms, double s, double c, double t )
{
  printf( "   %2d |%12.7lf |%12.7lf |%12.7lf\n", terms, s, c, t );
}

/**
    Prints out all the contents for what the user entered.
    Calls each function for scanning user input and printing out the table.
    Also finds the values for sine and cosine.
    Decides when the function should terminate when cosine and sine are very close.
    Begins when cosine is equal to 1 and sine is equal to zero then gets closer
    @return EXIT_SUCCESS, 0 if the program is successful
  */
int main()
{
  
  double angle = getAngle();


  if(angle > PI || angle < -1 * PI){
    
    return EXIT_SUCCESS;
  }
  tableHeader();
  
  double prevCos = 1.0;
  double prevSin = 0.0;
  int term = 1;
  tableRow(term, prevSin, prevCos, prevSin / prevCos);

  while(1 == 1){


    double nextSin = 0.0;
    double nextCos = 0.0;   
    
    //Calculates the sine value using a Taylor series
    if( term % 2 == 1 ){
      //Gets the angle to the power of the ter
      nextSin = angle;
      
      for(int i = 1; i < term; i++){
        nextSin *= angle;
        
      }
      for(int i = 1; i <= term; i++){
        nextSin /= (double) i;
      }
      
      //Checks whether to add or subtract based on where it is in the sequence of odd numbers
      //1, 5, 9 add while 3, 7, 11 subtract
      //Confirms by checking if its in a sequence of every 4 numbers starting at 1
      double orderOfOp = ((double)term - 1.0) / 4.0 + 0.5;
      //Adds
      if( ( int )orderOfOp == ( term - 1 ) / 4 ){
        nextSin = prevSin + nextSin;

      //Subtracts
      }else{
        nextSin = prevSin - nextSin;
      }
    }
    else{
      nextSin = prevSin;
    }
    
    //Calculates the cosine value using a Taylor Series
    if( term % 2 == 0 ){
      nextCos = angle;
      for(int i = 1; i < term; i++){
        nextCos *= angle;
      }

      
      for(int i = 1; i <= term; i++){
        nextCos /= (double) i;
      }


      //Checks whether to add or subtract based on where it is in the sequence of odd numbers
      //2, 6, 10 subtract while 4, 8, 12 add
      //Confirms by checking if its in a sequence of every 4 numbers starting at 2
      double orderOfOp = ((double)term - 2.0) / 4.0 + 0.5;
      //Subtracts
      if( ( int )orderOfOp == ( term - 2 ) / 4 ){
        nextCos = prevCos - nextCos;

      //Adds
      }else{
        nextCos = prevCos + nextCos;
      }

      

    }
    else{
      nextCos = prevCos;
    }
    term++;
    tableRow( term, nextSin, nextCos, nextSin / nextCos );
    
    if( difference( nextSin, prevSin ) < .000001 && difference( nextCos, prevCos ) < .000001){
      return EXIT_SUCCESS;
    }
    prevCos = nextCos;
    prevSin = nextSin;
    
  }
  return EXIT_SUCCESS;
}
