//Karol Dziekan

#include "garden.hpp"
#include "tree.hpp"
#include "branch.hpp"
#include "fruit.hpp"

#define NULL 0



//Konstruktory i destruktor
GARDEN_CLASS::GARDEN_CLASS(){
    this->first_tree = NULL;
    this->last_tree = NULL;
    this->hole_after = NULL;
    this->count_trees = 0;
    this->count_fruits = 0;
    this->weight_fruits = 0;
    this->count_branches = 0;
}

GARDEN_CLASS::~GARDEN_CLASS(){
    TREE_CLASS* tree = this -> first_tree;
    while(tree != NULL){
        TREE_CLASS* tree_next = tree->getNextTreePointer();
        delete tree;
        tree = tree_next;
    }
    this->first_tree = NULL;
    this->last_tree = NULL;
    this->hole_after = NULL;
}

GARDEN_CLASS::GARDEN_CLASS(const GARDEN_CLASS& other, bool propagate) {
    this->first_tree = NULL;
    this->last_tree = NULL;
    this->hole_after = NULL;

    if (!propagate) {
        this->count_trees = other.count_trees;
        this->count_fruits = other.count_fruits;
        this->weight_fruits = other.weight_fruits;
        this->count_branches = other.count_branches;
    } else {
        this->count_trees = 0;
        this->count_fruits = 0;
        this->weight_fruits = 0;
        this->count_branches = 0;
    }

    TREE_CLASS* prev_new_tree = NULL;
    TREE_CLASS* curr_other_tree = other.first_tree;
    TREE_CLASS* new_hole_after = NULL;

    while (curr_other_tree != NULL) {
        TREE_CLASS* new_tree = new TREE_CLASS(*curr_other_tree, this, prev_new_tree, NULL, curr_other_tree->getNumber(), propagate);
        if (prev_new_tree == NULL) {
            this->first_tree = new_tree;
        } else {
            prev_new_tree->setNextTreePointer(new_tree);
            new_tree->setPrevTreePointer(prev_new_tree);
        }
        if (other.hole_after == curr_other_tree) {
            new_hole_after = new_tree;
        }
        prev_new_tree = new_tree;
        curr_other_tree = curr_other_tree->getNextTreePointer();
    }
    this->last_tree = prev_new_tree;
    this->hole_after = new_hole_after;
}

//Metody wymagane
unsigned int GARDEN_CLASS::getTreesTotal(){return this->count_trees;}
unsigned int GARDEN_CLASS::getBranchesTotal(){return this->count_branches;}
unsigned int GARDEN_CLASS::getFruitsTotal(){return this->count_fruits;}
unsigned int GARDEN_CLASS::getWeightsTotal(){return this->weight_fruits;}

void GARDEN_CLASS::plantTree() {
    TREE_CLASS* prev = NULL;
    TREE_CLASS* next = NULL;
    unsigned int new_number = 0;

    if (this->first_tree == NULL) {
        prev = NULL;
        next = NULL;
        new_number = 0;
    }else if (this->hole_after == NULL) {
        prev = NULL;
        next = this->first_tree;
        new_number = 0;
    }else{

        prev = this->hole_after;
        next = prev->getNextTreePointer();
        new_number = prev->getNumber() + 1;
    }

    //cout << "Zajmuje: " << new_number << endl;
    TREE_CLASS* tree = new TREE_CLASS(this, prev, next, new_number);

    if (prev) prev->setNextTreePointer(tree);
    else this->first_tree = tree;
    if (next) next->setPrevTreePointer(tree);
    else this->last_tree = tree;

    TREE_CLASS* curr = tree;
    while (curr != NULL && curr->getNextTreePointer() != NULL) {
        if (curr->getNextTreePointer()->getNumber() != curr->getNumber() + 1) {
            this->hole_after = curr;
            return;
        }
        curr = curr->getNextTreePointer();
    }

    this->hole_after = this->last_tree;
}

