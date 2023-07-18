#ifndef EVICTED_ITEMS_H
#define EVICTED_ITEMS_H

#include <string>
#include <vector>
#include <unordered_map>
#include <list>
#include <utility>
#include <mutex>
#include <memory>


class evictedItems {

private:
	std::unordered_map<std::string, std::string> cacheMap;
    int m_capacity;
	mutable std::mutex m_mutex_;

public:
	evictedItems(evictedItems&& other) noexcept;
	evictedItems& operator=(evictedItems&& other) noexcept;
	evictedItems(int capacity);
    evictedItems();
	std::string getValue(std::string key);
	void insert(std::string key, std::string value);
	void erase(std::string key);
    int size();
    bool checkIfKeyExists(std::string);
    std::mutex& getMutex();
};

#endif