#ifndef ALIVEC_H
#define ALIVEC_H

template <class T>
class alivec
{
T* header=nullptr;
public:
    alivec();
    void insert(T& tmp);
};

#endif // ALIVEC_H
