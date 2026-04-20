#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        // Mapping of digits to letters
        vector<string> mapping = {
            "",     "",     "abc",  "def", 
            "ghi",  "jkl",  "mno",  "pqrs", 
            "tuv",  "wxyz"
        };
        
        vector<string> result;
        string current;
        backtrack(digits, mapping, 0, current, result);
        return result;
    }

private:
    void backtrack(const string& digits, const vector<string>& mapping, int index, string& current, vector<string>& result) {
        // Base case: if the current combination length equals digits length
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }

        // Get letters for the current digit
        string letters = mapping[digits[index] - '0'];
        for (char letter : letters) {
            current.push_back(letter);           // Choose
            backtrack(digits, mapping, index + 1, current, result); // Explore
            current.pop_back();                  // Un-choose (backtrack)
        }
    }
};