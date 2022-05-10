#include "s21_matrix_oop.hpp"

void S21Matrix::init_matrix(int rows, int cols) {
  _rows = rows;
  _cols = cols;
  _matrix = new double*[_rows];
  for (int i = 0; i < _rows; i++) {
    _matrix[i] = new double[_cols];
  }
}

void S21Matrix::copy_matrix(double** matrix) {
  for (int i = 0; i < _rows; i++) {
    for (int j = 0; j < _cols; j++) {
      _matrix[i][j] = matrix[i][j];
    }
  }
}

int S21Matrix::getRows() const { return _rows; }
int S21Matrix::getCols() const { return _cols; }

void S21Matrix::setRows(int num) { _rows = num; }
void S21Matrix::setCols(int num) { _cols = num; }

void S21Matrix::get_minor_matrix(const S21Matrix* other, int cut_row, int cut_col) {
  int row_tmp = 0;
  for (int i = 0; i < _rows; i++) {
    int col_tmp;
    col_tmp = 0;
    if (i == cut_row) row_tmp = 1;
    for (int j = 0; j < _rows; j++) {
      if (j == cut_col) col_tmp = 1;
      _matrix[i][j] = other->_matrix[i + row_tmp][j + col_tmp];
    }
  }
}
