// AssamblerCalculate.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <conio.h>
#include <sstream>

using namespace std;

class	Calculate
{
public:
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
            adc eax, ebx;
            mov result, eax;
        }
        return result;
    }
    static int Sub(int num1, int num2)
    {
        int result;
        __asm
        {
            mov eax, num1;
            mov ebx, num2;
            sub eax, ebx;
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
            imul ebx;
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
            mov edx, 0;
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
        int num = stoi(input);
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
static int CalculateX(int nums[])
{
    int x = Calculate::Add(nums[0], nums[1]);
    x = Calculate::Mul(x, nums[2]);
    x = Calculate::Sub(x, nums[3]);
    x = Calculate::Div(x, nums[4]);
    return x;
}
int main()
{
    int nums[5];
    for (char i = 'a'; i <= 'e'; i++)
    {  
        string name="";
        name = i;
        nums[i - 'a'] = ReadLine(name);
    }
	cout << ("Answer") << endl << CalculateX(nums);
    delete nums;
    _getch();
    return 0;
}
