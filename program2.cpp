//Program to count the number of words that has 'a' in them
//Monish Chunara - Shift I Track II

#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

bool check(char * str)
{
	for(int i = 0; i < strlen(str) ; i++)
	{
		if(str[i] == 'a')
			return true;
	}
	
	return false;
}

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
		if(check(str))
			count++;
	}
	cout << "\nNumber of words that has 'a' in them = " << count << endl << endl;
	
	file.close();
	
	return 0;
}
