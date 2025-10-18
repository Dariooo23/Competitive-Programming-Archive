// Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

typedef unsigned char BYTE;

struct OBJECT_TYPE{
    int litera;

    bool operator==(const OBJECT_TYPE &other) const {
        return litera == other.litera;
    }
};

struct NODE_STRUCT{
    OBJECT_TYPE* object;
    BYTE use;
    NODE_STRUCT* next;
};

BYTE SIZE = 5;

//Wszystkie rzeczy powyzej nalezy zakomentowac a dopiero przeslac na BaCa'e
//Na BaCa'y kod z rozwiazaniem dostaje te definicje z zewnatrz, ale dla wygody je stworzylem

NODE_STRUCT* NewNode(){
    NODE_STRUCT* node = new NODE_STRUCT;

    (*node).object = new OBJECT_TYPE[SIZE];
    (*node).use = 0;
    (*node).next = NULL;

    return node;
}

void DeleteNode(NODE_STRUCT* node){
    if (node == NULL){
        return;
    }

    delete[] (*node).object;
    delete node;
    return;
}

void Clear(NODE_STRUCT** head){
    if (*head == NULL){
        return;
    }

    NODE_STRUCT* current = *head;
    NODE_STRUCT* nextNode;

    while (current != NULL){
        nextNode = (*current).next;
        DeleteNode(current);
        current = nextNode;
    }

    *head = NULL;
    return;
}

void AddFirst(NODE_STRUCT** head, OBJECT_TYPE* object){
    NODE_STRUCT* first_node = *head;

    if (first_node == NULL){
        NODE_STRUCT* empty_node = NewNode();

        *head = empty_node;
        *((*empty_node).object) = *object;
        (*empty_node).use++;
    }else{
        if ((*first_node).use == SIZE){
            NODE_STRUCT* empty_node = NewNode();
    
            *head = empty_node;
            (*empty_node).next = first_node;
    
            (*(*empty_node).object) = *object;
            (*empty_node).use++;
        }else{
            OBJECT_TYPE* object_arr_ptr_end = (*first_node).object + (*first_node).use;
    
            while (object_arr_ptr_end != (*first_node).object){
                *object_arr_ptr_end = *(object_arr_ptr_end - 1);
                object_arr_ptr_end--;
            }
            *object_arr_ptr_end = *object;
    
            (*first_node).use++;
        }
    }

    return;
}

void AddLast(NODE_STRUCT** head, OBJECT_TYPE* object){
    NODE_STRUCT* current = *head;

    if (current == NULL){
        NODE_STRUCT* empty_node = NewNode();

        *head = empty_node;
        *((*empty_node).object) = *object;
        (*empty_node).use++;
    }else{
        while ((*current).next != NULL){
            current = (*current).next;
        }
    
        if ((*current).use == SIZE){
            NODE_STRUCT* empty_node = NewNode();
    
            (*current).next = empty_node;
            *((*empty_node).object) = *object;
            (*empty_node).use++;
        }else{
            OBJECT_TYPE* object_arr_ptr_end = (*current).object + (*current).use;
            *object_arr_ptr_end = *object;
            (*current).use++;
        }
    }
    return;
}


void GetFirst(NODE_STRUCT* head, NODE_STRUCT** node, BYTE* index){
    if (head == NULL){
        *node = NULL;
    }else{
        *node = head;
        *index = 0;
    }

    return;
}

void GetPrev(NODE_STRUCT* head, NODE_STRUCT* node, BYTE index, NODE_STRUCT** prev_node, BYTE* prev_index){
    if (head == NULL || node == NULL){
        *prev_node = NULL;
    }else{
        if (head == node){
            if (index == 0){
                *prev_node = NULL;
            }else{
                *prev_node = node;
                *prev_index = index - 1;
            }
        }else{
            if (index == 0){
                NODE_STRUCT* temp_node = head;
                while ((*temp_node).next != node){
                    temp_node = (*temp_node).next;
                }
                *prev_node = temp_node;
                *prev_index = (*temp_node).use - 1;
            }else{
                *prev_node = node;
                *prev_index = index - 1;
            }
        }
    }

    return;
}

void GetNext(NODE_STRUCT* head, NODE_STRUCT* node, BYTE index, NODE_STRUCT** next_node, BYTE* next_index){
    if (head == NULL || node == NULL){
        *next_node = NULL;
    }else{
        if ((*node).next == NULL){
            if (index == (*node).use - 1){
                *next_node = NULL;
            }else{
                *next_node = node;
                *next_index = index + 1;
            }
        }else{
            if (index == (*node).use - 1){
                *next_node = (*node).next;
                *next_index = 0;
            }else{
                *next_node = node;
                *next_index = index + 1;
            }
        }
    }

    return;
}

void GetLast(NODE_STRUCT* head, NODE_STRUCT** node, BYTE* index){
    if (head == NULL){
        *node = NULL;
    }else{
        NODE_STRUCT* current = head;
        while ((*current).next != NULL){
            current = (*current).next;
        }
        *node = current;
        *index = (*current).use - 1;
    }

    return;
}

