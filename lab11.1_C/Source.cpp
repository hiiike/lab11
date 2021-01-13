#include <iostream>
#include <fstream>
#include <Windows.h>
#include <time.h>

using namespace std;

void Create(const char* File_Name, const int N, const int min, const int max);
void Print(const char* File_Name);
void Process(const char* File_Name, const char* File_Result);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int min, max, N;
    cout << "Enter the minimum number: "; cin >> min;
    cout << "Enter the maximum number: "; cin >> max;

    cout << "Enter the number of numbers: "; cin >> N;

    Create("FirstFile.dat", N, min, max);
    cout << "Introductory data: ";
    Print("FirstFile.dat");

    Process("FirstFile.dat", "Result.dat");
    cout << "\n\nResult: ";
    Print("Result.dat");

    return 0;
}
void Create(const char* File_Name, const int N, const int min, const int max)
{
    srand((unsigned)time(NULL));

    ofstream t(File_Name, ios::binary);

    if (!t)
    {
        cerr << "Error opening file!\n";
        exit(1);
    }

    int x;
    for (int i = 0; i < N; i++)
    {
        x = min + rand() % (max - min + 1);
        t.write((char*)&x, sizeof(int));
    }

}
void Print(const char* File_Name)
{
    ifstream t(File_Name, ios::binary);

    if (!t)
    {
        cerr << "Error opening file!\n";
        exit(1);
    }

    int x;
    while (t.read((char*)&x, sizeof(int)))
        cout << x << " ";
}
void Process(const char* File_Name, const char* File_Result)
{
    ifstream First(File_Name, ios::binary);

    ofstream Result(File_Result, ios::binary);

    if (!First && !Result)
    {
        cerr << "Error opening file!\n";
        exit(1);
    }

    int x;
    while (First.read((char*)&x, sizeof(x)))
    {
        if (x > 0)
            Result.write((char*)&x, sizeof(x));
    }


}