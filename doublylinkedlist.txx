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
template<class T>
typename DoublyLinkedList<T>::Iterator& 
DoublyLinkedList<T>::Iterator::operator++() 
{ 
	// ToDo
	
}

template<class T>
typename DoublyLinkedList<T>::Iterator  
DoublyLinkedList<T>::Iterator::operator++(int) 
{ 
	// ToDo
	
}

template<class T>
typename DoublyLinkedList<T>::Iterator& 
DoublyLinkedList<T>::Iterator::operator--() 
{ 
	// ToDo
	 
}

template<class T>
typename DoublyLinkedList<T>::Iterator  
DoublyLinkedList<T>::Iterator::operator--(int) 
{ 
	// ToDo
	
}


/*
 * Reverse Iterator
 */
template<class T>
typename DoublyLinkedList<T>::Reverse_Iterator&
DoublyLinkedList<T>::Reverse_Iterator::operator++() 
{ 
	// ToDo
	
}

template<class T>
typename DoublyLinkedList<T>::Reverse_Iterator
DoublyLinkedList<T>::Reverse_Iterator::operator++(int)
{ 
	// ToDo
	
}

template<class T>
typename DoublyLinkedList<T>::Reverse_Iterator&
DoublyLinkedList<T>::Reverse_Iterator::operator--() 
{ 
	// ToDo
	
}

template<class T>
typename DoublyLinkedList<T>::Reverse_Iterator
DoublyLinkedList<T>::Reverse_Iterator::operator--(int)
{ 
	// ToDo
	
}

/*
 * Doubly linked list
 */
// Default constructor
template<class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
	// ToDo
	
}

// Copy constructor
template<class T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList& source)
{
	//ToDo
}


// Destructor
template<class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
	//ToDo
}


// Assignment operator
template<class T>
DoublyLinkedList<T>& 
DoublyLinkedList<T>::operator = (const DoublyLinkedList<T>& source)
{
	//ToDo	
	
}



// Total number of nodes in the list
template<class T>
int 
DoublyLinkedList<T>::Size() const
{
	//ToDo
	
}


// Insert a new node to the list as the first node
// Return the pointer of new node
template<class T>
typename DoublyLinkedList<T>::Iterator 
//typename Iterator
DoublyLinkedList<T>::InsertFirst(const T& data)
{
	//ToDo
	
}


// Insert a new node to the list as the last node
// Return the pointer of new node
template<class T>
typename DoublyLinkedList<T>::Iterator
DoublyLinkedList<T>::InsertLast(const T & data)
{
	//ToDo
}


// Insert a new node to the list after pos
// Return the pointer of new node
template<class T>
typename DoublyLinkedList<T>::Iterator 
DoublyLinkedList<T>::InsertNext(DoublyLinkedList<T>::Iterator pos, const T & data)
{
	//ToDo
}


// Insert a new node to the list before pos
// Return the pointer of new node
template<class T>
typename DoublyLinkedList<T>::Iterator 
DoublyLinkedList<T>::InsertPrev(Iterator, const T & data)
{
	//ToDo
}


// Delete node at pos in the list
template<class T>
bool 
DoublyLinkedList<T>::DeleteNode(Iterator pos)
{
	//ToDo
}


// Delete first node
template<class T>
bool 
DoublyLinkedList<T>::DeleteFirst()
{
	//ToDo
}


// Delete last node
template<class T>
bool 
DoublyLinkedList<T>::DeleteLast()
{
	//ToDo
}


template<class T>
void 
DoublyLinkedList<T>::Print(bool reverse)
{
	if(reverse)
	{
		for(Reverse_Iterator rit = rBegin(); rit!=rEnd(); rit++)
		{	
			std::cout << *rit << ", ";
		}
	}
	else 
	{		
		for(Iterator it = Begin(); it!=End(); it++)
		{	
			std::cout << *it << ", ";
		}		
	}
	
	std::cout << std::endl;
}

