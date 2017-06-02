#include <iostream>
#include "Chapter8Problems.h"
#include <vector>
#include <string>

int main() {

	/* The functions below are personal coding solutions to the programming exercises in Chapter 8 - Searching and Sorting Arrays from the textbook
	"Starting out with C++: From Control Structurs through Objects (8th Edition)" - By Tony Gaddis. 

	To test a different function, simply replace the function name on line 14 to whichever one you desire */

	chapter8Problems *p1 = new chapter8Problems();
	p1->searchBenchmarks();
	system("pause");
	return 0;
}

void chapter8Problems::accountValidation() {

	//Using linear search to validate an account number

	int bankAccount[] = { 5658845, 4520125, 7895122, 8777541, 8451277, 1302850, 8080152, 4562555, 5552012, 5050552, 7825877,1250255, 1005231, 6545231, 3852085, 7576651, 7881200, 4581002 };
	int index = 0;
	int userInput;
	int position = -1;
	bool found = false;

	//Ask user for input
	std::cout << "Please enter a seven-digit account number: ";
	std::cin >> userInput;

	//Input validation: Numbers must be 7 digits
	while (userInput < 1000000 || userInput > 9999999) {
		std::cout << "Account numbers can only contain 7 digits. Try again. " << std::endl;
		std::cin >> userInput;
	}

	//Linear Search Algorithm
	while (index < 18 && !found) {
		if (bankAccount[index] == userInput) {
			found = true;
			position = index;
		}
		index++;
	}

	//Confirm whether or not the user input is a valid account number
	if (position == -1)
		std::cout << "The account number you have entered is invalid." << std::endl;
	else
		std::cout << "The account number you have entered is valid!" << std::endl;
}

void chapter8Problems::lotteryWinners() {

	//This program uses linear search to see if the user entered the winning lottery numbers

	std::vector<int> lotteryNum { 13579, 26791, 26792, 33445, 55555, 62483, 77777, 79422, 85647, 93121 };
	int index = 0;
	int userInput;
	int position = -1;
	bool found = false;

	//Ask user for input
	std::cout << "Please enter a five-digit lottery ticket: ";
	std::cin >> userInput;

	//Input validation: Numbers must be 5 digits
	while (userInput < 10000 || userInput > 99999) {
		std::cout << "Lottery tickets can only contain 5 digits. Try again. " << std::endl;
		std::cin >> userInput;
	}

	//Linear Search Algorithm
	while (index < 10 && !found) {
		if (lotteryNum[index] == userInput) {
			found = true;
			position = index;
		}
		index++;
	}

	//Confirm whether or not the user input is a valid lottery number
	if (position == -1)
		std::cout << "The lottery number you have entered are not the winning lottery numbers." << std::endl;
	else
		std::cout << "Congratulations! You are the grand prize winner! The winning lottery numbers are: " << lotteryNum[position] << std::endl;
}

void chapter8Problems::lotteryBinary() {

	//This program uses binary search

	int lotteryNum[] = { 13579, 26791, 26792, 33445, 55555, 62483, 77777, 79422, 85647, 93121};
	int numElem = 10;
	int first = 0, last = numElem - 1, middle, position = -1;
	int userInput;
	bool found = false;

	//Ask user for input
	std::cout << "Please enter a five-digit lottery ticket: ";
	std::cin >> userInput;

	//Input validation: Numbers must be 7 digits
	while (userInput < 10000 || userInput > 99999) {
		std::cout << "Account numbers can only contain 5 digits. Try again. " << std::endl;
		std::cin >> userInput;
	}

	//Binary Search Algorithm
	while (!found && first <= last) {
		middle = (first + last) / 2;
		if (lotteryNum[middle] == userInput) {
			found = true;
			position = middle;
		}
		else if (lotteryNum[middle] > userInput)
			last = middle - 1;
		else
			first = middle + 1;
	}

	//Confirm whether or not the user input is a valid account number
	if (position == -1)
		std::cout << "Your lottery number tickets numbers are not the winning numbers." << std::endl;
	else
		std::cout << "Congratulations! You are the grand prize winner! The winning lottery numbers are: " << lotteryNum[position] << std::endl;
}

