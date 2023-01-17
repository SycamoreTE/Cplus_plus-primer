#include <cstddef>
#include <cstring>
#include <initializer_list>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <string>
#include <vector>
#include "Sales_data.h"

using std::begin;
using std::cin;
using std::cout;
using std::end;
using std::endl;
using std::initializer_list;
using std::runtime_error;
using std::string;
using std::vector;

void q_7_3()
{
    Sales_data total;
    if (cin >> total.bookNo >> total.units_sold)
    {
        Sales_data trans;
        while (cin >> trans.bookNo >> trans.units_sold)
        {
            if (total.isbn() == trans.isbn())
            {
                total.combine(trans);
            }
            else
            {
                cout << total.bookNo <<' '<< total.units_sold << endl;
                total = trans; //处理下一条交易
            }
        }
        // 输出最后一条交易
        cout << total.bookNo <<' '<< total.units_sold << endl;
    }
    else
    {
        std::cerr << "No data?!" << endl;
        return;
    }
}

void q_7_7(){
    Sales_data total;
    if (read(std::cin, total))
    {
        Sales_data trans;
        while (read(std::cin, trans))
        {
            if (total.isbn() == trans.isbn())
            {
                total.combine(trans);
            }
            else
            {
                print(std::cout, total);
                cout << endl;
                total = trans; //处理下一条交易
            }
        }
        // 输出最后一条交易
        print(std::cout, total);
        cout << endl;
    }
    else
    {
        std::cerr << "No data?!" << endl;
        return;
    }
}

void q_7_11(){
    Sales_data s1;
    Sales_data s2("IBNX");
    Sales_data s3("IBNX", 6, 20);
    Sales_data s4(cin);
    print(cout, s1);
    print(cout, s2);
    print(cout, s3);
    print(cout, s4);
}

void q_7_13(){
    Sales_data total(cin);
    if (!total.isbn().empty())
    {
        Sales_data trans;
        do{
            Sales_data temp(cin);
            trans = temp;
            if (total.isbn() == trans.isbn())
            {
                total.combine(trans);
            }
            else
            {
                print(std::cout, total);
                cout << endl;
                total = trans; //处理下一条交易
            }
        }while(!trans.isbn().empty());
        // 输出最后一条交易
        print(std::cout, total);
        cout << endl;
    }
    else
    {
        std::cerr << "No data?!" << endl;
        return;
    }
}

int main()
{
    // q_7_3();
    // q_7_7();
    // q_7_11();
    q_7_13();
    return 0;
}