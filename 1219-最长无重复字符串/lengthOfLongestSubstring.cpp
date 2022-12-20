#include <iostream>
#include <unordered_set>
using namespace std;

void getLongestSubstring(string s) {
    // 哈希集合，记录每个字符是否出现过
    unordered_set<char> occ;

    // 记录 string 长度
    int n = s.size();

    // 右指针，初始值为 -1，相当于我们在字符串的左边界的左侧，还没有开始移动
    int end = -1;

    // 最重要返回的：子串长度数值，子串内容
    int ans = 0;
    string res = NULL;
    
    // 枚举左指针的位置，初始值隐性地表示为 -1
    for (int i = 0; i < n; ++i) {
        if (i != 0) {
            // 左指针向右移动一格，移除一个字符
            occ.erase(s[i - 1]);
        }
        while (end + 1 < n && !occ.count(s[end + 1])) {
            // 不断地移动右指针
            occ.insert(s[end + 1]);
            ++rk;
        }
        // 第 i 到 rk 个字符是一个极长的无重复字符子串
        ans = fmax(ans, rk - i + 1);
    }
    cout << ans << endl;
    // return ans;
}

int main(){
    string a = "abcccdaf";
    lengthOfLongestSubstring(a);
}