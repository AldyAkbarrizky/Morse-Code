#ifndef MORSE_H
#define MORSE_H

#include "bintree.h"

void createMorseTree(BinTree *P);

void EncodeMorse(BinTree P, char text[]);

void DecodeMorse(BinTree P, char morse[]);

#endif
