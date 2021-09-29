#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct user {
    string lastName;
    string name;
    string number;
};

class addrBook {
private:
    int numOfUsers;  //number of users stored in the addrBook
    string filePath; //path to binary file

    //check if file in filePath exist (true if it does, false if doesnt)
    bool checkIfExist(){
        ifstream file;
        file.open(filePath.c_str());
        if (file)
            return true;
        return false;
    }

	bool createFile(){
		fstream file(filePath.c_str(), ios::out);
		if (file.fail())
			return false;
		file.close();
		return true;
	}

    //get the number of users in the addrBook
    int getNumOfUsers() {
        return 0;
    }

    //print the user in a formatted way
    void printUser(user u) {
        cout << "numero:  " << u.number << endl;
        cout << "nome:    " << u.name << endl;
        cout << "cognome: " << u.lastName << endl;
    }

    //clear the terminal
    void clear() {
        int ret_val = system("cls");
        if (!(ret_val == 0))
        {
            system("clear");
        }
    }

    //promt the title of the application
    void title() {
        cout << "addrBook file binari - Vanoncini Davide" << endl;
    }

    //write in append mode the user on the addrBook file
    //! dont write in append, check the "white spots" in the file from previous users
    bool writeUser(user u) {
        fstream file(filePath.c_str(), ios::app | ios::binary);
        if (file.fail())
        {
            return false;
        }
        file.write((char*) &u, sizeof(user));
        file.close();
        return true;
    }

public:
    //constructor
    addrBook(string path) {
        filePath = path;
        if (checkIfExist())
            if (!createFile())
            {
                cout << "file not created, error occurred";
                exit(1);
            }
    }

    //promt on console all the possible functions the user can select,
    //if showTitle is true the function will promt the title of the application
    int homeMenu(bool showTitle) {
        string selectionS = "";
        bool repeat = false;
        do {
            clear();
            if (repeat)
                cout << "puoi selezionare solo 1,2,3,4,5,6." << endl;
            else {
                if (showTitle)
                    title();
                cout << "seleziona un azione:" << endl;
            }
            cout << "1] aggiungi contatto" << endl;
            cout << "2] cerca un contatto" << endl;
            cout << "3] visualizza la rubrica" << endl;
            cout << "4] modifica un contatto" << endl;
            cout << "5] elimina un contatto" << endl;
            cout << "6] esci dal programma" << endl;
            getline(cin, selectionS);
            repeat = true;
        } while (selectionS != "1" && selectionS != "2" && selectionS != "3" && selectionS != "4" && selectionS != "5" && selectionS != "6");
        return stoi(selectionS);
    }

    //print all the users in the addrBook
    void functionHandler(int selected) {
        if (selected < 1 || selected > 6)
            return;
        switch (selected)
        {
        case 1:
            addUser();
        case 2:
            // searchUser();
			printUser(getUser(1));
        case 3:
            printUsers();
        case 4:
            // updateUser();
        case 5:
            // deleteUser();
        case 6:
            exit(1);
        }
    }

    void printUsers() {
        user u;
        fstream file(filePath.c_str(), ios::in | ios::binary); //apre il file binario in LETTURA
        if(!file) {
            cout << "Cannot open file!" << endl;
            return;
        }
        while (file.good()) {
            file.read((char *)&u, sizeof(user));
            printUser(u);
        }
    }

	user getUser(int index){
		user u;
    	fstream file(filePath.c_str(), ios::in|ios::binary); //apre il file binario in LETTURA
		file.seekg((index-1)*sizeof(user), ios::beg);
		file.read((char*) &u, sizeof(user)); //memorizza i 4 byte (del numero intero) letti dal file binario nella variabile n
		printUser(u);
		return u;
	}

    //get user's info and add the user to the file
    bool addUser() {
        user u;
        clear();
		cout << "AGGIUNGI UN NUOVO UTENTE" << endl;
		cout << "nome (max 20 caratteri)               > ";
		cin >> u.name;
		cout << "cognome (max 20 caratteri)            > ";
		cin >> u.lastName;
		cout << "numero di telefono (max 12 caratteri) > ";
		cin >> u.number;

        if (writeUser(u)) {
            cout << "added successfully" << endl;
            return false;
        }
        cout << "error adding to file" << endl;
        return true;
    }
};

int main()
{
    addrBook a("rubrica.dat");
    do
    {
        int selected = a.homeMenu(true);
        a.functionHandler(selected);
    } while (true);
}