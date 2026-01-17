#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<vector>

using namespace std;

struct Student
{
    int id;
    string name;
    int age;
    float marks[3];    // Marks For 3 Subjects
    
    float getAverage()
    const
    {
        return (marks[0] + marks[1] + marks[2]) / 3.0;
    }

    char getGrade()
    const
    {
        float avg = getAverage();

        if(avg >= 90) return 'A';
        else if(avg >= 80) return 'B';
        else if(avg >= 70) return 'C';
        else if(avg >= 60) return 'D';
        else return 'F';
    }
};

vector <Student> students;
int nextId = 1;

void load_Students()
{
    ifstream file("students.txt");
    if(!file.is_open()) 
    return;

    int maxId = 0;
    Student s;

    while(file >> s.id)
    {
        file.ignore();
        getline(file, s.name);
        file >> s.age;
        file >> s.marks[0] >> s.marks[1] >> s.marks[2];

        students.push_back(s);
        if(s.id > maxId)
        maxId = s.id;
    }
    nextId = maxId + 1;
    file.close();
}

int main()
{
    cout<<"Student management system";
    return 0;
}
