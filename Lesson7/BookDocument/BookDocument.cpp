#include <cstring>
#include <iostream>

using std::cout;
using std::endl;

class Document {
    char* name;  // Doc name.
public:
    Document(const char* docName = nullptr) { setName(docName); }
    void setName(const char*);
    const char* getName() const { return name; };
    void print() const;
};

class Book : public Document {
    long pageCount;
public:
    Book(const char* name = nullptr, long pageNum = 0);
    void setNumOfPages(long num) { pageCount = num; };
    void print() const;
};

void Document::setName(const char* docName)
{
    if (docName) {
        int len = strlen(docName) + 1;
        name = new char[len];
        strcpy_s(name, len, docName);
    }
}

void Document::print() const
{
    cout << "Name: " << name << endl;
}

Book::Book(const char* name, long pageNum) : Document(name)
{
    pageCount = pageNum;
}

void Book::print() const
{
    Document::print();
    cout << "Number of pages: " << pageCount << endl;
}

int main() {
    Document d;    
    Book b;
    d.setName("Diploma");
    b.setName("Pinocchio");
    b.setNumOfPages(543);

    d.print();
    b.print();
    b.Document::print();

    Document& d2 = b;
    d2.print();

    //Book& b2 = d;
}

