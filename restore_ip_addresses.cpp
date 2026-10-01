#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    void backtrack(int start, int dots, string& current, const string& s, vector<string>& ans) {
        if (dots == 4) {
            if (start == s.length()) {
                current.pop_back();
                ans.push_back(current);
            }
            return;
        }

        for (int len = 1; len <= 3; len++) {
            if (start + len > s.length()) break;

            string segment = s.substr(start, len);
            if (len > 1 && segment[0] == '0') break;
            if (stoi(segment) > 255) break;

            int original_len = current.length();
            current += segment + ".";

            backtrack(start + len, dots + 1, current, s, ans);

            current.erase(original_len);
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        if (s.length() < 4 || s.length() > 12) return ans;

        string current = "";
        backtrack(0, 0, current, s, ans);

        return ans;
    }
};

int main() {
    Solution sol;

    string s1 = "25525511135";
    string s2 = "0000";
    string s3 = "101023";


    vector<string> res1 = sol.restoreIpAddresses(s1);
    cout << "Restored IPs for \"" << s1 << "\":" << endl;
    for (const string& ip : res1) cout << ip << endl;

    vector<string> res2 = sol.restoreIpAddresses(s2);
    cout << "\nRestored IPs for \"" << s2 << "\":" << endl;
    for (const string& ip : res2) cout << ip << endl;

    vector<string> res3 = sol.restoreIpAddresses(s3);
    cout << "\nRestored IPs for \"" << s3 << "\":" << endl;
    for (const string& ip : res3) cout << ip << endl;

    return 0;
}