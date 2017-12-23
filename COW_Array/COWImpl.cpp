#include <cstdlib>
#include <atomic>
#include <iostream>
using namespace std;

#define NO_OF_ELEMS 5

struct Vector
{
	int *arr;
	int length;
};

class CopyOnWriteArray
{
	private:
		atomic<struct Vector *>v;
		int length;
		int index;
	public:
		
		CopyOnWriteArray()
		{
			v.store((struct Vector*)malloc(sizeof(struct Vector)) , memory_order_relaxed);
			Vector *tmp = v.load(memory_order_acquire);
			
			tmp->length = 10;
			index = 0;
			tmp->arr = (int*)malloc(10*sizeof(int));
		}

		CopyOnWriteArray(int l)
		{
			v.store((struct Vector*)malloc(sizeof(struct Vector)) , memory_order_relaxed);
			Vector *tmp = v.load(memory_order_acquire);
			
			tmp->length = l;
			index = 0;
			tmp->arr = (int*)malloc(l*sizeof(int));
		}

		void add(int elem)
		{

			struct Vector * new_vec = nullptr;
			struct Vector * old_vec = nullptr;
			do
			 {
			 	old_vec = v.load(memory_order_relaxed);
			 	atomic_thread_fence(memory_order_acquire);

			 	if(new_vec != nullptr)
			 	{
			 		free(new_vec->arr);
			 		free(new_vec);
			 	}
			 	
			 	
			 	new_vec = (struct Vector*)malloc(sizeof(struct Vector));
			 	
			 	if( index  == old_vec -> length - 1 )
			 	{
			 		new_vec->length = old_vec->length << 1;	
			 	}
			 	
			 	else
			 	{
			 		new_vec->length = old_vec->length;		
			 	} 
			 	

			 	new_vec->arr =(int*)malloc((new_vec->length)*sizeof(int));

			 	for(int i=0;i<=index;i++)
			 	{
			 		new_vec->arr[i] = old_vec->arr[i];
			 	}
			 	
			 	new_vec->arr[++index] = elem;


			 } while ( ! ( v ).compare_exchange_weak( old_vec , new_vec , memory_order_relaxed )); 
			
		}

		void disp()
		{
			struct Vector *tmp = v.load(memory_order_relaxed);
			for(int i = 0; i < tmp->length;i++)
			{
				cout<<" "<<tmp->arr[i];
			}
			cout<<endl;
		}

};


int main(int argc, char const *argv[])
{
	CopyOnWriteArray c(10);

	for(int i=1;i<NO_OF_ELEMS;i++)
	{
		c.add(i);
	}

	c.disp();
	
	return 0;
}
