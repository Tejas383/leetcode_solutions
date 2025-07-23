#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int I, J;
        bool found = false;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] == 'R') {
                    I = i;
                    J = j;
                    goto found;
                }
            }
        }

        found:
        int count = 0;
        for (int i = I - 1; i >= 0; i--) {
            if (board[i][J] != '.') {
                if (board[i][J] == 'p') 
                    count++;
                break;
            }
        }
        for (int i = I + 1; i < 8; i++) {
            if (board[i][J] != '.') {
                if (board[i][J] == 'p') 
                    count++;
                break;
            }
        }

        for (int j = J - 1; j >= 0; j--) {
            if (board[I][j] != '.') {
                if (board[I][j] == 'p') 
                    count++;
                break;
            }
        }
        for (int j = J + 1; j < 8; j++) {
            if (board[I][j] != '.') {
                if (board[I][j] == 'p') 
                    count++;
                break;
            }
        }

        return count;
    }
};