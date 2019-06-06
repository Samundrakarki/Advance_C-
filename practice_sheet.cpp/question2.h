
using namespace std;
template<class T>
class Queue {
private:
    QueueItem<T> ∗front;
    QueueItem<T> ∗back;
public:
    Queue();
    ˜Queue();
    T remove(int pos);
    void add (const T&);
    bool is_empty() const {
    return front == NULL;
    }
};