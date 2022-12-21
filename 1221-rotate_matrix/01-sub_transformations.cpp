#include<iostream>
#include<vector>
using namespace std;

// 上下对称
void upDownSymmetry(vector<vector<int>>& matrix, int n) {
    for (int i = 0; i < n/2; ++i) {
        for (int j = 0; j < n; ++j) {
            swap(matrix[i][j], matrix[n-i-1][j]);
        }
    }
}

// 左右对称
void leftRightSymmetry(vector<vector<int>>& matrix, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n/2; ++j) {
            swap(matrix[i][j], matrix[i][n-j-1]);
        }
    }
}

// 主对角线对称
void mainDiagSymmetry(vector<vector<int>>& matrix, int n) {
    for (int i = 0; i < n-1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

// 副对角线对称
void subDiagSymmetry(vector<vector<int>>& matrix, int n) {
    for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j < n-i-1; ++j) {
            swap(matrix[i][j], matrix[n-j-1][n-i-1]);
        }
    }
}

void rotate(vector<vector<int>>& matrix, int n){
    // 上下对称 + 主对角线对称
    upDownSymmetry(matrix, n);
    mainDiagSymmetry(matrix, n);

    // 主对角线对称 + 左右对称
    // mainDiagSymmetry(matrix, n);
    // leftRightSymmetry(matrix, n);

    // 左右对称 + 副对角线对称
    // leftRightSymmetry(matrix, n);
    // subdiagSymmetry(matrix, n);

    // 副对角线对称 + 上下对称
    // subdiagSymmetry(matrix, n);
    // upDownSymmetry(matrix, n);
}

int main() {
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    int n = matrix.size();

    rotate(matrix, n);
}