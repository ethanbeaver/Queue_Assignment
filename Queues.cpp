#include <iostream>
#include <cstdlib>

using namespace std;

template <class T>

class Queue
{
private:
    T *Q;
    int size;
    int front, rear;
public:
    Queue();
    Queue(int);
    bool emptyQ();
    bool fullQ();
    void addQ(T);
    T delQ();
    int lengthQ();
    void writeQ();
    void clearQ();
    void growShrinkQ();
    void wrapQ();
    void growTilOverflowQ();
    void shrinkTilUnderflowQ();
    void output1Q();
    void output5Q();
    void outputFullQ();
    void outputClearedQ();
};

template <class T>
Queue <T>::Queue()
{
    size=15;
    Q = new T[size];
    front=rear=0;
}

template <class T>
Queue <T>::Queue(int setSize)
{
    size=setSize;
    Q = new T[size];
    front=rear=0;
}

template <class T>
bool Queue<T>::emptyQ()
{
    if(front==rear)
        return true;
    else
        return false;
}

template <class T>
bool Queue<T>::fullQ()
{
    if(front==(rear+1)%size)
        return true;
    else
        return false;
}

template <class T>
void Queue<T>::addQ(T data)
{
    if(fullQ())
    {
        cout << "\nQueue Overflow\n\n";
        exit;
    }
    else
    {
        rear = (rear+1)%size;
        Q[rear] = data;
        cout << "Element Added\n";
    }
}

template <class T>
T Queue<T>::delQ()
{
    if(emptyQ())
    {
        cout << "\nQueue Underflow\n\n";
        exit;
    }
    else
    {
        front = (front +1)%size;
        cout << "Element Deleted\n";
        return Q[front];
    }
}

template <class T>
int Queue<T>::lengthQ()
{
    if (emptyQ())
    {
        return 0;
    }
    else if(front<rear)
    {
        return rear-front;
    }
    else
    {
        return rear-front+size;
    }
}

template <class T>
void Queue<T>::writeQ()
{
    if(emptyQ())
    {
        cout << "\nQueue Empty\n";
    }
    else
    {
        for(int i=1; i<=lengthQ();i++)
        {
            cout << Q[(front+i)%size] << "  ";
        }
    }
}

template <class T>
void Queue <T>::clearQ()
{
    front=rear=0;
}


template <class T>
void Queue<T>::growShrinkQ()
{
    int option;
    cout << "This is a function to grow and shrink the queue.\nTo add an element to the Queue, press 1.\nTo remove an element from the Queue, press 2.\nTo print the length of the Queue, press 3.\nTo quit the function, press 0.\n";
    cout << "Enter your choice: ";
    cin >> option;
    while(option!=0)
    {
        switch(option)
        {
            case 1:
                addQ("");
                break;
            case 2:
                delQ();
                break;
            case 3:
                cout << lengthQ() << endl; break;
        }
        cout << "Enter your choice: ";
        cin >> option;
    }
}



int main()
{
    Queue<string> a(10);
    return 0;
}
