#include "LeetCode.h"
#include <unordered_map>
#include <unordered_set>
#include <initializer_list>

TestUnit::TestUnit(string name) :m_name(std::move(name))
{
    TestUnitRegistry::instance().add(this);
}

const string& TestUnit::name() const
{
    return m_name;
}

TestUnitRegistry&    TestUnitRegistry::instance()
{
    static TestUnitRegistry inst;
    return inst;
}

void
TestUnitRegistry::add(TestUnit* test)
{
    m_tests.push_back(test);
}

tuple<vector<string>, vector<string>>
TestUnitRegistry::run() const
{
    vector<string> failed, succeeded;
    for (auto& test : m_tests)
    {
        if (test->run())
            succeeded.push_back(test->name());
        else
            failed.push_back(test->name());
    }
    return std::make_tuple(succeeded, failed);
}


//=========================================================
TwoSum::TwoSum() :TestUnit("TwoSum")
{
}

bool
TwoSum::run() const
{
    vector<int> in = { 0, 2, 15, 7, 11, 11, 13 };
    auto target = 9;
    auto extpected = vector<int>({ 1, 3 });
    return extpected == solve(in, target);
}

vector<int>
TwoSum::solve(const vector<int>& nums, int target) const
{
    unordered_map<int, int> matchMap; // <matchVal, thisValueId>
    for (size_t i = 0; i < nums.size(); ++i) {
        auto it = matchMap.find(nums[i]);
        if (it != matchMap.end()) {
            return { it->second, (int)i };
        }
        else {
            matchMap[target - nums[i]] = i;
        }
    }
    return{};
}

TwoSum g_twoSum;


//=========================================================
AddTwoNumbers::AddTwoNumbers() :TestUnit("AddTwoNumbers")
{
}

bool 
AddTwoNumbers::run() const
{
    {
        auto list1 = fromValues({ 2, 4, 3 });
        auto list2 = fromValues({ 5, 6, 4 });
        auto expected = vector<int>({ 7, 0, 8 });
        auto resList = addTwoNumbers(list1, list2);
        auto resValues = toValues(resList);
        deleteList(list1);
        deleteList(list2);
        deleteList(resList);
        if (expected != resValues)
            return false;
    }
    {
        auto list1 = fromValues({ 2, 4, 3 });
        auto list2 = fromValues({ 5, 6, 8 });
        auto expected = vector<int>({ 7, 0, 2, 1 });
        auto resList = addTwoNumbers(list1, list2);
        auto resValues = toValues(resList);
        deleteList(list1);
        deleteList(list2);
        deleteList(resList);
        if (expected != resValues)
            return false;
    }
    return true;
}

AddTwoNumbers::ListNode* 
AddTwoNumbers::addTwoNumbers(const ListNode* l1, const ListNode* l2) const
{
    ListNode* header = nullptr;
    ListNode* prevNode = nullptr;
    int carry = 0;
    auto cur1 = l1;
    auto cur2 = l2;
    while(cur1 || cur2)
    {
        int sum = carry;
        if (cur1) {
            sum += cur1->val;
            cur1 = cur1->next;
        }
        if (cur2) {
            sum += cur2->val;
            cur2 = cur2->next;
        }
        auto dig = sum % 10;
        carry = sum / 10;
        auto newNode = new ListNode(dig);
        if (!prevNode) {
            header = newNode;
            prevNode = header;
        }
        else {
            prevNode->next = newNode;
            prevNode = newNode;
        }
    }
    if (carry > 0) {
        auto newNode = new ListNode(carry);
        prevNode->next = newNode;
        prevNode = newNode;
    }

    return header;
}

void AddTwoNumbers::deleteList(ListNode* header) const
{
    while (header) {
        auto next = header->next;
        delete header;
        header = next;
    };
}


AddTwoNumbers::ListNode* AddTwoNumbers::fromValues(const vector<int> values) const
{
    if (values.empty())
        return nullptr;
    auto header = new ListNode(values[0]);
    auto prev = header;
    for (size_t i = 1; i < values.size(); ++i) {
        auto node = new ListNode(values[i]);
        prev->next = node;
        prev = node;
    }
    return header;
}

vector<int> AddTwoNumbers::toValues(const ListNode* header) const
{
    vector<int> res;
    auto cur = header;
    while (cur) {
        res.push_back(cur->val);
        cur = cur->next;
    }
    return res;
}


AddTwoNumbers gAddTwoNumbers;
