#ifndef BOARDH
#define BOARDH
#include"bitboard.h"
#include<iostream>
#include<map>
#include<string.h>
#include<vector>
#include<stdio.h>
#include<string>
#include<stdlib.h>
//#include<Windows.h>

#include"boardcn.h"
#include<math.h>
#define BLACK 0
#define WHITE 1
#define SEARCH 0
#define search 0
using namespace std;

class board
{
public:
    /*
    0  1  2  3  4
    5  6  7  8  9
    10 11 12 13 14
    15 16 17 18 19
    20 21 22 23 24
    */
    bitboard ban[2];
    bitboard notsafe[2];
    const static boardcn nb;// neighbor

    bitboard bitb[2];	
    char parent[BOARDCUL*BOARDCUL];
    bitboard air[BOARDCUL*BOARDCUL];
    char countair[BOARDSSIZE];


    int findParent(int i);
    void unite(int x,int y);
    void getallair();
    bool check_is_end();
    void add(int i,bool j);
    bool check(int i,bool j);
	void showboard();
    void showParent();
    void showAir();
    board();
    board(bitboard bb,bitboard ww);
    void Initboard(bitboard bb = bitboard(),bitboard ww = bitboard());
    inline bool get(int i,bool j);
    bool just_play_color();
    void getv(int bone[BOARDSSIZE],int wone[BOARDSSIZE],int two[BOARDSSIZE] ,int &bsize,int &wsize ,int &tsize);
    void getvec(vector<char> &bone,vector<char> &wone ,vector<char> &two );
    void setdata();
    void clear();
    string inttostring(int i);
    double simulate(bool j,int bone[BOARDSSIZE],int wone[BOARDSSIZE],int two[BOARDSSIZE] ,int bsize,int wsize ,int tsize );
    bool isempty();
};


#endif

