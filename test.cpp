#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
using namespace std;

struct user {
    char lastName[20];
    char name[20];
    char number[12];
};

// struct user {
//     string lastName;
//     string name;
//     string number;
// };

//print the user in a formatted way
void printUser(user u) {
    cout << "numero:  " << string(u.number) << endl;
    cout << "nome:    " << string(u.name) << endl;
    cout << "cognome: " << string(u.lastName) << endl;
}

void saveUser(user u){
    fstream file("test.dat", ios::app | ios::binary);
    file.write((char*) &u, sizeof(user));
    file.close();
}

user getUser(int index){
    user a;
    fstream fileBinario("test.dat", ios::in|ios::binary); //apre il file binario in LETTURA
    fileBinario.seekg(((index)*sizeof(user))+ sizeof(int) , ios::beg); //+ sizeof(int
    fileBinario.read((char*) &a, sizeof(user)); //memorizza i 4 byte (del numero intero) letti dal file binario nella variabile n
    fileBinario.close();
    return a;
}

void saveNumberOfUsers(int numUsers){
    fstream file("test.dat", ios::out | ios::binary);
    file.seekg(0, ios::beg);
    file.write((char*) &numUsers, sizeof(int));
    file.close();
}

int getNumOfUsers(){
    int numUsers = 0;
    fstream file("test.dat", ios::in | ios::binary);
    file.seekg(0, ios::beg);
    file.read((char*) &numUsers, sizeof(int));
    file.close();
    return numUsers;
}

int main(){
    user u[3];

    strncpy(u[0].name, "vano", sizeof(u[0].name - 1));
    strncpy(u[0].lastName, "vano", sizeof(u[0].lastName - 1));
    strncpy(u[0].number, "vano", sizeof(u[0].number - 1));

    strncpy(u[1].name, "vano", sizeof(u[1].name - 1));
    strncpy(u[1].lastName, "vanaa", sizeof(u[1].lastName - 1));
    strncpy(u[1].number, "2dfsdf", sizeof(u[1].number - 1));

    strncpy(u[2].name, "vano", sizeof(u[2].name - 1));
    strncpy(u[2].lastName, "vano", sizeof(u[2].lastName - 1));
    strncpy(u[2].number, "3333", sizeof(u[2].number - 1));

    

    saveNumberOfUsers(3);
    cout << "num of users: " << getNumOfUsers() << endl;


saveUser(u[0]);
    saveUser(u[1]);
    saveUser(u[2]);

    printUser(getUser(1));
    

        saveNumberOfUsers(4);
    cout << "num of users: " << getNumOfUsers() << endl;


    printUser(getUser(1));
    return 0;
}