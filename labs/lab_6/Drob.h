#ifndef DROB_H
#define DROB_H

class Drob {
private:
    int num;
    int den;

    void simplify();
    int gcd(int a, int b);

public:
    Drob(int num, int den);
    Drob(const Drob& other);
    Drob() = delete;

    int getNum() const;
    int getDen() const;

    Drob add(const Drob& other) const;
    Drob multiply(const Drob& other) const;
    Drob divide(const Drob& other) const;

    void print() const;
};

#endif
