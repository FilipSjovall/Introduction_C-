#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include "word.h"
#include <iterator>

using namespace std;

Word::Word(const string& w, const vector<string>& t) : dw{w}, trigrams{t}  {
	// const std::string dw = w;
	// const std::vector<std::string> trigrams = t;
	// Java-style... smidigare sätt för member variables?
}

string Word::get_word() const {
	return dw;
}

unsigned int Word::get_matches(const vector<string>& t) const {
	unsigned int cnt = 0;
	
	//for(unsigned int it = 0 ;it<t.size()-1; it++){	
		cout << trigrams.size() << "trigram size" << endl;
		for(auto tt: t){
			if(binary_search(trigrams.begin(), trigrams.end(), tt)  ){
				cnt ++;
			}
	//	}
	//		if(binary_search(trigrams.begin(), trigrams.end(), t[it])  ){ // innan find
				//if(t.at(it)!=t.at(it+1)){
	//				cnt++;	
				//}			
	//		}
	}
	return cnt;
}
