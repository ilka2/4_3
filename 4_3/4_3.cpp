#include <iostream>
#include <Windows.h>
#include <vector>
#include <sstream>

using namespace std;

// Функция для считывания ввода
void readInput(vector<int>& vec) {
    string input;
    getline(cin, input); // Считываем всю строку

    stringstream ss(input);
    vec.clear();

    // Пытаемся разобрать строку как вектор
    int x;
    while (ss >> x) {
        vec.push_back(x);
    }

    if (vec.size() != 0)
    {
        return;
    }

    // Если ни одно из условий не выполнено, сообщаем об ошибке
    cout << "Ошибка: введены некорректные данные. Ожидается ряд чисел, введенных через пробел" << endl;
    vec.clear();
}

class Functor
{
    vector<int> vec;

public:
    Functor(vector<int> vec) : vec(vec) {};

    void operator()()
    {

    }

    int get_sum()
    {
        int sum = 0;
        for (int i : vec)
        {
            sum += i;
        }
        return sum;
    }

    int get_count()
    {
        /*int count = 0;
        for (int i : vec)
        {
            count++;
        }*/
        return vec.size();
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    vector<int> vec;

    cout << "Введите числа через пробел:\n";
    readInput(vec);

    Functor functor(vec);
    cout << "Сумма чисел: " << functor.get_sum() << "\n";

    cout << "Количество чисел в выборке: " << functor.get_count() << "\n\n";


}

