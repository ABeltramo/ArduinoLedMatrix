#ifndef STRCONVERTERCLASS_H_INCLUDED
#define STRCONVERTERCLASS_H_INCLUDED

#include <bitset>
#include <vector>
#include <map>
#include <string>
using namespace std;

class StrConverter{
      public:
        //*** VARIABILI
        //Numero di colonne occupate da ogni lettera
        const static int NCol = 5;
        //Numero di righe occupate da ogni lettera
        const static int NRig = 6;
        //Dimensioni dello schermo occupato
        const static int DimCarSchermo = NCol*NRig;
        //*** FUNZIONI
        //Costruttore crea l'alfabeto con le corrispondenze
        StrConverter(void);
        //Converte il carattere Chr in un bitset che contiene 5 righe concatenate
        string ChrToBin(char Chr);
        //Converte una stringa binaria in un vettore contenente righe e colonne
        void ChrToVet(char Bin,vector<string>::iterator Vet);
      private:
        //Alfabeto contenente ogni lettera il suo corrispondente 
        map<char, bitset<DimCarSchermo>* > Alfabeto;
};

#endif
