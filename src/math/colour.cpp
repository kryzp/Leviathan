#include <lev/math/colour.h>

using namespace lev;

Colour::Colour()
	: r(0)
	, g(0)
	, b(0)
	, a(0)
{
}

Colour::Colour(float r, float g, float b, float a)
	: r(r)
	, g(g)
	, b(b)
	, a(a)
{
}

Colour::Colour(u32 packed)
	: r((u8)(packed >> 24) / 255.0f)
	, g((u8)(packed >> 16) / 255.0f)
	, b((u8)(packed >> 8) / 255.0f)
	, a((u8)(packed >> 0) / 255.0f)
{
}

u32 Colour::pack(const Colour& colour)
{
	u8 r = (u8)(colour.r * 255);
	u8 g = (u8)(colour.g * 255);
	u8 b = (u8)(colour.b * 255);
	u8 a = (u8)(colour.a * 255);

	return
		r << 24 |
		g << 16 |
		b << 8  |
		a << 0;
}

Colour Colour::from_u8(u8 r, u8 g, u8 b, u8 a)
{
	return Colour(
		(float)r / 255.0f,
		(float)g / 255.0f,
		(float)b / 255.0f,
		(float)a / 255.0f
	);
}

void Colour::premultiply()
{
	r *= a;
	g *= a;
	b *= a;
}

Colour Colour::premultiplied() const
{
	return Colour(
		r * a,
		g * a,
		b * a,
		a
	);
}

bool Colour::operator == (const Colour& other) const
{
	return (
		r == other.r &&
		g == other.g &&
		b == other.b &&
		a == other.a
	);
}

bool Colour::operator != (const Colour& other) const
{
	return !(*this == other);
}

Colour Colour::operator - () const
{
	return Colour(
		1.0f - r,
		1.0f - g,
		1.0f - b,
		a
	);
}

Colour Colour::operator * (float mult) const
{
	return Colour(
		(u8)((float)r * mult),
		(u8)((float)g * mult),
		(u8)((float)b * mult),
		(u8)((float)a * mult)
	);
}

Colour& Colour::operator *= (float mult)
{
	*this = *this * mult;
	return *this;
}

const Colour& Colour::empty()   { static const Colour EMPTY   = Colour(0, 0, 0, 0); return EMPTY;   }
const Colour& Colour::black()   { static const Colour BLACK   = Colour(0, 0, 0, 1); return BLACK;   }
const Colour& Colour::white()   { static const Colour WHITE   = Colour(1, 1, 1, 1); return WHITE;   }
const Colour& Colour::red()     { static const Colour RED     = Colour(1, 0, 0, 1); return RED;     }
const Colour& Colour::green()   { static const Colour GREEN   = Colour(0, 1, 0, 1); return GREEN;   }
const Colour& Colour::blue()    { static const Colour BLUE    = Colour(0, 0, 1, 1); return BLUE;    }
const Colour& Colour::yellow()  { static const Colour YELLOW  = Colour(1, 1, 0, 1); return YELLOW;  }
const Colour& Colour::magenta() { static const Colour MAGENTA = Colour(1, 0, 1, 1); return MAGENTA; }
const Colour& Colour::cyan()    { static const Colour CYAN    = Colour(0, 1, 1, 1); return CYAN;    }
