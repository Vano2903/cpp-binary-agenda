#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct user
{
	string lastName;
	string name;
	string number;
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
		if (checkIfExist())
		{
			createFile();
		}
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

	void title()
	{
		cout << "agenda file binari - Vanoncini Davide"
	}

	int homeMenu()
	{
		string selectionS;
		cout << "seleziona un azione:" << endl;
		cout << "1] aggiungi contatto" << endl;
		cout << "2] cerca un contatto" << endl;
		cout << "3] visualizza la rubirca" << endl;
		cout << "4] modifica un contatto" << endl;
		cout << "5] elimina un contatto" << endl;
		cout << "6] esci dal programma" << endl;
	}
};

int main()
{
	agenda a("agenda.dat");
}
