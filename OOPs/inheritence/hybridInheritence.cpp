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
    void getPInfo(){
        cout<<"\nName of Person: "<<name;
        cout<<"\nAge of "<<name<<": "<<age;
        cout<<"\nGender of "<<name<<": "<<(gender == 0 ? "Male" : "Female");
        return;
    }
};

class employee: public person{ // Base as well as Derived class
    public:
    int empId;
    int salary;

    void setEInfo(){
        setPInfo();
        cout<<"Enter the Employee ID of "<<name<<": ";
        cin>>empId;
        cout<<"Enter the salary of "<<name<<" (monthly in Rs.): ";
        cin>>salary;
    }
    void getEInfo(){
        getPInfo();
        cout<<"\n\nEmployee Id is : "<<empId;
        cout<<"\nSalary of "<<name<<": "<<salary;
    }
};

class child: public person{ // Base as well derived class
    public:
    string father;
    string mother;
    void setCInfo(){
        // setPInfo();
        cout<<"Enter the Father's name of "<<name<<": ";
        cin>>father;
        cout<<"Enter the Mother's name of "<<name<<": ";
        // cin.getline(dptName, 100, '\n');
        cin>>mother;
    }

    void getCInfo(){
        // getPInfo();
        cout<<"\n\nFather's name is : "<<father;
        cout<<"\nMother's name is : "<<mother;
    }
};

class developer: public employee, public child{ // derived class
    public:
    string major;
    string dptName;

    void setInfo(){
        setEInfo();
        setCInfo();
        cout<<"Enter the department name : ";
        // cin.getline(dptName, 100, '\n');
        cin>>dptName;
        cout<<"Enter the Major : ";
        cin>>major;
        return;
    }

    void getInfo(){
        getEInfo();
        getCInfo();
        cout<<"\n\nDepartment name of : "<<dptName;
        cout<<"\nMajor of : "<<major;
        cout<<endl<<endl;
    }
};

int main(){
    developer d;
    d.setInfo();
    d.getInfo();
    return 0;
}