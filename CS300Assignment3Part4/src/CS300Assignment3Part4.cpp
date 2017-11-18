//============================================================================
// Name        : CS300Assignment3Part4.cpp
// Author      : Ephraim Scarf
//============================================================================

#include <iostream>
#include "LinkedStack.h"
using namespace std;

LinkedStack<int> stack1;
LinkedStack<int> stack2;
void reverseDigits(int);

int main() {
	int input;
	cout<<"Enter a number: "<<endl;
	cin>>input;
	reverseDigits(input);

	// reverseDigits(input) reverses digits into stack1, but a second
	// stack is necessary to print the digits in the desired order
	while(!stack1.isEmpty()) {
		int temp = stack1.pop();
		stack2.push(temp);
	}

	while(!stack2.isEmpty()) {
		int temp = stack2.pop();
		cout<<temp;
	}
	return 0;
}

void reverseDigits(int x) {
	if(x < 10) {
		stack1.push(x);
		return;
	}

	else if((x % 10) == 0 ) {
		int temp = 0;
		stack1.push(temp);
		return reverseDigits((x / 10));
	}

	int lastDigit = x - ((x / 10) * 10 ); // if x is 957, lastDigit is 7
	stack1.push(lastDigit);
	return reverseDigits((x / 10));
}
