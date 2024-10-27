https://basecamp.eolymp.com/en/problems/135

#include <iostream>
#include <vector>
#include <numeric> 
using namespace std;

int lcm(int a, int b) {
    return (a / std::gcd(a, b)) * b; 
}


int lcm_multiple(const std::vector<int>& numbers) {
    int result = numbers[0];
    for (int i = 1; i < numbers.size(); i++) {
        result = lcm(result, numbers[i]);
    }
    return result;
}

int main() {
    int n;
    cin >> n;

   vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
       cin >> numbers[i];
    }

    int result = lcm_multiple(numbers);
    cout << result << endl;

   
}
