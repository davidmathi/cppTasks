#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main()
{
    ifstream file("/home/david/Desktop/Quote.txt");
    string aword;
    unordered_map<string,int> wordFreq;
    if (!file.good()) {
        cout << "Error: Failed to open the file.";
        return 1;
    }
    else {
        while( file >> aword ) {
            aword.erase(remove_if(aword.begin (), aword.end (), ::ispunct), aword.end ()); //Remove Punctuations from string
            unordered_map<string,int>::iterator got = wordFreq.find(aword);
            if ( got == wordFreq.end() )
              wordFreq.insert(std::make_pair<string,int>(aword.c_str(),1)); //insert the unique strings with default freq 1
            else
              got->second++; //found - increment freq
         }
    }
    file.close();

    cout << "\tWord Frequency Analyser\n"<<endl;
    cout << "     Frequency\t    Unique Words"<<endl;
    unordered_map<string,int>::iterator it;
    for ( it = wordFreq.begin(); it != wordFreq.end(); ++it )
      cout << "\t" << it->second << "\t\t" << it->first << endl;

    return 0;
}
