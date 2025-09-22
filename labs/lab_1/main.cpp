#include <iostream>
#include <cmath>

int main() {
    long double x;
    int k;
    std::cout<<"Vvedite k: "<<std::endl;
    std::cin>>k;
    std::cout<<"Vvedite x: "<<std::endl;
    std::cin>>x;

    while(abs(x)>1)
    {
       std::cout<<"Vvedite x ot -1 do 1: "<<std::endl;
       std::cin>>x;
    }

    while(k<=1)
    {
       std::cout<<"Vvedite k>1: "<<std::endl;
       std::cin>>k;
    }

    long double e = 1;
    for(int i = k; i>0; i--)
        e/=10;

    long double sum = 1, y = 1, y2 = 0;
    int t = 1;
    while(fabs(y) > e){
        y *= 1.*x*(3-2*t)/(2*t);
        sum+=1.*y;
        t++;
    }
    std::cout.precision(k);
    std::cout<<"Priblizennoe znachenie sqrt(1+x) = "<<sum<<std::endl;
    std::cout<<"Tochnoe znachenie sqrt(1+x) = " << sqrt(1 + x) << std::endl;
    std::cout<<"Raznica mezdu tochnym i priblizennym znachenijami: " << fabs(sqrt(1 + x)-sum) << std::endl;
    return 0;
}

