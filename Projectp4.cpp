#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <chrono>
#include <cstdlib>
#include "windows.h"
#include "Project.h"
#include "Projectp2.h"
#include "Projectp3.h"
#include "Projectp4.h"
using namespace std;

Sort::Sort()
{
	size = 0;
	string numbers;
	inputFile.open("dodgersNames.txt", ios::in);


	while (!inputFile.eof())
	{
		getline(inputFile, numbers);
		size++;
	}
	size = size / 3;
	playerBatting = new SortNames[size];
	inputFile.close();
	readNameFile();
}

void Sort::readNameFile()
{
	inputFile.open("dodgersNames.txt", ios::in);
	for (int count = 0; count < size; count++)
	{
		getline(inputFile, playerBatting[count].names);
		inputFile >> playerBatting[count].position;
		inputFile >> playerBatting[count].age;
		inputFile.ignore();
	}
	inputFile.close();
}

//Part of Quicksort Algorithm
int Sort::partition(SortNames* playerArray, int startIndex, int endIndex)
{
	int midpoint = startIndex + (endIndex - startIndex) / 2;
	string pivot = playerArray[midpoint].names;

	int low = startIndex;
	int high = endIndex;

	bool done = false;
	while (!done)
	{
		while (playerArray[low].names < pivot)
		{
			low = low + 1;
		}

	while (pivot < playerArray[high].names)
	{
		high = high - 1;
	}

	if (low >= high)
	{
		done = true;
	}
	else
	{
		string temp = playerArray[low].names;
		playerArray[low].names = playerArray[high].names;
		playerArray[high].names = temp;
		low = low + 1;
		high = high - 1;
	}
	}
	return high;
}

//Part of Quicksort Algorithm
void Sort::quickSort(SortNames* playerArray, int startIndex, int endIndex)
{
	if (endIndex <= startIndex) 
	{
		return;
	}

	int high = partition(playerArray, startIndex, endIndex);
	
	quickSort(playerArray, startIndex, high);
	quickSort(playerArray, high + 1, endIndex);


}

//Binary Search Algorithm
int Sort::binarySearch(SortNames* searchArray, int namesSize, string key)
{
	int mid = 0;
	int low = 0;
	int high = namesSize - 1;

	while (high >= low)
	{
		mid = (high + low) / 2;

		if (searchArray[mid].names < key)
		{
			low = mid + 1;
		}
		else if (searchArray[mid].names > key) 
		{
			high = mid - 1;
		}
		else 
		{
			return mid;
		}
	}
}

void Sort::displayNameFile()
{
	int choice, nameChoice, key;
	string playerName;
	long int before;
	long int after;

	cout << "Would you like to view the Dodgers in Ascending order? Enter 0 if no, Enter 1 if yes. ";
	cin >> choice;

	while (choice < 0 || choice > 1)
	{
		cout << "Enter the value 1 or 0" << endl;
		cin >> choice;
	}
	if (choice == 1)
	{
		before = GetTickCount();
		quickSort(playerBatting, 0, size -1);
		after = GetTickCount();
		
		cout << setprecision(2) << fixed << showpoint;
		for (int count = 0; count < size; count++)
		{
			cout << "Name: " << playerBatting[count].names << endl;
			cout << "Position: " << playerBatting[count].position << endl;
			cout << "Age: " << playerBatting[count].age << endl;
		}
		cout << "Getting tick count before QuickSort: " << before << endl;
		cout << "Getting tick count after QuickSort: " << after << endl;
	}

	cout << "Would you like to view a particular Dodger player? Enter 0 if no, Enter 1 if yes. ";
	cin >> nameChoice;

	while (nameChoice < 0 || nameChoice > 1)
	{
		cout << "Enter the value 1 or 0" << endl;
		cin >> choice;
	}
	if (nameChoice == 1)
	{
		cin.ignore();
		cout << "Please enter one of the players Full Name: ";
		getline(cin, playerName);

		before = GetTickCount();
		int key = binarySearch(playerBatting, size, playerName);
		after = GetTickCount();

		cout << playerBatting[key].names << endl;
		cout << playerBatting[key].position << endl;
		cout << playerBatting[key].age << endl;
		cout << "Getting tick count before Binary Search: " << before << endl;
		cout << "Getting tick count after Binary Serach: " << after << endl;
	}

}