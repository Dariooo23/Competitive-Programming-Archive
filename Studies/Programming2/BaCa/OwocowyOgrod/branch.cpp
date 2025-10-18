//Karol Dziekan

#include "garden.hpp"
#include "tree.hpp"
#include "branch.hpp"
#include "fruit.hpp"

#define NULL 0



//Konstruktory i Destruktor
BRANCH_CLASS::BRANCH_CLASS(){
    this -> ptr_to_tree = NULL;

    this -> prev_branch = NULL;
    this -> next_branch = NULL;

    this -> first_fruit = NULL;
    this -> last_fruit = NULL;

    this -> id_branch = 0;
    this -> length_branch = 0;

    this -> count_fruits = 0;
    this -> weight_fruits = 0;
}

BRANCH_CLASS::BRANCH_CLASS(TREE_CLASS* ptr_to_tree_arg, BRANCH_CLASS* prev_branch_arg, BRANCH_CLASS* next_branch_arg, unsigned int id_branch_arg){
    this -> ptr_to_tree = ptr_to_tree_arg;

    this -> prev_branch = prev_branch_arg;
    this -> next_branch = next_branch_arg;

    this -> first_fruit = NULL;
    this -> last_fruit = NULL;

    this -> id_branch = id_branch_arg;
    this -> length_branch = 0;

    this -> count_fruits = 0;
    this -> weight_fruits = 0;

    if (this -> ptr_to_tree != NULL) this -> ptr_to_tree -> changeBranchesCount(1);
}

BRANCH_CLASS::BRANCH_CLASS(const BRANCH_CLASS& branch_copy, TREE_CLASS* ptr_to_tree_copy, BRANCH_CLASS* prev_branch_copy, BRANCH_CLASS* next_branch_copy, unsigned int id_branch_copy, bool propagate) {
    this -> ptr_to_tree = ptr_to_tree_copy;
    this -> prev_branch = prev_branch_copy;
    this -> next_branch = next_branch_copy;

    if (id_branch_copy != 0) this -> id_branch = id_branch_copy;
    else this -> id_branch = branch_copy.id_branch;

    this -> length_branch = branch_copy.length_branch;

    this -> first_fruit = NULL;
    this -> last_fruit = NULL;

    FRUIT_CLASS* old_fruit = branch_copy.first_fruit;
    while(old_fruit != NULL){
        FRUIT_CLASS* new_fruit = new FRUIT_CLASS(*old_fruit, NULL, NULL, this, old_fruit -> getLength(), propagate);
        if (this -> first_fruit == NULL){
            this -> first_fruit = new_fruit;
            this -> last_fruit = new_fruit;
        }else{
            this -> last_fruit -> setNextFruitPointer(new_fruit);
            new_fruit -> setPrevFruitPointer(this -> last_fruit);
            this -> last_fruit = new_fruit;
        }
        old_fruit = old_fruit -> getNextFruitPointer();
    }

    if (propagate) {
        if (this -> ptr_to_tree != NULL) this -> ptr_to_tree -> changeBranchesCount(1);
    } else {
        this -> count_fruits = branch_copy.count_fruits;
        this -> weight_fruits = branch_copy.weight_fruits;
        // nie propagujemy liczników
    }
}

BRANCH_CLASS::~BRANCH_CLASS(){
    FRUIT_CLASS* fruit = this -> first_fruit;
    while(fruit != NULL){
        FRUIT_CLASS* fruit_next = fruit -> getNextFruitPointer();
        delete fruit;
        fruit = fruit_next;
    }

    if (this -> ptr_to_tree != NULL) this -> ptr_to_tree -> changeBranchesCount(-1);
    this -> ptr_to_tree = NULL;

    this -> prev_branch = NULL;
    this -> next_branch = NULL;

    this -> first_fruit = NULL;
    this -> last_fruit = NULL;

    this -> id_branch = 0;
    this -> length_branch = 0;
}



//Metody wymagane
unsigned int BRANCH_CLASS::getFruitsTotal(){return this -> count_fruits;}
unsigned int BRANCH_CLASS::getWeightsTotal(){return this -> weight_fruits;}
unsigned int BRANCH_CLASS::getHeight(){return this -> id_branch;}
unsigned int BRANCH_CLASS::getLength(){return this -> length_branch;}

void BRANCH_CLASS::growthBranch(){
    this -> length_branch += 1;
    
    FRUIT_CLASS* fruit = this -> first_fruit;
    while(fruit != NULL){
        fruit -> growthFruit();
        fruit = fruit -> getNextFruitPointer();
    }

    if (this -> length_branch % 2 == 0){
        FRUIT_CLASS* new_fruit = new FRUIT_CLASS(this -> length_branch, 0, this -> last_fruit, NULL, this);

        if (this -> length_branch == 2){
            this -> first_fruit = new_fruit;
            this -> last_fruit = new_fruit;
        }else{
            this -> last_fruit -> setNextFruitPointer(new_fruit);
            this -> last_fruit = new_fruit;
        }
    }
}

