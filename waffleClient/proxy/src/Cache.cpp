#include "Cache.hpp"

#include <iostream>

Cache::Cache() {
	readHits = 0;
	reads = 0;
	writeHits = 0;
	writes = 0;
	cacheWaffle = std::unordered_map<std::string, struct cacheStruct>();
	evictedItems = std::unordered_map<std::string, std::string>();
}

bool Cache::checkIfKeyExists(std::string key) {
	return cacheWaffle.find(key)!=cacheWaffle.end();
}


void Cache::insertIntoEvicted(std::string key, std::string value) {
	evictedItems[key] = value;
}

void Cache::removeFromEvicted(std::string key) {
	evictedItems.erase(key);
}

bool Cache::checkIfKeyExistsInEvicted(std::string key) {
	return evictedItems.find(key)!=evictedItems.end();
}

std::string Cache::getValue(std::string key){
	if(checkIfKeyExists(key) == true) {
		return cacheWaffle[key].value;
	}
	return "";
}

void Cache::markKeyDirty(std::string key) {
	if(checkIfKeyExists(key) == true) {
		cacheWaffle[key].isDirty = true;
	}
}

void Cache::unMarkKeyDirty(std::string key) {
	if(checkIfKeyExists(key) == true) {
		cacheWaffle[key].isDirty = false;
	}
}

bool Cache::checkIfKeyDirty(std::string key) {
	if(checkIfKeyExists(key) == true) {
		return cacheWaffle[key].isDirty;
	}
	return false;
}

void Cache::insertIntoCache(std::string key, std::string value, bool isDirty) {
	cacheWaffle.insert({key, cacheStruct(value, isDirty)});
}

void Cache::evictCache() {
	auto it = cacheWaffle.begin();
	while(it != cacheWaffle.end()) {
		// std::cout << "flag is " << it->second.isDirty << std::endl;
		if(!it->second.isDirty) {
			//evictedItems[it.first] = it.second.value;
			it = cacheWaffle.erase(it);
		} else {
			++it;
		}
		// } else {
		// 	cacheWaffle.erase(it.first);
		// }
	}
	//cacheWaffle.clear();
}

void Cache::removeFromCache(std::string key){
	if(checkIfKeyExists(key) == true) {
		cacheWaffle.erase(key);
	}
}

void Cache::printAll() {
	std::cout << "Current cache is : ";
	for(auto& it: cacheWaffle){
		std::cout << it.first << " " << std::endl;
	}
	//std::cout << std::endl;
}

int Cache::size() {
	return cacheWaffle.size()+evictedItems.size();
}

void Cache::printStatistics() {
	printf("Records in Cache: %lu\n", cacheWaffle.size());

	printf("Read Hits: %d\n", readHits);
	printf("Read Total: %d\n", reads);
	printf("Read Hit Ratio: %.4f\n", readHits / (float)reads);

	printf("Write Hits: %d\n", writeHits);
	printf("Write Total: %d\n", writes);
	printf("Write Hit Ratio: %.4f\n", writeHits / (float)writes);

	printf("Hits: %d\n", writeHits + readHits);
	printf("Total: %d\n", writes + reads);
	printf("Hit Ratio: %.4f\n", (writeHits + readHits) / (float)(writes + reads));
}