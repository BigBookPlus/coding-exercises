#pragma once
#include<list>
#include<unordered_map>
#include"Node.h"
using namespace std;
class LRUCache{
private:
	list<Node> s;
	unordered_map<int, list<Node>::iterator> addr;
	int size;
public:
	LRUCache(int capacity) :size(capacity){	}

	int get(int key);

	void set(int key, int value);
};