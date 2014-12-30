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
	//����Ĭ������
	LinkedList();

	//������ͷ���Ԫ��
	void addFirst(T element);

	//������β���Ԫ��
	void addLast(T elemebt);

	//�õ�����ͷԪ��
	T getFirst();

	//�õ�����βԪ��
	T getLast();

	//ɾ������ͷԪ�ز�����ֵ
	T removeFirst();

	//ɾ������βԪ�ز�����
	T removeLast();

	//��һ����Ԫ�ظ��ӵ�����β
	void add(T element);

	//��һ����Ԫ����ӵ�����ָ��λ��
	void add(int index,T element);

	//�������
	void clear();

	//����������ָ��Ԫ�أ�������ֵ
	bool contains(T element);

	//��������ָ��λ��Ԫ��
	T get(int index);

	//���������е�һ��ƥ��Ԫ�صĽ���±�
	int indexOf(T element);

	//�������Ϊ�գ�������ֵ
	bool isEmpty();

	//�������������һ��ƥ��Ԫ�صĽ���±�
	int lastIndexOf(T element);

	//ɾ��ָ��Ԫ�أ������е�һ����
	void remove(T element);

	//ɾ��ָ��Ԫ��(����)
	void removeAll(T element);

	//�õ������С
	int getSize();

	//ɾ��ָ��λ��Ԫ�أ�������
	T removeAt(int index);

	//��ָ��λ��Ԫ������Ϊ��ֵ��������ԭֵ
	T set(int index,T element);

private:
	Node<T> *head,*tail;
	int size;
};

//��������
template<typename T>
LinkedList<T>::LinkedList()
{
	head=tail=NULL;
	size=0;
}

//��Ԫ����ӵ�����ͷ
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

//��Ԫ����ӵ�����β
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

//��������ͷԪ��
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

//��������βԪ��
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

//ɾ������ͷԪ�ز�����
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

//ɾ������βԪ�ز�����
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

//��һ����Ԫ�ظ��ӵ�����β
template<typename T>
void LinkedList<T>::add(T element)
{
	addLast(element);
}

//��һ����Ԫ����ӵ�����ָ��λ��
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

//�������
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

//����������Ԫ�أ�������ֵ
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

//����ָ��λ��Ԫ��
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

//���������е�һ��ƥ������±�
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

//�����Ƿ�Ϊ��
template<typename T>
bool LinkedList<T>::isEmpty()
{
	return head==NULL;
}

//�������������һ��ƥ������±�
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

//ɾ��ָ��Ԫ��(�����е�һ����
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

//ɾ��ָ��Ԫ��(����)
template<typename T>
void LinkedList<T>::removeAll(T element)
{
	/*���ҵ�Ҫɾ����Ԫ��ʱ���Ѵ�Ԫ�ص��±괫�ݳ�ȥɾ������ʱ����ĳ��� ��1 ,Ϊ��ʹcurrent������������һ������
	����ɾ��֮ǰcurrent��ָ��Ҫɾ������һ������ɾ������һ������ǰ��(�±��С1)����--i*/
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

//�õ������С
template<typename T>
int LinkedList<T>::getSize()
{
	return size;
}

//ɾ��������ָ��λ�õ�Ԫ�ز�����
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

//��ָ��λ��Ԫ������Ϊ��ֵ��������ԭֵ
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

