#ifndef COHSHMP
#define COHSHMP

#include "node.h"
#include <iostream>
#include <atomic>

using namespace std;
class ConHashMap
{
	private:
		atomic<Node*> seg[31];
	public:
		ConHashMap();
		void put(int k, int v);
		int get(int k);
		friend ostream& operator<<(ostream &obj, ConHashMap& s);
};

#endif