#include "s21_matrix_oop.hpp"

// Базовый конструктор
S21Matrix::S21Matrix() {
  _rows = 3;
  _cols = 3;
  init_matrix(_rows, _cols);
}

// Параметризованный конструктор
S21Matrix::S21Matrix(int rows, int cols) {
  if (rows < 1 || cols < 1) {
    throw std::out_of_range("Number of rows or columns is less than zero");
  }
  init_matrix(rows, cols);
}

// Конструктор копирования
S21Matrix::S21Matrix(const S21Matrix& other)
    : S21Matrix(other._rows, other._cols) {
  copy_matrix(other._matrix);
}

// Конструктор перемещения
S21Matrix::S21Matrix(S21Matrix&& other)
    : _rows(other._rows), _cols(other._cols), _matrix(other._matrix) {
  other._matrix = nullptr;
  other._rows = 0;
  other._cols = 0;
}

// Деструктор
S21Matrix::~S21Matrix() {
  if (_matrix != nullptr) {
    for (int i = 0; i < _rows; i++) {
      delete[] _matrix[i];
    }
    delete[] _matrix;
  }
}

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

void S21Matrix::init_matrix(int rows, int cols) {
  _rows = rows;
  _cols = cols;
  _matrix = new double*[_rows]();
  for (int i = 0; i < _rows; i++) {
    _matrix[i] = new double[_cols]();
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

void S21Matrix::get_minor_matrix(const S21Matrix* other, int cut_row,
                                 int cut_col) {
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
