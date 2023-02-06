#ifndef NO_DEFAULT_H
#define NO_DEFAULT_H

class NoDefault
{
public:
    NoDefault(int) {}
};

class C{
public:
    C(): def(0){}
private:
    NoDefault def;
};
#endif