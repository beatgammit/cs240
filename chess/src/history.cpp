#include "history.h"

History::History(){
}

History::~History(){
	this->clear();
}

void History::push(Move tMove) {
	this->moveHistory.push_front(tMove);
}

Move History::pop() {
	Move tMove = this->moveHistory.front();
	this->moveHistory.pop_front();
	return tMove;
}

Move History::popBack() {
	Move tMove = this->moveHistory.back();
	this->moveHistory.pop_back();
	return tMove;
}

bool History::isEmpty() {
	return this->moveHistory.empty();
}

void History::clear(){
}
