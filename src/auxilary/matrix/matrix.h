#ifndef BRICK_GAME_SRC_AUXILARY_MATRIX_MATRIX_H
#define BRICK_GAME_SRC_AUXILARY_MATRIX_MATRIX_H

#include <iostream>


typedef struct {
    int** body;
    size_t row;
    size_t col;
} Matrix;

typedef enum {
   Clockwise,
   Counterclockwise
} RotSide;

Matrix * create_matrix(size_t row, size_t col);

void delete_matrix(Matrix *matrix);

void copy_matrix(Matrix *matrix, Matrix *result);

Matrix *rotate_matrix_90(Matrix *rotated_matrix, RotSide side);

#endif // BRICK_GAME_SRC_AUXILARY_MATRIX_MATRIX_H
