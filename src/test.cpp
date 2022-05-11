#include <gtest/gtest.h>

#include "s21_matrix_oop.hpp"

TEST(test_move_constructor, test_move_constructor_1) {
  // arrange
  S21Matrix expected(1, 2);
  expected(0, 0) = 1;
  expected(0, 1) = 2;

  S21Matrix matrixA(1, 2);
  matrixA(0, 0) = 1;
  matrixA(0, 1) = 2;

  // act
  S21Matrix matrixB(std::move(matrixA));

  // assert
  ASSERT_EQ(matrixB.getCols(), expected.getCols());

  for (int i = 0; i < matrixB.getRows(); i++) {
    for (int j = 0; j < matrixB.getCols(); j++) {
      ASSERT_NEAR(expected(i, j), matrixB(i, j), 1e-7);
    }
  }
}

TEST(test_sum, test_sum_1) {
  // arrange
  S21Matrix expected(2, 2);
  expected(0, 0) = 2;
  expected(0, 1) = 4;
  expected(1, 0) = 6;
  expected(1, 1) = 8;

  S21Matrix matrixA(2, 2);
  matrixA(0, 0) = 1;
  matrixA(0, 1) = 2;
  matrixA(1, 0) = 3;
  matrixA(1, 1) = 4;
  S21Matrix matrixB(matrixA);

  // act
  matrixA.sum_matrix(matrixB);

  // assert
  ASSERT_EQ(matrixA.getCols(), expected.getCols());

  for (int i = 0; i < matrixA.getRows(); i++) {
    for (int j = 0; j < matrixA.getCols(); j++) {
      ASSERT_NEAR(expected(i, j), matrixA(i, j), 1e-7);
    }
  }
}

TEST(test_sum, test_sum_2) {
  // arrange
  S21Matrix expected(2, 2);
  expected(0, 0) = 2.1;
  expected(0, 1) = 4;
  expected(1, 0) = 6;
  expected(1, 1) = 8;

  S21Matrix matrixA(2, 2);
  matrixA(0, 0) = 1.1;
  matrixA(0, 1) = 2;
  matrixA(1, 0) = 3;
  matrixA(1, 1) = 4;
  S21Matrix matrixB(2, 2);
  matrixB(0, 0) = 1;
  matrixB(0, 1) = 2;
  matrixB(1, 0) = 3;
  matrixB(1, 1) = 4;

  // act
  matrixA.sum_matrix(matrixB);

  // assert
  ASSERT_EQ(matrixA.getCols(), expected.getCols());

  for (int i = 0; i < matrixA.getRows(); i++) {
    for (int j = 0; j < matrixA.getCols(); j++) {
      ASSERT_NEAR(expected(i, j), matrixA(i, j), 1e-7);
    }
  }
}

TEST(test_sum, test_sum_3) {
  // arrange
  S21Matrix matrixA(2, 1);
  matrixA(0, 0) = 1.1;
  matrixA(0, 1) = 3;
  S21Matrix matrixB(3, 2);
  matrixB(0, 0) = 1;
  matrixB(0, 1) = 2;
  matrixB(1, 0) = 3;
  matrixB(1, 1) = 4;
  matrixB(2, 0) = 4;
  matrixB(2, 1) = 4;

  // act and assert
  ASSERT_THROW(matrixA.sum_matrix(matrixB), std::invalid_argument);
}

TEST(test_sum, test_sum_4) {
  // arrange
  S21Matrix expected(3, 2);
  expected(0, 0) = 2.1;
  expected(0, 1) = 4;
  expected(1, 0) = 6;
  expected(1, 1) = 8;
  expected(2, 0) = 8;
  expected(2, 1) = 8;

  S21Matrix matrixA(3, 2);
  matrixA(0, 0) = 1.1;
  matrixA(0, 1) = 2;
  matrixA(1, 0) = 3;
  matrixA(1, 1) = 4;
  matrixA(2, 0) = 4;
  matrixA(2, 1) = 4;
  S21Matrix matrixB(3, 2);
  matrixB(0, 0) = 1;
  matrixB(0, 1) = 2;
  matrixB(1, 0) = 3;
  matrixB(1, 1) = 4;
  matrixB(2, 0) = 4;
  matrixB(2, 1) = 4;

  // act
  matrixA.sum_matrix(matrixB);

  // assert
  ASSERT_EQ(matrixA.getCols(), expected.getCols());

  for (int i = 0; i < matrixA.getRows(); i++) {
    for (int j = 0; j < matrixA.getCols(); j++) {
      ASSERT_NEAR(expected(i, j), matrixA(i, j), 1e-7);
    }
  }
}

