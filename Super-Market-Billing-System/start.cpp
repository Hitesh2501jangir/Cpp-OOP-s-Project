#include<iostream>
#include<fstream>
#include<cstring>
#include<windows.h>
using namespace std;

class Bill{
private:
    string itemName;
    float rate;
    int quantity;
public:
    Bill():itemName(""),rate(0.0),quantity(0){}
    //setter function
    void setItemName(string item){
        itemName = item;
    }
    void setRate(float rate){
        this->rate = rate;
    }
    void setQuantity(int quantity){
        this->quantity = quantity;
    }
    //getter function
    string getItemName(){
        return itemName;
    }
    float getRate(){
        return rate;
    }
    int getQuantity(){
        return quantity;
    }
};

//Add data in files
void addItem(Bill b){
    bool close = false;
    while(!close){
        system("cls");
        int choice;
        cout<<"\t"<<"1. Add"<<endl;
        cout<<"\t"<<"2. Close"<<endl;
        cout<<"\tEnter Your Choice : ";
        cin>>choice;
        cin.ignore();
        if(choice==1){
            system("cls");
            string item;int quantity;float rate;
            //item
            cout<<"Enter the item name : ";
            getline(cin,item);
            b.setItemName(item);
            //rate
            cout<<"Enter the rate of item : ";
            cin>>rate;
            b.setRate(rate);
            //quantity
            cout<<"Enter the quantity : ";
            cin>>quantity;
            b.setQuantity(quantity);

            //set in file
            ofstream onfile;
            onfile.open("Bill.txt",ios::app);
            if(!onfile){
                cout<<"\t Error: File not open";
            }else{
                onfile<<b.getItemName()<<" | "<<b.getRate()<<" | "<<b.getQuantity()<<endl<<endl;
                onfile.close();
                cout<<"Item Added Successfully";
                Sleep(2000);
            } 
        }else if(choice==2){
            system("cls");
            close = true;
            cout<<"Back to menu";
            Sleep(2000);
        }else{
            cout<<"Invalid choice";
        }
    }
}

//Genertae Bill
void getBill(){
    system("cls");
    bool close = false;
    while(!close){
        int choice;
        cout<<"\t"<<"1. View"<<endl;
        cout<<"\t"<<"2. Close"<<endl;
        cout<<"\tEnter Your Choice : ";
        cin>>choice;
        cin.ignore();
        
        if(choice==1){
            ifstream infile;
            infile.open("BIll.txt");
            string str;
            if(!infile){
                cout<<"Error: File cant be access";
            }else{
                system("cls");
                while(getline(infile,str)){
                    cout<<str<<endl;
                }
                infile.close();
            }
            cout<<endl<<"File Fatched Successfully"<<endl<<endl;
        }else if(choice==2){
            close = true;
            system("cls");
            cout<<"Go Back To Menu";
            Sleep(2000);
        }else{
            cout<<"Invalid Choice";

        }
    }
}

int main(){
    Bill b1;
    bool exit = false;

    while(!exit){
        system("cls");
        int val;
        cout<<"Welcome to the Super Market Billing System"<<endl;
        cout<<"*******************************************"<<endl;
        cout<<"\t\t"<<"1. Add Item"<<endl;
        cout<<"\t\t"<<"2. Generate Bill"<<endl;
        cout<<"\t\t"<<"3. Exit"<<endl;
        cout<<"\t\t"<<"Enter your choice : ";
        cin>>val;

        if(val==1){
            addItem(b1);
        }else if(val==2){
            getBill();
        }else if(val==3){
            return 0;
        }else{
            cout<<"Invalid Choice";
        }
    }
}