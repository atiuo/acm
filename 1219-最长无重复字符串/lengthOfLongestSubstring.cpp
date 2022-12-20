#include <iostream>
#include <unordered_set>
using namespace std;

void SlidingWindow(string s) {
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
    
    // 只要 右指针数值小于数组长度，就继续
    while (right < n) {
        // 获取右指针指向的字符 rightestChar
        char rightestChar = s[right];
        // 遍历当前窗口中的元素，检查是否存在与 rightestChar 相同的元素
        for (int index = left; index < right; index++)
        {
            char tmpChar = s[index];
            // 如果存在重复元素
            if (rightestChar == tmpChar){
                // 就移动左指针到相同元素 index 之后的位置
                left = index + 1;
                // 并记录当前字符串的长度
                length = right - left;
                // 终止当前的 for 循环
                break;
            }
        }
    
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
    // string a = "abcdafggaccd";
    string a = "";
    SlidingWindow(a);
}