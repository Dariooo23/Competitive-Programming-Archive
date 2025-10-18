//Karol Dziekan

#include <iostream>
#include <string>

using namespace std;



//------------------------------ KLASA PLAYER ------------------------------
class PLAYER_CLASS {
    friend class CAESAR_CLASS;
    friend class ARENA_CLASS;
    friend class SQUAD_CLASS;

    public:
        unsigned int maxHealth;
        unsigned int health;
        unsigned int attack;
        unsigned int agility;
        unsigned int defense;

        virtual unsigned int getRemainingHealth() = 0;
        virtual unsigned int getDamage() = 0;
        virtual unsigned int getAgility() = 0;
        virtual void takeDamage(unsigned int) = 0;
        virtual void applyWinnerReward() = 0;
        virtual void cure() = 0;
        virtual void printParams() = 0;
        virtual string getID();

    protected:
        virtual void die() = 0;
};

string PLAYER_CLASS::getID() {return "";}



//------------------------------ KLASA CAESAR ------------------------------
class CAESAR_CLASS {
    public:
        void judgeDeathOrLife(PLAYER_CLASS* player);
};

static int verdictCounter = 0;
void CAESAR_CLASS::judgeDeathOrLife(PLAYER_CLASS* player) {
    if (player->getRemainingHealth() == 0){
        player->die();
        return;
    }

    verdictCounter++;
    if (verdictCounter % 3 == 0) player->die();
}



//------------------------------ KLASA ARENA ------------------------------
class ARENA_CLASS {
    private:
        CAESAR_CLASS* caesar;
    public:
        ARENA_CLASS(CAESAR_CLASS* caesarPtr);
        void fight(PLAYER_CLASS* player1, PLAYER_CLASS* player2);
};

ARENA_CLASS::ARENA_CLASS(CAESAR_CLASS* caesarPtr) {caesar = caesarPtr;}

void ARENA_CLASS::fight(PLAYER_CLASS* player1, PLAYER_CLASS* player2) {
    if (player1->getRemainingHealth() == 0 || player2->getRemainingHealth() == 0) return;

    PLAYER_CLASS* first;
    PLAYER_CLASS* second;
    if (player1->getAgility() >= player2->getAgility()) {
        first = player1;
        second = player2;
    } else {
        first = player2;
        second = player1;
    }

    first->printParams();
    second->printParams();

    int attackCount = 0;

    while (true) {
        second->takeDamage(first->getDamage());
        attackCount++;
        if (second->getRemainingHealth() == 0) second->die();
        second->printParams();
        if (first->getRemainingHealth() < 10 || second->getRemainingHealth() < 10 || attackCount >= 40) break;

        
        first->takeDamage(second->getDamage());
        attackCount++;
        if (first->getRemainingHealth() == 0) first->die();
        first->printParams();
        if (first->getRemainingHealth() < 10 || second->getRemainingHealth() < 10 || attackCount >= 40) break;
    }

    if (first->getRemainingHealth() > 0) {
        if(attackCount %2 == 0)caesar->judgeDeathOrLife(first);
        else verdictCounter++;
        first->printParams();
        if (first->getRemainingHealth() > 0) {
            first->applyWinnerReward();
            first->cure();
        }
    }
    if (second->getRemainingHealth() > 0) {
        if(attackCount %2 == 0)caesar->judgeDeathOrLife(second);
        else verdictCounter++;
        second->printParams();
        if (second->getRemainingHealth() > 0) {
            second->applyWinnerReward();
            second->cure();
        }
    }

    first->printParams();
    second->printParams();
}



//------------------------------ KLASA HUMAN ------------------------------
class HUMAN_CLASS : public virtual PLAYER_CLASS {
    public:
        string identifier;

        HUMAN_CLASS(const string& id);

        unsigned int getRemainingHealth();
        unsigned int getDamage();
        unsigned int getAgility();
        void takeDamage(unsigned int);
        void applyWinnerReward();
        void cure();
        void printParams();
        string getID();

    protected:
        void die();
};

HUMAN_CLASS::HUMAN_CLASS(const string& id) {
    identifier = id;
    maxHealth = 200;
    health = 200;
    attack = 30;
    agility = 10;
    defense = 10;
}

string HUMAN_CLASS::getID(){
    return identifier;
}

