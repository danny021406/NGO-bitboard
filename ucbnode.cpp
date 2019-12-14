#include "ucbnode.h"


void ucbnode::setlogc()
{
    logc = log(count);
}
ucbnode::ucbnode()
{
    
}
ucbnode::~ucbnode()
{
    if(childptr != NULL) {delete [] childptr;childptr=NULL;}
}


void ucbnode::initucbnode(int i,bool j)
{
    color=j;
    place=i;
    mean = 0.5;
    count = basenum;
    csize=0;
    memset(child,-1,sizeof(child));
    childptr=NULL;
    logc=1;
}

void ucbnode::addresult(double result)
{
    if((result > 0 && color==BLACK) || (result < 0 && color==WHITE) )
    {
        mean = (mean*count+1.00)/(count+1);
    }else
    {
        mean = (mean*count)/(count+1);
    }
    count+=1;
    setlogc();
}
void ucbnode::expansion(board &b)
{
	int i,k;
	bool j;
	j=!b.just_play_color();
	csize=0;
	for(i=0;i<BOARDSSIZE;i++)
	{
		if(b.check(i,j))
		{
			csize++;
		}
	}
	if(csize==0)
	{
		return;
	}
	childptr = new ucbnode [csize];
	k=0;
	for(i=0;i<BOARDSSIZE;i++)
	{
		if(b.check(i,j))
		{
			child[i]=k;
			childptr[k].initucbnode(i,j);
			k++;
		}
	}
}
int ucbnode::getbestmove()
{
	int ret = -1;
	double ans=-100,tmp;
	for(int i = 0;i<csize;i++)
	{
		tmp = childptr[i].count;// * childptr[i].mean;
		if(tmp > ans)
		{
			ans = tmp;
			ret=i;
		}
	}
	return ret;
}

void ucbnode::show_child()
{
	for(int i=0;i<csize;i++)
	{
		if(childptr[i].count<10)continue;
		cerr<< inttoGTPstring((int)childptr[i].place)<<' '<<childptr[i].mean<<' '<<childptr[i].count<<' '<<endl;
		//cerr<<sqrt( logc / ((childptr[i].count) - minusnum))* UCB_WEIGHT<<' ' ;
		// cerr<<(childptr[i].ravemean)<<' '<<(childptr[i].ravecount)<<endl;
	}
}
float ucbnode::show_inf(int best)
{
		cerr<<"total : "<< count -basenum <<endl<<"winrate :"<<(childptr[best].mean)<<"\n";
		//cerr<<"\nlog : "<<sqrt( logc / ((childptr[best].count) - minusnum))* UCB_WEIGHT ;
		// cerr<<"\nrave : "<<(childptr[best].ravemean)<<' '<<(childptr[best].ravecount)<<endl;
		return childptr[best].mean;
}

string ucbnode::inttoGTPstring(int i)
{
    string s = "A1";
    s[0]+= i / 9;
    if(s[0]>='I')s[0]++;
    s[1]+= i % 9;
    return s;
}
string ucbnode::inttostring(int i)
{
    return inttoGTPstring(i);
}