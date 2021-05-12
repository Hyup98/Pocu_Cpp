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
                out.uppercase;
                out << std::setfill(' ') << std::setw(12) << std::right << std::oct << tem << ' '
                    << std::setfill(' ') << std::setw(10) << std::right << std::dec << tem << ' '
                    << std::setfill(' ') << std::setw(8) << std::right <<std::hex << tem  << std::endl;
            }
        }
    }

    void PrintMaxFloat(std::istream& in, std::ostream& out)
    {
        float max;
        float tem;
        char sign;
        char maxSign = '+';
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
                    if (max < 0)
                    {
                        maxSign = '-';
                        max *= -1;
                    }
                }
            }

            if (tem >= 0)
            {
                sign = '+';
            }

            else if (tem < 0)
            {
                sign = '-';
            }

            if (in.fail())
            {
                in.clear();
                std::getline(in, trash, ' ');//수정 필요 할 수도
            }

            else
            {
                if (tem < 0)
                {
                    tem *= -1;
                }

                int decNum;
                double temDec = tem - (int)tem;
                if (temDec < 0)
                {
                    temDec *= -1;
                }
                temDec *= 1000;
                decNum = temDec;
                
                out.fixed;
                out.precision(3);
                out << std::setfill(' ') << std::setw(5) << std::left << ""
                    << sign
                    << std::setfill(' ') << std::setw(10) << std::right << std::noshowpoint << std::noshowpos << (int)tem << '.'
                    << std::setfill('0') << std::setw(3) << std::left << decNum << std::endl;
                    
            }
        }
        int decMaxNum;
        double temMaxDec = max - (int)max;
        
        temMaxDec *= 1000;
        decMaxNum = temMaxDec;
        out.fixed;
        out.precision(3);
        out << std::setfill(' ') << std::setw(5) << std::left << "max:"
            << maxSign
            << std::setfill(' ') << std::setw(10) << std::right<< std::noshowpoint << (int)max << '.'
            << std::setfill('0') << std::setw(3) << std::left << decMaxNum;

    }

}