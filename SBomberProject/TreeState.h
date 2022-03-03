#pragma once

#include <iostream>

class Tree;

class TreeState
{
public:

	TreeState() : passedTime(0) {}
	virtual ~TreeState() { }

	virtual void Draw(const Tree* tree) const = 0;
	virtual void Grow(Tree* tree, uint16_t time) = 0;

protected:

	uint64_t passedTime;
};

//============================================

class SmallTree : public TreeState
{
public:

	void Draw(const Tree* tree) const override;
	void Grow(Tree* tree, uint16_t time) override;
};

//============================================

class MiddleTree : public TreeState
{
public:

	void Draw(const Tree* tree) const override;
	void Grow(Tree* tree, uint16_t time) override;
};

//============================================

class BigTree : public TreeState
{
public:

	void Draw(const Tree* tree) const override;
	void Grow(Tree* tree, uint16_t time) override;
};