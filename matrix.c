#include <stdio.h>

#define MAX 100

typedef struct {
int matrixgrafh[MAX][MAX];
size_t rows;
size_t cols;
} matrix;

int main (void)
{
size_t j, k;
matrix m;

if (LoadMatrix(&m) == -1) {
    fprintf(stderr, "error: LoadMatrix failed.\n");
    return 1;
}

printf ("\nThe %zux%zu matrix read from file is:\n\n", m.rows, m.cols);    


return 0;
}