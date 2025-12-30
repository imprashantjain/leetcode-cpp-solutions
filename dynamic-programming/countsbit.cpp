#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            if (i % 2 == 0) {
                ans[i] = ans[i / 2];
            } else {
                ans[i] = ans[i / 2] + 1;
            }
        }
        return ans;
    }
};

int main() {
    int n;
    cout << "Enter your number: ";
    cin >> n;

    Solution obj;
    vector<int> result = obj.countBits(n);

    for (int i = 0; i <= n; i++) {
        cout << "Bits in " << i << " = " << result[i] << endl;
    }

    return 0;
}
