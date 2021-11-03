#ifndef VECTORTWO_H
#define VECTORTWO_H

struct Vector2
{
    Vector2() {x = 0.0f, y = 0.0f;}
    Vector2(float t_x, float t_y) {x = t_x; y = t_y;};
    Vector2(const Vector2 &v) {x = v.x; y = v.y;};

    Vector2 operator+(const Vector2 &v) const {return Vector2(x + v.x, y + v.y);}
    Vector2 operator-(const Vector2 &v) const {return Vector2(x - v.x, y - v.y);}

    Vector2 operator*(const float &f) const {return Vector2(x * f, y * f);}

    float x;
    float y;
};

#endif