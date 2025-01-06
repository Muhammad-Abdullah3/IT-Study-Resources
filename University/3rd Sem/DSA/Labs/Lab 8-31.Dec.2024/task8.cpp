#include <iostream>
#include <vector>
using namespace std;

vector<int> nextGreaterElement(const vector<int>& arr) {
    vector<int> result(arr.size(), -1);
    vector<int> stack;

    for (int i = arr.size() - 1; i >= 0; --i) {
        while (!stack.empty() && stack.back() <= arr[i]) {
            stack.pop_back();
        }
        if (!stack.empty()) {
            result[i] = stack.back();
        }
        stack.push_back(arr[i]);
    }

    return result;
}

int main() {
    vector<int> arr = {4, 5, 2, 10};
    vector<int> result = nextGreaterElement(arr);

    cout << "Array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    cout << "Next Greater Elements: ";
    for (int num : result) cout << num << " ";
    cout << endl;

    return 0;
}
