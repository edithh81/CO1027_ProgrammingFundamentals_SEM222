#include "knight2.h"
// Variable

/* * * BEGIN implementation of class BaseItem * * */
ItemType BaseItem:: gettype()
{
    return this->type;
}
BaseItem::BaseItem(ItemType type)
{
    this->type=type;
}
bool Antidote::canUse(BaseKnight *knight)
{
    BaseBag *bag=knight->getbag();
    if (bag->get(ANTIDOTE)!=nullptr) return 1;
    return 0;
}
void Antidote::use(BaseKnight *knight)
{
    knight->getbag()->deleteFirst();
}

void Antidote::getpoisoned(BaseKnight *knight)
{
    BaseBag *curbag=knight->getbag();
    for (int i =0; i < 3;i++)
    {   
       if (curbag->getrecsize()<3){
          for ( int j=0; j <curbag->getrecsize();j++) {curbag->deleteFirst();}
        return;}
       curbag->deleteFirst();
    }
    knight->sethp(knight->gethp()-10);
}
bool PhoenixI :: canUse(BaseKnight *knight)
{
return knight->gethp()<=0;
}
void PhoenixI::use(BaseKnight*knight)
{
knight->sethp(knight->getmaxHP());
knight->getbag()->deleteFirst();
}
bool PhoenixII:: canUse(BaseKnight*knight)
{
    return knight->gethp()<(knight->getmaxHP()/4);
}
void PhoenixII::use(BaseKnight *knight)
{
    knight->sethp(knight->getmaxHP());
    knight->getbag()->deleteFirst();
}
bool PhoenixIII::canUse(BaseKnight*knight)
{
    return knight->gethp()<(knight->getmaxHP()/3);
}
void PhoenixIII::use(BaseKnight *knight)
{
    knight->sethp(knight->gethp()<=0?knight->getmaxHP()/3:(knight->gethp()+knight->getmaxHP()/4));
    knight->getbag()->deleteFirst();
}

bool PhoenixIV::canUse(BaseKnight*knight)
{
    return knight->gethp()<(knight->getmaxHP()/2);
}
void PhoenixIV::use(BaseKnight*knight)
{
    knight->sethp(knight->gethp()<=0?knight->getmaxHP()/2:(knight->gethp()+knight->getmaxHP()/5));
    knight->getbag()->deleteFirst();
}
/* * * END implementation of class BaseItem * * */







