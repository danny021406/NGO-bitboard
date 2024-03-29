#ifndef MCTS_H
#define MCTS_H
#include "ucbnode.h"
class MCTStree
{
public:
	int selectlist[BOARDSSIZE];
	int slsize;
	ucbnode* root;
	board rboard;
    MCTStree();
    ~MCTStree();
    vector<ucbnode*> path;
	int bsize,wsize,tsize;
	int bone[BOARDSSIZE],wone[BOARDSSIZE],two[BOARDSSIZE];
	int sbnum,swnum;//select num
	int total;
	int totalnode;

    double getscore( ucbnode* nodeptr, int child);
    ucbnode* getbestchild(ucbnode* nodeptr);
    void select(board &b);
    void update(double result,board& b);
    void run_a_cycle();
    void reset(board &b);
    void clear();
	void show_path();
    string inttostring(int i);
    string inttoGTPstring(int i);
};


#endif // MCTS_H
