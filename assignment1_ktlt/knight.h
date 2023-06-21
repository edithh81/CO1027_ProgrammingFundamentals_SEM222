#ifndef __KNIGHT_H__
#define __KNIGHT_H__

#include "main.h"

void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue);
void adventureToKoopa(string file_input, int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue);
int event_11(int level, int phoenixdown);
int event_12(int HP);
void readFile(string file_input, int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown);
void battle0(int &rescue);
void battle1_5(int dem,int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue, int MaxHP);
void battle6(int dem,int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue, int MaxHP);
bool snt(int &HP);
void buff11(int & HP, int & level, int & phoenixdown);
int findminindex(int a[], int n);
int findmaxindex(int a[], int n);
int findminindex3(int a[], int n);
int findmaxindex3(int a[], int n);
bool moutainousarray(int a[], int n2);
void buff15_17(int &spell);
void mushghost3(int a[], int n);
int find2ndvalin3num(int a[]);
int find2indexndvalin3num(int a[]);
void buff19(string file_asclepius_pack, int a[][1000], int &x, int &y);
bool checkArthur(int &HP);
bool checkLancelot(int &HP);
void battle99(int dem,int & HP, int & level,int&rescue);
void buff18(string filename, int &HP, int n, int MaxHP);
bool findchar(string s, char c );
void lower(string &s);
#endif // __KNIGHT_H__