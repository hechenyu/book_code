#include <iostream>
#include <tr1/memory>

#include "sputil.h"

using std::tr1::shared_ptr;
using std::tr1::weak_ptr;
using std::cout;

struct node: instrumented
{
    shared_ptr<node> next;
    weak_ptr<node> weak_next;
};

static void cycle()
{
    cout << "Cycle:\n";
    node *head = new node;
    node *N1 = new node;
    shared_ptr<node> root(head);
    head->next = shared_ptr<node>(N1);
    N1->next = root;
}

static void no_cycle()
{
    cout << "Break cycle:\n";
    node *head = new node;
    node *N1 = new node;
    shared_ptr<node> root(head);
    head->next = shared_ptr<node>(N1);
    N1->weak_next = root;
}

int main()
{
    cycle();
    no_cycle();

    return 0;
}
