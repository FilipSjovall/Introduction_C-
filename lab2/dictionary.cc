#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <set>
#include "word.h"
#include "dictionary.h"
#include <sstream>
#include <iterator>
using namespace std;

Dictionary::Dictionary()
{
	fstream in("words.txt");
	unordered_set<string> wordlist;
	string line;
	// Extract chararcters until the delimiter ' ' is found
	while (getline(in, line))
	{
		string tmp = line.substr(0, line.find(" "));
		wordlist.insert(tmp);
	}

	// Fill words
	// Samma loop två gånger..... borde finnas ett bättre sätt.
	while (getline(in, line))
	{
		string tmp = line.substr(0, line.find(" "));
		wordlist.insert(tmp);
		vector<string> trigrams;
		string a = line.substr(line.find(" "), line.size());
		istringstream stream(a);
		string s;
		while (stream >> s)
		{
			trigrams.push_back(s); // Kunde använt iterator här?
		}
		words[tmp.length()].push_back(Word(tmp, trigrams));
	}
}

void get_trigrams(vector<string> trigrams, const string &line)
{ // &trigrams or not?
	if (line.size() > 2)
	{
		for (string::size_type i = 0; i < line.size() - 2; i++)
		{
			trigrams.push_back(line.substr(i, 3));
		}
	}
}

// Supposed to be fast
bool Dictionary::contains(const string &word) const
{
	// snabb???
	bool check = false;
	if (wordlist.find(word) != wordlist.end())
	{
		check = true;
	}
	return check;
}

vector<string> Dictionary::get_suggestions(const string &word) const
{
	// Speed is not a priority
	vector<string> suggestions;
	add_trigram_suggestions(suggestions, word);
	//rank_suggestions(suggestions, word);
	//trim_suggestions(suggestions);
	return suggestions;
}

void Dictionary::add_trigram_suggestions(vector<string> &suggestions, const string &word) const
{
	// Find suggestions which contain atleast half trigrams in word
	int l = word.length();
	vector<string> trigrams;
	get_trigrams(trigrams, word);

	for (int i = 0; i < words[l].size(); i++)
	{
		if (words[l][i].get_matches(trigrams) >= trigrams.size() / 2)
		{
			suggestions.push_back(words[l][i].get_word());
		}
	}
}

// get int element in pair
int get_first( pair<int, string> i ){ 
	return i.first; 
	}
// get string element
string get_second( pair<int, string> i ){ 
	return i.second; 
	}

void rank_suggestions(vector<string> &suggestions, const string &word)
{
	// sort the canditates
	vector<pair<int,string>> temp;
	for (int k = 0; k < suggestions.size(); k++)
	{
		int p = word.length();
		int q = suggestions[k].length();
		// Loop over cost
		int d[26][26] = {0};
		for (int i = 0; i < 26; i++)
		{
			for (int j = 0; j < 26; j++)
			{
				if (i == 0 && j != 0)
				{
					d[i][j] = i;
				}
				else if (i != 0 && j == 0)
				{
					d[i][j] = j;
				}
				int alt_1 = 10;
				if (p == q)
				{
					int alt_1 = d[i - 1][j - 1];
				}
				else
				{
					int alt_1 = d[i - 1][j - 1] + 1;
				}

				int alt_2 = d[i - 1][j] + 1;
				int alt_3 = d[i][j - 1] + 1;
				d[i][j] = min({alt_1,alt_2,alt_3});
			}
		}
		temp.push_back(make_pair(d[p][q],suggestions[k]));
	}
	std::sort(temp.begin(),temp.end(), get_first);
	for(int i=0;i<suggestions.size();i++){
		suggestions[i]=get_second(temp[i]);
	}
}

void trim_suggestions(vector<string> &suggestions)
{
	// suggestions should be kept to 5
}
