// ReverseString.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string.h>

using namespace std;
static void ClearArray(string s)
{
    s.clear();
}
int main()
{
    printf("input string\n");
    int lengh;
    string sentecsice;
    cin >> sentecsice;
    lengh = sentecsice.size();
    char* sentecsice2 = new char[lengh + 1]{};
    strcpy_s(sentecsice2, lengh + 1, sentecsice.c_str());
    ClearArray(sentecsice);
    _asm
    {
        sub lengh, 1;
        mov ebx, 0;
        mov eax, 0;

    inputLoop:
        mov eax, sentecsice2[ebx];
        push eax;
        inc ebx;

        cmp ebx, lengh
            jng inputLoop;

        xor ebx, ebx;
    outputLoop:
        pop eax;
        /*mov sentecsice2[ebx], eax;*/
        inc ebx;

        cmp ebx, lengh
            jng outputLoop;
    }
    cout << sentecsice2 << endl;
    system("pause");
}
