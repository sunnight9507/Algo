// 14888 연산자 끼워넣기
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[101];
int plus_n, minus_n, mul_n, div_n;
int min_n = 1000000000;
int max_n = -1000000000;

void func(int index, int sum, int plus, int minus, int mul, int div) {
    if (index == n) {
        if (sum > max_n) {
            max_n = sum;
        }
        if (sum < min_n) {
            min_n = sum;
        }
        return;
    }

    if (plus < 0 || minus < 0 || mul < 0 || div < 0) {
        return;
    }

    if (plus > 0) {
        func(index + 1, sum + arr[index], plus - 1, minus, mul, div);
    }
    if (minus > 0) {
        func(index + 1, sum - arr[index], plus, minus - 1, mul, div);
    }
    if (mul > 0) {
        func(index + 1, sum * arr[index], plus, minus, mul - 1, div);
    }
    if (div > 0) {
        func(index + 1, sum / arr[index], plus, minus, mul, div - 1);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> plus_n >> minus_n >> mul_n >> div_n;

    func(1, arr[0], plus_n, minus_n, mul_n, div_n);

    cout << max_n << '\n';
    cout << min_n << '\n';
    return 0;
}