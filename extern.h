#define MAX_FILE_LEN 32
#define PATH_COST 1
#define GOAL_STATE 1,2,3,4,5,6,7,8,9
//#define GOAL_STATE 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,0
#define SIZE 3
#define BOARD_SIZE SIZE*SIZE

struct stateNode{
	int heuristic;
	int state[BOARD_SIZE];
	int pathCost;
	struct stateNode * pred;
};


int cost(struct stateNode*);
int cmp(struct stateNode*, struct stateNode*);
void printNode(struct stateNode*);
void printNodePath(struct stateNode*);
void h(struct stateNode*, struct stateNode*);
int solvable(struct stateNode*, struct stateNode*);
