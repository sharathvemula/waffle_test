#ifndef FREQ_SMOOTHER_H
#define FREQ_SMOOTHER_H

#include <string>
#include <unordered_map>
#include <utility>
#include <set>

//#include "CloudDB.hpp"

bool freqCmp(std::pair<std::string, int> a, std::pair<std::string, int> b);

class FrequencySmoother {

private:
	std::set<std::pair<std::string, int>, decltype(&freqCmp)> accessTree;
	std::unordered_map<std::string, int> accessFreqs;

public:
	FrequencySmoother();
	void insert(std::string key);
	int getMinFrequency();
	void incrementFrequency(std::string key);
	std::string getKeyWithMinFrequency();
	int size();
	int getFrequency(std::string key);
	std::set<std::pair<std::string, int>, decltype(&freqCmp)>::iterator getIterator();

};

#endif