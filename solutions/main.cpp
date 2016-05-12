
#include <iostream>
#include <initializer_list>
#include <vector>
#include "LeetCode.h"

using namespace std;

bool testTwoSum()
{
    vector<int> in = {0, 2, 15, 7, 11, 11, 13};
    auto target = 9;
    auto res = LeetCode::twoSum(in, target);
    return res == vector<int>({1, 3});
}

int main()
{
    cout << "Test begin ..." << endl;


    bool bRet = true;

    bRet &= testTwoSum();

    cout << (bRet ? "Success." : "Failed. ") << endl;
    return 0;
}
