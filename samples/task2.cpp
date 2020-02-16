#include "stack.h"
int main() {
	Queue<int> q;
	for (int i = 0; i < 20; i++)
		q.push(i);
	q.pop();

	std::cout << q.back();
}