void GARDEN_CLASS::extractTree(unsigned int number) {
    if (this->first_tree == NULL || this->last_tree == NULL) return;

    TREE_CLASS* tree = NULL;
    if (this->first_tree->getNumber() == number) tree = this->first_tree;
    if (this->last_tree->getNumber() == number) tree = this->last_tree;
    if (tree == NULL) tree = this->getTreePointer(number);
    if (tree == NULL) return;

    if (tree->getPrevTreePointer() != NULL) tree->getPrevTreePointer()->setNextTreePointer(tree->getNextTreePointer());
    else this->first_tree = tree->getNextTreePointer();

    if (tree->getNextTreePointer() != NULL) tree->getNextTreePointer()->setPrevTreePointer(tree->getPrevTreePointer());
    else this->last_tree = tree->getPrevTreePointer();

    if (this -> hole_after != NULL) {
        unsigned int hole_number = this -> hole_after -> getNumber();
        unsigned int tree_number = tree -> getNumber();
        if (hole_number >= tree_number) {
            this -> hole_after = tree -> getPrevTreePointer();
        }
    }

    //cout << "Zwalniam: " << tree -> getNumber() << endl;
    delete tree;
}

void GARDEN_CLASS::cloneTree(unsigned int number) {
    TREE_CLASS* tree_to_clone = this->getTreePointer(number);
    if (tree_to_clone == NULL) return;

    TREE_CLASS* prev = NULL;
    TREE_CLASS* next = NULL;
    unsigned int new_number = 0;

    if (this->first_tree == NULL) {
        prev = NULL;
        next = NULL;
        new_number = 0;
    } else if (this->hole_after == NULL) {
        prev = NULL;
        next = this->first_tree;
        new_number = 0;
    } else {
        prev = this->hole_after;
        next = prev->getNextTreePointer();
        new_number = prev->getNumber() + 1;
    }

    //cout << "Zajmuje: " << new_number << endl;
    TREE_CLASS* new_tree = new TREE_CLASS(*tree_to_clone, this, prev, next, new_number, false);

    this->count_trees += 1;
    this->count_branches += new_tree->getBranchesTotal();
    this->count_fruits += new_tree->getFruitsTotal();
    this->weight_fruits += new_tree->getWeightsTotal();

    if (prev) prev->setNextTreePointer(new_tree);
    else this->first_tree = new_tree;
    if (next) next->setPrevTreePointer(new_tree);
    else this->last_tree = new_tree;

    TREE_CLASS* curr = new_tree;
    while (curr != NULL && curr->getNextTreePointer() != NULL) {
        if (curr->getNextTreePointer()->getNumber() > curr->getNumber() + 1) {
            this->hole_after = curr;
            return;
        }
        curr = curr->getNextTreePointer();
    }
    this->hole_after = this->last_tree;
}

void GARDEN_CLASS::growthGarden(){
    TREE_CLASS* tree = this->first_tree;
    while(tree != NULL){
        tree->growthTree();
        tree = tree->getNextTreePointer();
    }
}

void GARDEN_CLASS::fadeGarden(){
    TREE_CLASS* tree = this->first_tree;
    while(tree != NULL){
        tree->fadeTree();
        tree = tree->getNextTreePointer();
    }
}

void GARDEN_CLASS::harvestGarden(unsigned int length){
    TREE_CLASS* tree = this->first_tree;
    while(tree != NULL){
        tree->harvestTree(length);
        tree = tree->getNextTreePointer();
    }
}

TREE_CLASS* GARDEN_CLASS::getTreePointer(unsigned int number){
    if (this->first_tree == NULL || this->last_tree == NULL) return NULL;
    if (this->last_tree->getNumber() < number) return NULL;

    if (this->first_tree->getNumber() == number) return this->first_tree;
    if (this->last_tree->getNumber() == number) return this->last_tree;

    unsigned int first_num = this->first_tree->getNumber();
    unsigned int last_num = this->last_tree->getNumber();
    unsigned int avg = (first_num + last_num) / 2;

    if (number <= avg){
        TREE_CLASS* tree = this->first_tree;
        while(tree != NULL){
            if (tree->getNumber() == number){
                return tree;
            }
            if (tree->getNumber() > number){
                break;
            }
            tree = tree->getNextTreePointer();
        }
    }else{
        TREE_CLASS* tree = this->last_tree;
        while(tree != NULL){
            if (tree->getNumber() == number){
                return tree;
            }
            if (tree->getNumber() < number){
                break;
            }
            tree = tree->getPrevTreePointer();
        }
    }

    return NULL;
}



//Metody pomocnicze
void GARDEN_CLASS::changeWeights(int weight){this->weight_fruits += weight;}
void GARDEN_CLASS::changeFruitsCount(int count){this->count_fruits += count;}
void GARDEN_CLASS::changeBranchesCount(int count){this->count_branches += count;}
void GARDEN_CLASS::changeTreesCount(int count){this->count_trees += count;}