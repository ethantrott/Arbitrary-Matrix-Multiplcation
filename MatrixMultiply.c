/*
 * Author: Ethan Trott
 * Purpose: To multiply 2 random matrices
 * Language: C
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillRandom(int rows, int columns, int a[][columns]){
	//fill an array with random integers 1 to 9
	
	for (int r=0; r<rows; r++){	//for each row:
		for (int c=0; c<columns; c++){	//for each column:
			a[r][c] = rand()%9 + 1;		//set the value to a random integer 1-9
		}
	}
}

void multiplyMatrices(int r1, int r2, int c1, int c2, int in1[][c1], int in2[][c2], int out[][c2]){
	//multiply two matrices (array in1 and array in2) and store in array out
	
	for (int r=0; r<r1; r++){		//for each row in in1:
		for (int c=0; c<c2; c++){	//for each column in in2:
			out[r][c] = 0;		//set the vale of out[r][c] to 0
			
			for (int x=0; x<c1; x++){	//for each column in in1:
				//add the product of in1[r][x] and in2[x][c] to out[r][c]
				out[r][c]+=in1[r][x]*in2[x][c];
			}
		}
	}
}

int main(){
	srandom(time(0));	//set the seed for random number gen. based on current time

	int rows1, columns1, rows2, columns2;	//the size of the rows and columns for each matrix

	//----Input----
	
	printf("Enter number of rows and columns of first matrix (format: r x c): ");

	//"assume user only enters single digit numbers between 0-9"	
	scanf("%d x %d", &rows1, &columns1);	//store the input for matrix1 dimensions
	while (rows1==0||columns1==0){		//while either of the dimensions is 0:
		//ask for different dimensions
		
		printf("Error: The number of rows or columns of a matrix can't be 0.\nPlease try again.\n\n");
		printf("Enter number of rows and columns of first matrix (format: r x c): ");
		scanf("%d x %d", &rows1, &columns1);	//store the input for matrix1 dimensions
	}

	printf("Enter number of rows and columns of second matrix (format: r x c): ");
	
	//"assume user only enters single digit numbers between 0-9"	
	scanf("%d x %d", &rows2, &columns2);	//store the input for matrix2 dimensions
	while (rows2==0||columns2==0){		//while either of the dimensions is 0:
		//ask for different dimensions

		printf("Error: The number of rows or columns of a matrix can't be 0.\nPlease try again.\n\n");
		printf("Enter number of rows and columns of second matrix (format: r x c): ");
		scanf("%d x %d", &rows2, &columns2);	//store the input for matrix2 dimensions
	}
	
	printf("\n");

	if (rows2 != columns1){		//if the amount of rows in matrix2 doesn't equal the columns in matrix1:
		//report error and end program

	       	printf("Error: The %d x %d matrix can't be multiplied by %d x %d matrix.\n", rows1, columns1, rows2, columns2);
		printf("Reason: The number of columns of the 1st matrix must be equal to the number of rows of the 2nd matrix.\n");
	}else{	//the matrix is valid
		
		//----Processing----

		int matrix1[rows1][columns1];		//create matrix1 with proper dimensions
		int matrix2[rows2][columns2];		//create matrix2 with proper dimensions

		int maxRows;				//the largest amount of rows between the matrices

		fillRandom(rows1, columns1, matrix1);	//fill matrix1 with random integers 1-9
		fillRandom(rows2, columns2, matrix2);	//fill matrix2 with random integers 1-9

		int final[rows1][columns2];		//create the product matrix with proper dimensions
		
		//multiply matrix1 and matrix2 and store the result in final
		multiplyMatrices(rows1, rows2, columns1, columns2, matrix1, matrix2, final);

		if (rows1 > rows2) maxRows = rows1;	//if rows1 is larger than rows2, it's the largest
		else maxRows = rows2;			//if not, rows2 is the largest

		//----Output----

		for (int r=0; r<maxRows; r++){		//for each row in the matrix with the most rows:
			for (int c=0; c<columns1; c++){		//for each column in matrix1:
				//if there is a row to display: display each value
				if (r<rows1) printf("%d ", matrix1[r][c]);
				//if not: display spaces
				else printf("  ");
			}

			if (r==1) printf("  .   ");	//if it's the second row: display the . symbol
			else printf("      ");		//if it's not: display the spaces
			
			for (int c=0; c<columns2; c++){	//for each column in matrix2
				//if there is a row to display: display each value
				if (r<rows2) printf("%d ", matrix2[r][c]);
				//if not: display spaces
				else printf("  ");
			}

			if (r==0) printf("  =   ");	//if it's the first row: display the = symbol
			else printf("      ");		//if it's not display spaces

			if (r<rows1){			//if there's a row in final to display:
				for (int c=0; c<columns2; c++){		//for each column in final:
					printf("%-3d ", final[r][c]);	//display the value in final
				}
			}

			printf("\n");	//start a new line
		}
	}

	return 0;
}
