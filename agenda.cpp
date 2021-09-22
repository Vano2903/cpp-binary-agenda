#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct user
{
	char lastName[20];
	char name[20];
	char number[15];
};

class agenda
{
private:
	int numOfUsers;	 //number of users stored in the agenda
	string filePath; //path to binary file

	//check if file in filePath exist (true if it does, false if doesnt)
	bool checkIfExist()
	{
		ifstream file;
		file.open(filePath.c_str());
		if (file)
			return true;
		return false;
	}

	//create the file using filePath
	void createFile()
	{
		ofstream file(filePath.c_str());
		file.close();
	}

	//get the number of users in the agenda
	int getNumOfUsers()
	{
	}

	void printUser(user u)
	{
		cout << "numero:  " << string(u.number) << endl;
		cout << "nome:    " << string(u.name) << endl;
		cout << "cognome: " << string(u.lastName) << endl;
	}

public:
	//constructor
	agenda(string path)
	{
		filePath = path;
	}

	void getUsers()
	{
		user u;
		for (int i = 0; i < numOfUsers; i++)
		{
		}
	}

	//write in append mode the user on the agenda file
	void writeUser(user u)
	{
		fstream file(filePath.c_str(), ios::app | ios::binary);
		file.write((char *)&u, sizeof(user));
		file.close();
	}
};

int main()
{
	agenda a("agenda.dat");
}
