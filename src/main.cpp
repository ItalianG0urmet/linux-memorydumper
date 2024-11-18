#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <vector>

#include "../include/manager.h"

bool onlyModified = true;
std::string onlyFindString;
std::string pid;
std::string mapPath = "/proc/";
std::vector<std::string> fileStrings;

void loadArgs (int argc, char *argv[]);

int main(int argc, char *argv[]) {

    using std::cout, std::cerr, std::endl;

    loadArgs(argc, argv);
    try {

        if (pid.empty()) {
            cerr << "You must provide a process ID" << endl;
            return EXIT_FAILURE;
        }

        int pidVal = std::stoi(pid);
        if (pidVerify(pidVal)) {
            cerr << "Invalid pid: " << pidVal << endl;
            return 1;
        }

        mapPath.append(pid + "/maps");
        if (!fileManager(mapPath, fileStrings, onlyFindString)) {
            return 1;
        }
    } catch (const std::invalid_argument &e) {
        cerr << "Invalid PID format" << endl;
        return 1;
    }

    return 0;
}


void loadArgs (int argc, char *argv[]) {

    int opt;

    while ((opt = getopt(argc, argv, "p:f:")) != -1) {
        switch (opt) {
            case 'p':
                pid = optarg;
                break;
            case 'f':
                onlyFindString = optarg;
                break;
            case 'd':
                onlyModified = true;
            break;
            case '?':
                default:
                    std::cerr << "Use: " << argv[0] << " -p <PID> [-f <arg>]\n";
            exit(EXIT_FAILURE);
        }
    }
}