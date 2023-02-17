#include <iostream>
#include <string>
#include <vector>
#include <io.h>
#include <fcntl.h>
#include <unordered_map>
#include "keymapgraph.h"
#include "keyboarddispersion.h"

const std::vector<std::string> rusLower = { R"( 1234567890-=)",
											R"(            \)",
											R"(           )",
											R"(         .)" };

const std::vector<std::string> rusUpper = { R"x( !"№;%:?*()_+)x",
											 R"(            /)",
											 R"(           )",
											 R"(         ,)" };

const std::vector<std::string> engLower = { R"(`1234567890-=)",
											 R"(qwertyuiop[]\)",
											 R"(asdfghjkl;')",
											 R"(zxcvbnm,./)" };

const std::vector<std::string> engUpper = { R"x(~!@#$%^&*()_+)x",
											 R"(QWERTYUIOP{}|)",
											 R"(ASDFGHJKL:")",
											 R"(ZXCVBNM<>?)" };


void addSymbolsToHashTable(const std::vector<std::string>& keyboard, 
						   std::unordered_multimap<char, symbolPos>& hshtbl) 
{
	for (int i = 0; i < keyboard.size(); i++)
	{
		for (int j = 0; j < keyboard[i].length(); j++)
		{
			hshtbl.emplace(keyboard[i][j], symbolPos{ keyboard, i, j });
		}
	}
}

int minimalDistanseBetweenSymbols(char ch1, char ch2, 
								  const std::unordered_multimap<char, symbolPos> &symbolPositions)
{
	auto _1begEnd = symbolPositions.equal_range(ch1);
	auto _2begEnd = symbolPositions.equal_range(ch2);
	
	int minDistanse = INT_MAX;

	for (auto iiter = _1begEnd.first; iiter != _1begEnd.second; iiter++)
	{
		for (auto jiter = _2begEnd.first; jiter != _2begEnd.second; jiter++)
		{
			int tempDist = ((iiter->second.linePos - jiter->second.linePos) * 3) *
				((iiter->second.linePos - jiter->second.linePos) * 3) +
				(iiter->second.columnPos - jiter->second.columnPos) *
				(iiter->second.columnPos - jiter->second.columnPos);

			if (tempDist < minDistanse)
				minDistanse = tempDist;
		}
	}

	return minDistanse;
}


double scoreOfKeysAccuracy(std::string passStr) {
	std::unordered_multimap<char, symbolPos> symbolPositions;

	addSymbolsToHashTable(rusLower, symbolPositions);
	addSymbolsToHashTable(rusUpper, symbolPositions);
	addSymbolsToHashTable(engLower, symbolPositions);
	addSymbolsToHashTable(engUpper, symbolPositions);

	std::vector<std::vector<int>> keysMutualDistance;
	int passwordLength = passStr.length();

	keysMutualDistance.resize(passwordLength);

	for (int i = 0; i < passwordLength; i++) {
		keysMutualDistance[i].assign(passwordLength, INT_MAX);
	}

	for (int i = 0; i < passwordLength; i++)
	{
		for (int j = 0; j < passwordLength; j++)
		{
			if (i != j)
				keysMutualDistance[i][j] = minimalDistanseBetweenSymbols(passStr[i], passStr[j], symbolPositions);
		}
	}

	double sumDist = 0.0;

	for (int i = 0; i < passwordLength; i++)
	{
		for (int j = 0; j < passwordLength; j++)
		{
			if (i != j)
				sumDist += sqrt(static_cast<double>(keysMutualDistance[i][j]));
		}
	}

	double avgDist = sumDist / (passwordLength * passwordLength - passwordLength);

	double halfOfKeyboardMetric = sqrt((12 / 2) * (12 / 2) + (12 / 2) * (12 / 2));

	double allKeysInPsswdMetric = 6.23472;

	double resultScore = std::min((avgDist) / (halfOfKeyboardMetric) * 100, 100.0);

	return resultScore;
}

int keyboardDispersionScore(const std::string &pass) {

	std::string passStr = pass;
	Keymap_graph test = Keymap_graph(passStr);
	double joining_score = test.keys_sequentially_arrangement_score();
	
	

	//std::cout << "Score of number of sequences in password:           " << joining_score << 
	//	       "\nScore of average remoteness of symbols in password: " << distant_score <<
	//	       "\n---------------------\nSummary score of keyboard dispersion block: " << block_score << '\n';
	
	return static_cast<int>(joining_score);
}

//int main(int argc, char* argv[])
//{
//	std::string passStr;
//
//	std::cin >> passStr;
//
//	std::cout<<keyboardDispersionScore(passStr);
//}