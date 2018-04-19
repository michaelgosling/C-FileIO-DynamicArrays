#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXFNAME 64


int main() {
    char inName[MAXFNAME];
    char *fileString;
    FILE *infil;
    int c, maxrow, maxcol;
    int **matrix;


    printf("Enter the name of the array file: ");
    scanf(" %63s", inName);



    if ((infil = fopen (inName, "r")) == NULL) {
        printf("Error! Cannot open input file. \n");
        return 1; // terminate with error
    }

    int n = 0;
    int n2 = 0;

    while ((c=getc(infil)) != EOF){
        if (n == 0){
            char newC = (char)&c;
            maxrow = (int)newC;
        } else if (n == 1){
            char newC = (char)&c;
            maxcol = (int)newC;
            matrix = (int **)malloc(sizeof(int *)*maxrow);
            for (int count = 0; count < maxrow; count++){
                matrix[count] = (int *)malloc(sizeof(int)*maxcol);
            }
        } else {
            matrix[n][n2] = c;
            n2++;
            if (n2 >= maxcol){
                n2 = 0;
            }
        }
        if (n2 == 0){
            n++;
        } else {
            n2++;
        }

    }

    for (int i = 0; i < maxrow; i++){
        for (int j = 0; j < maxcol; j++){
            printf("%i ", matrix[i][j]);
        }
        printf("\n");
    }


    // dynamically allocate an array
    // maxrow = number of matrix rows
    // maxcol = line length

//    matrix = (int **)malloc(sizeof(int *)*maxrow);
//
//    for (int count = 0; count < maxrow; count++)
//    {
//        matrix[count] = (int *)malloc(sizeof(int)*maxcol);
//    }

}