#include<iostream>
#include<vector>
#include<vector>
#include<sstream>
using namespace std;


int main() {
	string sentence = "This is a sample sentence to split into words.";
	stringstream iss(sentence);

	string word;
	vector<string> words;

	while (iss >> word) {
		words.push_back(word);
	}

	for (const string& w : words) {
		cout << w << endl;
	}

	return 0;
}