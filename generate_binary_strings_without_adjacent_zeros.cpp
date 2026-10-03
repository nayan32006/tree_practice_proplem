#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    void backtrack(int n, string& current, vector<string>& result) {
        if (current.length() == n) {
            result.push_back(current);
            return;
        }

        current.push_back('1');
        backtrack(n, current, result);
        current.pop_back();

        if (current.empty() || current.back() != '0') {
            current.push_back('0');
            backtrack(n, current, result);
            current.pop_back();
        }
    }

public:
    vector<string> validStrings(int n) {
        vector<string> result;
        string current = "";
        backtrack(n, current, result);
        return result;
    }
};

int main() {
    Solution sol;

    int n1 = 3;
    int n2 = 1;


    vector<string> res1 = sol.validStrings(n1);
    cout << "Valid binary strings of length " << n1 << ":" << endl;
    for (const string& s : res1) {
        cout << "- " << s << endl;
    }

    vector<string> res2 = sol.validStrings(n2);
    cout << "\nValid binary strings of length " << n2 << ":" << endl;
    for (const string& s : res2) {
        cout << "- " << s << endl;
    }

    return 0;
}