void InsertPrev(NODE_STRUCT** head, NODE_STRUCT* node, BYTE index, OBJECT_TYPE* object){
    if ((*node).use == SIZE){
        if (index == 0){
            if (node == *head){
                NODE_STRUCT* empty_node = NewNode();
    
                *head = empty_node;
                (*empty_node).next = node;
    
                *((*empty_node).object) = *object;
                (*empty_node).use++;
            }else{
                NODE_STRUCT* temp_node = *head;
                
                while((*temp_node).next != node){
                    temp_node = (*temp_node).next;
                }

                if ((*temp_node).use == SIZE){
                    NODE_STRUCT* empty_node = NewNode();
    
                    (*temp_node).next = empty_node;
                    (*empty_node).next = node;
    
                    *((*empty_node).object) = *object;
                    (*empty_node).use++;
                }else{
                    *((*temp_node).object + (*temp_node).use) = *object;
                    (*temp_node).use++;
                }
            }
        }else{
            OBJECT_TYPE old_object = *((*node).object);

            if (node == *head){
                NODE_STRUCT* empty_node = NewNode();
    
                *head = empty_node;
                (*empty_node).next = node;
    
                *((*empty_node).object) = old_object;
                (*empty_node).use++;
            }else{
                NODE_STRUCT* temp_node = *head;
                
                while((*temp_node).next != node){
                    temp_node = (*temp_node).next;
                }

                if ((*temp_node).use == SIZE){
                    NODE_STRUCT* empty_node = NewNode();
    
                    (*temp_node).next = empty_node;
                    (*empty_node).next = node;
    
                    *((*empty_node).object) = old_object;
                    (*empty_node).use++;
                }else{
                    *((*temp_node).object + (*temp_node).use) = old_object;
                    (*temp_node).use++;
                }
            }

            OBJECT_TYPE* object_arr_ptr_start = (*node).object;
            int iterator = 0;
            
            while(iterator != index - 1){
                *object_arr_ptr_start = *(object_arr_ptr_start + 1);
                object_arr_ptr_start++;
                iterator++;
            }
            *object_arr_ptr_start = *object;
        }
    }else{
        OBJECT_TYPE* object_arr_ptr_end = (*node).object + (*node).use;

        while (object_arr_ptr_end != (*node).object + index){
            *object_arr_ptr_end = *(object_arr_ptr_end - 1);
            object_arr_ptr_end--;
        }
        *object_arr_ptr_end = *object;

        (*node).use++;
    }

    return;
}

void InsertNext(NODE_STRUCT* head, NODE_STRUCT* node, BYTE index, OBJECT_TYPE* object){
    if ((*node).use == SIZE){
        if (index == SIZE - 1){
            if ((*node).next == NULL){
                NODE_STRUCT* empty_node = NewNode();

                (*node).next = empty_node;

                *((*empty_node).object) = *object;
                (*empty_node).use++;
            }else{
                NODE_STRUCT* temp_node = (*node).next;

                if ((*temp_node).use == SIZE){
                    NODE_STRUCT* empty_node = NewNode();

                    (*node).next = empty_node;
                    (*empty_node).next = temp_node;

                    *((*empty_node).object) = *object;
                    (*empty_node).use++;
                }else{
                    OBJECT_TYPE* object_arr_end_ptr = (*temp_node).object + (*temp_node).use;
                    int iterator = (*temp_node).use;

                    while (iterator != 0){
                        *object_arr_end_ptr = *(object_arr_end_ptr - 1);
                        object_arr_end_ptr--;
                        iterator--;
                    }

                    *object_arr_end_ptr = *object;
                    (*temp_node).use++;
                }
            }
        }else{
            OBJECT_TYPE old_object = *((*node).object + (*node).use - 1);

            if ((*node).next == NULL){
                NODE_STRUCT* empty_node = NewNode();

                (*node).next = empty_node;

                *((*empty_node).object) = old_object;
                (*empty_node).use++;
            }else{
                NODE_STRUCT* temp_node = (*node).next;

                if ((*temp_node).use == SIZE){
                    NODE_STRUCT* empty_node = NewNode();

                    (*node).next = empty_node;
                    (*empty_node).next = temp_node;

                    *((*empty_node).object) = old_object;
                    (*empty_node).use++;
                }else{
                    OBJECT_TYPE* object_arr_end_ptr = (*temp_node).object + (*temp_node).use;
                    int iterator = (*temp_node).use;

                    while (iterator != 0){
                        *object_arr_end_ptr = *(object_arr_end_ptr - 1);
                        object_arr_end_ptr--;
                        iterator--;
                    }

                    *object_arr_end_ptr = old_object;
                    (*temp_node).use++;
                }
            }

            OBJECT_TYPE* object_arr_ptr_end = (*node).object + (*node).use - 1;
            int iterator = (*node).use - index - 1;

            while (iterator != 0){
                *object_arr_ptr_end = *(object_arr_ptr_end - 1);
                object_arr_ptr_end--;
                iterator--;
            }

            *(object_arr_ptr_end + 1) = *object;
        }
    }else{
        OBJECT_TYPE* object_arr_ptr_end = (*node).object + (*node).use;

        while (object_arr_ptr_end != (*node).object + index + 1){
            *object_arr_ptr_end = *(object_arr_ptr_end - 1);
            object_arr_ptr_end--;
        }
        *object_arr_ptr_end = *object;

        (*node).use++;
    }

    return;
}



