#include <bits/stdc++.h>
using namespace std;

class Bucket
{
private:
    list<int> eachContainer;

public:
    Bucket()
    {
        list<int> containerTemp;
        eachContainer = containerTemp;
    }

    void insert(int &key)
    {
        if (!exists(key))
            eachContainer.insert(eachContainer.begin(), key);
    }

    void remove(int &key)
    {
        if (exists(key))
            eachContainer.remove(key);
    }

    bool exists(int &key)
    {
        bool result = false;
        for (auto it = eachContainer.begin(); it != eachContainer.end(); ++it)
            if (*it == key)
                result = true;
        return result;
    }
};

class MyHashSet
{

private:
    int keyRange;
    vector<Bucket *> bucketsVec;

private:
    int _hash(int &key)
    {
        return (key % keyRange);
    }

public:
    /** Initialize your data structure here. */
    MyHashSet()
    {
        keyRange = 997;
        vector<Bucket *> bucketsVecTemp;
        bucketsVec = bucketsVecTemp;

        for (int i = 0; i < keyRange; ++i)
        {
            Bucket *bucketPtr = new Bucket();
            bucketsVec.push_back(bucketPtr);
        }
    }

    void add(int key)
    {
        int bucketIndex = _hash(key);
        bucketsVec[bucketIndex]->insert(key);
    }

    void remove(int key)
    {
        int bucketIndex = _hash(key);
        bucketsVec[bucketIndex]->remove(key);
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key)
    {
        int bucketIndex = _hash(key);
        return bucketsVec[bucketIndex]->exists(key);
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
