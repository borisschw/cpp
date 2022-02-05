#ifndef VECTOR_
#define VECTOR_


class Vector{
    public:
    Vector(int s);
    double& operator[](int i);
    int size();

    private:
        double *elem;
        int sz;
};

#endif