TEST(test_sub, test_sub_1) {
  // arrange
  S21Matrix expected(2, 2);
  expected(0, 0) = 0;
  expected(0, 1) = 0;
  expected(1, 0) = 0;
  expected(1, 1) = 0;

  S21Matrix matrixA(2, 2);
  matrixA(0, 0) = 1;
  matrixA(0, 1) = 2;
  matrixA(1, 0) = 3;
  matrixA(1, 1) = 4;
  S21Matrix matrixB(matrixA);

  // act
  matrixA.sub_matrix(matrixB);

  // assert
  ASSERT_EQ(matrixA.getCols(), expected.getCols());

  for (int i = 0; i < matrixA.getRows(); i++) {
    for (int j = 0; j < matrixA.getCols(); j++) {
      ASSERT_NEAR(expected(i, j), matrixA(i, j), 1e-7);
    }
  }
}

TEST(test_sub, test_sub_2) {
  // arrange
  S21Matrix expected(2, 2);
  expected(0, 0) = 0.1;
  expected(0, 1) = 0;
  expected(1, 0) = 0;
  expected(1, 1) = 0;

  S21Matrix matrixA(2, 2);
  matrixA(0, 0) = 1.1;
  matrixA(0, 1) = 2;
  matrixA(1, 0) = 3;
  matrixA(1, 1) = 4;
  S21Matrix matrixB(2, 2);
  matrixB(0, 0) = 1;
  matrixB(0, 1) = 2;
  matrixB(1, 0) = 3;
  matrixB(1, 1) = 4;

  // act
  matrixA.sub_matrix(matrixB);

  // assert
  ASSERT_EQ(matrixA.getCols(), expected.getCols());

  for (int i = 0; i < matrixA.getRows(); i++) {
    for (int j = 0; j < matrixA.getCols(); j++) {
      ASSERT_NEAR(expected(i, j), matrixA(i, j), 1e-7);
    }
  }
}

TEST(test_sub, test_sub_3) {
  // arrange
  S21Matrix matrixA(2, 1);
  matrixA(0, 0) = 1.1;
  matrixA(0, 1) = 3;
  S21Matrix matrixB(3, 2);
  matrixB(0, 0) = 1;
  matrixB(0, 1) = 2;
  matrixB(1, 0) = 3;
  matrixB(1, 1) = 4;
  matrixB(2, 0) = 4;
  matrixB(2, 1) = 4;

  // act and assert
  ASSERT_THROW(matrixA.sub_matrix(matrixB), std::invalid_argument);
}

TEST(test_sub, test_sub_4) {
  // arrange
  S21Matrix expected(3, 2);
  expected(0, 0) = 1;
  expected(0, 1) = 0;
  expected(1, 0) = 0;
  expected(1, 1) = 0;
  expected(2, 0) = 2;
  expected(2, 1) = 1;

  S21Matrix matrixA(3, 2);
  matrixA(0, 0) = 1;
  matrixA(0, 1) = 2;
  matrixA(1, 0) = 3;
  matrixA(1, 1) = 4;
  matrixA(2, 0) = 4;
  matrixA(2, 1) = 4;

  S21Matrix matrixB(3, 2);
  matrixB(0, 0) = 0;
  matrixB(0, 1) = 2;
  matrixB(1, 0) = 3;
  matrixB(1, 1) = 4;
  matrixB(2, 0) = 2;
  matrixB(2, 1) = 3;

  // act
  matrixA.sub_matrix(matrixB);

  // assert
  ASSERT_EQ(matrixA.getCols(), expected.getCols());

  for (int i = 0; i < matrixA.getRows(); i++) {
    for (int j = 0; j < matrixA.getCols(); j++) {
      ASSERT_NEAR(expected(i, j), matrixA(i, j), 1e-7);
    }
  }
}

