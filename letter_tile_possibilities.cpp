#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    int backtrack(vector<int>& freq) {
        int count = 0;

        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                count++;
                freq[i]--;
                count += backtrack(freq);
                freq[i]++;
            }
        }

        return count;
    }

public:
    int numTilePossibilities(string tiles) {
        vector<int> freq(26, 0);
        for (char c : tiles) {
            freq[c - 'A']++;
        }
        return backtrack(freq);
    }
};

int main() {
    Solution sol;

    string tiles1 = "AAB";
    string tiles2 = "AAABBC";
    string tiles3 = "V";


    cout << "Possibilities for \"" << tiles1 << "\": " << sol.numTilePossibilities(tiles1) << endl;
    cout << "Possibilities for \"" << tiles2 << "\": " << sol.numTilePossibilities(tiles2) << endl;
    cout << "Possibilities for \"" << tiles3 << "\": " << sol.numTilePossibilities(tiles3) << endl;
    


    return 0;
}