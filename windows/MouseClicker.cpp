/*
    Author: alexZr
    For non-commercial use only
    Proper English skill recommended during using.
    Please feel free to report bugs/issues if you find any.
    have fun!
*/


#include <iostream>
#include <string>
#include <Windows.h>
#include <cstdlib>

using namespace std;

void ClickLeft(INPUT Input){
	// left down 
	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
	::SendInput(1, &Input, sizeof(INPUT));

	// left up
	::ZeroMemory(&Input, sizeof(INPUT));
	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
	::SendInput(1, &Input, sizeof(INPUT));
}
void ClickRight(INPUT Input) {
	// right down 
	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
	::SendInput(1, &Input, sizeof(INPUT));

	// right up
	::ZeroMemory(&Input, sizeof(INPUT));
	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
	::SendInput(1, &Input, sizeof(INPUT));
}



int main(int argc, char** argv) {

	char leftOrRight = '0';
	int holdMouseBotton = -1;
	cout << "Enter which mouse botton you want to press:\n"
		<< "Left Mouse Botton:  L\nRight Mouse Botton:  R\n";

	cin >> leftOrRight;

	cout << "Do you want to spam the botton, or hold it:\n"
		<< "'0' for spamming, '1' for holding\n";

	cin >> holdMouseBotton;

	cout << "Press F7 to start clicking, then ESC key to quit\n";
	while (GetAsyncKeyState(VK_F7) == 0) { /* Waiting input*/ }

	srand(NULL);
	INPUT Input = { 0 };

	if (leftOrRight == 'L' | leftOrRight == 'l'  ) {
		if (holdMouseBotton == 0) {
			while (GetAsyncKeyState(VK_ESCAPE) == 0) {
				ClickLeft(Input);
				// to simulate human clicking, 
				// setup delay between 50 and 250ms.
				// the numbers are from results of my spamming mouse botton on an online stopwatch
				Sleep(rand() % 200 + 50);		
			}
		}
		else if (holdMouseBotton == 1) {
			// hold LMB
			Input.type = INPUT_MOUSE;
			Input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
			::SendInput(1, &Input, sizeof(INPUT));

			//wait for stop signal
			while (GetAsyncKeyState(VK_ESCAPE) == 0) {}

			// release LMB
			::ZeroMemory(&Input, sizeof(INPUT));
			Input.type = INPUT_MOUSE;
			Input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
			::SendInput(1, &Input, sizeof(INPUT));

		}
		else {
			cout << "Unrecongnized operation: " << holdMouseBotton << endl;
		}
	}
	else if (leftOrRight == 'R' | leftOrRight == 'r') {
		if (holdMouseBotton == 0) {
			while (GetAsyncKeyState(VK_ESCAPE) == 0) {
				ClickRight(Input);
				Sleep(rand() % 200 + 50);
			}
		}
		else if (holdMouseBotton == 1) {
			// hold RMB
			Input.type = INPUT_MOUSE;
			Input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
			::SendInput(1, &Input, sizeof(INPUT));

			//wait for stop signal
			while (GetAsyncKeyState(VK_ESCAPE) == 0) {}

			// release RMB
			::ZeroMemory(&Input, sizeof(INPUT));
			Input.type = INPUT_MOUSE;
			Input.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
			::SendInput(1, &Input, sizeof(INPUT));
		}
		else {
			cout << "Unrecongnized operation: " << holdMouseBotton << endl;
		}
	}
	else {
		cout << "Unknown mouse botton: " << leftOrRight << endl;
	}

	cout << "Clicking simulation ended.\n";
	return 0;
}