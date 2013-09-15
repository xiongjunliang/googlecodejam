#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long minscala(vector<int>& v1, vector<int>& v2) {
        long long ret = 0;
        int n = v1.size();
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        for (int i = 0; i < n; ++i) {
            ret += (long long)v1[i] * (long long)v2[n-i-1];
        }
        return ret;
    }

};

int main() {
    int T;
    cin >> T;
    int i = 1;
    Solution s;
    for (;i <= T; ++i) {
        int n;
        int x;
        cin >> n;
        vector<int> v1;
        vector<int> v2;
        for (int j = 0; j < n; ++j) {
            cin >> x;
            v1.push_back(x);
        }
        for (int j = 0; j < n; ++j) {
            cin >> x;
            v2.push_back(x);
        }
        long long ret = s.minscala(v1, v2);
        cout << "Case #" << i << ": " << ret << endl;
    }
    return 0;
}


