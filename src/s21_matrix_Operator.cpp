#include "s21_matrix_oop.hpp"

S21Matrix S21Matrix::operator+(const S21Matrix& other) {
  S21Matrix result(_rows, _cols);
  result.sum_matrix(other);
  result.sum_matrix(*this);
  return result;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) {
  S21Matrix result(_rows, _cols);
  result.sum_matrix(*this);
  result.sub_matrix(other);
  return result;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) {
  S21Matrix result(_rows, _cols);
  result.sum_matrix(*this);
  result.mul_matrix(other);
  return result;
}

S21Matrix S21Matrix::operator*(const double num) {
  S21Matrix result(_rows, _cols);
  result.sum_matrix(*this);
  result.mul_number(num);
  return result;
}

bool S21Matrix::operator==(const S21Matrix& other) {
  return this->eq_matrix(other);
}

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  if (this != &other) {
    this->~S21Matrix();
    this->copy_matrix(other);
  }
  return *this;
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
  this->sum_matrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
  this->sub_matrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
  this->mul_matrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const double num) {
  this->mul_number(num);
  return *this;
}

double S21Matrix::operator()(int rows, int cols) {
  if (_rows <= rows || _cols <= cols) {
    throw std::out_of_range("Incorrect input");
  }
  return _matrix[rows][cols];
}
