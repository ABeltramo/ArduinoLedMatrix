#include "WriterClass.h"
#include <stdexcept>


/*
* PRIVATE
*/
void Writer::ShiftSchermo(void){
     for(int i=1;i<NumCol+DimChr;i++) //Scorro la matrice dalla prima riga fino all'ultima
        for(int j=0;j<NumRig;j++) //Copio la riga i nella riga i-1
           Schermo[i-1][j] = Schermo[i][j]; //Copio nella casella precedente la i esima casella
     //L'ultima riga la metto a 0
     Schermo[NumCol+DimChr-1].reset();
}

void Writer::AppendSchermo(vector<string>::iterator V){
    int j;
    string app;
    for(int i=0;i<NumRig;i++) //Per ogni riga
        for(j=0;j<DimChr;j++) //Appendo al termine dello schermo il vettore passato in ingresso 
            if(V[i][j] == '1') 
                      Schermo[NumCol+j][i] = 1;
            else
                      Schermo[NumCol+j][i] = 0;
}
/*
* PUBLIC
*/

Writer::Writer(bool InitialState){
     Schermo.resize(NumCol+DimChr); //Dichiaro 24 bitset all'interno dello schermo (righe)
     SetSchermo(InitialState); //Inizializzo spegnendo lo schermo                   
}

Writer::Writer(void){
     Writer(false);                
}

Writer::~Writer(){
	Schermo.clear(); //Svuoto il vettore
}

void Writer::SetSchermo(bool Val){
     if (Val){
        for(int i=0;i<NumCol+DimChr;i++) //Setto tutti i bitset
             Schermo[i].set();     
     }
     else{
        for(int i=0;i<NumCol+DimChr;i++) //Resetto tutti i bitset
             Schermo[i].reset();  
     }    
}

string Writer::SchermoToString(void){
     string Ris;
     for(int i=0;i<NumRig;i++){ //Per ogni riga
         for(int j=0;j<NumCol;j++) //per ogni colonna tranne quelle aggiuntive
            if(Schermo[j][i]) //Se il bitset è su true
               Ris.push_back('1');
            else
               Ris.push_back('0');
         //Ris.push_back('\n'); //Manda a capo dopo ogni riga (SOLO PER VISUALIZZARE!)
     }
     return Ris; //Restituisco la stringa
}

string Writer::SchermoToStringHuman(void){
     string Ris;
     for(int i=0;i<NumRig;i++){ //Per ogni riga
         for(int j=0;j<NumCol;j++) //per ogni colonna tranne quelle aggiuntive
            if(Schermo[j][i]) //Se il bitset è su true
               Ris.push_back('1');
            else
               Ris.push_back(' ');
         Ris.push_back('\n'); //Manda a capo dopo ogni riga (SOLO PER VISUALIZZARE!)
     }
     return Ris; //Restituisco la stringa
}

bool Writer::BeginWrite(string Text,int Tempo,Serial &Connection){
	try{
		 //Serial Connection("COM3");
		 StrConverter Convertitore; //Converte un carattere in un vettore di stringhe (01...)
		 vector< bitset<DimChr> > Carattere(NumRig); //Matrice alla i esima riga contiene il valore delle colonne per quel carattere
		 vector<string> RisultatoConversione(NumRig); //Stringhe risultanti dal testo inserito
		 for(int i=0;i<(int)Text.length();i++){ //Passo ogni carattere del testo inserito in input
			Convertitore.ChrToVet(Text[i],RisultatoConversione.begin()); //Salvo in RisultatoConversione le varie stringhe che corrispondono a Text[i]
			AppendSchermo(RisultatoConversione.begin()); // Aggiungo in fondo allo schermo il nuovo carattere
			for(int k=0;k<=DimChr;k++){ //Eseguo DimChr+1 shift in modo da far comparire il carattere
			   ShiftSchermo(); 
			   /* Togliere i commenti per visualizzare sullo schermo la matrice
			   system("CLS");
			   cout << SchermoToString() << endl;
			   */
			   system("CLS");
			   cout << SchermoToStringHuman() << " ";
			   Connection.Write("2"+SchermoToString());
			   Sleep(Tempo);
			}
		 }
		 return true;
	}
	catch(exception & Err){
		throw std::runtime_error(Err.what()); 
		return false;
	}
}

bool Writer::LoadTextFromFile(string Path,Serial &Connection){
	string Linea;
	string Tempo;
	ifstream File;
	File.open(Path); //Apro il file
	if (!File.is_open()){ //Errore nell'apertura del file
		throw std::runtime_error("Non è stato possibile aprire il file in input");
		return false;
	}
	getline (File,Tempo); //Leggo la linea e la salvo in Linea
	while ( File.good() ){
      getline (File,Linea); //Leggo la linea e la salvo in Linea
	  BeginWrite(Linea+" ",atoi(Tempo.c_str()),Connection); //Invio la linea alla scheda Arduino
    }
    File.close(); //Chiudo il file
	return true;
}

