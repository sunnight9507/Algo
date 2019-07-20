// 2839 설탕 배달
#include <iostream>

using namespace std;

int func(int n) {
    
    int cnt = 0;
    while (n > 0) {

        if (n % 5 == 0) {
            n -= 5;
            cnt += 1;
        } else if (n % 3 == 0) {
            n -= 3;
            cnt += 1;
        } else if (n > 5) {
            n -= 5;
            cnt += 1;
        } else { // 4 or 2 or 1
            return -1;
        }
    }
    return cnt;
}

int main() {
    int n;
    int result;

    cin >> n;
    
    result = func(n);

    cout << result;

    return 0;
}