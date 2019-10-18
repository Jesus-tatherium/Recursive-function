#ifndef GESTIONVECTEUR_H
#define GESTIONVECTEUR_H

//return nearest int
int roundNear(float f);

// 0 -> soustraction
// 1 -> addition
sfVector2f AddSub2f(sfVector2f a, sfVector2f b, int type);

// 0 -> division
// 1 -> multiplication
sfVector2f MultDiv2f(sfVector2f a, sfVector2f b, int type);

// 0 -> soustraction
// 1 -> addition
sfVector2f AddSubInt(sfVector2f a, int b, int type);

// 0 -> division
// 1 -> multiplication
sfVector2f MultDivInt(sfVector2f a, int b, int type);

// 0 -> division
// 1 -> multiplication
sfVector2f MultDivFloat(sfVector2f a, float b, int type);

void PrintVect2f(sfVector2f a);
void PrintVect2i(sfVector2i a);

#endif // !GESTIONVECTEUR_H

