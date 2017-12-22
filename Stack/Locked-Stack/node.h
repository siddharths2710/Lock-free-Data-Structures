#ifndef NODE
#define NODE

class Node
{
	private:
		int data;
		Node* next;
	public:
		// Node();
		Node(int d);
		Node(int d, Node *n);
		void set_data(int d);
		void set_next(Node *n);
		int get_data();
		Node* get_next();
};

#endif
