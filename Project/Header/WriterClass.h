#ifndef WRITERCLASS_H_INCLUDED
#define WRITERCLASS_H_INCLUDED

#include "serial\SerialClass.h"
#include "strconverter\StrConverterClass.h"
#include <bitset>
#include <vector>
#include <windows.h>

class Writer{
      private:
         //Matrice contenente lo stato dello schermo
         const static int DimChr = 5; //Numero di colonne occupate da un singolo carattere
         const static int NumCol = 24; //Numero di colonne
         const static int NumRig = 6; //Numero di righe
         vector< bitset<NumRig> > Schermo; //Schermo[colonna][riga]
         void ShiftSchermo(void); //Shifto le righe dello schermo verso sinistra
         void AppendSchermo(vector<string>::iterator V); //Appende al fondo dello schermo il vettore passato in ingresso
      public:
         //Inizializza il vettore e resetta tutto lo schermo
         Writer(bool InitialState); //Stato iniziale: tutto acceso(true), tutto spento(false)
         Writer(); //In automatico tutto spento
         void SetSchermo(bool Val); //Setta lo schermo al valore inserito
         void BeginWrite(string Text,int Tempo); //Inizia a scrivere sullo schermo il testo Text
         string SchermoToString(void);
};

#endif
