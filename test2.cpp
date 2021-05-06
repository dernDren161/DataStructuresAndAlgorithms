//Implement a queue using a linked list

struct Node{
	int data;
	Node* next;
	Node(int data){
		this->data = data;
		next = NULL;
	}
};

struct Queue{
	Node* rear; Node* front;
	Queue(){
		rear = front = NULL;
	}

	void push(int key){
		Node* temp = new Node(key);

		if(rear == NULL){
			rear = front = temp;
			return;
		}
		rear -> next = temp;
		rear = temp;
	}

	void pop(){

		if(front==NULL) return;

		if(front != NULL){
			Node* store = front;
			front = front -> next;
		}

		if(front==NULL) rear = NULL;

		delete(store);
	}
};

int main(){
	Queue q;
	q.push(4);
	q.push(65);
	q.pop();
	q.push(7);
	q.push(5);
	q.push(72);
	q.pop();

	cout << q->front << endl;
	cout << q->rear << endl;
}
