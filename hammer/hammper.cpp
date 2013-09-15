
#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    float hammer(double v, double d) {
        return asin(d*9.8/(v*v))*180.0/3.1415926/2;
    }
};


int main() {
    int T;
    cin >> T;
    int i = 1;
    Solution s;
    cout.precision (7);//设置有效小数6位
    cout.setf (ios::fixed);
    for (; i <= T; ++i) {
        float v;
        float d;
        cin >> v >> d;

        cout << "Case #" << i << ": " << s.hammer(v, d) << endl;
    }
    return 0;
}
