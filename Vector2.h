#ifndef _VECTOR2_H
#define _VECTOR2_H

typedef struct V2 {
    int x;
    int y;
}Vector2;

/**
 * Returns a new Vector2 that is the sum of a and b
*/
Vector2 add(Vector2 a, Vector2 b);

/**
 * Returns a new Vector2 that is the difference between b and a 
 * (b-a)
*/
Vector2 sub(Vector2 a, Vector2 b);

/**
 * Returns a new Vector2 that is the dot product of a and value
*/
Vector2 dot(Vector2 a, float value);
#endif