unsigned int HUMAN_CLASS::getRemainingHealth() {return (health * 100) / maxHealth;}
unsigned int HUMAN_CLASS::getDamage() {return attack;}
unsigned int HUMAN_CLASS::getAgility() {return agility;}
void HUMAN_CLASS::applyWinnerReward() {attack += 2; agility += 2;}
void HUMAN_CLASS::cure() {health = maxHealth;}
void HUMAN_CLASS::die() {health = 0;}

void HUMAN_CLASS::takeDamage(unsigned int dmg) {
    if (dmg <= defense + agility) return;
    else dmg -= (defense + agility);

    if (dmg >= health) health = 0;
    else health -= dmg;
}

void HUMAN_CLASS::printParams() {
    if (getRemainingHealth() > 0) cout << identifier << ":" << maxHealth << ":" << health << ":" << getRemainingHealth() << "%:" << attack << ":" << agility << ":" << defense << endl;
    else cout << identifier << ":R.I.P." << endl;
}



//------------------------------ KLASA BEAST ------------------------------
class BEAST_CLASS : public virtual PLAYER_CLASS {
    public:
        string identifier;

        BEAST_CLASS(const string& id);

        unsigned int getRemainingHealth();
        unsigned int getDamage();
        unsigned int getAgility();
        void takeDamage(unsigned int);
        void applyWinnerReward();
        void cure();
        void printParams();
        string getID();

    protected:
        void die();
};

BEAST_CLASS::BEAST_CLASS(const string& id) {
    identifier = id;
    maxHealth = 150;
    health = 150;
    attack = 40;
    agility = 20;
    defense = -1;
}

string BEAST_CLASS::getID(){
    return identifier;
}

unsigned int BEAST_CLASS::getRemainingHealth() {return (health * 100) / maxHealth;}
unsigned int BEAST_CLASS::getAgility() {return agility;}
void BEAST_CLASS::applyWinnerReward() {attack += 2; agility += 2;}
void BEAST_CLASS::cure() {health = maxHealth;}
void BEAST_CLASS::die() {health = 0;}

unsigned int BEAST_CLASS::getDamage() {
    if (getRemainingHealth() < 25) return 2 * attack;
    else return attack;
}

void BEAST_CLASS::printParams() {
    if (health > 0) cout << identifier << ":" << maxHealth << ":" << health << ":" << getRemainingHealth() << "%:" << getDamage() << ":" << agility << endl;
    else cout << identifier << ":R.I.P." << endl;
}

void BEAST_CLASS::takeDamage(unsigned int dmg) {
    if (dmg <= agility / 2) return;
    else dmg -= agility /2;

    if (dmg >= health) health = 0;
    else health -= dmg;
}



//------------------------------ KLASA BERSERKER ------------------------------
class BERSERKER_CLASS : public HUMAN_CLASS, public BEAST_CLASS {
    public:
        BERSERKER_CLASS(const string& idHuman, const string& idBeast);

        unsigned int getRemainingHealth();
        unsigned int getDamage();
        unsigned int getAgility();
        void takeDamage(unsigned int);
        void applyWinnerReward();
        void cure();
        void printParams();
        string getID();

    protected:
        void die();
};

BERSERKER_CLASS::BERSERKER_CLASS(const string& idHuman, const string& idBeast) : HUMAN_CLASS(idHuman), BEAST_CLASS(idBeast) {
    HUMAN_CLASS::maxHealth = 200;
    HUMAN_CLASS::health = 200;
    HUMAN_CLASS::attack = 35;
    HUMAN_CLASS::agility = 5;
    HUMAN_CLASS::defense = 15;
}

string BERSERKER_CLASS::getID(){
    if (getRemainingHealth() < 25 && getRemainingHealth() > 0){
        return BEAST_CLASS::getID();
    }else{
        return HUMAN_CLASS::getID();
    }
}

unsigned int BERSERKER_CLASS::getRemainingHealth() {return HUMAN_CLASS::getRemainingHealth();}
void BERSERKER_CLASS::applyWinnerReward() {HUMAN_CLASS::applyWinnerReward();}
void BERSERKER_CLASS::cure() {HUMAN_CLASS::cure();}
void BERSERKER_CLASS::die() {HUMAN_CLASS::die();}

