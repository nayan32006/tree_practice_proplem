#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMin(const vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] > nums[high]) {
                // Minimum must be in the right unsorted part
                low = mid + 1;
            } else if (nums[mid] < nums[high]) {
                // Minimum is at mid or in the left part
                high = mid;
            } else {
                // nums[mid] == nums[high]: Ambiguous due to duplicates, shrink high
                high--;
            }
        }

        return nums[low];
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard Rotated Array with Duplicates
    vector<int> nums1 = {2, 2, 2, 0, 1, 2};
    int min1 = sol.findMin(nums1);

    // Test Case 2: Tricky Duplicates (Minimum in middle surrounded by duplicates)
    vector<int> nums2 = {10, 1, 10, 10, 10};
    int min2 = sol.findMin(nums2);

    // Test Case 3: Fully duplicate elements
    vector<int> nums3 = {3, 3, 3, 3, 3};
    int min3 = sol.findMin(nums3);

    cout << "=================================================" << endl;
    cout << "--- FIND MINIMUM IN ROTATED SORTED ARRAY II ---" << endl;
    cout << "=================================================" << endl;
    cout << "Test Case 1 [2, 2, 2, 0, 1, 2]   -> Minimum: " << min1 << endl;
    cout << "Test Case 2 [10, 1, 10, 10, 10]  -> Minimum: " << min2 << endl;
    cout << "Test Case 3 [3, 3, 3, 3, 3]      -> Minimum: " << min3 << endl;

    return 0;
}