#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
private:
    bool backtrack(int index, const vector<int>& matchsticks, vector<int>& sides, int target) {
        if (index == matchsticks.size()) {
            return sides[0] == target && sides[1] == target && 
                   sides[2] == target && sides[3] == target;
        }

        for (int i = 0; i < 4; i++) {
            if (sides[i] + matchsticks[index] > target) {
                continue;
            }

            bool skip = false;
            for (int j = 0; j < i; j++) {
                if (sides[j] == sides[i]) {
                    skip = true;
                    break;
                }
            }
            if (skip) continue;

            sides[i] += matchsticks[index];

            if (backtrack(index + 1, matchsticks, sides, target)) {
                return true;
            }

            sides[i] -= matchsticks[index];
        }

        return false;
    }

public:
    bool makesquare(vector<int>& matchsticks) {
        if (matchsticks.size() < 4) return false;

        long long totalSum = 0;
        for (int length : matchsticks) {
            totalSum += length;
        }

        if (totalSum % 4 != 0) return false;

        int target = totalSum / 4;
        sort(matchsticks.rbegin(), matchsticks.rend());

        if (matchsticks[0] > target) return false;

        vector<int> sides(4, 0);
        return backtrack(0, matchsticks, sides, target);
    }
};

int main() {
    Solution sol;

    vector<int> matchsticks1 = {1, 1, 2, 2, 2};
    vector<int> matchsticks2 = {3, 3, 3, 3, 4};


    cout << "Square ban sakta hai {1, 1, 2, 2, 2}? " << (sol.makesquare(matchsticks1) ? "True" : "False") << endl;
    cout << "Square ban sakta hai {3, 3, 3, 3, 4}? " << (sol.makesquare(matchsticks2) ? "True" : "False") << endl;

    return 0;
}