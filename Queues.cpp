#This is definitely a test
#But is it really?
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
        cout << "\nQueue Overflow\n";
        abort();
    }
    else
    {
        rear = (rear+1)%size;
        Q[rear] = data;
    }
}

template <class T>
T Queue<T>::delQ()
{
    if(emptyQ())
    {
        cout << "\nQueue Underflow\n";
        abort();
    }
    else
    {
        front = (front +1)%size;
        return Q[front];
    }
}

template <class T>
int Queue<T>::lengthQ()
{
    if(front<rear)
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


int main()
{
    Queue<string> a(5);
    a.writeQ();
    a.addQ("Cherry");
    a.addQ("Apple");
    a.addQ("Banana");
    a.writeQ();
    a.addQ("Pecan");
    cout << endl;
    a.writeQ();
    cout << endl;
    cout << a.delQ() << endl;
    cout << a.delQ() << endl;
    cout << a.delQ() << endl;
    cout << a.delQ() << endl;
    cout << a.delQ() << endl;
    return 0;
}
