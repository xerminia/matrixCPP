#include "matrix.h"

// Базовый конструктор
Matrix::Matrix() = default;

// Параметризованный конструктор
Matrix::Matrix(unsigned rows, unsigned cols) : rows_(rows), cols_(cols) {
  if (rows_ < 1 || cols_ < 1) {
    throw std::out_of_range("Number of rows or columns is less than zero");
  }
  MemoryAllocation();
}

// Конструктор копирования
Matrix::Matrix(const Matrix& other) : Matrix(other.rows_, other.cols_) {
  CopyMatrix(other.matrix_);
}

// Конструктор перемещения
Matrix::Matrix(Matrix&& other)
    : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_) {
  other.matrix_ = nullptr;
  other.rows_ = 0;
  other.cols_ = 0;
}

// Деструктор
Matrix::~Matrix() { clear(); }

void Matrix::clear() {
  for (unsigned i{}; i < rows_; ++i) {
    delete[] matrix_[i];
  }
  delete[] matrix_;
  matrix_ = nullptr;
  rows_ = 0;
  cols_ = 0;
}

bool Matrix::EqMatrix(const Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) return false;
  for (unsigned i{}; i < rows_; ++i)
    for (unsigned j{}; j < cols_; ++j)
      if (fabs(matrix_[i][j] - other.matrix_[i][j]) > kEPS) return false;
  return true;
}

void Matrix::SumMatrix(const Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_)
    throw std::invalid_argument("Sizes of both Matrixes are not equal");

  for (unsigned i{}; i < rows_; ++i)
    for (unsigned j{}; j < cols_; ++j) matrix_[i][j] += other.matrix_[i][j];
}

void Matrix::SubMatrix(const Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_)
    throw std::invalid_argument("Sizes of both Matrixes are not equal");

  for (unsigned i{}; i < rows_; ++i)
    for (unsigned j{}; j < cols_; ++j) matrix_[i][j] -= other.matrix_[i][j];
}

void Matrix::MulNumber(const double num) {
  for (unsigned i{}; i < rows_; ++i)
    for (unsigned j{}; j < cols_; ++j) matrix_[i][j] *= num;
}

void Matrix::MulMatrix(const Matrix& other) {
  if (cols_ != other.rows_)
    throw std::invalid_argument(
        "Number of columns in first matrix are not equal to number of rows in "
        "second matrix");

  Matrix result(rows_, other.cols_);
  for (unsigned i{}; i < rows_; ++i)
    for (unsigned j{}; j < other.cols_; ++j)
      for (unsigned k{}; k < other.rows_; ++k)
        result.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
  *this = result;
}

Matrix Matrix::Transpose() {
  Matrix result(cols_, rows_);
  for (unsigned i{}; i < rows_; ++i)
    for (unsigned j{}; j < cols_; ++j) result.matrix_[j][i] = matrix_[i][j];
  return result;
}

Matrix Matrix::CalcComplements() {
  if (rows_ != cols_ || rows_ < 2)
    throw std::invalid_argument("Matrix is not square");

  Matrix result(rows_, cols_), tmp(rows_ - 1, cols_ - 1);
  for (unsigned i{}; i < rows_; ++i) {
    for (unsigned j{}; j < rows_; ++j) {
      tmp.GetMinorMatrix(this, i, j);
      result.matrix_[i][j] = pow(-1, i + j) * tmp.Determinant();
    }
  }
  return result;
}

double Matrix::Determinant() {
  if (rows_ != cols_) throw std::invalid_argument("Matrix is not square");

  double result = 0.0;
  if (rows_ == 1) {
    result = matrix_[0][0];
  } else if (rows_ == 2) {
    result = matrix_[0][0] * matrix_[1][1] - matrix_[1][0] * matrix_[0][1];
  } else {
    int sign = 1;
    Matrix tmp(rows_ - 1, cols_ - 1);
    for (unsigned i{}; i < rows_; ++i) {
      tmp.GetMinorMatrix(this, i, 0);
      result += sign * matrix_[i][0] * tmp.Determinant();
      sign *= -1;
    }
  }
  return result;
}