TEST(test_mul_num, test_mul_num_1) {
  // arrange
  S21Matrix expected(3, 2);
  expected(0, 0) = 4;
  expected(0, 1) = 8;
  expected(1, 0) = 12;
  expected(1, 1) = 16;
  expected(2, 0) = 16;
  expected(2, 1) = 16;

  S21Matrix matrixA(3, 2);
  matrixA(0, 0) = 1;
  matrixA(0, 1) = 2;
  matrixA(1, 0) = 3;
  matrixA(1, 1) = 4;
  matrixA(2, 0) = 4;
  matrixA(2, 1) = 4;

  double val = 4;

  // act
  matrixA.mul_number(val);

  // assert
  ASSERT_EQ(matrixA.getCols(), expected.getCols());

  for (int i = 0; i < matrixA.getRows(); i++) {
    for (int j = 0; j < matrixA.getCols(); j++) {
      ASSERT_NEAR(expected(i, j), matrixA(i, j), 1e-7);
    }
  }
}

TEST(test_mul_num, test_mul_num_2) {
  // arrange
  S21Matrix expected(3, 2);
  expected(0, 0) = -1;
  expected(0, 1) = -2;
  expected(1, 0) = -3;
  expected(1, 1) = -4;
  expected(2, 0) = -4;
  expected(2, 1) = -4;

  S21Matrix matrixA(3, 2);
  matrixA(0, 0) = 1;
  matrixA(0, 1) = 2;
  matrixA(1, 0) = 3;
  matrixA(1, 1) = 4;
  matrixA(2, 0) = 4;
  matrixA(2, 1) = 4;

  double val = -1;

  // act
  matrixA.mul_number(val);

  // assert
  ASSERT_EQ(matrixA.getCols(), expected.getCols());

  for (int i = 0; i < matrixA.getRows(); i++) {
    for (int j = 0; j < matrixA.getCols(); j++) {
      ASSERT_NEAR(expected(i, j), matrixA(i, j), 1e-7);
    }
  }
}

TEST(test_eq, test_eq_1) {
  // arrange
  bool expected = true;

  S21Matrix matrixA(3, 2);
  matrixA(0, 0) = 1;
  matrixA(0, 1) = 2;
  matrixA(1, 0) = 3;
  matrixA(1, 1) = 4;
  matrixA(2, 0) = 4;
  matrixA(2, 1) = 4;

  S21Matrix matrixB(3, 2);
  matrixB(0, 0) = 1;
  matrixB(0, 1) = 2;
  matrixB(1, 0) = 3;
  matrixB(1, 1) = 4;
  matrixB(2, 0) = 4;
  matrixB(2, 1) = 4;

  // act
  bool actual = matrixA.eq_matrix(matrixB);

  // assert
  ASSERT_EQ(expected, actual);
}

TEST(test_eq, test_eq_2) {
  // arrange
  bool expected = false;

  S21Matrix matrixA(3, 2);
  matrixA(0, 0) = 1;
  matrixA(0, 1) = 2;
  matrixA(1, 0) = 3;
  matrixA(1, 1) = 4;
  matrixA(2, 0) = 4;
  matrixA(2, 1) = 4;

  S21Matrix matrixB(3, 2);
  matrixB(0, 0) = 1;
  matrixB(0, 1) = 1;
  matrixB(1, 0) = 3;
  matrixB(1, 1) = 4;
  matrixB(2, 0) = 4;
  matrixB(2, 1) = 4;

  // act
  bool actual = matrixA.eq_matrix(matrixB);

  // assert
  ASSERT_EQ(expected, actual);
}

TEST(test_eq, test_eq_3) {
  // arrange
  bool expected = false;

  S21Matrix matrixA(3, 2);

  S21Matrix matrixB(3, 3);

  // act
  bool actual = matrixA.eq_matrix(matrixB);

  // assert
  ASSERT_EQ(expected, actual);
}

TEST(test_mul, test_mul_1) {
  // arrange
  S21Matrix expected(2, 2);
  expected(0, 0) = 7;
  expected(0, 1) = 10;
  expected(1, 0) = 15;
  expected(1, 1) = 22;

  S21Matrix matrixA(2, 2);
  matrixA(0, 0) = 1;
  matrixA(0, 1) = 2;
  matrixA(1, 0) = 3;
  matrixA(1, 1) = 4;
  S21Matrix matrixB(2, 2);
  matrixB(0, 0) = 1;
  matrixB(0, 1) = 2;
  matrixB(1, 0) = 3;
  matrixB(1, 1) = 4;

  // act
  matrixA.mul_matrix(matrixB);

  // assert
  ASSERT_EQ(matrixA.getCols(), expected.getCols());

  for (int i = 0; i < matrixA.getRows(); i++) {
    for (int j = 0; j < matrixA.getCols(); j++) {
      ASSERT_NEAR(expected(i, j), matrixA(i, j), 1e-7);
    }
  }
}

