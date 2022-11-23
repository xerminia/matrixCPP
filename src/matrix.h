#ifndef SRC_MATRIX_H_
#define SRC_MATRIX_H_

#include <cmath>
#include <iostream>

const double kEPS = 1e-7;

class Matrix {
 public:
  unsigned GetRows() const;
  unsigned GetCols() const;
  void SetRows(unsigned num);
  void SetCols(unsigned num);

  // Method
  Matrix();
  Matrix(unsigned rows, unsigned cols);
  Matrix(const Matrix& other);
  Matrix(Matrix&& other);
  ~Matrix();

  void clear();

  // Matrix operations
  bool EqMatrix(const Matrix& other);
  void SumMatrix(const Matrix& other);
  void SubMatrix(const Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const Matrix& other);
  Matrix Transpose();
  Matrix CalcComplements();
  double Determinant();
  Matrix InverseMatrix();

  // overload operator
  Matrix operator+(const Matrix& other);
  Matrix& operator+=(const Matrix& other);

  Matrix operator-(const Matrix& other);
  Matrix& operator-=(const Matrix& other);

  Matrix operator*(const Matrix& other);
  Matrix& operator*=(const Matrix& other);

  Matrix operator*(const double num);
  friend Matrix operator*(const double value, const Matrix& other);
  Matrix& operator*=(const double num);

  bool operator==(const Matrix& other);
  Matrix& operator=(const Matrix& other);

  double& operator()(unsigned i, unsigned j) const;

 private:
  unsigned rows_{}, cols_{};
  double** matrix_{nullptr};

 private:
  void MemoryAllocation();
  void GetMinorMatrix(const Matrix* other, unsigned cut_row, unsigned cut_col);
  void CopyMatrix(double** matrix);
};

#endif  // SRC_MATRIX_H_
