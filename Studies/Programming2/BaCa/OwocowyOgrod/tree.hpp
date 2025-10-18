//Karol Dziekan

class FRUIT_CLASS;
class BRANCH_CLASS;
class TREE_CLASS;
class GARDEN_CLASS;

#define NULL 0



class TREE_CLASS{
    //Prywatne zmienne
    private:
        GARDEN_CLASS* ptr_to_garden;

        TREE_CLASS* prev_tree;
        TREE_CLASS* next_tree;

        BRANCH_CLASS* first_branch;
        BRANCH_CLASS* last_branch;

        unsigned int id_tree;
        unsigned int height_tree;

        unsigned int count_fruits;
        unsigned int weight_fruits;
        unsigned int count_branches;



    //Publiczne metody
    public:
        //Konstruktory i Destruktor
        TREE_CLASS();
        TREE_CLASS(GARDEN_CLASS*, TREE_CLASS*, TREE_CLASS*, unsigned int);
        TREE_CLASS(const TREE_CLASS&, GARDEN_CLASS* = NULL, TREE_CLASS* = NULL, TREE_CLASS* = NULL, unsigned int = 1000000000, bool = true);

        ~TREE_CLASS();



        //Metody wymagane
        unsigned int getBranchesTotal();
        unsigned int getFruitsTotal();
        unsigned int getWeightsTotal();
        unsigned int getNumber();
        unsigned int getHeight();

        void growthTree();
        void fadeTree();

        void harvestTree(unsigned int);
        void cutTree(unsigned int);

        void cloneBranch(BRANCH_CLASS*);

        GARDEN_CLASS* getGardenPointer();

        BRANCH_CLASS* getBranchPointer(unsigned int);


        
        //Metody pomocnicze
        void changeWeights(int);
        void changeFruitsCount(int);
        void changeBranchesCount(int);

        TREE_CLASS* getPrevTreePointer();
        TREE_CLASS* getNextTreePointer();

        void setPrevTreePointer(TREE_CLASS*);
        void setNextTreePointer(TREE_CLASS*);
};