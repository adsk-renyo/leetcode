#pragma once

#include <vector>
#include <string>
#include <tuple>

using namespace std;

class TestUnit
{
public:
    TestUnit(string name);

    const string& name() const;

    virtual bool run() const = 0;

protected:
    string  m_name;
};

//=========================================================
class TestUnitRegistry
{
public:
    static TestUnitRegistry&                instance();
    void                                    add(TestUnit* test);

    /// return <succeded tests, faield tests>
    tuple<vector<string>, vector<string>>   run() const;

public:
    std::vector<TestUnit*>  m_tests;
};

//=========================================================
class TwoSum : public TestUnit
{
public:
    TwoSum();
    bool run() const override;

private:
    vector<int> solve(const vector<int>& nums, int target) const;
};

//=========================================================
class AddTwoNumbers : public TestUnit
{
public:
    AddTwoNumbers();
    bool run() const override;

private:
    struct ListNode 
    {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

    ListNode* addTwoNumbers(const ListNode* l1, const ListNode* l2) const;
    void deleteList(ListNode* header) const;
    ListNode* fromValues(const vector<int> values) const;
    vector<int> toValues(const ListNode* header) const;
};