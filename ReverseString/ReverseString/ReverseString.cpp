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
    /*printf("input string\n");
    int lengh;
    string sentecsice;
    cin >> sentecsice;
    lengh = sentecsice.size();*/
    char sentecsice2[]{"offset"};
    int lengh = 6;
    _asm
    {
        sub lengh, 1;
        mov ebx, 0;
        mov eax, 0;

    inputLoop:
        mov al, sentecsice2[ebx];
        push eax;
        inc ebx;

        cmp ebx, lengh
            jng inputLoop;

        xor ebx, ebx;
    outputLoop:
        pop eax;
        mov sentecsice2[ebx], al;
        inc ebx;

        cmp ebx, lengh
            jng outputLoop;
    }
    printf((sentecsice2));
}
