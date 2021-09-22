#include <iostream>
#include <fstream>
#include <string>
using namespace std;


class agenda{
	private:
		int numOfUsers; //number of users stored in the agenda
		string filePath; //path to binary file
		
		//check if file in filePath exist (true if it does, false if doesnt)
		bool checkIfExist(){
			ifstream ifile;
		    ifile.open(filePath.c_str());
		    if(ifile) return true;
			return false;
		}
		
		//create the file using filePath
		void createFile(){
			ofstream outfile(filePath.c_str());
			outfile.close();
		}
	public:
		//constructor
		agenda(string path){
			filePath = path;
		}
		
		//get the number of users in the agenda
		int getNumOfUsers(){
			
		}
			
			
};

int main(){
	agenda a("agenda.dat");
}
