#include "Vector2.h"

Vector2 add(Vector2 a, Vector2 b) {
    return (Vector2) {a.x + b.x, a.y + b.y};
}

Vector2 sub(Vector2 a, Vector2 b) {
    return (Vector2) {a.x - b.x, a.y - b.y};
}

Vector2 dot(Vector2 a, float value) {
    return (Vector2) {(int)((float)a.x * value), (int)((float)a.y * value)};
}