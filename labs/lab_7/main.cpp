#include <iostream>
#include <clocale>
#include <vector>
#include "Student.h"

void inputMarks(int* marks, int c){
    for(int i = 0; i < c; i++){
        std::cout<<"Введите оценку "<<i+1<<": ";
        while(!(std::cin>> marks[i])){
            std::cout<<"Оценка не может быть дробной... Введите целое число: ";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
    }
}

int main(){
    setlocale(LC_ALL, "Russian");
    std::vector<Student*> students;
    char name[100];
    int course, group, recordBook;

    std::cout<<"Для завершения ввода студентов введите 0 при выборе типа"<<std::endl;

    while(true){
        std::cout<<"Выберите тип студента 1 - до сессий, 2 - после 1 сессии, 3 - после 2 сессии или 0 - для выхода: ";
        int t;
        std::cin>> t;

        if(t == 0)
            break;

        std::cin.ignore();
        std::cout<<"Введите имя: ";
        std::cin.getline(name, 100);
        std::cout<<"Введите курс: ";
        std::cin>> course;
        std::cout<<"Введите группу: ";
        std::cin>> group;
        std::cout<<"Введите номер зачетки: ";
        std::cin>> recordBook;

        switch(t){
            case 1:
                students.push_back(new Student(name, course, group, recordBook));
                break;
            case 2:{
                int m1[4];
                std::cout<<"Введите 4 оценки за 1 сессию: ";
                inputMarks(m1, 4);
                students.push_back(new Session1(name, course, group, recordBook, m1));
                break;
                }
            case 3:{
                int m1[4], m2[5];
                std::cout<<"Введите 4 оценки за 1 сессию: ";
                inputMarks(m1, 4);
                std::cout<<"Введите 5 оценок за 2 сессию: ";
                inputMarks(m2, 5);
                students.push_back(new Session2(name, course, group, recordBook, m1, m2));
                break;
            }
            default:
                std::cout<<"Нет таких студентов, сори";
                continue;
        }
    }

    if(students.empty())
        return 0;

    for(Student* s:students)
        std::cout<<*s<<std::endl;

    std::cout<<"Введите номер группы для расчета среднего балла по группе: ";
    int group1;
    std::cin>> group1;

    double sum = 0;
    int c = 0;
    for(Student* s:students)
        if(s->getGroup() == group1){
            double avg = s->getAverage();
            if(avg > 0){
                sum += avg;
                c++;
            }
        }

    if(c > 0)
        std::cout<<"Средний балл по группе "<<group1<<": "<<sum /c<<std::endl;

    for(Student* s:students)
        delete s;

    return 0;
}
