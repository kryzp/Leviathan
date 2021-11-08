#include <lev/math/vec2.h>
#include <lev/math/calc.h>
#include <lev/math/float2.h>

using namespace Lev;

Vec2::Vec2()
{
}

Vec2::Vec2(float x)
	: x(x)
	, y(x)
{
}

Vec2::Vec2(float x, float y)
	: x(x)
	, y(y)
{
}

Float2 Vec2::to_float2() const
{
	return Float2(x, y);
}

float Vec2::length() const
{
	return Calc::sqrt(length_squared());
}

float Vec2::length_squared() const
{
	return (x * x) + (y * y);
}

Vec2 Vec2::normalized() const
{
	float len = length();

	return Vec2(
		x / len,
		y / len
	);
}

float Vec2::dot(const Vec2& a, const Vec2& b)
{
	return (a.x * b.x) + (a.y * b.y);
}

bool Vec2::operator == (const Vec2& other) const { return x == other.x && y == other.y; }
bool Vec2::operator != (const Vec2& other) const { return !(*this == other); }

Vec2 Vec2::operator + (const Vec2& other) const { return Vec2(x + other.x, y + other.y); }
Vec2 Vec2::operator - (const Vec2& other) const { return Vec2(x - other.x, y - other.y); }
Vec2 Vec2::operator - ()                  const { return Vec2(-x, -y); }
Vec2 Vec2::operator * (const Vec2& other) const { return Vec2(x * other.x, y * other.y); }
Vec2 Vec2::operator / (const Vec2& other) const { return Vec2(x / other.x, y / other.y); }

Vec2& Vec2::operator += (const Vec2& other) { x += other.x; y += other.y; return *this; }
Vec2& Vec2::operator -= (const Vec2& other) { x -= other.x; y -= other.y; return *this; }
Vec2& Vec2::operator *= (const Vec2& other) { x *= other.x; y *= other.y; return *this; }
Vec2& Vec2::operator /= (const Vec2& other) { x /= other.x; y /= other.y; return *this; }

const Vec2 Vec2::ZERO  = Vec2(0, 0);
const Vec2 Vec2::ONE   = Vec2(1, 1);
const Vec2 Vec2::LEFT  = Vec2(-1, 0);
const Vec2 Vec2::RIGHT = Vec2(1, 0);
const Vec2 Vec2::UP    = Vec2(0, -1);
const Vec2 Vec2::DOWN  = Vec2(0, 1);
