//Program to count the number of words that start with 'e'
//Monish Chunara - Shift I Track II

#include<iostream>
#include<fstream>

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
		if(str[0]=='e')
			count++;
	}
	cout << "\nNumber of words that starts with 'e' = " << count << endl << endl;

	
	file.close();
	
	return 0;
}
