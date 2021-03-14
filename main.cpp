#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

std::string strip(std::string string1);

// the name of var's have to be the same
std::vector<std::string> split(std::string str);
//
int main(int argc, char *argv[]) {
    std::string last;
    std::string min;
    std::string max;
    char la1;
    int z;
    int y;
    std::string b;
    std::vector<int> sh2;
    std::vector<int> sh1;
    // to make possible terminal arguments.
    if (argc > 1) {
        b = std::string{argv[1]};
    } else {
        b = "./input.txt";
    }
    //
    std::string a;
    std::ifstream file(b);
    if (!file) {
        std::cout << "file wasn't open" << std::endl;
        // The exit here is very important, because the program can not working correctly after this moment.
        exit(1);
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

//    std::cout << last << std::endl;
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
    std::vector<std::string> words = split(last);


    for (auto word: words)
        if (word.length()>max.length()){max = word;};
    min = max;
    for (auto word: words)
        if (word.length()<min.length()){min = word;};

    std::cout<<min<<"     " <<max<<std::endl;

    for (auto word: words)
        std::cout<<strip(word)<<std::endl;
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

std::string strip(std::string string1){
    std::string last;
    while((!isalpha(string1[0]))){
        if (!isalpha(string1[0])){
            for (int i=1; i<string1.length()+1; ++i)
                last.push_back(string1[i]);
            string1 = last;
        }
        last="";
    }
    while((!isalpha(string1[string1.length()-1]))){
        if (!isalpha(string1[string1.length()-2])){
            for (int i=0; i<string1.length()-2; ++i)
                last.push_back(string1[i]);
            string1 = last;
        }
        last="";
    }
    return string1;
}






