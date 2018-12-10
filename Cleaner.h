#ifndef _CLEANER_H_
#define _CLEANER_H_

#include <list>
#include <string>

class Cleaner {
   private:
    std::list<std::string> validWords;
    std::list<std::pair<std::string, int>> frequencyPairs;
    int largestWordSize;

   public:
    Cleaner();
    void addWord(std::string potentialWord);
    ~Cleaner();
};

#endif