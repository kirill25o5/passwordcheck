#pragma once
#include <boost/algorithm/string.hpp>
#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include "windows.h"
#include <unordered_set>
#include <set>
#include <string_view>
#include <locale>
#include <vector>
#include <sstream>
#include <map>
#include <regex>

//from "privet" to "привет"
// arguments: password 
//            it - password.begin()
//            passwords - result vector of variants 
//            don't use other arguments
void getRussianWordsFromRussianEnglish(const std::string & password, std::string::const_iterator it, std::vector<std::string> & passwords,
                                       const std::string & newSymbols = "", std::string newPassword = "");

//from "ghbdtn" to "привет"
std::string getRussianWordFromEnglishLetters(const std::string & password);


//general func to count password complexity
int analizePasswordByWords(const std::string & password);


int sumLengthOfWords(const std::vector<std::pair<int, std::string>> & words);


bool getLowerCaseSet(const std::string_view & first3character, bool isRussian, const std::locale & loc, std::set<std::string> & data);


bool getWordFromSubPassword(const std::string & subPassword, const std::set<std::string> & data, std::string & word);


void getWordsFromPasswordForParticularCase(const std::string & password, bool isRussian, std::vector<std::pair<int, std::string>> & words);


void getWordsFromPassword(const std::string & password, std::vector<std::pair<int, std::string>> & words);


std::vector<std::string> determineWichWordsUsed(std::vector<std::pair<int, std::string>> & rawWords);

int getAmountOfDistringSubstrings(std::string password);


int getPossibleDates(std::string password);
