#include <vector>
#include <algorithm>
#include <iostream>


template <typename T> struct Node {  //어떤 타입으로 들어와도 Node 만들기 가능
	T data;
	Node<T>* next = nullptr;  // auto 타입으로 X.. 변수 선언 및 초기화 시에만 auto 타입 사용가능!!
	Node(T d = 0) :next(nullptr), data(d) {}
};



template <class T> struct LinkedList {
	Node<T>* head = nullptr;

	void pop_front() {
		if (head == nullptr)
			return;
		auto next = head->next;   //head로 만들 next 정의후 head->next 넣기
		delete head;  //기존 head 삭제 
		head = next;  //head 에 next 넣기
		return;
	}

	void push_front(const T& d) {
		auto newNode = new Node<T>(d);
		newNode->next = head;  //뉴노드의 다음에 헤드 연결
		head = newNode; //뉴노드를 헤드로
	}

	bool empty() const {  //링크드리스트가 비었는지 확인하는 함수
		return head == nullptr;

	}



	void push_back(const T& d) {
		auto cur = head;
		if (cur == nullptr) {
			auto newNode = new Node<T>(d);
			head = newNode;
			return;
		}
		while (cur != nullptr) {  //맨 끝 노드에 도달할 때까지 반복
			if (cur->next == nullptr) {  // 현재 노드가 맨 마지막 노드이면
				auto newNode = new Node<T>(d);
				cur->next = newNode;  //다음 노드에 뉴노드를 만들어서 붙여줌
				return;
			}
			cur = cur->next; //현재 노드가 다음 노드로 넘어감
		}

	}

	void pop_back() {
		if (head == nullptr) { //아무것도 없을 때 / pop_back 불가
			return;
		}
		if (head->next == nullptr) {  //리스트에 헤드 하나 뿐인 경우
			delete head;  //head가 가리키는 객체를 지우기
			head = nullptr;
			return;
		}
		auto cur = head;  //cur 에 head값 받아서
		while (cur->next != nullptr) {  //맨 끝 노드에 도달할 때까지 반복
			if (cur->next->next == nullptr) {  // 현재 노드의 다음다음이 맨 마지막 노드이면 (front list라서)
				delete cur->next;  //현재노드의 다음 노드를 지움
				cur->next = nullptr;  //다음 노드를 가리키는 포인터 null시키기
				return;
			}
			cur = cur->next; //현재 노드가 다음 노드로 넘어감
		}
		printf("Something is wrong! \n");  //리턴값이 없다면 오류
	}


};

template <class T>
std::ostream& operator << (std::ostream& os, LinkedList<T> list) {  //list 출력 오퍼레이터 오버로딩
	auto cur = list.head;
	while (cur != nullptr) {
		os << cur->data << " ";
		cur = cur->next;
	}
	return os;
}


template<class T> struct Queue {   //Queue 구현 struct
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


template<class T> struct Stack {       //Stack 구현 struct
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
std::ostream& operator << (std::ostream& os, const Queue<T> q) {  //Queue 출력 오퍼레이터 오버로딩
	auto cur = q.list.head;
	
	while (cur != nullptr) {
		os << cur->data << " ";
		cur = cur->next;
	}
	return os;
}

template <class T>    
std::ostream& operator << (std::ostream& os, const Stack<T> s) {  //Stack 출력 오퍼레이터 오버로딩
	auto cur = s.list.head;
	
	while (cur != nullptr) {
		os << cur->data << " ";
		cur = cur->next;
	}
	return os;
}


int main() {
	LinkedList<float> list;  //LinkedList 테스트
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


	//Queue 테스트
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



	// Stack 테스트
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