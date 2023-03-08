#ifndef CACHE_H
#define CACHE_H

#include <string>
#include <vector>
#include <unordered_map>
#include <list>
#include <utility>
#include <mutex>
#include <memory>


class Cache {

private:
	std::unordered_map<std::string, std::list<std::pair<std::string,std::string>>::iterator> cacheMap;
    std::list<std::pair<std::string,std::string>> accessList;
    int m_capacity;
	mutable std::mutex m_mutex_;


public:
	Cache(Cache&& other) noexcept;
	Cache& operator=(Cache&& other) noexcept;
	Cache();
	Cache(std::vector<std::string> keys, std::vector<std::string> values, int cacheCapacity);
	int size();
	bool checkIfKeyExists(std::string key);
	std::string getValue(std::string key);
	std::string getValueWithoutPositionChange(std::string key);
	void insertIntoCache(std::string key, std::string value);
	std::vector<std::string> evictLRElementFromCache();
	std::string getValueWithoutPositionChangeNew(std::string key, bool& isPresent);
	std::mutex& getMutex();
};

#endif