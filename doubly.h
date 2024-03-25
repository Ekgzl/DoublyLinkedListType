//
// Created by enes4 on 3/25/2024.
//

#ifndef DOUBLY_DOUBLY_H
#define DOUBLY_DOUBLY_H

#include <ostream>

#define NULL nullptr
using namespace std;

template <class T>
struct node
        {
            T info;
            node<T> *next,*back;
        };

    template <class T>
    class doublyLinkedList
            {
            protected:
                int count;
                node<T> *first,*last;
            public:
            doublyLinkedList();
            bool isEmpty();
            int length();
            T front();
            T back();
            void insertFirst(T& item);
            void insertLast(T& item);

            friend ostream& operator<<(ostream& os,doublyLinkedList<T>& list)
            {
                node<T> *current;
                current = list.first;

                while(current!= NULL)
                {
                    os << current->info;
                    if(current->next != NULL)
                        os << " -> ";
                    current = current->next;
                }
                return os;
            }

        node<T> *search(T &item);

        void deleteNode(const T &item);
    };

        template <class T>
        doublyLinkedList<T>::doublyLinkedList()
        {
            count = 0;
            first = NULL;
            last = NULL;
        }

        template <class T>
        bool doublyLinkedList<T>::isEmpty()
        {
            return(first == NULL);
        }

        template <class T>
        int doublyLinkedList<T>::length()
        {
            return count;
        }

        template <class T>
        T doublyLinkedList<T>::back()
        {
            return last->info;
        }

        template <class T>
        T doublyLinkedList<T>::front()
        {
            return first->info;
        }

        template <class T>
        void doublyLinkedList<T>::insertFirst(T &item)
        {
            node<T> *newNode = new node<T>;
            newNode->info = item;
            newNode->back = NULL;
            newNode->next = NULL;

            if(first == NULL) // case 1 empty
            {
                first = newNode;
                last = newNode;
                count++;
            }

            else
            {
                newNode->next = first; // case 2 not
                first->back = newNode;
                count++;
                first = newNode;
            }

        }

        template <class T>
        node<T>* doublyLinkedList<T>::search(T& item)
        {
            node<T> *current = first;
            if(first == NULL)
            {
                cout << "cannot find from empty list";
                return nullptr;
            }

            while(current != NULL)
            {
                if(current->info == item)
                {
                 return current;
                }
                else
                    current = current->next;
            }
            if(current == NULL)
            {
                cout << "couldnt find in list";
                return nullptr;
            }
        }

        template <class T>
        void doublyLinkedList<T>::insertLast(T &item)
        {
            node<T> *newNode = new node<T>;
            newNode->info = item;
            newNode->next = NULL;
            newNode->back = NULL;

            if(first==NULL)
            {
                first = newNode;
                last = newNode;
                count++;
            }

            else
            {
                last->next = newNode;
                newNode->back = last;
                last = newNode;
                count++;
            }
        }

        template <class T>
        void doublyLinkedList<T>::deleteNode(const T& item)
        {
            node<T> *current;

            if(first == NULL)
            {
                cout << "cannot find in empty list";
                return;
            }
            else
            {
                current = first;
                if(current->info == item) // ilkse case 1
                {
                    first = current->next;
                    if(first == NULL) // case2 bir item varsa
                    {
                        last = NULL;
                        count--;
                        delete current;
                        return;
                    }
                    first->back = NULL;
                    delete current;
                    count--;
                    return;
                }
                while(current != NULL)
                {
                    if(current->info == item)
                    {
                        current->back->next = current->next;
                        if(current->next == NULL)
                            last = current->back;
                        else
                            current->next->back = current->back;

                        delete current;
                        count--;
                        return;
                    }
                    else
                        current =current->next;
                }
                    cout << "cannot find in list";
                    return;



            }
        }




#endif //DOUBLY_DOUBLY_H