Matrix Matrix::InverseMatrix() {
  double determ = Determinant();
  if (fabs(determ) < kEPS) throw std::invalid_argument("Determinant is zero");

  Matrix tmp = CalcComplements();
  Matrix result = tmp.Transpose();
  result.MulNumber(1.0 / determ);

  return result;
}

Matrix Matrix::operator+(const Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_)
    throw std::invalid_argument("Sizes of both Matrixes are not equal");

  Matrix result(*this);
  result.SumMatrix(other);
  return result;
}

Matrix Matrix::operator-(const Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_)
    throw std::invalid_argument("Sizes of both Matrixes are not equal");

  Matrix result(*this);
  result.SubMatrix(other);
  return result;
}

Matrix Matrix::operator*(const Matrix& other) {
  Matrix result(*this);
  result.MulMatrix(other);
  return result;
}

Matrix Matrix::operator*(const double num) {
  Matrix result(*this);
  result.MulNumber(num);
  return result;
}

Matrix operator*(const double value, const Matrix& other) {
  Matrix result(other);
  result.MulNumber(value);
  return result;
}

bool Matrix::operator==(const Matrix& other) { return EqMatrix(other); }

Matrix& Matrix::operator=(const Matrix& other) {
  if (this != &other) {
    clear();
    rows_ = other.rows_;
    cols_ = other.cols_;
    MemoryAllocation();
    CopyMatrix(other.matrix_);
  }
  return *this;
}

Matrix& Matrix::operator+=(const Matrix& other) {
  SumMatrix(other);
  return *this;
}

Matrix& Matrix::operator-=(const Matrix& other) {
  SubMatrix(other);
  return *this;
}

Matrix& Matrix::operator*=(const Matrix& other) {
  MulMatrix(other);
  return *this;
}

Matrix& Matrix::operator*=(const double num) {
  MulNumber(num);
  return *this;
}

double& Matrix::operator()(unsigned i, unsigned j) const {
  if (i >= rows_ || j >= cols_) throw std::out_of_range("out_of_range");
  return matrix_[i][j];
}

void Matrix::MemoryAllocation() {
  matrix_ = new double*[rows_];
  matrix_[0] = new double[rows_ * cols_];
  for (unsigned i{0}; i < rows_; ++i) matrix_[i] = new double[cols_]{};
}

void Matrix::CopyMatrix(double** matrix) {
  for (unsigned i{}; i < rows_; ++i)
    for (unsigned j{}; j < cols_; ++j) matrix_[i][j] = matrix[i][j];
}

unsigned Matrix::GetRows() const { return rows_; }

unsigned Matrix::GetCols() const { return cols_; }

void Matrix::SetRows(unsigned num) {
  Matrix result(num, cols_);
  for (unsigned i{}; i < num && i < rows_; ++i)
    for (unsigned j{}; j < cols_; ++j) result.matrix_[i][j] = matrix_[i][j];
  *this = result;
}

void Matrix::SetCols(unsigned num) {
  Matrix result(rows_, num);
  for (unsigned i{}; i < rows_; ++i)
    for (unsigned j{}; j < num && j < cols_; ++j)
      result.matrix_[i][j] = matrix_[i][j];
  *this = result;
}

void Matrix::GetMinorMatrix(const Matrix* other, unsigned cut_row,
                            unsigned cut_col) {
  unsigned row_tmp{};
  for (unsigned i{}; i < rows_; ++i) {
    unsigned col_tmp{};
    col_tmp = 0;
    if (i == cut_row) row_tmp = 1;
    for (unsigned j{}; j < rows_; ++j) {
      if (j == cut_col) col_tmp = 1;
      matrix_[i][j] = other->matrix_[i + row_tmp][j + col_tmp];
    }
  }
}
