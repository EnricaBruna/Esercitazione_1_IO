#include <iostream>
#include <fstream>
#include <iomanip>

double newmapval(double n, int a_new, int b_new, int a_old, int b_old)
{
    return ((n-1)*(b_new - a_new)/(b_old - a_old))-1;
}


int main()
{
    int a = 1;
    int b = 5;
    int a_new = -1;
    int b_new = 2;


    std::ifstream infile("data.csv");

    if(infile.fail())
    {
        std::cerr << "File does not exist" << std::endl;
        return 1;
    }

    std::ofstream outfile("result.csv");
    outfile << std::setprecision(16)<<std::scientific;
    outfile << "#  N Mean" << std::endl;

    double val = 0;
    double newval = 0;
    double sumval = 0;
    unsigned int countval = 0;
    double mean = 0;

    while(infile >> val)
    {
        newval = newmapval(val,a_new, b_new, a, b);
        sumval += newval;
        countval ++;
        mean = sumval/countval;
        outfile <<countval << "   " << mean << std::endl;
    }
    infile.close();
    outfile.close();

    return 0;
}
