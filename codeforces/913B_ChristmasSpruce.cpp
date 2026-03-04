/*
Problem:
Given a rooted tree (parent array representation), determine whether 
every non-leaf node has at least 3 leaf children.

Approach:
- Build adjacency list from parent array.
- Track leaf nodes using a boolean array.
- For each non-leaf node:
  Count how many of its direct children are leaves.
- If any non-leaf node has fewer than 3 leaf children -> answer = No.

Time Complexity: O(n)
  - Building tree: O(n)
  - Checking each node and its children: O(n)

Space Complexity: O(n)
  - Adjacency list + leaf tracking
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> vec(n);
  vec[0] = 0;

  for (int i = 1; i < vec.size(); i++) 
    cin >> vec[i];

  vector<vector<int>> adj(n + 1);
  vector<bool>isLeaf(n + 1, true);
  for (int i = 1; i < n; i++) {
    adj[vec[i]].push_back(i + 1);
    isLeaf[vec[i]] = false;
  }

  bool ans = true;
  for (int i = 1; i <= n; i++) {
    int parent = i;

    if (isLeaf[parent])
      continue;

    int leaves = 0;
    for (auto child : adj[parent]) {
      if (isLeaf[child])
        leaves++;
      if (leaves == 3)
        break;
    }
    
    if (leaves < 3) {
      ans = false;
      break;
    }
  }

  if (ans)
    cout << "Yes";
  else
    cout << "No";
  cout << endl;

  return 0;
}
