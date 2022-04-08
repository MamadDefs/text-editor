#include "doublylinkedlist.h"
#include <iostream>
#include <math.h>

/**
 * Assignment 2 for COSE213 Data Structures
 *
 * 2022. 4. 4  Won-Ki Jeong (wkjeong@korea.ac.kr)
 *
 */

/*
 * Iterator
 */

template <class T>
typename DoublyLinkedList<T>::Iterator &
DoublyLinkedList<T>::Iterator::operator++()
{
	this->current = this->current->rlink;
	return *this;
}

template <class T>
typename DoublyLinkedList<T>::Iterator
DoublyLinkedList<T>::Iterator::operator++(int)
{
	DoublyLinkedList<T>::Iterator temp(*this);
	++(*this);
	return temp;
}

template <class T>
typename DoublyLinkedList<T>::Iterator &
DoublyLinkedList<T>::Iterator::operator--()
{
	this->current = this->current->llink;
	return *this;
}

template <class T>
typename DoublyLinkedList<T>::Iterator
DoublyLinkedList<T>::Iterator::operator--(int)
{
	DoublyLinkedList<T>::Iterator temp(*this);
	--(*this);
	return temp;
}

/*
 * Reverse Iterator
 */

template <class T>
typename DoublyLinkedList<T>::Reverse_Iterator &
DoublyLinkedList<T>::Reverse_Iterator::operator++()
{
	this->current = this->current->llink;
	return *this;
}

template <class T>
typename DoublyLinkedList<T>::Reverse_Iterator
DoublyLinkedList<T>::Reverse_Iterator::operator++(int)
{
	DoublyLinkedList<T>::Reverse_Iterator temp(*this);
	++(*this);
	return temp;
}

template <class T>
typename DoublyLinkedList<T>::Reverse_Iterator &
DoublyLinkedList<T>::Reverse_Iterator::operator--()
{
	this->current = this->current->rlink;
	return *this;
}

template <class T>
typename DoublyLinkedList<T>::Reverse_Iterator
DoublyLinkedList<T>::Reverse_Iterator::operator--(int)
{
	DoublyLinkedList<T>::Reverse_Iterator temp(*this);
	--(*this);
	return temp;
}

/*
 * Doubly linked list
 */
// Default constructor
template <class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
	this->first = new NodeType();
	this->first->rlink = this->first;
	this->first->llink = this->first;
}

// Copy constructor
template <class T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList &source)
{
	this->first = new NodeType();
	this->first->rlink = this->first;
	this->first->llink = this->first;
	NodeType *curr = source.first->rlink;
	while (curr != source.first)
	{
		this->InsertLast(curr->data);
		curr = curr->rlink;
	}
}

// Destructor
template <class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
	while (this->DeleteFirst())
		;
	delete first;
}

// Assignment operator
template <class T>
DoublyLinkedList<T> &
DoublyLinkedList<T>::operator=(const DoublyLinkedList<T> &source)
{
	// deleting the left list and replace it with right list
	while (this->DeleteFirst())
		;
	// inserting nodes
	NodeType *curr = source.first->rlink;
	while (curr != source.first)
	{
		this->InsertLast(curr->data);
		curr = curr->rlink;
	}
	return *this;
}

// Total number of nodes in the list
template <class T>
int DoublyLinkedList<T>::Size() const
{
	int count = 0;
	for (Iterator it = Begin(); it != End(); it++)
		count++;
	return count;
}

// Insert a new node to the list as the first node
// Return the pointer of new node
template <class T>
typename DoublyLinkedList<T>::Iterator
// typename Iterator
DoublyLinkedList<T>::InsertFirst(const T &data)
{
	NodeType *newNode = new NodeType();
	newNode->data = data;
	if (first->rlink == this->first)
	{
		newNode->rlink = first;
		newNode->llink = first;
		first->rlink = newNode;
		first->llink = newNode;
	}
	else
	{
		first->rlink->llink = newNode;
		newNode->rlink = first->rlink;
		newNode->llink = first;
		first->rlink = newNode;
	}
	return newNode;
}

// Insert a new node to the list as the last node
// Return the pointer of new node
template <class T>
typename DoublyLinkedList<T>::Iterator
DoublyLinkedList<T>::InsertLast(const T &data)
{
	NodeType *newNode = new NodeType();
	newNode->data = data;
	if (first->rlink == this->first)
	{
		newNode->rlink = first;
		newNode->llink = first;
		first->rlink = newNode;
		first->llink = newNode;
	}
	else
	{
		first->llink->rlink = newNode;
		newNode->rlink = first;
		newNode->llink = first->llink;
		first->llink = newNode;
	}
	return newNode;
}

// Insert a new node to the list after pos
// Return the pointer of new node
template <class T>
typename DoublyLinkedList<T>::Iterator
DoublyLinkedList<T>::InsertNext(DoublyLinkedList<T>::Iterator pos, const T &data)
{
	NodeType *newNode = new NodeType();
	newNode->data = data;
	newNode->rlink = pos.GetNodePointer()->rlink;
	newNode->llink = pos.GetNodePointer();
	newNode->rlink->llink = newNode;
	newNode->llink->rlink = newNode;
	return ++pos;
}

// Insert a new node to the list before pos
// Return the pointer of new node
template <class T>
typename DoublyLinkedList<T>::Iterator
DoublyLinkedList<T>::InsertPrev(Iterator pos, const T &data)
{
	NodeType *newNode = new NodeType();
	newNode->data = data;
	newNode->rlink = pos.GetNodePointer();
	newNode->llink = pos.GetNodePointer()->llink;
	newNode->rlink->llink = newNode;
	newNode->llink->rlink = newNode;
	return ++pos;
}

// Delete node at pos in the list
template <class T>
bool DoublyLinkedList<T>::DeleteNode(Iterator pos)
{
	if (pos == this->first)
		return false;
	else
	{
		NodeType *tempNode = pos.GetNodePointer();
		pos.GetNodePointer()->rlink->llink = pos.GetNodePointer()->llink;
		pos.GetNodePointer()->llink->rlink = pos.GetNodePointer()->rlink;
		delete tempNode;
		return true;
	}
}

// Delete first node
template <class T>
bool DoublyLinkedList<T>::DeleteFirst()
{
	if (this->Size() == 1)
	{
		NodeType *tempNode = this->first->rlink;
		this->first->rlink = this->first;
		this->first->llink = this->first;
		delete tempNode;
		return true;
	}
	else if (this->Size() > 1)
	{
		NodeType *tempNode = this->first->rlink;
		this->first->rlink->rlink->llink = this->first;
		this->first->rlink = this->first->rlink->rlink;
		delete tempNode;
		return true;
	}
	return false;
}

// Delete last node
template <class T>
bool DoublyLinkedList<T>::DeleteLast()
{
	if (this->Size() == 1)
	{
		NodeType *tempNode = this->first->rlink;
		this->first->rlink = this->first;
		this->first->llink = this->first;
		delete tempNode;
		return true;
	}
	else if (this->Size() > 1)
	{
		NodeType *tempNode = this->first->llink;
		this->first->llink->llink->rlink = this->first;
		this->first->llink = this->first->llink->llink;
		delete tempNode;
		return true;
	}
	return false;
}

template <class T>
void DoublyLinkedList<T>::Print(bool reverse)
{

	if (reverse)
	{
		for (Reverse_Iterator rit = rBegin(); rit != rEnd(); rit++)
		{
			std::cout << *rit << ", ";
		}
	}
	else
	{
		for (Iterator it = Begin(); it != End(); it++)
		{
			std::cout << *it << ", ";
		}
	}

	std::cout << std::endl;
}
