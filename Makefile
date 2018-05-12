all: main secondMain thirdMain fourthMain fifthMain

fifthMain: fifthMain.cpp
	g++ fifthMain.cpp -o fifthMain

fourthMain: fourthMain.cpp
	g++ fourthMain.cpp -o fourthMain

thirdMain: thirdMain.cpp
	g++ thirdMain.cpp -o thirdMain

secondMain: secondMain.cpp
	g++ secondMain.cpp -o secondMain

main: main.cpp
	g++ main.cpp -o main

clean:
	rm *.exe
