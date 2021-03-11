#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

std::vector<std::string> split(std::string sor);

int main() {
    std::string last;
    std::string min;
    std::string max;
    char la1;
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
    while (!file.eof())
    {
        getline(file,a);
        last.push_back(' ');
        for (int i=0; i < a.length(); ++i) {
            la1 = a[i];
            last.push_back(la1);
        }
    }
    //getline(file, a);

    std::cout << last << std::endl;
    for (int i = 0; i < sh1.size(); ++i)
        sh2.push_back(split(a)[i].length());

    /*for (int i = 0; i < sh1.size(); ++i){
        if (sh2[i]>max){
            max = sh2[i];
            z = i;
        }
        if (sh2[i]<min){
            min = sh2[i];
            y = i;
        }
    }
    */
    std::vector<std::string> words = split(a);


    for (auto word: words)
        if (word.length()>max.length()){max = word;};
    min = max;
    for (auto word: words)
        if (word.length()<min.length()){min = word;};

    std::cout<<min<<"     " <<max;
}

std::vector<std::string> split(std::string str){
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

