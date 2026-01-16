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

int main()
{
    cout<<"Student management system";
    return 0;
}
