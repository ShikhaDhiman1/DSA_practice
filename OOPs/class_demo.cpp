#include <iostream>
using namespace std;

class Student{
    public: // access specifier
        string name;
        int age;
        bool gender;

        //constructor
        Student(){
            cout<<"\n\nDefault Constructor of class Student!\n";
        }

        Student(string n, int a, bool g){ // parameterised constructor
            cout<<"\nThis is user a parameterised construcctoe\n";
            name = n;
            age = a;
            gender = g;
        }

        ~Student(){
            cout<<"\n\n**************************************************\n";
            cout<<"This is default destructor of Student class\n";
            cout<<"\n\n**************************************************\n";
        }
        // Student(Student &st){
        //     cout<<"\nThis is user defined copy construcctoe\n";
        //     name = st.name;
        //     age = st.age;
        //     gender = st.gender;
        // }

        bool operator == (Student &st){
            if(name == st.name && age == st.age && gender == st.gender){
                return true;
            }
            else return false;
        }

        void printInfo(){
            cout<<"\nInformation about the Student is : \n\n";
            cout<<"Name of Student is : "<<name;
            cout<<"\nAge of "<<name<<" is : "<<age;
            cout<<"\nGender of "<<name<<" is : "<<(gender==1?"Female":"male");
            return;
        }
};

class Student1{
    private:
        string name;
    public:
        int age;
        bool gender;

        //constructor
        Student1(){
            cout<<"\n\nDefault Constructor of class Student1!\n";
        }

        Student1(string n, int a, bool g){ // parameterised constructor
            cout<<"\nThis is user a parameterised construcctoe\n";
            name = n; 
            age = a;
            gender = g;
        }

        Student1(Student1 &st){    //copy constructor
            cout<<"\nThis is user defined copy construcctoe\n";
            name = st.name;
            age = st.age;
            gender = st.gender;
        }

        ~Student1(){
            cout<<"\n\n**************************************************\n";
            cout<<"This is default destructor of Student1 class\n";
            cout<<"\n\n**************************************************\n";
        }

        //class functions 
        void setName(string s){
            name = s;
            return;
        }

        bool operator == (Student1 &st){
            if(name == st.name && age == st.age && gender == st.gender){
                return true;
            }
            return false;
        }

        void printInfo(){
            cout<<"\nInformation about the Student is : \n\n";
            cout<<"Name of Student is : "<<name;
            cout<<"\nAge of "<<name<<" is : "<<age;
            cout<<"\nGender of "<<name<<" is : "<<(gender==1?"Female":"male");
            return;
        }
};

int main(){
    Student a;
    cout<<"Enter the name of Student : ";
    getline(cin, a.name);
    cout<<"Enter the age of "<<a.name<<" : ";
    cin>>a.age;
    cout<<"Enter the Gender of "<<a.name<<" (0: Male, 1: Female) : ";
    cin>>a.gender;
    a.printInfo();
    cout<<endl;
    Student a1("Shriti Sohan", 22, 1);
    a1.printInfo();

    cout<<"\n\n-----------------------------------------------------------------------\n";
    cout<<"\nFollowing are default copy constructor of Student class:\n";
    Student a2 = a1; // default copy constructor
    a2.printInfo();
    cout<<endl;
    Student a3(a1); // default copy constructor
    a3.printInfo();
    cout<<endl;
    (a3==a2)?"Same":"Not Same";

    Student1 b;
    string s;
    cout<<"\nEnter the name of Student : ";
    // getline(cin,s);
    cin>>s;
    b.setName(s);
    cout<<"Enter the age of "<<s<<" : ";
    cin>>b.age;
    cout<<"Enter the Gender of "<<s<<" (0: Male, 1: Female) : ";
    cin>>b.gender;
    b.printInfo();
    cout<<endl;
    Student1 b1("Shrivan Singhal", 21, 0);
    b1.printInfo();

    cout<<"\n\n-----------------------------------------------------------------------\n";
    cout<<"\nFollowing are user defined copy constructor of Student1 class:\n";
    Student1 b2 = b1; // user defined copy constructor
    b2.printInfo();
    cout<<endl;
    Student1 b3(b1); // user defined copy constructor
    b3.printInfo();
    if(b==b1){
        cout<<"b is same as b1";
    }
    else{
        cout<<"b is not same as b1";
    }
    cout<<endl;
    return 0;
}