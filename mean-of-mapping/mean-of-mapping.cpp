#include "mean-of-mapping.h"
#include<fstream>
#include<iostream>

///
#include<io.h>
void getfile(string path, vector<list>& files)
{
	///������Կ�����һ�ֶ�����ָ��ķ�װ���ڴ���Դ����ʱ�������ݵ������ڴ��ַ�����Ķ������Ż��ռ����ã��ʶ������ڴ��ַ���䣬���ڴ��������鷳
	///�����Ҫ������ġ������ָ��������ġ������ڴ��ַ��Ϊ�ڴ�������������
	long   hFile = 0;//�ļ����  
	//�ļ���Ϣ  
	struct _finddata_t fileinfo;
	string p;
	if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1)//�ҵ���һ���ļ��Ļ�������ѭ��
																					//assign()������string������ַ���������+�������c_str()��string��Ϊconst char*���˴�ʹ�������Ϻ���Ҫ��
	{
		int count = 0;//��¼��Ŀ¼���ļ�����
		do
		{
			//�����Ŀ¼,����֮  
			//�������,�����б�  
			if ((fileinfo.attrib &  _A_SUBDIR))//�����&������Ծɲ�֪����ʲô��˼
			{
				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
					getfile(p.assign(path).append("\\").append(fileinfo.name), files);//��˫��б������Ϊ��һ����б�ܱ�ʾ���������ķ��������⹦�ܡ�������\t \aһ����
			}
			else
			{
				list temp = { p.assign(path).append("\\").append(fileinfo.name),0.0 };//����push_back()ֻ����һ�����������Ҫ����һ����ʱlist��������������ݡ�
				files.push_back(temp);//push_back()����������vector�����һ��Ԫ��
									  //����ѹ��һ����Ԫ��,�˴���ζ���ҵ���һ�����ļ�����Ԫ�ؼ����ļ���ȫ·����&��ʼ����meanֵ��0.0
				count++;//����
			}
		} while (_findnext(hFile, &fileinfo) == 0);
		_findclose(hFile);
		
	}
}
///
void mean(list& f)
{
	using namespace std;
	ifstream infile(f.name);
	if (!infile.is_open())
	{
		cout << "�ļ�" << f.name << "��ʧ�ܣ��������ڲ��ڴ�Ŀ¼�л����𻵡�" << "�����˳���";
		exit(EXIT_FAILURE);
	}
	string waste;
	for (int i = 0; i < 31; i++)//������Ϣ���ܵĲ���
		getline(infile, waste);
	///
	double total=0.0;
	int times=0;
	while (!infile.eof()) {
		do {
			continue;
		} while (infile.get() != '('&&!infile.eof());//���������Ž�������mapping��֮ǰ�����������ַ�������eof������ѭ��
		
		double temp=0;
		infile >> temp;//ץȡmapping��
		total += temp;
		string w_waste;
		getline(infile, w_waste);
		times++;
	}
	f.mean = total / (--times);//log�ļ������һ�в�����mapping����Ϣ���Դ˽���������
	f.rows = times;
}
