//BackGround
#define GAME_ROWS       20
#define GAME_COLS       12

#define GAME_WALL       1
#define GAME_NOT_WALL   0

//Brick
#define BRICK_ROWS      4
#define BRICK_COLS      4

//
#define BRICK_START     (g_nType * (BRICK_ROWS * 4) + g_nRotate * BRICK_ROWS)



extern char g_BackGround[GAME_ROWS][GAME_COLS];
extern char g_Brick[][BRICK_COLS];

//brick
extern int g_nCurX;        //brick X坐标
extern int g_nCurY;        //brick Y坐标
extern int g_nType;        //brick 类型
extern int g_nRotate;      //旋转方式

extern int g_nFixed;        //是否已经固定

extern int g_nScore;   

extern int g_nPause;     
/*
Function: init background
*/
void
InitBackGround(void);

/*
Function: create brick
*/
void
CreateBrick(void);

/*
Function: MoveUp, that is to rotate
*/
void
MoveUp(void);

/*
Function: MoveUp, that is to ratate.
*/
void
MoveUp(void);

/*
Function: Move down quickly and fix this brick
*/
void
MoveFix(void);

void
MoveDown(void);

void
MoveLeft(void);

void
MoveRight(void);

/*
Function: fix the brick
*/
void
FixBrick(void);

/*
Function: set score
Param   : number of lines released
*/
void
SetScore(int released);


/*
Function: release the line all fixed with bricks

Return  : how many lines released.
*/
int
ReleaseLine(void);

/*
Function: entry point from the game
*/
void 
StartGame(void);