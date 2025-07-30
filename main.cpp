#include <iostream>
#include<vector>
#include<string>
using namespace std;

struct Student{
    int id;
    string name;
    int age;
    string course;
};

vector<Student> students;

void addStudent(){
    Student s;
    cout<<"\nEnter Student ID :";
    cin>>s.id;
    cout<<"Enter name :";
    cin.ignore();
    getline(cin,s.name);
    cout << "Enter Age: ";
    cin >> s.age;
    cout << "Enter Course: ";
    cin.ignore();
    getline(cin, s.course);

    students.push_back(s);
    cout<<"Student added successfully!\n\n";
}

void deleteStudents(){
    int id;
    cout<<"\n Enter Student ID to delete: ";
    cin>>id;

    bool found = false;
    for(auto i = students.begin(); i != students.end(); ++i){
        if (i->id == id) {
            students.erase(i);
            found = true;
            cout << "Student deleted successfully!\n";
            break;
        }
    }
    if(!found){
        cout<<"Student not found!\n";
    }
}

void displayStudents() {
    cout << "\n Student Records:\n";
    if (students.empty()) {
        cout << "No student records available.\n";
        return;
    }

    for (const auto& s : students) {
        cout << "\n--------------------------\n";
        cout << "ID     : " << s.id << endl;
        cout << "Name   : " << s.name << endl;
        cout << "Age    : " << s.age << endl;
        cout << "Course : " << s.course << endl;
    }
}

int main(){
    int choice;
    while(true){
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Delete Student\n";
        cout << "3. Display All Students\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice){
            case 1 : addStudent(); break;
            case 2: deleteStudents(); break;
            case 3: displayStudents(); break;
            case 4: cout << "👋 Exiting Program.\n"; return 0;
            default: cout << "Invalid choice. Try again!\n";
        }
    }
    return 0;
}


