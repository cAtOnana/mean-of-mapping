#pragma once
#include<string>
#include<vector>
using namespace std;

struct list
{
	std::string name;
	double mean;
	int rows;
};

void getfile(string path, vector<list>& files);//抓取某一目录下所有文件的文件名

void mean(list& f);//打开log文件，提取mapping率计算平均值。
							 //输出模块直接写在main（）里就好