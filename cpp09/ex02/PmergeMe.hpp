#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>

class PmergeMe
{
    private:
        std::deque<int> _deq;
        std::vector<int> _vec;

    public:
        PmergeMe();
        PmergeMe(const PmergeMe& src);
        PmergeMe& operator=(const PmergeMe& src);
        ~PmergeMe();

        bool                parseArgs(int argc, char** argv);
        std::vector<int>    sortVector();
        std::deque<int>     sortDeque();

        std::vector<int>    mergeInsertVector(std::vector<int>& input);
        void                insertInVector(std::vector<int>& mainChain, int element, int limit_index);

        std::deque<int>     mergeInsertDeque(std::deque<int>& input);
        void                insertInDeque(std::deque<int>& mainChain, int element, int limit_index);
        
        size_t              getJacobsthal(size_t n);
};

#endif