TEST(test_mul, test_mul_2) {
  // arrange
  S21Matrix expected(1, 3);
  expected(0, 0) = 29;
  expected(0, 1) = 42.2;
  expected(0, 2) = 5;

  S21Matrix matrixA(1, 2);
  matrixA(0, 0) = 5;
  matrixA(0, 1) = 1;
  S21Matrix matrixB(2, 3);
  matrixB(0, 0) = 4;
  matrixB(0, 1) = 8;
  matrixB(0, 2) = -2;
  matrixB(1, 0) = 9;
  matrixB(1, 1) = 2.2;
  matrixB(1, 2) = 15;

  // act
  matrixA.mul_matrix(matrixB);

  // assert
  ASSERT_EQ(matrixA.getCols(), expected.getCols());

  for (int i = 0; i < matrixA.getRows(); i++) {
    for (int j = 0; j < matrixA.getCols(); j++) {
      ASSERT_NEAR(expected(i, j), matrixA(i, j), 1e-7);
    }
  }
}

TEST(test_mul, test_mul_3) {
  // arrange
  S21Matrix matrixA(2, 1);
  matrixA(0, 0) = 1.1;
  matrixA(0, 1) = 3;
  S21Matrix matrixB(3, 2);
  matrixB(0, 0) = 1;
  matrixB(0, 1) = 2;
  matrixB(1, 0) = 3;
  matrixB(1, 1) = 4;
  matrixB(2, 0) = 4;
  matrixB(2, 1) = 4;

  // act and assert
  ASSERT_THROW(matrixA.mul_matrix(matrixB), std::invalid_argument);
}

TEST(test_transpose, test_transpose_1) {
  // arrange
  S21Matrix expected(2, 2);
  expected(0, 0) = 1;
  expected(0, 1) = 3;
  expected(1, 0) = 2;
  expected(1, 1) = 4;

  S21Matrix matrixA(2, 2);
  matrixA(0, 0) = 1;
  matrixA(0, 1) = 2;
  matrixA(1, 0) = 3;
  matrixA(1, 1) = 4;

  // act
  S21Matrix actual = matrixA.transpose();

  // assert
  ASSERT_EQ(actual.getCols(), expected.getCols());

  for (int i = 0; i < actual.getRows(); i++) {
    for (int j = 0; j < actual.getCols(); j++) {
      ASSERT_NEAR(expected(i, j), actual(i, j), 1e-7);
    }
  }
}

TEST(test_determinant, test_determinant_1) {
  // arrange
  double expected = -2;

  S21Matrix matrixA(2, 2);
  matrixA(0, 0) = 1;
  matrixA(0, 1) = 2;
  matrixA(1, 0) = 3;
  matrixA(1, 1) = 4;

  // act
  double actual = matrixA.determinant();

  // assert
  ASSERT_EQ(actual, expected);
}

TEST(test_determinant, test_determinant_2) {
  // arrange
  double expected = 0;

  S21Matrix matrixA(4, 4);
  matrixA(0, 0) = 1;
  matrixA(0, 1) = 2;
  matrixA(0, 2) = 3;
  matrixA(0, 3) = 4;

  matrixA(1, 0) = 1;
  matrixA(1, 1) = 2;
  matrixA(1, 2) = 3;
  matrixA(1, 3) = 4;

  matrixA(2, 0) = 1;
  matrixA(2, 1) = 2;
  matrixA(2, 2) = 3;
  matrixA(2, 3) = 4;

  matrixA(3, 0) = 1;
  matrixA(3, 1) = 2;
  matrixA(3, 2) = 3;
  matrixA(3, 3) = 4;

  // act
  double actual = matrixA.determinant();

  // assert
  ASSERT_EQ(actual, expected);
}

TEST(test_determinant, test_determinant_3) {
  // arrange
  double expected = 1;

  S21Matrix matrixA(1, 1);
  matrixA(0, 0) = 1;

  // act
  double actual = matrixA.determinant();

  // assert
  ASSERT_EQ(actual, expected);
}

TEST(test_determinant, test_determinant_4) {
  // arrange
  S21Matrix matrixA(1, 3);
  matrixA(0, 0) = 1;
  matrixA(0, 1) = 1;
  matrixA(0, 2) = 1;

  // act and assert
  ASSERT_THROW(matrixA.determinant(), std::invalid_argument);
}

