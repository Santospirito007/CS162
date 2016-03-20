/*
*  CIS 162 Spring 2015 Midterm Exam
*
*  Name:Joe Aguilera
*
*/

/* Big O questions, answer them here, below each question.

Given a linked list X and a vector Y, answer the question
and give a reason for you answer.

1) Which is faster to insert a new value at position zero?

Linked List

2) Which is faster to insert at position Z?

Vector

3) Which is faster to delete item at position Z?

Linked List

4) If both are sorted, which is faster to find a value?

The Same


Given two algorithms: One -> O(n^2), Two -> O(n log n),
which is faster?

n log n

Given the code fragment below, what is the big O?
//------------------------------
for (int i = 0; i < n; ++i) {
// do simple task, O(1)
}

for (int i = 0; i < n; ++i) {
// do simple task, O(1)
}

Big o of n
//------------------------------


*/

#include "stdafx.h"  // Remove this if not using Visual Studio
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// File Path - Do not change this function
// Pass in a file name and the function will return a full path
//   that may be used to open the file for ouput and input.
string getFilePath(const string& fileName) {
	string path = __FILE__;         //gets source code path, include file name
	path = path.substr(0, 1 + path.find_last_of('\\'));     //removes file name
	path += fileName;               //adds input file to path
	//path = "\\" + path;
	//cout << path << endl;
	return path;
} //-----------------------------------------------------------------------------

// Write the numbers 65 to 75. After each number
//   write the character with that UNICODE value.
// Use a (char) cast to get the character.
void writeFile(const string& path) {
	ofstream ost{ path };
	if (!ost) {
		cout << "cant open outputfile";
	}
	else {
		for (int i = 65; i<76;++i) {
			ost << i << "   ";
			wchar_t c = static_cast<wchar_t>(i);
			ost << c << endl;
		}
		ost.close();
		cout << "file Written to file" << endl;
	}

	return;
}

// Read an int value and a char value and print
//   them out with a space between and a line end.
// Read the file with a while() loop and do not
//   assume the number of data points in the file.
void readFile(const string& path) {
	ifstream ist{ path };
	if (!ist) {
		cout << "cant open read file";
	}
	else {
		int i;
		char c;
		char c2;
		while (ist >> i >> c>>c2) {
			cout << "int: " << i << " char: " << c<<c2 << endl;
		}
		cout << path << " was read:" << endl;
	}
	ist.close();


	return;
}

// class Mid, three private ints, default constructor
//   with values 1,2,3, and a three int constructor.
// Add methods to return the sum and product of the 
//   three ints. Do this with operator overload for
//   full points.
// Add a friend method to overload the << operator
//   and output the three ints as: (1,2,3).
// Please use inline code for your methods, short & sweet.
//
class Mid {
public:
	// Constructors
	Mid(){
		a = 1;
		b = 2;
		c = 3;
	};
	Mid(int a2, int b2, int c2){
		a = a2;
		b = b2;
		c = c2;
	};
	Mid operator*(Mid x){
		Mid b = *this;
		b.a *= x.a;
		b.b *= x.b;
		b.c *= x.c;
		return b;
	};
	Mid operator+( Mid x){
		Mid b = *this;
		b.a+=x.a;
		b.b += x.b;
		b.c += x.c;
		return b;
	};
	Mid operator<<(const Mid& x){
	};
	// Method to multiply this * other, return Mid.
	// Best if * overloaded
	Mid MultipliValue( Mid& a, Mid& b){
		Mid multi;
		multi = a * b;
		return multi;
	}
	// Method to add this + other, return Mid.
	// Best if + overloaded
	Mid AddtogetherVal(Mid&a, Mid&b){
		Mid Addy;
		Addy = a + b;
		return Addy;
	}
	// Output method to print Mid: (1,2,3).
	// Best if << overloaded
	void printMid(){
		cout << "(" << a << "," << b << "," << c << ")." << endl;
	}
private:
	// three private ints
	int a;
	int b;
	int c;
};



// print the values of the passed in array (could be heap based)
//  use the size parameter to determine how many to print
// Only two parameters please.
void print(const int *param[], const int& size){
	for (int i=0;i<size;++i) {
		cout << param[i] << endl;
	}
	return;
}


// initialize array (could be heap based) with
//  the values 0..size
// Only two parameters please.
void init(int param[], int size){
	for (int i = 0; i<size; ++i) {
		param[i] =i ;
	}
	return;
}


// write statements to accomplish each comment
// use only one statement per comment
void pointers() {
	// create c-style array of 100 ints initialized to zeros
	int param[100]{0};
	// create 100 ints on the heap initialized to zeros

	// print the last 10 ints of c-style array

	// print the last 10 ints of heap array
	for (int i = 100; i >= 90; --i){
		cout << param[i] << endl;
	};


	// call init with c-style array
	init(param, 100);

	// call init with heap array

	// print 15 values starting at 50, c-style array
	for (int k = 50; k <= 75; ++k){
		cout << param[k] << " ";
	};
	cout << endl;

	// print 15 values starting at 50, heap array

	// clean up the allocated memory


}

int main() {
	// do not change the line of code below, use the 'file' variable
	// initialize 'file' to a useful path+name
	string file{ getFilePath("file.txt") };

	// Write a file. Read the file and echo the contents.
	// Use writeFile() and readFile(), two function calls
	writeFile(file);
	readFile(file);

	// Create a Mid object with 2,2,2, name it x
	Mid x(2, 2, 2);

	// Create a default Mid object, name it y
	Mid y;

	// Create a Mid object that is the product of x * y, name it z, one statement
	Mid z;
	z.MultipliValue(x, y);

	// Print z with a label
	cout << "Mid object Z is Mid object X and y, x*y:   ";
	z.printMid();

	// Add z to z and print the result with a label, use only one statement
	z.AddtogetherVal(z, z);
	z.printMid();

	// Create a new Mid object dynamically, name it d, initialze with x.

	Mid *d = &x;

	// print d with a label
	d->printMid();
	// recover the memory used by d
	//delete d;
	// Call the pointers function
	pointers();

	return 0;
}


