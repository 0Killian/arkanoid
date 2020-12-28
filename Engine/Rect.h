#pragma once

#include "Vec2.h"

template <typename T>
class Rect
{
public:
	Rect(Vec2<T>& pos, const Vec2<T>& end)
		:
		pos(pos)
	{
		T x;
		T y;
		T width;
		T height;
		if (pos.x > end.x)
		{
			x = end.x;
			width = pos.x - x;
		}
		else
		{
			x = pos.x;
			width = end.x - x;
		}

		if (pos.y > end.y)
		{
			y = end.y;
			height = pos.y - end.y;
		}
		else
		{
			y = pos.y;
			height = end.y - end.y;
		}
		*this = Rect<T>(Vec2<T>(x, y), width, height);
	}

	Rect(const Vec2<T>& pos, const T width, const T height)
		:
		pos(pos),
		w(width),
		h(height)
	{}

	Vec2<T> pos;
	T w;
	T h;
};

typedef Rect<float> Rectf;