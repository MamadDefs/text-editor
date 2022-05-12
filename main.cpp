#include "doublylinkedlist.h"
#include "texteditor.h"
#include <iostream>

int main()
{

	TextEditor vi;

	vi.Insert("MMD Defs is cool");
	vi.Insert("MamadDefs.ir");
	vi.Insert("email: ");
	vi.Insert("saoshyant1999@yahoo.com");
	vi.Insert("End line :D");

	vi.Run();

	return 0;
}
