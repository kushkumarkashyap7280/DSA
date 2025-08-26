// =========== HashMap Implementation ===========

// WHAT IS MAP ?

// A map is a collection of key-value pairs, where each key is unique and is used to retrieve the corresponding value. Maps are also known as associative arrays or dictionaries in other programming languages. They provide efficient lookup, insertion, and deletion operations based on the key.

// what is hashtable ?

// A hashtable is a data structure that implements an associative array abstract data type, a structure that can map keys to values. A hashtable uses a hash function to compute an index into an array of buckets or slots, from which the desired value can be found. The keys are hashed to produce a unique index, allowing for fast data retrieval.

// there are two types of map

// 1. Ordered Map  - it works on bst and maintain the order so time complexity is O(log n)

// 2. Unordered Map  - it works on hashing and does not maintain the order so time complexity is O(1)

#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;
int main()
{

  // creation

  map<string, int> m;

  // insertion

  //  1.
  m.insert({"kush", 0});

  // 2.
  pair<string, int> p1 = make_pair("is", 1);
  m.insert(p1);

  // 3.
  m["hacker"] = 2;

  // updation

  m["hacker"] = 3;

  // searching

  cout << m["hacker"] << endl;
  cout << m.at("hacker") << endl;

  // cout << m["unknownKey"] << endl;   // 0
  //  cout << m.at("unknownKey") << endl;  // 0

  //  cout << m.at("unknownKey") << endl;   // output : terminate called after throwing an instance of 'std::out_of_range'
  //  cout << m["unknownKey"] << endl;

  // size
  cout << m.size() << endl;

  // if present or not

  cout << m.count("kush") << endl;

  cout << m.count("unknownKey") << endl;

  // erase

  m.erase("hacker");
  cout << m.count("hacker") << endl;

  cout << m.size() << endl;

  // iteartion

  // 1.
  for (auto i : m)
    cout << "key : " << i.first << "--->  " << i.second << endl;

  // 2.
  for (auto it = m.begin(); it != m.end(); it++)
  {
    cout << "key : " << it->first << "--->  " << it->second << endl;
  }

  return 0;
}