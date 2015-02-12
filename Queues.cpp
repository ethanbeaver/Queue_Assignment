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

template <class T>
void Queue <T>::growTilOverflowQ()
{
    if(fullQ())
    {
        while(!emptyQ())
        {
            delQ();
        }
    }
cout << "Queue length is " << lengthQ() << " . Adding until overflow" << endl;
while(!fullQ())
    addQ("Size");
addQ("Size");
}

template <class T>
void Queue <T>::shrinkTilUnderflowQ()
{
    if(emptyQ())
    {
        while(!fullQ())
        {
            addQ("Test");
        }
    }
cout << "Queue length is " << lengthQ() << " . Deleting until underflow" << endl;
while(!emptyQ())
    delQ();
delQ();
}

template <class T>
void Queue <T>::output1Q()
{
    addQ("Test");

    if(lengthQ()==1)
    {
        cout << "\nThere is one element in the queue. Congratulations. I guess?" << endl;
    }
    else
    {
        cout << "\nThere is NOT one element in the queue. Rather, there are " << lengthQ() << " elements." << endl;
    }
}

template <class T>
void Queue <T>::output5Q()
{
    for(int i=1; i<=5; i++)
    {
         addQ("Test");
    }

    if(lengthQ()==5)
    {
        cout << "\nThere are five elements in the queue. Congratulations. I guess?" << endl;
    }
    else
    {
        cout << "\nThere are NOT five elements in the queue. Rather, there are " << lengthQ() << " elements." << endl;
    }
}

template <class T>
void Queue <T>::outputFullQ()
{
    while(!fullQ())
    {
        addQ("Test");
    }
    if(fullQ())
    {
        cout << "\nQueue is full with "<< lengthQ() << " elements." << endl;
    }
    else
    {
        cout << "\nQueue is NOT full with " << lengthQ() << " elements." << endl;
    }
}

template <class T>
void Queue <T>::outputClearedQ()
{
        addQ("Size");
        cout << "\nQueue contains "<< lengthQ() << " elements. Clearing Queue." << endl;
        clearQ();
        cout << "\nQueue length is now: " << lengthQ() << ". That is all." << endl;

}


int main()
{

    Queue<string>a(10);
    return 0;
}

