//
// Created by Lloyd Brown on 8/29/19.
//

#ifndef WAFFLE_OPERATION_H
#define WAFFLE_OPERATION_H

#include <string>

class operation {
public:
    operation(const operation&) = default;
    operation& operator=(const operation&){
        return *this;
    };
    operation() : key(), value(){
    }

    ~operation() = default;
    std::string key;
    std::string value;

    bool operator == (const operation & rhs) const
    {
        if (!(key == rhs.key))
            return false;
        if (!(value == rhs.value))
            return false;
        return true;
    }
    bool operator != (const operation &rhs) const {
        return !(*this == rhs);
    }
};

#endif //WAFFLE_OPERATION_H