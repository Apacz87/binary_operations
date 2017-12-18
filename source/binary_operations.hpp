#ifndef BINARY_OPERATIONS_H_INCLUDED
#define BINARY_OPERATIONS_H_INCLUDED

#include <cstdint>

namespace bopr
{
   uint32_t setbiton(const uint32_t& t_value, const uint8_t& t_bit);
   uint32_t setbitoff(const uint32_t& t_value, const uint8_t& t_bit);
   uint32_t invertbit(const uint32_t& t_value, const uint8_t& t_bit);
   uint32_t invertbits(const uint32_t& t_value, const uint8_t& t_last, const uint8_t& t_count);
   bool bitstate(const uint32_t& t_value, const uint8_t& t_bit);
}

#endif
