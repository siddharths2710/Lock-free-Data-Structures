#ifndef NODE
#define NODE


class Node
{
	private:
		int data;
		Node *next;
	public:
		Node();

		Node(int d);

		Node(int d,Node *n);

		void setData(int d);

		void setNext(Node *n);

		int getData();

		Node* getNext();

		
};

#endif