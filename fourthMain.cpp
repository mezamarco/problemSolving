//Solving interview problems



#include <iostream>
#include <ctime> 
#include <vector> 
#include <unordered_map>

//Function Prototypes


void subArrayWithMostZeros(std::vector<int> & myVect , int n);

std::vector<int> twoSumProblem(std::vector<int> & theVect, int targetSum);



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
	
	std::vector<std::vector<int>> theAnswerVector;

	//Create a sub array
	std::vector<int> subVector;

	int counter = 0;

	//Split up the vector accordingly
	for(int i = 0; i < myVect.size(); i++){

		//Place the element into the subVector
		subVector.push_back(myVect[i]);
		++counter;
		
		//If we have stored n values into the subVector
		//then it is time that we put it in our Answer vector
	
		if(counter == n){

			//Store this subArray into the AnswerVector
			theAnswerVector.push_back(subVector);
	
			//Clear all the elements from the subVector
			subVector.clear();
			counter = 0;	
		}
	
	
	
	}

	//The answerVector now hold the subVector of the appropiate size 
	//Now I must print out all the sub arrays to see what is going on 

	std::cout << "\n\n\nWe found "<< theAnswerVector.size() << " Solutions:\n";
	for(int m = 0 ; m < theAnswerVector.size(); m++)
	{
		std::cout << m << ":\t[ "; 
		for(int theValue: theAnswerVector[m])
		{
			std::cout << theValue  << " "; 
		}
		std::cout << "]\n";
	
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

