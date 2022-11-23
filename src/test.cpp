#include <gtest/gtest.h>

#include "matrix.h"

TEST(test_move_constructor, test_move_constructor1) {
  Matrix expected(1, 2);
  expected(0, 0) = 5;
  expected(0, 1) = 7;

  Matrix matrixA(1, 2);
  matrixA(0, 0) = 5;
  matrixA(0, 1) = 7;

  Matrix matrixB(std::move(matrixA));

  ASSERT_EQ(matrixB.GetCols(), expected.GetCols());

  for (unsigned i{}; i < matrixB.GetRows(); i++) {
    for (unsigned j{}; j < matrixB.GetCols(); j++) {
      ASSERT_NEAR(expected(i, j), matrixB(i, j), kEPS);
    }
  }
}

TEST(test_sum, test_sum1) {
  Matrix expected(2, 2);
  expected(0, 0) = 10.2;
  expected(0, 1) = 20.4;
  expected(1, 0) = 30.6;
  expected(1, 1) = 40.8;

  Matrix matrixA(2, 2);
  matrixA(0, 0) = 5.1;
  matrixA(0, 1) = 10.2;
  matrixA(1, 0) = 15.3;
  matrixA(1, 1) = 20.4;

  Matrix matrixB(matrixA);

  matrixA.SumMatrix(matrixB);

  ASSERT_EQ(matrixA.GetCols(), expected.GetCols());

  for (unsigned i{}; i < matrixA.GetRows(); i++) {
    for (unsigned j{}; j < matrixA.GetCols(); j++) {
      ASSERT_NEAR(expected(i, j), matrixA(i, j), kEPS);
    }
  }
}

TEST(test_sum, test_sum2) {
  Matrix expected(2, 2);
  expected(0, 0) = 0;
  expected(0, 1) = 0;
  expected(1, 0) = 0;
  expected(1, 1) = 0;

  Matrix matrixA(2, 2);
  matrixA(0, 0) = -1;
  matrixA(0, 1) = -2;
  matrixA(1, 0) = -3;
  matrixA(1, 1) = -4;

  Matrix matrixB(2, 2);
  matrixB(0, 0) = 1;
  matrixB(0, 1) = 2;
  matrixB(1, 0) = 3;
  matrixB(1, 1) = 4;

  matrixA.SumMatrix(matrixB);

  ASSERT_EQ(matrixA.GetCols(), expected.GetCols());

  for (unsigned i{}; i < matrixA.GetRows(); i++) {
    for (unsigned j{}; j < matrixA.GetCols(); j++) {
      ASSERT_NEAR(expected(i, j), matrixA(i, j), kEPS);
    }
  }
}

TEST(test_sum, test_sum3) {
  Matrix matrixA(2, 1);
  matrixA(0, 0) = 5;
  matrixA(1, 0) = 5;

  Matrix matrixB(3, 2);
  matrixB(0, 0) = 1;
  matrixB(0, 1) = 2;
  matrixB(1, 0) = 3;
  matrixB(1, 1) = 4;
  matrixB(2, 0) = 5;
  matrixB(2, 1) = 6;

  ASSERT_THROW(matrixA.SumMatrix(matrixB), std::invalid_argument);
}

TEST(test_sum, test_sum4) {
  Matrix expected(3, 2);
  expected(0, 0) = 5;
  expected(0, 1) = 5;
  expected(1, 0) = 5;
  expected(1, 1) = 5;
  expected(2, 0) = 5;
  expected(2, 1) = 5;

  Matrix matrixA(3, 2);
  matrixA(0, 0) = 0;
  matrixA(0, 1) = 1;
  matrixA(1, 0) = 2;
  matrixA(1, 1) = 3;
  matrixA(2, 0) = 4;
  matrixA(2, 1) = 5;

  Matrix matrixB(3, 2);
  matrixB(0, 0) = 5;
  matrixB(0, 1) = 4;
  matrixB(1, 0) = 3;
  matrixB(1, 1) = 2;
  matrixB(2, 0) = 1;
  matrixB(2, 1) = 0;

  matrixA.SumMatrix(matrixB);

  ASSERT_EQ(matrixA.GetCols(), expected.GetCols());

  for (unsigned i{}; i < matrixA.GetRows(); i++) {
    for (unsigned j{}; j < matrixA.GetCols(); j++) {
      ASSERT_NEAR(expected(i, j), matrixA(i, j), kEPS);
    }
  }
}

