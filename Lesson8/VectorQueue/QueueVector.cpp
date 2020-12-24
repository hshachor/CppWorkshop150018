#include "QueueVector.h"
#include <cstring>

//== class QueueVector implementation ==

QueueVector::QueueVector(int size)
{
    capacity = size + 1;
    data = new int[capacity];
    clear();
}

QueueVector::QueueVector(const QueueVector& v) :
    data(new int[v.capacity]), capacity(v.capacity),
    nextSlot(v.nextSlot), firstUse(v.firstUse)
{
    if (data == nullptr) {
        throw "Memory allocation failure";
    }
    memcpy(data, v.data, capacity * sizeof(data[0]));
}

void QueueVector::clear()
{
    nextSlot = 0;
    firstUse = 0;
}

int QueueVector::dequeue()
{
    // can not dequeue from an empty queue
    if (isEmpty()) throw "Queue is empty";
    int dataloc = firstUse;
    ++firstUse %= capacity;
    return data[dataloc];
}

void QueueVector::enqueue(int val)
{
    // make sure Queue has not overflowed
    if ((nextSlot + 1) % capacity == firstUse)
        throw "the Queue is full";
    data[nextSlot] = val;
    ++nextSlot %= capacity;
}

int QueueVector::front() const
{
    // can not return a value from an empty Queue
    if (isEmpty()) throw "Queue is empty";
    return data[firstUse];
}
bool QueueVector::isEmpty() const
{    // Queue is empty if next slot is
    // pointing to same location as first use
    return nextSlot == firstUse;
}
