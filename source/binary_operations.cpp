#include "binary_operations.hpp"

namespace bopr
{
   uint32_t setbiton(const uint32_t& t_value, const uint8_t& t_bit)
   {
      uint32_t mask = 1 << t_bit;
      return t_value | mask;
   }

   uint32_t setbitoff(const uint32_t& t_value, const uint8_t& t_bit)
   {
      uint32_t mask = 1 << t_bit;
      return t_value & ~mask;
   }

   uint32_t invertbit(const uint32_t& t_value, const uint8_t& t_bit)
   {
      uint32_t mask = 1 << t_bit;
      return t_value ^ mask;
   }

   uint32_t invertbits(const uint32_t& t_value, const uint8_t& t_last, const uint8_t& t_count)
   {
      uint32_t bitsState, opposedBitState, mask;
      bitsState = t_value >> t_last + 1 - t_count;
      bitsState = ~bitsState;
      bitsState &= ~(~0 << t_count);
      bitsState <<= t_last + 1 - t_count;
      opposedBitState = ~(~0 << t_count);
      opposedBitState <<= t_last + 1 - t_count;
      opposedBitState = ~opposedBitState;
      mask = t_value & opposedBitState;
      return bitsState | mask;
   }

   bool bitstate(const uint32_t& t_value, const uint8_t& t_bit)
   {
      return ((t_value >> t_bit) & 1) != 0;
   }
}
