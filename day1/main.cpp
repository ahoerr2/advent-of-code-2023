#include <cctype>
#include <fstream>
#include <ostream>
#include <stdio.h>
#include <ranges>
#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>

constexpr const char inputFile[] = "../input.txt";

int main(int, char**){

  // Part 1

  std::ifstream input(inputFile);
  std::string line;
  uint total;
  if (!input.is_open()) {
    std::cerr << "Error Reading File!" << std::endl;
    return 1;
  }
  
  // Reads the lines of the file and extracts the first and last digits of the line to add to total
  auto parseLine = [](const std::string & line){
    uint firstNum = 0;
    uint lastNum = 0;
    for (unsigned char letter : line) {
      firstNum = (std::isdigit(letter) && firstNum == 0) ? letter - '0' : firstNum;
      lastNum = (std::isdigit(letter)) ? letter - '0' : lastNum;
    }

    // First and last digits are combined (ex 7   4 = 74) and are added to total 
    return (firstNum * 10) + lastNum;
  };

  while (std::getline(input, line)) {
    total += parseLine(line);
  }   
  
  input.close();
  std::cout << "Part 1 Total: " << total << "\n";
  
  // Total 55130
  

  // Part 2
  
  input.open(inputFile);
  total = 0;
  line = "";

  if (!input.is_open()) {
    std::cerr << "Error Reading File!" << std::endl;
    return 1;
  }

  std::unordered_map<std::string, uint> digit_map = {
    {"one",1},
    {"two",2},
    {"three",3},
    {"four",4},
    {"five",5},
    {"six",6},
    {"seven",7},
    {"eight",8},
    {"nine",9},
  };
  
  // Utils for finding substrings and replacing strings
  
  auto contains = [](const std::string & str, const std::string & subStr){
    auto pos = str.find(subStr);
    // Checks if substring exists (posititve position instead of -1)
    return pos != std::string::npos;
  };

  auto replace = [](std::string & str, const std::string & replaceStr, const std::string & replacementStr) {
    auto pos = str.find(replaceStr);
    return str.replace(pos,replaceStr.length(),replacementStr);
  };

  while (std::getline(input, line)) {
  // Replace the numeric digits in the line with actual digits so that previous parsing code can parse string ex(six -> 6)
    for (const auto& pair : digit_map) {
      while (contains(line, pair.first)){
        // Since all collisions (oneight) are based on one letter, replace the string with the digit and first and last char of word number ex.(t2o)
        std::string tufString = std::string(1,pair.first.front()) + std::to_string(pair.second) + std::string(1,pair.first.back());
        replace(line, pair.first, tufString);
      }
    }
    total += parseLine(line);
  }   
  
  
  input.close();
  std::cout << "Part 2 Total: " << total << "\n";

  // Total 54985

  return 0;
}
