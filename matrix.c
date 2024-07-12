#include <stdio.h>


typedef struct {
int matrixgraph[MAX][MAX];
size_t rows;
size_t cols;
} matrix;

int main (void)
{
size_t j, k;
matrix m;

int LoadMatrix(matrix *m);

if (LoadMatrix (&m) == -1) {
    fprintf (stderr, "error: LoadMatrix failed.\n");
    return 1;
}

printf ("\nThe %zux%zu matrix read from file is:\n\n", m.rows, m.cols);    
for (j = 0; j < m.rows; j++) {
    char *pad = " [ "; 
    for (k = 0; k < m.cols; k++) {
        printf ("%s%2d", pad, m.matrixgrafh[j][k]);
        pad = ", ";
    }
    printf (" ]\n");
}
putchar ('\n');

return 0;
}