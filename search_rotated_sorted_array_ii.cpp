#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool search(const vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                return true;
            }

            // Edge Case: Handling Duplicates where low, mid, and high are equal
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                high--;
                continue;
            }

            // Check if Left Half is Sorted
            if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1; // Target lies in left sorted half
                } else {
                    low = mid + 1;  // Target lies in right half
                }
            } 
            // Otherwise, Right Half must be Sorted
            else {
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;  // Target lies in right sorted half
                } else {
                    high = mid - 1; // Target lies in left half
                }
            }
        }

        return false;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Duplicates with target present
    vector<int> nums1 = {2, 5, 6, 0, 0, 1, 2};
    int target1 = 0;
    bool result1 = sol.search(nums1, target1);

    // Test Case 2: Duplicates with target absent
    vector<int> nums2 = {2, 5, 6, 0, 0, 1, 2};
    int target2 = 3;
    bool result2 = sol.search(nums2, target2);

    // Test Case 3: Tricky Duplicate Case (all boundary elements same)
    vector<int> nums3 = {1, 0, 1, 1, 1};
    int target3 = 0;
    bool result3 = sol.search(nums3, target3);

    cout << "===========================================" << endl;
    cout << "--- SEARCH IN ROTATED SORTED ARRAY II ---" << endl;
    cout << "===========================================" << endl;
    cout << "Test Case 1 (Target = 0): " << (result1 ? "Found (True)" : "Not Found (False)") << endl;
    cout << "Test Case 2 (Target = 3): " << (result2 ? "Found (True)" : "Not Found (False)") << endl;
    cout << "Test Case 3 (Target = 0): " << (result3 ? "Found (True)" : "Not Found (False)") << endl;

    return 0;
}