TEST(test_calc_complements, test_calc_complements_1) {
  // arrange
  S21Matrix expected;
  expected(0, 0) = 0;
  expected(0, 1) = 10;
  expected(0, 2) = -20;

  expected(1, 0) = 4;
  expected(1, 1) = -14;
  expected(1, 2) = 8;

  expected(2, 0) = -8;
  expected(2, 1) = -2;
  expected(2, 2) = 4;

  S21Matrix matrixA(3, 3);
  matrixA(0, 0) = 1;
  matrixA(0, 1) = 2;
  matrixA(0, 2) = 3;

  matrixA(1, 0) = 0;
  matrixA(1, 1) = 4;
  matrixA(1, 2) = 2;

  matrixA(2, 0) = 5;
  matrixA(2, 1) = 2;
  matrixA(2, 2) = 1;

  // act
  S21Matrix actual = matrixA.calc_complements();

  // assert
  ASSERT_EQ(actual.getCols(), expected.getCols());

  for (int i = 0; i < actual.getRows(); i++) {
    for (int j = 0; j < actual.getCols(); j++) {
      ASSERT_NEAR(expected(i, j), actual(i, j), 1e-7);
    }
  }
}

TEST(test_calc_complements, test_calc_complements_2) {
  // arrange
  S21Matrix matrixA(3, 2);
  matrixA(0, 0) = 1;
  matrixA(0, 1) = 2;

  matrixA(1, 0) = 0;
  matrixA(1, 1) = 4;

  matrixA(2, 0) = 5;
  matrixA(2, 1) = 2;

  // act and assert
  ASSERT_THROW(matrixA.calc_complements(), std::invalid_argument);
}

TEST(test_inverse_matrix, test_inverse_matrix_1) {
  // arrange
  S21Matrix expected(3, 3);
  expected(0, 0) = 1;
  expected(0, 1) = -1;
  expected(0, 2) = 1;

  expected(1, 0) = -38;
  expected(1, 1) = 41;
  expected(1, 2) = -34;

  expected(2, 0) = 27;
  expected(2, 1) = -29;
  expected(2, 2) = 24;

  S21Matrix matrixA(3, 3);
  matrixA(0, 0) = 2;
  matrixA(0, 1) = 5;
  matrixA(0, 2) = 7;

  matrixA(1, 0) = 6;
  matrixA(1, 1) = 3;
  matrixA(1, 2) = 4;

  matrixA(2, 0) = 5;
  matrixA(2, 1) = -2;
  matrixA(2, 2) = -3;

  // act
  S21Matrix actual = matrixA.inverse_matrix();

  // assert
  ASSERT_EQ(actual.getCols(), expected.getCols());

  for (int i = 0; i < actual.getRows(); i++) {
    for (int j = 0; j < actual.getCols(); j++) {
      ASSERT_NEAR(expected(i, j), actual(i, j), 1e-7);
    }
  }
}

TEST(test_inverse_matrix, test_inverse_matrix_2) {
  // arrange
  S21Matrix matrixA(3, 3);
  matrixA(0, 0) = 1;
  matrixA(0, 1) = 2;
  matrixA(0, 2) = 3;

  matrixA(1, 0) = 1;
  matrixA(1, 1) = 2;
  matrixA(1, 2) = 3;

  matrixA(2, 0) = 1;
  matrixA(2, 1) = 2;
  matrixA(2, 2) = 3;

  // act and assert
  ASSERT_THROW(matrixA.inverse_matrix(), std::invalid_argument);
}

TEST(test_operators, test_mul_operator_1) {
  // arrange
  S21Matrix expected(2, 2);
  expected(0, 0) = 34;
  expected(0, 1) = 25;

  expected(1, 0) = 30;
  expected(1, 1) = 39;

  S21Matrix matrixA(2, 2);
  matrixA(0, 0) = 2;
  matrixA(0, 1) = 5;

  matrixA(1, 0) = 6;
  matrixA(1, 1) = 3;

  S21Matrix matrixB(matrixA);

  // act
  S21Matrix actual = matrixA * matrixB;

  // assert
  ASSERT_EQ(actual.getCols(), expected.getCols());

  for (int i = 0; i < actual.getRows(); i++) {
    for (int j = 0; j < actual.getCols(); j++) {
      ASSERT_NEAR(expected(i, j), actual(i, j), 1e-7);
    }
  }
}

