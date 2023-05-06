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

void FrequencySmoother::setFrequency(std::string key, int value) {
	accessTree.erase({key, accessFreqs[key]});
	accessFreqs[key] = value;
	accessTree.insert({key, accessFreqs[key]});
}

int FrequencySmoother::getFrequency(std::string key) {
	return accessFreqs[key];
}

int FrequencySmoother::size() {
	return accessFreqs.size();
}

std::set<std::pair<std::string, int>, decltype(&freqCmp)>::iterator FrequencySmoother::getIterator() {
	return accessTree.begin();
}

int FrequencySmoother::getMaxFrequency() {
	return std::prev(accessTree.end())->second;
}

void FrequencySmoother::resetFrequency(int value) {
	for (auto& it: accessFreqs) {
    	accessTree.erase({it.first, accessFreqs[it.first]});
		accessFreqs[it.first] = value;
		accessTree.insert({it.first, accessFreqs[it.first]});
	} 
}
