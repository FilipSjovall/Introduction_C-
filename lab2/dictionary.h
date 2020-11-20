#ifndef DICTIONARY_H
#define DICTIONARY_H
#define w_size 23
#include <string>
#include <vector>
#include <unordered_set>
#include "word.h"

class Dictionary {
public:
	Dictionary() ; // default *?
	std::unordered_set<std::string> wordlist;
	std::vector<Word> words[w_size];
	bool contains(const std::string& word) const;
	void add_trigram_suggestions(std::vector<std::string>& suggestions , const std::string& word) const;
	std::vector<std::string> get_suggestions(const std::string& word) const;
	
private:
};

#endif
