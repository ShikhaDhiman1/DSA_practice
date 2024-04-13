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
};

class employee: public person{ // Base as well as Derived class
    public:
    int empId;
    int salary;

    void setEInfo(){
        cout<<"Enter the Employee ID of "<<name<<": ";
        cin>>empId;
        cout<<"Enter the salary of "<<name<<" (monthly in Rs.): ";
        cin>>salary;
    }
};

class developer: public employee{ // derived class
    public:
    string major;
    string dptName;

    void setInfo(){
        setPInfo();
        setEInfo();
        cout<<"Enter the department name of "<<name<<": ";
        // cin.getline(dptName, 100, '\n');
        cin>>dptName;
        cout<<"Enter the Major of "<<name<<": ";
        cin>>major;
        return;
    }

    void getInfo(){
        cout<<"\nName of Person: "<<name;
        cout<<"\nAge of "<<name<<": "<<age;
        cout<<"\nGender of "<<name<<": "<<(gender == 0 ? "Male" : "Female");
        cout<<"\nEmployee Id is : "<<empId<<endl;
        cout<<"\nDepartment name of "<<name<<": "<<dptName;
        cout<<"\nMajor of "<<name<<": "<<major;
        cout<<"\nSalary of "<<name<<": "<<salary;
        cout<<endl<<endl;
    }
};

int main(){
    developer d;
    d.setInfo();
    cout<<"\n====-------------------INFO-------------------=====\n";
    d.getInfo();
    return 0;
}