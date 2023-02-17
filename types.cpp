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
      getRussianWordsFromRussianEnglish(password, i + 1, passwords, "ку", newPassword);
      newPassword.append("к");
      break;

    case 'w':
      getRussianWordsFromRussianEnglish(password, i + 1, passwords, "у", newPassword);
      newPassword.append("в");
      break;

    case 'e':
      getRussianWordsFromRussianEnglish(password, i + 1, passwords, "и", newPassword);
      getRussianWordsFromRussianEnglish(password, i + 1, passwords, "э", newPassword);
      newPassword.append("е");
      break;

    case '3':
      getRussianWordsFromRussianEnglish(password, i + 1, passwords, "и", newPassword);
      getRussianWordsFromRussianEnglish(password, i + 1, passwords, "э", newPassword);
      getRussianWordsFromRussianEnglish(password, i + 1, passwords, "з", newPassword);
      newPassword.append("е");
      break;

    case 'r':
      newPassword.append("р");
      break;

    case 't':
      newPassword.append("т");
      break;

    case 'y':
      if (i + 1 != password.end() && *(i + 1) == 'a')
      {
        getRussianWordsFromRussianEnglish(password, i + 2, passwords, "ья", newPassword);
        getRussianWordsFromRussianEnglish(password, i + 2, passwords, "ия", newPassword);
        newPassword.append("я");
        i++;
        break;
      }

      if (i + 1 != password.end() && *(i + 1) == 'e')
      {
        getRussianWordsFromRussianEnglish(password, i + 2, passwords, "ье", newPassword);
        getRussianWordsFromRussianEnglish(password, i + 2, passwords, "ие", newPassword);
        newPassword.append("е");
        newPassword.append("е");
        i++;
        break;
      }

      if (i + 1 != password.end() && *(i + 1) == 'o')
      {
        getRussianWordsFromRussianEnglish(password, i + 2, passwords, "йо", newPassword);
        getRussianWordsFromRussianEnglish(password, i + 2, passwords, "ьё", newPassword);
        getRussianWordsFromRussianEnglish(password, i + 2, passwords, "ъё", newPassword);
        newPassword.append("ё");
        i++;
        break;
      }

      getRussianWordsFromRussianEnglish(password, i + 1, passwords, "ы", newPassword);
      getRussianWordsFromRussianEnglish(password, i + 1, passwords, "и", newPassword);
      getRussianWordsFromRussianEnglish(password, i + 1, passwords, "ь", newPassword);
      getRussianWordsFromRussianEnglish(password, i + 1, passwords, "ъ", newPassword);
      newPassword.append("й");
      break;

    case 'u':
      getRussianWordsFromRussianEnglish(password, i + 1, passwords, "ю", newPassword);
      getRussianWordsFromRussianEnglish(password, i + 1, passwords, "ью", newPassword);
      newPassword.append("у");
      break;

    case 'i':
    case '!':
      if (i + 1 != password.end() && *(i + 1) == 'a')
      {
        getRussianWordsFromRussianEnglish(password, i + 2, passwords, "ья", newPassword);
        getRussianWordsFromRussianEnglish(password, i + 2, passwords, "ия", newPassword);
        newPassword.append("я");
        i++;
        break;
      }

      getRussianWordsFromRussianEnglish(password, i + 1, passwords, "й", newPassword);
      newPassword.append("и");
      break;

    case '1':
      if (i + 1 != password.end() && *(i + 1) == 'a')
      {
        getRussianWordsFromRussianEnglish(password, i + 2, passwords, "ья", newPassword);
        getRussianWordsFromRussianEnglish(password, i + 2, passwords, "ия", newPassword);
        newPassword.append("я");
        i++;
        break;
      }

      getRussianWordsFromRussianEnglish(password, i + 1, passwords, "л", newPassword);
      newPassword.append("и");
      break;

    case 'o':
    case '0':
      newPassword.append("о");
      break;

    case 'p':
      if (i + 1 != password.end() && *(i + 1) == 'h')
      {
        newPassword.append("ф");
        i++;
        break;
      }

      newPassword.append("п");
      break;

    case 'a':
    case '@':
      newPassword.append("а");
      break;

    case 's':
    case '$':
      if (i + 1 != password.end() && *(i + 1) == 'h')
      {
        getRussianWordsFromRussianEnglish(password, i + 1, passwords, "с", newPassword);
        getRussianWordsFromRussianEnglish(password, i + 2, passwords, "ш", newPassword);
        newPassword.append("щ");
        i++;
        break;
      }
      newPassword.append("с");
      break;

    case 'd':
      newPassword.append("д");
      break;

    case 'f':
      newPassword.append("ф");
      break;

    case 'g':
      newPassword.append("г");
      break;

    case 'h':
      getRussianWordsFromRussianEnglish(password, i + 1, passwords, "ш", newPassword);
      newPassword.append("х");
      break;

    case 'j':
      if (i + 1 != password.end() && *(i + 1) == 'a')
      {
        getRussianWordsFromRussianEnglish(password, i + 2, passwords, "ья", newPassword);
        getRussianWordsFromRussianEnglish(password, i + 2, passwords, "ия", newPassword);
        getRussianWordsFromRussianEnglish(password, i + 1, passwords, "ж", newPassword);
        getRussianWordsFromRussianEnglish(password, i + 1, passwords, "дж", newPassword);
        newPassword.append("я");
        i++;
        break;
      }

      if (i + 1 != password.end() && *(i + 1) == 'o')
      {
        getRussianWordsFromRussianEnglish(password, i + 2, passwords, "йо", newPassword);
        getRussianWordsFromRussianEnglish(password, i + 2, passwords, "ьё", newPassword);
        getRussianWordsFromRussianEnglish(password, i + 2, passwords, "ъё", newPassword);
        getRussianWordsFromRussianEnglish(password, i + 1, passwords, "ж", newPassword);
        getRussianWordsFromRussianEnglish(password, i + 1, passwords, "дж", newPassword);
        newPassword.append("ё");
        i++;
        break;
      }

      if (i + 1 != password.end() && *(i + 1) == 'u')
      {
        getRussianWordsFromRussianEnglish(password, i + 2, passwords, "ью", newPassword);
        getRussianWordsFromRussianEnglish(password, i + 2, passwords, "ъю", newPassword);
        getRussianWordsFromRussianEnglish(password, i + 1, passwords, "ж", newPassword);
        getRussianWordsFromRussianEnglish(password, i + 1, passwords, "дж", newPassword);
        newPassword.append("ю");
        i++;
        break;
      }

      if (i + 1 != password.end() && *(i + 1) == 'e')
      {
        getRussianWordsFromRussianEnglish(password, i + 2, passwords, "ье", newPassword);
        getRussianWordsFromRussianEnglish(password, i + 2, passwords, "ъе", newPassword);
        getRussianWordsFromRussianEnglish(password, i + 2, passwords, "ьё", newPassword);
        getRussianWordsFromRussianEnglish(password, i + 2, passwords, "ъё", newPassword);
        getRussianWordsFromRussianEnglish(password, i + 1, passwords, "ж", newPassword);
        getRussianWordsFromRussianEnglish(password, i + 1, passwords, "дж", newPassword);
        newPassword.append("е");
        i++;
        break;
      }

      getRussianWordsFromRussianEnglish(password, i + 1, passwords, "ь", newPassword);
      getRussianWordsFromRussianEnglish(password, i + 1, passwords, "ъ", newPassword);
      getRussianWordsFromRussianEnglish(password, i + 1, passwords, "ж", newPassword);
      getRussianWordsFromRussianEnglish(password, i + 1, passwords, "й", newPassword);

      newPassword.append("дж");
      break;

    case 'k':
      newPassword.append("к");
      break;

    case 'l':
      newPassword.append("л");
      break;

    case 'z':
      newPassword.append("з");
      break;

    case 'x':
      getRussianWordsFromRussianEnglish(password, i + 1, passwords, "х", newPassword);
      newPassword.append("кс");
      break;

    case 'c':
      if (i + 1 != password.end() && *(i + 1) == 'h')
      {
        newPassword.append("ч");
        i++;
        break;
      }

      getRussianWordsFromRussianEnglish(password, i + 1, passwords, "с", newPassword);
      newPassword.append("к");
      break;

    case '4':
      newPassword.append("ч");
      break;

    case 'v':
      newPassword.append("в");
      break;

    case 'b':
    case '6':
      newPassword.append("б");
      break;

    case 'n':
      newPassword.append("н");
      break;

    case 'm':
      newPassword.append("м");
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
      newPasssword.append("й");
      break;

    case 'w':
      newPasssword.append("ц");
      break;

    case 'e':
      newPasssword.append("у");
      break;

    case 'r':
      newPasssword.append("к");
      break;

    case 't':
      newPasssword.append("е");
      break;

    case 'y':
      newPasssword.append("н");
      break;

    case 'u':
      newPasssword.append("г");
      break;

    case 'i':
      newPasssword.append("ш");
      break;

    case 'o':
      newPasssword.append("щ");
      break;

    case 'p':
    case '3':
      newPasssword.append("з");
      break;

    case '[':
      newPasssword.append("х");
      break;

    case ']':
      newPasssword.append("ъ");
      break;

    case 'a':
      newPasssword.append("ф");
      break;

    case 's':
      newPasssword.append("ы");
      break;

    case 'd':
      newPasssword.append("в");
      break;

    case 'f':
    case '@':
      newPasssword.append("а");
      break;

    case 'g':
      newPasssword.append("п");
      break;

    case 'h':
      newPasssword.append("р");
      break;

    case 'j':
    case '0':
      newPasssword.append("о");
      break;

    case 'k':
      newPasssword.append("л");
      break;

    case 'l':
      newPasssword.append("д");
      break;

    case ';':
      newPasssword.append("ж");
      break;

    case '\'':
      newPasssword.append("э");
      break;

    case 'z':
      newPasssword.append("я");
      break;

    case 'x':
    case '4':
      newPasssword.append("ч");
      break;

    case 'c':
      newPasssword.append("с");
      break;

    case 'v':
      newPasssword.append("м");
      break;

    case 'b':
      newPasssword.append("и");
      break;

    case 'n':
      newPasssword.append("т");
      break;

    case 'm':
      newPasssword.append("ь");
      break;

    case ',':
      newPasssword.append("б");
      break;

    case '.':
      newPasssword.append("ю");
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
        boost::algorithm::ireplace_all(line, "ё", "е", loc);
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
    boost::algorithm::ireplace_all(passwordCopy, "ё", "е", loc);

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
