#include <iostream>
#include <unordered_map>
using namespace std;

void HashSolution(string s) {
    // 记录 string 长度
    int n = s.size();

    // 左右指针
    int left = 0, right = 0;
    // 临时记录当前子串的长度，用于与最长子串做对比
    int length=0;

    // 最终要返回的：子串长度数值
    int ans = 0;
    // 目标子串的起止点
    int finalStart=0, finalEnd=0;

    // hash table
    unordered_map<char, int> hash;
    
    // 只要 右指针数值小于数组长度，就继续
    while (right < n) {
        // 获取右指针指向的字符 rightestChar
        char rightestChar = s[right];

        // 仅当s[start,end) 中，存在s[end]时，更新start
        if (hash.find(rightestChar) != hash.end() && hash[rightestChar] >= left)
        {
            left = hash[rightestChar] + 1;
            length = right - left;
        }
        hash[rightestChar] = right;

    
        // 不断地移动右指针
        right++;
        length++;

        if (length>ans){
            // 说明当前的子串是最大的，要更新 ans
            ans = length;
            // 记录其起止点
            finalStart = left;
            finalEnd = right;
        }
    }

    string res;
    for (int flag=finalStart; flag<finalEnd; flag++)
        res.append(1, s[flag]);
    
    cout << "input string:"<<s<<endl;
    cout <<"finalStart:"<<finalStart<<endl;
    cout <<"finalEnd:"<<finalEnd<<endl;
    cout << "longest non-repest sub string:"<<res<<endl;
    cout << "length:"<<ans << endl;
    // return ans;
}

int main(){
    string a = "abcdafggaccd";
    // string a = "";
    HashSolution(a);
}