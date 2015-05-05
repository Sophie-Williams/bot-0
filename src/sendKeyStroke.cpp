/*
 * send_keystroke.cpp
 *
 *  Created on: 5 mai 2015
 *      Author: Teddy
 */

#include <iostream>

#include "bot-0.hpp"
#include <windows.h>
#include <Winuser.h>

void sendKeyStroke(unsigned int keycode, HWND handle)
{

	// PostMessage takes a handle to a window (wich we need to acquire above)
	// a message (key down), a WPARAM (the key pressed), and an LPARAM (apparently unused here).
	if(!PostMessage(handle, WM_KEYDOWN, keycode, 0))
		std::cout << "Couldn't send KEYDOWN" << std::endl;
	if(!PostMessage(handle, WM_KEYUP, keycode, 0))
		std::cout << "Couldn't send KEYUP" << std::endl;
	else
		std::cout << "Message posted." << std::endl;

	return;
}
