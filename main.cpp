#include <iostream>
#include <vector>
#include <ctime>
#include <iterator>
#include <cmath>		//For abs()
#include <set>

//Function Prototypes
bool findInVector(std::vector<int> &theVector, int theValue);
bool findInSet(std::set<int> &theSet, int theValue);



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
	
	std::cout << "\n\n";
	std::vector<int> repeatedVector;







	//Solve by brute force O(n^2)
	//Simply compare the elements one by one
	int firstValue;
	for(int j = 0; j < myVector.size() - 2 ; j++ ){
		
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
	


	std::cout <<"\n\nWe will now use a better technique ot solve this problem.\n\n" << std::endl;

	//Be Clever and solve it in: O(n) time complexity and O(1) space complexity
	//We will the the markings by making values negative
	int theValue;
	std::set<int> checkSet;
	for(int r = 0; r < myVector.size(); r++ ){
	  
	  //Check if the value has already been found to be repeated

	  if(!findInSet( checkSet, myVector[r]) ){
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
	

	return 1;
}






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
