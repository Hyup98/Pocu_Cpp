#include "Lab2.h"
#include<iostream>
#include<iomanip>

namespace lab2
{
    void PrintIntegers(std::istream& in, std::ostream& out)
    {
        int tem;
        char trash;
        out << std::setfill(' ') << std::setw(12) << std::right << "oct" << ' '
            << std::setw(10) << std::right << "dec" << ' '
            << std::setw(8) << std::right << "hex"  << std::endl;

        out << std::setfill('-') << std::setw(13) << ' '
            << std::setw(11) << ' '
            << std::setw(8) << "" << std::endl;

        while (!in.eof())
        {
            in >> tem;


            if (in.fail())
            {
                in.clear();
                in >> trash;
            }
            else
            {
                out << std::setfill('.') << std::setw(12) << std::right << std::oct << tem << '.'
                    << std::setfill('.') << std::setw(10) << std::right << std::dec << tem << '.'
                    << std::setfill('.') << std::setw(8) << std::right << std::hex << tem << '.' << std::endl;
            }
        }
    }

    /*
    void PrintMaxFloat(std::istream& in, std::ostream& out)
    {

    }
    */
}