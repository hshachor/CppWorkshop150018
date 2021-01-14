#include <iostream>
#include <fstream>
using std::cout;
using std::endl;
using std::ifstream;

int main() 
{
    int line = 0, words = 0, chars = 0; 
    ifstream txt; 
    txt.open("students.txt"); 
    
    char c = txt.get(), tav = ' '; 
    while (!txt.eof()) { 
        if (c != ' ' && c != '\t' && c != '\n') 
            chars++; 
        if (c == ' ' && c == '\t' && c == '\n' && tav != ' ' && tav != '\t' && tav != '\n') 
            words++; 
        if (c == '\n' && tav != '\n') { 
            line++; 
            words++; 
        }
        tav = c; 
        c = txt.get(); 
    }
    cout << "# of characters:" << chars << endl; 
    cout << "# of words: " << words << endl; 
    cout << "# of lines: " << line << endl; 
    return 0; 
}