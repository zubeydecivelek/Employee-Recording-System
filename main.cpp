#include <iostream>
#include "Date.h"
#include "Employee.h"
#include "TemporaryEmployee.h"
#include "PermanentEmployee.h"
#include "CircularArrayLinkedList.h"
#include "DoubleDynamicLinkedList.h"
#include <vector>
#include <sstream>

using namespace std;

CircularArrayLinkedList circularList = CircularArrayLinkedList(); //For temporary employee
DoubleDynamicLinkedList linkedList = DoubleDynamicLinkedList(); //For permanent employee

void takeInput(string &name,string &surname,string &title,string &birthDate,string &appointmentDate, double &salary){
    cout<<"Type the Name\n";
    cin>>name;
    cout<<"Type the Surname\n";
    cin>>surname;
    cout<<"Type the Title\n";
    cin>>title;
    cout<<"Type salary coefficient\n";
    cin>>salary;
    cout<<"Type birth date\n";
    cin>>birthDate;
    cout<<"Type appointment date\n";
    cin>>appointmentDate;
}

void update(Employee* emp){
    string newTitle;
    double newSalary;
    cout<<"Type the title to update\n";
    cin>>newTitle;
    cout<<"Type the  salary coefficient to update\n";
    cin>>newSalary;
    emp->setTitle(newTitle);
    emp->setSalary(newSalary);
}

vector<int> splitDates(string date){
    vector<int> returnVec;
    istringstream stream (date);
    string splitted;
    while (getline(stream,splitted,'-')){
        returnVec.push_back(stoi(splitted));
    }
    return returnVec;
}

bool byEmployeeNumber(const Employee *emp1, const Employee *emp2){
    return (emp1->getEmployeeNumber()<emp2->getEmployeeNumber());
}

bool byAppointmentDate(const Employee *emp1, const Employee *emp2){
    return (emp1->getAppointmentDate() > emp2->getAppointmentDate());
}

bool byAppointmentDateReverse(const Employee *emp1, const Employee *emp2){
    return (emp1->getAppointmentDate() < emp2->getAppointmentDate());
}

void printVector(vector<Employee*> employeeVector){
    for (Employee *emp : employeeVector) {
        cout<<*emp<<endl;
    }
}

void createCombineLists(int choice){
    vector<Employee*> employeeVector;
    circularList.convertToVector(&employeeVector);
    linkedList.convertToVector(&employeeVector);
    if (choice == 6) sort(employeeVector.begin(),employeeVector.end(), byEmployeeNumber);
    else sort(employeeVector.begin(),employeeVector.end(), byAppointmentDate);
    printVector(employeeVector);
}

void command8(Date givenDate){
    vector<Employee*> employeeVector;
    circularList.convertToVector(&employeeVector);
    linkedList.convertToVector(&employeeVector);
    sort(employeeVector.begin(),employeeVector.end(), byAppointmentDateReverse);
    for (Employee *emp:employeeVector){
        if(givenDate > emp->getAppointmentDate()){
            cout<<*emp<<endl;
        }
    }
}

void command9(int year){
    vector<Employee*> employeeVector;
    circularList.convertToVector(&employeeVector);
    linkedList.convertToVector(&employeeVector);
    sort(employeeVector.begin(),employeeVector.end(), byAppointmentDate);
    for (Employee *emp:employeeVector){
        if(year == emp->getAppointmentDate().getYear()){
            cout<<*emp<<endl;
        }
    }
}

void command10(Date birth){
    vector<Employee*> employeeVector;
    circularList.convertToVector(&employeeVector);
    linkedList.convertToVector(&employeeVector);
    sort(employeeVector.begin(),employeeVector.end(), byEmployeeNumber);
    for (Employee *emp:employeeVector){
        if(birth < emp->getBirthDate()){
            cout<<*emp<<endl;
        }
    }
}

void command11(int month){
    vector<Employee*> employeeVector;
    circularList.convertToVector(&employeeVector);
    linkedList.convertToVector(&employeeVector);
    sort(employeeVector.begin(),employeeVector.end(), byEmployeeNumber);
    for (Employee *emp:employeeVector){
        if(month == emp->getBirthDate().getMonth()){
            cout<<*emp<<endl;
        }
    }
}

