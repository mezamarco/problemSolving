all: main thirdMain fourthMain fifthMain

fifthMain: fifthMain.cpp
	g++ fifthMain.cpp -o fifthMain

fourthMain: fourthMain.cpp
	g++ fourthMain.cpp -o fourthMain

thirdMain: thirdMain.cpp
	g++ thirdMain.cpp -o thirdMain


main: main.cpp
	g++ main.cpp -o main

clean:
	rm *.exe
