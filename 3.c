#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
#include <vector>
#include "boost/lexical_cast.hpp"

using namespace std;
int main()
{
float cost_calculator(string,int,int,int);
std::ifstream inputObject("/home/murali/Desktop/talkTime.txt");
std::string weekDay;
std::string weekEnd;
string time;
string duration;
string day;
int minutes;
int hours;
float sum=0.0;
float total;
std::string line;
while(std::getline(inputObject,line)){
 stringstream linestream(line);
 string item;
 int counter_loop=0;
 
 while(getline(linestream,item,' '))
{
 counter_loop+=1;
 if(counter_loop==1)
     day=item;
 else if(counter_loop==2){
     time=item;
    std::stringstream test(time);
std::string segment;
std::vector<std::string> seglist;
std::vector<int> intSegList;
while(std::getline(test, segment, ':'))
{
   seglist.push_back(segment);
}
for (size_t i=0; i<seglist.size(); i++)
   {
      intSegList.push_back(boost::lexical_cast<int>(seglist[i]));
   }
hours=intSegList[0];
minutes=intSegList[1];

}
 else if(counter_loop==3)
 {  
     counter_loop=0;
     duration=item;
 }
}



cout<<day<<hours<<minutes<<duration<<endl;

total=cost_calculator(day.c_str(),hours,minutes,atoi(duration.c_str()));
cout<<total<<endl;
sum =sum+total;


}

cout<<" total sum = "<<sum<<endl;
return 0;
}


float cost_calculator(std::string day ,int hours,int minutes,int time){
    
    float charge;
 if ((strcmp(day.c_str(),"Mo")==0)||(strcmp(day.c_str(),"Tu")==0)||(strcmp(day.c_str(),"We")==0)||(strcmp(day.c_str(),"Th")==0)||(strcmp(day.c_str(),"Fr")==0))
{
if (((hours>=8)&&(hours<=18))&&((minutes>=0)&&(minutes<60)))
{
charge=time*0.4;
}
else
{
charge=time*0.25; 
}
}
if ((strcmp(day.c_str(),"Su")==0)||(strcmp(day.c_str(),"Sa")==0))
{
charge=time*0.15; 
}

return charge;
    
}