void BRANCH_CLASS::fadeBranch(){
    if (this -> length_branch == 0) return;
    
    this -> length_branch -= 1;

    FRUIT_CLASS* fruit = this -> first_fruit;
    while(fruit != NULL){
        fruit -> fadeFruit();
        fruit = fruit -> getNextFruitPointer();
    }

    if (this -> length_branch % 2 == 1){
        if (this -> length_branch == 1){
            delete this -> last_fruit;

            this -> first_fruit = NULL;
            this -> last_fruit = NULL;
        }
        if (this -> length_branch == 3){
            delete this -> last_fruit;

            this -> first_fruit -> setNextFruitPointer(NULL);
            this -> last_fruit = this -> first_fruit;
        }
        if (this -> length_branch >= 5){
            FRUIT_CLASS* delete_fruit = this -> last_fruit;
            this -> last_fruit = this -> last_fruit -> getPrevFruitPointer();
            this -> last_fruit -> setNextFruitPointer(NULL);

            delete delete_fruit;
        }
    }
}

void BRANCH_CLASS::harvestBranch(unsigned int weight){
    FRUIT_CLASS* fruit = this -> first_fruit;

    while(fruit != NULL){
        if (fruit -> getWeight() >= weight)fruit -> pluckFruit();
        fruit = fruit -> getNextFruitPointer();
    }
}

void BRANCH_CLASS::cutBranch(unsigned int length){
    if (this -> length_branch <= length)return;
    
    this -> length_branch = length;

    FRUIT_CLASS* fruit = this -> last_fruit;
    while (fruit != NULL){
        if (fruit -> getLength() > length){
            FRUIT_CLASS* fruit_next = fruit -> getPrevFruitPointer();

            delete fruit;

            fruit = fruit_next;
        }else{
            break;
        }
    }

    if (fruit == NULL){
        this -> first_fruit = NULL;
        this -> last_fruit = NULL;
    }
    if (fruit != NULL){
        this -> last_fruit = fruit;
        this -> last_fruit -> setNextFruitPointer(NULL);
    }
}

FRUIT_CLASS* BRANCH_CLASS::getFruitPointer(unsigned int length){
    if (this -> length_branch < length || length % 2 != 0) return NULL;
    if (this -> first_fruit == NULL || this -> last_fruit == NULL) return NULL;
    if (this -> first_fruit -> getLength() == length) return this -> first_fruit;
    if (this -> last_fruit -> getLength() == length) return this -> last_fruit;

    unsigned int first_num = this -> first_fruit -> getLength();
    unsigned int last_num = this -> last_fruit -> getLength();
    unsigned int avg = (first_num + last_num) / 2;

    if (length <= avg) {
        FRUIT_CLASS* fruit = this -> first_fruit;
        while(fruit != NULL){
            unsigned int fruit_length = fruit -> getLength();
            if (fruit_length == length) return fruit;
            if (fruit_length > length) break;
            fruit = fruit -> getNextFruitPointer();
        }
    } else {
        FRUIT_CLASS* fruit = this -> last_fruit;
        while(fruit != NULL){
            unsigned int fruit_length = fruit -> getLength();
            if (fruit_length == length) return fruit;
            if (fruit_length < length) break;
            fruit = fruit -> getPrevFruitPointer();
        }
    }
    return NULL;
}

TREE_CLASS* BRANCH_CLASS::getTreePointer(){return this -> ptr_to_tree;}



//Metody pomocnicze
void BRANCH_CLASS::changeWeights(int weight){
    this -> weight_fruits += weight;
    TREE_CLASS* tree = this -> getTreePointer();
    if (tree != NULL) tree -> changeWeights(weight);
    
}

void BRANCH_CLASS::changeFruitsCount(int count){
    this -> count_fruits += count;
    TREE_CLASS* tree = this -> getTreePointer();
    if (tree != NULL) tree -> changeFruitsCount(count);
}

BRANCH_CLASS* BRANCH_CLASS::getPrevBranchPointer(){return this -> prev_branch;}
BRANCH_CLASS* BRANCH_CLASS::getNextBranchPointer(){return this -> next_branch;}

void BRANCH_CLASS::setPrevBranchPointer(BRANCH_CLASS* prev_branch_ptr){this -> prev_branch = prev_branch_ptr;}
void BRANCH_CLASS::setNextBranchPointer(BRANCH_CLASS* next_branch_ptr){this -> next_branch = next_branch_ptr;}