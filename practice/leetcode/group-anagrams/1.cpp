/**
 * Author by Rainboy blog: https://rainboylv.com github: https://github.com/rainboylvx
 * rbook: -> https://rbook.roj.ac.cn  https://rbook2.roj.ac.cn
 * rainboy的学习导航网站: https://idx.roj.ac.cn
 * create_at: 2026-07-28 21:58
 * update_at: 2026-07-28 21:58
 */
// main.cpp：26 字母计数 key，每组异位词只需 O(k) 构造 key。
#include <iostream>
#include <map>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        map<string, vector<string>> groups;
        for (int i=0;i<strs.size();i++) {
            string s = strs[i];
            int cnt[30]={0};
            for (int j=0;j<s.size();j++){
                char ch=s[j];
                cnt[ch - 'a']++;
            string key;
            for (int k=0;k<26;k++){
                int c=cnt[k];
                key += to_string(c) + "#";
            groups[key].push_back(s);
        }
        vector<vector<string>> ans;
        // for (int x=0;x<groups.size();x++){
        //     vector<vector<string>> v=groups[x];
        //     ans.push_back(move(v));
        // return ans;
        
        for (auto it = groups.begin(); it != groups.end(); ++it) { //遍历映射必须用begin->end
            ans.push_back(move(it->second));
            // move是移动语义，it是指针，it->second即值
            // 不move就复制过去，move就不用搬
        }
        return ans;
    }
};

// 本地测试 adapter，提交 LeetCode 时只保留 Solution 类
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<string> strs(n);
    for (int i = 0; i < n; i++)
        cin >> strs[i];

    auto ans = Solution().groupAnagrams(strs);
    for (auto &group : ans) {
        for (size_t i = 0; i < group.size(); i++) {
            if (i)
                cout << ' ';
            cout << group[i];
        }
        cout << '\n';
    }
    return 0;
}