#include "TerminalIcon.h"

TerminalIcon::TerminalIcon() {

}

TerminalIcon::TerminalIcon(float _x, float _y): DesktopIcon("Assets/Images/terminal.png", _x, _y) {

}

TerminalIcon::TerminalIcon(float _x, float _y, float scale) : DesktopIcon("Assets/Images/terminal.png", _x, _y, scale) {

}

void TerminalIcon::Open() {
	window = new Terminal(300, 300);
}