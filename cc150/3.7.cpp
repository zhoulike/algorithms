#include <iostream>
#include <list>

using namespace std;

class AnimalQueue
{
public:
    enum TYPE {CAT, DOG}; 

    AnimalQueue() :number(0) {} 

    void enqueue(TYPE t);
    unsigned int dequeueAny(); //return animal number
    unsigned int dequeueDog();
    unsigned int dequeueCat();

private:
    list<unsigned int> dog;
    list<unsigned int> cat;
    //each animal has an identical number, assume no overflow
    unsigned int number; 
};

void AnimalQueue::enqueue(TYPE t)
{
    if (t == CAT)
        cat.push_back(number++);
    else
        dog.push_back(number++);
}

unsigned int AnimalQueue::dequeueAny()
{
    unsigned int front_cat, front_dog;
    if (!cat.empty())
        front_cat = cat.front();

    if (!dog.empty())
        front_dog = dog.front();

    if (!cat.empty() && !dog.empty()) {
        if (front_cat < dog.front()) {
            cat.pop_front();
            return front_cat;
        } else {
            dog.pop_front();
            return front_dog;
        }
    } else if (!cat.empty()) {
        cat.pop_front();
        return front_cat;
    } else if (!dog.empty()) {
        dog.pop_front();
        return front_dog;
    } else
        return -1;
}

unsigned int AnimalQueue::dequeueCat()
{
    if (!cat.empty()) {
        unsigned int front_cat = cat.front();
        cat.pop_front();
        return front_cat;
    }
    else
        return -1;
}

unsigned int AnimalQueue::dequeueDog()
{
    if (!dog.empty()) {
        unsigned int front_dog = dog.front();
        dog.pop_front();
        return front_dog;
    }
    else
        return -1;
}


int main(int argc, char *argv[])
{
    AnimalQueue q; 
    q.enqueue(AnimalQueue::DOG);
    q.enqueue(AnimalQueue::DOG);
    q.enqueue(AnimalQueue::CAT);
    q.enqueue(AnimalQueue::CAT);
    q.enqueue(AnimalQueue::DOG);
    q.enqueue(AnimalQueue::CAT);

    cout << "dequeue cat: 2 == " << q.dequeueCat() << endl; 
    cout << "dequeue any: 0 == " << q.dequeueAny() << endl; 
    cout << "dequeue any: 1 == " << q.dequeueAny() << endl; 
    cout << "dequeue dog: 4 == " << q.dequeueDog() << endl; 
    cout << "dequeue any: 3 == " << q.dequeueAny() << endl; 
    cout << "dequeue any: 5 == " << q.dequeueAny() << endl; 
    return 0;
}
