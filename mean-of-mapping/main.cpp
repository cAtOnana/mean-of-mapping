#include"mean-of-mapping.h"
#include<iostream>
#include<fstream>
int main(int argc,char* argv[]) {//参数为目标根目录
	if (argc > 2){
		std::cout << "输入参数过多，程序退出。";
		exit(EXIT_FAILURE);
	}
	vector<list> file;
	getfile(argv[1], file);//char* 到string的类型转换（提升）
	std::cout << "一共找到" <<file.size() << "个文件。";
	for (int i = 0; i < file.size(); i++){
		mean(file[i]);//填充list.mean
	}
	std::cout << "均值计算完毕。正在准备输出...";
	std::string outfile_name = argv[1];
	outfile_name += "\\本目录平均mapping率表.xls";
	ofstream outfile(outfile_name);
	outfile << "文件名" <<"	"<<"平均mapping率" <<"权重"<< std::endl;
	for (int i = 0; i < file.size(); i++)
		outfile << file[i].name << "	" << file[i].mean <<"	" <<file[i].rows<< std::endl;
	cout << "输出完毕，程序退出。";
	return 0;
}