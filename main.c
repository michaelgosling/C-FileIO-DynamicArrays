#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXFNAME 64


int main() {
    char inName[MAXFNAME];
    FILE *infil;
    int num, maxrow, maxcol;
    int **matrix;


    printf("Enter the name of the array file: ");
    scanf(" %63s", inName);



    if ((infil = fopen (inName, "r")) == NULL) {
        printf("Error! Cannot open input file. \n");
        return 1; // terminate with error
    }

    // first line of file is 2 digits representing size of matrix in "row column" format
    // so we read the line and set them here respectively
    fscanf(infil, "%d %d", &maxrow, &maxcol);
    
    // create matrix based on number of rows and columns
    matrix = (int **)malloc(sizeof(int *)*maxrow);
    for (int count = 0; count < maxrow; count++) {
        matrix[count] = (int *)malloc(sizeof(int)*maxcol);
    }
    
    int row = 1; // row 0 is not part of matrix
    int col = 0;
    
    // read digit strings into matrix positions
    while((fscanf(infil, "%d", &num)) != EOF) {
        matrix[row-1][col] = num; // row - 1 because matrix row 0 is file row 1
        col++;
        if (col >= maxcol) {
            col = 0;
            row++;
        }
    }
    
    fclose(infil);

    for (int i = 0; i < maxrow; i++){
        for (int j = 0; j < maxcol; j++){
            printf("%i ", matrix[i][j]);
        }
        printf("\n");
    }

}
