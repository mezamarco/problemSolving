
#include <iostream>
#include <unordered_map>
#include <string>
#include <iterator>
#include <ctime>
#include <vector>
#include <unordered_map>


//Function Prototype
void windowProblem(std::vector<int>& vect, int windowSize);

void reverseString(std::string & theString);




int main(){
	
	std::cout << "We will solve the Display the frequncy problem\n\n";


	std::cout << "Enter a word: ";
	std::string myWord;
	getline(std::cin, myWord);

	//We will use a hash map to solve this problem, therefore use a unordered map container
	std::unordered_map<char, int > myMap;

	//For all the characters in the string
	for(int i =  0; i < myWord.length(); i++)
	{
		char ch = myWord.at(i);

		std::cout << ch << std::endl;
		//Store the character into our map and incremement the character counter
		myMap[ch] =  myMap[ch] + 1;
		
	}

	//We will use an iterator to print our the characters and their frequencies
	

	std::unordered_map<char,int>::iterator itr = myMap.begin();
	std::unordered_map<char,int>::iterator itrEnd = myMap.end();

	while(itr != itrEnd){
		
		std::cout << "Character: " << itr->first << "\tFrequency: " << itr->second << "\n";
		++itr;
	
	}
	

	std::cout <<"\n\n\nWe will now solve the Count distinct elements in every window of size k";	
	

	srand(time(NULL));
	//Lets get a random array started, we will use a vector.
	std::cout << "\n\nWhat is the size you want for the array: ";
	int theSize;
	std::cin >> theSize;

	std::vector<int> theVect;

	std::cout << "\n\nThe vector:\n";
	//Create a vector with the given size , the random elements are between:(1 - 10).
	for(int m = 0 ; m < theSize;  m++){
		int random  = rand() % 10 + 1;
		std::cout << random << "  ";
		
		//Place the elements in the vector
		theVect.push_back(random);

	}


	//We will now solve the problem, Ask the user how big the windows should be.
	std::cout <<"\n\nHow large should the windows be: ";
	int windowSize;
	std::cin >> windowSize;

	//Now call the function to solve this problem
	windowProblem(theVect, windowSize);

	
	std::cout << "\n\n";
	
	std::cin.ignore();
	//We will now solve the reverse the string problem.
	std:: cout << "What string do you want us to reverse: ";
	std::string originalString;
	getline(std::cin, originalString);

	reverseString(originalString);

	std::cout << "\n\n";

	
	//We will now simulate a biased dice 

	// Get 1 is %10, Get 2 is %10, Get 3 is %10, Get 4 is %10, Get 5 is %10, Get 6 is %50
	
	std::cout << "We will now roll a biased dice 15 times:";
	for(int i = 0 ; i < 15 ; i++){
		
		//Random value range: [1-100]

		int randomVal = rand() % 100 + 1;

		std::cout << "Random value: "<<randomVal << ", ROLLING:   ";

		if(randomVal <= 10){
			std::cout << "1" << "\n"; 	
		}
		else if(randomVal <= 20){
			std::cout << "2" << "\n";
		}
		else if(randomVal <= 30){
			std::cout << "3" << "\n";
		}
		else if(randomVal <= 40){
			std::cout << "4" << "\n";
		}
		else if(randomVal <= 50){
			std::cout << "5" << "\n";
		}
		else{	
			std::cout << "6" << "\n";
		}

	}
	std::cout << "\n\nWe are done. Bye.\n\n";
	
	
	return 0;
}




void windowProblem(std::vector<int>& vect, int windowSize){
	
	//Determine how big our vector is,
	//If the windowSize is too large then print Invalid window size
	int vectSize = vect.size();
	
	std::unordered_map<int,int> myMap;

	if(vectSize < windowSize){
		std::cout << "\n\nInvalid input: The windows size is too large\n\n";
		return;

	}

	int distinctCounter;

	//Print the element for each window and then figure the distict elements.
	
	for(int i = 0 ; i <= vectSize - windowSize; i++){
		
		std::cout << "Window " << i+1 << " : ";	
		
		for(int j = i; j < windowSize+i; j++){
				
			int value = vect[j];
			std::cout << value << "  ";
			
			
			//If we do not have the element in our map, then pace it in our map.
			if(myMap.find(value) == myMap.end()){
			
				++distinctCounter;
				myMap[value] = myMap[value] + 1;
			}	


		}
/*
		//Check all the element in the map. If the second value is a 1 then it was seen only
		//one time

		//lets use an iterator to solve this problem
		

		std::unordered_map<int,int>:: iterator itr = myMap.begin();
		std::unordered_map<int,int>:: iterator itrEnd = myMap.end();

		while(itr != itrEnd)
		{
			if(itr ->second == 1){
				++distinctCounter;
			}
			++itr;
		}
*/		
		std::cout << "\t\tDistict Counter:  " << distinctCounter << "\n";


	
		//Clear the counter.
		distinctCounter=0;

		//Clear the map
		myMap.clear();
		
	
			

	}





}


void reverseString(std::string & theString){
	//Reverse the String 
	
	int stringSize = theString.length();

	std::string reversedString;

	for(int i = 0; i < stringSize ; i++)
	{
		reversedString = reversedString + theString.at(stringSize-1-i);
	}

	std::cout << "\nReverse the String:\n";

	std::cout << reversedString << "\n\n";
	return;
}
