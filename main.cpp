#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

std::vector<std::string> vsor(std::string sor);

int main() {
    int max=0;
    int min=0;
    int z;
    int y;
    std::vector<int> sh2;
    std::vector<int> sh1;
    std::string b = "./input.txt";
    std::string a;
    std::ifstream file(b);
    if (!file) {
        std::cout << "file wasn't open" << std::endl;
    } else {
        std::cout << "file was open" << std::endl;
    }
    getline(file, a);

    std::cout << a << std::endl;
    for (int i = 0; i < a.length(); ++i){
        sh2.push_back(vsor(a)[i].length());
}
    for (int i = 0; i < a.length(); ++i){
        if (sh2[i]>max){
            max = sh2[i];
            z = i;
        }
        if (sh2[i]<min){
            min = sh2[i];
            y = i;
        }
    }
    std::cout<<'min:'<<sh1[z]<<'   max:'<<sh1[y];
}

std::vector<std::string> vsor(std::string str){
    std::vector<std::string> sh;
    std::string buf;
    std::stringstream ss(str);

    std::vector<std::string> tokens;

    while (ss >> buf)
        tokens.push_back(buf);

    for (auto &st:tokens) {
        sh.push_back(st);
    }
    return sh;

}

