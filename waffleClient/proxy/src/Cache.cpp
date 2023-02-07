#include "Cache.hpp"

#include <iostream>

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
	return cacheMap.find(key)!=cacheMap.end();
}


std::string Cache::getValue(std::string key){
	if (checkIfKeyExists(key) == false) return "";
    std::string val = cacheMap[key] -> second;
    accessList.erase(cacheMap[key]);
    accessList.push_front(make_pair(key,val));
    cacheMap[key] = accessList.begin();
    return val;
}

void Cache::insertIntoCache(std::string key, std::string value) {
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
	std::string keyToBeRemoved = accessList.back().first;
	std::string ValueToBeRemoved = accessList.back().second;
	accessList.pop_back();
    cacheMap.erase(keyToBeRemoved);
    return {keyToBeRemoved, ValueToBeRemoved};

}


int Cache::size() {
	return cacheMap.size();
}
