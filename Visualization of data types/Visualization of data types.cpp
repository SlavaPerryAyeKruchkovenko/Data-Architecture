// Visualization of data types.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <sstream>
#include <Bits.h>
#include<xbit_ops.h>


using namespace std;
class TypeData
{
public:
    TypeData(string num)
    {
        this->dataNum = num;
    }
private:
     string dataNum;
public:
    virtual string* GetDataNum()
    {
        return &this->dataNum;
    }
    void BigEndian(byte* numBytes,short sizeNum)
    {
        printf("BigEndian:\n");
        for (int i = sizeNum-1; i >=0 ; i--)
        {
            printByte(*(numBytes + i));
        }
        cout << endl;
    };
    void LittleEndian(byte* numBytes, short sizeNum)
    {
        printf("LittleEndian:\n");
        for (int i = 0 ; i <= sizeNum - 1; i++)
        {
            printByte(*(numBytes + i));
        }
        cout << endl;
    };
private:
    static void printByte(byte numByte)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << ((numByte >> (7 - j)) & 1);          
        }
        printf(" ");
    }
};
class Integer final :public TypeData
{
public:
    Integer(string num) :TypeData(num)
    {
        IntNum = stoi(num);
    };
private:
    int IntNum;
public:
    int GetIntNum()
    {
        return this->IntNum;
    };
};
class Floater final :public TypeData
{
public:
    Floater(string num) :TypeData(num)
    {
        FloatNum = stof(num);
    };
private:
    float FloatNum;
public:
    float GetFloatNum()
    {
        return this->FloatNum;
    };
};
class Doubler :public TypeData
{
public:
    Doubler(string num) :TypeData(num)
    {
        DoubleNum = stod(num);
    };
private:
    double DoubleNum;
public:
    double GetDoubleNum()
    {
        return this->DoubleNum;
    };
};

static void ConvertToEncoding(TypeData* data,short sizeNum)
{
    byte* numBytes=NULL;
    if (dynamic_cast<Integer*>(data))
    {
        Integer* type = dynamic_cast<Integer*>(data);
        int num = type->GetIntNum();
        numBytes = (byte*)&num;
    }  
    else if (dynamic_cast<Floater*>(data))
    {
        Floater* type = dynamic_cast<Floater*>(data);
        float num = type->GetFloatNum();
        numBytes = (byte*)&num;
    }
    else if (dynamic_cast<Doubler*>(data))
    {
        Doubler* type = dynamic_cast<Doubler*>(data);
        double num = type->GetDoubleNum();
        numBytes = (byte*)&num;
    }
    data->BigEndian(numBytes, sizeNum);
    data->LittleEndian(numBytes, sizeNum);
}
static bool CheckConvert(string input)
{
    try
    {
        stod(input);
        return true;
    }
    catch(const exception& error)
    {
        cout << error.what()<<endl;
        return false;
    }
}
static string ReadLine()
{
    string input;
    do
    {
        printf("Input number\n");
        cin >> input;

    } while (!CheckConvert(input));
    return input;
};
int main()
{
    while (true)
    {
        string input = ReadLine();
        Integer* integer = new Integer(input);
        ConvertToEncoding(integer, 4); 
        Floater* floater = new Floater(input);
        ConvertToEncoding(floater, 4);
        Doubler* doubler = new Doubler(input);
        ConvertToEncoding(doubler, 8);
    };

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
