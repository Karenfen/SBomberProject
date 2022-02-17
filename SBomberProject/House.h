#pragma once

#include <stdint.h>

#include "DestroyableGroundObject.h"


class House : public DestroyableGroundObject
{
public:

	House();

	bool __fastcall isInside(double x1, double x2) const override;

	inline uint16_t GetScore() const override { return score; }

	void Draw() const override;

private:

	friend class HouseBuilderA;
	friend class HouseBuilderB;
	friend class HouseBuilderC;

	char look[7][14];
	const uint16_t score = 40;
};


class HouseBuilder
{
public:
	
	virtual ~HouseBuilder(){}
	HouseBuilder() : m_house(nullptr) {}

	virtual void CriateHouse() {}
	virtual House* GetHouse() { return m_house; }

	virtual void BuildRuf() {}
	virtual void BuilWalls() {}
	virtual void BuildFloor() {}
	virtual void BuilWindows() {}
	virtual void BuilDoor() {}
	virtual void BuilPipe() {}

protected:

	House* m_house;
};

class HouseBuilderA : public HouseBuilder
{
public:

	void CriateHouse() override { m_house = new House; }

	void BuildRuf() override 
	{
		m_house->look[0][4] = '#';
		m_house->look[0][5] = '#';
		m_house->look[0][6] = '#';
		m_house->look[0][7] = '#';
		m_house->look[0][8] = '#';
		m_house->look[0][9] = '#';
		m_house->look[1][2] = '#';
		m_house->look[1][3] = '#';
		m_house->look[1][4] = '#';
		m_house->look[1][9] = '#';
		m_house->look[1][10] = '#';
		m_house->look[1][11] = '#';
	}
	void BuilWalls() override
	{
		for (size_t i = 0; i < 14; i++)
		{
			m_house->look[2][i] = '#';
		}

		for (size_t i = 0; i < 14; i++)
		{
			m_house->look[6][i] = '#';
		}

		for (size_t i = 2; i < 7; i++)
		{
			m_house->look[i][0] = '#';
		}

		for (size_t i = 2; i < 7; i++)
		{
			m_house->look[i][13] = '#';
		}

	}
	void BuilPipe() override
	{
		m_house->look[0][11] = '#';
		m_house->look[1][11] = '#';

	}
    void BuildFloor() override 
	{
		for (size_t i = 0; i < 14; i++)
		{
			m_house->look[6][i] = '#';
		}
	}

};

class HouseBuilderB : public HouseBuilder
{
public:

	void CriateHouse() override { m_house = new House; }

	void BuilWalls() override
	{
		for (size_t i = 0; i < 14; i++)
		{
			m_house->look[2][i] = '#';
		}

		for (size_t i = 0; i < 14; i++)
		{
			m_house->look[6][i] = '#';
		}

		for (size_t i = 2; i < 7; i++)
		{
			m_house->look[i][0] = '#';
		}

		for (size_t i = 2; i < 7; i++)
		{
			m_house->look[i][13] = '#';
		}

	}
	void BuilWindows() override
	{
		m_house->look[4][3] = '#';
		m_house->look[4][4] = '#';
		m_house->look[4][6] = '#';
		m_house->look[4][7] = '#';

	}
	void BuilDoor() override
	{
		m_house->look[4][10] = '#';
		m_house->look[4][11] = '#';
		m_house->look[5][10] = '#';
		m_house->look[5][11] = '#';
	}
	void BuildFloor() override
	{
		for (size_t i = 0; i < 14; i++)
		{
			m_house->look[6][i] = '#';
		}
	}
};

class HouseBuilderC : public HouseBuilder
{
public:

	void CriateHouse() override { m_house = new House; }

	void BuilWalls() override
	{
		for (size_t i = 0; i < 14; i++)
		{
			m_house->look[2][i] = '#';
		}

		for (size_t i = 0; i < 14; i++)
		{
			m_house->look[6][i] = '#';
		}

		for (size_t i = 2; i < 7; i++)
		{
			m_house->look[i][0] = '#';
		}

		for (size_t i = 2; i < 7; i++)
		{
			m_house->look[i][13] = '#';
		}

	}
	void BuilWindows() override
	{
		m_house->look[4][3] = '#';
		m_house->look[4][4] = '#';
		m_house->look[4][6] = '#';
		m_house->look[4][7] = '#';

	}
	void BuilDoor() override
	{
		m_house->look[4][10] = '#';
		m_house->look[4][11] = '#';
		m_house->look[5][10] = '#';
		m_house->look[5][11] = '#';
	}
	void BuildFloor() override
	{
		for (size_t i = 0; i < 14; i++)
		{
			m_house->look[6][i] = '#';
		}
	}
	void BuildRuf() override
	{
		m_house->look[0][4] = '#';
		m_house->look[0][5] = '#';
		m_house->look[0][6] = '#';
		m_house->look[0][7] = '#';
		m_house->look[0][8] = '#';
		m_house->look[0][9] = '#';
		m_house->look[1][2] = '#';
		m_house->look[1][3] = '#';
		m_house->look[1][4] = '#';
		m_house->look[1][9] = '#';
		m_house->look[1][10] = '#';
		m_house->look[1][11] = '#';
	}

};

class HouseDirector
{
public:

	House* CreateHouse(HouseBuilder& builder)
	{
		builder.CriateHouse();
		builder.BuildFloor();
		builder.BuilWalls();
		builder.BuildRuf();
		builder.BuilDoor();
		builder.BuilWindows();
		builder.BuilPipe();

		return builder.GetHouse();
	}

};