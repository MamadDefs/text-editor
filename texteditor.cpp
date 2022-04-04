#include "texteditor.h"
#include <iostream>

/**
 * Assignment 2 for COSE213 Data Structures
 *
 * 2022. 4. 4  Won-Ki Jeong (wkjeong@korea.ac.kr)
 *
 */

/*
// Default constructor
TextEditor::TextEditor()
{
	//ToDo
}

TextEditor::~TextEditor()
{
	//ToDo
}

// Insert a new line after the current position
void TextEditor::Insert(const char* s)
{
	// ToDo
}

// Delete the current line
void TextEditor::Delete()
{
	// ToDo
}

// Move one line up
void TextEditor::MoveUp()
{
	// ToDo
}

// Move one line down
void TextEditor::MoveDown()
{
	// ToDo
}

//
// Interactive mode
//
void TextEditor::Run()
{
	string inp;

	while(1)
	{
		cout << "> ";
		getline(cin, inp);

		// ToDo	- implement other functions
		if(inp == "u") MoveUp();
		else if(inp == "x") exit(0);
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
	if(buffer.Size() < 1) {
		std::cout << "Buffer is empty" << std::endl;
	}
	else {
		std::cout << "Current(L" << currLine << ") : " << *pos << std::endl;
	}
}

// Print all with the line number
void TextEditor::PrintAll()
{
	int i=1;
	for(BufferType::Iterator it=buffer.Begin(); it != buffer.End(); it++)
	{
		cout << "L" << i++ << " :";
		if(i == (currLine+1)) cout << "*";
		else cout << " ";
		cout << *it << endl;
	}
}
*/