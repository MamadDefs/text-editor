#include "texteditor.h"
#include <iostream>
using namespace std;
/**
 * Assignment 2 for COSE213 Data Structures
 *
 * 2022. 4. 4  Won-Ki Jeong (wkjeong@korea.ac.kr)
 *
 */

// Default constructor
TextEditor::TextEditor()
{
	pos = buffer.Begin();
	currLine = 0;
}

TextEditor::~TextEditor()
{
	buffer.~DoublyLinkedList();
}

// Insert a new line after the current position
void TextEditor::Insert(const char *s)
{
	buffer.InsertNext(pos, s);
	pos++;
	currLine++;
}

// Delete the current line
void TextEditor::Delete()
{
	// set up next position
	BufferType::Iterator nextPos = pos;
	nextPos++;
	if (nextPos == buffer.End())
	{
		nextPos--;
		nextPos--;
		currLine--;
	}

	// deleting
	if (buffer.Size() == 0)
		cout << "Buffer is empty";
	else
	{
		buffer.DeleteNode(pos);
	}
	pos = nextPos;
}

// Move one line up
void TextEditor::MoveUp()
{
	--pos;
	--currLine;
}

// Move one line down
void TextEditor::MoveDown()
{
	++pos;
	++currLine;
}

//
// Interactive mode
//
void TextEditor::Run()
{
	string inp;

	while (1)
	{
		cout << "> ";
		getline(cin, inp);

		// ToDo	- implement other functions
		if (inp == "u")
			MoveUp();
		else if (inp == "d")
			MoveDown();
		else if (inp == "p")
			Print();
		else if (inp == "pa")
			PrintAll();
		else if (inp == "r")
			Delete();
		else if (inp == "i")
		{
			string insert_inp;
			cout << "Enter the text: ";
			getline(cin, insert_inp);
			char *p = new char[insert_inp.length()];
			for (int i = 0; i < sizeof(p); i++)
				p[i] = insert_inp[i];
			Insert(p);
			delete p;
		}
		else if (inp == "x")
			exit(0);
		else
		{
			cout << "No such command. Available commands are u(up), d(down), p(print), pa(print all), r (delete), i(insert), and x(exit)" << endl;
		}
	}
}

// ----------------------

// Print the current line with the line number
void TextEditor::Print()
{
	if (buffer.Size() < 1)
	{
		std::cout << "Buffer is empty" << std::endl;
	}
	else
	{
		std::cout << "Current(L" << currLine << ") : " << *pos << std::endl;
	}
}

// Print all with the line number
void TextEditor::PrintAll()
{
	int i = 1;
	for (BufferType::Iterator it = buffer.Begin(); it != buffer.End(); it++)
	{
		cout << "L" << i++ << " :";
		if (i == (currLine + 1))
			cout << "*";
		else
			cout << " ";
		cout << *it << endl;
	}
}