void RemoveCurrent(NODE_STRUCT** head, NODE_STRUCT* node, BYTE index){
    if (node == NULL || *head == NULL){
        return;
    }else{
        if ((*node).use == 1){
            if (node == *head){
                *head = (*node).next;
                DeleteNode(node);
            }else{
                NODE_STRUCT *prev_node = *head;
                while ((*prev_node).next != node){
                    prev_node = (*prev_node).next;
                }
                (*prev_node).next = (*node).next;
                DeleteNode(node);
            }
        }else{
            OBJECT_TYPE* object_arr_ptr = (*node).object + index;
            int size_copy = (*node).use - index - 1;

            while (size_copy != 0){
                *object_arr_ptr = *(object_arr_ptr + 1);
                object_arr_ptr++;
                size_copy--;
            }

            (*node).use--;
        }
    }

    return;
}


void RemoveFirst(NODE_STRUCT** head){
    NODE_STRUCT* prev_node;
    BYTE prev_index;

    GetFirst(*head, &prev_node, &prev_index);

    RemoveCurrent(head, prev_node, prev_index);
    return;
}

void RemovePrev(NODE_STRUCT** head, NODE_STRUCT* node, BYTE index){
    NODE_STRUCT* prev_node;
    BYTE prev_index;

    GetPrev(*head, node, index, &prev_node, &prev_index);

    RemoveCurrent(head, prev_node, prev_index);
    return;
}

void RemoveNext(NODE_STRUCT* head, NODE_STRUCT* node, BYTE index){
    NODE_STRUCT* next_node;
    BYTE next_index;

    GetNext(head, node, index, &next_node, &next_index);

    RemoveCurrent(&head, next_node, next_index);
    return;
}

void RemoveLast(NODE_STRUCT** head){
    NODE_STRUCT* last_node;
    BYTE last_index;

    GetLast(*head, &last_node, &last_index);

    RemoveCurrent(head, last_node, last_index);
    return;
}

void Find(NODE_STRUCT* head, OBJECT_TYPE* object, NODE_STRUCT** node, BYTE* index){
    if (head == NULL){
        *node = NULL;
    }else{
        NODE_STRUCT* current = head;
        while (current != NULL){
            for (BYTE j = 0; j < (*current).use; j++){
                if (*object == *((*current).object + j)){
                    *node = current;
                    *index = j;
                    return;
                }
            }
            current = (*current).next;
        }

        *node = NULL;
    }

    return;
}

void Compress (NODE_STRUCT *head){
    if (head == NULL){
        return;
    }
    NODE_STRUCT* node = head;

    while (node != NULL){
        if ((*node).use == SIZE){
            node = (*node).next;
        }else{
            NODE_STRUCT* next_node = (*node).next;

            if (next_node != NULL){
                *((*node).object + (*node).use) = *((*next_node).object);
                (*node).use++;
                    
                RemoveCurrent(&node, next_node, 0);
            }else{
                return;
            }
        }
    }
    

    return;
}

void ReverseNode (NODE_STRUCT* node){
    if (node == NULL){
        return;
    }
    int i = 0;
    int j = (*node).use - 1;

    while (i < j){
        OBJECT_TYPE temp = *((*node).object + i);
        *((*node).object + i) = *((*node).object + j);
        *((*node).object + j) = temp;
        i++;
        j--;
    }

    return;
}

void Reverse (NODE_STRUCT* head){
    if (head == NULL){
        return;
    }
    
    NODE_STRUCT* node = head;

    while (node != NULL){
        ReverseNode(node);
        node = (*node).next;
    }

    node = head;
    int list_size = 0;

    while (node != NULL){
        node = (*node).next;
        list_size++;
    }

    NODE_STRUCT* prev_node = head;
    NODE_STRUCT* next_node = head;

    OBJECT_TYPE object;

    int index = 0;
    while (index < list_size / 2){
        int temp_index = 0;

        temp_index = 0;
        while (temp_index < list_size - index - 1){
            next_node = (*next_node).next;
            temp_index++;
        }

        while (temp_index < index){
            prev_node = (*prev_node).next;
            temp_index++;
        }

        temp_index = 0;
        while (temp_index < (*next_node).use){
            object = *((*next_node).object + temp_index);
            *((*next_node).object + temp_index) = *((*prev_node).object + temp_index);
            *((*prev_node).object + temp_index) = object;
            temp_index++;
        }

        if ((*next_node).use < (*prev_node).use){
            temp_index = (*next_node).use;
            while (temp_index < (*prev_node).use){
                *((*next_node).object + temp_index) = *((*prev_node).object + temp_index);
                temp_index++;
            }
        } 

        index++;
    }

    Compress(head);

    return;
}

