/*******************************************
     *FileName:
    *Author: Nerisateb
    *Version: 0.0.1
    *Date:
    *Description:
        *定义程序文件：
        *执行程序文件：
 *******************************************/
#ifndef _ACCABC_H_
#define _ACCABC_H_
#include <iostream>

// abstract base class
class AccABC
{
private:
    std::string fullName;
    long acctNum;
    double balance;

protected:
    long AcctNum() const { return acctNum; };
    const std::string &Fullname() const { return fullName; };

public:
    AccABC(const std::string &str = "Nullbody", long account = -1, double bal = 0.0);
    virtual ~AccABC(){};
    void deposit(double amt);
    double Balance() const { return balance; };
    virtual void AcctView() const = 0; // pure abstract function
    virtual void withdraw(double amt) = 0;
};

class Brass : public AccABC
{
public:
    Brass(const std::string &str = "Nullbody", long account = -1, double bal = 0.0) : AccABC(str, account, bal){};
    virtual void AcctView() const;
    virtual void withdraw(double amt);
};

class BrassPlus : public AccABC
{
private:
    double maxLoan;
    double rate; // interest rate
    double owesBank;

public:
    BrassPlus(const std::string &str = "Nullbody", long account = -1, double bal = 0.0,
        double ml = 500, double r = 0.0);
    BrassPlus(const AccABC &abc, double ml = 500, double r = 0.0);
    virtual void AcctView() const;
    virtual void withdraw(double amt);

    void ResetMax(double m) { maxLoan = m; }
    void ResetRate(double r) { rate = r; }
    void ResetOwes() { owesBank = 0; }
};

#endif