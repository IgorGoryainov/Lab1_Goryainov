#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream> 

int check_array(std::string file_name)
{
    int flag = 0;
    std::ifstream ifs;
    ifs.open(file_name + ".txt", std::ios::in);
    std::string s;
    std::getline(ifs, s);
    for (int i = 0; i < s.size(); i++)
        if (((s[i] < 48) || (s[i] > 57))&&(s[i] != 32)) flag = 1;
    ifs.close();
    return flag;
}

void load_report(int flag_fail)
{
    std::ofstream ofs;
    ofs.open("report.txt", std::ios::trunc);
    if (flag_fail != 1)
        ofs << "Input correct, task finished successfuly";
    else 
        ofs << "Input incorrect, task fail";
}

int get_len(std::string file_name)
{
    int n = 0;
    int x;
    std::ifstream ifs;
    ifs.open(file_name + ".txt", std::ios::in);
    while (ifs >> x) n++;
    ifs.close();
    return n;
}

int* get_array(std::string file_name)
{
    if (check_array(file_name) == 0)
    {
        std::ifstream ifs;
        int n = get_len(file_name);
        int* file_array = new int[n];
        ifs.open(file_name + ".txt", std::ios::in);
        for (int i = 0; i < n; i++) ifs >> file_array[i];
        ifs.close();
        return file_array;
    }
    else return NULL;
}

int task1_get(std::string file_name)   //get max len of raising array
{
    int* mas = get_array(file_name);
    if (mas != NULL)
    {
        int len = 1;
        int max_len = 1;
        int last_val;
        int n = get_len(file_name);
        last_val = mas[0];
        for (int i = 1; i < n; i++)
        {
            if (mas[i] - last_val > 0) len++;
            else
            {
                if (len > max_len) max_len = len;
                len = 1;
            }
            last_val = mas[i];
            if (len > max_len) max_len = len;
        }
        return max_len;
    }
    else return NULL;
    
}

void task1_write(int num)
{
    std::ofstream ofs;
    std::ostringstream ostr;
    ostr << num;
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
    if (task1_get(input_name) != NULL)
    {
        int val = task1_get(input_name);
        ofs.open(output_name, std::ios::trunc);
        ofs << val;
        ofs.close();
    }
    else
    {
        ofs.open(output_name, std::ios::trunc);
        ofs << "Incorrect input";
        ofs.close();
    }

}

int main()
{
    
    for (int i = 1; i < 6; i++)
        task1_write(i);
}
