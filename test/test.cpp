#include "stack.h"
#include <gtest.h>

TEST(Queue, can_create_queue) {
	Queue<int> q;
	ASSERT_NO_THROW();
}
TEST(Queue, can_push_element) {
	Queue<int> q;
	int a = 2;
	q.push(a);
	EXPECT_TRUE(q.front()==2);
}
TEST(Queue, can_pop_element) {
	Queue<int> q;
	int a = 1;
	int b = 2;
	q.push(a);
	q.push(b);
	q.pop();
	EXPECT_TRUE(q.back() == 2);
}
TEST(Queue, can_get_front_element) {
	Queue<int> q;
	int a = 1;
	int b = 2;
	q.push(a);
	q.push(b);
	EXPECT_TRUE(q.front() == 2);
}

TEST(Queue, can_get_back_element) {
	Queue<int> q;
	int a = 1;
	int b = 2;
	q.push(a);
	q.push(b);
	EXPECT_TRUE(q.back() == 1);
}