TEST(test_operators, test_mul_operator_2) {
  // arrange
  S21Matrix expected(2, 2);
  expected(0, 0) = 4;
  expected(0, 1) = 10;

  expected(1, 0) = 12;
  expected(1, 1) = 6;

  S21Matrix matrixA(2, 2);
  matrixA(0, 0) = 2;
  matrixA(0, 1) = 5;

  matrixA(1, 0) = 6;
  matrixA(1, 1) = 3;

  double val = 2;

  // act
  S21Matrix actual = matrixA * val;

  // assert
  ASSERT_EQ(actual.getCols(), expected.getCols());

  for (int i = 0; i < actual.getRows(); i++) {
    for (int j = 0; j < actual.getCols(); j++) {
      ASSERT_NEAR(expected(i, j), actual(i, j), 1e-7);
    }
  }
}

TEST(test_operators, test_mul_operator_4) {
  // arrange
  S21Matrix matrixA(2, 2);
  matrixA(0, 0) = 2;
  matrixA(0, 1) = 5;

  matrixA(1, 0) = 6;
  matrixA(1, 1) = 3;

  S21Matrix matrixB(1, 1);
  matrixB(0, 0) = 2;

  // act and assert
  ASSERT_THROW(matrixA * matrixB, std::invalid_argument);
}

TEST(test_operators, test_sum_operator_1) {
  // arrange
  S21Matrix expected(2, 2);
  expected(0, 0) = 4;
  expected(0, 1) = 10;

  expected(1, 0) = 12;
  expected(1, 1) = 6;

  S21Matrix matrixA(2, 2);
  matrixA(0, 0) = 2;
  matrixA(0, 1) = 5;

  matrixA(1, 0) = 6;
  matrixA(1, 1) = 3;

  S21Matrix matrixB(matrixA);

  // act
  S21Matrix actual = matrixA + matrixB;

  // assert
  ASSERT_EQ(actual.getCols(), expected.getCols());

  for (int i = 0; i < actual.getRows(); i++) {
    for (int j = 0; j < actual.getCols(); j++) {
      ASSERT_NEAR(expected(i, j), actual(i, j), 1e-7);
    }
  }
}

TEST(test_operators, test_sum_operator_2) {
  // arrange
  S21Matrix matrixA(2, 2);
  matrixA(0, 0) = 2;
  matrixA(0, 1) = 5;

  matrixA(1, 0) = 6;
  matrixA(1, 1) = 3;

  S21Matrix matrixB(1, 2);
  matrixB(0, 0) = 2;
  matrixB(0, 1) = 5;

  // act and assert
  ASSERT_THROW(matrixA + matrixB, std::invalid_argument);
}

TEST(test_operators, test_sub_operator_1) {
  // arrange
  S21Matrix expected(2, 2);
  expected(0, 0) = 0;
  expected(0, 1) = 0;

  expected(1, 0) = 0;
  expected(1, 1) = 0;

  S21Matrix matrixA(2, 2);
  matrixA(0, 0) = 2;
  matrixA(0, 1) = 5;

  matrixA(1, 0) = 6;
  matrixA(1, 1) = 3;

  S21Matrix matrixB(matrixA);

  // act
  S21Matrix actual = matrixA - matrixB;

  // assert
  ASSERT_EQ(actual.getCols(), expected.getCols());

  for (int i = 0; i < actual.getRows(); i++) {
    for (int j = 0; j < actual.getCols(); j++) {
      ASSERT_NEAR(expected(i, j), actual(i, j), 1e-7);
    }
  }
}

TEST(test_operators, test_sub_operator_2) {
  // arrange
  S21Matrix matrixA(2, 2);
  matrixA(0, 0) = 2;
  matrixA(0, 1) = 5;

  matrixA(1, 0) = 6;
  matrixA(1, 1) = 3;

  S21Matrix matrixB(1, 2);
  matrixB(0, 0) = 2;
  matrixB(0, 1) = 5;

  // act and assert
  ASSERT_THROW(matrixA - matrixB, std::invalid_argument);
}

