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
    char miniMenu(bool);
    int menu();

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
        return Q[front];
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
    }/*for(int i=1; i<=lengthQ();i++)
        {
            cout << Q[(front+i)%size] << "  ";
        }*/
    else if(rear>front)
    {
        for(int i=0; i<size;i++)
        {
            if((i<=rear)&&(i>front))
                cout << Q[i%size] << "  ";
            else
                cout << "Null" << "  ";
        }
    }
    else if(rear<front)
    {
        for(int i=0; i<size;i++)
        {
            if((i<=rear)||(i>front))
                cout << Q[i%size] << "  ";
            else
                cout << "Null" << "  ";
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
    cout << "This is a function to grow and shrink the queue.\n";
    cout << endl << "What would you like to do?" << endl;
    cout << endl;
    cout << "\t1) Grow your Queue." << endl;
    cout << "\t2) Shrink your Queue." << endl;
    cout << "\t3) Output Queue length." << endl;
    cout << endl;
    cout << "\t0) Quit" << endl;
    cout << "Enter your choice: ";
    cin >> option;
    while(option!=0)
    {
        switch(option)
        {
            case 1:
                addQ('A');
                break;
            case 2:
                delQ();
                break;
            case 3:
                cout << lengthQ() << endl; break;
            default:
                cerr << "Please enter a valid choice." << endl; cout << endl << "What would you like to do?" << endl;
                cout << "\t1) Grow your Queue." << endl;
                cout << "\t2) Shrink your Queue." << endl;
                cout << "\t3) Output Queue length." << endl;
                cout << endl;
                cout << "\t0) Quit" << endl; break;
        }
        cout << "Enter your choice: ";
        cin >> option;
    }
}

template <class T>
void Queue<T>::wrapQ()
{
    for(int i=1;i<=8;i++)
    addQ('A');
    for(int i=1;i<=3;i++)
    delQ();
    for(int i=1;i<=3;i++)
    addQ('A');
    cout << "The front pointer is " << front << endl;
    cout << "The rear pointer is " << rear << endl;
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
    addQ('A');
addQ('A');
}

template <class T>
void Queue <T>::shrinkTilUnderflowQ()
{
    if(emptyQ())
    {
        while(!fullQ())
        {
            addQ('A');
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
    addQ('A');

    if(lengthQ()==1)
    {
        cout << "\nThere is " << lengthQ() << " element in the queue. Congratulations." << endl;
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
         addQ('A');
    }

    if(lengthQ()==5)
    {
        cout << "\nThere are " << lengthQ() << " elements in the queue. Congratulations." << endl;
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
        addQ('A');
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

        cout << "\nQueue contains "<< lengthQ() << " elements. Clearing Queue." << endl;
        clearQ();
        cout << "\nQueue length is now: " << lengthQ() << ". That is all." << endl;


}

template <class T>
char Queue<T>::miniMenu(bool isMiniMenu)
//A menu that prints options, and takes the user's choice
{
    char choice;
    if (isMiniMenu){
    cout << endl << "What would you like to do?" << endl;
    cout << endl;
    cout << "\t1) Grow and Shrink your Queue." << endl;
    cout << "\t2) Test for Queue wraparound." << endl;
    cout << "\t3) Grow the queue until an overflow occurs." << endl;
    cout << "\t4) Shrink the Queue until an underflow occurs." << endl;
    cout << "\t5) Set and output a 1 element Queue"<< endl;
    cout << "\t6) Set and output a 5 element Queue." << endl;
    cout << "\t7) Set and output a full Queue." << endl;
    cout << "\t8) Clear and reset a Queue." << endl;
    cout << "\t9) Print the Queue." << endl;
    cout << endl << "\t0) Quit." << endl;
    }
    else
    {
        cout << "\n\n1)Grow/Shrink\t2)Wrap\t3)Over\t4)Under\t\t5)1Q\t\t6)5Q\t\t7)Full\t\t8)Reset\t\t9)Print\n";
    }
    cout << endl;
    cout << ">>>";
    //choice = getchar();
    cin >> choice;
    cout << endl;
    return choice;
}

template <class T>
int Queue<T>::menu()
{

    char option = NULL;
    bool printMenu = true;
    cout << " _    _  ____  __    ___  _____  __  __  ____  \n"
    <<"( \\/\\/ )( ___)(  )  / __)(  _  )(  \\/  )( ___)\n"
    <<" )    (  )__)  )(__( (__  )(_)(  )    (  )__) \n"
    <<"(__/\\__)(____)(____)\\___)(_____)(_/\\/\\_)(____)\n";

    while(option!='0')
    {
        option = miniMenu(printMenu);
        switch(option)
        {
            case '0': cout << "Goodbye"; break;
            case '1': clearQ(); growShrinkQ(); printMenu = false; break;
            case '2': clearQ(); wrapQ(); printMenu = false; break;
            case '3': clearQ(); growTilOverflowQ(); printMenu = false; break;
            case '4': clearQ(); shrinkTilUnderflowQ(); printMenu = false; break;
            case '5': clearQ(); output1Q(); printMenu = false; break;
            case '6': clearQ(); output5Q(); printMenu = false; break;
            case '7': clearQ(); outputFullQ(); printMenu = false; break;
            case '8': clearQ(); outputClearedQ(); printMenu = false; break;
            case '9': cout << endl; writeQ(); printMenu = false; break;
            default : cerr << "\nERROR: '" << option << "' is not a valid menu option.\n\n"; printMenu = true; break;
        }
    }
    return(0);
}


int main()
{

    Queue<char>a(10);
    a.menu();
    return 0;
}
