#include "stdafx.h"
#include <cstring>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

int* get_array(int n)
{
	int* mas = new int [n];
	if (n > 0)
	{
		mas[0] = 1;
	}
	if (n > 1)
	{
		mas[1] = 1;
	}
	if (n > 2)
	{
	for (int  i = 2; i < n; i++)
	{
		mas[i] = mas[i-2] + mas[i-1];
	}
	}
	return mas;
	delete[]mas;
}

void task2(int file_id)
{
	std::ostringstream ostr;
	ostr << file_id;
	std::string str_num = ostr.str();
	std::string part_output = "output_";
	std::string part_input = "input_";
	std::string part_2 = ".txt";
	std::string output_name;
	output_name += part_output;
	output_name += str_num;
	output_name += part_2;
	std::string input_name;
	input_name += part_input;
	input_name += str_num;
	input_name += part_2;
	std::ifstream ifs;
	ifs.open(input_name, std::ios::in);
	int n;
	ifs >> n;
	ifs.close();
	int* mas = get_array(n);
	int* new_mas = new int[n];
	for (int i = 0; i < n; i++)
	{
		new_mas[i] = mas[n-i-1];
	}
	std::ofstream ofs;
	ofs.open(output_name, std::ios::trunc);
	for (int i = 0; i < n; i++)
	{
		ofs << new_mas[i] << std::endl;
	}
	ofs.close();
	delete[]mas;
	delete[]new_mas;
	mas = NULL;
	new_mas == NULL;
}

int main()
{
	for (int i = 0; i < 3; i++)
	{
		task2(i+1);
	}
	return 0;
}
