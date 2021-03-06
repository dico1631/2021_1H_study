#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int>s(n);

    for (int i = 0;i < lost.size();i++) {
        s[lost[i] - 1]--;
    }

    for (int i = 0;i < reserve.size();i++) {
        s[reserve[i] - 1]++;
    }

    for (int i = 0;i < s.size();i++) {
        if (s[i] == 1) {
            if (i != 0 && s[i - 1] == -1) {
                s[i]--;
                s[i - 1]++;
            }

            else if (i != s.size() && s[i + 1] == -1) {
                s[i]--;
                s[i + 1]++;
            }
        }


    }

    for (int i = 0;i < s.size();i++) {
        if (s[i] == 0 || s[i] == 1) {
            answer++;
        }
    }

    return answer;
}