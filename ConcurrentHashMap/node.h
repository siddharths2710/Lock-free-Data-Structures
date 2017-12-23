#ifndef NODE
#define NODE

class Node
{
	public:
		const int k;
		volatile int v;
		Node* const next;
		Node(int k, int v, Node *n): k(k), v(v), next(n) {};
};

#endif
