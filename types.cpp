#include "types.h"
//-----------------------------------------------------------------------------------------------------------------------------------------
void getRussianWordsFromRussianEnglish(const std::string & password, std::string::const_iterator it, std::vector<std::string> & passwords,
                                       const std::string & newSymbols, std::string newPassword)
{
  setlocale(LC_ALL, "");
  newPassword.append(newSymbols);

  for (auto i = it; i != password.end(); ++i)
  {
    switch (*i)
    {
    case 'q':
      getRussianWordsFromRussianEnglish(password, i + 1, passwords, "ךף", newPassword);
      newPassword.append("ך");
      break;

    case 'w':
      getRussianWordsFromRussianEnglish(password, i + 1, passwords, "ף", newPassword);
      newPassword.append("ג");
      break;

    case 'e':
      getRussianWordsFromRussianEnglish(password, i + 1, passwords, "ט", newPassword);
      getRussianWordsFromRussianEnglish(password, i + 1, passwords, "‎", newPassword);
      newPassword.append("ו");
      break;

    case '3':
      getRussianWordsFromRussianEnglish(password, i + 1, passwords, "ט", newPassword);
      getRussianWordsFromRussianEnglish(password, i + 1, passwords, "‎", newPassword);
      getRussianWordsFromRussianEnglish(password, i + 1, passwords, "ח", newPassword);
      newPassword.append("ו");
      break;

    case 'r':
      newPassword.append("נ");
      break;

    case 't':
      newPassword.append("ע");
      break;

    case 'y':
      if (i + 1 != password.end() && *(i + 1) == 'a')
      {
        getRussianWordsFromRussianEnglish(password, i + 2, passwords, "üÿ", newPassword);
        getRussianWordsFromRussianEnglish(password, i + 2, passwords, "טÿ", newPassword);
        newPassword.append("ÿ");
        i++;
        break;
      }

      if (i + 1 != password.end() && *(i + 1) == 'e')
      {
        getRussianWordsFromRussianEnglish(password, i + 2, passwords, "üו", newPassword);
        getRussianWordsFromRussianEnglish(password, i + 2, passwords, "טו", newPassword);
        newPassword.append("ו");
        newPassword.append("ו");
        i++;
        break;
      }

      if (i + 1 != password.end() && *(i + 1) == 'o')
      {
        getRussianWordsFromRussianEnglish(password, i + 2, passwords, "ימ", newPassword);
        getRussianWordsFromRussianEnglish(password, i + 2, passwords, "ü¸", newPassword);
        getRussianWordsFromRussianEnglish(password, i + 2, passwords, "ת¸", newPassword);
        newPassword.append("¸");
        i++;
        break;
      }

      getRussianWordsFromRussianEnglish(password, i + 1, passwords, "û", newPassword);
      getRussianWordsFromRussianEnglish(password, i + 1, passwords, "ט", newPassword);
      getRussianWordsFromRussianEnglish(password, i + 1, passwords, "ü", newPassword);
      getRussianWordsFromRussianEnglish(password, i + 1, passwords, "ת", newPassword);
      newPassword.append("י");
      break;

    case 'u':
      getRussianWordsFromRussianEnglish(password, i + 1, passwords, "‏", newPassword);
      getRussianWordsFromRussianEnglish(password, i + 1, passwords, "ü‏", newPassword);
      newPassword.append("ף");
      break;

    case 'i':
    case '!':
      if (i + 1 != password.end() && *(i + 1) == 'a')
      {
        getRussianWordsFromRussianEnglish(password, i + 2, passwords, "üÿ", newPassword);
        getRussianWordsFromRussianEnglish(password, i + 2, passwords, "טÿ", newPassword);
        newPassword.append("ÿ");
        i++;
        break;
      }

      getRussianWordsFromRussianEnglish(password, i + 1, passwords, "י", newPassword);
      newPassword.append("ט");
      break;

    case '1':
      if (i + 1 != password.end() && *(i + 1) == 'a')
      {
        getRussianWordsFromRussianEnglish(password, i + 2, passwords, "üÿ", newPassword);
        getRussianWordsFromRussianEnglish(password, i + 2, passwords, "טÿ", newPassword);
        newPassword.append("ÿ");
        i++;
        break;
      }

      getRussianWordsFromRussianEnglish(password, i + 1, passwords, "כ", newPassword);
      newPassword.append("ט");
      break;

    case 'o':
    case '0':
      newPassword.append("מ");
      break;

    case 'p':
      if (i + 1 != password.end() && *(i + 1) == 'h')
      {
        newPassword.append("פ");
        i++;
        break;
      }

      newPassword.append("ן");
      break;

    case 'a':
    case '@':
      newPassword.append("א");
      break;

    case 's':
    case '$':
      if (i + 1 != password.end() && *(i + 1) == 'h')
      {
        getRussianWordsFromRussianEnglish(password, i + 1, passwords, "ס", newPassword);
        getRussianWordsFromRussianEnglish(password, i + 2, passwords, "ר", newPassword);
        newPassword.append("ש");
        i++;
        break;
      }
      newPassword.append("ס");
      break;

    case 'd':
      newPassword.append("ה");
      break;

    case 'f':
      newPassword.append("פ");
      break;

    case 'g':
      newPassword.append("ד");
      break;

    case 'h':
      getRussianWordsFromRussianEnglish(password, i + 1, passwords, "ר", newPassword);
      newPassword.append("ץ");
      break;

    case 'j':
      if (i + 1 != password.end() && *(i + 1) == 'a')
      {
        getRussianWordsFromRussianEnglish(password, i + 2, passwords, "üÿ", newPassword);
        getRussianWordsFromRussianEnglish(password, i + 2, passwords, "טÿ", newPassword);
        getRussianWordsFromRussianEnglish(password, i + 1, passwords, "ז", newPassword);
        getRussianWordsFromRussianEnglish(password, i + 1, passwords, "הז", newPassword);
        newPassword.append("ÿ");
        i++;
        break;
      }

      if (i + 1 != password.end() && *(i + 1) == 'o')
      {
        getRussianWordsFromRussianEnglish(password, i + 2, passwords, "ימ", newPassword);
        getRussianWordsFromRussianEnglish(password, i + 2, passwords, "ü¸", newPassword);
        getRussianWordsFromRussianEnglish(password, i + 2, passwords, "ת¸", newPassword);
        getRussianWordsFromRussianEnglish(password, i + 1, passwords, "ז", newPassword);
        getRussianWordsFromRussianEnglish(password, i + 1, passwords, "הז", newPassword);
        newPassword.append("¸");
        i++;
        break;
      }

      if (i + 1 != password.end() && *(i + 1) == 'u')
      {
        getRussianWordsFromRussianEnglish(password, i + 2, passwords, "ü‏", newPassword);
        getRussianWordsFromRussianEnglish(password, i + 2, passwords, "ת‏", newPassword);
        getRussianWordsFromRussianEnglish(password, i + 1, passwords, "ז", newPassword);
        getRussianWordsFromRussianEnglish(password, i + 1, passwords, "הז", newPassword);
        newPassword.append("‏");
        i++;
        break;
      }

      if (i + 1 != password.end() && *(i + 1) == 'e')
      {
        getRussianWordsFromRussianEnglish(password, i + 2, passwords, "üו", newPassword);
        getRussianWordsFromRussianEnglish(password, i + 2, passwords, "תו", newPassword);
        getRussianWordsFromRussianEnglish(password, i + 2, passwords, "ü¸", newPassword);
        getRussianWordsFromRussianEnglish(password, i + 2, passwords, "ת¸", newPassword);
        getRussianWordsFromRussianEnglish(password, i + 1, passwords, "ז", newPassword);
        getRussianWordsFromRussianEnglish(password, i + 1, passwords, "הז", newPassword);
        newPassword.append("ו");
        i++;
        break;
      }

      getRussianWordsFromRussianEnglish(password, i + 1, passwords, "ü", newPassword);
      getRussianWordsFromRussianEnglish(password, i + 1, passwords, "ת", newPassword);
      getRussianWordsFromRussianEnglish(password, i + 1, passwords, "ז", newPassword);
      getRussianWordsFromRussianEnglish(password, i + 1, passwords, "י", newPassword);

      newPassword.append("הז");
      break;

    case 'k':
      newPassword.append("ך");
      break;

    case 'l':
      newPassword.append("כ");
      break;

    case 'z':
      newPassword.append("ח");
      break;

    case 'x':
      getRussianWordsFromRussianEnglish(password, i + 1, passwords, "ץ", newPassword);
      newPassword.append("ךס");
      break;

    case 'c':
      if (i + 1 != password.end() && *(i + 1) == 'h')
      {
        newPassword.append("ק");
        i++;
        break;
      }

      getRussianWordsFromRussianEnglish(password, i + 1, passwords, "ס", newPassword);
      newPassword.append("ך");
      break;

    case '4':
      newPassword.append("ק");
      break;

    case 'v':
      newPassword.append("ג");
      break;

    case 'b':
    case '6':
      newPassword.append("ב");
      break;

    case 'n':
      newPassword.append("ם");
      break;

    case 'm':
      newPassword.append("ל");
      break;

    default:
      break;
    }

    if (i == password.end())
      break;
  }

  passwords.push_back(newPassword);
}
//-----------------------------------------------------------------------------------------------------------------------------------------
std::string getRussianWordFromEnglishLetters(const std::string & password)
{
  setlocale(LC_ALL, "");
  std::string newPasssword;
  for (auto i : password)
  {
    switch (i)
    {
    case 'q':
      newPasssword.append("י");
      break;

    case 'w':
      newPasssword.append("צ");
      break;

    case 'e':
      newPasssword.append("ף");
      break;

    case 'r':
      newPasssword.append("ך");
      break;

    case 't':
      newPasssword.append("ו");
      break;

    case 'y':
      newPasssword.append("ם");
      break;

    case 'u':
      newPasssword.append("ד");
      break;

    case 'i':
      newPasssword.append("ר");
      break;

    case 'o':
      newPasssword.append("ש");
      break;

    case 'p':
    case '3':
      newPasssword.append("ח");
      break;

    case '[':
      newPasssword.append("ץ");
      break;

    case ']':
      newPasssword.append("ת");
      break;

    case 'a':
      newPasssword.append("פ");
      break;

    case 's':
      newPasssword.append("û");
      break;

    case 'd':
      newPasssword.append("ג");
      break;

    case 'f':
    case '@':
      newPasssword.append("א");
      break;

    case 'g':
      newPasssword.append("ן");
      break;

    case 'h':
      newPasssword.append("נ");
      break;

    case 'j':
    case '0':
      newPasssword.append("מ");
      break;

    case 'k':
      newPasssword.append("כ");
      break;

    case 'l':
      newPasssword.append("ה");
      break;

    case ';':
      newPasssword.append("ז");
      break;

    case '\'':
      newPasssword.append("‎");
      break;

    case 'z':
      newPasssword.append("ÿ");
      break;

    case 'x':
    case '4':
      newPasssword.append("ק");
      break;

    case 'c':
      newPasssword.append("ס");
      break;

    case 'v':
      newPasssword.append("ל");
      break;

    case 'b':
      newPasssword.append("ט");
      break;

    case 'n':
      newPasssword.append("ע");
      break;

    case 'm':
      newPasssword.append("ü");
      break;

    case ',':
      newPasssword.append("ב");
      break;

    case '.':
      newPasssword.append("‏");
      break;

    default:
      break;
    }
  }

  return newPasssword;
}
//-----------------------------------------------------------------------------------------------------------------------------------------
int analizePasswordByWords(const std::string & password)
{
  std::vector<std::pair<int, std::string>>  rawWords;
  getWordsFromPassword(password, rawWords);

  std::vector<std::string> wordsInPassword = determineWichWordsUsed(rawWords);
  if (wordsInPassword.size() >= 4)
    return 100;

  int lengthOfWords = 0;
  for (auto & i : wordsInPassword)
    lengthOfWords += i.length();
  int rating = static_cast<int>((float(lengthOfWords) / float(password.length())) * 100);
  if (rating > 100)
    rating = 100;
  rating = 100 - rating;

  switch (wordsInPassword.size())
  {
  case 3:
    rating += 50;
    break;

  case 2:
    rating += 25;
    break;

  default:
    break;
  }

  if (rating > 100)
    rating = 100;

  return rating;
}
//-----------------------------------------------------------------------------------------------------------------------------------------
int sumLengthOfWords(const std::vector<std::pair<int, std::string>> & words)
{
  int sum = 0;
  for (auto & i : words)
    sum += i.second.length();

  return sum;
}
//-----------------------------------------------------------------------------------------------------------------------------------------
bool getLowerCaseSet(const std::string_view & first3character, bool isRussian, const std::locale & loc, std::set<std::string> & data)
{
  data.clear();
  if (std::isdigit(first3character.front()))
    return false;

  std::string path;
  if (isRussian)
  {
    std::stringstream ss;
    ss << "dictionary\\" << char(std::toupper(first3character.front())) << ".txt";
    path = ss.str();
  }
  else
  {
    std::stringstream ss;
    ss << "dictionary_eng\\" << char(std::tolower(first3character.front())) << ".txt";
    path = ss.str();
  }

  std::string line;
  std::ifstream in(path);
  if (in.is_open())
  {
    while (getline(in, line))
    {
      if (boost::algorithm::istarts_with(line, first3character, loc))
        break;
    }

    if (in.eof())
      return false;

    do
    {
      boost::algorithm::to_lower(line, loc);
      if (isRussian)
        boost::algorithm::ireplace_all(line, "¸", "ו", loc);
      if (boost::algorithm::istarts_with(line, first3character, loc) == false)
        break;
      data.insert(line);
    } while (getline(in, line));
  }
  else
  {
    return false;
  }
  in.close();

  return true;
}
//-----------------------------------------------------------------------------------------------------------------------------------------
bool getWordFromSubPassword(const std::string & subPassword, const std::set<std::string> & data, std::string & word)
{
  word.clear();

  size_t pos = 3;


  for (;;)
  {
   auto subStr = subPassword.substr(0, pos++);
    auto it = data.equal_range(subStr);
  
    if (it.first != data.end() && *it.first == subStr)
      word = subStr;
  
    if (it.first == it.second && (it.second == data.end() || boost::algorithm::starts_with(*it.second, subStr) == false))
      break;
  
    if (subPassword.size() < pos)
      break;
  }

  //for (size_t pos=3; pos != subPassword.length(); ++pos)
  //{
  //  auto subStr= subPassword.substr(0, pos);
  //  if (data.contains(subStr))
  //    word.swap(subStr);
  //}


  if (word.empty())
    return false;
  return true;
}
//-----------------------------------------------------------------------------------------------------------------------------------------
void getWordsFromPasswordForParticularCase(const std::string & password, bool isRussian, std::vector<std::pair<int, std::string>> & words)
{
  if (password.length() < 3)
    return;

  setlocale(LC_ALL, "");
  std::locale loc;
  if (isRussian)
    loc = std::locale("russian");
  else
    loc = std::locale("english");

  std::string passwordCopy = boost::algorithm::to_lower_copy(password, loc);
  if (isRussian)
    boost::algorithm::ireplace_all(passwordCopy, "¸", "ו", loc);

  std::string_view passwordSW = passwordCopy;
  for (int pos = 0; pos < passwordCopy.size() - 2; pos++)
  {
    auto subWord = passwordSW.substr(pos);

    std::set<std::string> wordsForSearchingFrom;
    if (getLowerCaseSet(subWord.substr(0, 3), isRussian, loc, wordsForSearchingFrom) == false)
      continue;

    std::string resultWord;
    if (getWordFromSubPassword(std::string(subWord.begin(), subWord.end()), wordsForSearchingFrom, resultWord))
    {
      words.push_back(std::make_pair(pos, resultWord));
      pos += resultWord.length() - 1;
    }
  }
}
//-----------------------------------------------------------------------------------------------------------------------------------------
void getWordsFromPassword(const std::string & password, std::vector<std::pair<int, std::string>> & words)
{
  words.clear();

  std::string passwordCP = password;
  boost::algorithm::to_lower(passwordCP);

  getWordsFromPasswordForParticularCase(passwordCP, false, words);

  std::string passwordRus = getRussianWordFromEnglishLetters(passwordCP);
  getWordsFromPasswordForParticularCase(passwordRus, true, words);

  std::vector<std::pair<int, std::string>> buffer1, buffer2;
  std::vector<std::string> passwordsRus;
  getRussianWordsFromRussianEnglish(passwordCP, passwordCP.begin(), passwordsRus);
  for (auto & pass : passwordsRus)
  {
    buffer1.clear();
    getWordsFromPasswordForParticularCase(pass, true, buffer1);
    if (sumLengthOfWords(buffer1) > sumLengthOfWords(buffer2))
    {
      buffer2.swap(buffer1);
    }
  }
  words.insert(words.end(), buffer2.begin(), buffer2.end());
  std::sort(words.begin(), words.end(), [](const std::pair<int, std::string> & a, const std::pair<int, std::string> & b)
    {
      return a.second.length() > b.second.length();
    });
}
//-----------------------------------------------------------------------------------------------------------------------------------------
std::vector<std::string> determineWichWordsUsed(std::vector<std::pair<int, std::string>> & rawWords)
{
  if (rawWords.empty())
    return std::vector<std::string>();

  std::vector<std::string> words;
  std::vector<std::pair<int, std::string>> bufferWords;

  bufferWords.push_back(rawWords.front());
  rawWords.erase(rawWords.begin());
  for (auto & newWord : rawWords)
  {
    int flag = 0;
    for (auto & bufWord : bufferWords)
    {
      if (newWord.first >= bufWord.first && newWord.first < bufWord.first + bufWord.second.length() - 1
        || newWord.first + newWord.second.length() - 1 >= bufWord.first
        && newWord.first + newWord.second.length() - 1 < bufWord.first + bufWord.second.length() - 1)
        flag++;
    }
    if (flag == 0)
      bufferWords.push_back(newWord);
  }

  for (auto & i : bufferWords)
  {
    words.push_back(i.second);
  }

  return words;
}
int getAmountOfDistringSubstrings(std::string password)
{
  int n = (int)password.size();
  std::vector<int> prefix(1 + n);
  int sum = 0;
  int total = n * (n + 1) / 2;

  for (int ix = 0; ix < n; ix++)
  {
    prefix[1] = 0;
    int len = 0;
    int max = 0;
    int k = password.size();
    for (int i = 1; i < k; i++)
    {
      while (true)
      {
        if (password[i] == password[len])
        {
          len++;
          break;
        }
        if (len == 0)
        {
          break;
        }
        len = prefix[len];
      }
      prefix[i + 1] = len;
      //max = std::max(max, len);
      max = (max > len) ? max : len;
    }
    sum += (int)password.size() - max*2;
    password.erase(password.begin());
  }
  //std::cout << "Sum of distinct substrings of a given string: " << sum << std::endl;
  //std::cout << "Sum of all substrings of a given string: " << total << std::endl;
  return static_cast<int>((float)sum / (float)total * 100);
}
int getPossibleDates(std::string password)
{
  const std::regex gono1("19[3-9]{2}|20[0-1]\\d|19[A-Za-z]+[3-9]{2}|20[A-Za-z][0-1]\\d|"
    "[0-1][0-9]02|2[0-8]02|[0-2][0-9]0[^2]|[0-2][0-9]1[0-2]|300[^2]|310[13578]|"
    "311[02]|[0-1][0-9]02[3-9][0-9]|2[0-8]02[3-9][0-9]|[0-2][0-9]0[^2][3-9][0-9]|"
    "[0-2][0-9]1[0-2][3-9][0-9]|300[^2][3-9][0-9]|310[13578][3-9][0-9]|"
    "311[02][3-9][0-9][0-1][0-9]02[0-1][0-9]|2[0-8]02[0-1][0-9]|"
    "[0-2][0-9]0[^2][0-1][0-9]|[0-2][0-9]1[0-2][0-1][0-9]|300[^2][0-1][0-9]|"
    "310[13578][0-1][0-9]|311[02][0-1][0-9]|[0-1][0-9]0219[3-9][0-9]"
    "|2[0-8]0219[3-9][0-9]|[0-2][0-9]0[^2]19[3-9][0-9]|[0-2][0-9]1[0-2]19[3-9][0-9]|"
    "300[^2]19[3-9][0-9]|310[13578]19[3-9][0-9]|311[02]19[3-9][0-9]|"
    "[0-1][0-9]0220[0-1][0-9]|2[0-8]0220[0-1][0-9]|[0-2][0-9]0[^2]20[0-1][0-9]|"
    "[0-2][0-9]1[0-2]20[0-1][0-9]|300[^2]20[0-1][0-9]|310[13578]20[0-1][0-9]|311[02]20[0-1][0-9]");


  int len = password.length();
  if (std::regex_search(password, gono1))
  {
    auto newEnd = std::remove_if(password.begin(), password.end(), isdigit);
    password.erase(newEnd, password.end());
    return static_cast<int>(float(password.length()) / float(len) * 100);

  }
  else
    return 100;
}
//-----------------------------------------------------------------------------------------------------------------------------------------
