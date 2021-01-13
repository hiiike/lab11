
#include <iostream>
#include<fstream>
#include <Windows.h>
#include <time.h>

using namespace std;

void Create(const char* File_Name);
void Process(const char* File_Name, const char* File_Result);
void Print(const char* File_Result);

int main()
{
    srand((unsigned)time(NULL));

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Create("FirstFile.dat");
    Print("FirstFile.dat");

    Process("FirstFile.dat", "Result.dat");
    Print("Result.dat");

    return 0;
}
void Create(const char* File_Name)
{
    ofstream First_File(File_Name, ios::binary);

    double y;

    for (int i = 0; i < 20; i++)
    {
        y = (2 * (20 * 1.)) * rand() / RAND_MAX - (20 * 1.);
        First_File.write((char*)&y, sizeof(y));
    }
}
void Process(const char* File_Name, const char* File_Result)
{
    ifstream First_File(File_Name, ios::binary);
    ofstream Second_File(File_Result, ios::binary);

    double y;
    while (First_File.read((char*)&y, sizeof(y)))
        if (y > 0)
            Second_File.write((char*)&y, sizeof(y));

}
void Print(const char* File_Result)
{
    cout << "file contents: ";

    ifstream Second_File(File_Result, ios::binary);

    double y;
    while (Second_File.read((char*)&y, sizeof(y)))
        cout << y << " ";
    cout << endl;
}