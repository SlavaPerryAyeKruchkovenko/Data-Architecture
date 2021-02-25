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
    unsigned char returnNum;
    int haveOverFlow=0;
    _asm
    {
        mov al, a;
        mov bl, b;
        adc al, bl;
        mov returnNum, al;
        jnc RET2
        jc RET1;
        RET1:
            mov haveOverFlow, 1;
        RET2:
    }
    WriteLine(haveOverFlow, "UnSigned");
    return (int)returnNum;
}
static int SignedAdd(unsigned char a, unsigned char b)
{
    char returnNum;
    signed char num1 = (signed char)a;
    signed char num2 = (signed char)b;
    int haveOverFlow=0;
    _asm
    {
        mov al, num1;
        mov bl, num2;
        adc al, bl;   
        mov returnNum, al;
        jno RET2
        jo RET1;
        RET1:
            mov haveOverFlow, 1;
        
        RET2:     
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
