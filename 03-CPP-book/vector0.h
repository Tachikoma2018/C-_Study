/*******************************************
    *FileName:
    *Author: Nerisateb
    *Version: 0.0.1
    *Date:
    *Description:
        *定义程序文件：
        *执行程序文件：
*******************************************/
#ifndef _VECTOR0_H_
#define _VECTOR0_H_

#include<iostream>
namespace VECTOR{

    class Vector{
    public:
        enum Mode{RECT,POL};
    private:
        double x;
        double y;
        Mode mode;

    public:
        Vector(double a=0.0,double b=0.0,Mode form = RECT);
        ~Vector(){};
        double xval()const{return x;};
        double yval()const{return y;};
        double magval() const;
        double angval() const;
        void polar_mode();
        void rect_mode();
        // reset to 0
        void reset(double n1,double n2,Mode form=RECT);
        // operator overloading
        Vector operator+(const Vector& v) const;
        Vector operator-(const Vector& v) const;
        Vector operator-() const;
        Vector operator*(double n) const;
        // friends
        friend std::ostream& operator<<(std::ostream& cout,const Vector& v);
        friend Vector operator*(double n,const Vector& v);
    };


}//namespace VECTOR

#endif