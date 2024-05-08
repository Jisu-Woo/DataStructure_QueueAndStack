#include <vector>
#include <algorithm>
#include <iostream>


template <typename T> struct Node {  //� Ÿ������ ���͵� Node ����� ����
	T data;
	Node<T>* next = nullptr;  // auto Ÿ������ X.. ���� ���� �� �ʱ�ȭ �ÿ��� auto Ÿ�� ��밡��!!
	Node(T d = 0) :next(nullptr), data(d) {}
};



template <class T> struct LinkedList {
	Node<T>* head = nullptr;

	void pop_front() {
		if (head == nullptr)
			return;
		auto next = head->next;   //head�� ���� next ������ head->next �ֱ�
		delete head;  //���� head ���� 
		head = next;  //head �� next �ֱ�
		return;
	}

	void push_front(const T& d) {
		auto newNode = new Node<T>(d);
		newNode->next = head;  //������� ������ ��� ����
		head = newNode; //����带 ����
	}

	bool empty() const {  //��ũ�帮��Ʈ�� ������� Ȯ���ϴ� �Լ�
		return head == nullptr;

	}



	void push_back(const T& d) {
		auto cur = head;
		if (cur == nullptr) {
			auto newNode = new Node<T>(d);
			head = newNode;
			return;
		}
		while (cur != nullptr) {  //�� �� ��忡 ������ ������ �ݺ�
			if (cur->next == nullptr) {  // ���� ��尡 �� ������ ����̸�
				auto newNode = new Node<T>(d);
				cur->next = newNode;  //���� ��忡 ����带 ���� �ٿ���
				return;
			}
			cur = cur->next; //���� ��尡 ���� ���� �Ѿ
		}

	}

	void pop_back() {
		if (head == nullptr) { //�ƹ��͵� ���� �� / pop_back �Ұ�
			return;
		}
		if (head->next == nullptr) {  //����Ʈ�� ��� �ϳ� ���� ���
			delete head;  //head�� ����Ű�� ��ü�� �����
			head = nullptr;
			return;
		}
		auto cur = head;  //cur �� head�� �޾Ƽ�
		while (cur->next != nullptr) {  //�� �� ��忡 ������ ������ �ݺ�
			if (cur->next->next == nullptr) {  // ���� ����� ���������� �� ������ ����̸� (front list��)
				delete cur->next;  //�������� ���� ��带 ����
				cur->next = nullptr;  //���� ��带 ����Ű�� ������ null��Ű��
				return;
			}
			cur = cur->next; //���� ��尡 ���� ���� �Ѿ
		}
		printf("Something is wrong! \n");  //���ϰ��� ���ٸ� ����
	}


};

template <class T>
std::ostream& operator << (std::ostream& os, LinkedList<T> list) {  //list ��� ���۷����� �����ε�
	auto cur = list.head;
	while (cur != nullptr) {
		os << cur->data << " ";
		cur = cur->next;
	}
	return os;
}


template<class T> struct Queue {   //Queue ���� struct
	LinkedList<T> list;
	void pop() {
		list.pop_front();
	}
	void push(const T& v) {
		list.push_back(v);
	}
	T front() const {
		return list.head->data;
	}

	bool empty() const {
		return list.empty();
	}
};


template<class T> struct Stack {       //Stack ���� struct
	LinkedList<T> list;
	void pop() {
		list.pop_front();
	}
	void push(const T& v) {
		list.push_front(v);
	}
	T top() const {
		return list.head->data;
	}
	bool empty() const {
		return list.empty();
	}
};


template <class T>   
std::ostream& operator << (std::ostream& os, const Queue<T> q) {  //Queue ��� ���۷����� �����ε�
	auto cur = q.list.head;
	
	while (cur != nullptr) {
		os << cur->data << " ";
		cur = cur->next;
	}
	return os;
}

template <class T>    
std::ostream& operator << (std::ostream& os, const Stack<T> s) {  //Stack ��� ���۷����� �����ε�
	auto cur = s.list.head;
	
	while (cur != nullptr) {
		os << cur->data << " ";
		cur = cur->next;
	}
	return os;
}


int main() {
	LinkedList<float> list;  //LinkedList �׽�Ʈ
	list.push_back(1.5);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);
	list.push_back(5);
	list.push_back(6);
	list.push_back(7);
	list.push_back(8);
	list.pop_back();
	list.pop_back();
	list.pop_back();
	list.empty();

	std::cout << list << std::endl;


	//Queue �׽�Ʈ
	std::cout << "Queue Test\n";
	Queue<int> queue;
	queue.push(1);
	queue.push(2);
	queue.push(3);
	queue.push(4);
	queue.push(5);

	std::cout << queue << std::endl;
	queue.pop();



	std::cout << queue << std::endl;

	std::cout << queue.empty() << std::endl;
	std::cout << queue.front() << std::endl;



	// Stack �׽�Ʈ
	std::cout << "Stack Test\n";
	Stack<int> stack;
	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);
	stack.push(5);

	std::cout << stack << std::endl;
	stack.pop();
	std::cout << stack << std::endl;
	std::cout << stack.empty() << std::endl;
	std::cout << stack.top() << std::endl;

	return 0;
}