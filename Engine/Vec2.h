#pragma once

template <typename T>
class Vec2
{
public:
	Vec2(T x, T y)
		:
		x(x),
		y(y)
	{}

	Vec2<T>& operator+(const Vec2<T>& rhs)
	{
		return Vec2<T>(x + rhs.x, y + rhs.y);
	}

	Vec2<T>& operator+=(const Vec2<T>& rhs)
	{
		return *this = *this + rhs;
	}

	Vec2<T>& operator +=(const T& rhs)
	{
		return *this = *this + rhs;
	}

	Vec2<T>& operator+(const T& rhs)
	{
		return Vec2<T>(x + rhs, y + rhs);
	}

	T x;
	T y;
};

typedef Vec2<float> Vec2f;