#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
  TMatrix<int> m(5);

  ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	TMatrix<int> m1(5);
	TMatrix<int> m2(m1);
	EXPECT_EQ(m1, m2);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int> m1(5);
	m1[0][0] = 10;
	m1[0][1] = 10;
	TMatrix<int> m2(m1);
	m1[1][2] = 4;
	EXPECT_NE(m1, m2);
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> m(5);
	EXPECT_EQ(m.GetSize(), 5);
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> m1(5);
	m1[0][0] = 10;
	EXPECT_EQ(m1[0][0], 10);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> m1(5);
	ASSERT_ANY_THROW(m1[-1][0] = 10);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> m1(5);
	ASSERT_ANY_THROW(m1[5][5] = 10);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int>m(5);
	ASSERT_NO_THROW(m = m);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<int>m(5);
	m[0][0] = 5;
	TMatrix<int>m1(5);
	ASSERT_NO_THROW(m1 = m);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int>m(5);
	TMatrix<int>m1(3);
	m1 = m;
	EXPECT_EQ(m1.GetSize(), 5);
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix<int>m(5);
	TMatrix<int>m1(3);
	ASSERT_NO_THROW(m1 = m);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix<int>m(5);
	TMatrix<int>m1(5);
	m[0][0] = 10;
	m1[0][0] = 10;
	EXPECT_EQ(m == m1, true);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int>m(5);
	EXPECT_EQ(m == m, true);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int>m(5);
	TMatrix<int>m1(3);
	EXPECT_EQ(m1 == m, false);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{

	TMatrix<int>m1(2);
	TMatrix<int>m2(2);
	TMatrix<int>m3(2);

	m1[0][0] = 1;
	m1[0][1] = 1;
	m1[1][1] = 1;

	m2 = m1;

	m3[0][0] = 2;
	m3[0][1] = 2;
	m3[1][1] = 2;

	EXPECT_EQ(m1 + m2, m3);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int>m1(2);
	TMatrix<int>m2(3);

	ASSERT_ANY_THROW(m1 + m2);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int>m1(2);
	TMatrix<int>m2(2);
	TMatrix<int>m3(2);

	m1[0][0] = 1;
	m1[0][1] = 1;
	m1[1][1] = 1;

	m2[0][0] = 1;
	m2[0][1] = 1;
	m2[1][1] = 1;

	EXPECT_EQ(m1 - m2, m3);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int>m1(2);
	TMatrix<int>m2(3);

	ASSERT_ANY_THROW(m1 - m2);
}

