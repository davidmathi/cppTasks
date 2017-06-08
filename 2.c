#include <iostream>
#include <string>
#include <math.h>
#include <fstream>

using namespace std;


int main() {
    ofstream fileDesc;
fileDesc.open("output2.txt",ios::app);

    void itemOut(string x,std::ofstream& fileDesc);
    void changeOut(float diff,std::ofstream& fileDesc);
    int items[3]={2,2,2};
    float quarters,dimes,nickels,totalInput,price;
    string item;
	int selection;
    float difference;
    do{
        difference=0;
    cout<<"-----------------------------------------------------------------"<<'\n'<<'\n'<<endl;
	cout<<"Enter number of Quarters,Dimes,Nickels"<<endl;
    fileDesc<<"Enter number of Quarters,Dimes,Nickels"<<endl;
	 cin >> quarters>>dimes>>nickels;
     fileDesc<<quarters<<' '<<dimes<<' '<<nickels<<endl;
         totalInput=quarters*0.25+dimes*0.1+nickels*0.05;

	 cout<<"select  "
         <<"1. Potato chips $1.25 "
         <<"2. Cookies $0.85 "
         <<"3. Candies $0.95 "
         <<endl;
    fileDesc<<"select  "
         <<"1. Potato chips $1.25 "
         <<"2. Cookies $0.85 "
         <<"3. Candies $0.95 "
         <<endl;
	 cin >> selection;
   
   
     if(items[selection-1]>=0){
     switch(selection){
         case  1:
             price=1.25;
             item="Potato Chips";
             items[selection-1]--;
             break;
         case  2:
             price=0.85;
             item="Cookies";
             items[selection-1]--;
             break;
         case  3:
             price=0.95;
             item="Candies";
             items[selection-1]--;
             break;
         default:
             cout<<"Item Doesn't Exist.Try Again"<<endl;
             fileDesc<<"Item Doesn't Exist.Try Again"<<endl;
            changeOut(totalInput,fileDesc);
             continue; 
     }
     
     
     cout<<selection<<" - selected"<<endl;
     fileDesc<<selection<<" - selected"<<endl;

     
     
   if(totalInput>=price){
        itemOut(item,fileDesc);
       
        difference=totalInput-price;
        changeOut(difference,fileDesc);
   }
   else{
       cout<<"Less Amount Inserted.Please Insert "<<price<<endl;
       fileDesc<<"Less Amount Insterted.Please Insert "<<price<<endl;
       fileDesc<<"---------------------------------------"<<endl;
   }
     }else{
        cout<<"Item out of stock"<<endl;
            fileDesc<<"Item out of stock"<<endl;
            changeOut(totalInput,fileDesc);
    }
    }
    while(1);
    
	return 0;
}





void itemOut(string x,std::ofstream& fileDesc)
{
    cout<<"Please take your "<<x<<'\n'<<"*****"<<endl;
    fileDesc<<"Please take your "<<x<<'\n'<<"*****"<<endl;
    
}

void changeOut(float diff,std::ofstream& fileDesc){
    
    
    float quarters,dimes,nickels;
    quarters=int(diff/0.25);
    dimes=int((diff-quarters*0.25)/0.1);
    nickels=round((diff-quarters*0.25-dimes*0.1)/0.05);
    cout<<"Please Take the Change -" <<"quarters-"<<quarters<<'\n'
                                     <<"dimes-"<<dimes<<'\n'
                                     <<"nickels-"<<nickels<<'\n';
                
     fileDesc<<"Take the change of "<<diff<<endl;
     fileDesc<<'\n'<<"quarters-"<<quarters<<'\n'
                                     <<"dimes-"<<dimes<<'\n'
                                     <<"nickels-"<<nickels<<'\n';
       fileDesc<<"--------------------------------------"<<endl;     
    
}
