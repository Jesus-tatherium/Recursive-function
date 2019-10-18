#include "stdafx.h"
#include <stdlib.h>
#include <math.h>
#include "GestionImage.h"
#include "GestionVecteur.h"
#include "GestionTexte.h"

#define WIDTH 1024
#define HEIGHT 768
#define PI 3.1415926535897932384
#define DEG2RAD PI / 180.0f

#define MODIF 0.87f

sfRenderWindow* window = 0;
sfEvent event;
float angleSize;
float length;
float limit;


float norme(sfVector2f a)
{
	return sqrtf(a.x * a.x + a.y * a.y);
}

sfVector2f Rotatage(sfVector2f v, float angle)
{
	sfVector2f vOut;
	float cosA = cosf(angle);
	float sinA = sinf(angle);

	vOut.x = v.x * cosA - v.y * sinA;
	vOut.y = v.y * cosA + v.x * sinA;
	return vOut;
}

sfVector2f RotatageAutour(sfVector2f v, sfVector2f pivot, float angle)
{
	v.x -= pivot.x;
	v.y -= pivot.y;

	v = Rotatage(v, angle);

	v.x += pivot.x;
	v.y += pivot.y;

	return v;
}

void line(sfVertexArray* array, sfVector2f point1, sfVector2f point2, sfColor color)
{
	sfVertexArray_setPrimitiveType(array, sfLines);

	sfVertex vertex;
	vertex.color = color;

	vertex.position = point1;
	sfVertexArray_append(array, vertex);
	vertex.position = point2;
	sfVertexArray_append(array, vertex);
}


sfVector2f shift(sfVector2f a)
{
	sfVector2f decal = { WIDTH / 2, HEIGHT - 200 };
	return AddSub2f(a, decal, 1);
}

sfVector2f shift2(sfVector2f a, sfVector2f decal)
{
	return AddSub2f(a, decal, 1);
}

void branch(sfVertexArray* array, sfVector2f oriIni, sfVector2f lenIni, float angleIni)
{
	sfVector2f ori = oriIni;
	sfVector2f len = lenIni;
	float angle = angleIni;
	sfVector2f end;


	sfVector2f ori1 = ori;
	sfVector2f len1 = len;
	float angle1 = angle;
	sfVector2f end1;

	sfVector2f ori2 = ori;
	sfVector2f len2 = len;
	float angle2 = angle;
	sfVector2f end2;

	//tronc
	end = ori;

	end1 = end;
	len1 = MultDivFloat(len1, MODIF, 1);

	end2 = end;
	len2 = MultDivFloat(len2, MODIF, 1);

	if (norme(len) > limit)
	{
		sfColor tempColorA = sfColor_fromRGBA(rand() % 255, rand() % 255, 0, 255);
		sfColor tempColorB = sfColor_fromRGBA(0, rand() % 255, 0, 255);

		//left branch
		ori1 = end1;
		len1 = MultDivFloat(len1, MODIF, 1);
		end1 = AddSub2f(end1, len1, 1);
		end1 = RotatageAutour(end1, ori1, angle1 - (angleSize + 0) * DEG2RAD);
		line(array, ori1, end1, tempColorA);
		branch(array, end1, len1, angle1 - (angleSize + 0) * DEG2RAD);

		//right branch
		ori2 = end2;
		len2 = MultDivFloat(len2, MODIF, 1);
		end2 = AddSub2f(end2, len2, 1);
		end2 = RotatageAutour(end2, ori2, angle2 + (angleSize + 0) * DEG2RAD);
		line(array, ori2, end2, tempColorB);
		branch(array, end2, len2, angle2 + (angleSize + 0) * DEG2RAD);

	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	char params;
	printf("Custom parameters? (y/n)\t");
	scanf("%c", &params);
	fflush(stdin); while ((getchar()) != '\n');
	if (params == 'y')
	{
		printf("angle (y/n)\t");
		scanf("%f", &angleSize);
		fflush(stdin); while ((getchar()) != '\n');
		printf("length (y/n)\t");
		scanf("%f", &length);
		fflush(stdin); while ((getchar()) != '\n');
		printf("minimum size for drawn line (in pixels) (y/n)\t");
		scanf("%f", &limit);
		fflush(stdin); while ((getchar()) != '\n');
	}
	else if (params == 'n')
	{
		angleSize = 30;
		length = 200;
		limit = 3;
	}
	printf("\n\nangle can be changed using key + and key -");


	
	sfVector2f origin = { 0,0 };
	sfVector2f len = { 0,-length };


	sfVideoMode mode = { WIDTH, HEIGHT, 32 };
	window = sfRenderWindow_create(mode, "SFML window", sfResize | sfClose, NULL);

	sfVertexArray* array = sfVertexArray_create();




	line(array, (sfVector2f) { WIDTH / 2, HEIGHT }, shift(origin), sfRed);
	branch(array, shift(origin), len, 0 * DEG2RAD);
	/*branch(array, (sfVector2f) { 512, 184 }, (sfVector2f) { 0, -130}, -angleSize * DEG2RAD);
	branch(array, (sfVector2f) { 335, 92 }, (sfVector2f) { 0, -84 }, -135 * DEG2RAD);*/




	while (sfRenderWindow_isOpen(window))
	{
		while (sfRenderWindow_pollEvent(window, &event))
		{
			if (event.type == sfEvtClosed) exit(0);
			if (event.type == sfEvtKeyPressed)
			{
				if (event.key.code == sfKeyAdd)
				{
					angleSize++;
				}
				if (event.key.code == sfKeySubtract)
				{
					angleSize--;
				}
				sfVertexArray_clear(array);
				line(array, (sfVector2f) { WIDTH / 2, HEIGHT }, shift(origin), sfRed);
				branch(array, shift(origin), len, 0 * DEG2RAD);
			}
		}

		sfRenderWindow_clear(window, sfBlack);

		sfRenderWindow_drawVertexArray(window, array, NULL);

		sfRenderWindow_display(window);
	}
	return 0;
}