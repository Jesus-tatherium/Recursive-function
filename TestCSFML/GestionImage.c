#include "GestionImage.h"
#include "stdafx.h"

sfSprite* LoadSprite(char* sNom, char isCentered)
{
	sfTexture* tempTex;
	sfSprite* tempSprite;
	tempTex = sfTexture_createFromFile(sNom, NULL);

	tempSprite = sfSprite_create();
	sfSprite_setTexture(tempSprite, tempTex, 0);

	if (isCentered)
	{

		sfVector2u tailleImage = sfTexture_getSize(tempTex);
		sfVector2f centre = { (float)tailleImage.x / 2.f, (float)tailleImage.y / 2.f };
		sfSprite_setOrigin(tempSprite, centre);
	}
	return tempSprite;
}

sfSprite* LoadSpriteR(char* sNom, char isCentered)
{
	sfTexture* tempTex;
	sfSprite* tempSprite;
	tempTex = sfTexture_createFromFile(sNom, NULL);

	tempSprite = sfSprite_create();
	sfSprite_setTexture(tempSprite, tempTex, 0);

	if (isCentered)
	{

		sfVector2u tailleImage = sfTexture_getSize(tempTex);
		sfVector2f centre = { (float)tailleImage.x / 2.f - 16, (float)tailleImage.y / 2.f - 16};
		sfSprite_setOrigin(tempSprite, centre);
	}
	return tempSprite;
}

void BlitSprite(sfSprite* _sprite, sfVector2f pos, sfRenderWindow* window)
{

	sfSprite_setPosition(_sprite, pos);
	sfRenderWindow_drawSprite(window, _sprite, NULL);
}

void Pixel(sfImage* image, sfVector2f pos, sfColor color, sfVideoMode mode)
{
	if (pos.x > 0 && pos.x < mode.width && pos.y > 0 && pos.y < mode.height)
	{
		sfImage_setPixel(image, pos.x, pos.y, color);
	}
}
