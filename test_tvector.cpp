 #include "utmatrix.h"

#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)
{
  ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copied_vector)
{
  TVector<int> v(10);

  ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
	TVector<int> v(5);
	v[2] = 3;
	v[4] = 5;
	TVector<int> vc(v);
	EXPECT_EQ(v, vc);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
	TVector<int> v(5);
	v[2] = 3;
	v[4] = 5;
	TVector<int> vc(v);
	v[0] = 10;
	EXPECT_NE(vc, v);
}

TEST(TVector, can_get_size)
{
  TVector<int> v(4);

  EXPECT_EQ(4, v.GetSize());
}

TEST(TVector, can_get_start_index)
{
  TVector<int> v(4, 2);

  EXPECT_EQ(2, v.GetStartIndex());
}

TEST(TVector, can_set_and_get_element)
{
  TVector<int> v(4);
  v[0] = 4;

  EXPECT_EQ(4, v[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
	TVector<int> v;
	ASSERT_ANY_THROW(v[-1] = 19);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
	TVector<int> v(10);
	ASSERT_ANY_THROW(v[11] = 19);
}

TEST(TVector, can_assign_vector_to_itself)
{
	TVector<int> v;
	ASSERT_NO_THROW(v = v);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
	TVector<int> v;
	v[5] = 10;
	TVector<int> vc;
	vc = v;
	EXPECT_EQ(v, vc);
}

TEST(TVector, assign_operator_change_vector_size)
{
	TVector<int> v;
	v[5] = 10;
	TVector<int> vc(5);
	vc = v;
	EXPECT_EQ(vc.GetSize(), 10);
}

TEST(TVector, can_assign_vectors_of_different_size)
{
	TVector<int> v;
	v[5] = 10;
	TVector<int> vc(5);
	vc[2] = 2;
	vc = v;
	EXPECT_EQ(vc, v);
}

TEST(TVector, compare_equal_vectors_return_true)
{
	TVector<int> v1, v2;
	v1[5] = 6;
	v1[8] = -19;
	v2[5] = 6;
	v2[8] = -19;
	EXPECT_EQ(v1 == v2, true);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
	TVector<int> v;
	EXPECT_EQ(v == v, true);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
	TVector<int> v1;
	TVector<int> v2(5);
	EXPECT_EQ(v1 == v2, false);
}

TEST(TVector, can_add_scalar_to_vector)
{
	TVector<int> v1(3);
	TVector<int> v2(3);
	v2[0] = 3;
	v2[1] = 3;
	v2[2] = 3;
	EXPECT_EQ(v1+3, v2);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
	TVector<int> v1(3);
	TVector<int> v2(3);
	v2[0] = -3;
	v2[1] = -3;
	v2[2] = -3;
	EXPECT_EQ(v1 - 3, v2);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
	TVector<int> v1(3);
	TVector<int> v2(3);
	v2[0] = 5;
	v2[1] = 5;
	v2[2] = 5;
	v1[0] = 1;
	v1[1] = 1;
	v1[2] = 1;
	EXPECT_EQ(v1 * 5, v2);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
	TVector<int> v1(3);
	TVector<int> v2(3);
	TVector<int> v3(3);
	
	v1[0] = 1;
	v1[1] = 2;
	v1[2] = 3;
	
	v2[0] = 1;
	v2[1] = 2;
	v2[2] = 3;

	v3[0] = 2;
	v3[1] = 4;
	v3[2] = 6;

	EXPECT_EQ(v1 + v2, v3);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
	TVector<int> v1(2);
	TVector<int> v2(3);

	v1[0] = 1;
	v1[1] = 2;

	v2[0] = 1;
	v2[1] = 2;
	v2[2] = 3;

	ASSERT_ANY_THROW(v1 + v2);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
	TVector<int> v1(3);
	TVector<int> v2(3);
	TVector<int> v3(3);

	v1[0] = 2;
	v1[1] = 3;
	v1[2] = 4;

	v2[0] = 1;
	v2[1] = 2;
	v2[2] = 3;

	v3[0] = 1;
	v3[1] = 1;
	v3[2] = 1;

	EXPECT_EQ(v1 - v2, v3);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
	TVector<int> v1(2);
	TVector<int> v2(3);

	v1[0] = 1;
	v1[1] = 2;

	v2[0] = 1;
	v2[1] = 2;
	v2[2] = 3;

	ASSERT_ANY_THROW(v1 - v2);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
	TVector<int> v1(3);
	TVector<int> v2(3);

	v1[0] = 1;
	v1[1] = 2;
	v1[2] = 3;

	v2[0] = 2;
	v2[1] = 3;
	v2[2] = 4;

	EXPECT_EQ(v1*v2, 20);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{

	TVector<int> v1(2);
	TVector<int> v2(3);

	v1[0] = 1;
	v1[1] = 2;

	v2[0] = 1;
	v2[1] = 2;
	v2[2] = 3;

	ASSERT_ANY_THROW(v1 * v2);
}

