#pragma once
#include <iostream>
template<class Type> class LinkedList_Iter;

template <class TempType>
class Template_Single_Linked_List
{
	
	struct Template_Node;

	friend class LinkedList_Iter < TempType >;
public:
	// made to do a call back when I call the drop function
	void(*DropCallBackFuncptr)(TempType ObjtoCallBackOn);

	unsigned int counter = 0;
	Template_Node* root_Head;
	Template_Node* end_Tail;
	struct Template_Node
	{
		TempType* Var;
		Template_Node* Next;

	};

	Template_Single_Linked_List();
	~Template_Single_Linked_List();

	void ShowValue(int);
	void CombineValues(TempType);
	TempType& operator[](unsigned int);
	void addHead(TempType& addMe);
	void addTail(TempType& addMe);
	void Insert(LinkedList_Iter<TempType>& index, TempType& v);
	void remove(LinkedList_Iter<TempType>& index);
	// deletes node and returns what was being used
	TempType& Drop(LinkedList_Iter<TempType>& index);
	void EmptyList();
};
template <class TempType>
Template_Single_Linked_List<TempType>::Template_Single_Linked_List()
{
	root_Head = nullptr;
	end_Tail = nullptr;
}
template <class  TempType>
Template_Single_Linked_List<TempType>::~Template_Single_Linked_List()
{
	EmptyList();
}

template <class  TempType>
void Template_Single_Linked_List<TempType>::ShowValue(int i)
{
	std::cout << (*(this))[i] << std::endl;
}

template <class TempType>
void Template_Single_Linked_List<TempType>::CombineValues(TempType addThisToVar)
{
	//std::cout << Var + addThisToVar << std::endl;
}
template <class  TempType>
TempType& Template_Single_Linked_List<TempType>::operator[](unsigned int Index)
{
	
	Template_Node*  Iter = root_Head;
	for (unsigned int count = 0; count < counter && count < Index ; count++)
	{
		Iter = Iter->Next;
	}
	return *(Iter->Var);
}
template <class  TempType>
void Template_Single_Linked_List<TempType>::addHead(TempType& addMe)
{
	counter++;
	if (root_Head == nullptr)
	{
		root_Head = new Template_Node();
		root_Head->Var = &addMe;
		end_Tail = root_Head;
		end_Tail->Next =nullptr;
	}
	else
	{
		Template_Node* New_Head = new Template_Node();
		New_Head->Var = &addMe;
		New_Head->Next = root_Head;
		root_Head = New_Head;
		
	}
	
	
}
template <class TempType>
void Template_Single_Linked_List<TempType>::addTail(TempType& addMe)
{
	counter++;
	if (root_Head == nullptr)
	{
		root_Head = new Template_Node();
		root_Head->Var = &addMe;
		end_Tail = root_Head->Next = root_Head;
		end_Tail->Next = nullptr;
	}
	else
	{
		Template_Node* New_Tail = new Template_Node();
		New_Tail->Var = &addMe;
		New_Tail->Next = nullptr;
		end_Tail->Next = New_Tail;
		end_Tail=New_Tail;
		
	}
	
	
}
template <class TempType> void
Template_Single_Linked_List<TempType>::EmptyList()
{
	Template_Node* temp = nullptr;
	while (root_Head != nullptr)
	{
		temp = root_Head;
	
		root_Head = root_Head->Next;
		// deletes node but acutal var it was point to, becuase just held a memory address
		delete temp;
	}
	root_Head = nullptr;
	counter = 0;
}

template <class TempType> void
Template_Single_Linked_List<TempType>::Insert(LinkedList_Iter<TempType>& index, TempType& v)
{
	if (index.CurrentNode == root_Head &&  root_Head != nullptr)
	{
		addHead(v);
		index.CurrentNode = root_Head;
	}
	else if (index.PrevNode != nullptr)
	{
		Template_Node* nNode = new Template_Node;
		nNode->Var = &v;
		nNode->Next = index.CurrentNode;
		index.PrevNode->Next = nNode;
		index.CurrentNode = nNode;
	}
	counter++;
}

template <class TempType> void
Template_Single_Linked_List<TempType>::remove(LinkedList_Iter<TempType>& index)
{
	if (root_Head != nullptr && index.CurrentNode == root_Head)
	{
		root_Head = index.CurrentNode->Next;
		delete index.CurrentNode;
		index.CurrentNode = root_Head;
		counter--;

	}
	else if (index.CurrentNode)
	{

		
		index.PrevNode->Next = index.CurrentNode->Next;
		delete index.CurrentNode;
		index.CurrentNode = index.PrevNode->Next;
		
		counter--;
	}
}
template <class TempType> TempType&
Template_Single_Linked_List<TempType>::Drop(LinkedList_Iter<TempType>& index)
{
	TempType*returnPointer = nullptr;
	if (root_Head != nullptr && index.CurrentNode == root_Head)
	{
		root_Head = index.CurrentNode->Next;
		returnPointer= index.CurrentNode->Var;
		delete  index.CurrentNode;
		index.CurrentNode = root_Head;
		counter--;

	}
	else if (index.CurrentNode)
	{


		index.PrevNode->Next = index.CurrentNode->Next;
		returnPointer = index.CurrentNode->Var;
		delete  index.CurrentNode;
		index.CurrentNode = index.PrevNode->Next;

		counter--;
	}
	if(DropCallBackFuncptr)
	this->DropCallBackFuncptr(*returnPointer);
	return *returnPointer;
}
template <class TempType>
 class LinkedList_Iter
{
	    friend class Template_Single_Linked_List <TempType>;

	    Template_Single_Linked_List<TempType>* list;

	    typename Template_Single_Linked_List<TempType>::Template_Node* CurrentNode;
	    typename Template_Single_Linked_List<TempType>::Template_Node* PrevNode;
public:	
	LinkedList_Iter(Template_Single_Linked_List<TempType>& listToIterate);

	void begin();

	bool end();


	LinkedList_Iter<TempType>& operator++();
	LinkedList_Iter<TempType>& operator++(int);
	TempType& current() const;
 };






 template <class TempType> LinkedList_Iter<TempType>::
LinkedList_Iter(Template_Single_Linked_List<TempType>& listToIterate)
 {
	 list = &listToIterate;
	 begin();
 }

 template <class TempType> void LinkedList_Iter<TempType>::
	 begin()
 {
	 CurrentNode = list->root_Head;
	 PrevNode = nullptr;
 }

 template <class TempType> bool LinkedList_Iter<TempType>::
	end()
 {
	 return(!CurrentNode);
 }

 template <class TempType> LinkedList_Iter<TempType>&  LinkedList_Iter<TempType>::
	 operator++()
 {
	 if (CurrentNode != nullptr && list->counter != 0)
	 {
		 PrevNode = CurrentNode;
		 CurrentNode = CurrentNode->Next;


	 }
	 return *this;
 }
 template <class TempType> LinkedList_Iter<TempType>&   LinkedList_Iter<TempType>::
	 operator++(int)
 {
	 return ++(*(this));
 }
 template <class TempType> TempType&  LinkedList_Iter<TempType>::
	current() const
 {
	 return(*(CurrentNode->Var));
 }
 