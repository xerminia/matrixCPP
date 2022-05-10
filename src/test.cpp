#include "gtest/gtest.h"
#include "s21_matrix_oop.hpp"

TEST(test_move_constructor, test_move_constructor_1) {
  // arrange
  S21Matrix expected(1, 2);
  expected(0, 0, 1);
  expected(0, 1, 2);

  S21Matrix matrixA(1, 2);
  matrixA(0, 0, 1);
  matrixA(0, 1, 2);

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

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
