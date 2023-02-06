#ifndef DEBUG_H
#define DEBUG_H

class Debug
{
public:
    constexpr Debug(bool b = true): hw(b), io(b), other(b){}
    constexpr Debug(bool h, bool i, bool o): hw(h), io(i), other(o){}

    constexpr bool any(){return hw || io || other;}
    void set_hw(bool h){hw = h;}
    void set_io(bool i){io = i;}
    void set_other(bool o){other = o;}
private:
    bool hw;   //硬件错误
    bool io;   //io错误
    bool other;
};

#endif