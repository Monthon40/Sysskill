struct list_node{
	int value;
	struct list_node * next;
};
typedef struct list_node Node;

Node * front;

int search(int num);
void insert(int num);
int delete(int num);
void print();
