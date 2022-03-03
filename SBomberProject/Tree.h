#pragma once

#include <memory>

#include "DynamicObject.h"



class TreeState;

class Tree : public DynamicObject
{
private:

	std::unique_ptr <TreeState> state;

public:

	Tree(std::unique_ptr <TreeState> p_state);

	void Move(uint16_t time) override;

	void Draw() const override;

	void SetState(std::unique_ptr <TreeState> p_state);
};