#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int n = 3;

void printMatrix (int matrix[][n], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void * function (void * args) {
    int ** arr = (int **) args;

    int * row = arr[0];
    int * column = arr[1];

    int *result = malloc(sizeof(int));
    * result = 0;

    for (int i = 0; i < n; i++) {
        * result += row[i] * column[i];
    }

    pthread_exit((void *) result);
}

int main () {

    srand(time(NULL));

    //matrix creation
    int matrix1 [n][n];
    int matrix2 [n][n];

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            matrix1[r][c] = rand() % 10;
            matrix2[c][r] = rand() % 10;
        }
    }

    printf("Matrix 1:\n");
    printMatrix(matrix1, n);
    printf("Matrix 2:\n");
    printMatrix(matrix2, n);

    int result [n][n];

    //threads
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            pthread_t thread;
            int * args[] = {matrix1[i], matrix2[j]};
            void * retval;
            pthread_create(&thread, NULL, function, (void *) args);
            pthread_join(thread, &retval);
            result[i][j] = * (int *) retval;
        }
    }

    printf("Result matrix:\n");
    printMatrix(result, n);

    return 0;
}