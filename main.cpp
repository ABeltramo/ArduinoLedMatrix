#include "writer/Writer.cpp"
#include <iostream>

using namespace std;

int main(){
    Writer Scrittore;
    while(true)
       Scrittore.BeginWrite("Ciao mi chiamo Alessandro ",50);
    system("PAUSE");
    return 0;   
}