/* * * BEGIN implementation of class BaseOpp * * */
BaseOpponent *BaseOpponent:: createOPP(int i, int eventid)
{
    switch(eventid)
    {
      case 1: return new MadBear(i, eventid); break;
      case 2: return new Bandit(i, eventid); break;
      case 3: return new LordLupin(i, eventid); break;
      case 4: return new Elf(i,eventid); break;
      case 5: return new Troll(i, eventid); break;
      case 6: return new Tornbery(i, eventid); break;
      case 7: return new QueenOfCards(i,eventid); break;
      case 8: return new NinadeRings(i, eventid); break;
      case 9: return new DurianGarden(i, eventid); break;
      case 10: return new OmegaWeapon(i, eventid); break;
      case 11: return new Hades(i, eventid); 
    }
    return nullptr;
}
BaseOpponent::BaseOpponent(int i=0, int eventid=0)
{   
    this->eventid=eventid;
    this->index=i;
    this->levelO=(i+eventid)%10+1;
}
void BaseOpponent::setlevelO(){
    this->levelO=levelO;
}
int BaseOpponent::getlevelO(){
    return this->levelO;
}
void BaseOpponent:: attack(ArmyKnights *army, int eventid){
    BaseKnight *knight= army->lastKnight();
    if(knight->isLancelot(knight->getmaxHP())||knight->isPaladin(knight->getmaxHP())||knight->getlevel()>=this->levelO)
    {   
        army->transgil(army, gilcollect[eventid]); return;
    }
      knight->sethp(knight->gethp()-baseDame[eventid]*(this->levelO-knight->getlevel()));
      if (!knight->checkPhoenix())
         army->setArmy();   
}
void MadBear::seteventid(){
    this->eventid=1;
}
int MadBear::geteventid(){
    return this->eventid;
}
void Bandit::seteventid(){
    this->eventid=2;
}
int Bandit::geteventid(){
    return this->eventid;
}
void LordLupin::seteventid(){
    this->eventid=3;
}
int LordLupin::geteventid(){
    return this->eventid;
}
void Elf::seteventid(){
    this->eventid=4;
}
int Elf::geteventid(){
    return this->eventid;
}
void Troll:: seteventid()
{
    this->eventid=5;
}
int Troll::geteventid()
{
    return this->eventid;
}
void Tornbery::seteventid(){
    this->eventid=6;
}
int Tornbery::geteventid(){
    return this->eventid;
}
void QueenOfCards::seteventid(){
    this->eventid=7;
}
int QueenOfCards::geteventid(){
    return this->eventid;
}
void NinadeRings::seteventid(){
    this->eventid=8;
}
int NinadeRings::geteventid(){
    return this->eventid;
}
void DurianGarden::seteventid(){
    this->eventid=9;
}
int DurianGarden::geteventid(){
    return this->eventid;
}
void OmegaWeapon::seteventid(){
    this->eventid=10;
}
int OmegaWeapon::geteventid(){
    return this->eventid;
}
void Hades::seteventid(){
    this->eventid=11;
}
int Hades::geteventid(){
    return this->eventid;
}
void Tornbery:: attack(ArmyKnights *army, int eventid)
{  
   BaseKnight *knight=army->lastKnight();
   if(knight->getlevel()>=this->levelO)
   {
    knight->setlevel(knight->getlevel()+1);
    if(knight->getlevel()>10) knight->setlevel(10); 
    return;
   }
   if (knight->isDragon(knight->getmaxHP())) return;
      BaseItem *item=knight->getbag()->get(ANTIDOTE);
      if (item != nullptr && item->canUse(knight)) 
      { 
        item->use(knight);
        return;
      }
    BaseBag *curbag=knight->getbag();
    for (int i =0; i < 3;i++)
    {   
       if(curbag->getHead(curbag)==nullptr) break;
       curbag->deleteFirst();
    }
    knight->sethp(knight->gethp()-10);
    if(!knight->checkPhoenix())
        army->setArmy();
}
void QueenOfCards::attack(ArmyKnights *army, int eventid)
{
    BaseKnight *knight=army->lastKnight();
    if(knight->getlevel()>=this->levelO) 
    {
        army->transgil(army, knight->getgil()); 
        return;
    }
    if(knight->isPaladin(knight->getmaxHP())) return;
    knight->setgil(knight->getgil()/2);
}
void NinadeRings::attack(ArmyKnights *army, int eventid)
{
    BaseKnight*knight=army->lastKnight();
    if(knight->gethp()>=(knight->getmaxHP()/3))  return;

    

    if(knight->isPaladin(knight->getmaxHP()))
    {
        knight->sethp(knight->gethp()+knight->getmaxHP()/5);
        return;
    }

    if (knight->getgil()<50) return;

    knight->setgil(knight->getgil()-50);
    knight->sethp(knight->gethp()+knight->getmaxHP()/5);
}
void DurianGarden ::attack(ArmyKnights *army, int eventid)
{
BaseKnight*knight=army->lastKnight();
knight->sethp(knight->getmaxHP());
}
void OmegaWeapon :: attack(ArmyKnights*army, int eventid)
{   
    BaseKnight *knight=army->lastKnight();
    if ((knight->gethp()==knight->getmaxHP()&&knight->getlevel()==10)||(knight->isDragon(knight->getmaxHP())))
    {
        knight->setlevel(10);
        knight->setgil(999);
        army->setmeetOmega();
    }
    else{
        knight->sethp(0);
        if(!knight->checkPhoenix())
            army->setArmy();
    }
}
void Hades::attack(ArmyKnights *army, int eventid)
{
    BaseKnight *knight = army->lastKnight();
    if ((knight->getlevel()==10) || (knight->isPaladin(knight->getmaxHP())&&knight->getlevel()>=8))
    {  
       army->setPaladinShield();
       army->setmeetHades();
    }
    else {
        knight->sethp(0);
        if(!knight->checkPhoenix())
            army->setArmy();
    }
}
/* * * END implementation of class BaseOpp* * */











