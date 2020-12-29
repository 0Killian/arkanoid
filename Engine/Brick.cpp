#include "Brick.h"

Brick::Brick(Vec2i& pos, Color c)
	:
	hitbox(pos + 1, width - 1, height - 1),
	c(c),
	border(std::max(c.GetR() - 70, 0), std::max(c.GetG() - 70, 0), std::max(c.GetB() - 70, 0)),
	fullColorRect(pos + 3, width - 3, height - 3)
{
	
}

void Brick::Draw(Graphics& gfx) const
{
	gfx.DrawRect(hitbox, border);
	gfx.DrawRect(fullColorRect, c);
}

bool Brick::operator==(const Brick& rhs)
{
	return hitbox == rhs.hitbox && c == rhs.c;
}
