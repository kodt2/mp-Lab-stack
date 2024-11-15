#include "tstack.h"
#include <gtest.h>

TEST(Tlist, can_create_stack_with_positive_length)
{
	ASSERT_NO_THROW(TStack<int> m(5));
}

TEST(Tlist, throws_when_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(TStack<int> m(-5));
}

TEST(Tlist, can_create_copied_stack)
{
	TStack<int> m(5);
	ASSERT_NO_THROW(TStack<int> m1(m));
}

TEST(Tlist, copied_stack_is_equal_to_source_one)
{
	TStack<int> m(5);
	TStack<int> m1(m);
	EXPECT_EQ(m, m1);
}

TEST(Tlist, copied_stack_has_its_own_memory)
{
	TStack<int> m(5);
	TStack<int> m1(m);
	m1.push(1);
	TStack<int> res(5);
	res.push(1);
	EXPECT_EQ(m1, res);
}

TEST(Tlist, can_get_size)
{
	int sz = 5;
	TStack<int> l(sz);
	EXPECT_EQ(sz, l.size());
}

TEST(Tlist, can_get_element)
{
	TStack<int> m(5);
	ASSERT_NO_THROW(m.top());
}