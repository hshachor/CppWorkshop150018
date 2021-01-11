#include<fstream>
#include<cstring>
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

	student(int id, char* name1)
	{
		this->id = id;
		strcpy_s(this->name, strlen(name1) + 1, name1);

	}

	friend ostream& operator<<(ostream& os, student& st)
	{
		os << "Id: " << st.id << " Name: " << st.name << endl;
		return os;
	}

	bool operator!()
	{
		return id != 0;
	}

};

template<class T>
class AnyKindFile
{
	
	fstream f;
	int size;
	string fileName;

public:

	AnyKindFile(string name, int len) :size(len), fileName(name)
	{
		CreateFile();
		f.open(fileName, ios::binary | ios::in | ios::out);
	}

	~AnyKindFile()
	{
		f.close();
	}

	void CreateFile()
	{
		ofstream fout(fileName, ios::binary);
		T stam;
		for (int i = 0; i < size; i++)
		{
			fout.write((char*)&stam, sizeof(T));
		}
		fout.close();
	}

	void addNewElement(T s, int index)
	{
		f.seekp((index - 1) * sizeof(T), ios::beg);
		f.write((char*)&s, sizeof(T));
	}

	bool ElemExist(int index)
	{
		T s;
		f.seekg((index - 1) * sizeof(T), ios::beg);
		f.read((char*)&s, sizeof(T));
		return !s;
	}

	void DeleteElem(int index)
	{
		f.seekp((index - 1) * sizeof(T), ios::beg);
		T s;
		f.write((char*)&s, sizeof(T));
	}

	friend ostream& operator<<(ostream& os, AnyKindFile<T>& akf)
	{
		T elem;

		akf.f.seekg(0);
		for (int i = 0; i < sf.size; i++)
		{
			f.read((char*)&elem, sizeof(T));
			if (!elem)
				cout << elem;
		}
		return os;
	}
};


void main()
{
	AnyKindFile<student> akf("AKBinFile.bin", 10);

	student s1(3, "moshe");
	akf.addNewElement(s1, s1.id);

	student s2(4, "david");
	akf.addNewElement(s2, s2.id);

	student s3(6, "avi");
	akf.addNewElement(s3, s3.id);

	if (akf.ElemExist(4))
		akf.ElemExist(4);

	system("pause");
}