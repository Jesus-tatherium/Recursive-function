#include "GestionVecteur.h"
#include "stdafx.h"
#include <math.h>

//return nearest int
int roundNear(float f)
{
	int a = ceilf(f);
	int b = (int)f;

	if (fabsf(f - a) <= fabsf(f - b))
	{
		return a;
	}
	else
	{
		return b;
	}
}

// 0 -> soustraction
// 1 -> addition
sfVector2f AddSub2f(sfVector2f a, sfVector2f b, int type)
{
	sfVector2f ret = a;
	if (type == 0)
	{
		ret.x -= b.x;
		ret.y -= b.y;
	}
	else
	{
		ret.x += b.x;
		ret.y += b.y;
	}
	return ret;
}

// 0 -> division
// 1 -> multiplication
sfVector2f MultDiv2f(sfVector2f a, sfVector2f b, int type)
{
	sfVector2f ret = a;
	if (type == 0)
	{
		ret.x /= b.x;
		ret.y /= b.y;
	}
	else
	{
		ret.x *= b.x;
		ret.y *= b.y;
	}
	return ret;
}

// 0 -> soustraction
// 1 -> addition
sfVector2f AddSubInt(sfVector2f a, int b, int type)
{
	sfVector2f ret = a;
	if (type == 0)
	{
		ret.x -= b;
		ret.y -= b;
	}
	else
	{
		ret.x += b;
		ret.y += b;
	}
	return ret;
}

// 0 -> division
// 1 -> multiplication
sfVector2f MultDivInt(sfVector2f a, int b, int type)
{
	sfVector2f ret = a;
	if (type == 0)
	{
		ret.x /= b;
		ret.y /= b;
	}
	else
	{
		ret.x *= b;
		ret.y *= b;
	}
	return ret;
}

// 0 -> division
// 1 -> multiplication
sfVector2f MultDivFloat(sfVector2f a, float b, int type)
{
	sfVector2f ret = a;
	if (type == 0)
	{
		ret.x /= b;
		ret.y /= b;
	}
	else
	{
		ret.x *= b;
		ret.y *= b;
	}
	return ret;
}


void PrintVect2f(sfVector2f a)
{
	printf("%f %f\n", a.x, a.y);
}

void PrintVect2i(sfVector2i a)
{
	printf("%d %d\n", a.x, a.y);
}

