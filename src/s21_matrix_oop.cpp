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
