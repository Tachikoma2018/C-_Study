/*******************************************
    *FileName:
    *Author: Nerisateb
    *Version: 0.0.1
    *Date:
    *Description:
        *包含头文件：vector0.h
*******************************************/
#include"vector0.h"
#include<math.h>
using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;

namespace VECTOR
{
    const double Rad2deg = 45.0/atan(1.0);
    Vector::Vector(double a, double b, Mode form){
        x = a;
        y = b;
        mode = form;
    }
    void Vector::reset(double n1,double n2,Mode form){

        if(form==Vector::RECT){
            x = n1;
            y = n2;
            mode = RECT;
        }else if(form==Vector::POL){
            // if POL type input, then n2 == angle in double type
            x = n1*cos(n2/Rad2deg);
            y = n1*sin(n2/Rad2deg);
            mode = RECT;// force to RECT mode, to show in (x,y) format
        }else{
            cout<<">>>Incorrect 3rd argument to Vector() --";
            cout<<"vector set to 0\n";
            x = y = 0.0;
            mode = RECT;
        }
    }

    double Vector::magval() const{
        return sqrt(x*x+y*y);
    }
    double Vector::angval() const{
        if(x==0.0 && y==0.0)
            return 0;
        else
            return atan2(y,x);
    }
    void Vector::polar_mode(){
        mode = POL;
    }
    void Vector::rect_mode(){
        mode = RECT;
    }


    // operator overloading
    Vector Vector::operator+(const Vector& v) const{
        return Vector(x + v.x, y + v.y);
    }
    Vector Vector::operator-(const Vector& v) const{
        return Vector(x - v.x, y - v.y);
    }
    Vector Vector::operator-() const{
        return Vector(-x,-y);
    }
    Vector Vector::operator*(double n) const{
        return Vector(n*x,n*y);
    }
    // friends

    Vector operator*(double n,const Vector& v){
        return v*n;
    }
    std::ostream& operator<<(std::ostream& os,const Vector& v){
        if(v.mode==Vector::RECT)
            os<<"(x,y) = ("<<v.x<<", "<<v.y<<")\n";
        else if(v.mode==Vector::POL)
            os<<"(mag,val) = ("<<v.magval()<<", "<<v.angval()<<")\n";
        else
            os<<"Vector object mode is invalid!\n";

        return os;
    }


} // namespace VECTOR


