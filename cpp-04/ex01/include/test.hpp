#ifndef TEST_HPP
#define TEST_HPP

#define ENDL std::cout << std::endl;
#define OUT_TITLE(title) std::cout << "\n<< " << (title) << " >>" << std::endl;
#define RESULT(obj) std::cout << obj;
#define SET_IDEA(obj, idx, str) obj.getBrainP()->setIdeas(idx, str);
#define GET_IDEA(obj, idx) std::cout << "ideas[" << idx << "] " << obj.getBrainP()->getIdeas(idx) << std::endl;
#define SET_IDEAS(obj, until, str) \
    if (until >= 0 && until < 100) { \
        for (int i = 0; i < until; ++i) obj.getBrainP()->setIdeas(i, str); \
    } else { std::cout << "SET_IDEAS: Invalid number" << std::endl; };
#define GET_IDEAS(obj, until) \
    if (until >= 0 && until < 100) { \
        for (int i = 0; i < until; ++i) std::cout << "ideas[" << i << "] " << obj.getBrainP()->getIdeas(i) << std::endl; \
    } else { std::cout << "GET_IDEAS: Invalid number" << std::endl; };
#endif
