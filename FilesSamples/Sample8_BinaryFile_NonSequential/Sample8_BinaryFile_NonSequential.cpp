#include<fstream>
#include<string>
#include<iostream>
using namespace std;

struct student
{
	char name[12];
	//char* name; //no!!!
	//string name //no!!!
	int id;

	student()
	{
		id = 0;
		char name1[12] = { 0 };
		strcpy_s(name, 12, name1);
	}

	student(int id, const char* name1)
	{
		this->id = id;
		strcpy_s(this->name, strlen(name1) + 1, name1);
	}
};


class StudentFile
{
	fstream f;
	int size;
	string fileName;
public:
	
	StudentFile(string name, int len) :size(len), fileName(name)
	{
		CreateFile();
		f.open(fileName, ios::binary | ios::in | ios::out);
	}
	
	~StudentFile()
	{
		f.close();
	}
	
	void CreateFile()
	{
		ofstream fout(fileName, ios::binary);
		student stam;
		for (int i = 0; i < size; i++)
		{
			fout.write((char*)&stam, sizeof(student));
		}
		fout.close();
	}

	void addNewStudent(student s)
	{
		f.seekp	((s.id - 1) * sizeof(student), ios::beg	);
		f.write((char*)&s, sizeof(student));
	}

	bool StudentExist(int index)
	{
		student s;
		f.seekg((index - 1) * sizeof(student), ios::beg);
		f.read((char*)&s, sizeof(student));
		return s.id != 0;
	}

	void DeleteStudent(int index)
	{
		f.seekp((index - 1) * sizeof(student), ios::beg);
		student stam;
		f.write((char*)&stam, sizeof(student));
	}

	friend ostream& operator<<(ostream& os, StudentFile& sf)
	{
		student st;

		sf.f.seekg(0);
		for (int i = 0; i < sf.size; i++)
		{
			sf.f.read((char*)&st, sizeof(student));
			if (st.id)
				os << "Id: " << st.id << " Name: " << st.name << endl;
		}
		return os;
	}

};

void main()
{

	StudentFile sf("StudentsBinFile.bin", 10);

	student s(3, "moshe");
	sf.addNewStudent(s);

	sf.addNewStudent(student(4, "david"));
	sf.addNewStudent(student(6, "avi"));

	if (sf.StudentExist(4))
		sf.DeleteStudent(4);

	cout << sf;

	system("pause");
}