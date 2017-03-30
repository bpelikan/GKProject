#pragma once
class Coordinate
{
public:
	Coordinate(bool v = true);
	~Coordinate();
	void Draw();
private:
	bool visible;
};

