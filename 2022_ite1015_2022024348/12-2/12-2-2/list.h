#include <iostream>
using namespace std;
template <class U>
class Node
{
	public:
		U data;
		Node<U>* next = NULL;
};
template <class T>
class List {
private:
    Node<T> *head;
public:
    List() : head(NULL) {};
    ~List()
{
	while(head->next != NULL)
	{
		pop_front();
	}
	delete head;
}
//free resources
    List(T* arr, int n_nodes)
{
	head = new Node<T>;
	head->data = arr[0];
	for(int i = 1;i < n_nodes;++i)
	{
		push_back(arr[i]);
	}
}
//create a list with n_nodes
void insert_at(int idx, const T& data)
{
	Node<T>* tmp = head;
	for(int i = 1;i < idx;++i)
	{
		tmp = tmp->next;
	}
	Node<T>* temp = new Node<T>;
	temp->data = data;
	temp->next = tmp->next;
	tmp->next = temp;
}
    void remove_at(int idx)
{
	Node<T>* tmp = head;
	for(int i = 1;i < idx;++i)
	{
		tmp = tmp->next;
	}
	if(tmp->next->next != NULL)
	{
		tmp->next = tmp->next->next;
	}
	else
	{
		tmp->next = NULL;
	}
}
    void pop_back()
{
	Node<T>* tmp = head;
	Node<T>* temp;
	while(tmp->next !=NULL)
	{
		temp = tmp;
		tmp = tmp->next;
	}
	temp->next = NULL;
	delete tmp;
}
    void push_back(const T& val)
{
	Node<T>* tmp = head;
	while(tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	Node<T>* temp = new Node<T>;
	temp->data = val;
	tmp->next = temp;
}
    void pop_front()
{
	Node<T>* tmp = head;
	head = tmp->next;
	delete tmp;
}
    void push_front(const T& val)
{
	Node<T>* tmp = new Node<T>;
	tmp->data = val;
	tmp->next = head;
	head = tmp;
}
template <class U>
    friend ostream& operator<<(ostream& out, List<U>& rhs);//print out nodes
};
template <class T>
ostream& operator<<(ostream& out, List<T>& rhs)
{
	Node<T>* tmp = rhs.head;
	while(tmp->next != NULL)
	{
		out << tmp->data << ',';
		tmp = tmp->next;
	}
	out << tmp->data;
	return out;
}