TEST(test_sub, test_sub1) {
  Matrix expected(2, 2);
  expected(0, 0) = 0;
  expected(0, 1) = 0;
  expected(1, 0) = 0;
  expected(1, 1) = 0;

  Matrix matrixA(2, 2);
  matrixA(0, 0) = 10;
  matrixA(0, 1) = 20;
  matrixA(1, 0) = 30;
  matrixA(1, 1) = 40;

  Matrix matrixB(matrixA);
  matrixA.SubMatrix(matrixB);

  ASSERT_EQ(matrixA.GetCols(), expected.GetCols());

  for (unsigned i{}; i < matrixA.GetRows(); i++) {
    for (unsigned j{}; j < matrixA.GetCols(); j++) {
      ASSERT_NEAR(expected(i, j), matrixA(i, j), kEPS);
    }
  }
}

TEST(test_sub, test_sub2) {
  Matrix expected(2, 2);
  expected(0, 0) = 3;
  expected(0, 1) = 1;
  expected(1, 0) = -1;
  expected(1, 1) = -3;

  Matrix matrixA(2, 2);
  matrixA(0, 0) = 5;
  matrixA(0, 1) = 4;
  matrixA(1, 0) = 3;
  matrixA(1, 1) = 2;

  Matrix matrixB(2, 2);
  matrixB(0, 0) = 2;
  matrixB(0, 1) = 3;
  matrixB(1, 0) = 4;
  matrixB(1, 1) = 5;

  matrixA.SubMatrix(matrixB);

  ASSERT_EQ(matrixA.GetCols(), expected.GetCols());

  for (unsigned i{}; i < matrixA.GetRows(); i++) {
    for (unsigned j{}; j < matrixA.GetCols(); j++) {
      ASSERT_NEAR(expected(i, j), matrixA(i, j), kEPS);
    }
  }
}

TEST(test_sub, test_sub3) {
  Matrix matrixA(2, 1);
  matrixA(0, 0) = 1;
  matrixA(1, 0) = 2;

  Matrix matrixB(3, 2);
  matrixB(0, 0) = 3;
  matrixB(0, 1) = 4;
  matrixB(1, 0) = 5;
  matrixB(1, 1) = 6;
  matrixB(2, 0) = 7;
  matrixB(2, 1) = 8;

  ASSERT_THROW(matrixA.SubMatrix(matrixB), std::invalid_argument);
}

TEST(test_sub, test_sub4) {
  Matrix expected(3, 2);
  expected(0, 0) = -9;
  expected(0, 1) = -8;
  expected(1, 0) = -7;
  expected(1, 1) = -26;
  expected(2, 0) = -25;
  expected(2, 1) = -24;

  Matrix matrixA(3, 2);
  matrixA(0, 0) = 1;
  matrixA(0, 1) = 2;
  matrixA(1, 0) = 3;
  matrixA(1, 1) = 4;
  matrixA(2, 0) = 5;
  matrixA(2, 1) = 6;

  Matrix matrixB(3, 2);
  matrixB(0, 0) = 10;
  matrixB(0, 1) = 10;
  matrixB(1, 0) = 10;
  matrixB(1, 1) = 30;
  matrixB(2, 0) = 30;
  matrixB(2, 1) = 30;

  matrixA.SubMatrix(matrixB);

  ASSERT_EQ(matrixA.GetCols(), expected.GetCols());

  for (unsigned i{}; i < matrixA.GetRows(); i++) {
    for (unsigned j{}; j < matrixA.GetCols(); j++) {
      ASSERT_NEAR(expected(i, j), matrixA(i, j), kEPS);
    }
  }
}

TEST(test_mul_num, test_mul_num1) {
  Matrix expected(3, 2);
  expected(0, 0) = 4;
  expected(0, 1) = 8;
  expected(1, 0) = 12;
  expected(1, 1) = 16;
  expected(2, 0) = 20;
  expected(2, 1) = 24;

  Matrix matrixA(3, 2);
  matrixA(0, 0) = 1;
  matrixA(0, 1) = 2;
  matrixA(1, 0) = 3;
  matrixA(1, 1) = 4;
  matrixA(2, 0) = 5;
  matrixA(2, 1) = 6;

  matrixA.MulNumber(4);

  ASSERT_EQ(matrixA.GetCols(), expected.GetCols());

  for (unsigned i{}; i < matrixA.GetRows(); i++) {
    for (unsigned j{}; j < matrixA.GetCols(); j++) {
      ASSERT_NEAR(expected(i, j), matrixA(i, j), kEPS);
    }
  }
}

