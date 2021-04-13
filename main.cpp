#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>


std::vector <std::string> preprocessing(std::string path);

std::string strip(std::string string1);

// the name of var's have to be the same
std::vector <std::string> split(std::string str);

//
int main(int argc, char *argv[]) {
    std::string last;
    std::string min;
    std::string max;
    int result = 0;
    char la1;
    int z;
    int y;
    int Max_result=0;
    int Min_result=0;
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
    while (!file.eof()) {
        getline(file, a);
        last.push_back(' ');
        for (int i = 0; i < a.length(); ++i) {
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
    std::vector <std::string> words = preprocessing("./input.txt");


    for (auto word: words)
        if (word.length() > max.length()) { max = word; };
    min = max;
    for (auto word: words)
        if (word.length() < min.length()) { min = word; };

    for (auto word: words){
        if (word.length() == max.length()){Max_result+=1;}
        if (word.length() == min.length()){Min_result+=1;}
    }
    std::cout <<"min:  "<< min << std::endl;
    std::cout <<"max:  "<< max << std::endl;
    std::cout <<"min_count:  "<< Min_result << std::endl;
    std::cout <<"max_count:  "<< Max_result << std::endl;

   /* for (auto word: words)
        std::cout << strip(word) << std::endl;*/

    std::vector <std::string> words3 = preprocessing("./input.txt");

    for (auto word: words3) {
        std::cout << word << "   ";
        result += 1;
    }
    std::cout << std::endl;
    std::cout << "result of the last task:  "<<result;
}

std::vector <std::string> split(std::string str) {
    std::vector <std::string> sh;
    std::string buf;
    std::stringstream ss(str);

    std::vector <std::string> tokens;

    while (ss >> buf)
        tokens.push_back(buf);

    for (auto &st:tokens) {
        sh.push_back(st);
    }
    return sh;

}

std::string strip(std::string input_string) { // better name is input_string
    if (input_string.length() != 1) {
        std::string las; // I didn`t understand the meaning of this variable =)
        while ((!isalpha(input_string[0]))) {
            if (!isalpha(input_string[0])) {
                for (int i = 1; i < input_string.length() + 1; ++i)
                    las.push_back(input_string[i]); // better use string stream (more in the tasks I asked to make)
                input_string = las;
            }
            las = "";

            if (input_string.length() == 1) {}
            while ((!isalpha(input_string[input_string.length() - 2]))) {
                if (!isalpha(input_string[input_string.length() - 2])) {
                    for (int i = 0; i < input_string.length() - 2; ++i)
                        las.push_back(input_string[i]);
                    input_string = las;
                }
                las = "";
            }
        }
    }
    /*
     * How to do better? (if you know lambda functions and iterators (we will learn that =)))
void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return std::isalpha(ch);
    }));
}
static inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isalpha(ch);
    }).base(), s.end());
}
static inline void strip(std::string &s) {
    ltrim(s);
    rtrim(s);
}
     *
     * */
    return input_string;
}



//Last task // not clear name, what is the functional of the function?
///////////////////////////////?
// Where formatting was??? CLion can make a perfect formatting for you, just press Ctrl+Alt+l
///////////////////////////////?
std::vector <std::string> preprocessing(std::string path) {
    std::string z;
    std::string last02;
    std::ifstream file02(path);
    std::string last01 = "";
    while (!file02.eof()) {
        getline(file02, z);
        z+=" ";//function split ignore other
        for(auto &letter :z){
            last01+=(std::tolower(letter));
        } // lines 170-173 - you just copy the line char by char. why?
    }

    std::vector <std::string> words2 = split(last01);


    for (auto &word: words2) {
        word = strip(word);
    }// as you can see here. split fn doesn`t did it`s job, because to the input you gave one word....
    return words2;

}





