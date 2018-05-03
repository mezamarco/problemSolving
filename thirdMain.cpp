// This is were I will solve all my Dynamic Programming Problems


// I solve 7 problems in this cpp file:

// Fibonacci Sequence(Regular and Dynamic)
// Make Change (Regular and Dynamic)
// Summation without an operator, Do the solve using binary manipulations
// Angram Problem: Are the two strings anagrams
// three value sum :  Give all the sets where: a + b + c == 0


//#include <iostream>
#include <chrono>      //To determine te run time of a function
#include <limits>
#include <iostream>
#include <unordered_map>
#include <vector>


using namespace std::chrono;

//Function Prototypes


int fibSeq(int n);
int efficientFibSeq(int n);

int makeChange(int n);

int efficientMakeChange(int n);


int sum(int a , int b);
bool isAnagram(std::string &s1, std::string &s2);


void threeSum(std::vector<int> & theVector);
void bubbleSort(std::vector<int> & vect);


int const coinsArr[4] = {25,10,5,1};



int main(){

	std::cout <<"\nWe will solve the Fibonacci Sequence in two ways:" << std::endl;


	std::cout << "Enter the Number for our Fibonacci Sequence: ";
	int number;
	std::cin >> number;



	std::chrono::high_resolution_clock::time_point slowTime1 = std::chrono::high_resolution_clock::now();
	int slowAns = fibSeq(number);
	std::cout << "\n\nThe slow answer to Fib(" << number << ") = " << slowAns << std::endl;
 	std::chrono::high_resolution_clock::time_point slowTime2 = std::chrono::high_resolution_clock::now();


	auto durationSlow = std::chrono::duration_cast<microseconds>( slowTime2 - slowTime1 ).count();
	std::cout << "The running time was: " << durationSlow;


	//To get the answer faster, we must use dynamic programming.
	


	std::chrono::high_resolution_clock::time_point fastTime1 = std::chrono::high_resolution_clock::now();
	int fastAns = efficientFibSeq(number);
	std::cout << "\n\n\nThe fast answer to Fib(" << number << ") = " << fastAns << std::endl;
	std::chrono::high_resolution_clock::time_point fastTime2 = std::chrono::high_resolution_clock::now();
    
	auto durationFast = std::chrono::duration_cast<microseconds>( fastTime2 - fastTime1 ).count();
	
	std::cout << "The running time was: " << durationFast << "\n\n\n";





	std::cout << "We will now solve the Make Change Problem" <<  std::endl;
	std::cout << "We will Make Change for the value: ";
	int changeValue;
	std::cin >> changeValue;

	
	std::chrono::high_resolution_clock::time_point slowTime10 = std::chrono::high_resolution_clock::now();
	
	int slowMinCoinsNeeded = makeChange(changeValue);
	std::cout << "\n\nThe slow answer to makeChange(" << changeValue << ") = " <<slowMinCoinsNeeded; 

 	std::chrono::high_resolution_clock::time_point slowTime20 = std::chrono::high_resolution_clock::now();


	auto durationSlow00 = std::chrono::duration_cast<microseconds>( slowTime20 - slowTime10 ).count();
	std::cout << "\nThe running time was: " << durationSlow00;

	std::chrono::high_resolution_clock::time_point fastTime10 = std::chrono::high_resolution_clock::now();
	int fastMinCoinsNeeded = efficientMakeChange(changeValue);
	std::cout << "\n\nThe fast answer to makeChange(" <<changeValue << ") = " << fastMinCoinsNeeded; 
	std::chrono::high_resolution_clock::time_point fastTime20 = std::chrono::high_resolution_clock::now();

	auto durationFast00 = std::chrono::duration_cast<microseconds>( fastTime20 - fastTime10 ).count();
	std::cout << "\nThe running time was: " << durationFast00 << "\n\n\n";
	
	std::cout << "\n\n";




	std::cout << "We will now solve the Addition of two numbers, but without using the operators.\n";

	std::cout << "Enter the first value for the summation: ";
	int a;
	int b;
	std::cin >> a;
	
	std::cout << "Enter the second value for the summation: ";
	std::cin >> b;

	std::cout << "The sum: " << a << " + " << b << " = " << sum(a,b);

	std::cout <<"\n\n";




	std::cout << "We will now solve the ANAGRAMS problem.\n";
	std::string s1;
	std::string s2;



	std::cout << "What will be the first String: ";
	std::cin >> s1;
	std::cout << "\nWhat will be the second String: ";
	std::cin >> s2;

	std::cout << "\n\nDo we have an Anagram(" << s1 << "," << s2 << ") = " << isAnagram(s1,s2)<<"\n\n\n";








	//We will now solve the three sum problem
	//GIven an array of integers 
	//write a function that will return all the sets where a+b+c ==0 
	
	//Lets get an array and then apply the threesum function to it
	std::cout << "We will now solve the THREE SUM PROBLEM.\n" << std::endl;
	std::cout << "How big will the size of the array be:  " << std::endl;
	int arraySize;
	std::cin >> arraySize;

	std::vector<int> theVect;
	//Lets populate the array with random elements
	for(int m=0; m< arraySize; m++){
	
		//Get a random value and then place it in our vector 
		//Random value range: (-20 to 20)
		int randomValue = (rand() % 41)- 20 ;
		theVect.push_back(randomValue);

	}
	std::cout << "\n\nThe Vector holds:\n";
	//Let the user see the random elements of the vectors
	for(int val : theVect){
		std::cout << val << "  ";
	}

	//Use the function to print out all the solutions tot the three sum problem
	threeSum(theVect);



}