unsigned int BERSERKER_CLASS::getDamage() {
    if (getRemainingHealth() < 25) {
        BEAST_CLASS::health = HUMAN_CLASS::health;
        BEAST_CLASS::attack = HUMAN_CLASS::getDamage();
        BEAST_CLASS::agility = HUMAN_CLASS::getAgility();
        BEAST_CLASS::maxHealth = HUMAN_CLASS::maxHealth;
        return BEAST_CLASS::getDamage();
    } else {
        return HUMAN_CLASS::getDamage();
    }
}

unsigned int BERSERKER_CLASS::getAgility() {
    if (getRemainingHealth() < 25) {
        BEAST_CLASS::health = HUMAN_CLASS::health;
        BEAST_CLASS::attack = HUMAN_CLASS::getDamage();
        BEAST_CLASS::agility = HUMAN_CLASS::getAgility();
        BEAST_CLASS::maxHealth = HUMAN_CLASS::maxHealth;
        return BEAST_CLASS::getAgility();
    } else {
        return HUMAN_CLASS::getAgility();
    }
}

void BERSERKER_CLASS::takeDamage(unsigned int dmg) {
    if (getRemainingHealth() < 25) {
        BEAST_CLASS::health = HUMAN_CLASS::health;
        BEAST_CLASS::attack = HUMAN_CLASS::getDamage();
        BEAST_CLASS::agility = HUMAN_CLASS::getAgility();
        BEAST_CLASS::maxHealth = HUMAN_CLASS::maxHealth;
        BEAST_CLASS::takeDamage(dmg);
        HUMAN_CLASS::health = BEAST_CLASS::health;
    } else {
        HUMAN_CLASS::takeDamage(dmg);
    }
}

void BERSERKER_CLASS::printParams() {
    if (getRemainingHealth() < 25 && getRemainingHealth() > 0) {
        BEAST_CLASS::health = HUMAN_CLASS::health;
        BEAST_CLASS::attack = HUMAN_CLASS::getDamage();
        BEAST_CLASS::agility = HUMAN_CLASS::getAgility();
        BEAST_CLASS::maxHealth = HUMAN_CLASS::maxHealth;
        BEAST_CLASS::printParams();
    } else {
        HUMAN_CLASS::printParams();
    }
}



//------------------------------ KLASA SQUAD ------------------------------
class SQUAD_CLASS : public PLAYER_CLASS {
    private:
        struct node {
            PLAYER_CLASS* member;
            node* next;
            node(PLAYER_CLASS* m, node* n = 0) : member(m), next(n) {}
        };
        node* head;
        node* tail;

        string identifier;
        int memberCount;

        void updateStats();

    public:
        SQUAD_CLASS(const string& id);
        ~SQUAD_CLASS();

        void addPlayer(PLAYER_CLASS* player);

        unsigned int getRemainingHealth();
        unsigned int getDamage();
        unsigned int getAgility();
        void takeDamage(unsigned int);
        void applyWinnerReward();
        void cure();
        void printParams();

    protected:
        void sortMembers();
        void die();
};

SQUAD_CLASS::SQUAD_CLASS(const string& id) {
    identifier = id;
    head = 0;
    tail = 0;
    memberCount = 0;
    agility = 0;
    health = 0;
    attack = 0;
}

SQUAD_CLASS::~SQUAD_CLASS() {
    node* current = head;
    while (current) {
        node* next = current->next;
        delete current;
        current = next;
    }
    head = 0;
    tail = 0;
}

void SQUAD_CLASS::updateStats() {
    node* prev = 0;
    node* current = head;
    while (current) {
        node* next = current->next;
        if (current->member->getRemainingHealth() == 0) {
            if (prev) prev->next = next;
            else head = next;
            if (current == tail) tail = prev;
            delete current;
            current = next;
        } else {
            prev = current;
            current = next;
        }
    }
    if (!head) {
        tail = 0;
        agility = 0;
        health = 0;
        attack = 0;
        memberCount = 0;
        return;
    }
    unsigned int minAgility = head->member->getAgility();
    unsigned int maxHealth = head->member->getRemainingHealth();
    unsigned int sumDamage = 0;
    int count = 0;
    current = head;
    while (current) {
        unsigned int agi = current->member->getAgility();
        unsigned int hp = current->member->getRemainingHealth();
        unsigned int dmg = current->member->getDamage();
        if (agi < minAgility) minAgility = agi;
        if (hp > maxHealth) maxHealth = hp;
        sumDamage += dmg;
        count++;
        current = current->next;
    }
    agility = minAgility;
    health = maxHealth;
    attack = sumDamage;
    memberCount = count;
}

