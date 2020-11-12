#pragma once
#include <iostream>
class Student
{
public:
    int id;
    Student() { std::cout << "ctor of Student\n"; id = 0; }
    Student(int _id) :id(_id)
    {
        std::cout << "ctor of Student\n";
    }
    ~Student()
    {
        std::cout << "desctr of Student\n";
    }
};

class Grade
{
    int max;
    Student arr[6];

public:
    Grade() : max(6)
    {
        for (int i = 0; i < 6; i++) std::cin >> arr[i].id;
        std::cout << "ctor of Grade\n";
    }
    ~Grade()
    {
        std::cout << max << " ";
        std::cout << arr[0].id << std::endl;
        std::cout << "desctr of Grade\n";
    }
};

