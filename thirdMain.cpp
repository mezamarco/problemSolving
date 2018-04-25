#include <iostream>
#include <chrono>      //To determine te run time of a function

using namespace std::chrono;

//Function Prototypes


int fibSeq(int n);
int efficientFibSeq(int n);


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