TEST(test_mul_num, test_mul_num2) {
  Matrix expected(3, 4);
  expected(0, 0) = -1;
  expected(0, 1) = -2;
  expected(0, 2) = -3;
  expected(0, 3) = -4;

  expected(1, 0) = -5;
  expected(1, 1) = -6;
  expected(1, 2) = -7;
  expected(1, 3) = -8;

  expected(2, 0) = -9;
  expected(2, 1) = -10;
  expected(2, 2) = -11;
  expected(2, 3) = -12;

  Matrix matrixA(3, 4);
  matrixA(0, 0) = 1;
  matrixA(0, 1) = 2;
  matrixA(0, 2) = 3;
  matrixA(0, 3) = 4;

  matrixA(1, 0) = 5;
  matrixA(1, 1) = 6;
  matrixA(1, 2) = 7;
  matrixA(1, 3) = 8;

  matrixA(2, 0) = 9;
  matrixA(2, 1) = 10;
  matrixA(2, 2) = 11;
  matrixA(2, 3) = 12;

  matrixA.MulNumber(-1);

  ASSERT_EQ(matrixA.GetCols(), expected.GetCols());

  for (unsigned i{}; i < matrixA.GetRows(); i++) {
    for (unsigned j{}; j < matrixA.GetCols(); j++) {
      ASSERT_NEAR(expected(i, j), matrixA(i, j), kEPS);
    }
  }
}

TEST(test_mul, test_mul1) {
  Matrix expected(2, 2);
  expected(0, 0) = 7;
  expected(0, 1) = 10;
  expected(1, 0) = 15;
  expected(1, 1) = 22;

  Matrix matrixA(2, 2);
  matrixA(0, 0) = 1;
  matrixA(0, 1) = 2;
  matrixA(1, 0) = 3;
  matrixA(1, 1) = 4;

  Matrix matrixB(2, 2);
  matrixB(0, 0) = 1;
  matrixB(0, 1) = 2;
  matrixB(1, 0) = 3;
  matrixB(1, 1) = 4;

  matrixA.MulMatrix(matrixB);

  ASSERT_EQ(matrixA.GetCols(), expected.GetCols());

  for (unsigned i{}; i < matrixA.GetRows(); i++) {
    for (unsigned j{}; j < matrixA.GetCols(); j++) {
      ASSERT_NEAR(expected(i, j), matrixA(i, j), kEPS);
    }
  }
}

TEST(test_mul, test_mul2) {
  Matrix expected(1, 3);
  expected(0, 0) = 29;
  expected(0, 1) = 42.2;
  expected(0, 2) = 5;

  Matrix matrixA(1, 2);
  matrixA(0, 0) = 5;
  matrixA(0, 1) = 1;

  Matrix matrixB(2, 3);
  matrixB(0, 0) = 4;
  matrixB(0, 1) = 8;
  matrixB(0, 2) = -2;
  matrixB(1, 0) = 9;
  matrixB(1, 1) = 2.2;
  matrixB(1, 2) = 15;

  matrixA.MulMatrix(matrixB);

  ASSERT_EQ(matrixA.GetCols(), expected.GetCols());

  for (unsigned i{}; i < matrixA.GetRows(); i++) {
    for (unsigned j{}; j < matrixA.GetCols(); j++) {
      ASSERT_NEAR(expected(i, j), matrixA(i, j), kEPS);
    }
  }
}

TEST(test_mul, test_mul3) {
  Matrix matrixA(2, 1);
  matrixA(0, 0) = 1.1;
  matrixA(1, 0) = 3;

  Matrix matrixB(3, 2);
  matrixB(0, 0) = 1;
  matrixB(0, 1) = 2;
  matrixB(1, 0) = 3;
  matrixB(1, 1) = 4;
  matrixB(2, 0) = 4;
  matrixB(2, 1) = 4;

  ASSERT_THROW(matrixA.MulMatrix(matrixB), std::invalid_argument);
}

