#include <iostream>
#include <string>
#include <list>
using namespace std;

template<typename T>
class Node
{
public:
	T element;
	Node<T>* next;
	Node()
	{
		next=NULL;
	}
	Node(T element)
	{
		this->element=element;
		next=NULL;
	}
};

template<typename T>
class LinkedList
{
public:
	//创建默认链表
	LinkedList();

	//在链表头添加元素
	void addFirst(T element);

	//在链表尾添加元素
	void addLast(T elemebt);

	//得到链表头元素
	T getFirst();

	//得到链表尾元素
	T getLast();

	//删除链表头元素并返回值
	T removeFirst();

	//删除链表尾元素并返回
	T removeLast();

	//将一个新元素附加到链表尾
	void add(T element);

	//将一个新元素添加到链表指定位置
	void add(int index,T element);

	//清空链表
	void clear();

	//如果链表包含指定元素，返回真值
	bool contains(T element);

	//返回链表指定位置元素
	T get(int index);

	//返回链表中第一个匹配元素的结点下标
	int indexOf(T element);

	//如果链表为空，返回真值
	bool isEmpty();

	//返回链表中最后一个匹配元素的结点下标
	int lastIndexOf(T element);

	//删除指定元素（链表中第一个）
	void remove(T element);

	//删除指定元素(所有)
	void removeAll(T element);

	//得到链表大小
	int getSize();

	//删除指定位置元素，并返回
	T removeAt(int index);

	//将指定位置元素设置为新值，并返回原值
	T set(int index,T element);

private:
	Node<T> *head,*tail;
	int size;
};

//创建链表
template<typename T>
LinkedList<T>::LinkedList()
{
	head=tail=NULL;
	size=0;
}

//将元素添加到连表头
template<typename T>
void LinkedList<T>::addFirst(T element)
{
	Node<T> *newNode=new Node<T>(element);
	newNode->next=head;
	head=newNode;
	size++;

	if(tail==NULL)
	{
		tail=head;
	}
}

//将元素添加到链表尾
template<typename T>
void LinkedList<T>::addLast(T element)
{
	if(tail==NULL)
	{
		head=tail=new Node<T>(element);
	}
	else
	{
		tail->next=new Node<T>(element);
		tail=tail->next;
	}
	size++;
}

//返回链表头元素
template<typename T>
T LinkedList<T>::getFirst() 
{
	if(size==0)
	{
		throw runtime_error("Index out of range");
	}
	else
	{
		return head->element;
	}
}

//返回链表尾元素
template<typename T>
T LinkedList<T>::getLast()
{
	if(size==0)
	{
		throw runtime_error("Index out of range");
	}
	else
	{
		return tail->element;
	}
}

//删除链表头元素并返回
template<typename T>
T LinkedList<T>::removeFirst() throw (runtime_error)
{
	if(size==0)
	{
		throw runtime_error("No elements in the list");
	}
	else
	{
		Node<T> *temp=head;
		head=head->next;
		if(head==NULL)
		{
			tail=NULL;
		}
		size--;
		T element=temp->element;
		delete temp;
		return element;
	}
}

//删除链表尾元素并返回
template<typename T>
T LinkedList<T>::removeLast() throw (runtime_error)
{
	if(size==0)
	{
		throw runtime_error("No elements in the list");
	}
	else if(size==1)
	{
		Node<T> *temp=head;
		head=tail=NULL;
		size=0;
		T element=temp->element;
		delete temp;
		return element;
	}
	else
	{
		Node<T> *current=head;
		for(int i=0;i<size-2;i++)
		{
			current=current->next;
		}

		Node<T> *temp=tail;
		tail=current;
		tail->next=NULL;
		size--;
		T element=temp->element;
		delete temp;
		return element;
	}
}

//将一个新元素附加到链表尾
template<typename T>
void LinkedList<T>::add(T element)
{
	addLast(element);
}

//将一个新元素添加到链表指定位置
template<typename T>
void LinkedList<T>::add(int index,T element)
{
	if(index==0)
	{
		addFirst(element);
	}
	else if(index>=size)
	{
		addLast(element);
	}
	else
	{
		Node<T> *current=head;
		for(int i=1;i<index;i++)
		{
			current=current->next;
		}
		Node<T> *temp=current->next;
		current->next=new Node<T>(element);
		(current->next)->next=temp;
		size++;
	}
}

