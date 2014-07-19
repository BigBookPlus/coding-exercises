#include"LRUCache.h"
int LRUCache::get(int key) {

	if (addr.find(key) == addr.end())
		return -1;
	s.splice(s.begin(), s, addr[key]);
	addr[key] = s.begin();
	return addr[key]->value;
}

void LRUCache::set(int key, int value) {
	Node* target = NULL;
	if (addr.find(key) != addr.end())
	{
		addr[key]->value = value;
		s.splice(s.begin(), s, addr[key]);
		addr[key] = s.begin();
	}
	else{
		if (s.size() == size)
		{
			addr.erase(s.back().key);
			s.pop_back();
		}
		//Node *newNode = new Node(key,value);
		s.push_front(Node(key, value));
		addr[key] = s.begin();

	}
}