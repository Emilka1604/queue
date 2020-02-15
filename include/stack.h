#pragma once
#include <memory>
#include <iostream>
#include <exception>

template<class T>
class Queue {
private:
	std::unique_ptr<T[]> ptr;
	T* begin;
	T* end;
	int Msize;
	int size;
public:
	Queue() {
		size = 0;
		Msize = 10;
		ptr.reset(new T[Msize]);
		begin = &ptr[0];
		end = &ptr[0];
	}
	void pop() {
		if (size == 0) {
			std::exception ex("empty queue");
			throw ex;
		}
		else {
			if (begin == &ptr[Msize - 1]) {
				begin = &ptr[0];
			}
			else {
				begin++;
			}
			size--;
		}

	}
	void push(T& val) {
		if (size == Msize) {
			std::unique_ptr<T[]> ptr1;
			ptr1.reset(new T[Msize / 2 * 3]);
			Msize = Msize / 2 * 3;
			int i = 0;
			while (begin != &ptr[size - 1]) {
				ptr1[i] = *begin;
				begin++;
				i++;
			}
			ptr1[i] = *begin;
			i++;
			begin = &ptr[0];
			while (begin != end) {
				ptr1[i] = *begin;
				begin++;
				i++;
			}
			ptr1[size] = val;
			size++;
			ptr1.swap(ptr);
			begin = &ptr[0];
			end = &ptr[size];
		}
		else
			if (end == &ptr[Msize - 1]) {
				ptr[Msize - 1] = val;
				end = &ptr[0];
				size++;
			}
			else {
				*end = val;
				end++;
				size++;
			}
	}
	T& front() {
		if (size == 0) {
			std::exception ex("empty queue");
			throw ex;
		}
		else
			if (end == &ptr[0]) {
				return ptr[Msize - 1];
			}
			else {
				end--;
				T a = *end;
				end++;
				return a;
			}
	}
	T& back() {
		if (size == 0) {
			std::exception ex("empty queue");
			throw ex;
		}
		else
			return *begin;
	}

};