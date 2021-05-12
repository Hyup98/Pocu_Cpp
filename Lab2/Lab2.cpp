#include "Lab2.h"
#include<iostream>
#include<iomanip>
#include<string>

namespace lab2
{
    void PrintIntegers(std::istream& in, std::ostream& out)
    {
        int tem;
        std::string trash;
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
                std::getline(in, trash, ' ');//수정 필요 할 수도
            }
            else
            {
                
                out << std::uppercase << std::setfill(' ') << std::setw(12) << std::right << std::oct << tem << ' '
                    << std::setfill(' ') << std::setw(10) << std::right << std::dec << tem << ' '
                    << std::setfill(' ') << std::setw(8) << std::right <<std::hex << tem  << std::endl;
            }
        }
    }

    void PrintMaxFloat(std::istream& in, std::ostream& out)
    {
        float max = 0;
        float tem;
        std::string trash;
        int flag = 0;

        while (!in.eof())
        {
            in >> tem;

            if (flag == 0)
            {
                max = tem;
                flag++;
            }

            else if (flag != 0)
            {
                if (max <= tem)
                {
                    max = tem;
                }
            }

            if (in.fail())
            {
                in.clear();
                std::getline(in, trash, ' ');//수정 필요 할 수도
            }

            else
            {
                out << std::showpoint << std::fixed << std::setprecision(3) << std::showpos << std::setfill(' ') << std::setw(5) << std::left << ""
                    << std::setfill(' ') << std::setw(15) << std::internal << tem << "\n";
            }
        }
       
        out << std::showpoint << std::fixed << std::setprecision(3) << std::showpos << std::setfill(' ') << std::setw(5) << std::left << ""
            << std::setfill(' ') << std::setw(15) << std::internal << max;

    }

}