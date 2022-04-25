#include <lev/math/calc.h>

#include <math.h>

using namespace lev;

float calc::abs(float x)
{
	return ::fabsf(x);
}

float calc::mod(float x, float y)
{
	return ::fmodf(x, y);
}

float calc::sqrt(float x)
{
	return ::sqrtf(x);
}

float calc::invsqrt(float x)
{
	return 1.0f / sqrt(x);
}

float calc::pow(float x, float e)
{
	return ::powf(x, e);
}

float calc::exp(float x)
{
	return ::powf(calc::E, x);
}

float calc::sigmoid(float x)
{
	return 1.0f - (1.0f / (1.0f + calc::exp(x)));
}

float calc::log(float x, float b)
{
	return ::logf(x) / ::logf(b);
}

float calc::log2(float x)
{
	return ::log2f(x);
}

float calc::log10(float x)
{
	return ::log10f(x);
}

float calc::ln(float x)
{
	return ::logf(x);
}

float calc::max(float a, float b)
{
	return (a > b) ? a : b;
}

float calc::min(float a, float b)
{
	return (a < b) ? a : b;
}

float calc::clamp(float v, float mn, float mx)
{
	return calc::max(mn, calc::min(mx, v));
}

float calc::sign(float x)
{
	if (x < 0.0f)
		return -1.0f;
	else if (x > 0.0f)
		return 1.0f;

	return 0.0f;
}

float calc::round(float x)
{
	return ::roundf(x);
}

float calc::floor(float x)
{
	return ::floorf(x);
}

float calc::ceil(float x)
{
	return ::ceilf(x);
}

bool calc::within_epsilon(float lhs, float rhs, float epsilon)
{
	float delta = rhs - lhs;
	return ::fabsf(delta) <= epsilon;
}

float calc::approach(float from, float to, float amount)
{
	return (to > from) ? calc::min(from + amount, to) : calc::max(from - amount, to);
}

float calc::lerp(float from, float to, float amount)
{
	return from + ((to - from) * amount);
}

float calc::spring(float from, float to, float bounciness, float tension, float& intermediate)
{
	intermediate = calc::lerp(intermediate, (to - from) * tension, 1.0f / bounciness);
	return intermediate;
}

float calc::sin(float x)
{
	return ::sinf(x);
}

float calc::cos(float x)
{
	return ::cosf(x);
}

float calc::tan(float x)
{
	return ::tanf(x);
}

float calc::asin(float x)
{
	return ::asinf(x);
}

float calc::acos(float x)
{
	return ::acosf(x);
}

float calc::atan(float x)
{
	return ::atanf(x);
}

float calc::atan2(float y, float x)
{
	return ::atan2f(y, x);
}
