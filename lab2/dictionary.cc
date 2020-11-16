#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include "word.h"
#include "dictionary.h"
#include <sstream>

using namespace std;


Dictionary::Dictionary() {
	fstream in("words.txt");
	unordered_set<string> wordlist;
	string line;
	

	// Extract chararcters until the delimiter ' ' is found
	while( getline(in, line) ){
		string tmp = line.substr(0,line.find(" "));
		wordlist.insert(tmp);	
	}
	vector<Word> words[20];
	// Samma loop två gånger..... borde finnas ett bättre sätt.
	while( getline(in, line) ){
		string tmp = line.substr(0,line.find(" "));
		wordlist.insert(tmp);	
	
			vector<string> trigrams;
		string a = line.substr(line.find(" "), line.size());
		istringstream stream(a);
		string s;
		while(stream >> s){
			trigrams.push_back(s); // Kunde använt iterator här?
		}
		words[tmp.length()].push_back( Word(tmp, trigrams) );	
		}
}


// Supposed to be fast
bool Dictionary::contains(const string& word) const { 
	// snabb???
	bool check = false;
	if(wordlist.find(word)!= wordlist.end()){
		check=true;
	}
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
