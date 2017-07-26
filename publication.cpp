#include<iostream>
#include<string>
using namespace std;

class Publication{
public:
    string title;
    float price;
    
     void getData1(){
    cout<<"Enter Title of the Book"<<endl;
     cin>>title;
     cout<<"Enter Price of the Book"<<endl;
     cin>>price;}
     
      void putData1(){
      cout<<" Book Title - "<<title<<endl;
     cout<<" Book Price - "<<price<<endl;
      }
     
     
     
    
    virtual void getData()=0;
    virtual void putData()=0;
};


class Book:public Publication{
private:
    int pages;
public:
    void getData(){
      Publication::getData1();
     cout<<" Enter Number of Pages "<<endl;
     cin>>pages;
        
        
    }
    
    void putData(){
     Publication::putData1();
     cout<<"Number of Pages "<<pages<<endl;
     
        
        
    }
    
    
};

class Tape:public Publication{
    private:
    float  minutes;
public:
    void getData(){
     Publication::getData1();
     cout<<" Enter Total Minutes "<<endl;
     cin>>minutes;
        
        
    }
    
    void putData(){
    Publication::putData1();
     cout<<"Total Minutes "<<minutes<<endl;
     
        
        
    }
    
    
    
};



int main(){
    Publication* pubarr[100];
    int number =0;
    int selection=0;
    int i=0;
    
    do {
        cout<<"What tyoe.1.Book 2.Tape"<<endl;
        cin>>selection;
        if(selection==1){
            pubarr[number]=new Book;
            pubarr[number]->getData();
            
        }
        else if (selection==2)
        {
            pubarr[number]=new Tape;
            pubarr[number]->getData();
            //pubarr[number]->putData();
            
        }
        
        number=number+1;
        cout<<"Enter One more 1.Yes 2.No"<<endl;
        cin>>selection;
        
        
    }
    while(selection==1);
    
  
    cout<<"********************"<<endl; 
   while (i<number){
     pubarr[i]->putData();
     cout<<"*********************"<<endl;
     cout<<endl;
     
     i++;
}
        
    
    
    
    
    
 return 0;
 
}




