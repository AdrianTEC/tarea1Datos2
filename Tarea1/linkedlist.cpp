#include <iostream>

//INSPIRE CODE IN https://gist.github.com/dukky/9244500
template<class T>
struct node {
    node<T>* next;
    T data;
};

template<class T>
class LinkedList
{
public:
    node<T>* first;
    node<T>* last;
    int longitud;
    LinkedList<T>()
        {
            first = NULL;
            last = NULL;
            longitud=0;
        }

    void add(T data)
        {
            longitud+=1;
            if(!first)
                {

                first = new node<T>;
                first->data = data;
                first->next = NULL;
                last = first;

                }
            else {

                if(last == first)
                    {

                    last = new node<T>;
                    last->data = data;
                    last->next = NULL;
                    first->next = last;
                    }
                else
                    {

                        node<T>* insdata = new node<T>;
                        insdata->data = data;
                        insdata->next = NULL;
                        last->next = insdata;
                        last = insdata;
                    }
            }
        }

    T get(int index)
        {
            if(index == 0)
                {
                    // Get the first element
                    return this->first->data;
                }
            else
                {
                    // Get the index'th element
                    node<T>* curr = this->first;
                    for(int i = 0; i < index; ++i)
                        {
                            curr = curr->next;
                        }
                    return curr->data;
                }
        }

    void print_list()
        {

        node<T>* curr = this->first;
        for(int i = 0; i < longitud; ++i)
            {

               curr = curr->next;


            }
        }
    T operator[](int index)
        {
            return get(index);
        }

};
