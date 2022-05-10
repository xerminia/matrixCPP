#include "s21_matrix_oop.hpp"

bool S21Matrix::eq_matrix(const S21Matrix& other) {
  bool flag = true;
  if (_rows == other._rows && _cols == other._cols) {
    for (int i = 0; i < _rows && flag; i++) {
      for (int j = 0; j < _cols && flag; j++) {
        if (fabs(_matrix[i][j] - other._matrix[i][j]) > 1e-7) flag = false;
      }
    }
  } else {
    flag = false;
  }
  return flag;
}

void S21Matrix::sum_matrix(const S21Matrix& other) {
  if (_rows != other._rows || _cols != other._cols) {
    throw std::invalid_argument("Sizes of both Matrixes are not equal");
  }
  for (int i = 0; i < _rows; i++) {
    for (int j = 0; j < _cols; j++) {
      (*this)(i, j) += other(i, j);
    }
  }
}

void S21Matrix::sub_matrix(const S21Matrix& other) {
  if (_rows != other._rows || _cols != other._cols) {
    throw std::invalid_argument("Sizes of both Matrixes are not equal");
  }
  for (int i = 0; i < _rows; i++)
    for (int j = 0; j < _cols; j++) (*this)(i, j) -= other(i, j);
}

void S21Matrix::mul_number(const double num) {
  for (int i = 0; i < _rows; i++) {
    for (int j = 0; j < _cols; j++) {
      (*this)(i, j) *= num;
    }
  }
}

void S21Matrix::mul_matrix(const S21Matrix& other) {
  if (_cols != other._rows) {
    throw std::invalid_argument(
        "Number of columns in first matrix are not equal to number of rows in "
        "second matrix");
  }
  S21Matrix result(_rows, other._cols);
  for (int i = 0; i < _rows; i++) {
    for (int j = 0; j < other._cols; j++) {
      for (int k = 0; k < other._rows; k++) {
        result._matrix[i][j] += _matrix[i][k] * other._matrix[k][j];
      }
    }
  }
  *this = result;
  // tmp.~S21Matrix();
}

S21Matrix S21Matrix::transpose() {
  S21Matrix result(_cols, _rows);
  for (int i = 0; i < _rows; i++) {
    for (int j = 0; j < _cols; j++) {
      result(j, i) = (*this)(i, j);
    }
  }
  return result;
}

S21Matrix S21Matrix::calc_complements() {
  if (_rows != _cols && _rows < 2) {
    throw std::invalid_argument("Matrix is not square");
  }
  S21Matrix result(_rows, _cols), tmp(_rows - 1, _cols - 1);
  for (int i = 0; i < _rows; i++) {
    for (int j = 0; j < _rows; j++) {
      tmp.get_minor_matrix(this, i, j);
      result._matrix[i][j] = pow(-1, i + j) * tmp.determinant();
    }
  }
  return result;
}

double S21Matrix::determinant() {
  if (_rows != _cols) {
    throw std::invalid_argument("Matrix is not square");
  }
  double result = 0.0;
  if (_rows == 1) {
    result = _matrix[0][0];
  } else if (_rows == 2) {
    result = _matrix[0][0] * _matrix[1][1] - _matrix[1][0] * _matrix[0][1];
  } else {
    int sign = 1;
    S21Matrix tmp(_rows - 1, _cols - 1);
    for (int i = 0; i < _rows; i++) {
      tmp.get_minor_matrix(this, i, 0);
      result += sign * _matrix[i][0] * tmp.determinant();
      sign *= -1;
    }
  }
  return result;
}

S21Matrix S21Matrix::inverse_matrix() {
  double determ = determinant();
  if (fabs(determ) < 1e-7) {
    throw std::invalid_argument("Determinant is zero");
  }
  S21Matrix tmp = calc_complements();
  S21Matrix result = tmp.transpose();
  result.mul_number(1.0 / determ);

  return result;
}
