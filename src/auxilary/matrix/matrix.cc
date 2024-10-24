#include "matrix.h"

Matrix * create_matrix(size_t row, size_t col){
    Matrix *result = new Matrix;
    result->row = row;
    result->col = col;
    result->body = new int* [row];
    for (size_t i = 0; i < row; i++)
        result->body[i] = new int [col];
    for (size_t i = 0; i < row; i++)
        for (size_t j = 0; j < col; j++)
            result->body[i][j] = 0;

    return result;
}

void delete_matrix(Matrix *matrix) {
    for (size_t i = 0; i < matrix->row; i++){
        delete [] (matrix->body[i]);
    }
    delete [] matrix->body;
    delete matrix;
}

void copy_matrix(Matrix *matrix, Matrix *result){
    result->row = matrix->row;
    result->col = matrix->col;
    for (size_t i = 0; i < matrix->row; i++)
    {
        for (size_t j = 0; j <  matrix->col; j++)
        {
            result->body[i][j] = matrix->body[i][j];
        }
        
    }
}

Matrix *rotate_matrix_90(Matrix *rotated_matrix, RotSide side) {
    Matrix *result_matrix = NULL;
    if (rotated_matrix){
        unsigned new_matrix_row = rotated_matrix->col;
        unsigned new_matrix_col = rotated_matrix->row;
        result_matrix = create_matrix(new_matrix_row, new_matrix_col);
        if (result_matrix != NULL){
            for (unsigned ci = 0; ci < rotated_matrix->col; ci++){
                for (unsigned ri = rotated_matrix->row - 1; (int)ri >= 0; ri--){
                    if (side == Clockwise) result_matrix->body[ci][new_matrix_col-1-ri] = rotated_matrix->body[ri][ci];
                    else if (side == Counterclockwise) result_matrix->body[new_matrix_row-1-ci][ri] = rotated_matrix->body[ri][ci];
                }
            }
        }
        else result_matrix = NULL;
    }
    return result_matrix;
}