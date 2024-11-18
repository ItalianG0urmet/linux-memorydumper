#include "../../include/manager.h"

#include <fstream>
#include <iostream>
#include <csignal>
#include <vector>
#include <regex>



bool pidVerify(int pid) {
   return (kill(pid, 0) != 0);
}

void lineFormatter(std::string line, std::vector<std::string> fileStrings, const std::string& findOnly) {

   if (line.find('/') == std::string::npos) return;
   std::regex pattern(R"(^.*?/)");

   line = std::regex_replace(line, pattern, "");
   if (!findOnly.empty() && line.find(findOnly) != std::string::npos) {
      std::cout << line << std::endl;
      fileStrings.push_back(line);
   } else {
      std::cout << line << std::endl;
      fileStrings.push_back(line);
   }
}


bool fileManager(const std::string& path, std::vector<std::string> fileStrings, std::string findOnly){

   std::ifstream infile;
   infile.open(path);
   std::string line;

   if (infile.fail()) return false;

   while (getline(infile, line))
      lineFormatter(line, fileStrings, findOnly);

   infile.close();

   return true;
}
