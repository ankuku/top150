#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        // Merge in reverse order
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            }
            else {
                nums1[k--] = nums2[j--];
            }
        }

        // For leftovers or when nums1 is empty
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    };

    void printArray(vector<int>& nums, int size) {
        cout << "[";
        for (int i = 0; i < size; i++) {
            cout << nums[i];
            if (i < size - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 2, 4, 7, 8, 9};
    int m = 3;
    vector<int> nums2 = {3, 4, 6};
    int n = 3;

    cout << "Before merging:\nnums1: ";
    sol.printArray(nums1, m+n);
    cout << "nums2: ";
    sol.printArray(nums2, n);

    sol.merge(nums1, m, nums2, n);

    cout << "After merging:\nnums1: ";
    sol.printArray(nums1, m+n);

    return 0;

}