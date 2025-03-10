#include<iostream>
#include<windows.h>
#include<fstream>
#include<cstring>
using namespace std;
static int availabilityOfBed = 6;
int totalBedBooked;
void getTotalBedBooked(){
    int val;
    ifstream infile;
    infile.open("bed.txt");
    infile >> val;
    totalBedBooked = val;
}

class Student{
private:
    string studentName, studentRollNo,studentAddress;
public:
    void setName(string name){
        studentName = name;
    }
    void setRollNo(string roll){
        studentRollNo = roll;
    }
    void setAddress(string Address){
        studentAddress = Address;
    }
    string getName(){
        return studentName;
    }
    string getRollNo(){
        return studentRollNo;
    }
    string getAddress(){
        return studentAddress;
    }
};
// int Student::availabilityOfBed = 3;

bool checkAvailabily()
{
    if (totalBedBooked >= availabilityOfBed)
    {
        cout << "No Bed is Available";
        Sleep(2000);
        return false;
    }
    else
    {
        totalBedBooked++;
        ofstream onfile;
        onfile.open("bed.txt");
        onfile << totalBedBooked;
        return true;
    }
}

//ENTRY RECORD FUNCTION
void bookBed(){
    system("cls");
    if(!checkAvailabily()){
        return;
    }
    //student detail entry
    cout << "Enter the details :------>" << endl;
    Student s;
    string name, rollNo, address;
    cout << "Enter the Student name : ";
    getline(cin, name);
    s.setName(name);
    cout << "Enter the Student roll no : ";
    getline(cin, rollNo);
    s.setRollNo(rollNo);
    cout<<"Enter the Student address : ";
    getline(cin, address);
    s.setAddress(address);
    cout << "Your Bed is reserved ";
    ofstream StudentData("Stuedent-Data.txt", ios::app);
    StudentData << s.getName() << "\t|\t" << s.getRollNo() << "\t|\t" << s.getAddress() << endl;
    StudentData.close();
    Sleep(3000);
}


//DISPLAY FUNCTION
void mainMenu(){
    bool exit = false;
    while(!exit){int choice;
        system("cls");
        cout << "Welcome to Hostel Accommodation System" << endl;
        cout << "*******************************************" << endl<<endl;
        cout << "1. Reserve a bed"<<endl;
        cout << "2. Exit"<<endl;
        cout << "Enter your choice : ";
        cin >> choice;
        cin.ignore();
        switch(choice){
            case 1:
                getTotalBedBooked();
                bookBed();
                break;
            case 2:
                exit = true;
                break;
            default :
                cout << "Invalid Choice";
                Sleep(2000);
        }
    }
}


//MAIN FUNCTION
int main(){
    mainMenu();
}