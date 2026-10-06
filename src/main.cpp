#include <iostream>
#include <string>
#include "TypingSession.hpp"

int main(int argc, char* argv[]){
    std::cout << "Welcome to Super Fortnight Typing!" << std::endl;
    std::string text = "The quick brown fox jumps over the lazy dog";
    StringTypingSession session(text);
    std::string input;
    std::cout << text << std::endl;
    while(!session.passageComplete()){
        std::cin >> input;
        input.push_back(' ');
        session.submitText(input);
    }
    std::cout << session.mistakeCount() << " mistakes." << std::endl;
    return 0;
}