TEST(test_eq, test_eq1) {
  bool expected = true;

  Matrix matrixA(3, 2);
  matrixA(0, 0) = 1.1;
  matrixA(0, 1) = 2.2;
  matrixA(1, 0) = 3.3;
  matrixA(1, 1) = 4.4;
  matrixA(2, 0) = 5.5;
  matrixA(2, 1) = 6.6;

  Matrix matrixB(3, 2);
  matrixB(0, 0) = 1.1;
  matrixB(0, 1) = 2.2;
  matrixB(1, 0) = 3.3;
  matrixB(1, 1) = 4.4;
  matrixB(2, 0) = 5.5;
  matrixB(2, 1) = 6.6;

  ASSERT_EQ(expected, matrixA.EqMatrix(matrixB));
}

TEST(test_eq, test_eq2) {
  bool expected = false;

  Matrix matrixA(3, 2);
  matrixA(0, 0) = 0;
  matrixA(0, 1) = 1;
  matrixA(1, 0) = 2;
  matrixA(1, 1) = 3;
  matrixA(2, 0) = 4;
  matrixA(2, 1) = 5;

  Matrix matrixB(3, 2);
  matrixB(0, 0) = 1;
  matrixB(0, 1) = 2;
  matrixB(1, 0) = 3;
  matrixB(1, 1) = 4;
  matrixB(2, 0) = 5;
  matrixB(2, 1) = 6;

  ASSERT_EQ(expected, matrixA.EqMatrix(matrixB));
}

TEST(test_eq, test_eq3) {
  bool expected = false;

  Matrix matrixA(3, 2);
  Matrix matrixB(3, 3);

  ASSERT_EQ(expected, matrixA.EqMatrix(matrixB));
}

TEST(test_Transpose, test_Transpose1) {
  Matrix expected(2, 2);
  expected(0, 0) = 1;
  expected(0, 1) = 3;
  expected(1, 0) = 2;
  expected(1, 1) = 4;

  Matrix matrixA(2, 2);
  matrixA(0, 0) = 1;
  matrixA(0, 1) = 2;
  matrixA(1, 0) = 3;
  matrixA(1, 1) = 4;

  Matrix actual = matrixA.Transpose();

  ASSERT_EQ(actual.GetCols(), expected.GetCols());

  for (unsigned i{}; i < actual.GetRows(); i++) {
    for (unsigned j{}; j < actual.GetCols(); j++) {
      ASSERT_NEAR(expected(i, j), actual(i, j), kEPS);
    }
  }
}

TEST(test_Determinant, test_Determinant1) {
  double expected = -40;

  Matrix matrixA(3, 3);
  matrixA(0, 0) = 1;
  matrixA(0, 1) = 2;
  matrixA(0, 2) = 3;

  matrixA(1, 0) = 0;
  matrixA(1, 1) = 4;
  matrixA(1, 2) = 2;

  matrixA(2, 0) = 5;
  matrixA(2, 1) = 2;
  matrixA(2, 2) = 1;

  ASSERT_EQ(expected, matrixA.Determinant());
}

TEST(test_Determinant, test_Determinant2) {
  double expected = -7900;

  Matrix matrixA(5, 5);
  matrixA(0, 0) = 1;
  matrixA(0, 1) = 2;
  matrixA(0, 2) = 3;
  matrixA(0, 3) = 4;
  matrixA(0, 4) = 3;

  matrixA(1, 0) = 0;
  matrixA(1, 1) = 4;
  matrixA(1, 2) = 2;
  matrixA(1, 3) = 3;
  matrixA(1, 4) = 13;

  matrixA(2, 0) = 5;
  matrixA(2, 1) = 2;
  matrixA(2, 2) = 1;
  matrixA(2, 3) = 3;
  matrixA(2, 4) = 3;

  matrixA(3, 0) = 5;
  matrixA(3, 1) = 12;
  matrixA(3, 2) = 1;
  matrixA(3, 3) = 3;
  matrixA(3, 4) = 3;

  matrixA(4, 0) = 5;
  matrixA(4, 1) = 2;
  matrixA(4, 2) = 1;
  matrixA(4, 3) = 8;
  matrixA(4, 4) = 3;

  ASSERT_EQ(matrixA.Determinant(), expected);
}

TEST(test_Determinant, test_Determinant3) {
  double expected = 1;

  Matrix matrixA(1, 1);
  matrixA(0, 0) = 1;

  ASSERT_EQ(matrixA.Determinant(), expected);
}

