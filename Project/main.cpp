#include "Header\WriterClass.h"
#include <iostream>
#include <stdexcept>
#include <Windows.h>

using namespace std;

int main(){
	try{
		Serial Con("COM3");
		Writer Scrittore(false);
		while(true)
		   Scrittore.LoadTextFromFile("In.txt",Con);
	}
	catch(exception & Err){
		cout << "Spiacenti un errore e' avvenuto." << endl << Err.what() << endl; 
   }
	system("PAUSE");
	return 0;   
}