
#ifndef JIMP_EXERCISES_SHAPE_H
#define JIMP_EXERCISES_SHAPE_H


class Shape {

public:
    virtual void draw()=0;
};

class Square: public Shape{
public:
    void draw();

};

class Circle: public Shape{
public:
    void draw();

};

class Triangle: public Shape{
public:
    void draw();

};

#endif //JIMP_EXERCISES_SHAPE_H