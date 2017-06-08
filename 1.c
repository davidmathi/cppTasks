#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream fileDesc;
    fileDesc.open("output.txt",ios::app);
    
	float rate=16.78;
	int hours;
    int dependents;
    float socialTaxPer=0.06;
    float fedTaxPer=0.14;
    int unionDuePerWeek=10;
    int dependentFee=35;
    float grossPay,netPay,socialTax,fedTax;
	cout<<"Enter working Hours"<<endl;
	 cin >> hours;
	 cout<<"Enter Number of Dependents"<<endl;
	 cin >> dependents;
     if(hours<40)
        grossPay=rate * hours;
     else
         grossPay=rate*40+rate*(hours-40)*1.5;
         
     socialTax=socialTaxPer*grossPay;
     fedTax=fedTaxPer*grossPay;
     netPay=grossPay-socialTax-fedTax-unionDuePerWeek;
     if(dependents>=3)
         netPay=netPay-dependentFee;
     else
         dependentFee=0;
    
    cout<<"Gross Pay      ="<<grossPay<<endl;
    cout<<"Social Tax     ="<<socialTax<<endl;
    cout<<"Federal Tax    ="<<fedTax<<endl;
    cout<<"Dependent Fee  ="<<dependentFee<<endl;
    cout<<"Union Fee      ="<<unionDuePerWeek<<endl;
    cout<<"Net Pay        ="<<netPay<<endl;
    
     fileDesc<<"Gross Pay      ="<<grossPay<<endl;
    fileDesc<<"Social Tax     ="<<socialTax<<endl;
    fileDesc<<"Federal Tax    ="<<fedTax<<endl;
    fileDesc<<"Dependent Fee  ="<<dependentFee<<endl;
    fileDesc<<"Union Fee      ="<<unionDuePerWeek<<endl;
    fileDesc<<"Net Pay        ="<<netPay<<endl;
    fileDesc<<"--------------------------------------"<<endl;
     fileDesc.close();
    
	return 0;
}
