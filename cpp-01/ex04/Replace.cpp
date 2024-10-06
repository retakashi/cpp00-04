#include "Replace.hpp"

Replace::Replace(const std::string filename, std::string s1, std::string s2)
    : inFilename(filename), s1(s1), s2(s2) {
  this->s1Len = this->s1.length();
  this->s2Len = this->s2.length();
}

Replace::~Replace() {}

void Replace::replaceS1S2() {
  this->setOutFilename();
  this->readFileToStr(this->getInFilename());
  this->replaceFileStr();
  this->writeFileStr(this->getOutFilename());
}

void Replace::setOutFilename() {
  size_t pos;

  pos = this->inFilename.find(".");
  if (pos != std::string::npos && pos != 0)
    this->outFilename = this->inFilename.substr(0, pos);
  else
    this->outFilename = this->inFilename.substr(0);
  this->outFilename.append(".replace");
}

void Replace::readFileToStr(std::string filename) {
  std::ifstream in_fs;
  std::ostringstream ostr;

  in_fs.open(filename);
  if (!in_fs) {
    std::cerr << "File doesn't exit." << std::endl;
    std::exit(EXIT_FAILURE);
  }
  ostr << in_fs.rdbuf();
  this->fileStr = ostr.str();
}

size_t Replace::findS1(std::string file_str, std::string s1, size_t pos) {
  size_t ret;

  if (s1.empty()) return (std::string::npos);
  ret = file_str.find(s1, pos);
  return (ret);
}

void Replace::replaceFileStr() {
  size_t pos;

  if (this->s1.empty() && this->fileStr.empty())
  {
    this->fileStr.insert(0, this->s2);
    return ;
  }
  pos = this->findS1(this->getFileStr(), this->getS1(), 0);
  while (pos != std::string::npos) {
    this->fileStr.erase(pos, this->s1Len);
    this->fileStr.insert(pos, this->s2);
    pos = this->findS1(this->getFileStr(), this->getS1(), pos + this->s2Len);
  }
}

void Replace::writeFileStr(std::string outFilename) {
  std::ofstream rep_fs;

  rep_fs.open(outFilename);
  if (!rep_fs) {
    std::cerr << "Failed to open out file." << std::endl;
    std::exit(EXIT_FAILURE);
  }
  rep_fs << this->getFileStr();
}

const std::string Replace::getInFilename() const { return (this->inFilename); }
const std::string Replace::getFileStr() const { return (this->fileStr); }
const std::string Replace::getS1() const { return (this->s1); }
const std::string Replace::getOutFilename() const { return (this->outFilename); }