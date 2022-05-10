#include "s21_matrix_oop.hpp"

// Базовый конструктор
S21Matrix::S21Matrix() {
  _rows = 3;
  _cols = 3;
  this->init_matrix();
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
S21Matrix::S21Matrix(S21Matrix&& other)
    : _rows(other._rows), _cols(other._cols), _matrix(other._matrix) {
  other._rows = 0;
  other._cols = 0;
  other._matrix = nullptr;
}

// Деструктор
S21Matrix::~S21Matrix() {
  if (_matrix) {
    for (int i = 0; i < _rows; i++) {
      delete[] _matrix[i];
    }
    delete[] _matrix;
  }
}
