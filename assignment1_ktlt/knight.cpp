#include "knight.h"
// variables
string line2,line3;
string file_mush_ghost,file_asclepius_pack,file_merlin_pack;
int MaxHP;
float baseDame[6]={0,1,1.5,4.5,7.5,9.5};
int oldlevel;
int dem;
int small;
int fmascot;
int r1,c1;
int arr[1000];
int n2;
int arr2[1000][1000];
int n9;
int chop;
bool finish;
int buff;
bool isLancelot;
bool isArthur;
int b_merlin, b_acs;
// --------------------
int event_11(int level, int phoenixdown)
{
    int n1=((level+phoenixdown)%5+1)*3;
    if (n1==0) return n1;
    else 
    {
        int s1=(2*99+(n1-1)*(-2))*n1/2;
        return s1;
    }
}
int event_12(int HP)
{ 
    if ( HP ==1) {return HP;}
    else 
    {    int fibo[17]={0,1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987};
         for ( int i =16; i>=2; i--)
         {
             if (fibo[i]>=HP) {continue;}
             else {HP=fibo[i];break;}
         }
         return HP;
    }
}
void readFile(string file_input, int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown)
{
    ifstream in;
    in.open(file_input);
    in >>HP;
    in >>level;
    in >>remedy;
    in >>maidenkiss;
    in >>phoenixdown;
    getline(in,line2);
    getline(in,line2);
    getline(in,file_merlin_pack);
    int pos = file_merlin_pack.find(',');
    file_mush_ghost=file_merlin_pack.substr(0,pos);
    file_merlin_pack=file_merlin_pack.substr(pos+1);
    pos = file_merlin_pack.find(',');
    file_asclepius_pack=file_merlin_pack.substr(0,pos);
    file_merlin_pack=file_merlin_pack.substr(pos+1);
}
void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue) {
    cout << "HP=" << HP
        << ", level=" << level
        << ", remedy=" << remedy
        << ", maidenkiss=" << maidenkiss
        << ", phoenixdown=" << phoenixdown
        << ", rescue=" << rescue << endl;
}
void battle0(int &rescue)
{
  rescue=1; 
}
void battle1_5(int dem,int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue, int MaxHP, string battle)
{  
    int b=dem%10;
    int levelO=(dem > 6)?((b > 5)?b : 5) : b; 
    if (isArthur||isLancelot||level > levelO) {level++;if (level>10) {level=10;}}
    else if ( level < levelO)
    {
       int damage=baseDame[battle[0]-48]*levelO*10;
       HP=HP-damage;
       if (HP<=0)
       {
        if (phoenixdown!=0){phoenixdown--; HP=MaxHP;}
        else rescue=0;
       }
    }
    else {level=level;}
}
void battle6(int dem,int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue, int MaxHP)
{
    int b=dem%10;
    int levelO=dem > 6?(b > 5?b : 5) : b;
    if (isArthur||isLancelot|| level > levelO) {level+=2; if (level>10) level=10;}
    else if ( level < levelO)
    {   small=4;
        if (remedy!=0) { remedy--;HP=HP;small=0;}
        else if (HP<5) HP=1;
        else{
        HP=HP/5;}
    }
}
void battle7(int dem,int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue, int MaxHP)
{   oldlevel=level;
    int b=dem%10;
    int levelO=dem > 6?(b > 5?b : 5) : b;
    if (isArthur||isLancelot||level > levelO) {level+=2; if (level>10) level=10;}
    else if ( level < levelO)
    {   
        fmascot=4;
        if (maidenkiss!=0){maidenkiss--; fmascot=0;level=level;}
        else {
            level=1;
        }
    }
}
bool prime ( int &HP)
{   if(HP==2) return 1;
    else if(HP<2) return 0;
    else{
    for ( int i =2 ; i*i<=HP; i++)
    { 
        if(HP%i==0) {return 0;}
    }}
    return 1;
} 
void buff11(int &HP, int &level, int &phoenixdown, int &MaxHP)
{
 int s1=event_11(level,phoenixdown);
 HP=HP+(s1%100);
 bool check=prime(HP);
 if( check ) {HP++;check=prime(HP);}
 while ( !check)
 {
    HP++;
    check=prime(HP);
 }
 if ( HP > MaxHP) HP=MaxHP;
}
void nerf13(string file_mush_ghost, int a[], int &n)
{
if (file_mush_ghost!="")
{
    ifstream mushghost;
    mushghost.open(file_mush_ghost);
    mushghost>>n;
    char c;
   for ( int i =0; i < n; i++)
   {
    mushghost>>a[i]>>c;
   }
}
}
int findminindex(int a[], int n)
{   
    int min = a[0];
    int minindex=0;
    for ( int i =1; i < n; i++)
    {
        if (min >=a[i]) {minindex=i; min=a[i];}
    }
    return minindex;
}
int findminindex3(int a[], int n)
{   
    int min = a[0];
    int minindex=0;
    for ( int i =1; i < n; i++)
    {
        if (min >a[i]) {minindex=i; min=a[i];}
    }
    return minindex;
}
int findmaxindex(int a[], int n)
{   
    int max = a[0];
    int maxindex=0;
    for ( int i =1; i < n; i++)
    {
        if (max <=a[i]) {maxindex=i; max=a[i];}
    }
    return maxindex;
}
int findmaxindex3(int a[], int n) 
{   
    int max = a[0];
    int maxindex=0;
    for ( int i =1; i < n; i++)
    {
        if (max <a[i]) {maxindex=i; max=a[i];}
    }
    return maxindex;
}
bool moutainousarray(int a[], int n)
{   
    int count=0;
    int min = a[0];
	int i = 1;
	while (min < a[i])
	{
		count++;
		min = a[i];
		i++;
	}
	int max = a[count];
	while (max > a[i])
	{
		count++; max = a[i]; i++;
	}
    if (count==n) return 1;
    else return 0;
}
int find2ndvalin3num(int a[])
{
   if (a[0]>a[1]&&a[0]<a[2]) return a[0];
   else if (a[0]>a[2]&&a[0]<a[1]) return a[0];
   else if (a[1]>a[0]&&a[1]<a[2]) return a[1];
   else if (a[1]>a[2]&&a[1]<a[0]) return a[1];
   else if (a[2]>a[0]&&a[2]<a[1]) return a[2];
   else if (a[2]>a[1]&&a[2]<a[0]) return a[2];
   else return -5;
}
int find2indexndvalin3num(int a[])
{
   if (a[0]>a[1]&&a[0]<a[2]) return 0;
   else if (a[0]>a[2]&&a[0]<a[1]) return 0;
   else if (a[1]>a[0]&&a[1]<a[2]) return 1;
   else if (a[1]>a[2]&&a[1]<a[0]) return 1;
   else if (a[2]>a[0]&&a[2]<a[1]) return 2;
   else if (a[2]>a[1]&&a[2]<a[0]) return 2;
   else return -7;
}
void buff15_17(int &spell)
{
    spell++;
    if ( spell >99) spell =99;
}
void buff19(string file_asclepius_pack, int a[][1000], int &r1, int &c1, int &remedy,int &maidenkiss, int &phoenixdown, int &HP, int &level)
    { 
    if(file_asclepius_pack!="")
    {
    ifstream asclepiuis;
    asclepiuis.open(file_asclepius_pack);
    asclepiuis >>r1 >>c1;
    for (int i=0; i < r1; i++)
    {
        for ( int j =0; j< c1; j++)
        {
            asclepiuis>>a[i][j];
        }
    }
    int c_spell=0;
            for ( int i =0; i < r1; i ++)
            {
                for ( int j =0; j < c1; j++)
                {
                  if (a[i][j]==16) {remedy++;c_spell++; if (small!=0) {remedy--; HP*=5;small=0;}if (remedy>99){remedy=99;}}
                  else if (a[i][j]==17) {maidenkiss++;c_spell++;if (fmascot!=0){maidenkiss--;level=oldlevel;fmascot=0;}if (maidenkiss>99){maidenkiss=99;} }
                  else if (a[i][j]==18) {phoenixdown++;c_spell++;if (phoenixdown>99){phoenixdown=99;}}
                  if(c_spell==3||j==c1-1) {c_spell=0; break;}
                }
            }
    }
    }

