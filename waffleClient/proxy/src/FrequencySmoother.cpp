#include "FrequencySmoother.hpp"

#include <iostream>
#include <fstream>
bool freqCmp(std::pair<std::string, int> a, std::pair<std::string, int> b){ return (a.second == b.second ? a.first < b.first : a.second < b.second); }

FrequencySmoother::FrequencySmoother() : accessTree(freqCmp) {}

void FrequencySmoother::insert(std::string key) {
	if(accessFreqs.find(key)!=accessFreqs.end()) {
		return;
	}
	accessFreqs[key] = 0;
	accessTree.insert({key, 0});
}

int FrequencySmoother::getFrequency(std::string key) {
	return accessFreqs[key];
}

int FrequencySmoother::getMinFrequency() {
	return accessTree.begin()->second;
}

std::string FrequencySmoother::getKeyWithMinFrequency() {
	return accessTree.begin()->first;
}

void FrequencySmoother::incrementFrequency(std::string key) {
	accessTree.erase({key, accessFreqs[key]});
	accessFreqs[key]++;
	accessTree.insert({key, accessFreqs[key]});
}

int FrequencySmoother::size() {
	return accessFreqs.size();
}

void FrequencySmoother::printFreqs() {
	std::cout << "Printing frequencies ";
	for(auto& it: accessFreqs) {
		std::cout << "Key: " << it.first << " Value: " << it.second << " ";
	}
	std::cout << std::endl;
}