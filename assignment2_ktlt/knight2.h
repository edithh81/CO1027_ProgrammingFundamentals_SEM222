#ifndef __KNIGHT2_H__
#define __KNIGHT2_H__

#include "main.h"
// các class (tiền khai báo)
class BaseBag;
class BaseOpponent;
class MadBear;
class Bandit;
class LordLupin;
class Elf;
class Troll;
class Tornbery;
class QueenOfCards;
class NinadeRings;
class DurianGarden;
class OmegaWeapon;
class Hades;
class BaseKnight;
class PaladinKnight;
class LancelotKnight;
class DragonKnight;
class NormalKnight;
class ArmyKnights;
class BaseItem;
class Antidote;
class PhoenixI;
class PhoenixII;
class PhoenixIII;
class PhoenixIV;
class Events;
class KnightAdventure;
// #define DEBUG

enum ItemType {ANTIDOTE=0, PHOENIXI,PHOENIXII,PHOENIXIII,PHOENIXIV};
enum KnightType { PALADIN = 0, LANCELOT, DRAGON, NORMAL };
const double baseDame[6]={0,10,15,45,75,95};
const int gilcollect[6]={0,100,150,450,750,800};  

// Basebag
class BaseBag {
private:
int recsize;
int maxsize;
BaseKnight *knight=nullptr;
struct Node{
    BaseItem *item;
    Node *next;
};  
Node *head=nullptr;
public:
    void setrecsize(int size);
    void setmaxsize(int max);
    int getmaxsize();
    int getrecsize();
    BaseBag(BaseKnight* knight, int a, int b);
    ~BaseBag();
    Node *newnode(BaseItem *item);
    virtual bool insertFirst(BaseItem * item);
    virtual BaseItem * get(ItemType itemType);
    virtual void deleteFirst();
    virtual void swapItem(Node *node);
    virtual string toString() const;
    virtual BaseItem *getPhoenix();
    Node *getHead(BaseBag *bag);
};
//
class BaseOpponent{
    protected:
    int levelO;
    int eventid;
    int index;
    public:
    
    virtual void setlevelO();
    virtual int getlevelO();
    virtual void seteventid(){};
    virtual int geteventid()=0;
    BaseOpponent(int i, int eventid);
    ~BaseOpponent();
    static BaseOpponent *createOPP(int i, int eventid); 
    virtual void attack(ArmyKnights *army, int eventid);
};
class MadBear:public BaseOpponent{
   private:
   public:
   MadBear(int i, int eventid):BaseOpponent(i, eventid){}
   void seteventid();
   int geteventid();
};
class Bandit:public BaseOpponent{
   private:
   public:
   Bandit(int i, int eventid):BaseOpponent(i, eventid){}
   void seteventid();
   int geteventid();
};
class LordLupin:public BaseOpponent{
   private:
   public:
   LordLupin(int i, int eventid):BaseOpponent(i, eventid){}
   void seteventid();
   int geteventid();
};
class Elf:public BaseOpponent{
   private:
   public:
   Elf(int i, int eventid):BaseOpponent(i, eventid){}
   void seteventid();
   int geteventid();
};
class Troll:public BaseOpponent{
   private:
   public:
   Troll(int i, int eventid):BaseOpponent(i, eventid){}
   void seteventid();
   int geteventid();
};
class Tornbery:public BaseOpponent{
   private:
   public:
   Tornbery(int i, int eventid):BaseOpponent(i, eventid){}
   void seteventid();
   int geteventid();
   void attack(ArmyKnights *army, int eventid);
};
class QueenOfCards:public BaseOpponent{
   private:
   public:
   QueenOfCards(int i, int eventid):BaseOpponent(i, eventid){}
   void seteventid();
   int geteventid();
   void attack(ArmyKnights *army, int eventid);
};
class NinadeRings:public BaseOpponent{
    private:
    public:
    NinadeRings(int i, int eventid): BaseOpponent(i, eventid){}
    void seteventid();
    int geteventid();
    void attack(ArmyKnights *army, int eventid);
};
class DurianGarden:public BaseOpponent
{
    private:
    public:
    DurianGarden(int i, int eventid):BaseOpponent(i,eventid){}
    void seteventid();
    int geteventid();
    void attack(ArmyKnights *army, int eventid);
};
class OmegaWeapon:public BaseOpponent{
   private:
   public:
   OmegaWeapon(int i, int eventid):BaseOpponent(i, eventid){}
   void seteventid();
   int geteventid();
   void attack(ArmyKnights *army, int eventid);
};
class Hades: public BaseOpponent{
   private:
   public:
   Hades(int i, int eventid):BaseOpponent(i, eventid){}
   void seteventid();
   int geteventid();
   void attack(ArmyKnights *army, int eventid);
};
//
class BaseKnight {
protected:
    int id;
    int hp;
    int maxhp;
    int level;
    int gil;
    int antidote;
    BaseBag *bag=nullptr;
    KnightType knightType;  
public:
    BaseKnight(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI, KnightType type);
    ~BaseKnight(); 
    static bool isPaladin(int maxhp);
    static bool isLancelot(int maxhp);
    static bool isDragon(int maxhp);
    static BaseKnight * create(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI);
    string toString() const;
    void sethp(int hp);
    int gethp();
    void setgil(int gil);
    int getgil();
    void setlevel(int level);
    int getlevel();
    bool checkPhoenix();
    int getmaxHP();
    BaseBag *getbag();
    bool checkAntidote();
    KnightType getType();
};
class PaladinKnight:public BaseKnight
{
  public:
  PaladinKnight(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI)
  :BaseKnight(id,maxhp, level, gil, antidote, phoenixdownI, PALADIN){}
  void setsizeofbag();
};
class LancelotKnight:public BaseKnight
{
  public:
  LancelotKnight(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI)
  :BaseKnight(id,maxhp, level, gil, antidote, phoenixdownI, LANCELOT){}
  void setsizeofbag();
};
class DragonKnight:public BaseKnight
{
  public:
  DragonKnight(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI)
  :BaseKnight(id,maxhp, level, gil, antidote, phoenixdownI, DRAGON){}
  void setsizeofbag();
};
class NormalKnight: public BaseKnight
{
    public:
    NormalKnight(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI)
    :BaseKnight(id,maxhp, level, gil, antidote, phoenixdownI, NORMAL){}
    void setsizeofbag();
};
// ArmyKnights
class ArmyKnights {
private:
int curnumofK;
int numofK;
bool meetOmega;
bool meetHades;
bool palashield, lancespear, guienehair, excalibursw;
BaseKnight **knighti=nullptr;
public:
    ArmyKnights (const string & file_armyknights);
    ~ArmyKnights();
    bool fight(BaseOpponent * opponent);
    bool fightUltimecia();
    bool adventure (Events * events);
    int count() const;
    void setArmy();
    void resetArmy();
    BaseKnight *getKnight(int index);
    BaseKnight * lastKnight() const;
    void transgil(ArmyKnights *army, int gilcollect);
    bool checklastK();
    
