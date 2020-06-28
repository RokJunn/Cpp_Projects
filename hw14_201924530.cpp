#include <iostream>
#include <cstring>
using namespace std;

class StackException {
	const string msg;
public:
	StackException(const string& _msg) : msg(_msg) {}
	void print() const { cout << msg << endl; }
};

class CharStack {
	int size;
	int top;
	char* s;
public:
	CharStack(int sz) {
		if (sz < 0) throw new StackException("Array size is invalid!");
		top = 0;
		s = new char[size = sz];
	}
	~CharStack() {
		delete[] s;
	}
	CharStack(const CharStack& stack) {
		s = new char[strlen(stack.s) + 1];
		strcpy(s, stack.s);
		size = stack.size;
		top = stack.top;
	}
	CharStack& operator=(const CharStack& stack) {
		delete[] s;
		size = stack.size;
		top = stack.top;
		s = new char[strlen(stack.s) + 1];
		strcpy(s, stack.s);
		return *this;
	}
	// destructor, copy constructor, and assignment operator
	void push(char c) {
		if (top >= size) throw StackException("Invalid push!");
		s[top++] = c;
	}
	char pop() {
		if (top <= size) throw StackException("Invalid pop!");
		char r = s[--top];
		s[top] = '\0';
		return r;
	}
	void print() const {
		for (int i = 0; i < top; i++) cout << s[i];
		cout << endl;
	}
};

int main() {
	try {
		CharStack s1(-1); //Array size is invalid!

		CharStack s2(2);
		s2.push('1');
		s2.push('2');
		s2.push('3'); //Invalid push!

		CharStack s3(1);
		s3.pop(); //Invalid pop!
	}
	catch (const StackException& e) { e.print(); }
	catch (const StackException* const e) { e->print(); delete e; }
}
