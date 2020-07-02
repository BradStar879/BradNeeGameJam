#include "Terminal.h"

Terminal::Terminal() {

}

Terminal::Terminal(float _x, float _y): DesktopWindow("Assets/Images/Terminal_Concept.png", _x, _y) {
	curString = "";
	oldStrings = "";
	shift = false;
}

void Terminal::Update() {
	if (IsSelected()) {
		CheckShift();
		AcceptInput();
	}
	if (Mouse::ButtonDown(GLFW_MOUSE_BUTTON_RIGHT)) {
		cout << oldStrings << curString << endl;
	}
	DesktopWindow::Update();
}

void Terminal::CheckShift() {
	if (Keyboard::Key(GLFW_KEY_LEFT_SHIFT) || Keyboard::Key(GLFW_KEY_RIGHT_SHIFT)) {
		shift = true;
	}
	else shift = false;
}

void Terminal::AcceptInput() {
	if (Keyboard::KeyDown(GLFW_KEY_A)) {
		if (shift) curString += "A";
		else curString += "a";
	}
	if (Keyboard::KeyDown(GLFW_KEY_B)) {
		if (shift) curString += "B";
		else curString += "b";
	}
	if (Keyboard::KeyDown(GLFW_KEY_C)) {
		if (shift) curString += "C";
		else curString += "c";
	}
	if (Keyboard::KeyDown(GLFW_KEY_D)) {
		if (shift) curString += "D";
		else curString += "d";
	}
	if (Keyboard::KeyDown(GLFW_KEY_E)) {
		if (shift) curString += "E";
		else curString += "e";
	}
	if (Keyboard::KeyDown(GLFW_KEY_F)) {
		if (shift) curString += "F";
		else curString += "f";
	}
	if (Keyboard::KeyDown(GLFW_KEY_G)) {
		if (shift) curString += "G";
		else curString += "g";
	}
	if (Keyboard::KeyDown(GLFW_KEY_H)) {
		if (shift) curString += "H";
		else curString += "h";
	}
	if (Keyboard::KeyDown(GLFW_KEY_I)) {
		if (shift) curString += "I";
		else curString += "i";
	}
	if (Keyboard::KeyDown(GLFW_KEY_J)) {
		if (shift) curString += "J";
		else curString += "j";
	}
	if (Keyboard::KeyDown(GLFW_KEY_K)) {
		if (shift) curString += "K";
		else curString += "k";
	}
	if (Keyboard::KeyDown(GLFW_KEY_L)) {
		if (shift) curString += "L";
		else curString += "l";
	}
	if (Keyboard::KeyDown(GLFW_KEY_M)) {
		if (shift) curString += "M";
		else curString += "m";
	}
	 if (Keyboard::KeyDown(GLFW_KEY_N)) {
		if (shift) curString += "N";
		else curString += "n";
	}
	if (Keyboard::KeyDown(GLFW_KEY_O)) {
		if (shift) curString += "O";
		else curString += "o";
	}
	if (Keyboard::KeyDown(GLFW_KEY_P)) {
		if (shift) curString += "P";
		else curString += "p";
	}
	if (Keyboard::KeyDown(GLFW_KEY_Q)) {
		if (shift) curString += "Q";
		else curString += "q";
	}
	if (Keyboard::KeyDown(GLFW_KEY_R)) {
		if (shift) curString += "R";
		else curString += "r";
	}
	if (Keyboard::KeyDown(GLFW_KEY_S)) {
		if (shift) curString += "S";
		else curString += "s";
	}
	if (Keyboard::KeyDown(GLFW_KEY_T)) {
		if (shift) curString += "T";
		else curString += "t";
	}
	if (Keyboard::KeyDown(GLFW_KEY_U)) {
		if (shift) curString += "U";
		else curString += "u";
	}
	if (Keyboard::KeyDown(GLFW_KEY_V)) {
		if (shift) curString += "V";
		else curString += "v";
	}
	if (Keyboard::KeyDown(GLFW_KEY_W)) {
		if (shift) curString += "W";
		else curString += "w";
	}
	if (Keyboard::KeyDown(GLFW_KEY_X)) {
		if (shift) curString += "X";
		else curString += "x";
	}
	if (Keyboard::KeyDown(GLFW_KEY_Y)) {
		if (shift) curString += "Y";
		else curString += "y";
	}
	if (Keyboard::KeyDown(GLFW_KEY_Z)) {
		if (shift) curString += "Z";
		else curString += "z";
	}
	if (Keyboard::KeyDown(GLFW_KEY_SPACE)) {
		curString += " ";
	}
	if (Keyboard::KeyDown(GLFW_KEY_1)) {
		if (shift) curString += "!";
		else curString += "1";
	}
	if (Keyboard::KeyDown(GLFW_KEY_2)) {
		if (shift) curString += "@";
		else curString += "2";
	}
	if (Keyboard::KeyDown(GLFW_KEY_3)) {
		if (shift) curString += "#";
		else curString += "3";
	}
	if (Keyboard::KeyDown(GLFW_KEY_4)) {
		if (shift) curString += "$";
		else curString += "4";
	}
	if (Keyboard::KeyDown(GLFW_KEY_5)) {
		if (shift) curString += "%";
		else curString += "5";
	}
	if (Keyboard::KeyDown(GLFW_KEY_6)) {
		if (shift) curString += "^";
		else curString += "6";
	}
	if (Keyboard::KeyDown(GLFW_KEY_7)) {
		if (shift) curString += "&";
		else curString += "7";
	}
	if (Keyboard::KeyDown(GLFW_KEY_8)) {
		if (shift) curString += "*";
		else curString += "8";
	}
	if (Keyboard::KeyDown(GLFW_KEY_9)) {
		if (shift) curString += "(";
		else curString += "9";
	}
	if (Keyboard::KeyDown(GLFW_KEY_0)) {
		if (shift) curString += ")";
		else curString += "0";
	}
	if (Keyboard::KeyDown(GLFW_KEY_BACKSPACE) || Keyboard::KeyDown(GLFW_KEY_DELETE)) {
		if (curString != "") curString = curString.substr(0, curString.size()-1);
	}
	if (Keyboard::KeyDown(GLFW_KEY_ENTER)) {
		oldStrings += curString + "\n";
		cout << curString << endl;
		Parse();
		curString = "";
	}

}

void Terminal::Parse() {
	if (curString == "") {

	}
	else {
		vector<string> tokens;
		/*char * token = strtok(curString, " ");
		tokens.push_back(token);
		while (token != NULL) {
			token = strtok(curString, " ");
			tokens.push_back(token);
		}
		for (int i = 0; i < tokens.size(); i++) {
			cout << tokens[i] << "---" << endl;
		}*/
	}
}

void Terminal::Help() {

}

