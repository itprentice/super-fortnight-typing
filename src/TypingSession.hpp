#ifndef TYPINGSESSION_H
#define TYPINGSESSION_H

#include "Passage.hpp"
#include <string>
#include <string_view>
#include <vector>
#include <cstddef>
// #include <utility>
template <typename CharT>
class TypingSession{
  private:
    Passage<CharT> passage;
    std::size_t pIndex;
    std::vector<std::size_t> mistakes;
  public:
    TypingSession(std::basic_string<CharT> text)
      : passage(text), pIndex(0) {}

    inline bool passageComplete(){
      return pIndex >= passage.size();
    }

    void backspace(){
      if (pIndex >= 0){
        if (pIndex == mistakes.back()){
          mistakes.pop_back();
        }
        pIndex--;
      }
    }
    void submitText(std::basic_string_view<CharT> text){
      // std::size_t index = pIndex;
      for (auto c : text){
        if (passageComplete()){
          break;
        }
        if (!passage.isCharAtCorrect(c, pIndex)){
          mistakes.push_back(pIndex);
        }
        pIndex++;
      }
    }
    // void submitFullAttempt(std::basic_string_view<CharT> text);
    inline size_t mistakeCount(){
      return mistakes.size();
    }

};
typedef TypingSession<char> StringTypingSession ;
#endif
