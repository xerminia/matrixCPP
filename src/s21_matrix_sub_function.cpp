#include "s21_matrix_oop.hpp"

void S21Matrix::init_matrix() {
  _matrix = new double*[_rows];
  for (int i = 0; i < _rows; i++) {
    _matrix[i] = new double[_cols];
  }
}

void S21Matrix::copy_matrix(const S21Matrix& other) {
  _cols = other._cols;
  _rows = other._rows;

  _matrix = new double*[_rows];
  for (int i = 0; i < _rows; i++) {
    _matrix[i] = new double[_cols];
    for (int j = 0; j < _cols; j++) {
      _matrix[i][j] = other._matrix[i][j];
    }
  }
}

int S21Matrix::getRows() { return _rows; }
int S21Matrix::getCols() { return _cols; }

void S21Matrix::setRows(int num) { _rows = num; }
void S21Matrix::setCols(int num) { _cols = num; }

void S21Matrix::setMatrix(int rows, int cols, double num) {
  if (_rows <= rows || _cols <= cols) {
    throw std::out_of_range("Incorrect Matrix");
  }
  _matrix[rows][cols] = num;
}
double S21Matrix::getMatrix(int rows, int cols) {
  if (_rows <= rows || _cols <= cols) {
    throw std::out_of_range("Incorrect Matrix");
  }
  return _matrix[rows][cols];
}

void S21Matrix::cut_one_rows_cols(const S21Matrix* other, int rows, int cols) {
  int row_tmp = 0;
  for (int i = 0; i < _rows; i++) {
    int col_tmp;
    col_tmp = 0;
    if (i == rows) row_tmp = 1;
    for (int j = 0; j < _rows; j++) {
      if (j == cols) col_tmp = 1;
      _matrix[i][j] = other->_matrix[i + row_tmp][j + col_tmp];
    }
  }
}
