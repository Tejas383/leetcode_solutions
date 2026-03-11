// Approach Name: Bit-Length Mask Complement
// Time complexity = O(log n)
// Space complexity = O(1)

class Solution {
public:
  int bitwiseComplement(int n) {
    if (n == 0)
      return 1;
    
    int bits = 0;
    int temp = n;
    // count the number of bits in n
    while (temp) {
      bits++;
      temp = temp >> 1;
    }
    // binary number + its complimentary = all ones (upto 'bits' bits)
    // => all ones (upto 'bits' bits) - n = ans
    int ones = (1 << bits) - 1;
    return (ones - n);
  }
};