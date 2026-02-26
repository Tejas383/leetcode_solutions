#include <string>
using namespace std;

class Solution {
public:
    void divideByTwo(string& s) {
        s.pop_back();
    }

    void addOne(string& s) {
        int i = s.size() - 1;

        while (i >= 0 && s[i] == '1') {
            s[i] = '0';
            i--;
        }

        if (i < 0) 
            s = '1' + s;
        else
            s[i] = '1';
    }

    int numSteps(string s) {
        int steps = 0;

        while (s.size() > 1) {
            if (s[s.size() - 1] == '0')
                divideByTwo(s);
            else
                addOne(s);

            steps++;
        }

        return steps;
    }
};