TEST(test_operators, test_eq_1) {
  // arrange
  bool expected = true;

  S21Matrix matrixA(3, 2);
  matrixA(0, 0) = 1;
  matrixA(0, 1) = 2;
  matrixA(1, 0) = 3;
  matrixA(1, 1) = 4;
  matrixA(2, 0) = 4;
  matrixA(2, 1) = 4;

  S21Matrix matrixB(3, 2);
  matrixB(0, 0) = 1;
  matrixB(0, 1) = 2;
  matrixB(1, 0) = 3;
  matrixB(1, 1) = 4;
  matrixB(2, 0) = 4;
  matrixB(2, 1) = 4;

  // act
  bool actual = matrixA == matrixB;

  // assert
  ASSERT_EQ(expected, actual);
}

TEST(test_operators, test_assignment_1) {
  // arrange
  S21Matrix expected(3, 2);
  expected(0, 0) = 1;
  expected(0, 1) = 2;
  expected(1, 0) = 3;
  expected(1, 1) = 4;
  expected(2, 0) = 4;
  expected(2, 1) = 4;

  S21Matrix matrixA(3, 2);
  matrixA(0, 0) = 1;
  matrixA(0, 1) = 2;
  matrixA(1, 0) = 3;
  matrixA(1, 1) = 4;
  matrixA(2, 0) = 4;
  matrixA(2, 1) = 4;

  // act
  S21Matrix actual = matrixA;

  // assert
  ASSERT_EQ(actual.getCols(), expected.getCols());

  for (int i = 0; i < actual.getRows(); i++) {
    for (int j = 0; j < actual.getCols(); j++) {
      ASSERT_NEAR(expected(i, j), actual(i, j), 1e-7);
    }
  }
}

TEST(test_operators, test_addition_assignment_1) {
  // arrange
  S21Matrix expected(3, 2);
  expected(0, 0) = 2;
  expected(0, 1) = 4;
  expected(1, 0) = 6;
  expected(1, 1) = 8;
  expected(2, 0) = 8;
  expected(2, 1) = 8;

  S21Matrix actual(3, 2);
  actual(0, 0) = 1;
  actual(0, 1) = 2;
  actual(1, 0) = 3;
  actual(1, 1) = 4;
  actual(2, 0) = 4;
  actual(2, 1) = 4;

  // act
  actual += actual;

  // assert
  ASSERT_EQ(actual.getCols(), expected.getCols());

  for (int i = 0; i < actual.getRows(); i++) {
    for (int j = 0; j < actual.getCols(); j++) {
      ASSERT_NEAR(expected(i, j), actual(i, j), 1e-7);
    }
  }
}

TEST(test_operators, test_addition_assignment_2) {
  // arrange
  S21Matrix matrixA(3, 2);
  matrixA(0, 0) = 2;
  matrixA(0, 1) = 4;
  matrixA(1, 0) = 6;
  matrixA(1, 1) = 8;
  matrixA(2, 0) = 8;
  matrixA(2, 1) = 8;

  S21Matrix matrixB(1, 1);
  matrixB(0, 0) = 1;

  // act and assert
  ASSERT_THROW(matrixA += matrixB, std::invalid_argument);
}

TEST(test_operators, test_substraction_assignment_2) {
  // arrange
  S21Matrix matrixA(3, 2);
  matrixA(0, 0) = 2;
  matrixA(0, 1) = 4;
  matrixA(1, 0) = 6;
  matrixA(1, 1) = 8;
  matrixA(2, 0) = 8;
  matrixA(2, 1) = 8;

  S21Matrix matrixB(1, 1);
  matrixB(0, 0) = 1;

  // act and assert
  ASSERT_THROW(matrixA -= matrixB, std::invalid_argument);
}

TEST(test_operators, test_multiplication_assignment_1) {
  // arrange
  S21Matrix expected(2, 2);
  expected(0, 0) = 9;
  expected(0, 1) = 10;
  expected(1, 0) = 20;
  expected(1, 1) = 24;

  S21Matrix actual(2, 2);
  actual(0, 0) = 1;
  actual(0, 1) = 2;
  actual(1, 0) = 4;
  actual(1, 1) = 4;

  // act
  actual *= actual;

  // assert
  ASSERT_EQ(actual.getCols(), expected.getCols());

  for (int i = 0; i < actual.getRows(); i++) {
    for (int j = 0; j < actual.getCols(); j++) {
      ASSERT_NEAR(expected(i, j), actual(i, j), 1e-7);
    }
  }
}

