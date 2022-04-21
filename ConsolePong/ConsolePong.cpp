
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <time.h>
#include <cstdlib>
using namespace std;

struct Pad1 {
	int x=5, y1=10, y2=15;
};
struct Pad2 {
	int x=100-5, y1 = 10, y2 = 15;
};
struct Screen {
	int x = 100;
	int y = 25;
};
struct Ball {
	int x = 50, y = 10;
	int xMove = 1, yMove = 1;
};
int score1 = 0;
int score2 = 0;
void drawPad3(int pad1x, int pad2x, int y1, int y2,int pad2y1,int pad2y2,int screenx,int screeny,int ballx, int bally) {
	
	for (int i = 0; i < screeny; i++) {

		if (i == 0 || i==screeny-1) {
			for (int j = 0; j < screenx; j++) {
				cout << "#";
			}
			cout << "\n";
		}
		else {
			for (int j = 0; j < screenx; j++) {
				if (j == 0 || j == screenx - 1) {
					cout << "#";
				}
				else {
					
					if (i >= y1 && i <= y2 && j==pad1x) {
						cout << "|";
					}
					else if (i >= pad2y1 && i <= pad2y2 && j == pad2x) {
						cout << "|";
					}
					else if (i == bally && j == ballx) {
						cout << "O";
					}
					else {
						cout << " ";
					}
				}
			}
			cout << "\n";
		}
		
	}
		cout << "\nScore : =>" << score1<<" - "<<score2;
		
}
void MoveBall(Ball* ball, Screen* screen ,Pad1* pad1,Pad2* pad2) {
	if (ball->x == screen->x - 1 || ball->x == (screen->x - screen->x+1) ||(ball->x == pad1->x + 1 && (ball->y >= pad1->y1 && ball->y <= pad1->y2))|| (ball->x == pad2->x - 1 && (ball->y >= pad2->y1 && ball->y <= pad2->y2))		) {
		if (ball->x == screen->x - 1) {
			score2 += 1;
			Ball newBall; ball->x = newBall.x; ball->y = newBall.y;
			
		}
		else if (ball->x == (screen->x - screen->x + 1)) {
			score1 += 1;
			Ball newBall; ball->x = newBall.x; ball->y = newBall.y;
		}

		ball->xMove *= -1;

	}
	if (ball->y == screen->y - 1 || ball->y == (screen->y - screen->y+1)) {
		ball->yMove *= -1;
	}
	ball->x += ball->xMove;
	ball->y += ball->yMove;
}
void GameEngine(Screen* screen,Pad1* pad1,Pad2* pad2,Ball* ball) {
	drawPad3(pad1->x, pad2->x, pad1->y1, pad1->y2, pad2->y1, pad2->y2, screen->x, screen->y, ball->x, ball->y);
	unsigned char a;


	while (1)
	{
		Sleep(100);
		system("cls");
		if (_kbhit())
		{
			char current = _getch();
			if (current == 's' && pad1->y2 < screen->y-2) {

				drawPad3(pad1->x, pad2->x, pad1->y1, pad1->y2, pad2->y1, pad2->y2, screen->x, screen->y, ball->x, ball->y);
				pad1->y1++; pad1->y2++;
			}
			if (current == 'w' && pad1->y1 > screen->y - 19) {

				drawPad3(pad1->x, pad2->x, pad1->y1, pad1->y2, pad2->y1, pad2->y2, screen->x, screen->y, ball->x, ball->y);
				pad1->y1--; pad1->y2--;
			}
			if (current == 'e' && pad2->y1 > screen->y - 19) {

				drawPad3(pad1->x, pad2->x, pad1->y1, pad1->y2, pad2->y1, pad2->y2, screen->x, screen->y, ball->x, ball->y);
				pad2->y1--; pad2->y2--;
			}
			if (current == 'd' && pad2->y2 < screen->y - 2) {

				drawPad3(pad1->x, pad2->x, pad1->y1, pad1->y2, pad2->y1, pad2->y2, screen->x, screen->y, ball->x, ball->y);
				pad2->y1++; pad2->y2++;
			}
			cout << endl;
		}
		else {
			drawPad3(pad1->x, pad2->x, pad1->y1, pad1->y2, pad2->y1, pad2->y2, screen->x, screen->y, ball->x, ball->y);
			
		}
		MoveBall(ball, screen, pad1 ,pad2);
	}
}

int main(){
	Screen screen;
	Pad1 pad1;
	Pad2 pad2;
	Ball ball;
	GameEngine(&screen, &pad1, &pad2, &ball);
	
	return 0;
}

//drawPad2(5,4, 4, 9, 20, 100);

	//drawPad1(5, 3, 4,20-3,20-4,20,100);