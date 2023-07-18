#include "Cache.hpp"

#include <iostream>


Cache::Cache(Cache&& other) noexcept :
    cacheMap(std::move(other.cacheMap)),
    accessList(std::move(other.accessList)),
    m_capacity(other.m_capacity)
{}


Cache& Cache::operator=(Cache&& other) noexcept {
    if (this != &other) {
        m_capacity = std::move(other.m_capacity);
        accessList = std::move(other.accessList);
        cacheMap = std::move(other.cacheMap);
    }
    return *this;
}

Cache::Cache() {
    m_capacity = 0;
}

Cache::Cache(std::vector<std::string> keys, std::vector<std::string> values, int cacheCapacity) {
	// cacheMap = unordered_map<std::string, list<std::pair<std::string,std::string>>::iterator>();
    // accessList = list<std::pair<std::string,std::string>>();
    m_capacity = cacheCapacity;
    if(keys.size() == values.size()){
    	for(int i=0;i<keys.size();++i) {
    		insertIntoCache(keys[i], values[i]);
    	}
    }
}

bool Cache::checkIfKeyExists(std::string key) {
    std::lock_guard<std::mutex> lock(m_mutex_);
	return cacheMap.find(key)!=cacheMap.end();
}


std::string Cache::getValue(std::string key){
    std::lock_guard<std::mutex> lock(m_mutex_);
	if (cacheMap.find(key)!=cacheMap.end()) return "";
    std::string val = cacheMap[key] -> second;
    accessList.erase(cacheMap[key]);
    accessList.push_front(make_pair(key,val));
    cacheMap[key] = accessList.begin();
    return val;
}

std::string Cache::getValueWithoutPositionChange(std::string key){
    std::lock_guard<std::mutex> lock(m_mutex_);
    if (cacheMap.find(key) == cacheMap.end()) return "";
    return cacheMap[key]->second;
}

void Cache::insertIntoCache(std::string key, std::string value) {
    std::lock_guard<std::mutex> lock(m_mutex_);
	if (cacheMap.count(key) == 0)
    {
        if (cacheMap.size() == m_capacity)
        {
            std::string keyToBeRemoved = accessList.back().first;
            accessList.pop_back();
            cacheMap.erase(keyToBeRemoved);
        }
    }
    else
    {
        accessList.erase(cacheMap[key]);
    }
    accessList.push_front(make_pair(key,value));
    cacheMap[key] = accessList.begin();
}


std::vector<std::string> Cache::evictLRElementFromCache() {
    // std::lock_guard<std::mutex> lock(m_mutex_);
    if(accessList.empty()) return {"", ""};
	std::string keyToBeRemoved = accessList.back().first;
	std::string ValueToBeRemoved = accessList.back().second;
	accessList.pop_back();
    cacheMap.erase(keyToBeRemoved);
    return {keyToBeRemoved, ValueToBeRemoved};

}


int Cache::size() {
    std::lock_guard<std::mutex> lock(m_mutex_);
	return cacheMap.size();
}

std::string Cache::getValueWithoutPositionChangeNew(std::string key, bool& isPresent) {
    std::lock_guard<std::mutex> lock(m_mutex_);
    if (cacheMap.find(key )== cacheMap.end()) {
        isPresent = false;
        return "";
    }
    isPresent = true;
    return cacheMap[key]->second;
}

std::mutex& Cache::getMutex() {
	return m_mutex_;
}

