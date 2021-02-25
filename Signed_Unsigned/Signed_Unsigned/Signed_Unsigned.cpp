// Signed_Unsigned.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <math.h>
using namespace std;
static int UnsignedAdd(unsigned char a,unsigned char b);
static int SignedAdd(unsigned char a, unsigned char b);
static void WriteLine(int flag,string name);
static unsigned char ReadLine(string name)
{
    cout << "Input Num " << name << endl;
    int num;
    cin >> num;
    return num;
}
int main()
{
    unsigned char a, b;
    a = ReadLine("a");
    b = ReadLine("b");
    cout << UnsignedAdd(a, b) << " UnSigned" << endl;
    cout << SignedAdd(a, b) << " Signed" << endl;
}
static int UnsignedAdd(unsigned char a, unsigned char b)
{
    int num1 = a;
    int num2 = b;
    int returnNum;
    int haveOverFlow=0;
    _asm
    {
        mov eax, num1;
        mov ebx, num2;
        add eax, ebx;
        cdq;
        mov ebx, 256;
        mov edx, 0;
        div ebx;
        mov returnNum, edx;

        RET1:
            mov haveOverFlow, 1;

        jo RET1;

        RET2:
            mov haveOverFlow, 0;
        jno RET2;
    }
    WriteLine(haveOverFlow, "UnSigned");
    return returnNum;
}
static int SignedAdd(unsigned char a, unsigned char b)
{
    int returnNum;
    int num1 = (signed char)a;
    int num2 = (signed char)b;
    int haveOverFlow = 0;
    _asm
    {
        mov eax, num1;
        mov ebx, num2;
        add eax, ebx;
        mov returnNum, eax;

        RET1:
            mov haveOverFlow, 1;
        jo RET1;

        RET2:
            mov haveOverFlow, 0;
        jno RET2;
               
    }
    WriteLine(haveOverFlow, "Signed");
    return returnNum;
}
static void WriteLine(int flag,string name)
{
    if (flag)
        cout << ("OverFlow") << " " << name << endl;

    else
        cout << ("no OverFlow") << " " << name << endl;
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
