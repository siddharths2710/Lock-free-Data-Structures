#ifndef NODE
#define NODE

template<typename T>
class Node
{
	private:
		T data;
		Node<T>* next;
	public:
		// Node();
		Node(T d);
		Node(T d, Node<T> *n);
		void set_data(T d);
		void set_next(Node<T> *n);
		T get_data();
		Node<T>* get_next();
};

#endif
