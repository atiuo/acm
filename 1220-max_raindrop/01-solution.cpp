#include<iostream>
#include<vector>
using namespace std;

int maxArea(vector<int>& height) {
    // 左右指针
    int i(0), j = height.size() - 1, temp(0);
    // 最终要返回的结果，存储的是在已经计算过的情形中，能接到的最大雨量
    int res(0), final_pointer_left(0), final_pointer_right(0);

    // 详细写法
    // 只要两个指针没有相遇，就可以继续
    while (i<j){
        // 主要思想：移动短边(i就是加，j就是减)
        if (height[i] < height[j]){
            temp = (j - i) * height[i];
            if (temp>res){
                res = temp;
                final_pointer_left = i;
                final_pointer_right = j;
            }
            i++;
        }
        else{
            temp = (j - i) * height[j];
            if (temp>res){
                res = temp;
                final_pointer_left = i;
                final_pointer_right = j;
            }
            j--;
        }
        // printf("temp:%d, res:%d\n", temp, res);
        // printf("i:%d, j:%d\n",i, j);
        // printf("final_pointer_left:%d, final_pointer_right:%d\n",final_pointer_left, final_pointer_right);
    }

    // 另一种更简约的写法
    // while(i < j) {
    //     res = height[i] < height[j] ? 
    //         max(res, (j - i) * height[i++]): 
    //         max(res, (j - i) * height[j--]); 
    // }

    return res;
}

int main(){
    vector<int> heights={1,8,6,2,5,4,8,3,7};
    // vector<int> heights={1,8,3,7};
    int res = maxArea(heights);
    printf("%d", res);
}
