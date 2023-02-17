#include "types.h"
#include "pupa.h"
#include "keyboarddispersion.h"


//int sumLengthOfWords(const std::vector<std::pair<int,std::string>> & words)
//{
//  int sum = 0;
//  for (auto & i : words)
//    sum += i.second.length();
//
//  return sum;
//}
//
//bool getLowerCaseSet(const std::string_view & first3character, bool isRussian, const std::locale & loc, std::set<std::string> & data)
//{
//  data.clear();
//  if (std::isdigit(first3character.front()))
//    return false;
//
//  std::string path;
//  if (isRussian)
//  {
//    std::stringstream ss;
//    ss << "dictionary\\" << char(std::toupper(first3character.front())) << ".txt";
//    path = ss.str();
//  }
//  else
//  {
//    std::stringstream ss;
//    ss << "dictionary_eng\\" << char(std::tolower(first3character.front())) << ".txt";
//    path = ss.str();
//  }
//
//  std::string line;
//  std::ifstream in(path);
//  if (in.is_open())
//  {
//    while (getline(in, line))
//    {
//      if (boost::algorithm::istarts_with(line, first3character, loc))
//        break;
//    }
//
//    if (in.eof())
//      return false;
//
//    do
//    {
//      boost::algorithm::to_lower(line, loc);
//      if(isRussian)
//        boost::algorithm::ireplace_all(line, "¸", "å", loc);
//      if (boost::algorithm::istarts_with(line, first3character, loc) == false)
//        break;
//      data.insert(line);
//    } while (getline(in, line));
//  }
//  else
//  {
//    return false;
//  }
//  in.close();
//
//  return true;
//}
//
//
//bool getWordFromSubPassword(const std::string & subPassword, const std::set<std::string> & data, std::string & word)
//{
//  word.clear();
//
//  size_t pos = 3;
//
//
//  for (;;)
//  {
//    auto subStr = subPassword.substr(0, pos++);
//    auto it = data.equal_range(subStr);
//
//    if (it.first!=data.end() && *it.first == subStr)
//      word = subStr;
//
//    if (it.first == it.second && (it.second == data.end() || boost::algorithm::starts_with(*it.second, subStr) == false))
//      break;
//
//    if (subPassword.size() < pos)
//      break;
//  }
//  
//  if (word.empty())
//    return false;
//  return true;
//}
//
//
//void getWordsFromPasswordForParticularCase(const std::string & password, bool isRussian, std::vector<std::pair<int,std::string>> & words)
//{
//  if (password.length() < 3)
//    return;
//
//  setlocale(LC_ALL, "");
//  std::locale loc; 
//  if (isRussian)
//    loc = std::locale("russian");
//  else
//    loc = std::locale("english");
//
//  std::string passwordCopy = boost::algorithm::to_lower_copy(password, loc);
//  if (isRussian)
//    boost::algorithm::ireplace_all(passwordCopy, "¸", "å", loc);
//
//  std::string_view passwordSW = passwordCopy;
//  for (int pos = 0; pos < passwordCopy.size() - 2; pos++)
//  {
//    auto subWord = passwordSW.substr(pos);
//
//    std::set<std::string> wordsForSearchingFrom;
//    if (getLowerCaseSet(subWord.substr(0, 3), isRussian, loc, wordsForSearchingFrom) == false)
//      continue;
//
//    std::string resultWord;
//    if (getWordFromSubPassword(std::string(subWord.begin(), subWord.end()), wordsForSearchingFrom, resultWord))
//    {
//      words.push_back(std::make_pair(pos,resultWord));
//      pos += resultWord.length() - 1;
//    }
//  }
//}
//
//
//void getWordsFromPassword(const std::string & password, std::vector<std::pair<int, std::string>> & words)
//{
//  words.clear();
//
//  std::string passwordCP = password;
//  boost::algorithm::to_lower(passwordCP);
//
//  getWordsFromPasswordForParticularCase(passwordCP, false, words);
//
//  std::string passwordRus = getRussianWordFromEnglishLetters(passwordCP);
//  getWordsFromPasswordForParticularCase(passwordRus, true, words);
//  
//  std::vector<std::pair<int,std::string>> buffer1, buffer2;
//  std::vector<std::string> passwordsRus;
//  getRussianWordsFromRussianEnglish(passwordCP, passwordCP.begin(), passwordsRus);
//  for (auto & pass : passwordsRus)
//  {
//    buffer1.clear();
//    getWordsFromPasswordForParticularCase(pass, true, buffer1);
//    if (sumLengthOfWords(buffer1) > sumLengthOfWords(buffer2))
//    {
//      buffer2.swap(buffer1);
//    }
//  }
//  words.insert(words.end(),buffer2.begin(), buffer2.end());
//  std::sort(words.begin(), words.end(), [](const std::pair<int, std::string> & a, const std::pair<int, std::string> & b)
//  {
//    return a.second.length() > b.second.length();
//  });
//}
//
//
//std::vector<std::string> determineWichWordsUsed(std::vector<std::pair<int, std::string>> & rawWords)
//{
//  if (rawWords.empty())
//    return std::vector<std::string>();
//
//  std::vector<std::string> words;
//  std::vector<std::pair<int, std::string>> bufferWords;
//
//  bufferWords.push_back(rawWords.front());
//  rawWords.erase(rawWords.begin());
//  for (auto & newWord : rawWords)
//  {
//    int flag = 0;
//    for (auto & bufWord : bufferWords)
//    {
//      if (newWord.first >= bufWord.first && newWord.first < bufWord.first + bufWord.second.length()-1
//          || newWord.first+newWord.second.length() -1 >= bufWord.first 
//             && newWord.first + newWord.second.length() - 1 < bufWord.first + bufWord.second.length() - 1)
//        flag++;
//    }
//    if (flag == 0)
//      bufferWords.push_back(newWord);
//  }
//
//  for (auto & i : bufferWords)
//  {
//    words.push_back(i.second);
//  }
//
//  return words;
//}
//
//
//int analizePasswordByWords(const std::string & password)
//{
//  std::vector<std::pair<int, std::string>>  rawWords;
//  getWordsFromPassword(password, rawWords);
//  
//  std::vector<std::string> wordsInPassword = determineWichWordsUsed(rawWords);
//  if (wordsInPassword.size() >= 4)
//    return 100;
//
//  int lengthOfWords = 0;
//  for (auto & i : wordsInPassword)
//    lengthOfWords += i.length();
//  int rating = static_cast<int>((float(lengthOfWords) / float(password.length())) * 100);
//  if (rating > 100)
//    rating = 100;
//  rating = 100 - rating;
//
//  switch (wordsInPassword.size())
//  {
//  case 3:
//    rating += 50;
//    break;
//
//  case 2:
//    rating += 25;
//    break;
//
//  default:
//    break;
//  }
//
//  if (rating > 100)
//    rating = 100;
//
//  return rating;
//}


