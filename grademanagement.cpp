#include <iostream>
#include <vector>
#include <cstring>

using namespace std;


struct Student
{
    string name;
    int id;
    int grade;
};

void disp(vector<Student>& s);
void addStudent(vector<Student>& s);


int main()
{
    vector<Student> s;
    string c;

    do {
        addStudent(s);

        cout <<endl<< "Do you want to run again? (yes/no): ";
        cin >> c;

    } while (c == "yes");

    disp(s);
}

void disp(vector<Student>& s)
{
    int ctr=1;
    cout<<endl<<"List of Students:"<<endl;
    for (Student i: s)
    {
        cout<<"Student "<<ctr++<<":"<<endl;
        cout<<i.name<<endl;
        cout<<i.id<<endl;
        cout<<i.grade<<endl<<endl;


    }
}

void addStudent(vector<Student>& s)
{
    Student stud;
    cout<<"Enter student name:"<<endl;
    cin>>stud.name;
    cout<<"Enter student id:"<<endl;
    cin>>stud.id;
    cout<<"Enter student grade:"<<endl;
    cin>>stud.grade;

    s.push_back(stud);
}
