#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int helper(char** matrix, int r, int c, int rows, int cols, int* cache, int* maxSquareLength, int* firstMaxIndex) {
    if (r >= rows || c >= cols) {
        return 0;
    }

    int index = r * cols + c;

    if (cache[index] == -1) {
        int down = helper(matrix, r + 1, c, rows, cols, cache, maxSquareLength, firstMaxIndex);
        int right = helper(matrix, r, c + 1, rows, cols, cache, maxSquareLength, firstMaxIndex);
        int diag = helper(matrix, r + 1, c + 1, rows, cols, cache, maxSquareLength, firstMaxIndex);

        if (matrix[r][c] == '.') {
            cache[index] = 1 + MIN(down, MIN(right, diag));

            if (cache[index] > *maxSquareLength) {
                *maxSquareLength = cache[index];
                *firstMaxIndex = index;
            }
        } else {
            cache[index] = 0;
        }
    }

    return cache[index];
}


int maximalSquare(char** matrix, int matrixSize, int* matrixColSize, int* firstMaxRow, int* firstMaxCol) {
    if (matrixSize == 0 || *matrixColSize == 0) return 0;

    int rows = matrixSize;
    int cols = *matrixColSize;
    int maxSquareLength = 0;
    int firstMaxIndex = -1;

    int* cache = (int*)malloc(rows * cols * sizeof(int));

    for (int i = 0; i < rows * cols; i++) {
        cache[i] = -1;
    }

    helper(matrix, 0, 0, rows, cols, cache, &maxSquareLength, &firstMaxIndex);

    if (firstMaxIndex != -1) {
        *firstMaxRow = firstMaxIndex / cols;
        *firstMaxCol = firstMaxIndex % cols;
    }

    free(cache);

    return maxSquareLength;
}

void convertToSquare(char** matrix, int startRow, int startCol, int sideLength) {
    int i = startRow;
    while (i < startRow + sideLength) {
        int j = startCol;
        while (j < startCol + sideLength) {
            matrix[i][j] = 'x';
            j++;
        }
        i++;
    }
}



int main() {
    char* matrix[] = {
        strdup(".O.OO"),
        strdup("....O"),
        strdup("....O"),
        strdup("....O"),
        strdup("....O")
    };
    int matrixSize = 5;
    int matrixColSize = 5;

    int firstMaxRow, firstMaxCol;
    int maxSquareLength = maximalSquare(matrix, matrixSize, &matrixColSize, &firstMaxRow, &firstMaxCol);

    if (maxSquareLength > 0) {
        convertToSquare(matrix, firstMaxRow, firstMaxCol, maxSquareLength);
    }

    for (int i = 0; i < matrixSize; i++) {
        printf("%s\n", matrix[i]);
        free(matrix[i]);
    }

    return 0;
}
