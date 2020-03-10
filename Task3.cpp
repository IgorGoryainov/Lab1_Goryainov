#include <iostream>
#include <ctime>
#include <fstream>

bool check_val(int a, int b)
{
    bool flag_fail = 0;
    if ((a < 0) || (b < 0)) flag_fail = 1;
    if (a > b)  flag_fail = 1;
    return flag_fail;
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

int** generate_matric(int n, int a, int b)
{
    srand(time(0));
    int** matric = new int* [n];
    for (int i = 0; i < n; i++)
        matric[i] = new int[n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            matric[i][j] = rand() % b + a;
    return matric;
    for (int i = 0; i < n; i++)
        delete[]matric[i];
}

void writer(int n, int** matric)
{
    std::fstream fs;
    fs.open("task3_input1.dat", std::ios::out | std::ios::binary);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            fs.write((char *)&matric[i][j], sizeof(int));
    fs.close();
}

int** reader(int n)
{
    std::fstream fs;
    int** matric = new int* [n];
    for (int i = 0; i < n; i++)
        matric[i] = new int[n];
    fs.open("task3_input1.dat", std::ios::in | std::ios::binary);
    int k = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            fs.read((char*)&matric[i][j], sizeof(int));
    fs.close();
    return matric;
    for (int i = 0; i < n; i++)
        delete[]matric[i];
}

int** transponate_matric(int n, int** matric)
{
    int** new_matric = new int* [n];
    for (int i = 0; i < n; i++)
        new_matric[i] = new int[n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            new_matric[i][j] = matric[j][i];
    return new_matric;
    for (int i = 0; i < n; i++)
        delete[]new_matric[i];
}

int main()
{
    int n, a, b;
    std::cin >> n;
    std::cin >> a >> b;
    int** matric = generate_matric(n, a, b);
    writer(n, matric);
    matric = reader(n);
    matric = transponate_matric(n, matric);
    writer(n, matric);
    if (!check_val(a, b))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                std::cout << matric[i][j] << ' ';
            std::cout << std::endl;
        }
    }
    load_report(check_val(a, b));
    for (int i = 0; i < n; i++)
        delete[]matric[i];
    return 0;
}
