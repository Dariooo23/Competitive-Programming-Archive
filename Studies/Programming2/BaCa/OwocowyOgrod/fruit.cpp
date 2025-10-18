// Karol Dziekan

#include "garden.hpp"
#include "tree.hpp"
#include "branch.hpp"
#include "fruit.hpp"

#define NULL 0



// Konstruktory i Destruktor
FRUIT_CLASS::FRUIT_CLASS(){
    this -> prev_fruit = NULL;
    this -> next_fruit = NULL;
    this -> ptr_to_branch = NULL;

    this -> id_fruit = 0;
    this -> weight_fruit = 0;
}

FRUIT_CLASS::FRUIT_CLASS(const FRUIT_CLASS &fruit_arg, FRUIT_CLASS *prev_fruit_arg, FRUIT_CLASS *next_fruit_arg, BRANCH_CLASS *ptr_to_branch_arg, unsigned int id_fruit_arg, bool propagate) {
    this -> prev_fruit = prev_fruit_arg;
    this -> next_fruit = next_fruit_arg;
    this -> ptr_to_branch = ptr_to_branch_arg;

    if (id_fruit_arg != 0) this -> id_fruit = id_fruit_arg;
    else this -> id_fruit = fruit_arg.id_fruit;

    if (propagate) {
        this -> weight_fruit = 0;
        this -> changeWeights(fruit_arg.weight_fruit);
        if (this -> ptr_to_branch != NULL) this -> ptr_to_branch -> changeFruitsCount(1);
    } else {
        this -> weight_fruit = fruit_arg.weight_fruit;
    }
}

FRUIT_CLASS::FRUIT_CLASS(unsigned int id_fruit_arg, unsigned int weight_fruit_arg, FRUIT_CLASS *prev_fruit_arg, FRUIT_CLASS *next_fruit_arg, BRANCH_CLASS *ptr_to_branch_arg){
    this -> prev_fruit = prev_fruit_arg;
    this -> next_fruit = next_fruit_arg;
    this -> ptr_to_branch = ptr_to_branch_arg;
    this -> id_fruit = id_fruit_arg;

    this -> weight_fruit = 0;
    this -> changeWeights(weight_fruit_arg);
    if (this -> ptr_to_branch != NULL)this -> ptr_to_branch -> changeFruitsCount(1);
}

FRUIT_CLASS::~FRUIT_CLASS(){
    this -> pluckFruit();
    if (this -> ptr_to_branch != NULL) this -> ptr_to_branch -> changeFruitsCount(-1);

    this -> prev_fruit = NULL;
    this -> next_fruit = NULL;
    this -> ptr_to_branch = NULL;
    this -> id_fruit = 0;
}



// Metody wymagane
unsigned int FRUIT_CLASS::getLength(){return this -> id_fruit;}
unsigned int FRUIT_CLASS::getWeight(){return this -> weight_fruit;}
void FRUIT_CLASS::growthFruit(){this -> changeWeights(1);}
void FRUIT_CLASS::fadeFruit(){if (this -> weight_fruit != 0)this -> changeWeights(-1);}
void FRUIT_CLASS::pluckFruit(){this -> changeWeights(-(this -> weight_fruit));}
BRANCH_CLASS *FRUIT_CLASS::getBranchPointer(){return this -> ptr_to_branch;}



// Metody pomocnicze
FRUIT_CLASS *FRUIT_CLASS::getPrevFruitPointer(){return this -> prev_fruit;}
FRUIT_CLASS *FRUIT_CLASS::getNextFruitPointer(){return this -> next_fruit;}

void FRUIT_CLASS::setPrevFruitPointer(FRUIT_CLASS *fruit){this -> prev_fruit = fruit;}
void FRUIT_CLASS::setNextFruitPointer(FRUIT_CLASS *fruit){this -> next_fruit = fruit;}

void FRUIT_CLASS::changeWeights(int weight){
    this -> weight_fruit += weight;
    BRANCH_CLASS *branch = this -> getBranchPointer();
    if (branch != NULL)branch -> changeWeights(weight);
}