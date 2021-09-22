#include <iostream>
#include <fstream>
#include <string>
using namespace std;


class agenda{
	private:
		int numOfUsers;
		
		string filePath  = "agenda.txt";
		
	public:
//		agenda(string path){
//			filePath = path;
//		}
		void createFile(){
			ofstream outfile ("ciao.txt");
			outfile << "my text here!" << endl;
			outfile.close();
		}
		bool checkIfExist(){
			ifstream ifile;
		    ifile.open((char*) &filePath);
		    if(ifile) {
		   		cout << "trovato";
		   		return true;
		    } 
		    cout << "non trovato";
			return false;
		}
		
		int getNumOfUsers(){
			
		}
			
};

int main(){
	agenda a; //("agenda.txt")
	a.createFile();
	cout << a.checkIfExist();
//cout << __cplusplus;
}
