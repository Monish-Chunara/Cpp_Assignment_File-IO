//Program to count the number of times the word 'the' is present in the file
//Monish Chunara - Shift I Track II

#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;


int main()
{
	char str[20];
	
	ifstream file;
	try			//trying to open the file
	{
		file.open("file.txt");
		
		if(file.fail())
			throw 'e';
	}
	catch(char e)
	{
			cout << "File could not be opened" << endl;
			return 0;
	}
	catch(...)
	{
			cout << "Unknown Exception occured while opening the file!" << endl;
			return 0;
	}
	int count = 0;
	while(file >> str)
	{
		if(!strcmp(str, "the"))
			count++;
	}
	cout << "\nNumber of times 'the' is present in the file = " << count << endl << endl;
	
	file.close();
	
	return 0;
}
