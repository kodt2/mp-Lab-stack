#include <iostream>
template<typename T>
class TStack {
private:
	int mem;
	int n;
	T* stack;
public:
	TStack() {
		n = 0;
		mem = 0;
	}
	TStack(TStack s1) {
		n = s1.n;
		mem = s1.mem;
		if (stack == nullptr){
		delete[] stack;
		}
		stack = new T[mem];
		for (int i = 0; i < n; i++) {
			stack[i] = s1.stack[i];
		}
	}
	~TStack() {
		n = 0;
		mem = 0;
		delete[] stack;
	}
	void push(T e) {
		if (mem != 0) {
			if (n >= mem) {
				mem = 2 * mem;
				T* temp = stack;
				stack = new T[mem];
				for (int i = 0; i < n; i++) {
					stack[i] = temp->stack[i];
				}
				delete[] temp;
				stack[n] = e;
				n++;
			}
			else {
				stack[n] = e;
				n++;
			}
		}
		else {
			n = 1;
			mem = 1;
			stack = new T[1];
			stack[0] = e;
		}
	}
	void pop() {
		n--;
	}
	T top() {
		return (stack[n-1]);
	}
	int size() {
		return n;
	}
	bool empty() {
		return n == 0;
	}
};