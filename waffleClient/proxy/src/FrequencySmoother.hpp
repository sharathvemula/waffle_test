#ifndef FREQ_SMOOTHER_H
#define FREQ_SMOOTHER_H

#include <string>
#include <unordered_map>
#include <utility>
#include <set>
#include <mutex>
#include <memory>


bool freqCmp(std::pair<std::string, int> a, std::pair<std::string, int> b);

class FrequencySmoother {

private:
	std::set<std::pair<std::string, int>, decltype(&freqCmp)> accessTree;
	std::unordered_map<std::string, int> accessFreqs;

public:
	FrequencySmoother(FrequencySmoother&& other) noexcept;
	FrequencySmoother& operator=(FrequencySmoother&& other) noexcept;
	FrequencySmoother();
	void insert(std::string key);
	int getMinFrequency();
	void incrementFrequency(std::string key);
	void setFrequency(std::string key, int value);
	std::string getKeyWithMinFrequency();
	int size();
	int getFrequency(std::string key);
	std::set<std::pair<std::string, int>, decltype(&freqCmp)>::iterator getIterator();
	std::mutex& getMutex();
	mutable std::mutex m_mutex_;

};

#endif