unsigned int SQUAD_CLASS::getAgility() { 
    updateStats();
    return agility; 
}

unsigned int SQUAD_CLASS::getDamage() { 
    updateStats();
    return attack; 
}

unsigned int SQUAD_CLASS::getRemainingHealth() { 
    updateStats();
    return health; 
}

void SQUAD_CLASS::addPlayer(PLAYER_CLASS* player) {
    updateStats();

    node* current = head;
    while (current) {
        if (current->member == player) return;
        current = current->next;
    }
    node* newNode = new node(player, 0);
    if (!head) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    updateStats();
}

void SQUAD_CLASS::takeDamage(unsigned int enemyAttack) {
    updateStats();
    if (memberCount == 0) return;
    unsigned int baseDamage = enemyAttack / memberCount;
    node* current = head;
    while (current) {
        current->member->takeDamage(baseDamage);
        current = current->next;
    }
    updateStats();
}

void SQUAD_CLASS::applyWinnerReward() {
    updateStats();
    node* current = head;
    while (current) {
        current->member->applyWinnerReward();
        current = current->next;
    }
    updateStats();
}

void SQUAD_CLASS::cure() {
    updateStats();
    node* current = head;
    while (current) {
        current->member->cure();
        current = current->next;
    }
    updateStats();
}

void SQUAD_CLASS::die() {
    updateStats();
    node* current = head;
    while (current) {
        current->member->die();
        current = current->next;
    }
    updateStats();
}

void SQUAD_CLASS::sortMembers() {
    if (!head || !head->next) return;

    bool swapped;
    do {
        swapped = false;
        node* curr = head;
        node* next = head->next;

        while (next) {
            PLAYER_CLASS* a = curr->member;
            PLAYER_CLASS* b = next->member;

            string idA = a->getID();
            string idB = b->getID();
            unsigned int defA = a->defense;
            unsigned int defB = b->defense;
            unsigned int maxHealthA = a->maxHealth, maxHealthB = b->maxHealth;
            unsigned int healthA = a->health, healthB = b->health;
            unsigned int hpPercA = a->getRemainingHealth(), hpPercB = b->getRemainingHealth();
            unsigned int dmgA = a->getDamage(), dmgB = b->getDamage();
            unsigned int agiA = a->getAgility(), agiB = b->getAgility();

            bool shouldSwap = false;
            if (idA > idB) shouldSwap = true;
            else if (idA == idB && maxHealthA > maxHealthB) shouldSwap = true;
            else if (idA == idB && maxHealthA == maxHealthB && healthA > healthB) shouldSwap = true;
            else if (idA == idB && maxHealthA == maxHealthB && healthA == healthB && hpPercA > hpPercB) shouldSwap = true;
            else if (idA == idB && maxHealthA == maxHealthB && healthA == healthB && hpPercA == hpPercB && dmgA > dmgB) shouldSwap = true;
            else if (idA == idB && maxHealthA == maxHealthB && healthA == healthB && hpPercA == hpPercB && dmgA == dmgB && agiA > agiB) shouldSwap = true;
            else if (idA == idB && maxHealthA == maxHealthB && healthA == healthB && hpPercA == hpPercB && dmgA == dmgB && agiA == agiB && defA > defB) shouldSwap = true;

            if (shouldSwap) {
                swap(curr->member, next->member);
                swapped = true;
            }
            curr = next;
            next = next->next;
        }
    } while (swapped);
}

void SQUAD_CLASS::printParams() {
    updateStats();
    if (!head) {
        cout << identifier << ":nemo" << endl;
        return;
    }
    cout << identifier << ":" << memberCount << ":" << getRemainingHealth() << "%:" << getDamage() << ":" << getAgility() << endl;

    sortMembers();
    node* current = head;
    while (current) {
        current->member->printParams();
        current = current->next;
    }
}
