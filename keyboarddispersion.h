#ifndef KEYBOARDDISPERSION_H
#define KEYBOARDDISPERSION_H



struct symbolPos
{
	const std::vector<std::string>& keyboard;
	int linePos;
	int columnPos;
};

void addSymbolsToHashTable(const std::vector<std::string>&,	std::unordered_multimap<char, symbolPos>&);

int minimalDistanseBetweenSymbols(char, char, const std::unordered_multimap<char, symbolPos>&);

double scoreOfKeysAccuracy(std::string);

int keyboardDispersionScore(const std::string&);

#endif //KEYBOARDDISPERSION_H