int main(int argc, char ** argv) {

  enum {
    forWords = 30,
    forLen = 100,
    forKeyb = 75,
    forSubs = 20,
    forDates = 20,
    forDistant=40
  };


 if (argc != 2)
  std::cout << "invalid input";
 
 int passByWords= analizePasswordByWords(argv[1]);
 std::cout << "words " << passByWords << std::endl;
 
 int passByLenAndComb =  analizePasswordByLenAndCombinatoryComplexity(argv[1]);
 std::cout << "len " << passByLenAndComb << std::endl;
 
 int passByKeyboard = keyboardDispersionScore(argv[1]);
 std::cout << "keyboard " << passByKeyboard << std::endl;
 
 int passBySubs = getAmountOfDistringSubstrings(argv[1]);
 std::cout << "subs " << passBySubs << std::endl;
 
 int passByDates = getPossibleDates(argv[1]);
 std::cout << "date " << passByDates << std::endl;

 int passByDistantScore = static_cast<int>(scoreOfKeysAccuracy(argv[1]));
 std::cout << "accuracy " << passByDistantScore << std::endl;
 
 std::cout << "average " << (passByWords*forWords+
                             passByLenAndComb*forLen+
                             passByKeyboard*forKeyb+
                             passBySubs*forSubs+
                             passByDates*forDates+
                             passByDistantScore*forDistant)/(forWords+forLen+forKeyb+forSubs+forDates+forDistant) << std::endl;


 return 0;
}

















