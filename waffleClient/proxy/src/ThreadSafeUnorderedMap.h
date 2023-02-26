#include <unordered_map>
#include <mutex>
#include <memory>

template<typename T>
class ThreadSafeUnorderedMap {
public:
    ThreadSafeUnorderedMap() = default;
    ThreadSafeUnorderedMap(const ThreadSafeUnorderedMap&) = delete;
    ThreadSafeUnorderedMap& operator=(const ThreadSafeUnorderedMap&) = delete;

    bool insertIfNotPresent(const std::string& key, const std::shared_ptr<T>& value = nullptr) {
        std::lock_guard<std::mutex> lock(m_mutex_);
        if(m_map_.find(key) == m_map_.end()) {
            m_map_[key].push_back(value);
            return false;
        }
        m_map_[key].push_back(value);
        return true;
    }

    bool isPresent(const std::string& key) const {
        std::lock_guard<std::mutex> lock(m_mutex_);
        auto iter = m_map_.find(key);
        if (iter != m_map_.end()) {
            return false;
        }
        return true;
    }

    void clearPromises(const std::string& key, const std::string& value) {
        std::lock_guard<std::mutex> lock(m_mutex_);
        for(auto& it: m_map_[key]) {
            if(it != NULL) {
                it->set_value(value);
            }
        }
        m_map_.erase(key);
    }

private:
    mutable std::mutex m_mutex_;
    std::unordered_map<std::string, std::vector<std::shared_ptr<T>>> m_map_;
};
