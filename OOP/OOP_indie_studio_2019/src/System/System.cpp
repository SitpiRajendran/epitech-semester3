#include <fstream>
#include <dirent.h>
#include <iostream>
#include "System.hpp"
#include "MapGenerator.hpp"

System::System() {}
System::~System() {}

void System::saveMap(std::vector<std::string> map) {
    std::string strmap = "";
    std::ofstream file("Maps/.SavedMap");

    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[i].size(); j++) {
            if (map[i][j] != ' ' && map[i][j] != '#' && map[i][j] != 'C')
                map[i][j] = ' ';
        }
    }
    map[1][1] = '1';
    map[20][20] = '2';
    for (size_t i = 0; i < map.size(); i ++)
        strmap += map[i] + "\n";
    file << strmap;
    file.close();
    strmap.clear();
}

std::vector<std::string> System::loadMap() {
    std::string tmp;
    std::vector<std::string> load;
    std::ifstream file("Maps/.SavedMap");

    if (file.is_open() == false) {
        printf("generate\n");
        return (indie::MapGenerator().generate());
    }
    while (getline(file, tmp)){
        load.push_back(tmp);
        printf("%s\n", tmp.c_str());
    }
    file.close();
    tmp.clear();
    return load;
}

std::vector<std::string> System::loadStat(std::string name)
{
    DIR *pDIR;
    std::string statsLine;
    std::string file;
    std::ifstream StatFile;
    std::string fileName = "./Maps/";
    std::vector<std::string> load;
    struct dirent *entry;
    int found = 0;

    pDIR = opendir("./Maps");
    if (pDIR == nullptr)
        throw (Exception("Can't find Saves directory"));
    while (entry = readdir(pDIR)) {
        file.assign(entry->d_name);
        if (file.find(name) != std::string::npos) {
            fileName.append(file);
            found = 1;
        }
    }
    closedir(pDIR);
    if (found == 0)
        throw (Exception("Can't find save file file"));
    StatFile.open(fileName);
    if (StatFile.is_open() == false)
        throw (Exception("Can't open save file"));
    while (getline(StatFile, statsLine))
        load.push_back(statsLine);
    StatFile.close();
    return (load);
}