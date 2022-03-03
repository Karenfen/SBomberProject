#include "Tree.h"
#include "TreeState.h"



Tree::Tree(std::unique_ptr <TreeState> p_state): state(std::move(p_state)) { }

void Tree::Move(uint16_t time)
{ 
	state->Grow(this, time); 
}

void Tree::Draw() const { state->Draw(this); }

void Tree::SetState(std::unique_ptr <TreeState> p_state)
{
	state = std::move(p_state);
}