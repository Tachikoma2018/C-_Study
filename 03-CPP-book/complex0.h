/*******************************************
    *FileName: complex0.h
    *Author: Nerisateb
    *Version: 0.0.1
    *Date:
    *Description:
        定义程序文件：complex0.cpp
        执行程序文件：11.9.7.cpp
*******************************************/
#ifndef _COMPLEX0_H_
#define _COMPLEX0_H_

#include<complex>
#include<iostream>
class Complex{
private:
    double real;
    double imag;

public:
    Complex(double r = 0.0, double i = 0.0);
    ~Complex(){};

    Complex operator~() const;
    Complex operator+(const Complex& c1) const;
    Complex operator-(const Complex& c1) const;
    Complex operator*(const Complex& c1) const;
    Complex operator*(double dd) const;
    friend Complex operator*(double dd,const Complex& c1);

    friend std::ostream& operator<<(std::ostream& cout,const Complex& c1);
    // 如何让 cin >> Complex ？(a+bi)
    friend bool operator>>(std::istream& cin, Complex& c1);
};




#endif