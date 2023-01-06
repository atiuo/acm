#include<iostream>
#include<vector>
#include <cctype> //判断字符类型需要的头文件
using namespace std;


// 输出数组
void output_matrix(vector<vector<int>> vectors){
    if (vectors.size()==0){
        cout<<"null"<<endl;
    }
    for (int i=0; i<vectors.size(); i++){
        cout <<"[";
        for (int j=0; j<vectors[i].size(); j++){
            cout << vectors[i][j] <<", " ;
        }
        cout <<"]" <<endl;
    }
}

// 根据起始数值，将所有区间按从大到小的顺序排列
vector<vector<int>> Bubble(vector<vector<int>> intervals){
    sort(intervals.begin(), intervals.end());
    return intervals;
}

// 判断区间是否重叠
bool existOverlap(vector<vector<int>> intervals) {
    // 将区间按照会议开始实现升序排序
    sort(intervals.begin(), intervals.end());
    // 遍历，如果下一个在前一个结束之前就开始了，返回 false。
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] < intervals[i - 1][1]) {
            return true;
        }
    }
    return false;
}

// 合并有重叠的区间
vector<vector<int>> merge_overlaps(vector<vector<int>>& intervals) {
    // 输入检查
    if (intervals.size() == 0) {
        return {};
    }
    // 确保有序
    sort(intervals.begin(), intervals.end());

    // 开始合并
    vector<vector<int>> merged;
    for (int i = 0; i < intervals.size(); ++i) {
        cout<<"\n"<<i<<"-th loop:"<<endl;

        // 取第 i 个区间的起止两个数值
        int L = intervals[i][0], R = intervals[i][1];
        cout<<"L&R: "<<L<<", "<<R<<endl;

        // 检查 merged 长度 [以下五行为 debug 使用，正式上线可注释掉]
        if (merged.size()!=0){
            cout<<"merged.back(): "<<merged.back()[1]<<endl;
        }
        cout<<"merged.size(): "<<merged.size()<<endl;
        cout<<"merged array:"<<endl;
        output_matrix(merged);

        // note: “或” 优先级 高于 “大于小于号”
        // 如果当前区间的左端点 L, 在数组 merged 中最后一个区间的右端点之后, 则不会重合，直接将该区间加入数组 merged 的末尾
        // 如果 merged 数组为空, 直接将这个区间加入数组 merged 的末尾
        if (!merged.size() || merged.back()[1] < L) 
        {
            merged.push_back({L, R});
        }
        else {
            merged.back()[1] = max(merged.back()[1], R);
        }
        cout<<"updated merged array:"<<endl;
        output_matrix(merged);
    }
    return merged;
}

// 删除被完全覆盖的

vector<vector<int>> delete_overlaps(vector<vector<int>>& intervals) {
    // 输入检查
    if (intervals.size() == 0) {
        return {};
    }
    // 确保有序
    sort(intervals.begin(), intervals.end());
    cout<<"original intervals:"<<endl;
    output_matrix(intervals);

    // 开始合并
    vector<vector<int>> overlaps_deleted;
    for (int i = 0; i < intervals.size(); ++i) {
        // cout<<"\n"<<i<<"-th loop:"<<endl;

        // 取第 i 个区间的起止两个数值，存入 L 和 R
        // 此次循环判断对象为 L、R 和 overlaps_deleted 中的元素
        int L = intervals[i][0], R = intervals[i][1];

        // // 检查 deleted 长度 [以下五行为 debug 使用，正式上线可注释掉]
        // // if (overlaps_deleted.size()!=0){
        // //     cout<<"deleted.back(): "<<overlaps_deleted.back()[1]<<endl;
        // // }
        // cout<<"deleted array:"<<endl;
        // output_matrix(overlaps_deleted);
        
        // note: 
        // “或” 优先级 高于 “大于小于号”
        // 当前区间的左端点: L
        // 将当前区间加入结果列表的末尾: deleted.push_back({left_number, right_number})
        // 判断：
        // 如果 L 在数组 deleted 中最后一个区间的右端点之后(<L), 则不会重合，push 当前区间
        if (overlaps_deleted.size()==0){
            overlaps_deleted.push_back({L, R});
        } 
        // 如果新的区间已经被 overlaps_deleted 最后一个区间包裹，跳过当前区间
        else{
            // printf("当前区间: [%d, %d], 已存储的最后一个区间: [%d, %d]\n", L, R, overlaps_deleted.back()[0], overlaps_deleted.back()[1]);
            if (overlaps_deleted.back()[0] <=L && overlaps_deleted.back()[1] >= R)
                continue;
            else
                overlaps_deleted.push_back({L, R});
        }
            
        

        // cout<<"updated deleted array:"<<endl;
        // output_matrix(overlaps_deleted);
    }
    return overlaps_deleted;
}


int main(void){
    vector<vector<int>> intervals = {{1,3},{4,6},{7,9}, {2,5}, {4,5}};
    // cout<<"\noriginal vectors:"<<endl;
    // output_matrix(intervals);

    // vector<vector<int>> sorted = Bubble(intervals);
    // cout<<"\nbubbled vectors:"<<endl;
    // output_matrix(sorted);

    // cout<<"\nif exist overlap: "<<existOverlap(intervals)<<endl;
    
    // vector<vector<int>> merged = merge_overlaps(intervals);
    // cout<<"\nmerged vectors:"<<endl;
    // output_matrix(merged);

    vector<vector<int>> deleted = delete_overlaps(intervals);
    cout<<"\ndeleted intervals:"<<endl;
    output_matrix(deleted);

}