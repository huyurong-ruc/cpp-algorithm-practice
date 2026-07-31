#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> groups;

        for (size_t i = 0; i < strs.size(); ++i) {
            const string& s = strs[i];
            int cnt[26] = {0};   // 用传统数组，初始化为0

            // 遍历字符串每个字符
            for (size_t j = 0; j < s.size(); ++j) {
                cnt[s[j] - 'a']++;
            }

            // 构造 key
            string key;
            for (int k = 0; k < 26; ++k) {
                key += to_string(cnt[k]) + "#";
            }

            groups[key].push_back(s);
        }

        // 收集结果
        vector<vector<string>> ans;
        for (auto it = groups.begin(); it != groups.end(); ++it) {
            ans.push_back(move(it->second));
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<string> strs(n);
    for (int i = 0; i < n; ++i) {
        cin >> strs[i];
    }

    auto ans = Solution().groupAnagrams(strs);

    for (size_t i = 0; i < ans.size(); ++i) {
        const auto& group = ans[i];
        for (size_t j = 0; j < group.size(); ++j) {
            if (j != 0) cout << ' ';
            cout << group[j];
        }
        cout << '\n';
    }
    return 0;
}