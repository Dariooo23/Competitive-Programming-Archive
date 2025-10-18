//Karol Dziekan

#include "garden.hpp"
#include "tree.hpp"
#include "branch.hpp"
#include "fruit.hpp"

#define NULL 0



//Konstruktory i Destruktor
TREE_CLASS::TREE_CLASS(){
    this -> ptr_to_garden = NULL;

    this -> prev_tree = NULL;
    this -> next_tree = NULL;

    this -> first_branch = NULL;
    this -> last_branch = NULL;

    this -> id_tree = 0;
    this -> height_tree = 0;

    this -> count_fruits = 0;
    this -> weight_fruits = 0;
    this -> count_branches = 0;
}

TREE_CLASS::TREE_CLASS(GARDEN_CLASS* ptr_to_garden_arg, TREE_CLASS* prev_tree_arg, TREE_CLASS* next_tree_arg, unsigned int id_tree_arg){
    this -> ptr_to_garden = ptr_to_garden_arg;

    this -> prev_tree = prev_tree_arg;
    this -> next_tree = next_tree_arg;

    this -> first_branch = NULL;
    this -> last_branch = NULL;

    this -> id_tree = id_tree_arg;
    this -> height_tree = 0;

    this -> count_fruits = 0;
    this -> weight_fruits = 0;
    this -> count_branches = 0;

    this -> ptr_to_garden -> changeTreesCount(1);
}

TREE_CLASS::TREE_CLASS(const TREE_CLASS& tree_copy, GARDEN_CLASS* ptr_to_garden_copy, TREE_CLASS* prev_tree_copy, TREE_CLASS* next_tree_copy, unsigned int id_tree_copy, bool propagate) {
    this -> first_branch = NULL;
    this -> last_branch = NULL;

    this -> ptr_to_garden = ptr_to_garden_copy;
    if (propagate && this -> ptr_to_garden != NULL) this -> ptr_to_garden -> changeTreesCount(1);

    this -> prev_tree = prev_tree_copy;
    this -> next_tree = next_tree_copy;

    if (id_tree_copy != 1000000000) this -> id_tree = id_tree_copy;
    else this -> id_tree = tree_copy.id_tree;

    this -> height_tree = tree_copy.height_tree;

    BRANCH_CLASS* old_branch = tree_copy.first_branch;
    while(old_branch != NULL){
        BRANCH_CLASS* new_branch = new BRANCH_CLASS(*old_branch, this, NULL, NULL, old_branch -> getHeight(), propagate);
        if (this -> first_branch == NULL){
            this -> first_branch = new_branch;
            this -> last_branch = new_branch;
        }else{
            this -> last_branch -> setNextBranchPointer(new_branch);
            new_branch -> setPrevBranchPointer(this -> last_branch);
            this -> last_branch = new_branch;
        }
        old_branch = old_branch -> getNextBranchPointer();
    }

    if (!propagate) {
        this -> count_branches = tree_copy.count_branches;
        this -> count_fruits = tree_copy.count_fruits;
        this -> weight_fruits = tree_copy.weight_fruits;
    }
}

TREE_CLASS::~TREE_CLASS(){
    BRANCH_CLASS* branch = this -> first_branch;
    while(branch != NULL){
        BRANCH_CLASS* branch_next = branch -> getNextBranchPointer();
        delete branch;
        branch = branch_next;
    }

    if (this -> ptr_to_garden != NULL) this -> ptr_to_garden -> changeTreesCount(-1);
    this -> ptr_to_garden = NULL;

    this -> prev_tree = NULL;
    this -> next_tree = NULL;

    this -> first_branch = NULL;
    this -> last_branch = NULL;

    this -> id_tree = 0;
    this -> height_tree = 0;

    this -> count_fruits = 0;
    this -> weight_fruits = 0;
    this -> count_branches = 0;
}



//Metody wymagane
unsigned int TREE_CLASS::getBranchesTotal(){return this -> count_branches;}
unsigned int TREE_CLASS::getFruitsTotal(){return this -> count_fruits;}
unsigned int TREE_CLASS::getWeightsTotal(){return this -> weight_fruits;}
unsigned int TREE_CLASS::getNumber(){return this -> id_tree;}
unsigned int TREE_CLASS::getHeight(){return this -> height_tree;}

void TREE_CLASS::growthTree(){
    this -> height_tree += 1;

    BRANCH_CLASS* branch = this -> first_branch;
    while(branch != NULL){
        branch -> growthBranch();
        branch = branch -> getNextBranchPointer();
    }

    if (this -> height_tree % 3 == 0){
        BRANCH_CLASS* new_branch = new BRANCH_CLASS(this, this -> last_branch, NULL, this -> height_tree);
        if (this -> height_tree == 3){
            this -> first_branch = new_branch;
            this -> last_branch = new_branch;
        }else{
            this -> last_branch -> setNextBranchPointer(new_branch);
            new_branch -> setPrevBranchPointer(this -> last_branch);
            this -> last_branch = new_branch;
        }
    }
}