TEST(test_Determinant, test_Determinant4) {
  Matrix matrixA(1, 3);
  matrixA(0, 0) = 1;
  matrixA(0, 1) = 1;
  matrixA(0, 2) = 1;

  ASSERT_THROW(matrixA.Determinant(), std::invalid_argument);
}

TEST(test_calc_complements, test_calc_complements1) {
  Matrix expected(3, 3);
  expected(0, 0) = 0;
  expected(0, 1) = 10;
  expected(0, 2) = -20;

  expected(1, 0) = 4;
  expected(1, 1) = -14;
  expected(1, 2) = 8;

  expected(2, 0) = -8;
  expected(2, 1) = -2;
  expected(2, 2) = 4;

  Matrix matrixA(3, 3);
  matrixA(0, 0) = 1;
  matrixA(0, 1) = 2;
  matrixA(0, 2) = 3;

  matrixA(1, 0) = 0;
  matrixA(1, 1) = 4;
  matrixA(1, 2) = 2;

  matrixA(2, 0) = 5;
  matrixA(2, 1) = 2;
  matrixA(2, 2) = 1;

  Matrix actual = matrixA.CalcComplements();

  ASSERT_EQ(actual.GetCols(), expected.GetCols());

  for (unsigned i{}; i < actual.GetRows(); ++i) {
    for (unsigned j{}; j < actual.GetCols(); ++j) {
      ASSERT_NEAR(expected(i, j), actual(i, j), kEPS);
    }
  }
}

TEST(test_calc_complements, test_calc_complements2) {
  Matrix matrixA(3, 2);
  matrixA(0, 0) = 1;
  matrixA(0, 1) = 2;
  matrixA(1, 0) = 0;
  matrixA(1, 1) = 4;
  matrixA(2, 0) = 5;
  matrixA(2, 1) = 2;

  ASSERT_THROW(matrixA.CalcComplements(), std::invalid_argument);
}

TEST(test_inverse_matrix, test_inverse_matrix1) {
  Matrix expected(3, 3);
  expected(0, 0) = 1;
  expected(0, 1) = -1;
  expected(0, 2) = 1;

  expected(1, 0) = -38;
  expected(1, 1) = 41;
  expected(1, 2) = -34;

  expected(2, 0) = 27;
  expected(2, 1) = -29;
  expected(2, 2) = 24;

  Matrix matrixA(3, 3);
  matrixA(0, 0) = 2;
  matrixA(0, 1) = 5;
  matrixA(0, 2) = 7;

  matrixA(1, 0) = 6;
  matrixA(1, 1) = 3;
  matrixA(1, 2) = 4;

  matrixA(2, 0) = 5;
  matrixA(2, 1) = -2;
  matrixA(2, 2) = -3;

  Matrix actual = matrixA.InverseMatrix();

  ASSERT_EQ(actual.GetCols(), expected.GetCols());

  for (unsigned i{}; i < actual.GetRows(); i++) {
    for (unsigned j{}; j < actual.GetCols(); j++) {
      ASSERT_NEAR(expected(i, j), actual(i, j), kEPS);
    }
  }
}

TEST(test_inverse_matrix, test_inverse_matrix2) {
  Matrix matrixA(3, 3);
  matrixA(0, 0) = 1;
  matrixA(0, 1) = 2;
  matrixA(0, 2) = 3;

  matrixA(1, 0) = 1;
  matrixA(1, 1) = 2;
  matrixA(1, 2) = 3;

  matrixA(2, 0) = 1;
  matrixA(2, 1) = 2;
  matrixA(2, 2) = 3;

  ASSERT_THROW(matrixA.InverseMatrix(), std::invalid_argument);
}

TEST(test_operators, test_mul_operator_1) {
  Matrix expected(2, 2);
  expected(0, 0) = 34;
  expected(0, 1) = 25;
  expected(1, 0) = 30;
  expected(1, 1) = 39;

  Matrix matrixA(2, 2);
  matrixA(0, 0) = 2;
  matrixA(0, 1) = 5;
  matrixA(1, 0) = 6;
  matrixA(1, 1) = 3;

  Matrix matrixB(matrixA);
  Matrix actual = matrixA * matrixB;

  ASSERT_EQ(actual.GetCols(), expected.GetCols());

  for (unsigned i{}; i < actual.GetRows(); i++) {
    for (unsigned j{}; j < actual.GetCols(); j++) {
      ASSERT_NEAR(expected(i, j), actual(i, j), kEPS);
    }
  }
}

