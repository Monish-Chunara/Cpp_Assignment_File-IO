//Program to store and search student's details in a file
//Monish Chunara - Shift I Track II

#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

void search(int);
bool NotText(string);

int main()
{
	int choice;
	int id;
	string name, branch, location;

	fstream file;
	
	try			//trying to open the file
	{
		file.open("database.txt", ios::app);
	
		if(file.fail())
		{
			throw 'e';
		}
	}

	catch(char e)
	{
		cout << "Database file could not be opened." << endl;
		return 0;
	}

	catch(...)
	{
			cout << "Unknown Exception occured while opening the file!" << endl;
			return 0;
	}
	
	do
	{
		cout << "\n*****Menu*****\n1. Enter student details\n2. Find student\n3. Exit\nChoice: ";
		cin >> choice;
		
		switch(choice)
		{
			case 1: try{
				cout << "\nEnter the student Id: ";
				cin >> id;
				
				cout << "Enter the student name: ";
				cin >> name;
				
				cout << "Enter the student branch: ";
				cin >> branch;
				
				cout << "Enter the student location: ";
				cin >> location;
				
				//checking for validation of data
				if(NotText(name) || NotText(branch) || NotText(location))
				{
					throw 2.5;
				}
				else
				{
					file << id << " ";
					file << name << " ";
					file << branch << " ";
					file << location << endl;
					cout << "\nStudent data recorded.\n" << endl;
				}
				}
				catch(double d)
				{
					cout << "\nName, Branch and Location cannot contain numbers and special characters!\n" << endl;
				}
				
				break;
			
			case 2: cout << "\nEnter the student id to search: " ;
				cin >> id;
				
				search(id);
				
				break;
			
			case 3:file.close();
				cout << "\nExiting...\n" << endl;
				break;
				
			default: cout << "Invalid choice" << endl;
		}
	}
	while(choice!=3);
	
	return 0;
}

void search(int query_id)
{
	int read_id;
	string str;
	bool flag = false;
	
	ifstream file;
	
	try		//trying to read the file
	{
		file.open("database.txt", ios::in);
		
		if(file.fail())
			throw -1;
	}
	catch(int i)
	{
		cout << "File could not be opened for reading." << endl;
		return;
	}
	catch(...)
	{
		cout << "Unknown exception occured while opening the file." << endl;
		return;
	}
	
	while(file >> read_id)
	{
		if(read_id == query_id)
		{
			flag = true;
			break;
		}
		getline(file, str);		//if id not matched, then skip that line
	}
	
	if(flag)
	{
			cout << "\n-------------------------" << endl;
			cout << "Student Details:" << endl;
			cout << "-------------------------" << endl;
			
			cout << "Id\t:\t" << read_id << endl;
			
			file >> str;
			cout << "Name\t:\t" << str << endl;
			
			file >> str;
			cout << "Branch\t:\t" << str << endl;
			
			file >> str;
			cout << "Location:\t" << str << endl;
			cout << "-------------------------" << endl;
			
	}
	else
	{
			cout << "Student with this id not found." << endl;
	}
	
	file.close();
}

bool NotText(string str)
{
	for(int i=0; i<str.length() ; i++)
	{
		if(!isalpha(str[i]))
			return true;
	}
	return false;
}
