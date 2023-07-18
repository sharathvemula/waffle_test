#ifndef WAFFLE_UTIL_H
#define WAFFLE_UTIL_H

#include <stdint.h>
#include <string>
#include <random>

uint32_t rand_uint32(const uint32_t &min, const uint32_t &max);

std::string rand_str(const int len);


#endif //WAFFLE_UTIL_H