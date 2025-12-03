#include "PmergeMe.hpp"
#include <sstream>
#include <limits>
#include <sys/time.h>

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& src) { *this = src; }

PmergeMe& PmergeMe::operator=(const PmergeMe& src) {
    if (this != &src) {
        _vec = src._vec;
        _deq = src._deq;
    }
    return *this;
}


size_t PmergeMe::getJacobsthal(size_t n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return getJacobsthal(n - 1) + 2 * getJacobsthal(n - 2);
}


void PmergeMe::insertInVector(std::vector<int>& mainChain, int element, int limit_index) {
    std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.begin() + limit_index, element);
    mainChain.insert(it, element);
}

std::vector<int> PmergeMe::mergeInsertVector(std::vector<int>& input) {
    size_t n = input.size();
    if (n <= 1) return input;

    bool hasStraggler = (n % 2 != 0);
    int straggler = 0;
    if (hasStraggler) {
        straggler = input.back();
        input.pop_back();
    }

    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < input.size(); i += 2) {
        if (input[i] > input[i + 1])
            pairs.push_back(std::make_pair(input[i], input[i + 1]));
        else
            pairs.push_back(std::make_pair(input[i + 1], input[i]));
    }

    std::vector<int> largerElements;
    for (size_t i = 0; i < pairs.size(); ++i)
        largerElements.push_back(pairs[i].first);

    std::vector<int> mainChain = mergeInsertVector(largerElements);

    std::vector<int> pend;
    pend.reserve(pairs.size());
    
    for (size_t i = 0; i < mainChain.size(); ++i) {
        for (size_t j = 0; j < pairs.size(); ++j) {
            if (pairs[j].first == mainChain[i]) {
                pend.push_back(pairs[j].second);
                pairs.erase(pairs.begin() + j);
                break;
            }
        }
    }

    mainChain.insert(mainChain.begin(), pend[0]);
    size_t insertedCount = 1;
    for (size_t k = 3; insertedCount < pend.size(); ++k) {
        size_t currentJacob = getJacobsthal(k);
        size_t limit = std::min(currentJacob, pend.size());
        size_t rangeEnd = limit;
        size_t rangeStart = getJacobsthal(k - 1); 

        for (size_t i = rangeEnd; i > rangeStart; --i) {
            if (i - 1 >= pend.size())
                continue;
            int elementToInsert = pend[i - 1];
            insertInVector(mainChain, elementToInsert, mainChain.size());
            insertedCount++;
        }
    }

    if (hasStraggler) {
        insertInVector(mainChain, straggler, mainChain.size());
    }

    return mainChain;
}

std::vector<int> PmergeMe::sortVector() {
    return mergeInsertVector(_vec);
}

void PmergeMe::insertInDeque(std::deque<int>& mainChain, int element, int limit_index) {
    std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.begin() + limit_index, element);
    mainChain.insert(it, element);
}

std::deque<int> PmergeMe::mergeInsertDeque(std::deque<int>& input) {
    size_t n = input.size();
    if (n <= 1)
        return input;

    bool hasStraggler = (n % 2 != 0);
    int straggler = 0;
    if (hasStraggler) {
        straggler = input.back();
        input.pop_back();
    }

    std::deque<std::pair<int, int> > pairs;
    for (size_t i = 0; i < input.size(); i += 2) {
        if (input[i] > input[i + 1])
            pairs.push_back(std::make_pair(input[i], input[i + 1]));
        else
            pairs.push_back(std::make_pair(input[i + 1], input[i]));
    }

    std::deque<int> largerElements;
    for (size_t i = 0; i < pairs.size(); ++i)
        largerElements.push_back(pairs[i].first);

    std::deque<int> mainChain = mergeInsertDeque(largerElements);

    std::deque<int> pend;
    for (size_t i = 0; i < mainChain.size(); ++i) {
        for (size_t j = 0; j < pairs.size(); ++j) {
            if (pairs[j].first == mainChain[i]) {
                pend.push_back(pairs[j].second);
                pairs.erase(pairs.begin() + j);
                break;
            }
        }
    }

    mainChain.insert(mainChain.begin(), pend[0]);

    size_t insertedCount = 1;
    for (size_t k = 3; insertedCount < pend.size(); ++k) {
        size_t currentJacob = getJacobsthal(k);
        size_t limit = std::min(currentJacob, pend.size());
        size_t rangeEnd = limit;
        size_t rangeStart = getJacobsthal(k - 1); 

        for (size_t i = rangeEnd; i > rangeStart; --i) {
            if (i - 1 >= pend.size())
                continue;
            int elementToInsert = pend[i - 1];
            insertInDeque(mainChain, elementToInsert, mainChain.size());
            insertedCount++;
        }
    }

    if (hasStraggler) {
        insertInDeque(mainChain, straggler, mainChain.size());
    }

    return mainChain;
}

std::deque<int> PmergeMe::sortDeque() {
    return mergeInsertDeque(_deq);
}

static bool isPositiveInteger(const std::string& s) {
    if (s.empty())
        return false;
    for (size_t i = 0; i < s.size(); ++i) {
        if (!isdigit(s[i])) 
            return false;
    }
    return true;
}

bool PmergeMe::parseArgs(int argc, char** argv) {
    _vec.clear();
    _deq.clear();
    for (int i = 1; i < argc; ++i) {
        std::string s(argv[i]);
        if (!isPositiveInteger(s))
            return false;
        long val;
        std::stringstream ss(s);
        ss >> val;
        if (val < 0 || val > 2147483647)
            return false;
        _vec.push_back(val);
        _deq.push_back(val);
    }
    return !_vec.empty();
}