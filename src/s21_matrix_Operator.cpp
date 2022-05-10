#include "s21_matrix_oop.hpp"

S21Matrix S21Matrix::operator+(const S21Matrix& other) {
  if (_rows != other._rows || _cols != other._cols) {
    throw std::invalid_argument("Sizes of both Matrixes are not equal");
  }
  S21Matrix result(*this);
  result.sum_matrix(other);
  return result;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) {
  if (_rows != other._rows || _cols != other._cols) {
    throw std::invalid_argument("Sizes of both Matrixes are not equal");
  }
  S21Matrix result(*this);
  result.sub_matrix(other);
  return result;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) {
  S21Matrix result(*this);
  result.mul_matrix(other);
  return result;
}

S21Matrix S21Matrix::operator*(const double num) {
  S21Matrix result(*this);
  result.mul_number(num);
  return result;
}

S21Matrix operator*(const double num, const S21Matrix& other) {
  S21Matrix result(other);
  result.mul_number(num);
  return result;
}

bool S21Matrix::operator==(const S21Matrix& other) {
  if (_rows != other._rows || _cols != other._cols) {
    throw std::invalid_argument("Sizes of both Matrixes are not equal");
  }
  return eq_matrix(other);
}

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  if (this != &other) {
    this->~S21Matrix();
    init_matrix(other._rows, other._cols);
    copy_matrix(other._matrix);
  }
  return *this;
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
  sum_matrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
  sub_matrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
  mul_matrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const double num) {
  mul_number(num);
  return *this;
}

double& S21Matrix::operator()(int row, int col) const {
  if (_rows < row || _cols < col || col < 0 || row < 0) {
    throw std::out_of_range("Number of rows or columns is less than zero");
  }
  return _matrix[row][col];
}
