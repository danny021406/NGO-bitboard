#ifndef UCBNODE_H
#define UCBNODE_H
#include "board.h"
#include <math.h>
#define basenum 0
#define ravenum 20

#define minusnum (basenum - 2)//�����@
#define minusrnum (ravenum - 2)
const double UCB_WEIGHT = 0.25;
class ucbnode
{

public:
	char place;//���B�U��
	bool color;//�֤U��
	char child[BOARDSSIZE+1];//��p��
	int csize;
	ucbnode* childptr;
	double count;//basenum + real
	double mean; //1:color Ĺ 0:color ��
	double ravecount;//ravenum +real
	double ravemean;// 1 color Ĺ  -1 color ��
	double logc;

    void initucbnode(int i,bool j);
    void addresult(double result);
    int getbestmove();
	vector<float> getPolicy();
    void show_child();
    float show_inf(int child);
    void expansion(board &b);
	string inttostring(int i);
    string inttoGTPstring(int i);
	ucbnode();
	~ucbnode();
	void setlogc();
};
#endif //UCBNODE_H