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

void getfile(string path, vector<list>& files);//ץȡĳһĿ¼�������ļ����ļ���

void mean(list& f);//��log�ļ�����ȡmapping�ʼ���ƽ��ֵ��
							 //���ģ��ֱ��д��main������ͺ