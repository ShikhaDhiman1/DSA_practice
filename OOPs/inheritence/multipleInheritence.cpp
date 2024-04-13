#include <iostream>
using namespace std;

class person{ //Base Class(Parent or Superclass)
    public:
    string name;
    int age;
    bool gender;

    void setPInfo(){
        cout<<"Enter the name of Person: ";
        // getline(cin, name, '\n');
        cin>>name;
        cout<<"Enter the age of "<<name<<": ";
        cin>>age;
        cout<<"Enter the gender of "<<name<<" (0: male, 1: female): ";
        cin>>gender;
        return;
    }
    void getInfo(){
        cout<<"\nName of Person: "<<name;
        cout<<"\nAge of "<<name<<": "<<age;
        cout<<"\nGender of "<<name<<": "<<(gender == 0 ? "Male" : "Female");
        return;
    }
};

class employee: public person{ // Derived class
    public:
    string dptName;
    int empId;
    int salary;

    void setEInfo(){
        setPInfo();
        cout<<"Enter the Employee ID of "<<name<<": ";
        cin>>empId;
        cout<<"Enter the Department name of "<<name<<": ";
        // cin.getline(dptName, 100, '\n');
        cin>>dptName;
        cout<<"Enter the salary of "<<name<<" (monthly in Rs.): ";
        cin>>salary;
    }
    void getEInfo(){
        getInfo();
        cout<<"\nEmployee Id is : "<<empId<<endl;
        cout<<"\nDepartment name of "<<name<<": "<<dptName;
        cout<<"\nSalary of "<<name<<": "<<salary;
    }
};

class student: public person{ // derived class
    public:
    string schlName;
    string clss;
    int rollNo;

    void setSInfo(){
        setPInfo();
        cout<<"Enter the School name of "<<name<<": ";
        // cin.getline(dptName, 100, '\n');
        cin>>schlName;
        cout<<"Enter the Class of "<<name<<": ";
        cin>>clss;
        cout<<"Enter the Roll no. of "<<name<<": ";
        cin>>rollNo;
        return;
    }

    void getSInfo(){
        getInfo();
        cout<<"\nSchool name of "<<name<<": "<<schlName;
        cout<<"\nClass of "<<name<<": "<<clss;
        cout<<"\nRoll No. of "<<name<<": "<<rollNo;
        cout<<endl<<endl;
    }
};

int main(){
    cout<<"\n**********EMPLOYEE************\n";
    employee e;
    e.setEInfo();
    cout<<"\n====-------------------INFO-------------------=====\n";
    e.getEInfo();
    cout<<"\n\n**********STUDENT************\n";
    student s;
    s.setSInfo();
    cout<<"\n====-------------------INFO-------------------=====\n";
    s.getSInfo();
    cout<<endl;
    return 0;
}