//Solving interview problems



#include <iostream>
#include <ctime> 
#include <vector> 
#include <unordered_map>

//Function Prototypes


void subArrayWithMostZeros(std::vector<int> & myVect , int n);

std::vector<int> twoSumProblem(std::vector<int> & theVect, int targetSum);
int getZeros(int val);


int main(){

	//Problem: Find a subarray with size of n in an array.
	// Calculate the products of the elements,
	// return the subarray whose products has the most zeros
	std::cout << "We will solve the problem of getting the subArray" 
		<<"\nwhere the product of all its elements have the most zeros\n";


	std::cout << "How large will the array be: ";
       	int size;
	std::cin >> size;

	std::cout << "\nHow big will the size for the subArrays be: ";
	int n;
	std::cin >> n;

	//Create our array with the given size, but make sure to
	//populate it first with random variable.
	
	std::vector<int> theArr;

	srand(time(NULL));
	std::cout << "\nWhat is in vector of Random Elements:\n";

	int randomValue;
	for(int i = 0; i < size ; i++)
	{
		//The element will be of range: (1 - 50)
		randomValue = (rand() % 50 + 1);
		std::cout << randomValue << "  ";
		theArr.push_back( randomValue);
	}

	
	
	//Our array has been populated
	subArrayWithMostZeros(theArr,n);


	//We will now find the TWO SUM PROBLEM	
	std::cout << "\n\n\nWe will now solve the TWO SUM PROBLEM. Using the vector from above.\n";
	
	std::cout << "What is the target sum: ";
	int targetSum;
	std::cin >> targetSum;  

	std::vector<int> answerVector =  twoSumProblem(theArr, targetSum);

	if(answerVector.empty())
	{
		std::cout << "\n\nNo Solution was Found.\n\n";
	}
	else
	{
		std::cout << "\n\nIndex Answers: [  ";
		for(int m: answerVector){
		
			std::cout << m << "  "; 
		}
		std::cout << "]\n\n"; 

	}





	return 0;




}

void subArrayWithMostZeros(std::vector<int> & myVect, int n){
	
	std::vector<std::vector<int>> mainVector;

	//Create a sub array
	std::vector<int> subVector;

	int counter = 0;


	//Split up the vector accordingly, be careful about the bounds
	for(int i = 0; i <= (myVect.size() - n); i++){

		//We will store the product at the nth position of our array
		int product = 1;
		int j = i;
		int limit = i+n;

		//Get n element in into our sub vector [ (0) - (n-1)]
		while( j< limit){
		
			//Determine the product total
			product = product * myVect[j];
			//place the current element into the sub vector
			subVector.push_back(myVect[j]);
			++j;
		}

		//We need to save the total product in the nth position of the subVector
		subVector.push_back(product);

		//Now place this subVector into the main vector.
		//And clear the subVector
		mainVector.push_back(subVector);
		subVector.clear();
	}

	//Print all the contents of the subVector.
	std::cout << "\n\n\nWe found "<< mainVector.size() << " Solutions:\n";
	for(int m = 0 ; m < mainVector.size(); m++)
	{
		std::cout << m << ":\t[ "; 
		for(int theValue: mainVector[m])
		{
			std::cout << theValue  << " "; 
		}
		std::cout << "]\n";
	
	}	

	//We need to save the correct subArray
	std::vector<int> answerVector;
	//Save the index of this main vector that holds our answer.
	int max = 0;
	//Check only the values at position n.
	for(int k = 0; k < mainVector.size(); k++){
		//Access the given vector from the main vector.
		std::vector<int>current = mainVector[k];

		int number = current[n];

		//We have the product number, now determine the number of zeros

		int numberOfZeros = getZeros(number);

		if(numberOfZeros > max  ){
			//Save this vector.
			answerVector = current;
			max = numberOfZeros;
		}

	}

	//We hold the answer vector.
	std::cout  << "The array that hold the most number of zeros in the total product is: ";
	
	std::cout  << "Number of Zeros: " << max  << "\n";
	for(int val: answerVector){
		std::cout << val << "   ";
	}


	return;


	
}



std::vector<int> twoSumProblem(std::vector<int> & nums, int targetSum){

	//Create our Hash Map in order to be able to find elements in O(1) run time
	
	std::unordered_map<int, int> myMap;

	//FOr all the element in the vector
	for(int i = 0; i < nums.size(); i++)
	{
		//Get the complement and if we find it in our map then we are done
		int complement = targetSum - nums[i];

		//Recall that finding an element in a hash map will give us an iterator type
		//If we cannot find the element then we will get the end iterator.
		if(myMap.find(complement) != myMap.end()){
			//We found the complement in our map
			std::vector<int> ansVect = {myMap[complement], i};
			return ansVect;
		}
		//Insert the mapping of the element and index
		myMap[nums[i]] = i;

	}

	//If we reach this point, we found no solution, therefore return an empty vector
	std::vector<int> emptyVect;
	return emptyVect;
}

int getZeros(int val){
	int count= 0;
	while(val > 0){
		//Isolate every single digit and then check if we have a zero.
		int digit = val%10;
		val = val /10;
		//Check if we have a zero digit
		if(digit == 0)
			++count;

	}
	return count;
}
