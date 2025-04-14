#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void readGrid( int rows, int cols, int grid[ rows ][ cols ] )
{
  // Add code to read in all the elements of grid from standard input.
  int current = 0; 
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      scanf("%d", &current);
      grid[i][j] = current;
    }
  }
}


// Add parameters to to pass a variable-sized array to the following
// function.  It's the same as the previous function, but I want you
// to get a chance to type it in yourself.
void reportMaxima( int rows, int columns, int grid[rows][columns] )
{
  
  // Add code to find local maxima and print them out in row major order.
  //Check the corners of the array
  //First row
  for(int i = 0; i < columns; i++){
    if(i == 0){
      if(grid[0][i] > grid[0][1] && grid[0][i] > grid[1][1] && grid[0][i] > grid[1][i]){
        printf("0 0\n");
      }
    }else if(i == columns - 1){
      if(grid[0][i] > grid[0][i - 1] && grid[0][i] > grid[1][i] && grid[0][i] > grid[1][i - 1]){
        printf("0 %d\n", i);
      }
    }else{
      if(grid[0][i] > grid[0][i - 1] && grid[0][i] > grid[0][i + 1] && grid[0][i] > grid[1][i - 1] && grid[0][i] > grid[1][i + 1] && grid[0][i] > grid[1][i]){
        printf("0 %d\n", i);
      }
    }
  }

  //Do the middle rows
  for(int i = 1; i < rows - 1; i++){
    for(int j = 0; j < columns; j++){
    if(j == 0){
      if(grid[i][j] > grid[i][j + 1] && grid[i][j] > grid[i + 1][j + 1] && grid[i][j] > grid[i + 1][j] 
        && grid[i][j] > grid[i - 1][j] && grid[i][j] > grid[i - 1][j + 1]){
        printf("%d %d\n", i, j);
      }
    }else if(j == columns - 1){
      if(grid[i][j] > grid[i][j - 1] && grid[i][j] > grid[i + 1][j - 1] && grid[i][j] > grid[i - 1][j - 1] 
        && grid[i][j] > grid[i - 1][j] && grid[i][j] > grid[i + 1][j]){
        printf("%d %d\n", i, j);
      }
    }else{
      if(grid[i][j] > grid[i][j - 1] && grid[i][j] > grid[i + 1][j - 1] && grid[i][j] > grid[i - 1][j - 1] 
        && grid[i][j] > grid[i - 1][j] && grid[i][j] > grid[i + 1][j] && grid[i][j] > grid[i][j + 1] 
        && grid[i][j] > grid[i + 1][j + 1] && grid[i][j] > grid[i - 1][j + 1]){
        printf("%d %d\n", i, j);
      }
    }

    //Last row
    
    }
  }

  for(int i = 0; i < columns; i++){
    if(i == 0){
      if(grid[rows - 1][i] > grid[rows - 1][1] && grid[rows - 1][i] > grid[rows - 2][i] && grid[rows - 1][i] > grid[rows - 2][1]){
        printf("%d 0\n", rows - 1);
      }
    }else if(i == columns - 1){
      if(grid[rows - 1][i] > grid[rows - 1][i - 1] && grid[rows - 1][i] > grid[rows - 2][i] && grid[rows - 1][i] > grid[rows - 2][i - 1]){
        printf("%d %d\n",rows - 1 , i);
      }
    }else{
      if(grid[rows - 1][i] > grid[rows - 1][i - 1] && grid[rows - 1][i] > grid[rows - 1][i + 1] && grid[rows - 1][i] > grid[rows - 2][i - 1] && grid[rows - 1][i] > grid[rows - 2][i] && grid[rows - 1][i] > grid[rows - 2][i + 1]){
        printf("%d %d\n",rows - 1 , i);
      }
    }
  }
}

int main()
{
  // Add code to read in the grid size from standard input.
  int row = 0;
  int column = 0;
  scanf("%d", &row);
  scanf("%d", &column);

  // Declare a variable-sized array to hold the grid.
  int vars [row][column];

  // Call readGrid() to populate the array.
  readGrid(row, column, vars);
  
  // Call reportMaxima() to print out all local maxima.
  reportMaxima(row, column, vars);
  
  return EXIT_SUCCESS;
}