/* * * BEGIN implementation of class BaseBag * * */
void BaseBag:: setrecsize (int size)
{
    this->recsize=size;
}
void BaseBag:: setmaxsize(int max)
{
    this->maxsize=max;
}
int BaseBag::getrecsize()
{
    return this->recsize;
}
BaseItem *BaseBag::getPhoenix()
{
    Node *findphoneix=this->head;
    while (findphoneix!=nullptr)
    {
        if(findphoneix->item->gettype()!=ANTIDOTE)
        {
            if(findphoneix->item->canUse(this->knight))
            {   
                this->swapItem(findphoneix);
                return this->head->item;
            }
        }
        findphoneix=findphoneix->next;
    }
    return nullptr;
}

BaseBag::BaseBag(BaseKnight* knight, int a, int b)
{
    this->head=nullptr;
    this->knight=knight;
    this->recsize=0;
    if(knight->isDragon(knight->getmaxHP())) this->maxsize=14;
    else if (knight->isLancelot(knight->getmaxHP())) this->maxsize=16;
    else if (knight->isPaladin(knight->getmaxHP())) this->maxsize=99;
    else this->maxsize=19;
    for ( int i =0; i < a; i ++)
    {
        this->insertFirst(new PhoenixI());
    }
    if (!knight->isDragon(knight->getmaxHP()))
    {
    for ( int i =0; i < b; i ++)
    {
        this->insertFirst(new Antidote());
    }
    }
}
BaseBag::~BaseBag()
{   
    while(this->head!=nullptr) this->deleteFirst();
    delete this->head;
}
BaseBag::Node *BaseBag ::getHead(BaseBag *bag)
{
    return bag->head;
}
BaseBag::Node *BaseBag::newnode(BaseItem *item)
{
    Node* node = new Node;
    node->item=item;
    node->next=nullptr;
    return node;
}
bool BaseBag::insertFirst(BaseItem *item)
{   
    if(this->recsize==this->maxsize) {return false;}
    this->setrecsize(this->getrecsize()+1);
    Node* node = this->newnode(item);
    if (this->head==nullptr)
    {  
        this->head=node;
    }
    else 
    {
        node->next=this->head;
        this->head=node;
    }
    return true;
}
BaseItem* BaseBag::get(ItemType itemType)
{
Node *node=this->head;
while(node!=nullptr)
{
    if(node->item->gettype()==itemType)
    {   
        this->swapItem(node);
        return this->head->item;
    }
    node=node->next;
}
return nullptr;
}
void BaseBag::deleteFirst()
{   
    if(this->head ==nullptr) return;
    this->setrecsize(this->getrecsize()-1);
    Node *p=this->head;
    this->head=p->next;
    delete p;
}
void BaseBag::swapItem(Node *node)
{
BaseItem *p=node->item;
node->item=this->head->item;
this->head->item=p;
}
string BaseBag::toString () const
{
string itemt[5]={"Antidote","PhoenixI","PhoenixII","PhoenixIII","PhoenixIV"};

string s="Bag[count="+to_string(this->recsize)+";";
if (this->recsize==0) return s+"]";
Node *p=this->head;
while(p!=nullptr)
{
    s += itemt[(p->item->gettype())]+",";
    p=p->next;
}
s=s.substr(0,s.length()-1);
return s+"]";
}
/* * * END implementation of class BaseBag * * */











/* * * BEGIN implementation of class Events * * */
Events:: Events(const string &file_events)
{
   ifstream in;
   in.open(file_events);
   in >>n;
   this->eventi=new int[n];
   for ( int i =0; i < n; i++)
   {
    in >>eventi[i];
   }
   in.close();
}
Events::~Events()
{
    delete []eventi;
}
int Events::count () const 
{
    return this->n;
} 
int Events:: get (int i) const{
    return this->eventi[i];
} 
/* * * END implementation of class Events * * */









