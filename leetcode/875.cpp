#include <vector>
#include <algorithm>
using namespace std;

// Approach Name: Binary Search on Answer
// Time complexity = O(n logn)
// Space complexity = O(1)

class Solution {
public:
  // sHelper function to check if Koko can finish all banana piles with eating speed = k within h hours
  bool canEat(int k, vector<int>& piles, int h) {
    long long time = 0;  // total hours required

    for (auto count : piles) {
      // number of hours needed for this pile
      time += count / k;

      // if bananas are not perfectly divisible by k,
      // one extra hour is needed to finish the remaining bananas
      if (count % k != 0)
        time++;
    }

    // return true if total time required is within allowed hours
    return time <= h;
  }

  int minEatingSpeed(vector<int>& piles, int h) {
    // Binary search on possible eating speed
    // minimum speed cannot be less than 1
    int left = 0;

    // maximum possible speed is the largest pile
    int right = *max_element(piles.begin(), piles.end());

    // continue until search space reduces to one answer
    while (right - left > 1) {
      // try the middle speed
      int mid = (right + left) / 2;

      // check if Koko can finish bananas with this speed
      if (canEat(mid, piles, h))
        right = mid; // if she can finish in speed x, she can finish in any speed > x, so try for speed < x
      else
        left = mid; // if she can not finish in speed x, she can not finish in any speed > x, so try for speed > x
    }

    // right will hold the minimum valid eating speed
    return right;
  }
};