void chapter8Problems::accountSelection() {

	//Uses selection sort to sort array before using binary search algorithm (ASSUMING ALL VALUES ARE DIFFERENT)

	int bankAccount[] = { 5658845, 4520125, 7895122, 8777541, 8451277, 1302850, 8080152, 4562555, 5552012, 5050552, 7825877,1250255, 1005231, 6545231, 3852085, 7576651, 7881200, 4581002 };
	int startScan, minIndex, minValue, size = 18;
	int userInput;
	int first = 0, last = size - 1, middle, position = -1;
	bool found = false;

	//Ask user for input
	std::cout << "Please enter a seven-digit account number: ";
	std::cin >> userInput;

	//Input validation: Numbers must be 7 digits
	while (userInput < 1000000 || userInput > 9999999) {
		std::cout << "Account numbers can only contain 7 digits. Try again. " << std::endl;
		std::cin >> userInput;
	}

	//Selection sort to sort array elements in order
	for (startScan = 0; startScan < (size - 1); startScan++) {
		minIndex = startScan;
		minValue = bankAccount[startScan];
		for (int index = startScan + 1; index < size; index++) {
			if (bankAccount[index] < minValue) {
				minValue = bankAccount[index];
				minIndex = index;
			}
		}
		bankAccount[minIndex] = bankAccount[startScan];
		bankAccount[startScan] = minValue;
	}

	//Use binary search to validate the user's input
	while (!found && first <= last) {
		middle = (first + last) / 2;
		if (bankAccount[middle] == userInput) {
			found = true;
			position = middle;
		}
		else if (bankAccount[middle] > userInput)
			last = middle - 1;
		else
			first = middle + 1;
	}
	
	//Confirm whether or not the user input is a valid account number
	if (position == -1)
		std::cout << "The account number you have entered is invalid." << std::endl;
	else
		std::cout << "The account number you have entered is valid!" << std::endl;
}

void chapter8Problems::rainfallMod() {

	//Modify the Rainfall Statistics Program in Chapter 7 to sort the 12 months in order of rainfall from highest to lowest

	double rainfall[12];
	double rainfallDup[12];
	double totalRainfall = 0;

	//Receive user input and calculates total rainfall for the year
	for (int i = 1; i < 13; i++) {
		std::cout << "Please enter the total rainfall for month " << i << ": ";
		std::cin >> rainfall[i - 1];

		//Input Validation: Values cannot be negative
		while (rainfall[i - 1] < 0) {
			std::cout << "Value cannot be negative. Try again." << std::endl;
			std::cin >> rainfall[i - 1];
		}
	}

	//Create a duplicate array of rainfall for future comparison
	for (int i = 1; i < 13; i++) {
		rainfallDup[i - 1] = rainfall[i - 1];
	}

	//Use bubble sort to sort rainfall array in descending order
	bool swap;
	double temp;
	int size = 12;

	do {
		swap = false;
		for (int count = 0; count < (size - 1); count++) {
			if (rainfall[count] < rainfall[count + 1]) {
				temp = rainfall[count];
				rainfall[count] = rainfall[count + 1];
				rainfall[count + 1] = temp;
				swap = true;
			}
		}
	} while (swap);

	//Compare duplicate array and sorted array to determine the order from highest to lowest of rainfall from each month (**check for output when user inputs duplicate values!**)
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
			int month = j + 1;
			if (rainfall[i] == rainfallDup[j]) {
				std::cout << "Month " << month << ": " << rainfall[i] << std::endl;
			}
		}
	}
}

void chapter8Problems::stringSelectionSort() {
	
	//This program will use selection sort to sort an array of strings

	const int NUM_NAMES = 20;
	int startScan, minIndex, size = 20;
	std::string minValue;
	std::string names[20] = { "Collins, Bill", "Smith, Bart", "Allen, Jim", "Griffin, Jim", "Stamey, Marty", "Rose, Geri",
							   "Taylor, Terri", "Johnson, Jill", "Allison, Jeff", "Looney, Joe", "Wolfe, Bill", "James, Jean",
							   "Weaver, Jim", "Pore, Bob", "Rutherford, Greg", "Javens, Renee", "Harrison, Rose", "Setzer, Cathy", "Pike, Gordon",
							   "Holland, Beth" };

	//Selection sort to sort array elements in order
	for (startScan = 0; startScan < (size - 1); startScan++) {
		minIndex = startScan;
		minValue = names[startScan];
		for (int index = startScan + 1; index < size; index++) {
			if (names[index] < minValue) {
				minValue = names[index];
				minIndex = index;
			}
		}
		names[minIndex] = names[startScan];
		names[startScan] = minValue;
	}

	//Display the sorted array
	for (int i = 0; i < size; i++)
		std::cout << names[i] << std::endl;
}

