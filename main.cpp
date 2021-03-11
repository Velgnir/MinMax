#include <iostream>
#include <string>

std::string strip(std::string string1);

int main() {
    std::cout<<strip(".,...../.,Clovo,,/.....");
    return 0;
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
