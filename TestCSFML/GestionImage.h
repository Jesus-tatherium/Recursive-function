#ifndef GESIONIMAGE_H
#define GESIONIMAGE_H


sfSprite* LoadSprite(char* sNom, char isCentered);

sfSprite* LoadSpriteR(char* sNom, char isCentered);

void BlitSprite(sfSprite* _sprite, sfVector2f pos, sfRenderWindow* window);

void Pixel(sfImage* image, sfVector2f pos, sfColor color, sfVideoMode mode);

#endif // !GESIONIMAGE_H