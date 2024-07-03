#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n, d;
    string x;

    while (cin >> n >> d >> x, n != 0 && d != 0) {
        vector<int> stack;

        for (char c : x) {
            int digit = c - '0';

            while (!stack.empty() && d > 0 && stack.back() < digit) {
                stack.pop_back();
                d--;
            }
            stack.push_back(digit);
        }

        // Se ainda restarem remoções, removemos do final
        while (d > 0) {
            stack.pop_back();
            d--;
        }

        for (int num : stack) {
            cout << num;
        }
        cout << endl;
    }

    return 0;
}
