#include <iostream>
#include <vector>
#include <deque>
#include <sys/time.h>
#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    PmergeMe pm;
    if (!pm.parseArgs(argc, argv))
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    std::cout << "Before: ";
    for(int i = 1; i < argc; ++i)
    {
        std::cout << argv[i] << (i < argc - 1 ? " " : "");
    }
    std::cout << std::endl;

    // Vector
    struct timeval start, end;
    gettimeofday(&start, NULL);
    std::vector<int> resVec = pm.sortVector();
    gettimeofday(&end, NULL);
    double vecTime = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);

    // Deque
    gettimeofday(&start, NULL);
    std::deque<int> resDeq = pm.sortDeque();
    gettimeofday(&end, NULL);
    double deqTime = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);

    std::cout << "After:  ";
    for (size_t i = 0; i < resVec.size(); ++i)
    {
        std::cout << resVec[i] << (i < resVec.size() - 1 ? " " : "");
    }
    std::cout << std::endl;

    std::cout.setf(std::ios::fixed);
    std::cout.precision(5);
    std::cout << "Time to process a range of " << resVec.size() 
              << " elements with std::vector : " << vecTime << " us" << std::endl;
    std::cout << "Time to process a range of " << resDeq.size() 
              << " elements with std::deque  : " << deqTime << " us" << std::endl;

    return 0;
}