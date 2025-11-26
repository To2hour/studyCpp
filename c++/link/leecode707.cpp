#include <iostream>
#include <math.h>
#include <vector>
class MyLinkedList {
    private:
        int val;
        MyLinkedList *next;
    public:
        MyLinkedList() {
            
        }
        
        int get(int index) {
            for (int i = 0; i < index; i++) {
                if (next == NULL) {
                    return -1;
                }
                next = next->next;
            }
            return next->val;
        }
        
        void addAtHead(int val) {
            
        }
        
        void addAtTail(int val) {
            
        }
        
        void addAtIndex(int index, int val) {
            
        }
        
        void deleteAtIndex(int index) {
            
        }
    };
    