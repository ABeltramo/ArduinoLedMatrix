#include "StrConverterClass.h"
#include <ctype.h>
#include <stdexcept>

StrConverter::StrConverter(void){
   //A-Z
   Alfabeto['a'] = new bitset<DimCarSchermo> (string("011101000110001111111000110001"));
   Alfabeto['b'] = new bitset<DimCarSchermo> (string("111101000111110100011000111110"));
   Alfabeto['c'] = new bitset<DimCarSchermo> (string("111111000010000100001000011111"));
   Alfabeto['d'] = new bitset<DimCarSchermo> (string("111101000110001100011000111110"));
   Alfabeto['e'] = new bitset<DimCarSchermo> (string("111111000011100100001000011111"));
   Alfabeto['f'] = new bitset<DimCarSchermo> (string("111111000011100100001000010000"));
   Alfabeto['g'] = new bitset<DimCarSchermo> (string("111111000010111100011000111111"));
   Alfabeto['h'] = new bitset<DimCarSchermo> (string("100011000111111100011000110001"));
   Alfabeto['i'] = new bitset<DimCarSchermo> (string("001000010000100001000010000100"));
   Alfabeto['l'] = new bitset<DimCarSchermo> (string("100001000010000100001000011111"));
   Alfabeto['m'] = new bitset<DimCarSchermo> (string("100011101110101100011000110001"));
   Alfabeto['n'] = new bitset<DimCarSchermo> (string("100011100110101100111000110001"));
   Alfabeto['o'] = new bitset<DimCarSchermo> (string("111111000110001100011000111111"));
   Alfabeto['p'] = new bitset<DimCarSchermo> (string("111101000110001111101000010000"));
   Alfabeto['q'] = new bitset<DimCarSchermo> (string("111101001010010101101001111110"));
   Alfabeto['r'] = new bitset<DimCarSchermo> (string("111101000110001111101000110001"));
   Alfabeto['s'] = new bitset<DimCarSchermo> (string("111111000011111000010000111111"));
   Alfabeto['t'] = new bitset<DimCarSchermo> (string("111110010000100001000010000100"));
   Alfabeto['u'] = new bitset<DimCarSchermo> (string("100011000110001100011000111111"));
   Alfabeto['v'] = new bitset<DimCarSchermo> (string("100011000110001100010101000100"));
   Alfabeto['z'] = new bitset<DimCarSchermo> (string("111110000100010001000100011111"));
   //Punteggiatura
   Alfabeto['!'] = new bitset<DimCarSchermo> (string("001000010000100001000000000100"));
   Alfabeto['?'] = new bitset<DimCarSchermo> (string("011100000100110001000000000100"));
   Alfabeto['.'] = new bitset<DimCarSchermo> (string("000000000000000000000000000100"));
   Alfabeto[':'] = new bitset<DimCarSchermo> (string("000000010000000000000010000000"));
   Alfabeto[';'] = new bitset<DimCarSchermo> (string("000000010000000000000010001000"));
   Alfabeto[','] = new bitset<DimCarSchermo> (string("000000000000000000000010001000"));
   Alfabeto[' '] = new bitset<DimCarSchermo> (string("000000000000000000000000000000"));
   //Operandi
   Alfabeto['+'] = new bitset<DimCarSchermo> (string("000000010000100111110010000100"));
   Alfabeto['-'] = new bitset<DimCarSchermo> (string("000000000000000011100000000000"));   
   Alfabeto['*'] = new bitset<DimCarSchermo> (string("000000000001010001000101000000"));
   Alfabeto['/'] = new bitset<DimCarSchermo> (string("000010001000100010001000000000"));
   Alfabeto['='] = new bitset<DimCarSchermo> (string("000000000001110000000111000000"));
   //Numeri
   Alfabeto['0'] = new bitset<DimCarSchermo> (string("111111000110001100011000111111"));
   Alfabeto['1'] = new bitset<DimCarSchermo> (string("001000110010100001000010011111"));
   Alfabeto['2'] = new bitset<DimCarSchermo> (string("011101000100010001000100011111"));   
   Alfabeto['3'] = new bitset<DimCarSchermo> (string("011101000100111000011000101110"));
   Alfabeto['4'] = new bitset<DimCarSchermo> (string("000100011001010111110001000010"));
   Alfabeto['5'] = new bitset<DimCarSchermo> (string("111111000011110000010000111110"));
   Alfabeto['6'] = new bitset<DimCarSchermo> (string("111111000011111100011000111111"));
   Alfabeto['7'] = new bitset<DimCarSchermo> (string("111110000100010001000100010000"));   
   Alfabeto['8'] = new bitset<DimCarSchermo> (string("011101000110001011101000101110"));
   Alfabeto['9'] = new bitset<DimCarSchermo> (string("011101000110001011110000101110"));
}

string StrConverter::ChrToBin(char Chr){
   //Ricerco all'interno del dizionario il carattere selezionato
   Chr = tolower(Chr); //Trasformo in minuscolo
   if(Alfabeto.count(Chr)>0)//Ricerco se è presente Chr tra le chiavi
      return (*Alfabeto[Chr]).to_string<char,char_traits<char>,allocator<char> >(); 
   else
      throw std::runtime_error("Il carattere: non e' stato trovato");                         
}

void StrConverter::ChrToVet(char Chr,vector<string>::iterator Vet){
   //Suddivido ogni riga da un altra
   try{
        string Bin = ChrToBin(Chr);
        for(int i=0;i<NRig;i++)
                *Vet++ = Bin.substr((i*NCol),NCol);
   }
   catch(exception & Err){
      throw std::runtime_error(Err.what()); 
   }
                         
}
