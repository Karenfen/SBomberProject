#pragma once

#include <stdint.h>
#include <vector>
#include <string>

#include "DestroyableGroundObject.h"
#include "Mediator.h"



class Tank : public DestroyableGroundObject
{
public:

	bool __fastcall isInside(double x1, double x2) const override;

	inline uint16_t GetScore() const override { return score; }

	void Draw() const override;

	void SetMessages();

	void SetMediator(std::unique_ptr<Mediator> pMediator);

private:

	void SendMessage() const;

	static std::unique_ptr<Mediator> m_mediator;

	const uint16_t score = 30;

	static std::vector<std::string> messages;
};

