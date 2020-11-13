#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <vector>
#include <unordered_set>

class Dictionary {
public:
	Dictionary(); // default *?
	std::unordered_set<std::string> wordlist;
	bool contains(const std::string& word) const;
	std::vector<std::string> get_suggestions(const std::string& word) const;
private:
};

#endif