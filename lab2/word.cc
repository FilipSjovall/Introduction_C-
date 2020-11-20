#include <string>
#include <vector>
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
	return string();
}

unsigned int Word::get_matches(const vector<string>& t) const {
	char c;
	unsigned int cnt = 0;
	
	for(int it = 0 ;it<t.size()-1; it++){
			if(find(trigrams.begin(), trigrams.end(), t[it]) != trigrams.end() && t[it] != t[it+1] ){
				cnt++;		
			}
	}

	return cnt+1;
}
