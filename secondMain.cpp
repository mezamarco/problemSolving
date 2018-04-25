#include <iostream>
#include <stack>




//Function Prototypes
int getOnes(int x);

int main(){

	//Problem: Number of Ones in Binary
	std::cout << "We will solve the number of ones in binary problem\n";


	std::cout << "Enter the integer number: ";
	int num;
	std::cin >> num;


	int oneCounter = getOnes(num);

	std::cout << "\n\nThe number of ones in the binary of: " << num << " is:   ";
	std::cout << oneCounter << "\n\n\n";



}

int getOnes(int x)
{ 
	//To properly display the integer in binary form(Becasue we will have the reversed order)
	//Place the all bits into a stack
	//Diplay the bits and pop them

	std::stack<int> myStack;
	std::cout <<"\n";
	int oneCounter = 0;
	for(int i = 0; i < 32; i++)
	{	
		int modifiedValue = (x & 1);
		
		myStack.push(modifiedValue);

		if(modifiedValue == 1)
		{
			++oneCounter;
		}
		x = x >> 1;
	}


	//Now display the integer in its binary form
	while(!myStack.empty()){
		std::cout << myStack.top();
		myStack.pop();
	}


	return oneCounter;
}
