#include "mean-of-mapping.h"
#include<fstream>
#include<iostream>

///
#include<io.h>
void getfile(string path, vector<list>& files)
{
	///句柄可以看作是一种对物理指针的封装。内存资源管理时常对数据的物理内存地址作出改动以最优化空间利用，故而物理内存地址常变，对内存管理带来麻烦
	///因此需要“不变的”句柄来指代“常变的”物理内存地址，为内存管理带来便利。
	long   hFile = 0;//文件句柄  
	//文件信息  
	struct _finddata_t fileinfo;
	string p;
	if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1)//找到第一个文件的话，进入循环
																					//assign()用于往string后面加字符串，类似+运算符；c_str()将string变为const char*，此处使参数符合函数要求
	{
		int count = 0;//记录此目录下文件个数
		do
		{
			//如果是目录,迭代之  
			//如果不是,加入列表  
			if ((fileinfo.attrib &  _A_SUBDIR))//这里的&运算符仍旧不知道是什么意思
			{
				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
					getfile(p.assign(path).append("\\").append(fileinfo.name), files);//用双反斜杠是因为第一个反斜杠表示“接下来的符号有特殊功能”，就像\t \a一样。
			}
			else
			{
				list temp = { p.assign(path).append("\\").append(fileinfo.name),0.0 };//由于push_back()只接受一个参数，因此要建立一个临时list变量来存放新数据。
				files.push_back(temp);//push_back()函数用于往vector的最后一个元素
									  //后面压入一个新元素,此处意味着找到了一个新文件。此元素即新文件的全路径名&初始化的mean值，0.0
				count++;//计数
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
		cout << "文件" << f.name << "打开失败，可能由于不在此目录中或已损坏。" << "程序退出。";
		exit(EXIT_FAILURE);
	}
	string waste;
	for (int i = 0; i < 31; i++)//跳过信息介绍的部分
		getline(infile, waste);
	///
	double total=0.0;
	int times=0;
	while (!infile.eof()) {
		do {
			continue;
		} while (infile.get() != '('&&!infile.eof());//遇到左括号进而遇到mapping率之前，跳过所有字符；遇到eof则跳出循环
		
		double temp=0;
		infile >> temp;//抓取mapping率
		total += temp;
		string w_waste;
		getline(infile, w_waste);
		times++;
	}
	f.mean = total / (--times);//log文件的最后一行不包含mapping率信息，对此进行修正。
	f.rows = times;
}