void chapter8Problems::binaryStringSearch() {

	//This program will use binary search in an array of strings

	const int NUM_NAMES = 20;
	int startScan, minIndex, size = 20;
	int first = 0, last = size - 1, middle, position = -1;
	bool found = false;
	
	std::string minValue, userInput;
	std::string names[20] = { "Collins, Bill", "Smith, Bart", "Allen, Jim", "Griffin, Jim", "Stamey, Marty", "Rose, Geri",
		"Taylor, Terri", "Johnson, Jill", "Allison, Jeff", "Looney, Joe", "Wolfe, Bill", "James, Jean",
		"Weaver, Jim", "Pore, Bob", "Rutherford, Greg", "Javens, Renee", "Harrison, Rose", "Setzer, Cathy", "Pike, Gordon",
		"Holland, Beth" };

	//Ask user for name input
	std::cout << "Please enter a name to find in the form of: last name, first name" << std::endl;
	getline(std::cin, userInput);

	//Selection sort to sort array elements in order
	for (startScan = 0; startScan < (size - 1); startScan++) {
		minIndex = startScan;
		minValue = names[startScan];
		for (int index = startScan + 1; index < size; index++) {
			if (names[index] < minValue) {
				minValue = names[index];
				minIndex = index;
			}
		}
		names[minIndex] = names[startScan];
		names[startScan] = minValue;
	}

	//Use binary search to validate the user's input
	while (!found && first <= last) {
		middle = (first + last) / 2;
		if (names[middle] == userInput) {
			found = true;
			position = middle;
		}
		else if (names[middle] > userInput)
			last = middle - 1;
		else
			first = middle + 1;
	}

	//Confirm whether or not the name entered was found in the array
	if (position == -1)
		std::cout << "The name you have entered was not found." << std::endl;
	else
		std::cout << "The name you have entered is valid!" << std::endl;
}

void chapter8Problems::searchBenchmarks() {

	//This program will keep a count of the number of comparisons that both linear search and binary search make in an array of 20 integers

	const int size = 20;
	int numbers[size] = { 2,9,1,3,0,8,7,11,6,5,39,29,27,40,58,31,39,20,25,10 };
	int index = 0, userInput, position = -1;
	int linearComparison = 0;
	bool found = false;

	//Ask user for input
	std::cout << "Please enter an integer to find: ";
	std::cin >> userInput;

	//Linear Search Algorithm
	while (index < size && !found) {
		if (numbers[index] == userInput) {
			found = true;
			position = index;
			linearComparison++;
		}
		else
			linearComparison++;
		index++;
	}

	//Selection Sort to organize the array in order before beginning the Binary Search
	int startScan, minIndex, minValue;
	for (startScan = 0; startScan < (size - 1); startScan++) {
		minIndex = startScan;
		minValue = numbers[startScan];
		for (int index = startScan + 1; index < size; index++) {
			if (numbers[index] < minValue) {
				minValue = numbers[index];
				minIndex = index;
			}
		}
		numbers[minIndex] = numbers[startScan];
		numbers[startScan] = minValue;
	}

	//Binary Search Algorithm
	int first = 0, last = size - 1, middle, position2 = -1, binaryComparison = 0;
	bool found2 = false;
	while (!found2 && first <= last) {
		middle = (first + last) / 2;
		if (numbers[middle] == userInput) {
			found2 = true;
			position2 = middle;
			binaryComparison++;
		}
		else if (numbers[middle] > userInput) {
			last = middle - 1;
			binaryComparison++;
		}
		else {
			first = middle + 1;
			binaryComparison++;
		}
	}

	//Return number of comparisons for each search algorithm
	std::cout << "Amount of comparisons using linear search: " << linearComparison << std::endl;
	std::cout << "Amount of comparisons using binary search: " << binaryComparison << std::endl;

	//Confirm whether or not the user's input was found
	if (position == -1)
		std::cout << "The value you have inputted was not found: " << userInput << std::endl;
	else
		std::cout << "The value you have inputted was found: " << userInput << std::endl;
}

chapter8Problems::chapter8Problems() {
}