#include <iostream>
#include <cassert>

using namespace std;

class List;
class Iterator;

class Link {
public:
    Link(int n);
private:
    int data;
    Link* next;
    friend class List;
    friend class Iterator;
};

class List {
public:
    List();
    ~List() {}
    bool empty() const;
    void push_back(int x);
    void push_front(int x);
    void pop_back();
    void pop_front();
    Iterator begin();
    Iterator end();
    Iterator erase(Iterator iter);
    int size();
    void insert(Iterator iter, int x);
private:
    Link* first;
};

class Iterator {
public:
    Iterator();
    void operator++();
    int & operator*();
private:
    Link* position;
    friend class List;
};

Link::Link(int n){
    data = n;
    next = NULL;
}
List::List(){
    first = NULL;
}
bool List::empty() const {
    if(first == NULL)
        return true;
    else
        return false;
}
void List::push_back(int x) { //pushes to back of list
    Link* new_link = new Link(x);
    Link* linkptr = first;
    if(first == NULL)
    {
        first = new_link;
    }
    else
    {
        while(linkptr->next!=NULL){
            linkptr = linkptr->next;
        }
        linkptr->next = new_link;
    }
}
void List::push_front(int x) { //pushes to front of list
    Link* new_link = new Link(x);
    if(first == NULL)
    {
        first = new_link;
    }
    else
    {
        new_link->next = first;
        first = new_link;
    }
}
void List::pop_back(){ //removes last in list
    Link * link;
    while(link!=NULL){
        link->next;
    }
    delete link->next;
    link->next = NULL;
}
void List::pop_front(){ //removes first in list
    first = first->next;
}
void List::insert(Iterator iter, int x){ //pushes a number into a specific part of the list
    if(iter.position == NULL) //skips un-needed steps if the list is empty
    {
        push_back(x);
        return;
    }
    Link* after = iter.position;
    Link* new_link = new Link(x);
    new_link->next = after;
    if(first == NULL)
        first = new_link;
}
Iterator::Iterator(){
    position = NULL;
}
Iterator List::begin(){ //returns first part of the list
    Iterator iter;
    iter.position = first;
    return iter;
}
Iterator List::end(){ //returns last part of the list
    Iterator iter;
    iter.position = NULL;
    return iter;
}
void Iterator::operator++() { //moves iterator to next part of the list
    assert(position != NULL);
    position = position->next;
}
int & Iterator::operator*(){ //outputs what the iterator is pointing to
    assert(position != NULL);
    return position->data;
}
Iterator List::erase(Iterator iter){ //remove a specific part of the list
    Link* remove = iter.position;
    Link* after = remove->next;
    if(remove == first)
        first = after;
    delete remove;
}
int List::size(){ //return the size of the list
    Link * link = first;
    int count = 0;
    while (link != NULL) {
        ++count;
        link = link->next;
    }
    return count;
}
void testa(){ //tests push back and push front
    List a;
    assert(a.empty() == true);
    a.push_back(16);
    assert(a.empty() == false);
    Iterator it;
    it = a.begin();
    assert(a.size() == 1);
    a.push_front(3);
    assert(*it = 16);
    it = a.begin();
    assert(*it = 3);
    a.erase(it);
    it = a.begin();
    assert(*it = 16);
}
void testb(){ //tests erase and insert
    List b;
    b.push_back(20);
    Iterator it;
    it = b.begin();
    b.push_front(29);
    assert(*it = 20);
    it = b.begin();
    assert(*it = 29);
    b.erase(it);
    it = b.begin();
    assert(*it = 20);
    b.insert(it, 21);
    assert(*it = 21);
    it = b.begin();
    assert(*it = 20);
}
void testc() {//tests first number
    List c;
    c.push_back(7);
    c.push_front(5);
    c.push_back(9);
    Iterator it;
    it = c.begin();
    c.erase(it);
    it = c.begin();
    assert(*it = 7);
    ++it;
    assert(*it = 9);
}
void testd(){//tests middle number
    List d;
    d.push_back(3);
    d.push_back(5);
    d.push_back(7);
    Iterator it;
    it = d.begin();
    ++it;
    d.erase(it);
    it = d.begin();
    assert(*it = 3);
    ++it;
    assert(*it = 7);
}
void teste(){//tests last number
    List e;
    e.push_back(5);
    e.push_back(7);
    e.push_back(9);
    Iterator it;
    it = e.begin();
    ++it;
    ++it;
    e.erase(it);
    it = e.begin();
    assert(*it = 5);
    ++it;
    assert(*it = 7);
    ++it;
}
void testf(){ //size function test
    List f;
    assert(f.size() == 0);
    f.push_back(5);
    assert(f.size() == 1);
    f.push_back(7);
    assert(f.size() == 2);
    f.push_back(9);
    assert(f.size() == 3);
}

int main() {
    testa();
    testb();
    testc();
    testd();
    teste();
    testf();
    
    cout << "All tests passed." << endl;
}

