#include "evictedItems.h"

#include <iostream>


evictedItems::evictedItems(evictedItems&& other) noexcept :
    cacheMap(std::move(other.cacheMap)),
    m_capacity(other.m_capacity)
{}


evictedItems& evictedItems::operator=(evictedItems&& other) noexcept {
    if (this != &other) {
        m_capacity = std::move(other.m_capacity);
        cacheMap = std::move(other.cacheMap);
    }
    return *this;
}

evictedItems::evictedItems() {
    m_capacity = 0;
}

evictedItems::evictedItems(int cacheCapacity) {
    m_capacity = cacheCapacity;
}

std::string evictedItems::getValue(std::string key){
    std::lock_guard<std::mutex> lock(m_mutex_);
    if (cacheMap.find(key) == cacheMap.end()) return "";
    return cacheMap[key];
}

void evictedItems::insert(std::string key, std::string value) {
    // std::lock_guard<std::mutex> lock(m_mutex_);
    cacheMap[key] = value;
}

void evictedItems::erase(std::string key) {
    std::lock_guard<std::mutex> lock(m_mutex_);
    cacheMap.erase(key);
}

int evictedItems::size() {
    std::lock_guard<std::mutex> lock(m_mutex_);
    return cacheMap.size();
}

bool evictedItems::checkIfKeyExists(std::string key) {
    std::lock_guard<std::mutex> lock(m_mutex_);
    if(cacheMap.find(key) == cacheMap.end()) {
        return false;
    }
    return true;
}

std::mutex& evictedItems::getMutex() {
	return m_mutex_;
}


