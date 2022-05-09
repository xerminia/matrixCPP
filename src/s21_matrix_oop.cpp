#include "s21_matrix_oop.hpp"

// Базовый конструктор
S21Matrix::S21Matrix() {
  _rows = 0;
  _cols = 0;
  _matrix = nullptr;
}

// Параметризованный конструктор
S21Matrix::S21Matrix(int rows, int cols) {
  if (rows < 1 || cols < 1) {
    throw std::out_of_range("Incorrect input");
  }
  _rows = rows;
  _cols = cols;
  init_matrix();
}

// Конструктор копирования
S21Matrix::S21Matrix(const S21Matrix& other) { this->copy_matrix(other); }

// Конструктор перемещения
S21Matrix::S21Matrix(S21Matrix&& other) {
  std::swap(_rows, other._rows);
  std::swap(_cols, other._cols);
  std::swap(_matrix, other._matrix);
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
