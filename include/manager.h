#ifndef MANAGER_H
#define MANAGER_H
#include <string>
#include <vector>

bool pidVerify(int pid);
bool fileManager(const std::string& path, std::vector<std::string> fileStrings, std::string findOnly);

#endif //MANAGER_H