TEST(test_operators, test_mul_operator2) {
  Matrix expected(2, 2);
  expected(0, 0) = 4;
  expected(0, 1) = 10;
  expected(1, 0) = 12;
  expected(1, 1) = 6;

  Matrix matrixA(2, 2);
  matrixA(0, 0) = 2;
  matrixA(0, 1) = 5;
  matrixA(1, 0) = 6;
  matrixA(1, 1) = 3;

  Matrix actual = matrixA * 2;

  ASSERT_EQ(actual.GetCols(), expected.GetCols());

  for (unsigned i{}; i < actual.GetRows(); i++) {
    for (unsigned j{}; j < actual.GetCols(); j++) {
      ASSERT_NEAR(expected(i, j), actual(i, j), kEPS);
    }
  }
}

TEST(test_operators, test_mul_operator3) {
  Matrix matrixA(2, 2);
  matrixA(0, 0) = 2;
  matrixA(0, 1) = 5;
  matrixA(1, 0) = 6;
  matrixA(1, 1) = 3;

  Matrix matrixB(1, 1);
  matrixB(0, 0) = 2;

  ASSERT_THROW(matrixA * matrixB, std::invalid_argument);
}

TEST(test_operators, test_mul_operator4) {
  Matrix expected(2, 2);
  expected(0, 0) = 4;
  expected(0, 1) = 10;
  expected(1, 0) = 12;
  expected(1, 1) = 6;

  Matrix matrixA(2, 2);
  matrixA(0, 0) = 2;
  matrixA(0, 1) = 5;
  matrixA(1, 0) = 6;
  matrixA(1, 1) = 3;

  Matrix actual = 2 * matrixA;

  ASSERT_EQ(actual.GetCols(), expected.GetCols());

  for (unsigned i{}; i < actual.GetRows(); i++) {
    for (unsigned j{}; j < actual.GetCols(); j++) {
      ASSERT_NEAR(expected(i, j), actual(i, j), kEPS);
    }
  }
}

TEST(test_operators, test_sum_operator1) {
  Matrix expected(2, 2);
  expected(0, 0) = 4;
  expected(0, 1) = 10;
  expected(1, 0) = 4;
  expected(1, 1) = 20;

  Matrix matrixA(2, 2);
  matrixA(0, 0) = 2;
  matrixA(0, 1) = 5;
  matrixA(1, 0) = 2;
  matrixA(1, 1) = 10;

  Matrix matrixB(matrixA);
  Matrix actual = matrixA + matrixB;

  ASSERT_EQ(actual.GetCols(), expected.GetCols());

  for (unsigned i{}; i < actual.GetRows(); i++) {
    for (unsigned j{}; j < actual.GetCols(); j++) {
      ASSERT_NEAR(expected(i, j), actual(i, j), kEPS);
    }
  }
}

TEST(test_operators, test_sum_operator2) {
  Matrix matrixA(2, 2);
  matrixA(0, 0) = 2;
  matrixA(0, 1) = 5;
  matrixA(1, 0) = 6;
  matrixA(1, 1) = 3;

  Matrix matrixB(1, 2);
  matrixB(0, 0) = 2;
  matrixB(0, 1) = 5;

  ASSERT_THROW(matrixA + matrixB, std::invalid_argument);
}

TEST(test_operators, test_sub_operator1) {
  Matrix expected(2, 2);
  expected(0, 0) = 0;
  expected(0, 1) = 0;
  expected(1, 0) = 0;
  expected(1, 1) = 0;

  Matrix matrixA(2, 2);
  matrixA(0, 0) = 20;
  matrixA(0, 1) = 50;
  matrixA(1, 0) = 20;
  matrixA(1, 1) = 60;

  Matrix matrixB(matrixA);
  Matrix actual = matrixA - matrixB;

  ASSERT_EQ(actual.GetCols(), expected.GetCols());

  for (unsigned i{}; i < actual.GetRows(); i++) {
    for (unsigned j{}; j < actual.GetCols(); j++) {
      ASSERT_NEAR(expected(i, j), actual(i, j), kEPS);
    }
  }
}

