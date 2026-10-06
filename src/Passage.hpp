#include <string>
template <typename CharT>
class Passage{
  protected:
    std::basic_string<CharT> text;
  public: 
    Passage(std::basic_string<CharT> t) : text(t) {}
    /**
     * input: a character and an index that the caller believes contains the passed character
     * output: true if character c is at the specified index in the passage, false otherwise
     */
    inline bool isCharAtCorrect(CharT c, size_t index){
      return c == text[index];
    }
    /**
     * input: an attempt at replicating the passage text
     * output: the number of mistakes in the attempt
     */
    // size_t gradeString(std::basic_string_view<CharT> attempt, size_t startingIndex);

    inline size_t size(){
      return text.size();
    }
};
typedef Passage<char> StringPassage;
