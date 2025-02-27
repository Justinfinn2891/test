#include <vector> 
#ifndef STACK_H
#define STACK_H
#include <string>
struct pixel{
  int red;
  int green;
  int blue;
};

class stack{

 private:
  std::string magic_number;
  int width;
  int height;
  int max_color;
  std::vector<pixel> pixels;
  std::string filename;
 public:
  stack();
  void readFile(std::string filename, int amount);

};


#endif