TEST(test_operators, test_sub_operator2) {
  Matrix matrixA(2, 2);
  matrixA(0, 0) = 2;
  matrixA(0, 1) = 5;
  matrixA(1, 0) = 6;
  matrixA(1, 1) = 3;

  Matrix matrixB(1, 2);
  matrixB(0, 0) = 2;
  matrixB(0, 1) = 5;

  ASSERT_THROW(matrixA - matrixB, std::invalid_argument);
}

TEST(test_operators, test_eq1) {
  bool expected = true;

  Matrix matrixA(3, 2);
  matrixA(0, 0) = 1;
  matrixA(0, 1) = 2;
  matrixA(1, 0) = 3;
  matrixA(1, 1) = 4;
  matrixA(2, 0) = 4;
  matrixA(2, 1) = 4;

  Matrix matrixB(3, 2);
  matrixB(0, 0) = 1;
  matrixB(0, 1) = 2;
  matrixB(1, 0) = 3;
  matrixB(1, 1) = 4;
  matrixB(2, 0) = 4;
  matrixB(2, 1) = 4;

  bool actual = matrixA == matrixB;

  ASSERT_EQ(expected, actual);
}

TEST(test_operators, test_assignment1) {
  Matrix expected(3, 2);
  expected(0, 0) = 1;
  expected(0, 1) = 2;
  expected(1, 0) = 3;
  expected(1, 1) = 4;
  expected(2, 0) = 4;
  expected(2, 1) = 4;

  Matrix matrixA(3, 2);
  matrixA(0, 0) = 1;
  matrixA(0, 1) = 2;
  matrixA(1, 0) = 3;
  matrixA(1, 1) = 4;
  matrixA(2, 0) = 4;
  matrixA(2, 1) = 4;

  Matrix actual = matrixA;

  ASSERT_EQ(actual.GetCols(), expected.GetCols());

  for (unsigned i{}; i < actual.GetRows(); i++) {
    for (unsigned j{}; j < actual.GetCols(); j++) {
      ASSERT_NEAR(expected(i, j), actual(i, j), kEPS);
    }
  }
}

TEST(test_operators, test_addition_assignment1) {
  Matrix expected(3, 2);
  expected(0, 0) = 2;
  expected(0, 1) = 4;
  expected(1, 0) = 6;
  expected(1, 1) = 8;
  expected(2, 0) = 8;
  expected(2, 1) = 8;

  Matrix actual(3, 2);
  actual(0, 0) = 1;
  actual(0, 1) = 2;
  actual(1, 0) = 3;
  actual(1, 1) = 4;
  actual(2, 0) = 4;
  actual(2, 1) = 4;

  actual += actual;

  ASSERT_EQ(actual.GetCols(), expected.GetCols());

  for (unsigned i{}; i < actual.GetRows(); i++) {
    for (unsigned j{}; j < actual.GetCols(); j++) {
      ASSERT_NEAR(expected(i, j), actual(i, j), kEPS);
    }
  }
}

TEST(test_operators, test_addition_assignment2) {
  Matrix matrixA(3, 2);
  matrixA(0, 0) = 2;
  matrixA(0, 1) = 4;
  matrixA(1, 0) = 6;
  matrixA(1, 1) = 8;
  matrixA(2, 0) = 8;
  matrixA(2, 1) = 8;

  Matrix matrixB(1, 1);
  matrixB(0, 0) = 1;

  ASSERT_THROW(matrixA += matrixB, std::invalid_argument);
}

TEST(test_operators, test_substraction_assignment2) {
  Matrix matrixA(3, 2);
  matrixA(0, 0) = 2;
  matrixA(0, 1) = 4;
  matrixA(1, 0) = 6;
  matrixA(1, 1) = 8;
  matrixA(2, 0) = 8;
  matrixA(2, 1) = 8;

  Matrix matrixB(1, 1);
  matrixB(0, 0) = 1;

  ASSERT_THROW(matrixA -= matrixB, std::invalid_argument);
}

