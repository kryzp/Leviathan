#pragma once

namespace Lev
{
	struct Float2;

	struct Vec2
	{
		static const Vec2 ZERO;
		static const Vec2 ONE;
		static const Vec2 LEFT;
		static const Vec2 RIGHT;
		static const Vec2 UP;
		static const Vec2 DOWN;

		float x;
		float y;

		Vec2();
		Vec2(float x);
		Vec2(float x, float y);

		Float2 to_float2() const;

		float length() const;
		float length_squared() const;

		Vec2 normalized() const;

		static float dot(const Vec2& a, const Vec2& b);

		bool operator == (const Vec2& other) const;
		bool operator != (const Vec2& other) const;

		Vec2 operator + (const Vec2& other) const;
		Vec2 operator - (const Vec2& other) const;
		Vec2 operator - () const;
		Vec2 operator * (const Vec2& other) const;
		Vec2 operator / (const Vec2& other) const;

		Vec2& operator += (const Vec2& other);
		Vec2& operator -= (const Vec2& other);
		Vec2& operator *= (const Vec2& other);
		Vec2& operator /= (const Vec2& other);
	};
}
