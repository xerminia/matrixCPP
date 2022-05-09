#ifndef S21_MATRIX_OOP_H
#define S21_MATRIX_OOP_H

#include <cmath>
#include <iostream>

class S21Matrix {
 private:
  // Attributes
  int _rows, _cols;
  double** _matrix;

 public:
  void setMatrix(int x, int y, double num);
  double getMatrix(int x, int y);

  int getRows();
  int getCols();
  void setRows(int num);
  void setCols(int num);
  void init_matrix();
  void cut_one_rows_cols(const S21Matrix* other, int rows, int cols);
  void copy_matrix(const S21Matrix& other);

  // Method
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other);
  ~S21Matrix();

  // Matrix operations
  bool eq_matrix(const S21Matrix& other);
  void sum_matrix(const S21Matrix& other);
  void sub_matrix(const S21Matrix& other);
  void mul_number(const double num);
  void mul_matrix(const S21Matrix& other);
  S21Matrix transpose();
  S21Matrix calc_complements();
  double determinant();
  S21Matrix inverse_matrix();

  // overload operator
  S21Matrix operator+(const S21Matrix& other);
  S21Matrix operator-(const S21Matrix& other);
  S21Matrix operator*(const S21Matrix& other);
  S21Matrix operator*(const double num);
  bool operator==(const S21Matrix& other);
  S21Matrix& operator=(const S21Matrix& other);
  S21Matrix& operator+=(const S21Matrix& other);
  S21Matrix& operator-=(const S21Matrix& other);
  S21Matrix& operator*=(const S21Matrix& other);
  S21Matrix& operator*=(const double num);
  double operator()(int rows, int cols);
};

#endif  // S21_MATRIX_OOP_H
