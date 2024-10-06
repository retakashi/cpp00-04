#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
private:
    static const int strArrLen = 100;
    std::string ideas[strArrLen];

public:
    Brain();
    Brain(const Brain &other);
    Brain &operator=(const Brain &other);
    ~Brain();
    const std::string getIdeas(int i) const;
    void setIdeas(int i, std::string str);
};
#endif
