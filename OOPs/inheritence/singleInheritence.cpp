#include <iostream>
using namespace std;

class employee{ // Base class
    int empId;
    public:
    string name;
    int age;
    bool gender;

    void setEmpId(){
        cout<<"Employee id is : ";
        cin>>empId;
    }

    void getEmpId(){
        cout<<"\n\nEmployee Id is : "<<empId<<endl;
    }
};

class manager: public employee{ // Derived Class
    public:
    // char dptName[100];
    string dptName;
    void setInfo(){
        cout<<"Enter the name of employee: ";
        // getline(cin, name, '\n');
        cin>>name;
        cout<<"Enter the age of "<<name<<": ";
        cin>>age;
        cout<<"Enter the gender of "<<name<<" (0: male, 1: female): ";
        cin>>gender;
        cout<<"Enter the department name of "<<name<<": ";
        // cin.getline(dptName, 100, '\n');
        cin>>dptName;
        return;
    }

    void getInfo(){
        cout<<"\nName of employee: "<<name;
        cout<<"\nAge of "<<name<<": "<<age;
        cout<<"\nGender of "<<name<<": "<<(gender == 0 ? "Male" : "Female");
        cout<<"\nDepartment name of "<<name<<": "<<dptName;
        cout<<endl<<endl;
        return;
    }
};

int main(){
    manager m1;
    m1.setEmpId();
    m1.setInfo();
    cout<<"\n====-------------------INFO-------------------=====\n";
    m1.getEmpId();
    m1.getInfo();
    return 0;
}