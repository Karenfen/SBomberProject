#pragma once

#include <stdint.h>
#include <vector>
#include <string>

#include "DestroyableGroundObject.h"
#include "Mediator.h"



class Tank : public DestroyableGroundObject
{
public:

	Tank(std::shared_ptr<Mediator> pMediator) : m_mediator(pMediator){ }

	bool __fastcall isInside(double x1, double x2) const override;

	inline uint16_t GetScore() const override { return score; }

	void Draw() const override;

private:

	void SendMessage() const;

	std::shared_ptr<Mediator> m_mediator;

	const uint16_t score = 30;

	static std::vector<std::string> messages;
};

