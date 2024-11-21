#include "tstack.h"
#include <gtest.h>

TEST(TStack, can_create_stack_with_positive_length)
{
	ASSERT_NO_THROW(TStack<int> m);
}

TEST(TStack, can_create_copied_stack)
{
	TStack<int> m;
	m.push(10);
	ASSERT_NO_THROW(TStack<int> m1(m));
}

TEST(TStack, copied_stack_is_equal_to_source_one)
{
	TStack<int> m;
	m.push(10);
	TStack<int> m1(m);
	EXPECT_EQ(m, m1);
}

TEST(TStack, copied_stack_has_its_own_memory)
{
	TStack<int> m;
	TStack<int> m1(m);
	m1.push(1);
	TStack<int> res;
	res.push(1);
	EXPECT_EQ(m1, res);
}

TEST(TStack, can_get_size)
{
	int sz = 5;
	TStack<int> l;
	l.push(1);
	l.push(1);
	l.push(2);
	l.push(1);
	l.push(2);
	EXPECT_EQ(sz, l.size());
}

TEST(TStack, can_get_element)
{
	TStack<int> m;
	m.push(1);
	ASSERT_NO_THROW(m.top());
}

TEST(TStack, can_pop_element)
{
	TStack<int> m;
	m.push(1);
	ASSERT_NO_THROW(m.pop());
}