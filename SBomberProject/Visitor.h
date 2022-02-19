#pragma once

class Bomb;
class Plane;

class Visitor
{
public:

	virtual void log(Bomb* b) = 0;

	virtual void log(Plane* p) = 0;

};


class LogVisitor : public Visitor
{
public:

	void log(Bomb* b) override;

	void log(Plane* p) override;

};