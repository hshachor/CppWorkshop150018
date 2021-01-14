#include <iostream>
using namespace std;
#include <fstream>
#include "ClientData.h"

int main()
{	// Create credit file
    try
    {
        ofstream createFile("credit.dat");
        if (!createFile)
            throw "File could not be created.\n";
        ClientData client;  // Empty record
        for (int i = 0; i < 100; i++)
            createFile.write((char*)&client, sizeof(ClientData));
        createFile.close();
    }
    catch (char* msg)
    {
        cout << msg;
    }
    return 0;
}