TEST(test_operators, test_multiplication_assignment_2) {
  // arrange
  S21Matrix expected(2, 2);
  expected(0, 0) = 2;
  expected(0, 1) = 4;
  expected(1, 0) = 8;
  expected(1, 1) = 8;

  S21Matrix actual(2, 2);
  actual(0, 0) = 1;
  actual(0, 1) = 2;
  actual(1, 0) = 4;
  actual(1, 1) = 4;

  double val = 2;

  // act
  actual *= val;

  // assert
  ASSERT_EQ(actual.getCols(), expected.getCols());

  for (int i = 0; i < actual.getRows(); i++) {
    for (int j = 0; j < actual.getCols(); j++) {
      ASSERT_NEAR(expected(i, j), actual(i, j), 1e-7);
    }
  }
}

TEST(test_operators, test_multiplication_assignment_3) {
  // arrange
  S21Matrix matrixA(3, 2);
  matrixA(0, 0) = 2;
  matrixA(0, 1) = 4;
  matrixA(1, 0) = 6;
  matrixA(1, 1) = 8;
  matrixA(2, 0) = 8;
  matrixA(2, 1) = 8;

  S21Matrix matrixB(1, 1);
  matrixB(0, 0) = 1;

  // act and assert
  ASSERT_THROW(matrixA *= matrixB, std::invalid_argument);
}

TEST(test_operators, test_parathesis_1) {
  // arrange
  double expected = 2;

  S21Matrix matrixA(2, 2);
  matrixA(0, 0) = 1;
  matrixA(0, 1) = 2;
  matrixA(1, 0) = 4;
  matrixA(1, 1) = 4;

  // act
  double actual = matrixA(0, 1);

  // assert
  ASSERT_EQ(actual, expected);
}

TEST(test_operators, test_parathesis_2) {
  // arrange
  double expected = 5;

  S21Matrix matrixA(2, 2);
  matrixA(0, 0) = 1;
  matrixA(0, 1) = 2;
  matrixA(1, 0) = 4;
  matrixA(1, 1) = 4;

  // act
  matrixA(0, 1) = 5;
  double actual = matrixA(0, 1);

  // assert
  ASSERT_EQ(actual, expected);
}

TEST(test_operators, test_parathesis_3) {
  // arrange
  S21Matrix matrixA(2, 2);
  matrixA(0, 0) = 1;
  matrixA(0, 1) = 2;
  matrixA(1, 0) = 4;
  matrixA(1, 1) = 4;

  // act and assert
  ASSERT_THROW(matrixA(0, 5) = 2, std::out_of_range);
}

TEST(test_operators, test_parathesis_4) {
  // arrange
  S21Matrix matrixA(2, 2);
  matrixA(0, 0) = 1;
  matrixA(0, 1) = 2;
  matrixA(1, 0) = 4;
  matrixA(1, 1) = 4;

  // act and assert
  ASSERT_THROW(matrixA(0, 5), std::out_of_range);
}

TEST(test_getters, test_getters_1) {
  // arrange
  double expected = 2;

  S21Matrix matrixA(2, 1);
  matrixA(0, 0) = 1;
  matrixA(1, 0) = 4;

  // act
  double actual = matrixA.getRows();

  // assert
  ASSERT_EQ(actual, expected);
}

TEST(test_getters, test_getters_2) {
  // arrange
  double expected = 1;

  S21Matrix matrixA(2, 1);
  matrixA(0, 0) = 1;
  matrixA(1, 0) = 4;

  // act
  double actual = matrixA.getCols();

  // assert
  ASSERT_EQ(actual, expected);
}

TEST(test_setters, test_setters_1) {
  // arrange
  double expected = 3;

  S21Matrix matrixA(2, 1);
  matrixA(0, 0) = 1;
  matrixA(1, 0) = 4;

  // act
  matrixA.setRows(3);
  double actual = matrixA.getRows();
  matrixA.setRows(2);

  // assert
  ASSERT_EQ(actual, expected);
}

TEST(test_setters, test_setters_2) {
  // arrange
  double expected = 3;

  S21Matrix matrixA(2, 1);
  matrixA(0, 0) = 1;
  matrixA(1, 0) = 4;

  // act
  matrixA.setCols(3);
  double actual = matrixA.getCols();
  matrixA.setCols(1);

  // assert
  ASSERT_EQ(actual, expected);
}

TEST(test_constructor, test_constructor_throw) {
  // act
  ASSERT_THROW(S21Matrix matrixA(-1, 2), std::out_of_range);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