void TREE_CLASS::fadeTree(){
    if (this -> height_tree == 0) return;

    this -> height_tree -= 1;

    BRANCH_CLASS* branch = this -> first_branch;
    while(branch != NULL){
        branch -> fadeBranch();
        branch = branch -> getNextBranchPointer();
    }

    if (this -> height_tree % 3 == 2){
        if (this -> height_tree == 2){
            delete this -> last_branch;

            this -> first_branch = NULL;
            this -> last_branch = NULL;
        }
        if (this -> height_tree == 5){
            delete this -> last_branch;

            this -> first_branch -> setNextBranchPointer(NULL);
            this -> last_branch = this -> first_branch;
        }
        if (this -> height_tree >= 7){
            BRANCH_CLASS* delete_branch = this -> last_branch;
            this -> last_branch = this -> last_branch -> getPrevBranchPointer();
            this -> last_branch -> setNextBranchPointer(NULL);

            delete delete_branch;
        }
    }
}

void TREE_CLASS::harvestTree(unsigned int weight){
    BRANCH_CLASS* branch = this -> first_branch;
    while (branch != NULL){
        branch -> harvestBranch(weight);
        branch = branch -> getNextBranchPointer();
    }
}

void TREE_CLASS::cutTree(unsigned int height){
    if (this -> height_tree < height){
        return;
    }

    this -> height_tree = height;

    BRANCH_CLASS* branch = this -> last_branch;
    while (branch != NULL){
        if (branch -> getHeight() > height){
            BRANCH_CLASS* next_branch = branch -> getPrevBranchPointer();

            delete branch;

            branch = next_branch;
        }else{
            break;
        }
    }

    if (branch == NULL){
        this -> first_branch = NULL;
        this -> last_branch = NULL;
    }else{
        this -> last_branch = branch;
        this -> last_branch -> setNextBranchPointer(NULL);
    }
}

void TREE_CLASS::cloneBranch(BRANCH_CLASS* copy_branch){
    if (copy_branch == NULL) return;

    BRANCH_CLASS* branch = this -> first_branch;
    while (branch != NULL) {
        if (branch -> getLength() == 0) break;
        branch = branch -> getNextBranchPointer();
    }

    if (branch == NULL || branch -> getLength() != 0) return;

    BRANCH_CLASS* prev_branch = branch->getPrevBranchPointer();
    BRANCH_CLASS* next_branch = branch->getNextBranchPointer();

    BRANCH_CLASS* new_branch = new BRANCH_CLASS(*copy_branch, this, prev_branch, next_branch, branch -> getHeight());
    if (prev_branch != NULL) prev_branch->setNextBranchPointer(new_branch);
    else this -> first_branch = new_branch;
    if (next_branch != NULL) next_branch->setPrevBranchPointer(new_branch);
    else this -> last_branch = new_branch;

    delete branch;
}

GARDEN_CLASS* TREE_CLASS::getGardenPointer(){return this -> ptr_to_garden;}

BRANCH_CLASS* TREE_CLASS::getBranchPointer(unsigned int length){
    if (length == 0 || length % 3 != 0 || this -> height_tree < length){
        return NULL;
    }

    if (this -> first_branch == NULL || this -> last_branch == NULL) return NULL;
    if (this -> first_branch -> getHeight() == length) return this -> first_branch;
    if (this -> last_branch -> getHeight() == length) return this -> last_branch;

    unsigned int first_num = this -> first_branch -> getHeight();
    unsigned int last_num = this -> last_branch -> getHeight();
    unsigned int avg = (first_num + last_num) / 2;

    if (length <= avg) {
        BRANCH_CLASS* branch = this -> first_branch;
        while(branch != NULL){
            unsigned int branch_length = branch -> getHeight();
            if (branch_length == length){
                return branch;
            }
            if (branch_length > length){
                break;
            }
            branch = branch -> getNextBranchPointer();
        }
    } else {
        BRANCH_CLASS* branch = this -> last_branch;
        while(branch != NULL){
            unsigned int branch_length = branch -> getHeight();
            if (branch_length == length){
                return branch;
            }
            if (branch_length < length){
                break;
            }
            branch = branch -> getPrevBranchPointer();
        }
    }
    return NULL;
}



//Metody pomocnicze
void TREE_CLASS::changeWeights(int weight){
    this -> weight_fruits += weight;
    GARDEN_CLASS* garden = this -> getGardenPointer();
    if (garden != NULL) garden -> changeWeights(weight);
}

void TREE_CLASS::changeFruitsCount(int count){
    this -> count_fruits += count;
    GARDEN_CLASS* garden = this -> getGardenPointer();
    if (garden != NULL) garden -> changeFruitsCount(count);
}

void TREE_CLASS::changeBranchesCount(int count){
    this -> count_branches += count;
    GARDEN_CLASS* garden = this -> getGardenPointer();
    if (garden != NULL) garden -> changeBranchesCount(count);
}

TREE_CLASS* TREE_CLASS::getPrevTreePointer(){return this -> prev_tree;}
TREE_CLASS* TREE_CLASS::getNextTreePointer(){return this -> next_tree;}
void TREE_CLASS::setPrevTreePointer(TREE_CLASS* prev_tree_ptr){this -> prev_tree = prev_tree_ptr;}
void TREE_CLASS::setNextTreePointer(TREE_CLASS* next_tree_ptr){this -> next_tree = next_tree_ptr;}