void command12(string title){
    vector<Employee*> employeeVector;
    circularList.convertToVector(&employeeVector);
    linkedList.convertToVector(&employeeVector);
    sort(employeeVector.begin(),employeeVector.end(), byAppointmentDateReverse);
    for (Employee *emp:employeeVector){
        if(title == emp->getTitle()){
            cout<<*emp<<endl;
            return;
        }
    }
}

int main() {
    PermanentEmployee emp1(1,"İkrar","Konca","CEO", 100000, Date(16,12,1998), Date(19,1,2002),2);
    PermanentEmployee emp2(4,"Talha","Altundaş","yazılımcı", 8500, Date(26,10,2000), Date(16,5,2005),0);
    PermanentEmployee emp3(5,"Şamil","Emeç","yazılımcı", 8500, Date(20,3,1999), Date(30,7,2008),5);
    TemporaryEmployee temporaryEmployee1(20,"Ahmet", "Kahraman","tasarımcı",20000,Date(24,8,2001),Date(25,5,2005),3);
    TemporaryEmployee temporaryEmployee2(24,"Mehmet", "Uçankuş","tasarımcı",20000,Date(20,11,1985),Date(27,5,2003),2);
    TemporaryEmployee temporaryEmployee3(30,"Mustafa", "Gidenaraba","tasarımcı",25000,Date(24,8,1990),Date(25,5,2004),10);

    circularList.add(&temporaryEmployee1);
    circularList.add(&temporaryEmployee2);
    circularList.add(&temporaryEmployee3);

    linkedList.add(&emp1);
    linkedList.add(&emp2);
    linkedList.add(&emp3);


    string menu = "_ Employee Recording System _\n"
                  "1) Appointment of a new employee\n"
                  "2) Appointment of a transferred employee\n"
                  "3) Updating the the title and salary coefficient of an employee\n"
                  "4) Deleting of an employee\n"
                  "5) Listing the information of an employee\n"
                  "6) Listing employees ordered by employee number\n"
                  "7) Listing employees ordered by appointment date\n"
                  "8) Listing employees appointed after a certain date\n"
                  "9) Listing employees assigned in a given year\n"
                  "10) Listing employees born before a certain date\n"
                  "11) Listing employees born in a particular month\n"
                  "12) Listing the information of the last assigned employee with a given title\n";

    while (true){
        cout<<menu<<endl;
        int choice;
        cin>>choice;

        if(choice == 1){
            int employeeNumber;
            cout<<"Please type the employee number"<<endl;
            cin>>employeeNumber;
            if(circularList.contains(employeeNumber) || linkedList.contains(employeeNumber)) {
                cout<<"Employee already exists in the system"<<endl;
            }
            else{
                int employeeType;
                cout<<"Type the employee type"<<endl;
                cin>> employeeType;
                string name,surname,title, birthDate, appointmentDate;
                double salary;
                if (employeeType==0){
                    takeInput(name,surname,title,birthDate,appointmentDate,salary);
                    vector<int> birthDateVec = splitDates(birthDate), appointmentDateVec = splitDates(appointmentDate);
                    TemporaryEmployee emp(employeeNumber,name,surname,title,salary,Date(birthDateVec[0],birthDateVec[1], birthDateVec[2]),Date(appointmentDateVec[0],appointmentDateVec[1],appointmentDateVec[2]),0);
                    circularList.add(&emp);
                    cout<<"Employee added to the system\n";
                }
                else if(employeeType==1){
                    takeInput(name,surname,title,birthDate,appointmentDate,salary);
                    vector<int> birthDateVec = splitDates(birthDate), appointmentDateVec = splitDates(appointmentDate);
                    PermanentEmployee emp(employeeNumber,name,surname,title,salary,Date(birthDateVec[0],birthDateVec[1], birthDateVec[2]),Date(appointmentDateVec[0],appointmentDateVec[1],appointmentDateVec[2]),0);
                    linkedList.add(&emp);
                    cout<<"Employee added to the system\n";
                }
            }
        }
        else if (choice==2){
            int employeeNumber;
            cout<<"Please type the employee number"<<endl;
            cin>>employeeNumber;
            if(circularList.contains(employeeNumber) || linkedList.contains(employeeNumber)) {
                cout<<"Employee already exists in the system"<<endl;
            }
            else{
                int employeeType;
                cout<<"Type the employee type"<<endl;
                cin>> employeeType;
                string name,surname,title, birthDate, appointmentDate;
                double salary;
                int lengthService;
                if (employeeType==0){
                    takeInput(name,surname,title,birthDate,appointmentDate,salary);
                    cout<<"Type length of service days\n";
                    cin>>lengthService;
                    vector<int> birthDateVec = splitDates(birthDate), appointmentDateVec = splitDates(appointmentDate);
                    TemporaryEmployee emp(employeeNumber,name,surname,title,salary,Date(birthDateVec[0],birthDateVec[1], birthDateVec[2]),Date(appointmentDateVec[0],appointmentDateVec[1],appointmentDateVec[2]),lengthService);
                    circularList.add(&emp);
                    cout<<"Employee added to the system\n";
                    cout<<emp.getName()<<endl;
                }
                else if(employeeType==1){
                    takeInput(name,surname,title,birthDate,appointmentDate,salary);
                    cout<<"Type length of service days\n";
                    cin>>lengthService;
                    vector<int> birthDateVec = splitDates(birthDate), appointmentDateVec = splitDates(appointmentDate);
                    PermanentEmployee emp(employeeNumber,name,surname,title,salary,Date(birthDateVec[0],birthDateVec[1], birthDateVec[2]),Date(appointmentDateVec[0],appointmentDateVec[1],appointmentDateVec[2]),lengthService);
                    linkedList.add(&emp);
                    cout<<"Employee added to the system\n";
                    cout<<emp.getName()<<endl;
                }
            }
        }
        else if (choice == 3){
            int employeeNumber;
            cout<<"Please type the employee number"<<endl;
            cin>>employeeNumber;
            if(!(circularList.contains(employeeNumber)) && !(linkedList.contains(employeeNumber))) {
                cout<<"Employee not found in the system"<<endl;
            }
            else if (circularList.contains(employeeNumber)){
                TemporaryEmployee * emp = circularList.find(employeeNumber);
                update(emp);
            }
            else{
                PermanentEmployee *emp = linkedList.findEmployee(employeeNumber);
                update(emp);
            }
        }
        else if (choice == 4){
            int employeeNumber;
            cout<<"Please type the employee number"<<endl;
            cin>>employeeNumber;
            if(!(circularList.contains(employeeNumber)) && !(linkedList.contains(employeeNumber))) {
                cout<<"Employee not found in the system"<<endl;
            }
            else if (circularList.contains(employeeNumber)){
                circularList.erase(employeeNumber);
            }
            else{
                linkedList.erase(employeeNumber);
            }
        }
        else if (choice == 5){
            int employeeNumber;
            cout<<"Please type the employee number"<<endl;
            cin>>employeeNumber;
            if(!(circularList.contains(employeeNumber)) && !(linkedList.contains(employeeNumber))) {
                cout<<"Employee not found in the system"<<endl;
            }
            else if (circularList.contains(employeeNumber)){
                TemporaryEmployee * emp = circularList.find(employeeNumber);
                cout<<*emp<<endl;
            }
            else {
                PermanentEmployee *emp = linkedList.findEmployee(employeeNumber);
                cout<<*emp<<endl;
            }
        }
        else if (choice == 6 || choice == 7){
            createCombineLists(choice);
        }
        else if (choice == 8){
            cout<<"Type the date\n";
            string dateString;
            cin>>dateString;
            vector<int> dates = splitDates(dateString);
            Date date(dates[0],dates[1],dates[2]);
            command8(date);
        }
        else if (choice == 9){
            cout<<"Type the year\n";
            int year;
            cin>>year;
            command9(year);
        }
        else if (choice == 10){
            cout<<"Type the date\n";
            string dateString;
            cin>>dateString;
            vector<int> dates = splitDates(dateString);
            command10(Date(dates[0],dates[1],dates[2]));
        }
        else if (choice == 11){
            cout<<"Type the month\n";
            int month;
            cin>>month;
            command11(month);
        }
        else if (choice == 12){
            cout<<"Type the title\n";
            string title;
            cin>>title;
            command12(title);
        }
    }
    return 0;
}
