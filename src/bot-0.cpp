//============================================================================
// Name        : bot-0.cpp
// Author      : Teddy Legroux
// Version     :
// Copyright   : dowtfyouwant
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include "bot-0.hpp"
#include <windows.h>

#include <unistd.h>
#include <stdio.h>
#include <time.h>

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	unsigned int keycode = VK_ESCAPE;
	cout << "Sending the key..." << endl;
	targetKeyStroke(keycode);

	return 0;
}

