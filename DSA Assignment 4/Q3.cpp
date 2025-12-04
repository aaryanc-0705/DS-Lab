#include <iostream>
#include <queue>
using namespace std;

const int MAX_CHAR = 26;

void firstNonRepeating(string str) {
    int charCount[MAX_CHAR] = {0};
    queue<char> q;

    for (char ch : str) {
        charCount[ch - 'a']++;
        
        q.push(ch);

        while (!q.empty() && charCount[q.front() - 'a'] > 1) {
            q.pop();
        }

        if (!q.empty()) {
            cout << q.front() << " ";
        } else {
            cout << -1 << " ";
        }
    }
    cout << endl;
}

int main() {
    string input = "ababc";
    firstNonRepeating(input); 
    return 0;
}
