#include <iostream>
#include <clocale>
#include "Drob.h"

int main() {
    setlocale(LC_ALL, "Russian");
    int n1, d1, n2, d2;


    std::cout << "Введите числитель первой дроби: ";
    std::cin >> n1;
    std::cout << "Введите знаменатель первой дроби: ";
    std::cin >> d1;
    if(!d1){
        std::cout<<"Деление на ноль запрещено"<<std::endl;
        return 0;
    }
    Drob f1(n1, d1);

    std::cout << "Введите числитель второй дроби: ";
    std::cin >> n2;
    std::cout << "Введите знаменатель второй дроби: ";
    std::cin >> d2;
    if(!d2){
        std::cout<<"Деление на ноль запрещено"<<std::endl;
        return 0;
    }
    Drob f2(n2, d2);

    std::cout << "Дробь 1: ";
    f1.print();
    std::cout << std::endl;
    std::cout << "Дробь 2: "<<std::endl;
    f2.print();
    std::cout << std::endl;

    Drob sum = f1.add(f2);
    std::cout << "Сумма: ";
    sum.print();
    std::cout << std::endl;

    Drob mult = f1.multiply(f2);
    std::cout << "Произведение: ";
    mult.print();
    std::cout << std::endl;

    Drob div = f1.divide(f2);
    std::cout << "Частное: ";
    div.print();
    std::cout << std::endl;

    return 0;
}
