// Final Exam Code Spring 2015 CS 162
// Your Name Here Joe Aguilera
//
// Implement as many functions as you can.
// Start with the Constructors, test as you go.


#include <iostream>
using namespace std;

/*----------------------------
*  Basic Stack Class
*  Implement using Dynamic Memory
*  Use 'int' for your stack elements
*/
class Stack {
public:
	// Construct Stack with space for n items
	Stack(int);
	// Copy constructor for Stack
	Stack(const Stack&);
	// Destructor for Stack
	~Stack();
	// Add an element to the Stack
	//   Return a reference to the stack
	Stack& push(int);
	// Return the value at the top of the Stack
	//   leaving the stack unchanged
	int top();
	// Remove the top item from the stack
	void pop();
	// Return true with empty stack, false otherwise
	bool isEmpty();
	// Return true with full stack, false otherwise
	bool isFull();
	void make_space(int);
private:
	int size;
	int capacity;
	int * storage;
};

/* Stack Implementation Code Here */

Stack::Stack(int a){
	size = a;
	capacity = a;
	storage = new int[a];

	for (int i = 0; i < size; ++i){
		storage[i] = 0;
	}
}

Stack::Stack(const Stack&other) :size{ other.size }, storage{ new int[other.size] }
{
	storage = new int[size];
	copy(other.storage, other.storage + size, storage);

	return;
}

Stack::~Stack(){
	delete[] storage;
}

void Stack::make_space(int z_alloc)
{
	int index = size;
	size = 0;
	int size_counter;
	if (z_alloc <= capacity) return;                    // never decrease allocation
	int* p = new int[z_alloc];                      // allocate new space
	for (int i = 0; i < index; ++i) {
		p[i] = storage[i];  // copy old elements
		size_counter++;
	}
	delete[] storage;                               // deallocate old space
	storage = p;                                    // storage is set to the needed size
	capacity = z_alloc;
	size = size_counter;

	return;
}

Stack& Stack::push(int a){

	if (capacity == 0)
	{
		make_space(100);
	}                           	// make space for 100 more elements when add to end

	else if (size == capacity)
	{
		make_space(2 * capacity);
	}                               	// get more space
	storage[size] = a;         	// add at end of Number_Store
	++size;                           	// increase size (sz is the number of elements)
	return *this;
}
int Stack::top(){
	int index = size - 1;
	int value = storage[index];

	return value;

}
void Stack::pop(){
	int  index = size - 1;
	int* Holder = new int[index];

	for (int i = 0; i < index; ++i){
		Holder[i] = storage[i];
	}

	delete[] storage;
	storage = new int[index];

	for (int i = 0; i < index; ++i){
		storage[i] = Holder[i];
	}
	delete[] Holder;

	size = index;
}
bool isEmpty(){

}
bool isFull(){

}

/*
// Return true if ==, false otherwise
// Use ONLY stack methods, leave the stacks unchanged.
bool operator==(const Stack& lhs, const Stack& rhs) {


}
// Print the values on the stack, using ONLY
//   stack methods, leave the stack unchanged.
ostream& operator<<(ostream&ost, const Stack& s) {

}
*/


/* End of Stack Implementation Code */

void testStack(void);

int main() {
	cout << "Joe Aguilera" << endl;
	testStack();

	return 0;
}

// Test your Stack methods below.
// Add additional tests to the following code
void testStack(void) {
	cout << "Stack Testing..." << endl;
	/*
	Stack s(10);
	s.push(3).push(7).push(1).push(9);
	s.pop(); s.pop(); s.push(8); s.pop(); s.pop();
	cout << s.top() << endl;
	*/
}