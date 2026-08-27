#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    // Prime factor counts of d (1..9) for {2, 3, 5, 7}.
    // p2[1..9] / p3 / p5 / p7
    static const int p2[10], p3[10], p5[10], p7[10];

    // Minimum number of digits required to absorb a given prime budget.
    // Greedy peel 9, 8, 7, 6, 5, 4, 3, 2.
    static int minDigits(int a, int b, int c, int d) {
        const int greedy[] = {9, 8, 7, 6, 5, 4, 3, 2};
        int cnt = 0;
        for (int x : greedy) {
            while (a >= p2[x] && b >= p3[x] && c >= p5[x] && d >= p7[x]) {
                a -= p2[x]; b -= p3[x]; c -= p5[x]; d -= p7[x];
                cnt++;
            }
        }
        if (a || b || c || d) return -1;
        return cnt;
    }

    // Smallest string of exact length L whose digit product has prime budget
    // >= (a,b,c,d), using only digits 1-9. Assumes minDigits <= L.
    // 1s come first (smallest position), then non-1 digits in ascending order.
    static string smallestStr(int a, int b, int c, int d, int L) {
        const int greedy[] = {9, 8, 7, 6, 5, 4, 3, 2};
        vector<int> digits;
        for (int x : greedy) {
            while (a >= p2[x] && b >= p3[x] && c >= p5[x] && d >= p7[x]) {
                a -= p2[x]; b -= p3[x]; c -= p5[x]; d -= p7[x];
                digits.push_back(x);
            }
        }
        sort(digits.begin(), digits.end());
        int ones = L - (int)digits.size();
        string s;
        while (ones-- > 0) s.push_back('1');
        for (int x : digits) s.push_back(char('0' + x));
        return s;
    }

    // Smallest string of EXACT length L (== num.size()) with product's prime
    // budget >= (a,b,c,d) and value >= num. Digit-by-digit greedy.
    // Returns empty if no such string exists.
    static string smallestGE(string num, int a, int b, int c, int d) {
        int n = (int)num.size();
        string result(n, '?');
        int ca = a, cb = b, cc = c, cd = d;
        for (int i = 0; i < n; i++) {
            bool placed = false;
            for (int x = 1; x <= 9; x++) {
                int ra = ca - p2[x], rb = cb - p3[x], rc = cc - p5[x], rd = cd - p7[x];
                if (ra < 0 || rb < 0 || rc < 0 || rd < 0) continue;
                if (minDigits(ra, rb, rc, rd) > n - i - 1) continue;
                char cx = char('0' + x);
                if (cx > num[i]) {
                    // Commit: place x, fill rest with smallest.
                    result[i] = cx;
                    string tail = smallestStr(ra, rb, rc, rd, n - i - 1);
                    for (int k = 0; k < (int)tail.size(); k++)
                        result[i + 1 + k] = tail[k];
                    return result;
                }
                if (cx == num[i]) {
                    // Tentative: place x, continue.
                    result[i] = cx;
                    ca = ra; cb = rb; cc = rc; cd = rd;
                    placed = true;
                    break;
                }
                // cx < num[i]: skip
            }
            if (!placed && result[i] == '?') return "";
        }
        // All positions matched num exactly.
        if (result.find('?') == string::npos) return result;
        return "";
    }

    string smallestNumber(string num, long long t) {
        if (t == 0) return "-1"; // product of non-zero digits is never divisible by 0
        // Step 1: prime factorization of t in {2, 3, 5, 7}.
        int a = 0, b = 0, c = 0, d = 0;
        for (long long p = 2; p <= 7; p++) {
            while (t % p == 0) {
                if (p == 2) a++;
                else if (p == 3) b++;
                else if (p == 5) c++;
                else if (p == 7) d++;
                t /= p;
            }
        }
        if (t != 1) return "-1";

        int n = (int)num.size();

        // Try exact-length match: smallest n-digit valid number >= num.
        string exact = smallestGE(num, a, b, c, d);
        if (!exact.empty()) return exact;

        // Try longer lengths. Any L-digit number (L > n) automatically > num.
        // The smallest such number is the smallest L-digit valid number.
        // Minimum L is max(n+1, minDigits(need)) — beyond that, more 1s only
        // make the number larger, so max(n+1, minDigits) is optimal.
        int minDig = minDigits(a, b, c, d);
        if (minDig < 0) return "-1";
        int L = max(n + 1, minDig);
        return smallestStr(a, b, c, d, L);
    }
};

const int Solution::p2[10] = {0,0,1,0,2,0,1,0,3,0};
const int Solution::p3[10] = {0,0,0,1,0,0,1,0,0,2};
const int Solution::p5[10] = {0,0,0,0,0,1,0,0,0,0};
const int Solution::p7[10] = {0,0,0,0,0,0,0,1,0,0};
