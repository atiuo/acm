#pragma once
#include <tuple>
#include <vector>//尽量减少用指针，因为指针不好操控，所以定义数组就用vector
#include <optional> 
using namespace std;

//用类来抽象矩阵这个概念，让这个代码变得简洁好懂
class Matrix
{
//静态方法（公有的方法，和独立的对象无关）
public:
	//打印不是矩阵独一无二的属性，所以不定义为对象方法
	static void print(const Matrix& m);
	static Matrix mulptiple1(const Matrix& A, const Matrix& B);
    
//数据访问功能
public:
	//设置矩阵的维度，比如B矩阵用一半，想要改变B的size
	void setsize(unsigned int N, unsigned int M,float val = 0.0f);
	//获得矩阵维度信息
	std::tuple<unsigned int, unsigned int> getsize() const;
	//因为元素的值为private变量，所以要通过public函数来获得矩阵的元素的值 索引号从1开始
	float getElement(unsigned int i, unsigned int j) const;
	//设置矩阵的元素值 索引号从1开始
	void setElement(float val, unsigned int i, unsigned int j);

	//返回值是float类型的引用,意思是如果对返回值进行更改，引用的那个变量值也会直接跟着变
	float& element(unsigned int i, unsigned int j);
	
	//返回值是float类型的引用，即返回的值是一个左值
	float& operator()(unsigned int i, unsigned int j);


//构造
public:
	Matrix(unsigned int N, unsigned int M, float val = 0.0f);
	Matrix(std::vector<float> buff, unsigned int N, unsigned int M) ;

//成员数据
private:
	//实际数据
	std::vector<float> m_Data;
	//尺寸
	unsigned int m_N, m_M;// 矩阵维度不可能小于0，所以用unsigned int类型
};

Matrix operator*(const Matrix& A, const Matrix& B);

