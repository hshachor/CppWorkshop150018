#pragma once
#include"Queue.h"

//-------------------------------------------------------
//  class QueueVector
//  Queue implemented using vector operations
//-------------------------------------------------------
class QueueVector : public Queue
{
public:
    // constructor requires a starting size
    QueueVector(int max);
    QueueVector(const QueueVector&);
    virtual ~QueueVector() {}

    // implement Queue protocol
    void clear() override;
    int dequeue() override;
    void enqueue(int value) override;
    int front() const override;
    bool isEmpty() const override;

private:
    int * data;
    int capacity;
    int nextSlot;
    int firstUse;
};

