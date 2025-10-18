//Karol Dziekan

class FRUIT_CLASS;
class BRANCH_CLASS;
class TREE_CLASS;
class GARDEN_CLASS;

#define NULL 0



class FRUIT_CLASS{
    //Prywatne zmienne
    private:
        FRUIT_CLASS* prev_fruit;
        FRUIT_CLASS* next_fruit;

        BRANCH_CLASS* ptr_to_branch;

        unsigned int id_fruit;
        
        unsigned int weight_fruit;



    //Publiczne metody
    public:
        //Konstruktory i Destruktor
        FRUIT_CLASS();
        FRUIT_CLASS(const FRUIT_CLASS&, FRUIT_CLASS* = NULL, FRUIT_CLASS* = NULL, BRANCH_CLASS* = NULL, unsigned int = 0, bool = true);
        FRUIT_CLASS(unsigned int, unsigned int, FRUIT_CLASS*, FRUIT_CLASS*, BRANCH_CLASS*);

        ~FRUIT_CLASS();



        //Metody wymagane
        unsigned int getLength();
        unsigned int getWeight();

        void growthFruit();
        void fadeFruit();
        void pluckFruit();

        BRANCH_CLASS* getBranchPointer();



        //Metody pomocnicze
        FRUIT_CLASS* getPrevFruitPointer();
        FRUIT_CLASS* getNextFruitPointer();

        void setPrevFruitPointer(FRUIT_CLASS*);
        void setNextFruitPointer(FRUIT_CLASS*);

        void changeWeights(int);
};