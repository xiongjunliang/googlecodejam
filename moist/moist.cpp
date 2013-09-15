
#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution {
public:
    int moist(vector<string>& strs) {
        if (strs.size() <= 1) {
            return 0;
        }
        int cnt = 0;
        int lastidx = 0;
        for (int i = 1; i < strs.size(); ++i) {
            if (strs[i] < strs[lastidx]) {
                cnt += 1;
            } else {
                lastidx = i;
            }
        }
        return cnt;
    }
};

int main() {
    int T;
    cin >> T;
    int i = 1;
    Solution s;
    for (; i <= T; ++i) {
        int n;
        cin >> n;
        vector<string> v;
        string str;
        getline(cin, str);
        for (int j = 0; j < n; ++j) {
            getline(cin, str);
            v.push_back(str);
        }
        cout << "Case #" << i << ": " << s.moist(v) << endl;
    }
}
