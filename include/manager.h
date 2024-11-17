#ifndef PID_H
#define PID_H
#include <string>
#include <vector>

bool pidVerify(int pid);
bool fileManager(std::string path, std::vector<std::string> fileStrings, std::string findOnly);

#endif //PID_H
