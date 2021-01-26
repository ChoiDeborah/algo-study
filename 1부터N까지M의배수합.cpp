#include <iostream>

using namespace std;

int solution(void)
{
    int n, m, sum = 0;

    cin >> n;
    cin >> m;

    for(int i = 0; i <= n; ++i) {
        if(i%m == 0)
        {
            sum += i;
        }
    }

    return sum;
}

int main(void)
{
    cout << solution();
    return 0;
}