#pragma once

#include "Rect.h"
#include "Colors.h"
#include "Graphics.h"

class Brick
{
public:
	Brick(Vec2i& pos, Color c);
	void Draw(Graphics& gfx) const;

	static constexpr int width = 50;
	static constexpr int height = 20;

	bool operator==(const Brick& rhs);
private:
	Recti hitbox;
	Recti fullColorRect;
	Color c;
	Color border;
};

