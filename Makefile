all: main secondMain thirdMain

thirdMain: thirdMain.cpp
	g++ thirdMain.cpp -o thirdMain

secondMain: secondMain.cpp
	g++ secondMain.cpp -o secondMain

main: main.cpp
	g++ main.cpp -o main

clean:
	rm *.exe
