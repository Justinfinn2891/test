
#include "stack.h"
#include <fstream>
#include <iostream>
stack::stack(){
  width = 0;
  height = 0;
  max_color = 0;
  magic_number = "";
}

std::string stack::padWithZeros(int number, int width) {
    return (std::string(width - std::to_string(number).length(), '0') + std::to_string(number));
}

void stack::readFile(std::string name, int amount){
  std::string formatted_amount; 
  int j = 1;
  std::ifstream file;
  
  while(amount > 0){
    formatted_amount = padWithZeros(j, 3);
    std::string filename = "./" + name + "/" + name + "_" + formatted_amount + ".ppm";
    file.open(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }
    std::cout << filename << std::endl;
    int red = 0;
    int blue = 0;
    int green = 0; 
    file >> magic_number >> width >> height >> max_color;
    std::cout << magic_number; 
   
    pixels.resize(width*height);
    // magic number identify
    for(int i = 0; i < height*width; i++){
      file >> red >> green >> blue;
      pixels[i].red += red;
      pixels[i].green += green;
      pixels[i].blue += blue;
    }
    
    j++;
    amount--;
    file.close();
  }

  for (int i = 0; i < 50 && i < pixels.size(); i++) {
     std::cout << pixels[i].red << " " << pixels[i].green << " " << pixels[i].blue << std::endl;
  }
  std::cout << pixels.size();
}
