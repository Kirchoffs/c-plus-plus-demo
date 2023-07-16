#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
using ll = long long;

struct BigInteger {
    static const int BASE = 100000000;
    static const int WIDTH = 8;

    // From low digits to high digits
    vector<int> nums;

    BigInteger(ll num = 0) {
        *this = num;
    }

    BigInteger(const string& str) {
        *this = str;
    }

    BigInteger operator=(ll num) {
        nums.clear();
        do {
            nums.push_back(num % BASE);
            num /= BASE;
        } while (num > 0);
        return *this;
    }

    BigInteger operator=(const string& str) {
        nums.clear();
        // 1 ~ 8: 1
        // 9 ~ 16: 2
        // 17 ~ 24: 3
        int len = (str.length() - 1) / WIDTH + 1;
        int num;
        // Low digits number first
        for (int i = 0; i < len; i++) {
            int end = str.length() - i * WIDTH;
            int start = max(0, end - WIDTH);
            sscanf(str.substr(start, end - start).c_str(), "%d", &num);
            nums.push_back(num);
        }
        return *this;
    }
};

ostream& operator<<(ostream& out, const BigInteger& big_integer) {
    if (big_integer.nums.empty()) {
        out << 0;
        return out;
    }

    out << big_integer.nums.back();
    for (int i = big_integer.nums.size() - 2; i >= 0; i--) {
        char buf[20];
        snprintf(buf, 20, "%08d", big_integer.nums[i]);
        for (int j = 0; j < strlen(buf); j++) out << buf[j];
    }
    return out;
}

istream& operator>>(istream& in, BigInteger& big_integer) {
    string str;
    in >> str;
    big_integer = str;
    return in;
}

int main() {
    BigInteger num_alpha("123456789012345678901234567890");
    cout << num_alpha << endl;

    BigInteger num_beta;
    cin >> num_beta;
    cout << num_beta << endl;
}