/* * * BEGIN implementation of class BaseKnight * * */
KnightType BaseKnight:: getType(){
    return this->knightType;
}
void DragonKnight::setsizeofbag()
{
    this->bag->setmaxsize(14);
}
void LancelotKnight::setsizeofbag()
{
    this->bag->setmaxsize(16);
}
void NormalKnight::setsizeofbag()
{
    this->bag->setmaxsize(19);
}
void PaladinKnight::setsizeofbag()
{
    this->bag->setmaxsize(999);
}
bool BaseKnight::checkAntidote()
{
    BaseItem *antidote=this->bag->get(ANTIDOTE);
    if(antidote!=nullptr)
    {
        antidote->use(this);
        return 1;
    }
    return 0;
}
BaseBag *BaseKnight::getbag()
{
    return this->bag;
}
int BaseKnight::getmaxHP()
{
    return this->maxhp;
}
void BaseKnight::setgil(int gil){
    this->gil=gil;
}
int BaseKnight::getgil()
{
    return this->gil;
}
void BaseKnight::sethp(int hp){
    this->hp=hp;
}
int BaseKnight::gethp()
{
    return this->hp;
}
void BaseKnight::setlevel(int level){
    this->level=level;
}
int BaseKnight::getlevel()
{
    return this->level;
}
bool BaseKnight::checkPhoenix(){
    BaseItem *item=this->bag->getPhoenix();
    if (item!=nullptr)
    {
        item->use(this);
        return 1;
    }
    if (this->gethp()>0) return 1;
    if(this->getgil()<100) return 0;
    this->setgil(this->getgil()-100);
    hp=0.5*maxhp; return 1;
}
BaseKnight* BaseKnight::create(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI)
{
 if (isPaladin(maxhp)) return new PaladinKnight(id,maxhp,level,gil,antidote,phoenixdownI);
 if (isLancelot(maxhp)) return new LancelotKnight(id, maxhp,level, gil, antidote, phoenixdownI);
 if (isDragon(maxhp)) return new DragonKnight(id, maxhp, level,gil, antidote,phoenixdownI);
 return new NormalKnight(id,maxhp, level, gil, antidote, phoenixdownI);
}
BaseKnight::BaseKnight(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI, KnightType type)
{
    this->id=id; this->maxhp=maxhp; this->level=level; this->gil=gil; this->antidote=antidote;this->knightType=type;
    this->hp=maxhp;
    this->bag=new BaseBag(this, phoenixdownI, antidote);
}
BaseKnight ::~BaseKnight()
{
    delete this->bag;
}
bool BaseKnight::isPaladin (int maxhp)
{
     if (maxhp<2) return 0;
        else {
            for ( int i =2; i*i<=maxhp;i++) 
            {
                if (maxhp%i==0) return 0;
            }
            return 1;
        }
}
bool BaseKnight:: isLancelot(int maxhp)
{
      return maxhp==888;
}
bool BaseKnight::isDragon(int maxhp)
{     if(maxhp>100)
     {
      int a=maxhp/100;
      int b=(maxhp%100)/10;
      int c=maxhp%10;
      int m=a*a, n=b*b, p=c*c;
      if((a!=b&&b!=c&&a!=c)&&((m==n+p)||(n==m+p)||(p==m+n))) {return 1;}
     }
      return 0;
}
string BaseKnight::toString() const {
    string typeString[4] = {"PALADIN", "LANCELOT", "DRAGON", "NORMAL"};
    // inefficient version, students can change these code
    //      but the format output must be the same
    string s("");
    s += "[Knight:id:" + to_string(id) 
        + ",hp:" + to_string(hp) 
        + ",maxhp:" + to_string(maxhp)
        + ",level:" + to_string(level)
        + ",gil:" + to_string(gil)
        + "," + bag->toString()
        + ",knight_type:" + typeString[knightType]
        + "]";
    return s;
}

/* * * END implementation of class BaseKnight * * */