int fibSeq(int n){
	//Use recursion to solve this problem.
	if(n == 0)
		return 0;
	if(n == 1)
		return 1;

	return(fibSeq(n-1) + fibSeq(n-2) );
}
int efficientFibSeq(int n){
	//Use Dynamic Prgramming to solve this problem.
	//This means that we will sacrifice memory in order to make our program run faster.
	int fibArr[n+1];


	fibArr[0] = 0;	
	fibArr[1] = 1;	

	for(int i= 2; i <= n ; i++){
	
		fibArr[i] =  fibArr[i-1] + fibArr[i-2];
	}


	return fibArr[n];
}


int makeChange(int n){

	if(n==0)
		return 0;

	//Set minCoins to infinity
	int minCoins = std::numeric_limits<int>::max();

	for(int coin: coinsArr){
	
		//Check for valid coins. 
		//Valid if the subtraction will not give us a negative value
		if( n - coin >= 0 ){
			int currMinCoins = makeChange(n-coin);

			if(currMinCoins < minCoins){
				minCoins = currMinCoins;
			}
		
		}
	
	}	
	//Add back the coins that was used for recursion.
	return minCoins + 1;

}




int efficientMakeChange(int n){
	
 	//Create our array of Answers
	int answersArr[n+1];
	answersArr[0] = 0;


	for(int i = 1; i <= n ; i++){

		//Set minCoins equal to infinity.
		int minCoins = std::numeric_limits<int>::max();

	
		for(int coin : coinsArr){
	
			//For valid coins only
			if(i - coin >= 0){
				int currentMinCoins = answersArr[i-coin] + 1;

				if(currentMinCoins < minCoins)
				{
					minCoins = currentMinCoins;
				}
		
			}
		}	
		//Store the answer
		//std::cout <<"Storing into " << i <<" : " <<minCoins << std::endl; 
		answersArr[i] = minCoins;
	}
	//The answersArr have been populated
	//Return the wanted answer we are done.
	return answersArr[n];
}


int sum(int a , int b){

	//Our b will be modified with each recursion. When b is zero then we are done. 
	if(b == 0){
		return a;
	}	
	//Use recursion to solve this problem
	//Do the proper binary addition using xor
	//Xor will do the addition, but it will not carry over the 

	int partialSum = a^b;

	//The partial sum is done, but now we have to add in the carry over bits
	//
	int carry = (a & b) << 1;

	return sum(partialSum, carry);
}

