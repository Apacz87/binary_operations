namespace bopr
{
   unsigned setbiton(const unsigned& t_value, const int& t_bit)
   {
      unsigned mask;
      mask = 1 << t_bit;
      return t_value | mask;
   }

   unsigned setbitoff(const unsigned& t_value, const int& t_bit)
   {
      unsigned mask;
      mask = 1 << t_bit;
      return t_value & ~mask;
   }

   unsigned invertbit(const unsigned& t_value, const int& t_bit)
   {
      unsigned mask;
      mask = 1 << t_bit;
      return t_value ^ mask;
   }

   unsigned invertbits(const unsigned& t_value, const int& t_last, const int& t_count)
   {
      unsigned bitsState, opposedBitState, mask;
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

   bool bitstate(const unsigned& t_value, const int& t_bit)
   {
      return ((t_value >> t_bit) & 1) != 0;
   }
}
