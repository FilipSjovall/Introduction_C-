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
	string line;

	while (getline(in, line))
	{
		string tmp = line.substr(0, line.find(" "));
		wordlist.insert(tmp);
		vector<string> trigrams;
		string a = line.substr(line.find(" ",2), line.size()-1);
		istringstream stream(a);
		string s;
		while (stream >> s)
		{
			trigrams.push_back(s); // Kunde använt iterator här?
		}
		words[tmp.length()].push_back(Word(tmp, trigrams));
	}
}

void get_trigrams(vector<string> &trigrams, const string &line)
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
	//cout << words[word.length()] << endl;
	bool check = false;
	if (wordlist.find(word) != wordlist.end())
	{
		check = true;
	}
	return check;
}

void Dictionary::add_trigram_suggestions(vector<string> &suggestions, const string &word) const
{
	// Find suggestions which contain atleast half trigrams in word
	int l = word.length();
	vector<string> trigrams;
	get_trigrams(trigrams, word);
	if(word.length()>3){
		for (unsigned int i = 0; i < words[l].size()-1; i++)
		{
			for(unsigned int k=0; k<4;k++){	
				if(words[l-2+k].begin()!=words[l-2+k].end()){	// if not empty	
					if (words[l-2+k][i].get_matches(trigrams) >= trigrams.size() / 2 )
					{
						suggestions.push_back(words[l][i].get_word());
					}
				}
			}
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


bool myComparison(const pair<int,string> &a,const pair<int,string> &b)
{
       return a.first<b.first;
}

void Dictionary::rank_suggestions(vector<string> &suggestions, const string &word) const{
	// sort the canditates
	vector<pair<int,string>> temp;
	
	for (unsigned int k = 0; k < suggestions.size(); k++)
	{
		int alt_1 = 1000;
		int alt_2 = 1000;
		int alt_3 = 1000;
		int p = word.length();
		int q = suggestions[k].length();
		// Loop over cost
		int d[26][26] = {0};
		for(int i=0; i<26; i++){
			d[i][0] = i;
		}
		for(int i=0; i<26; i++){
			d[0][i] = i;
		}
		for (int i = 1; i < p; i++)
		{
			for (int j = 1; j < q; j++)
			{
				//if (word.at(i-1)==suggestions[k].at(j-1))
				if (word[i-1]==suggestions[k][j-1])
				{
					alt_1 = d[i - 1][j - 1];
				}
				else
				{
					alt_1 = d[i - 1][j - 1] + 1;
				}
				
			//	int alt_2 = d[i - 1][j] + 1;
			//	int alt_3 = d[i][j - 1] + 1;
				
				d[i][j] = min({alt_1, d[i-1][j]+1, d[i][j-1]+1});

				cout << d[i][j] << endl;
			}
		}
		temp.push_back(make_pair(d[p-1][q-1],suggestions[k]));
	}
	std::sort(temp.begin(),temp.end(),myComparison);
	for(unsigned int i=0;i<suggestions.size();i++){
		suggestions[i]=get_second(temp[i]);
	}
}

void Dictionary::trim_suggestions(vector<string> &suggestions) const{
	// suggestions should be kept to 5
	if(suggestions.size()>5){
		suggestions.erase(suggestions.begin()+5,suggestions.end());
	}
}

vector<string> Dictionary::get_suggestions(const string &word) const
{
	// Speed is not a priority
	vector<string> suggestions;
	add_trigram_suggestions(suggestions, word);
	rank_suggestions(suggestions, word);
	trim_suggestions(suggestions);
	return suggestions;
}