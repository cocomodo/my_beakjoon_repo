#include <string>
#include <vector>
// #include <iostream>
#include <bits/stdc++.h>

using namespace std;

string solution(string letter) {
    string answer = "";
    unordered_map<string, string> morse = { 
        {".-","a"},
        {"-...","b"},
        {"-.-.","c"},
        {"-..","d"},
        {".","e"},
        {"..-.","f"},
        {"--.","g"},
        {"....","h"},
        {"..","i"},
        {".---","j"},
        {"-.-","k"},
        {".-..","l"},
        {"--","m"},
        {"-.","n"},
        {"---","o"},
        {".--.","p"},
        {"--.-","q"},
        {".-.","r"},
        {"...","s"},
        {"-","t"},
        {"..-","u"},
        {"...-","v"},
        {".--","w"},
        {"-..-","x"},
        {"-.--","y"},
        {"--..","z"}
    };
    string tmp;
    for(auto c: letter){
        if(c==' '){
            answer+=morse[tmp];
            tmp="";
        }
        else tmp+=c;
    }
    answer+=morse[tmp];
    return answer;
}