#include <iostream>
#include <vector>

using namespace std;

// 函数重载判断是否为左值引用
template <typename T> void leftOrRightValue(T &t) {
    cout << "Function Overload: ";
    cout << "l-value" << endl;
}

// 函数重载判断是否为右值引用
template <typename T> void leftOrRightValue(T &&t) {
    cout << "Function Overload: ";
    cout << "r-value" << endl;
}

// 使用模板元编程判断是否为左值引用
// 1. 使用is_lvalue_reference<T>::value判断是否为左值引用
template <typename T> void judge(T &&t) {
    cout << "judge: ";
    if (std::is_lvalue_reference<T>::value) {
        cout << "l-value" << endl;
    } else {
        cout << "r-value" << endl;
    }
}

int main() {
    int a = 1;
    judge(a);                       // l-value
    judge(1);                       // r-value
    judge(std::move(a));            // r-value
    leftOrRightValue(a);            // l-value
    leftOrRightValue(1);            // r-value
    leftOrRightValue(std::move(a)); // r-value

    vector<int> v = {1, 2, 3};
    judge(v[0]);                       // l-value
    judge(v[0] + 1);                   // r-value
    judge(std::move(v[0]));            // r-value
    leftOrRightValue(v[0]);            // l-value
    leftOrRightValue(v[0] + 1);        // r-value
    leftOrRightValue(std::move(v[0])); // r-value
    return 0;
}