    void setArmywUlti(int i);
    void setmeetOmega();
    void setmeetHades();
    void setPaladinShield();
    void setLancelotSpear();
    void setGuinevereHair();
    void setExcaliburSword();
    bool hasPaladinShield() const;
    bool hasLancelotSpear() const;
    bool hasGuinevereHair() const;
    bool hasExcaliburSword() const;
    void pickPhoenixdownII();
    void pickPhoenixdownIII();
    void pickPhoenixdownIV();

    void printInfo() const;
    void printResult(bool win) const;
};
// BaseItem
class BaseItem {
private:
ItemType type;
public:
    BaseItem(ItemType type);
    ItemType gettype();
    virtual bool canUse ( BaseKnight * knight ) = 0;
    virtual void use ( BaseKnight * knight ) = 0;
};
class Antidote: public BaseItem
{
private:
public:
Antidote():BaseItem(ANTIDOTE){}
bool canUse ( BaseKnight * knight );
void use ( BaseKnight * knight );
void getpoisoned(BaseKnight *knight);
};
class PhoenixI: public BaseItem
{
private:
public:
PhoenixI():BaseItem(PHOENIXI){}
bool canUse ( BaseKnight * knight );
void use ( BaseKnight * knight );
};
class PhoenixII: public BaseItem
{
private:
public:
PhoenixII():BaseItem(PHOENIXII){}
bool canUse ( BaseKnight * knight );
void use ( BaseKnight * knight );
};
class PhoenixIII: public BaseItem
{
private:
public:
PhoenixIII():BaseItem(PHOENIXIII){}
bool canUse ( BaseKnight * knight );
void use ( BaseKnight * knight );
};
class PhoenixIV: public BaseItem
{
private:
public:
PhoenixIV():BaseItem(PHOENIXIV){}
bool canUse ( BaseKnight * knight );
void use ( BaseKnight * knight );
};
// Events
class Events {
private:
int n;
int *eventi;
public:
    int count() const;
    int get(int i) const;
    Events(const string &file_events);
    ~Events();
};
class KnightAdventure {
private:
    ArmyKnights * armyKnights;
    Events * events;

public:
    KnightAdventure();
    ~KnightAdventure(); // TODO:

    void loadArmyKnights(const string &);
    void loadEvents(const string &);
    void run();
};
//
#endif // __KNIGHT2_H__