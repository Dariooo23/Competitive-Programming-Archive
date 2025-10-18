//Karol Dziekan

class FRUIT_CLASS;
class BRANCH_CLASS;
class TREE_CLASS;
class GARDEN_CLASS;

#define NULL 0



class GARDEN_CLASS{
    private:
        TREE_CLASS* first_tree;
        TREE_CLASS* last_tree;

        TREE_CLASS* hole_after;

        unsigned int count_trees;
        unsigned int count_fruits;
        unsigned int weight_fruits;
        unsigned int count_branches;



    public:
        //Konstruktory i Destruktor
        GARDEN_CLASS();
        GARDEN_CLASS(const GARDEN_CLASS&, bool = true);

        ~GARDEN_CLASS();



        //Metody wymagane
        unsigned int getTreesTotal();
        unsigned int getBranchesTotal();
        unsigned int getFruitsTotal();
        unsigned int getWeightsTotal();

        void plantTree();
        void cloneTree(unsigned int);
        void extractTree(unsigned int);

        void growthGarden();
        void fadeGarden();
        void harvestGarden(unsigned int);

        TREE_CLASS* getTreePointer(unsigned int);



        //Metody pomocnicze
        void changeWeights(int);
        void changeFruitsCount(int);
        void changeBranchesCount(int);
        void changeTreesCount(int);
};