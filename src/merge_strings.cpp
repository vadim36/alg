#include <cstdlib>
#include <iostream>

using namespace std;

class Solution {
public:
	string mergeAlternately(string word1, string word2) {
		bool isValid{
			this->validateLength(word1, word2)
		};
		if (!isValid) return "";

		string res_word{ "" };
		int i{ 0 };

		while (i < word1.length() || i < word2.length()) {
			if (i < word1.length()) {
				res_word += word1[i];
			}

			if (i < word2.length()) {
				res_word += word2[i];
			}

			i++;
		}

		return res_word;
	}
private:
	bool validateLength(string word1, string word2) {
		if (word1.length() < 1 || word2.length() < 1) {
			cout << "Error: words are too small";
			return false;
		}

		if (word1.length() > 100 || word2.length() > 100) {
			cout << "Error: words are too big";
			return false;
		}

		return true;
	}
};
	

int main() {
	Solution solution{};
	string word1{}, word2{};
	cout << "Print 2 words: ";
	cin >> word1 >> word2;
	cout << "The result word is " 
		<< solution.mergeAlternately(word1, word2);
	
	return EXIT_SUCCESS;
}