#include "Student.h"
#include <cstring>

int Student::idCounter = 1;

Student::Student(const char* n, int c, int g, int rb):id(idCounter++), recordBook(rb), course(c), group(g){
    name = new char[strlen(n) + 1];
    strcpy(name, n);
}
Student::Student(const Student& other) : id(idCounter++), recordBook(other.recordBook), course(other.course), group(other.group){
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
}

Student::~Student(){
    delete[] name;
}
std::ostream& operator<<(std::ostream& os, const Student& s){
    s.print(os);
    return os;
}
void Student::setName(const char* n){
    delete[] name;
    name = new char[strlen(n) + 1];
    strcpy(name, n);
}

void Student::setCourse(int c){
    course = c;
}
void Student::setGroup(int g){
    group = g;
}

void Student::print(std::ostream& os) const{
    os<< "ID: "<< id<< std::endl;
    os<<"Имя: " << name<< std::endl;
    os<< "Курс: " << course<< std::endl;
    os<< "Группа: " << group<< std::endl;
    os << "Зачетка: " << recordBook<< std::endl;
}

Session1::Session1(const char* n, int c, int g, int rb, const int m1[4]):Student(n, c, g, rb){
    for(int i = 0; i < 4; i++)
        marks1[i] = m1[i];
}

Session1::Session1(const Session1& other) : Student(other){
    for(int i = 0; i < 4; i++)
        marks1[i] = other.marks1[i];
}

void Session1::setMark1(int index, int value){
    if(index >= 0 && index < 4)
        marks1[index] = value;
}
int Session1::getMark1(int index) const{
    return(index >= 0 && index < 4) ? marks1[index] : 0;
}

double Session1::getAverage() const{
    double sum = 0;
    for(int m : marks1)
        sum += m;
    return sum/4.0;
}

void Session1::print(std::ostream& os) const{
    Student::print(os);
    os << " Оценки 1 сессия: ";
    for(int m : marks1)
        os << m << " ";
    os<<std::endl;
    os<<"Ср. балл: " << getAverage();
}

Session2::Session2(const char* n, int c, int g, int rb, const int m1[4], const int m2[5]):Session1(n, c, g, rb, m1){
    for(int i = 0; i < 5; i++)
        marks2[i] = m2[i];
}

Session2::Session2(const Session2& other) : Session1(other){
    for(int i = 0; i < 5; i++)
        marks2[i] = other.marks2[i];
}

void Session2::setMark2(int index, int value){
    if(index >= 0 && index < 5)
        marks2[index] = value;
}

int Session2::getMark2(int index) const{
    return(index >= 0 && index < 5) ? marks2[index] : 0;
}

double Session2::getAverage() const{
    double sum = 0;
    for(int i = 0; i < 4; i++)
        sum += marks1[i];
    for(int i = 0; i < 5; i++)
        sum += marks2[i];
    return sum/9.0;
}

void Session2::print(std::ostream& os) const{
    Session1::print(os);
    os << " Оценки 2 сессия: ";
    for(int m : marks2)
        os << m << " ";
    os<<std::endl;
    os<<"Ср. за год: " << getAverage();
}
