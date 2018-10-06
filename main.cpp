#include <iostream>
#include <vector>
#include <ctime>
#include <iterator>
#include <cmath>		//For abs()
#include <set>

//Function Prototypes
bool findInVector(std::vector<int> &theVector, int theValue);
bool findInSet(std::set<int> &theSet, int theValue);
void reverseTheString(std::string &theString);
void solveDivisibility(int x);

int getChange(std::vector<int> &myVector, int x);

int main(){

 	//Problem: Display the elements that are repeated in the array
	//Note: The elements in the array will be between:   1 <= x <= array.size()


	//Fist get a random array
	
	srand(time(NULL));

	
	std::cout << "How big will the array be, (2 - 20):   ";
	int size;
	std::cin >> size;
	
	std::vector<int> myVector;
	
	for(int i = 0; i < size; i++ ){
		myVector.push_back(rand()%size  + 1 );
	}


	std::vector<int>::iterator myItr = myVector.begin();
	std::vector<int>::iterator myItrEnd = myVector.end();
	std::cout << "We have a the following Vector:" << std::endl; 
	while(myItr != myItrEnd){
	
		std::cout << *myItr << "   ";
		++myItr;
	}
	//Make a copy of this original vector
	std::vector<int> myVectorTwo = myVector;

	std::cout << "\n\n";
	std::vector<int> repeatedVector;







	//Solve by brute force O(n^2)
	//Simply compare the elements one by one
	int firstValue;
	for(int j = 0; j < myVector.size() - 1 ; j++ ){
		
		firstValue = myVector[j];


		for(int k = j+1; k < myVector.size() ; k++){
			
			//Avoid repetition of finding the same repeated element
			if(!findInVector(repeatedVector,firstValue)){
				//Start comparing the values
				if( firstValue == myVector[k])
				{
					std::cout<< "Found Repetition: " << firstValue <<std::endl;
					repeatedVector.push_back(firstValue);
				}
			}
			

		}
	}
	

	std::cout <<"\n\nNote: That the element in the array are integers between: 1 <= x <= array.size()"<< std::endl;
	std::cout <<"We will now use a better technique to solve this problem.\n\n" << std::endl;

	//Be Clever and solve it in: O(n) time complexity and O(1) space complexity
	//We will the the markings by making values negative
	int theValue;
	std::set<int> checkSet;
	for(int r = 0; r < myVector.size(); r++ ){
	  
	  //Check if the value has already been found to be repeated

	  if(!findInSet( checkSet, abs(myVector[r])) ){
		//Get the value for the future index position, use absolute value
		theValue = abs(myVector[r]) - 1;

		//Check if the value of the given index is already a negative value
		//Use that index position to make it into a negative value
		if(myVector[theValue] < 0){
			//If the value is negative then it has this index has been marked before
			std::cout << "Repeated Element: " << theValue + 1 << std::endl;  
			checkSet.insert(theValue + 1 );
		} else {
			//Mark the given position
			myVector[theValue] = myVector[theValue]*(-1);
		}

	  }
	}
	
	checkSet.clear();
 	//Problem: Display the elements that are repeated in the array
	//Note: The elements in the array will be between:   0 <= x <= array.size() - 1


	std::cout <<"\n\nSame problem, but now the element in the array will be between: 0 <= x <= array.size() -1\n\n" << std::endl;

	//Be Clever and solve it in: O(n) time complexity and O(1) space complexity
	//We will the the markings by making values negative
	theValue =0;
	
	for(int r = 0; r < myVectorTwo.size(); r++ ){
	  
	  //Check if the value has already been found to be repeated

	  if(!findInSet( checkSet, abs(myVectorTwo[r]))){
		//Get the value for the future index position, use absolute value
		theValue = abs(myVectorTwo[r]);

		//Check if the value of the given index is already a negative value
		//Use that index position to make it into a negative value
		if(myVectorTwo[theValue] < 0){
			//If the value is negative then it has this index has been marked before
			std::cout << "Repeated Element: " << theValue << std::endl;  
			checkSet.insert(theValue );
		} else {
			//Mark the given position
			myVectorTwo[theValue] = myVectorTwo[theValue]*(-1);
		}

	  }
	}
	



	//Problem:Reverse a String.
	std::cout << "\n\nWe will now solve the Reverse the String problem.\n" << std::endl;

	//Get a string with random characters. The size of the string will be between: (5-50)
	std::cout << "Enter the size of the string: ";
	int stringSize;
	std::cin >> stringSize;

	std::string originalString;
	//Create the string with the given length
	int decimalNumber;
	for(int k = 0; k < stringSize; k++)
	{
		//Use the rand function to get a character with ASCII values: (97-122)
		decimalNumber = (rand() % 26) + 97;
	       //Convert the decimal number into a character and add it to the orginal string
	       originalString = originalString  + (char) decimalNumber;	
	}
	std::cout << "\nThe original string is: \n" << originalString << std::endl;

	reverseTheString(originalString);

	std::cout << "\nWe have reversed the string: " << std::endl;
	std::cout << originalString << "\n\n";

	//Problem: Divisibility, Check the values from 1 to x
	//If divisible by 3 and 5: print "FizzBuzz"
	//If only divisible by 3: print "Fizz"
	//If only divisible by 5: print "Buzz"
	//else just print the number.
	
	// Get the value of x
	std::cout << "We will now solve the problem of divisibility(Up to the value of x)"<< std::endl;
	
	std::cout << "Enter the value of x: ";
	int x;
	std::cin >> x;
	
	std::cout << "\n\nDo divisibility up to the number: " << x << "\n";
	solveDivisibility(x);

	std::cout << "\n\n";




	//Problem: Making change
	//Given an input x, 
	//write a function to determine the minimum number of coins 
	//required to make that exsact amount of change


	//First create a vector with our possible coins
	std::vector<int> vect = {25,10,5,1};
	
	//Some actual examples of input and output are:
	//11 -> 2 coins
	//26 -> 2 coins
	//33 -> 5 Coins
	
	
	// We will solve this problem with a recursive function
        std::cout << "We will now Solve the Make Change Problem.\n" << std::endl;
	int changeNumber;
	std::cout << "Enter the Change value so we can break it down: ";
	std::cin >> changeNumber;

	//Call the recursive function 
	int minCoins = getChange(vect, changeNumber);

	std::cout << "Breaking down: " << changeNumber << std::endl;
	std::cout << "The Minimum number of coins is: " << minCoins << "\n\n\n"; 



	
	

	return 1;
}



