#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> freq(n + 1, 0);

        for (int i = 0; i < n; i++) {
            citations[i] >= n ? freq[n]++ : freq[citations[i]]++;
        }

        int total = 0;
        for (int i = n; i >= 0; i--) {
            total += freq[i];
            if (total >= i) {
                return i;
            }
        }
        return 0;
    }
};

int main() {
    vector<int> citations = {3, 0, 6, 1, 5};
    Solution sol;
    cout << sol.hIndex(citations) << endl;
}