bool isAnagram(std::string &s1, std::string &s2){


	//Compare the size of the strings, if not equal then we do not have an anagram
	if(s1.length() != s2.length())
		return 0;


	//NOTE: Every int is initialized equal to zero
	std::unordered_map<char, int> myMap;

	//Populate the map using the first string
	for(int i = 0; i < s1.length(); i++)
	{
		//Make sure we are reading a lowercase character
		char ch = tolower(s1.at(i));
		//Add a to key to this character will be the number 1.
		myMap[ch] = myMap[ch] + 1;
	}

	//Now use the second string to determine if we have that character inside our map
	for(int j = 0; j < s2.length(); j++){
	
		//Make sure we are dealing with a lowercase character
		char theChar = tolower(s2.at(j));

		if(!myMap[theChar])
			return 0;
		else{
			//Reduce the given character by one
			myMap[theChar] = myMap[theChar] - 1;

			if(myMap[theChar] == -1)
				return 0;
		}


	}

	//If we reach here than we have an anagram
	return 1;

}


//Print out all the three sets that will give me the sum of zero
void threeSum(std::vector<int> & theVector){

	//Our vector must be sorted in order to solve this problem
	//In this case we will use the bubble sort method
	//We pass by reference and therefore our bubble sort function will modify the vector
	bubbleSort(theVector);
	
	//Our bubble sort function takes O(n^2) time. 
	//Our vector has been sorted and now we must solve the problem
	
	
	//Create a vector of vectors
	std::vector<std::vector<int>> theAnswerVector;

	for (int i = 0; i < theVector.size() - 3; i++ )
	{
		//Avoid the same element when traversing the vector
		//We need to make sure that the current element is larger than the previous element  
		if(i == 0 || theVector[i] > theVector[i-1])
		{
			//Now we need to keep track of our elements.
			//The start will be the next value indeces after i  
			//THe end will be the last value of our array.
			int start = i+1;
			int end = theVector.size() - 1;
			int sum = 0;

			while(start < end){
				
				sum = theVector[i]  + theVector[start] + theVector[end];
				
				
				//We have our three values and now check if we have a sum of zero
				if(sum == 0){
					//We found a solution set and store this vector of three into
					//the answer vector
					std::vector <int> oneSolution;

				       	oneSolution.push_back(theVector[i]);
				       	oneSolution.push_back(theVector[start]);
				       	oneSolution.push_back(theVector[end]);
					
					theAnswerVector.push_back(oneSolution);
				}

				//If we dont get a sum of zero
				//We must now move the start value or the end value
				

				//If the sum value is to low then move the start the right
				if( sum  < 0)
				{
				     //We must increment our start index, but we must avoid 
				     //case of having the same value after shifting to the right
				     //and remember we do not want to pass the end value
				     int currentStart = start;
				     while(theVector[currentStart] == theVector[start]  && start < end)
				     {
					++start;
				     } 

				}
				else{
				     //DO the same but now to the end index
				     int currentEnd = end;
				     while(theVector[currentEnd] == theVector[end] && start < end)
				     {
				     	--end;
				     }	
				}



			}
		
		
		}
	}

	

	//We have our vector with all the answers, so lets print out the sets of three that add to zero
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
}

void bubbleSort(std::vector<int> & vect){

	//For all the elements in the vector except the last two elements
	for(int i = 0; i < vect.size()-1; i++){
		//For all the elements in the vector except the last element
		for(int j = 0; j < vect.size() - 1; j++){
		
		
			//Start comparing the values and move the values accordingly
			if( vect[j] > vect[j+1])
			{
				int temp = vect[j];
				vect[j] = vect[j+1];
				vect[j+1] = temp;
			}

		}
	
		//Do this k-1 steps 
	}
	return;
}
