#include "../../include/manager.h"

#include <fstream>
#include <iostream>
#include <signal.h>
#include <vector>
#include <regex>


std::regex pattern(R"(^.*?/)");

bool pidVerify(int pid) {
   return (kill(pid, 0) != 0);
}

void lineFormatter(std::string line, std::vector<std::string> fileStrings, std::string findOnly) {
   if (line.find("/") == std::string::npos) return;

   line = std::regex_replace(line, pattern, "");
   if (!findOnly.empty()) {
      if (line.find(findOnly) != std::string::npos) {
         std::cout << line << std::endl;
         fileStrings.push_back(line);
      }
   } else {
      std::cout << line << std::endl;
      fileStrings.push_back(line);
   }
}


bool fileManager(std::string path, std::vector<std::string> fileStrings, std::string findOnly){

   using  std::cout, std::string, std::endl ;

   std::ifstream infile;
   infile.open(path);

   if (infile.fail()) {
      return false;
   }

   string line;

   while (getline(infile, line)) {
      lineFormatter(line, fileStrings, findOnly);
   }

   infile.close();

   return true;
}