/* * * BEGIN implementation of class ArmyKnights * * */
void ArmyKnights::setArmywUlti(int i){
    for (int j=i+1; j<this->curnumofK;j++)
        this->knighti[j-1]=this->knighti[j];
    this->knighti[curnumofK-1]=nullptr;
    --this->curnumofK;
}
void ArmyKnights::setmeetOmega()
{
    this->meetOmega=true;
}
void ArmyKnights::setmeetHades()
{
    this->meetHades=true;
}
void ArmyKnights::transgil(ArmyKnights *army, int gilcollect)
{   
    int extragil=0;
    for ( int i=this->curnumofK-1; i>=0;i--)
    {   
        if(extragil==0)
        {
        knighti[i]->setgil(knighti[i]->getgil()+gilcollect);
        if(knighti[i]->getgil()>999)
        {   
            extragil=knighti[i]->getgil()-999;
            knighti[i]->setgil(999);
        }
        else break;
        }
        else{
        knighti[i]->setgil(knighti[i]->getgil()+extragil);
        if(knighti[i]->getgil()>999)
        {   
            extragil=knighti[i]->getgil()-999;
            knighti[i]->setgil(999);
        }
        else break;
        }
    }
}
void ArmyKnights ::setArmy()
{     
    --this->curnumofK;
}
ArmyKnights::ArmyKnights(const string &file_armyknights)
{
    ifstream in;
    in.open(file_armyknights);
    in >>numofK;
    this->curnumofK=numofK;
    this->knighti=new BaseKnight*[curnumofK];
    int id=1;
    for ( int i =0; i < numofK; i++)
    {   
        int HP,level,phoenixdown1,gil, antidote;
        in>>HP>>level>>phoenixdown1>>gil>>antidote;
        knighti[i]=BaseKnight::create(id,HP,level,gil,antidote,phoenixdown1);
        id++;
    }
    this->meetHades=this->meetOmega=this->guienehair=this->lancespear=this->palashield=this->excalibursw=false;
}
int ArmyKnights::count() const
{   
    return this->curnumofK;
}
BaseKnight* ArmyKnights::lastKnight() const
{
return this->knighti[this->curnumofK-1];
}

