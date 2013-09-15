
#include <iostream>
#include <set>
#include <vector>
#include <deque>
#include <tr1/unordered_map>
#include <tr1/unordered_set>

using namespace std;

using std::tr1::unordered_set;
using std::tr1::unordered_map;

class Solution {
public:
    bool badhorse(vector<string>& v1, vector<string>& v2) {
        unordered_map<string, int> idx;
        unordered_map<int, unordered_set<int> > rule;
        int n = v1.size();
        int id = 0;
        for (int i = 0; i < n; ++i) {
            if (idx.find(v1[i]) == idx.end()) {
                idx.insert(make_pair(v1[i], id));
                id ++;
            }
            if (idx.find(v2[i]) == idx.end()) {
                idx.insert(make_pair(v2[i], id));
                id ++;
            }
            unordered_map<int, unordered_set<int> >::iterator iter;
            iter = rule.find(idx[v1[i]]);
            if (iter != rule.end()) {
                iter->second.insert(idx[v2[i]]);
            } else {
                rule.insert(make_pair(idx[v1[i]], unordered_set<int>()));
                rule[idx[v1[i]]].insert(idx[v2[i]]);
            }
            iter = rule.find(idx[v2[i]]);
            if (iter != rule.end()) {
                iter->second.insert(idx[v1[i]]);
            } else {
                rule.insert(make_pair(idx[v2[i]], unordered_set<int>()));
                rule[idx[v2[i]]].insert(idx[v1[i]]);
            }
        }
        vector<int> color(id, -1);
        deque<int> q;
        while (1) {
            int next = -1;
            if (!q.empty()) {
                next = q.front();
                q.pop_front();
            } else {
                for (int i = 0; i < id; ++i) {
                    if (color[i] == -1) {
                        next = i;
                        color[i] = 0;
                        break;
                    }
                }
            }
            if (next == -1) {
                break;
            }
            int new_color = (color[next]+1)%2;
            unordered_set<int>::iterator iter = 
                rule[next].begin();
            for(; iter != rule[next].end(); ++iter) {
                if (color[*iter] == -1) {
                    color[*iter] = new_color;
                    q.push_back(*iter);
                } else if (color[*iter] != new_color){
                    return false;
                } 
            }
        }
        return true;
    }

};

int main() {
    int T;
    cin >> T;
    int i = 1;
    Solution s;
    for (;i <= T; ++i) {
        int n;
        cin >> n;
        vector<string> v1;
        vector<string> v2;
        string s1;
        string s2;
        while (n--) {
            cin >> s1 >> s2;
            v1.push_back(s1);
            v2.push_back(s2);
        }
        if (s.badhorse(v1, v2)) {
            cout << "Case #" << i << ": Yes" << endl;
        } else {
            cout << "Case #" << i << ": No" << endl;
        }
    }
    return 0;
}


