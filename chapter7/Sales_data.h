#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <iostream>
#include <string>

class Sales_data;

std::istream &read(std::istream &is, Sales_data &item);
std::ostream &print(std::ostream &os, const Sales_data &item);
Sales_data add(const Sales_data &lhs, const Sales_data &rhs);

class Sales_data
{
    friend std::istream &read(std::istream &is, Sales_data &item);
    friend std::ostream &print(std::ostream &os, const Sales_data &item);
    friend Sales_data add(const Sales_data &lhs, const Sales_data &rhs);

public:
    Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p) {std::cout << "Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p)"<<std::endl;}
    Sales_data() : Sales_data("", 0, 0) {std::cout << "Sales_data() : Sales_data("", 0, 0)" << std::endl;}
    Sales_data(const std::string &s) : Sales_data(s, 0, 0) {std::cout << "Sales_data(const std::string &s) : Sales_data(s, 0, 0)" << std::endl;}
    Sales_data(std::istream &is) : Sales_data() { read(is, *this); std::cout << "Sales_data(std::istream &is) : Sales_data() " << std::endl;}
    // 关于sales_data对象的操作
    std::string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data &);
    inline double avg_price() const;

private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0; // 总销售数量
};

Sales_data &Sales_data::combine(const Sales_data &src)
{
    units_sold += src.units_sold;
    revenue += src.revenue;
    return *this;
}

inline double Sales_data::avg_price() const
{
    if (units_sold)
    {
        return revenue / units_sold;
    }
    else
    {
        return 0;
    }
}

std::istream &read(std::istream &is, Sales_data &item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item)
{
    os << item.bookNo << ' ' << item.units_sold << ' '
       << item.revenue << ' ' << item.avg_price() << std::endl;
    return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

#endif