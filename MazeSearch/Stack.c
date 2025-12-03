int stack[1000];
int size = 0;

void push(int data) {
	stack[size] = data;
	size++;
}

void pop() {
	stack[size - 1] = 0;
	size--;
}

int size() {
	return size;
}