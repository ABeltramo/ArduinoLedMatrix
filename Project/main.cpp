#include "Header\WriterClass.h"
#include <iostream>
#include <stdexcept>

using namespace std;

int main(){
	try{
		Writer Scrittore(false);
		while(true)
		   Scrittore.BeginWrite("Ciao mi chiamo Alessandro ",50);
	}
	catch(exception & Err){
		cout << "Spiacenti un errore e' avvenuto." << endl << Err.what() << endl; 
   }
	system("PAUSE");
	return 0;   
}