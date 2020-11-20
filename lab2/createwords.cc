#include<iostream>
#include <iomanip>
#include<fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <cctype>

using namespace std;

// get the trigrams
void get_trigrams(vector<string> trigrams,const string &line){ // &trigrams or not?
  if(line.size()>2){
    for(string::size_type i = 0; i<line.size()-2; i++){
      trigrams.push_back(line.substr(i,3));
    }
  }
}

int main() {
  string line;
  ifstream textfile; 
  ofstream out("words.txt");
  textfile.open("/usr/share/dict/words"); // UTF-8 encoded
  while ( getline(textfile, line)){
    vector<string> trigrams;
    
    transform(line.begin(), line.end(), line.begin(), ::tolower); // Change line to lower case.
    get_trigrams(trigrams,line);                                  // Get the trigrams
    int nbr_tigs{trigrams.size()};                                // The number of trigrams.
    if(nbr_tigs>0){
      sort(trigrams.begin(),trigrams.end());                        // Sort the trigrams
      out << line << " " << nbr_tigs  << " ";                       // Write to file
      for(int i = 0; i<nbr_tigs; i++){
        out << trigrams[i] << " ";
      } 
      out << "\n"; 
    }
    else{
      out << line << " " << 0 << " ";
      out << "\n";
    }
  }
  return 0;
}