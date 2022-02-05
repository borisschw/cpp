#include <vector.h>


double& Vector::operator[](int i)// definition of subscripting
{
    return elem[i];
}

Vector::Vector(int s)// definition of the constructor
    :elem{new double[s]},sz{s}// initialize members
{

}
int Vector::size()
{
    return sz;
}