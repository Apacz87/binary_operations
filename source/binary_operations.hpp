#ifndef BINARY_OPERATIONS_H_INCLUDED
#define BINARY_OPERATIONS_H_INCLUDED

namespace bopr
{
   unsigned setbiton(const unsigned& t_value, const int& t_bit);
   unsigned setbitoff(const unsigned& t_value, const int& t_bit);
   unsigned invertbit(const unsigned& t_value, const int& t_bit);
   unsigned invertbits(const unsigned& t_value, const int& t_last, const int& t_first);
   bool bitstate(const unsigned& t_value, const int& t_bit);
}

#endif
