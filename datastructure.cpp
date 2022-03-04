#include <bits/stdc++.h>

using namespace std;

// sort in descending order
bool compareDesc(int a, int b)
{
    return a > b;
}
// sort in descending order of maginitude
bool compareAsc(int a, int b)
{
    return a < b;
}
// sort in descending order of maginitude
bool compareMagDesc(int a, int b)
{
    return abs(a) > abs(b);
}
// sort in ascending order of maginitude
bool compareMagAsce(int a, int b)
{
    return abs(a) < abs(b);
}
bool cmpString(char a, char b)
{
    return a < b;
}
int main()
{
    // this is greater priority queue which has 20 at top;
    priority_queue<int, vector<int>> pq;
    ;
    // to make smaller priority queue use as  =>  priority_queue<int, vector<int>,greater<int>> pq
    // It has 2 at top

    pq.push(20);
    pq.push(10);
    pq.push(2);
    pq.push(12);
    cout << pq.top() << "\n";

    //-------------------------------------- set and maps --------------------------------------------
    set<int> myset;
    myset.insert(20);
    myset.insert(2);
    myset.insert(30);
    myset.insert(3);

    // find() gives itertor to the elememt if exits otherwise it is equal to myset.end();
    auto it = myset.find(30);
    cout << *it << "\n";
    //---------------------------maps---------------------------------
    map<string, int> myMap;
    myMap.insert(make_pair("AMan", 20));
    cout << myMap["AMan"] << "\n";

    //----------------------- sorting arrays ---------------------------------------

    vector<int> vec = {1, 0, -1, 4, 12, 45, 64, -8, 29, 4};
    sort(vec.begin(), vec.end(), compareAsc);
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    // ------------------------sorting strings --------------------------------
    string s = "govind";
    sort(s.begin(), s.end(), cmpString);
    cout << s << "\n";
    // -----------------------------permutation-------------------------------
    do
    {
        cout << "Pemuting-\n";
    } while (!next_permutation(vec.begin(), vec.end()));
    //------------------------------------stringstream-----------------
    // to write value use << and to read use >>
    stringstream numToString;
    numToString << 5;
    string val;
    numToString >> val; // val is "5" now;

    stringstream stringToNum;
    stringToNum << "5";
    int val1;
    try
    {
        stringToNum >> val1;
        cout<<val1<<"\n";
    }
    catch (exception e)
    {
        cout << "Eexception occured\n";
        cout << e.what() << "\n";
    }
}