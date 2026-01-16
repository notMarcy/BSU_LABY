#include "Drob.h"
#include <iostream>
#include <stdexcept>
#include <cmath>

int Drob::gcd(int a, int b){
    return b == 0 ? std::abs(a) : gcd(b, a % b);
}

void Drob::simplify(){
    if(den == 0) return;

    if(den < 0){
        num = -num;
        den = -den;
    }

    int common = gcd(num, den);
    num/=common;
    den/=common;
}

Drob::Drob(int num, int den) : num(num), den(den){
    simplify();
}

Drob::Drob(const Drob& other) : num(other.num), den(other.den){}

int Drob::getNum() const { return num; }
int Drob::getDen() const { return den; }

Drob Drob::add(const Drob& other) const {
    int resNum = num*other.den+other.num*den;
    int resDen = den*other.den;
    return Drob(resNum, resDen);
}

Drob Drob::multiply(const Drob& other) const {
    return Drob(num*other.num, den*other.den);
}

Drob Drob::divide(const Drob& other) const {
    if(!other.num){
        return Drob(0, 0);
    }
    return Drob(num*other.den, den*other.num);
}

void Drob::print() const {
    if(!den)
        std::cout<<"Деление на ноль запрещено"<<std::endl;
    else
        if(den == 1){
            std::cout << num;
        } else{
            std::cout << num << "/" << den;
        }
}
