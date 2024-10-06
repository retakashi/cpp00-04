#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

class Replace {
 private:
  std::string inFilename;
  std::string s1;
  std::string s2;
  std::string outFilename;
  std::string fileStr;
  size_t s1Len;
  size_t s2Len;

 public:
  Replace(const std::string filename, std::string s1, std::string s2);
  ~Replace();
  void replaceS1S2();
  void setOutFilename();
  void readFileToStr(std::string filename);
  size_t findS1(std::string fileStr, std::string s1, size_t pos);
  void replaceFileStr();
  void writeFileStr(std::string outFilename);
  const std::string getInFilename() const;
  const std::string getFileStr() const;
  const std::string getS1() const;
  const std::string getOutFilename() const;
};
#endif