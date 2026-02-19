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
    
    float getPercentage() 
    const
    { 

        float totalMarks = marks[0] + marks[1] + marks[2];

        return (totalMarks / 300.0) * 100.0;  // Out of 300 total marks
    }

    char getGrade()
    const
    {
        float avg = getPercentage();

        if(avg >= 90) return 'A';
        else if(avg >= 80) return 'B';
        else if(avg >= 70) return 'C';
        else if(avg >= 60) return 'D';
        else return 'F';
    }
};

vector <Student> students;

void load_Students()
{
    ifstream file("students.txt");
    if(!file.is_open()) 
    return;

    Student s;

    while(file >> s.id)
    {
        file.ignore();
        getline(file, s.name);
        file >> s.age;
        file >> s.marks[0] >> s.marks[1] >> s.marks[2];

        students.push_back(s);
       
    }
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

    cout<<"\n==== Add New Student ===="<<endl;
    cout<<"Enter Student Id : ";
    cin>>s.id;

    for(const auto& student : students)
    {
        if(student.id == s.id)
        {
            cout<<"Error! Student ID Already Exists!"<<endl;
            return;
        }
    }

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
    cout<<"Percentage : " << fixed << setprecision(2) << s.getPercentage() << endl;
    cout<<"Grade : " << s.getGrade() << endl;
}

void displayAllStudents()
{
    if(students.empty())
    {
        cout<<"\nNo Students in the System Yet! Proceed To Add Student."<<endl;
        return;
    }
    cout<<"\n ======================================================================= All Students ======================================================================="<<endl;
    cout<<"Id\tName\t\tAge\tSub 1\tSub 2\tSub 3\tPercentage\tGrade"<<endl;
    cout<<"\n ============================================================================================================================================================"<<endl;

    for(const auto& s : students)
    {
        cout<<s.id<<"\t";
        cout<<left<<setw(24)<<s.name;
        cout<<s.age<<"\t";

        cout<<s.marks[0]<<"\t";
        cout<<s.marks[1]<<"\t";
        cout<<s.marks[2]<<"\t";

        cout<<fixed<<setprecision(2)<<s.getPercentage()<<"\t\t";
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

    bool found = false;
    for(const auto& s : students)
    {
        if( s.id == id)
        {
            cout<<"\n===== Student Found ====="<<endl;
            cout<<"Id : "<<s.id<<endl;
            cout<<"Name : "<<s.name<<endl;
            cout<<"Age : "<<s.age<<endl<<endl;
            cout<<"Marks for Subject 1 : "<<s.marks[0]<<endl;
            cout<<"Marks for Subject 2 : "<<s.marks[1]<<endl;
            cout<<"Marks for Subject 3 : "<<s.marks[2]<<endl;
            cout<<endl<<"Percentage : "<<fixed<<setprecision(2)<<s.getPercentage()<<endl;
            cout<<"Grade : "<<s.getGrade()<<endl;
            found = true;
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
    cout<<"\nEnter Student Id To Update : ";
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

void delete_Student()
{
    if(students.empty())
    {
        cout<<"\nNo tudent To Delete."<<endl;
        return;
    }
    int id;
    cout<<"\nEnter Student ID To Delete : ";
    cin>>id;

    bool found = false;
    for(size_t i = 0; i < students.size(); i++)
    {
        if(students[i].id == id)
        {
            cout<<"Delete Student : "<<students[i].name<<"? (y/n) : ";
            char confirm;
            cin>>confirm;

            if(confirm == 'y'  || confirm == 'Y')
            {
                students.erase(students.begin() + i);
                save_Students();
                cout<<"\nStudent Deleted successfuly !"<<endl;
            }
            else
            {
                cout<<"\nDeletion Cancelled."<<endl;
            }
            found = true;
            break;
        }
    }
    if(!found)
    {
        cout<<"\nStudent With Id "<<id<<" Not Found."<<endl;
    }
}

int main()
{
    load_Students();

    cout<<"============================================================"<<endl;
    cout<<"              Student management System                     "<<endl;
    cout<<"============================================================"<<endl;

    while(true)
    {
        cout<<"\n------ Menu ------"<<endl;
        cout<<"1. Add Student"<<endl;
        cout<<"2. Display All Students"<<endl;
        cout<<"3. Search Student"<<endl;
        cout<<"4. Update Student"<<endl;
        cout<<"5. Delete Student"<<endl;
        cout<<"6. Exit"<<endl;

        cout<<"\nEnter Your Choice : ";

        int choice;
        cin>>choice;

        switch(choice)
        {
            case 1:
                add_Student();
                break;

            case 2:
                displayAllStudents();
                break;

            case 3:
                search_Student();
                break;

            case 4:
                update_Student();
                break;

            case 5:
                delete_Student();
                break;

            case 6:
                cout<<"Thanks For Using Student Management System. Goodbye!"<<endl;
                return 0;

            default:
                cout<<"\nInvalid Choice. please Try Again."<<endl;
        }
    }
    return 0;
}
