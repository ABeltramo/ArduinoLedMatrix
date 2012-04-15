Writer.h (c++)
==========

Classe creata appositamente per scrivere su una matrice di led collegata ad una scheda Arduino.
Il progetto &egrave; composto da 3 principali classi:
SerialClass.h -> &egrave; la classe più bassa crea una connessione con la board Arduino.
StrConverterClass.h -> Crea una mappa di ogni carattere e la sua relativa conversione in binario (led acceso o spento).
WriterClass.h -> Utilizzando le due classi precedenti scrive a scorrimento una stringa fornita in input.

WriterClass.h
------
	 Writer(bool InitialState); //Stato iniziale: tutto acceso(true), tutto spento(false)
         Writer(); //In automatico tutto spento
         void SetSchermo(bool Val); //Setta lo schermo al valore inserito
         void BeginWrite(string Text,int Tempo); //Inizia a scrivere sullo schermo il testo Text
         string SchermoToString(void); //Restituisce una stringa contenente lo schermo


Licenza
-------
Copyright (C) 2012  Alessandro Beltramo <beltramo.ale@gmail.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see http://www.gnu.org/licenses/.