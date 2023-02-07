#include <iostream>
#include <iterator>
#include <stdexcept>
#include <string>
#include <vector>
#include <fstream>

#include "Sales_data.h"

using namespace std;

int main(int argc, char *argv[])
{
    ifstream input(argv[1]);
    ofstream output(argv[2], ofstream::app);
    Sales_data total;
    if (read(input, total))
    {
        Sales_data trans;
        while (read(input, trans))
        {
            if (total.isbn() == trans.isbn())
            {
                total.combine(trans);
            }
            else
            {
                print(output, total) << endl;
                total = trans;
            }
        }
        print(output, total) << endl;
    }
    else
    {
        cerr << "No data" << endl;
        return -1;
    }
}