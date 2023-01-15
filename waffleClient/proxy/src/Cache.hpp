#ifndef CACHE_H
#define CACHE_H

#include <string>
#include <vector>
#include <unordered_map>

struct cacheStruct {
	bool isDirty;
	std::string value;
	cacheStruct(): isDirty(false), value("") {}
	cacheStruct(std::string value, bool isDirty): isDirty(isDirty), value(value) {}
};

class Cache {

private:
	std::unordered_map<std::string, struct cacheStruct> cacheWaffle;
	int readHits;
	int reads;
	int writeHits;
	int writes;

public:
	Cache();
	int size();
	bool checkIfKeyExists(std::string key);
	bool checkIfKeyExistsInEvicted(std::string key);
	std::string getValue(std::string key);
	void markKeyDirty(std::string key);
	void unMarkKeyDirty(std::string key);
	bool checkIfKeyDirty(std::string key);
	void insertIntoCache(std::string key, std::string value, bool dirty);
	void insertIntoEvicted(std::string key, std::string value);
	void removeFromEvicted(std::string key);
	void evictCache();
	void removeFromCache(std::string key);
	void printStatistics();
	void printAll();
	std::unordered_map<std::string, std::string> evictedItems;
};

#endif