TEST(test_operators, test_multiplication_assignment1) {
  Matrix expected(2, 2);
  expected(0, 0) = 9;
  expected(0, 1) = 10;
  expected(1, 0) = 20;
  expected(1, 1) = 24;

  Matrix actual(2, 2);
  actual(0, 0) = 1;
  actual(0, 1) = 2;
  actual(1, 0) = 4;
  actual(1, 1) = 4;

  actual *= actual;

  ASSERT_EQ(actual.GetCols(), expected.GetCols());

  for (unsigned i{}; i < actual.GetRows(); i++) {
    for (unsigned j{}; j < actual.GetCols(); j++) {
      ASSERT_NEAR(expected(i, j), actual(i, j), kEPS);
    }
  }
}

TEST(test_operators, test_multiplication_assignment2) {
  Matrix expected(2, 2);
  expected(0, 0) = 2;
  expected(0, 1) = 4;
  expected(1, 0) = 8;
  expected(1, 1) = 8;

  Matrix actual(2, 2);
  actual(0, 0) = 1;
  actual(0, 1) = 2;
  actual(1, 0) = 4;
  actual(1, 1) = 4;

  actual *= 2;

  ASSERT_EQ(actual.GetCols(), expected.GetCols());

  for (unsigned i{}; i < actual.GetRows(); i++) {
    for (unsigned j{}; j < actual.GetCols(); j++) {
      ASSERT_NEAR(expected(i, j), actual(i, j), kEPS);
    }
  }
}

TEST(test_operators, test_multiplication_assignment3) {
  Matrix matrixA(3, 2);
  matrixA(0, 0) = 2;
  matrixA(0, 1) = 4;
  matrixA(1, 0) = 6;
  matrixA(1, 1) = 8;
  matrixA(2, 0) = 8;
  matrixA(2, 1) = 8;

  Matrix matrixB(1, 1);
  matrixB(0, 0) = 1;

  ASSERT_THROW(matrixA *= matrixB, std::invalid_argument);
}

TEST(test_operators, test_parathesis1) {
  double expected = 2;

  Matrix matrixA(2, 2);
  matrixA(0, 0) = 1;
  matrixA(0, 1) = 2;
  matrixA(1, 0) = 4;
  matrixA(1, 1) = 4;

  double actual = matrixA(0, 1);

  ASSERT_EQ(actual, expected);
}

TEST(test_operators, test_parathesis2) {
  double expected = 5;

  Matrix matrixA(2, 2);
  matrixA(0, 0) = 1;
  matrixA(0, 1) = 2;
  matrixA(1, 0) = 4;
  matrixA(1, 1) = 4;

  matrixA(0, 1) = 5;
  double actual = matrixA(0, 1);

  ASSERT_EQ(actual, expected);
}

TEST(test_operators, test_parathesis3) {
  Matrix matrixA(2, 2);
  matrixA(0, 0) = 1;
  matrixA(0, 1) = 2;
  matrixA(1, 0) = 4;
  matrixA(1, 1) = 4;

  ASSERT_THROW(matrixA(0, 5) = 2, std::out_of_range);
}

TEST(test_operators, test_parathesis4) {
  Matrix matrixA(2, 2);
  matrixA(0, 0) = 1;
  matrixA(0, 1) = 2;
  matrixA(1, 0) = 4;
  matrixA(1, 1) = 4;

  ASSERT_THROW(matrixA(0, 5), std::out_of_range);
}

TEST(test_getters, test_getters1) {
  double expected = 2;

  Matrix matrixA(2, 1);
  matrixA(0, 0) = 1;
  matrixA(1, 0) = 4;

  double actual = matrixA.GetRows();

  ASSERT_EQ(actual, expected);
}

TEST(test_getters, test_getters2) {
  double expected = 1;

  Matrix matrixA(2, 1);
  matrixA(0, 0) = 1;
  matrixA(1, 0) = 4;

  double actual = matrixA.GetCols();

  ASSERT_EQ(actual, expected);
}

TEST(test_setters, test_setters1) {
  double expected = 3;

  Matrix matrixA(2, 1);
  matrixA(0, 0) = 1;
  matrixA(1, 0) = 4;

  matrixA.SetRows(3);
  double actual = matrixA.GetRows();
  matrixA.SetRows(2);

  ASSERT_EQ(actual, expected);
}

TEST(test_setters, test_setters2) {
  double expected = 3;

  Matrix matrixA(2, 1);
  matrixA(0, 0) = 1;
  matrixA(1, 0) = 4;

  matrixA.SetCols(3);
  double actual = matrixA.GetCols();
  matrixA.SetCols(1);

  ASSERT_EQ(actual, expected);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
