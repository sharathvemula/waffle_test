#include "FrequencySmoother.hpp"

#include <iostream>
#include <fstream>

bool freqCmp(std::pair<std::string, int> a, std::pair<std::string, int> b){ return (a.second == b.second ? a.first < b.first : a.second < b.second); }

FrequencySmoother::FrequencySmoother(FrequencySmoother&& other) noexcept :
    accessTree(std::move(other.accessTree)),
    accessFreqs(std::move(other.accessFreqs))
{}


FrequencySmoother& FrequencySmoother::operator=(FrequencySmoother&& other) noexcept {
    if (this != &other) {
        accessTree = std::move(other.accessTree);
        accessFreqs = std::move(other.accessFreqs);
    }
    return *this;
}

FrequencySmoother::FrequencySmoother() : accessTree(freqCmp) {}

void FrequencySmoother::insert(std::string key) {
	std::lock_guard<std::mutex> lock(m_mutex_);
	if(accessFreqs.find(key)!=accessFreqs.end()) {
		return;
	}
	accessFreqs[key] = 0;
	accessTree.insert({key, 0});
}


int FrequencySmoother::getMinFrequency() {
	std::lock_guard<std::mutex> lock(m_mutex_);
	return accessTree.begin()->second;
}

std::string FrequencySmoother::getKeyWithMinFrequency() {
	std::lock_guard<std::mutex> lock(m_mutex_);
	return accessTree.begin()->first;
}

void FrequencySmoother::incrementFrequency(std::string key) {
	std::lock_guard<std::mutex> lock(m_mutex_);
	accessTree.erase({key, accessFreqs[key]});
	accessFreqs[key]++;
	accessTree.insert({key, accessFreqs[key]});
}

int FrequencySmoother::getFrequency(std::string key) {
	std::lock_guard<std::mutex> lock(m_mutex_);
	return accessFreqs[key];
}

int FrequencySmoother::size() {
	std::lock_guard<std::mutex> lock(m_mutex_);
	return accessFreqs.size();
}

std::set<std::pair<std::string, int>, decltype(&freqCmp)>::iterator FrequencySmoother::getIterator() {
	// std::lock_guard<std::mutex> lock(m_mutex_);
	return accessTree.begin();
}

std::mutex& FrequencySmoother::getMutex() {
	return m_mutex_;
}

// template<typename Func>
//     void iterateAccessTree(Func func) {
//         std::lock_guard<std::mutex> lock(m_mutex_);
//         func(it);
//     }

// void FrequencySmoother::printFreqs() {
// 	std::cout << "Printing frequencies ";
// 	for(auto& it: accessFreqs) {
// 		std::cout << "Key: " << it.first << " Value: " << it.second << " ";
// 	}
// 	std::cout << std::endl;
// }