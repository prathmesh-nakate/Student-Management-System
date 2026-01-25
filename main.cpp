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

void save_Students()
{
    ofstream file("students.txt");
    for (const auto& s : students)
    {
        file << s.id << endl;
        file << s.name <<endl;
        file << s.age << endl;
        file << s.marks[0] << " " << s.marks[1] << " " << s.marks[2] << endl;
    }
    file.close();
}

void add_Student()
{
    Student s;
    s.id = nextId++;

    cout<<"\n==== Add New Student ===="<<endl;
    cout<<"Student Id : "<<s.id<<"(Auto-generated)"<<endl;

    cout<<"Enter name : ";
    cin.ignore();
    getline(cin, s.name);

    cout<<"Enter Age : ";
    cin>>s.age;

    cout<<"Enter Marks for Subject 1 :";
    cin>>s.marks[0];
    cout<<"Enter Marks for Subject 2 :";
    cin>>s.marks[1];
    cout<<"Enter Marks for Subject 3 :";
    cin>>s.marks[2];

    students.push_back(s);
    save_Students();

    cout<<"\nStudent Added Successfully !"<<endl;
    cout<<"Average Marks : " << fixed << setprecision(2) << s.getAverage() << endl;
    cout<<"Grade : " << s.getGrade() << endl;
}

void displayAllStudents()
{
    if(students.empty())
    {
        cout<<"\nNo Students in the System Yet."<<endl;
        return;
    }
    cout<<"\n ======================================================================= All Students ======================================================================="<<endl;
    cout<<"Id\tName\t\tAge\tSub 1\tSub 2\tSub 3\tAverage\tGrade"<<endl;
    cout<<"\n ============================================================================================================================================================"<<endl;

    for(const auto& s : students)
    {
        cout<<s.id<<"\t";
        cout<<left<<setw(24)<<s.name;
        cout<<s.age<<"\t";

        cout<<s.marks[0]<<"\t";
        cout<<s.marks[1]<<"\t";
        cout<<s.marks[2]<<"\t";

        cout<<fixed<<setprecision(2)<<s.getAverage()<<"\t\t";
        cout<<s.getGrade()<<endl;
    }
        cout << "========================================================================================================================================================" << endl;

}

void search_Student()
{
    if(students.empty())
    {
        cout<<"\nTo Students To Search."<<endl;
        return;
    }

    int id;
    cout<<"\nEnter Student ID To Search : ";
    cin>>id;

    bool fount = false;
    for(const auto& s : students)
    {
        if( s.id == id)
        {
            cout<<"\n===== Student Found ====="<<endl;
            cout<<"Id : "<<s.id<<endl;
            cout<<"Name : "<<s.name<<endl;
            cout<<"Age : "<<s.age<<endl;
            cout<<"Marks for Subject 1 : "<<s.marks[0]<<endl;
            cout<<"Marks for Subject 2 : "<<s.marks[1]<<endl;
            cout<<"Marks for Subject 3 : "<<s.marks[2]<<endl;
            cout<<"Average Marks : "<<fixed<<setprecision(2)<<s.getAverage()<<endl;
            cout<<"Grade : "<<s.getGrade()<<endl;
            fount = true;
            break;
        }
    }
    if(!found)
    {
        cout<<"\nStudent With Id "<<id<<" Not Found."<<endl;
    }
}

void update_Student()
{
    if(students.empty())
    {
        cout<<"\nNo Student To Update."<<endl;
        return;
    }
    int id;
    cout<<"\nEnter Student Id To Update : "<<endl;
    cin>>id;

    bool found = false;
    for(auto& s : students)
    {
        if (s.id == id)
        {
            cout<<"\nCurrent Details : "<<endl;
            cout<<"Name : "<<s.name<<endl;
            cout<<"Age : "<<s.age<<endl;

            cout<<"\nEnter New Details : "<<endl;

            cout<<"Enter Name : ";
            cin.ignore();
            getline(cin, s.name);
            
            cout<<"Enter Age : ";
            cin>>s.age;

            cout<<"Enter Marks For Subject 1 : ";
            cin>>s.marks[0];
            cout<<"Enter Marks For Subject 2 : ";
            cin>>s.marks[1];
            cout<<"Enter Marks For Subject  3 : ";
            cin>>s.marks[2];

            save_Students();
            cout<<"\nStudent Updated Successfully ! "<<endl;
            found = true;
            break;
        }
    }
    if(!found)
    {
        cout<<"\nStudent With ID "<<id<<"Not Found."<<endl;
    }
}

int main()
{
    cout<<"Student management system";
    return 0;
}
