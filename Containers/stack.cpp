#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

bool polindrom(string str)
{
    stack<char> s;
    int i = 0;
    for (; i < str.size() / 2; i++)
        s.push(str[i]);

    if (str.size() % 2)
        i++;

    while (!s.empty()) {
        if (str[i++] != s.top())
            return false;
        s.pop();
    }
    return true;
}

int main()
{
    char word[20];
    cout << "enter a word: ";
    cin >> word;

    if (polindrom(word))
        cout << word << " is polindrom\n";
    else
        cout << word << " is not polindrom\n";

    return 0;
}