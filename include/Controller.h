#include "Board.h"
#include <iostream>

class Controller
{
public:
	Controller() : m_read(true), m_out(false) {}

	void run();

private:
	bool m_read;
	bool m_out;
};