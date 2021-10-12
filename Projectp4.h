#ifndef PROJECTP4_H
#define PROJECTP4_H

class Sort
{
private:
	int size;
	fstream inputFile;
	fstream outputFile;
	//Declaring struct SortNames
	struct SortNames
	{
		string names;
		string position;
		string age;
	};
	SortNames* playerBatting;
public:
	Sort();
	void readNameFile();
	int partition(SortNames*, int, int);
	void quickSort(SortNames*, int, int);
	int binarySearch(SortNames*, int, string);
	void displayNameFile();
};

#endif