//清空链表
template<typename T>
void LinkedList<T>::clear()
{
	while(head!=NULL)
	{
		Node<T> *temp=head;
		head=head->next;
		delete temp;
		size--;
	}
	tail=NULL;
}

//如果链表包含元素，返回真值
template<typename T>
bool LinkedList<T>::contains(T element)
{
	Node<T> *current=head;
	for(int i=0;i<size;i++)
	{
		if(current->element==element)
		{
			return true;
		}
		current=current->next;
	}

	return false;
}

//返回指定位置元素
template<typename T>
T LinkedList<T>::get(int index)
{
	if(index<0 || index>size-1)
	{
		throw runtime_error("Index out of range");
	}
	
	Node<T> *current=head;
	for(int i=0;i<index;i++)
	{
		current=current->next;
	}
	return current->element;
}

//返回链表中第一个匹配结点的下标
template<typename T>
int LinkedList<T>::indexOf(T element)
{
	Node<T> *current=head;
	for(int i=0;i<size;i++)
	{
		if(current->element==element)
		{
			return i;
		}
		current=current->next;
	}

	return -1;
}

//链表是否为空
template<typename T>
bool LinkedList<T>::isEmpty()
{
	return head==NULL;
}

//返回链表中最后一个匹配结点的下标
template<typename T>
int LinkedList<T>::lastIndexOf(T element)
{
	int result=-1;
	Node<T> *current=head;
	for(int i=0;i<size;i++)
	{
		if(current->element==element)
		{
			result=i;
		}
		current=current->next;
	}

	return result;
}

//删除指定元素(链表中第一个）
template<typename T>
void LinkedList<T>::remove(T element)
{
	Node<T> *current=head;
	for(int i=0;i<size;i++)
	{
		if(current->element==element)
		{
			if(i==0)
			{
				removeFirst();
			}
			else if(i==size-1)
			{  
				removeLast();
			}
			else
			{
				removeAt(i);
			}
			break;
		}
		current=current->next;
	}
}

//删除指定元素(所有)
template<typename T>
void LinkedList<T>::removeAll(T element)
{
	/*当找到要删除的元素时，把此元素的下标传递出去删除，此时链表的长度 减1 ,为了使current能正常的起到下一个数，
	故在删除之前current先指向要删除的下一个数，删除后下一个数往前移(下标减小1)，故--i*/
	Node<T> *current=head;
	for(int i=0;i<size;i++)
	{
		if(current->element==element)
		{
			if(i==0)
			{
				current=current->next;
				removeFirst();
			}
			else if(i==size-1)
			{  
				current=current->next;   
				removeLast();
			}
			else
			{
				current=current->next;
				removeAt(i);
			}
			--i;
			continue;
		}
		current=current->next;
	}
}

//得到链表大小
template<typename T>
int LinkedList<T>::getSize()
{
	return size;
}

//删除链表中指定位置的元素并返回
template<typename T>
T LinkedList<T>::removeAt(int index) 
{
	if(index<0 || index>=size)
	{
		throw runtime_error("Index out of range");
	}
	else if(index==0)
	{
		return removeFirst();
	}
	else if(index==size-1)
	{
		return removeLast();
	}
	else
	{
		Node<T> *previous=head;
		for(int i=1;i<index;i++)
		{
			previous=previous->next;
		}
		Node<T> *current=previous->next;
		previous->next=current->next;
		size--;
		T element=current->element;
		delete current;
		return element;
	}
}

//将指定位置元素设置为新值，并返回原值
template<typename T>
T LinkedList<T>::set(int index,T element)
{
	if (index<0 || index>=size)
	{
		throw runtime_error("Index out of range");
	}
	else
	{
		Node<T> *current=head;
		for(int i=0;i<index;i++)
		{
			current=current->next;
		}
		T element2=current->element;
		current->element=element;

		return element2;
	}
}

int main()
{

	try
	{
		LinkedList<int> list;

		for(int i=0;i<10;i++)
		{
			list.addLast(i);
		}

		list.removeAt(88);

	//	list.clear();

		cout<<"szie:"<<list.getSize()<<endl;

		cout<<list.getFirst()<<endl;
	}
	catch(exception &e)
	{
		cout<<e.what()<<endl;
	}

	system("pause");
	return 0;
}

