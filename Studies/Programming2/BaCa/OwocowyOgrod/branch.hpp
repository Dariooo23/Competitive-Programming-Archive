//Karol Dziekan

class FRUIT_CLASS;
class BRANCH_CLASS;
class TREE_CLASS;
class GARDEN_CLASS;

#define NULL 0



class BRANCH_CLASS{
    //Prywatne zmienne
    private:
        TREE_CLASS* ptr_to_tree;

        BRANCH_CLASS* prev_branch;
        BRANCH_CLASS* next_branch;

        FRUIT_CLASS* first_fruit;
        FRUIT_CLASS* last_fruit;

        unsigned int id_branch;
        unsigned int length_branch;

        unsigned int count_fruits;
        unsigned int weight_fruits;



    //Publiczne metody
    public:
        //Konstruktory i Destruktor
        BRANCH_CLASS();
        BRANCH_CLASS(TREE_CLASS*, BRANCH_CLASS*, BRANCH_CLASS*, unsigned int);
        BRANCH_CLASS(const BRANCH_CLASS&, TREE_CLASS* = NULL, BRANCH_CLASS* = NULL, BRANCH_CLASS* = NULL, unsigned int = 0, bool = true);

        ~BRANCH_CLASS();



        //Metody wymagane
        unsigned int getFruitsTotal();
        unsigned int getWeightsTotal();
        unsigned int getHeight();
        unsigned int getLength();

        void growthBranch();
        void fadeBranch();

        void harvestBranch(unsigned int);

        void cutBranch(unsigned int);

        FRUIT_CLASS* getFruitPointer(unsigned int);

        TREE_CLASS* getTreePointer();



        //Metody pomocnicze
        void changeWeights(int);
        void changeFruitsCount(int);

        BRANCH_CLASS* getPrevBranchPointer();
        BRANCH_CLASS* getNextBranchPointer();

        void setPrevBranchPointer(BRANCH_CLASS*);
        void setNextBranchPointer(BRANCH_CLASS*);
};