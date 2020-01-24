#include<iostream>
#include<string>
using namespace std;


template <class T>
class Vector {
public:
	struct Node
	{
		T data;
		Node *Next;
		Node(T d)
		{
			data = d;
			//base = NULL;
			//int size;
		}
		Node()
		{

		}
	};

	Node* base;

	// you can have as many functions defined here as you think are appropriate
	// to implement the required operators of the class
public:
	
	int GetSize()const // return the size of the linked list
	{
		if (base == NULL)
			return 1;

		int count = 2;
		Node *ptr = base;

		for (; ptr->Next != NULL; count++)
			ptr = ptr->Next;

		return count;
	}

	int operator*() const// unary operator* to return the size of the linked list
	{
		return GetSize();
	}


	T & operator [] (int Position)// get the element at given position L-H-S
	{
		Position++;
		int size = this->GetSize();

		if (Position <1 || Position>size + 1)
			cout << "Invalid Position !" << endl;
		else
		{
			T ObjToReturn;
			Node *ptr = base;
			for (int i = 1; i < Position; i++)
				ptr = ptr->Next;
			return ptr->data;
		}
	}

	T & operator [] (const int Position) const// get the element at given position R-H-S, also the operator will be used on const object
	{
		int size = this->GetSize();
		if (Position <1 || Position>size)
			cout << "Invalid Position !" << endl;
		else
		{
			//Book ObjToReturn;
			Node *ptr = base;
			for (int i = 1; i < Position; i++)
				ptr = ptr->Next;
			return ptr->data;
		}
	}

	/*	T & operator [] (const bool& StartOrEnd)// get the element at start if StartOrEnd is true, otherwise return the  element at the end (L-H-S)
		{
			if (head == NULL)
				cout << "LinkedList incomplete !" << endl;
			else
			{
				Node *ptr = head;

				if (StartOrEnd == false)
				{
					while (ptr->Next != NULL)
						ptr = ptr->Next;
					return ptr->data;
				}

				else if (StartOrEnd == true)
					return ptr->data;
			}
		}*/

		/*	const Book& operator [] (const bool& StartOrEnd) const// get the element at start if StartOrEnd is true, otherwise return the  element at the end R-H-S
			{
				if (head == NULL)
					cout << "LinkedList incomplete !" << endl;
				else
				{
					Node *ptr = head;

					if (StartOrEnd == false)
					{
						while (ptr->Next != NULL)
							ptr = ptr->Next;
						return ptr->data;
					}

					else if (StartOrEnd == true)
						return ptr->data;
				}
			}
		*/
		/*	T & operator()(const Book& ObjToInsert, const int& Position)// insert the element at the given position
			{
				if (Position<1)
					cout << "Invalid Position !" << endl;

				if (head == NULL)
				{
					if (ObjToInsert.getSISBN() == '\0')
						cout << "Book has invalid ISBN !" << endl;
					Node *newNode = new Node(ObjToInsert);
					newNode->Next = NULL;
					head = newNode;
					return *this;
				}
				Node * successor_ptr = head;
				Node * previous_ptr = NULL;
				Node *newNode = new Node(ObjToInsert);

				for (int i = 1; i <= Position; i++)
				{
					previous_ptr = successor_ptr;
					successor_ptr = successor_ptr->Next;
				}
				newNode->Next = successor_ptr;
				previous_ptr->Next = newNode;
				return *this;
			}
		*/
	void insert(string  d)// insert the element at the rear of the list
	{



		Node *newNode = new Node(d);
		newNode->Next = NULL;
		Node * temp = base;
		if (base != NULL)
		{
			for (; temp->Next != NULL; )
				temp = temp->Next;
			temp->Next = newNode;
		}
		else
			base = newNode;

		//return *this;
		//cout << "done" <<d <<endl;
	}






	Vector & operator~()// unary operator~ to remove the element from the rear
	{

	}

	/*	LinkedList operator!()// return a new list that has the elements in the reverse order
	{
	LinkedList *LL1=new LinkedList;
	if(head!=NULL)
	{
	Node *array=new Node [GetSize()];
	Node *ptr=head;
	for(int i=0;i<this->GetSize();i++)
	{
	array[i]=ptr;
	ptr=ptr->Next;
	}
	Node *new_ptr=new Node(array[GetSize()-1]);
	LL1->head=new_ptr;
	Node *temp=new_ptr;
	for(int i=GetSize()-2;i>=0;i--)
	{
	new_ptr=new Node(array[i]);
	temp->Next=new_ptr;
	temp=new_ptr;
	LL1->head=new_ptr;
	}

	return *LL1;
	}
	}
	*/

	~Vector()
	{

	}

	Vector()
	{
		base = NULL;
		//size = 1;
	}

};