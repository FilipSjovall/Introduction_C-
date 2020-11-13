#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include "word.h"
#include "dictionary.h"

using namespace std;


Dictionary::Dictionary() {
	fstream in;
	in.open("word.txt");
	string c;
	c >> in;
  unordered_set<string> wordlist;
	for(int i = 0; i<c.size(); i++){

	}
}


// Supposed to be fast
bool Dictionary::contains(const string& word) const { 
	bool check = false;
	return check;
}
vector<string> Dictionary::get_suggestions(const string& word) const {
	// Speed is not a priority
	vector<string> suggestions;
//	add_trigram_suggestions(suggestions, word);
//	rank_suggestions(suggestions, word);
//	trim_suggestions(suggestions);

	return suggestions;
}

void add_trigram_suggestions(vector<string>& suggestions , const string& word){
	// Find suggestions which contain atleast half trigrams in word
}

void rank_suggestions(vector<string>& suggestions , const string& word){
	// sort the canditates
}

void trim_suggestions(vector<string>& suggestions){
// suggestions should be kept to 5
}
