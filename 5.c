#include<iostream>
#include<fstream>
#include<unordered_map>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
ifstream fileObj("/home/murali/Desktop/text.txt");
string word;
unordered_map<string,int> frequentWords;

while(fileObj >> word){
word.erase(remove_if(word.begin(),word.end(),::ispunct),word.end());
unordered_map<string,int>::iterator fr=frequentWords.find(word);
if(fr==frequentWords.end())
frequentWords.insert(make_pair<string,int>(word.c_str(),1));
else
fr->second++;

}
fileObj.close();


cout<<" Word Frequency Analysis"<<endl;
cout<<" Word Frequency"<<endl;
unordered_map<string,int>::iterator now;
for (now=frequentWords.begin();now!=frequentWords.end();now++)
cout<<now->second<<"\t"<<now->first<<endl;

return 0;

}
