#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

class Solution {
private:
    void backtrack(int index, string& s, vector<string>& result) {
        if (index == s.length()) {
            result.push_back(s);
            return;
        }

        if (isdigit(s[index])) {
            backtrack(index + 1, s, result);
            return;
        }

        s[index] = tolower(s[index]);
        backtrack(index + 1, s, result);

        s[index] = toupper(s[index]);
        backtrack(index + 1, s, result);
    }

public:
    vector<string> letterCasePermutation(string s) {
        vector<string> result;
        backtrack(0, s, result);
        return result;
    }
};

int main() {
    Solution sol;

    string s1 = "a1b2";
    string s2 = "3z4";


    vector<string> res1 = sol.letterCasePermutation(s1);
    cout << "Permutations for \"" << s1 << "\":" << endl;
    for (const string& str : res1) {
        cout << "- " << str << endl;
    }

    vector<string> res2 = sol.letterCasePermutation(s2);
    cout << "\nPermutations for \"" << s2 << "\":" << endl;
    for (const string& str : res2) {
        cout << "- " << str << endl;
    }

    return 0;
}