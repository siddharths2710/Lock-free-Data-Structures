#include <iostream>
#include "conhashmap.h"
using namespace std;

ConHashMap::ConHashMap() {
	for (int i = 0; i < 31; i++) {
		seg[i] = nullptr;
	}
}

void ConHashMap::put(int k, int v)
{
	Node* n = seg[k % 31].load(memory_order_relaxed);
	for (; n != nullptr; n = n->next) {
		if (n->k == k) {
			n->v = v;
			return;
		}
	}
	Node* en;
	do {
		n = seg[k % 31].load(memory_order_relaxed);
		en = new Node(k, v, n);
	} while(!seg[k % 31].compare_exchange_strong(n, en, memory_order_relaxed));
}

int ConHashMap::get(int k)
{
	Node* n = seg[k % 31].load(memory_order_relaxed);
	for (; n != nullptr; n = n->next) {
		if (n->k == k) {
			return n->v;
		}
	}
	return 0;
}

ostream& operator<<(ostream &obj, ConHashMap& s)
{
	for (int i = 0; i < 31; i++) {
		Node* n = s.seg[i].load(memory_order_relaxed);
		for (; n != nullptr; n = n->next) {
			obj << n->k << ":" << n->v << " ";
		}
	}
	obj << "\n";
	return obj;
}
