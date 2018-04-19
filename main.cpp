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
	//Make a copy of this original vector
	std::vector<int> myVectorTwo = myVector;

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
