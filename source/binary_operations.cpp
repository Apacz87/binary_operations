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
      unsigned bitState, oBitState, mask;
      bitState = t_value >> t_bit;
      bitState = ~bitState;
      bitState &= ~(~0 << 1);
      bitState <<= t_bit;
      oBitState = ~(~0 << 1);
      oBitState <<= t_bit;
      oBitState = ~oBitState;
      mask = t_value & oBitState;
      return bitState | mask;
   }
}
