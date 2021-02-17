// AssamblerCalculate.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <conio.h>
#include <sstream>

using namespace std;

class Calculate
{public:
    Calculate(char opperation)
    {
        this->sign = opperation;
    }
private:
    static char sign;
public:
    static int Add(int num1, int num2)
    {
        int result;
        __asm
        {
            mov eax, num1;
            mov ebx, num2;
            add eax, ebx;
            mov result, eax;
        }
        return result;
    }
    static int Mul(int num1, int num2)
    {
        int result;
        __asm
        {
            mov eax, num1;
            mov ebx, num2;
            mul ebx;
            mov result, eax;
        }
        return result;
    }
    static int Div(int num1, int num2)
    {
        int result;
        __asm
        {
            mov eax, num1;
            mov ebx, num2;
            div ebx;
            mov result, eax;
        }
        return result;
    }
};
static bool CheckConvert(string input)
{
    try
    {
        stoi(input);
        return true;
    }
    catch (const exception& error)
    {
        cout << error.what() << endl;
        return false;
    }
}
static int ReadLine(string name)
{
    string input;
    do
    {
        cout << ("enter ") << name<<endl;
        cin >> input;

    } while (!CheckConvert(input));
    return stoi(input);
}
int main()
{
    int nums[5];
    for (char i = 'a'; i <= 'e'; i++)
    {  
        nums[i - 'a'] = ReadLine(to_string(i));
    }
    cout<<Calculate::Div(nums[0], nums[1]);
    _getch();
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
