#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:

	void popStack(stack<int>& myStack) {
		if (!myStack.empty()) {
			myStack.pop();
		}
		else {
			cout << "Stack is empty. Cannot pop." << endl;
		}
	}

	void isEmpty(stack<int>& myStack) {
		if (myStack.empty()) {
			cout << "Stack is empty." << endl;
		}
		else {
			cout << "Stack is not empty." << endl;
		}
	}

	int topElement(stack<int>& myStack) {
		if (!myStack.empty()) {
			return myStack.top();
		}
		else {
			cout << "Stack is empty. No top value." << endl;
			return -1;
		}
	}

};

int main() {

	Solution sol;

	stack<int> myStack;

	
	myStack.push(21);
	myStack.push(15);
	myStack.push(96);
	myStack.push(13); 

	cout << "Stack size: " << myStack.size() << endl;

	sol.popStack(myStack);

	cout << "Stack size after pop: " << myStack.size() << endl;

	cout << "Is stack is empty or not: ";

	sol.isEmpty(myStack);


	cout << "Top element: " << sol.topElement(myStack) << endl;




	return 0;
}