void ArmyKnights:: setGuinevereHair()
{
    this->guienehair=true;
}
void ArmyKnights:: setLancelotSpear()
{
    this->lancespear=true;
}
void ArmyKnights::setPaladinShield()
{
    this->palashield=true;
}
void ArmyKnights::setExcaliburSword()
{   if(this->lancespear&&this->palashield&&this->guienehair)
{
    this->excalibursw=true;
}
}
bool ArmyKnights::hasLancelotSpear()const{
    return this->lancespear;
}
bool ArmyKnights::hasGuinevereHair()const{
    return this->guienehair;
}
bool ArmyKnights::hasExcaliburSword()const{
    return this->excalibursw;
}
bool ArmyKnights::hasPaladinShield() const
{
    return this->palashield;
}
void ArmyKnights::printInfo() const {
    cout << "No. knights: " << this->count();
    if (this->count() > 0) {
        BaseKnight * lknight = lastKnight(); // last knight
        cout << ";" << lknight->toString();
    }
    cout << ";PaladinShield:" << this->hasPaladinShield()
        << ";LancelotSpear:" << this->hasLancelotSpear()
        << ";GuinevereHair:" << this->hasGuinevereHair()
        << ";ExcaliburSword:" << this->hasExcaliburSword()
        << endl
        << string(50, '-') << endl;
}
bool ArmyKnights :: fight(BaseOpponent *opponent)
{   
    opponent->seteventid();
    opponent->attack(this,opponent->geteventid());
    if (this->curnumofK==0) return false;
    return true;
}
void ArmyKnights::printResult(bool win) const {
    cout << (win ? "WIN" : "LOSE") << endl;
}
void ArmyKnights:: resetArmy()
{
    this->curnumofK=numofK;
}
BaseKnight *ArmyKnights::getKnight(int index)
{
    return this->knighti[index];
}
bool ArmyKnights::checklastK()
{
    return this->curnumofK==0;
}
ArmyKnights ::~ArmyKnights()
{
  for ( int i =0; i <numofK; i++)
  {
    delete knighti[i];
  }
  delete []knighti;
}
void ArmyKnights:: pickPhoenixdownII()
{   
    BaseItem *phoenixII=new PhoenixII();
    for (int i =curnumofK-1; i>=0; i--)
    {
        BaseKnight *knight=this->getKnight(i);
        BaseBag *bag= knight->getbag();
        if(bag->insertFirst(phoenixII)) break;
    }
}
void ArmyKnights:: pickPhoenixdownIII()
{   
    BaseItem *phoenixIII=new PhoenixIII();
    for (int i =curnumofK-1; i>=0; i--)
    {
        BaseKnight *knight=this->getKnight(i);
        BaseBag *bag= knight->getbag();
        if(bag->insertFirst(phoenixIII)) break;
    }
}
void ArmyKnights:: pickPhoenixdownIV()
{   
    BaseItem *phoenixIV=new PhoenixIV();
    for (int i =curnumofK-1; i>=0; i--)
    {
        BaseKnight *knight=this->getKnight(i);
        BaseBag *bag= knight->getbag();
        if(bag->insertFirst(phoenixIV)) break;
    }
}
bool ArmyKnights:: fightUltimecia()
{
    if(this->hasExcaliburSword()) return 1;
    if (this->hasGuinevereHair()&&this->hasLancelotSpear()&&this->hasPaladinShield())
    {
        int HPofUlti=5000;
        for (int i=curnumofK-1;i>=0;i--)
        {
            int level=knighti[i]->getlevel();
            int HP=knighti[i]->gethp();
            int maxHP=knighti[i]->getmaxHP();
            if (knighti[i]->isLancelot(maxHP))
            {
                HPofUlti-=HP*level*0.05;
            }
            else if (knighti[i]->isPaladin(maxHP))
            {
                HPofUlti-=HP*level*0.06;
            }
            else if (knighti[i]->isDragon(maxHP))
            {
                HPofUlti-=HP*level*0.075;
            }
            if (HPofUlti>0&&knighti[i]->getType()!=NORMAL)  this->setArmywUlti(i);
            if (HPofUlti<=0) return true;
        }
    }
    this->curnumofK=0;
    return 0;
}
bool ArmyKnights::adventure(Events *events)
{
   bool beatUltimecia=false;
   int i=0; 
   int numofEvents=events->count();
   while(i<numofEvents)
   {
    int eventid=events->get(i);
    switch(eventid)
    {
        case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: 
        {
            BaseOpponent *opp= BaseOpponent::createOPP(i,eventid);
            if (this->fight(opp))
            {
                 break;
            }
            if(this->checklastK()) break;
        }
        case 10: 
        {   
            if(this->meetOmega) break;
            BaseOpponent *opp= BaseOpponent::createOPP(i,eventid); 
            if(this->fight(opp)) break;
            else break;
        }
        case 11:
        {   
            if (this->meetHades) break;
            BaseOpponent *opp= BaseOpponent::createOPP(i,eventid);
            if(this->fight(opp))  break;
            else break;
        }
        case 112: this->pickPhoenixdownII(); break;
        case 113: this->pickPhoenixdownIII(); break;
        case 114: this->pickPhoenixdownIV(); break;
        case 95: this->setPaladinShield(); break;
        case 96: this->setLancelotSpear(); break;
        case 97: this->setGuinevereHair(); break;
        case 98: this->setExcaliburSword(); break;
        case 99: beatUltimecia=this->fightUltimecia();    
    }
    this->printInfo();
    if (this->checklastK()) return beatUltimecia;
    i++;
   }
   return beatUltimecia;
}
/* * * END implementation of class ArmyKnights * * */

/* * * BEGIN implementation of class KnightAdventure * * */
KnightAdventure::KnightAdventure() {
    armyKnights = nullptr;
    events = nullptr;
}
KnightAdventure::~KnightAdventure(){
    delete this->events;
    delete this->armyKnights;

}
void KnightAdventure::loadArmyKnights(const string &file_armyknights){
this->armyKnights=new ArmyKnights(file_armyknights);
}
void KnightAdventure::loadEvents(const string &file_events)
{
this->events=new Events(file_events);
}
void KnightAdventure::run(){
  this->armyKnights->printResult(this->armyKnights->adventure(this->events));
}
/* * * END implementation of class KnightAdventure * * */