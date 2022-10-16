#pragma once


class NegativeNunb 
{
public:
    NegativeNunb(double _numb, int _i, int _j) // коструктор
        : numb(_numb), i(_i), j(_j)
    {}
    double numb; //число
    int i; //координата по х в массиве
    int j;//координата по у в массиве
    ~NegativeNunb() = default; // деструктор
};

