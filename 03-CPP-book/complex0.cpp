/*******************************************
    *FileName:
    *Author: Nerisateb
    *Version: 0.0.1
    *Date:
    *Description: 执行程序文件 为 11.9.7.cpp
*******************************************/
#include<iostream>
#include"complex0.h"

Complex::Complex(double r,double i){
    real = r;
    imag = i;
}

Complex Complex::operator~() const{
    Complex cco;
    cco.real = -real;
    cco.imag = -imag;
    return cco;
}

Complex Complex::operator+(const Complex& c1) const{
    Complex cco;
    cco.real = real + c1.real;
    cco.imag = imag + c1.imag;
    return cco;
}
Complex Complex::operator-(const Complex& c1) const{
    Complex cco;
    cco.real = real-c1.real;
    cco.imag = imag-c1.imag;
    return cco;
}

Complex Complex::operator*(const Complex& c1) const{
    Complex cco;
    cco.real = real*c1.real - imag*c1.imag;
    cco.imag = real*c1.imag + c1.real*imag;
    return cco;
}
Complex Complex::operator*(double dd) const{
    Complex cco;
    cco.real = dd*real;
    cco.imag = dd*imag;
    return cco;
}
Complex operator*(double dd,const Complex& c1){
    return c1*dd;
}



std::ostream& operator<<(std::ostream& cout,const Complex& c1){
    cout<<"("<<c1.real<<","<<c1.imag<<"i)"<<std::endl;
    return cout;
}
// 如何让 cin >> Complex ？(a+bi)
bool operator>>(std::istream& cin, Complex& c1){

    std::cout<<"real(double): ";
    if(!(cin>>c1.real))
        return false;
    std::cout<<"imaginary(double): ";
    if(!(cin>>c1.imag))
        return false;

    return true;
}