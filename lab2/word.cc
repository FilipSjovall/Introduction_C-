#include <string>
#include <vector>
#include "word.h"

using std::vector;
using std::string;

Word::Word(const string& w, const vector<string>& t) {

}

string Word::get_word() const {
	return string();
}

unsigned int Word::get_matches(const vector<string>& t) const {
	char c;
	unsigned int cnt = 0;
	
	// Alt 0
	cnt = t.size()-1;
	
	// Alt 1
	// cnt = (int)t[0][0]-'0'; // if the number of trigrams is included
	
	// ALT 2
	// for(string::size_type i = 0; i < t.size(); i++){ // if the number of trigrams is not included
	//	if(i==' '){
	//		cnt++;
	//	}
	//}
	return cnt+1;
}
