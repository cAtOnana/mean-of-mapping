#include"mean-of-mapping.h"
#include<iostream>
#include<fstream>
int main(int argc,char* argv[]) {//����ΪĿ���Ŀ¼
	if (argc > 2){
		std::cout << "����������࣬�����˳���";
		exit(EXIT_FAILURE);
	}
	vector<list> file;
	getfile(argv[1], file);//char* ��string������ת����������
	std::cout << "һ���ҵ�" <<file.size() << "���ļ���";
	for (int i = 0; i < file.size(); i++){
		mean(file[i]);//���list.mean
	}
	std::string outfile_name = argv[1];
	outfile_name += +"��Ŀ¼ƽ��mapping�ʱ�.xls";
	ofstream outfile(outfile_name);
	outfile << "�ļ���" <<"	"<<"ƽ��mapping��" << std::endl;
	for (int i = 0; i < file.size(); i++)
		outfile << file[i].name << "	" << file[i].mean << std::endl;

	return 0;
}