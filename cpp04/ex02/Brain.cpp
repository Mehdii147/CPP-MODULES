#include "Brain.hpp"   

Brain::Brain()
{
    for (int i = 0; i < 100; i++)
    {
        this->ideas[i] = "empty";
    }
    std::cout << "Constructer Brain Called" << std::endl;
}

Brain::Brain(const Brain &copy)
{
    int i = 0;
    while (i < 100)
    {
        this->ideas[i] = copy.ideas[i];
        i++;
    }
}

Brain &Brain::operator=(const Brain &copy)
{
    if (this != &copy){
        for (int i = 0; i < 100; i++)
        {
            this->ideas[i] = copy.ideas[i];
        }
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "Destructer Brain Called" << std::endl;
}