//Simple problem
bool findInVector(std::vector<int> &theVector, int theValue){
	
	if(!theVector.empty()){
	  for(int m = 0; m <theVector.size(); m++){
       		  if(theValue == theVector[m]){
		  	return true;
		  }
	  }
	}
	return false;
}



bool findInSet(std::set<int> &theSet, int theValue){
	
	if(theSet.empty()){
		return 0;
	}


	std::set<int>::iterator myItr = theSet.begin();
	std::set<int>::iterator myItrEnd = theSet.end();

	while(myItr != myItrEnd)
	{

		if(*myItr == theValue)
		{
			
			return 1; 
		}
		++myItr;
	}
	return 0;

}



void reverseTheString(std::string &theString){
	//To reverse the string, I need to consider two index points
	int i=0;
	int j = theString.length() - 1;

	while(i<j)
	{
		int temp = theString[i];
		theString[i] = theString[j];
		theString[j] = temp;

		++i;
		--j;
	}
	return;
}


void solveDivisibility(int x){
  for(int i = 1; i <= x; i++ )
  {
	if( (i%3 == 0) &&  (i%5 == 0) )
		std::cout << "FizzBuzz\n";
	else if (i %3 == 0)
		std::cout << "Fizz\n"; 
	else if (i % 5 == 0)
		std::cout << "Buzz\n";
	else
		std::cout  << i << "\n";
  }
  return;
}
 
//Our recursive function
int getChange(std::vector<int> &myVector, int x){
	
	if(x == 0){
		return 0;
	}
	std::cout << "Entering the Function for: " << x << std::endl;
	int min = x;

	//FOr each coin in the array of coins
	for(int theCoin: myVector){
		std::cout << "Trying for coin: " << theCoin;

		if( x - theCoin >= 0)
		{
			std::cout << "\tSuccess\nMove to another function:  "<< x- theCoin <<  "\n"; 
			int c = getChange(myVector, x - theCoin);
			if( min > c + 1)
			{
				min = c + 1;
			}
		}
		else{
			std::cout <<"\tFailed: Return: " << min << "\n";
		       	
		}
	}
	

	return min;
}

