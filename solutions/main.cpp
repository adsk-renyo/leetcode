
#include "LeetCode.h"
#include <iostream>
#include <tuple>

using namespace std;

int main()
{
    cout << "Test begin ..." << endl;
    cout << "=======================================" << endl;

    auto res = TestUnitRegistry::instance().run();
    auto succeeded = std::get<0>(res);
    auto failed = std::get<1>(res);
    cout << "succeeded tests: " << endl;
    int ic = 0;
    for (auto& name : succeeded)
    {
        cout << "    " << ++ic << ". "<< name << endl;
    }

    ic = 0;
    cout << endl << "failed tests: " << endl;
    for (auto& name : failed)
    {
        cout << "    " << ++ic << ". " << name << endl;
    }

    cout << endl << "=======================================" << endl;
    cout << "done" << endl;
    return 0;
}
