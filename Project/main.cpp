#include "Header\WriterClass.h"
#include <iostream>

using namespace std;

int main(){
    Writer Scrittore(false);
    while(true)
       Scrittore.BeginWrite("Ciao mi chiamo Alessandro ",50);
    system("PAUSE");
    return 0;   
}