bool checkArthur( int &HP)
{
    if (HP==999) return 1;
    else return 0;
}
bool checkLancelot(int &HP)
{
   return prime(HP);
}
void battle99(int dem,int & HP, int & level, int&rescue, int MaxHP)
{
 if (checkArthur(MaxHP)) {level=10;}
 else if (checkLancelot(MaxHP)&& level>=8) { level =10;}
 else if (level==10) {rescue =1;}
 else {
     rescue=0;
     finish=0;
 }
}
bool findchar(string s, char c )
{
int pos1=s.find(c);
if (pos1!=string :: npos) return 1;
else return 0;
}
void lower(string &s)
{
    for ( int i =0; i < s.length(); i++)
    {
        s[i]=tolower(s[i]);
    }
}
void buff18(string filename, int &HP, int n, int MaxHP)
{
if (filename!="")
{
    ifstream merlin;
    merlin.open(filename);
    merlin >> n;
    string text;
    while( getline(merlin, text))
    {   
        int pos3=text.find("merlin");
        int pos3_1=text.find("Merlin");
        if(pos3!=string::npos||pos3_1!=string::npos) {HP+=3; if (HP>MaxHP) HP=MaxHP;}
        else 
        {
            lower(text);
            char c[6]={'m','e','r','l','i','n'};
            bool checkchar=1;
            for ( int i =0; i < 6; i++)
            {  
                checkchar=findchar(text,c[i]);
                if (!checkchar) break;
            }
            if (checkchar) {HP+=2; if (HP>MaxHP) HP=MaxHP;}
        }
    }
}
}
void adventureToKoopa(string file_input, int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue) 
{
    readFile(file_input,  HP,  level,  remedy,  maidenkiss,  phoenixdown);
    MaxHP=HP;
    rescue=-1;
    isArthur=checkArthur(MaxHP);
    isLancelot=checkLancelot(MaxHP);
     dem=0;
     small=0; fmascot=0; finish=1;buff=0; b_merlin=0; b_acs=0;
   stringstream battlestr(line2);
     string battle;
    battlestr >> battle;
    while(rescue==-1)
    {   
        ++dem;
        if ( battle=="0")
        {
            battle0(rescue);
            display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
            break;
        }
        else if (battle =="1"||battle =="2"||battle =="3"||battle =="4"||battle =="5")
        {
            battle1_5(dem,HP,level,remedy,maidenkiss,phoenixdown,rescue,MaxHP,battle);
        }
        else if ( battle=="6"&& small==0&& fmascot==0)
        {
            battle6(dem,HP,level,remedy,maidenkiss,phoenixdown,rescue,MaxHP);
        }
        else if ( battle=="7"&& small==0&&fmascot==0)
        {
            battle7(dem,HP,level,remedy,maidenkiss,phoenixdown,rescue,MaxHP);
        }
        else if ( battle=="11")
        {
            buff11(HP,level,phoenixdown,MaxHP);
        }
        else if (battle=="12")
        {
            HP=event_12(HP);
        }
        else if(battle.substr(0,2)=="13")
        {   
            battle=battle.substr(2);
            nerf13(file_mush_ghost, arr, n2);
            for ( int i =0; i < battle.length();i++)
            {
                if (battle[i] == '1')
                {
                int mini=findminindex(arr,n2);
                int maxi=findmaxindex(arr,n2);
                // cout << mini << maxi;
                HP=HP-(maxi+mini);
                if (HP>MaxHP) HP=MaxHP;
                else if ( HP<=0 && phoenixdown!=0) 
                {
                    phoenixdown--;
                    HP=MaxHP;
                }
                else if (HP<=0) {rescue=0;finish=0; break;}
                }
                else if ( battle[i]=='2')
                {   
                    bool c=moutainousarray(arr,n2);
                    if(c)
                    {int mti=findmaxindex(arr,n2);
                     int mtx=arr[mti];
                     HP=HP-(mtx+mti);
                    }
                    else HP=HP+5;
                     if (HP>MaxHP) HP=MaxHP;
                else if ( HP<=0 && phoenixdown!=0) 
                {
                    phoenixdown--;
                    HP=MaxHP;
                }
                else if (HP<=0) {rescue=0;finish=0; break;}
                }
                else if ( battle[i]=='3')
                {
                    ifstream mushghost3;
                    mushghost3.open(file_mush_ghost);
                    int x;
                    mushghost3 >> x;
                    char c1;
                    int a3[100];
                    for ( int i =0; i < x; i ++)
                    {
                      mushghost3 >> a3[i]>> c1;
                      if (a3[i]<0)
                      {
                        a3[i]*=-1;
                      }
                      a3[i]=(a3[i]*17+9)%257;
                    }
                    int mini2=findminindex3(a3,x);
                  int maxi2=findmaxindex3(a3,x);
                //   cout << mini2 << maxi2;
                  HP=HP-(maxi2+mini2);
                if (HP>MaxHP) HP=MaxHP;
                else if ( HP<=0 && phoenixdown!=0) 
                {
                    phoenixdown--;
                    HP=MaxHP;
                }
                 else if (HP<=0) {rescue=0;finish=0; break;}
                }
                else if (battle[i]=='4')
                {    ifstream mushghost3;
                    mushghost3.open(file_mush_ghost);
                    int x;
                    mushghost3 >> x;
                    // if (x<3) continue;
                    char c1;
                    int a3[100];
                    for ( int i =0; i < x; i ++)
                    {
                      mushghost3 >> a3[i]>> c1;
                      if (a3[i]<0)
                      {
                        a3[i]*=-1;
                      }
                      a3[i]=(a3[i]*17+9)%257;
                    }
                    int max2_3x=find2ndvalin3num(a3);
                    int max2_3i=find2indexndvalin3num(a3);
                    HP=HP-(max2_3x+max2_3i);
                     if (HP>MaxHP) HP=MaxHP;
                else if ( HP<=0 && phoenixdown!=0) 
                {
                    phoenixdown--;
                    HP=MaxHP;
                }
                 else if (HP<=0) {rescue=0;finish=0; break;}
                }
            }
        }
        else if ( battle =="15")
        {
            buff15_17(remedy);
            if ( remedy >99) remedy=99;
            if (small!=0)
            {
                HP*=5; remedy--;
                if ( HP > MaxHP) HP=MaxHP;
                small=0;
            }
        }
        else if ( battle =="16")
         {
            buff15_17(maidenkiss);
            if ( maidenkiss >99) maidenkiss=99;
            if (fmascot!=0) {
                maidenkiss--; level=oldlevel;
            }
        }
        else if ( battle =="17")
        {
            buff15_17(phoenixdown);
            if ( phoenixdown >99) phoenixdown=99;
        }
        else if ( battle=="19"&&b_acs==0)
        {   
            b_acs++;
           buff19(file_asclepius_pack,arr2,r1,c1,remedy,maidenkiss,phoenixdown, HP, level);
        }
        else if (battle=="99")
        {
            battle99(dem,HP,level,rescue,MaxHP);
        }
        else if ( battle=="18"&&b_merlin==0)
        {
            b_merlin++;
            buff18(file_merlin_pack,HP,n9,MaxHP);
        }
           if (small>0) 
        {small--;
        if(small==0) {if(HP>0){HP*=5;} if(HP>MaxHP)HP=MaxHP;}}
        if (fmascot>0) 
        {fmascot--; if(fmascot==0) {level=oldlevel;}}
        if ( rescue==0 || HP ==0) {rescue=0; display(HP,level, remedy, maidenkiss,phoenixdown,rescue); break;}
        else if (rescue ==-1) {
            if ( !(battlestr>>battle)) {rescue =1;display(HP,level, remedy, maidenkiss,phoenixdown,rescue); break;}
            else display(HP,level, remedy, maidenkiss,phoenixdown,rescue);
        }
        else if (rescue ==1){display(HP,level, remedy, maidenkiss,phoenixdown,rescue); finish=0;}
        if(!finish) break;
    }
}