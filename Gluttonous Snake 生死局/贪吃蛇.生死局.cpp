#include <stdio.h>  
#include <Windows.h>  
#include <time.h>  
#include <stdlib.h>  
#include <conio.h>    
typedef struct snake  
{  
    int x, y;//����  
    int direction;//�ƶ�����  ��1  ��2  ��3  ��4  
    snake * next;  
}*Msnake;  
  
struct food  
{  
    int x, y;  
}F;  
struct food1  
{  
    int x, y;  
}F1[800];  
int ai=0,k=0;  
int level; //�ȼ� 
int lengt = 4;//�߳���  
int t;//���ڼ�ʱ 
int score = 0;  //��óɼ� 
int l;// ���ڼ�¼��ͬ�ȼ����ٶ� 
int n = 0;//�Ե�ʳ�����  
snake * creat();//��ʼ���ߵ�λ�ü�����  
void showMain();//�����ն˵Ĵ�С������ ������Ϸ���棨�߿���ʾ�������ɼ�etc) 
void gotoxy(int x, int y);  //�����ƶ� 
void c(int k); //��ɫѡ�� 
int time(); //������ʱ 
void ycgb(int k); //���ع��  
void game(); //������Ϸ���� 
void draw(snake * head); //��������  
void newfood(snake * head);// //�������ʳ�ﲢ��֤ʳ�ﲻ���ߵ������غ�  
void newfood1(snake * head);  //��������ϰ�����֤�ϰ������ߵ������غ� 
int random();  //����������ֵ 
int direc(char ch);//���������  
void key(snake * head, snake * p);  //�ı��ߵķ�������ͣ���ܵ�ʵ��
void cls();//���� 
int main()  
{  
    ycgb(0);  
    showMain();  
    game();  
    while (1)  
    {  
        cls();
        gotoxy(32,10);  
        printf("���س������¿�ʼ��Ϸ��");  
        gotoxy(36,11);  
        printf("��Esc���뿪��Ϸ��");  
        char ch;  
        ch = getch();  
        while (ch != 13 && ch != 27)  
        {  
            ch = getch();  
        }  
        if (ch == 13)  
        {  
            showMain();  
            game();  
        }  
        else break;  
    }  
    return 0;  
}  
int direc(char ch)//���������  
{  
    if (ch == -32)  
    {  
        ch = getch();  
        if (ch == 72) return 1;  
        if (ch == 80) return 3;  
        if (ch == 75) return 2;  
        if (ch == 77) return 4;  
    }  
    return 0;  
}  
  
snake * creat() // ��ʼ���ߵ�λ�ü����� 
{  
    snake *head, *p, *q;  
    head = (snake *) malloc (sizeof(snake));  
    head->x = 28;  
    head->y = 10;  
    head->direction = 4;  
    head->next = NULL;  
    p = head;  
    for (int i = 0; i < 3; i++)  
    {  
        q = (snake *) malloc (sizeof(snake));  
        p->next = q;  
        q->next = NULL;  
        q->x = p->x + 2;  
        q->y = p->y;  
        q->direction = p->direction;  
        p = q;  
    }  
    return head;  
}  
  
void showMain()//�����ն˵Ĵ�С������ ������Ϸ���棨�߿���ʾ�������ɼ�etc)  
{  
    int i;  
    system("title ̰����.������");  
    system("mode con cols=80 lines=35");  
    gotoxy(28, 10);  
    c(10);  
    printf("��ӭ����̰���ߵ����磡��");  
    gotoxy(0, 0);  
    c(3);  
    for (i = 0; i < 40; i++)  
    {  
        printf("�~");  
        Sleep(30);  
    }  
    for (i = 1; i < 25; i++)  
    {  
        gotoxy(78, i);  
        printf("�~");  
        Sleep(30);  
    }  
    for (i = 39; i >= 0; i--)  
    {  
        gotoxy(2*i, 25);  
        printf("�~");  
        Sleep(30);  
    }  
    for (i = 24; i >= 1; i--)  
    {  
        gotoxy(0, i);  
        printf("�~");  
        Sleep(30);  
    }  
    c(10);  
    gotoxy(30, 11);  
    printf("��ѡ���Ѷȣ�0~6����");  
    scanf("%d", &level);  
    switch(level)
	{
	    case 1: l = 600;break; 
        case 2: l = 400;break; 
        case 3: l = 200;break;  
        case 4: l = 150;break;  
        case 5: l = 100;break; 
        case 6: l = 60;break;  
        default: l = 2333; break;
	 } 
    cls();  
    c(15);  
    gotoxy(4, 26);  
    printf("�ȼ��� %d", level);  
    gotoxy(20, 26);  
    printf("������ %d", score);  
    gotoxy(4, 27);  
    printf("��ǰ���ȣ� %d", lengt);  
    gotoxy(20, 27);  
    printf("�ѳ�ʳ������� %d", n);  
    gotoxy(45, 26);  
    printf("�ƶ�����������");  
    gotoxy(45, 27);  
    printf("��ͣor�������ո�");  
    gotoxy(67, 27);  
    printf("��������־");
	gotoxy(20,30);
	c(10); 
	printf("������ɫ����Ϸ����!��ɫ���������С�ɰ�����!");
	gotoxy(28,31); 
	printf("������һ�����Ȼ�����Ŷ��"); 
}  
  
void key(snake * head, snake * p)//�ı��ߵķ�������ͣ���ܵ�ʵ�� 
{  
    char ch;  
    int i, j,a;  
    if (kbhit())  
    {  
        ch = getch();  
        if (ch == -32)  
        {  
            i = direc(ch);  
            j = p->direction;  
            if ((i==1&&j==3)||(i==2&&j==4)||(i==3&&j==1)||(i==4&&j==2));//�ж��Ƿ���ԭ�з������ͻ  
            else  
                p->direction = i;  
        }else  
            if (ch == 32)  
            {  
                cls();  
                gotoxy(36,10);  
                printf("��ͣ��");  
                while (1)  
                {  
                    if (kbhit() && getch() == 32)  
                    {  
                        gotoxy(36,10);  
                        printf("     ");  
                        draw(head);
                        gotoxy(F.x, F.y);  
                        c(12);  
                        printf("��");
						for(a=0;a<ai;a++)
						{
							gotoxy(F1[a].x,F1[a].y);
							c(10);
							printf("��");
						  }  
                        break;  
                    }  
                }  
            }  
    }  
}  
  
void cls() //���� 
{  
    gotoxy(2, 1);  
    for (int i = 1; i < 26; i++)  
    {  
        for (int j = 2; j < 78; j++)  
            printf(" ");  
        gotoxy(2, i);  
    }  
}  
int random()//����������ֵ  
{  
    srand(time()+rand());//����������ӳ�ʼ��  
    return rand();//���������  
}  
  
void newfood(snake * head)  //�������ʳ�ﲢ��֤ʳ�ﲻ���ߵ������غ� 
{  
    int j; 
    snake *p;  
    p = head;  
    int f = 1;  
    F.x = random() % 76 + 1;  
    if (F.x&1) F.x++;  
    F.y = random() % 24 + 1;  
    while (p)  
    {  
        if (p->x == F.x && p->y == F.y)  
        {  
            f = 0;  
            break;  
        }
		for(j=0;j<ai;j++)
		{
			  if (F1[j].x  == F.x && F1[j].y == F.y)  
		        {  
		            f = 0;  
		            break;  
		        } 
		  }  
        p = p->next;  
    }  
    if (f)  
    {  
        c(12);  
        gotoxy(F.x, F.y);  
        printf("��");  
    }  
    else newfood(head);  
} 
void newfood1(snake * head)  //��������ϰ�����֤�ϰ������ߵ������غ� 
{  
    snake *p;  
    p = head;  
    int f = 1;  
    F1[ai].x = random() % 76 + 1;  
    if (F1[ai].x&1) F1[ai].x++;  
    F1[ai].y = random() % 24 + 1;  
    while (p)  
    {  
        if (p->x == F1[ai].x && p->y == F1[ai].y)  
        {  
            f = 0;  
            break;  
        }  
        p = p->next;  
    }
    if (F.x == F1[ai].x && F.y == F1[ai].y)  
    {  
        f = 0;  
    }  
    if (f)  
    {  
        c(10);  
        gotoxy(F1[ai].x, F1[ai].y);  
        printf("��"); 
		ai++; 
    }  
    else newfood1(head);
} 
  
void draw(snake * head) //���� 
{  
    gotoxy(head->x, head->y);  
    c(12);  
    printf("��");  
    c(15);  
    head = head->next;  
    while (head->next)  
    {  
        gotoxy(head->x, head->y);  
        printf("��");  
        head = head->next;  
    }  
    c(12);  
    gotoxy(head->x, head->y);  
    printf("��");  
}  
  
void c(int k)//�ı���ɫ���  
{  
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), k);  
}  
  
int time()//������ʱ  
{  
    clock_t t=clock()/CLOCKS_PER_SEC;  
    return t;  
}  
  
void gotoxy(int x,int y) //�ƶ����  
{  
    COORD coord;  
    coord.X=x;  
    coord.Y=y;  
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), coord );  
}  
  
void ycgb(int k)//���ع��  
{  
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);  
    CONSOLE_CURSOR_INFO cci;  
    GetConsoleCursorInfo(hOut,&cci);  
    cci.bVisible=k;//��1Ϊ��ʾ����0Ϊ����  
    SetConsoleCursorInfo(hOut,&cci);  
}  
 void game() //������Ϸ����  
{  
   again: ai=0;
	int j;
    snake *head, *p, *q, *s;  
    head = creat();  
    s=p = head;  
   
    while (p->next)  
        p = p->next;  
    draw(head);  
    newfood(head);  
    while (1)  
    {  
        q = (snake *) malloc (sizeof(snake));  
        p->next = q;  
        q->direction = p->direction;  
        q->next = NULL;  
        switch(p->direction)  
        {  
            case 1: q->x = p->x; q->y = p->y - 1; break;  
            case 2: q->x = p->x - 2; q->y = p->y; break;  
            case 3: q->x = p->x; q->y = p->y + 1; break;  
            case 4: q->x = p->x + 2; q->y = p->y; break;  
        }  
        if (q->x == F.x && q->y == F.y) //�Ե�ʳ��߱䳤���������ݣ� 
        {  
            gotoxy(p->x, p->y);  
            c(15);  
            printf("��");  
            gotoxy(q->x, q->y);  
            c(12);  
            printf("��");  
            p = q;  
            score = score +level;  
            lengt++;  
            n++;
            k++;
		    if(k==8-level) 
			{
				level=(level)%6+1;
     			switch(level)
				{
				    case 1: l = 600;break; 
			        case 2: l = 400;break; 
			        case 3: l = 200;break;  
			        case 4: l = 150;break;  
			        case 5: l = 100;break; 
			        case 6: l = 60;break;  
				 } 
			    cls();  
	            gotoxy(30, 10);  
	            printf("��ϲ��������");  
	            Sleep(1000);
	            cls(); 
				k=0;
				goto again; 				
			}  
            c(15);  
            gotoxy(20, 26);  
            printf("������ %d", score);  
            gotoxy(4, 27);  
            printf("��ǰ���ȣ� %d", lengt);  
            gotoxy(20, 27);  
            printf("�ѳ�ʳ������� %d", n);  
            newfood(head);  
        }else  
        {  
		    for(j=0;j<ai;j++)//�Ƿ�ײ�����ϰ��� 
			{
				if(F1[j].x==q->x && F1[j].y==q->y)
				{
				    cls();  
		            gotoxy(30, 10);  
		            printf("���ķ���Ϊ%d", score);  
		            Sleep(2500);  
		            score = 0;  
		            n = 0;
					k=0;  
		            lengt = 4;  
		            return;  	
				}
			 } 
            gotoxy(head->x, head->y);  
            printf(" ");  
            head = head->next;  
            free(s);  
            gotoxy(head->x, head->y);  
            c(12);  
            printf("��");  
            gotoxy(p->x, p->y);  
            c(15);  
            printf("��");  
            gotoxy(q->x, q->y);  
            c(12);  
            printf("��");  
            p = q;  
        }
		newfood1(head);   
        Sleep(l); 
        key(head, q);  
        if (q->x==0||q->x==78||q->y==0||q->y==25)//��ǽ����  
        {  
            cls();  
            gotoxy(30, 10);  
            printf("���ķ���Ϊ%d", score);  
            Sleep(2500);  
            score = 4;  
            n = 0;  
            lengt = 0;
			k=0;  
            return;  
        }
		s=head;   
        while (s->next)  
        {  
            if (q->x == s->x && q->y == s->y)//���Լ�����  
            {  
                cls();  
                gotoxy(30, 10);  
                printf("���ķ���Ϊ%d", score);  
                Sleep(2500);  
                score = 0;  
                n = 0;  
                lengt = 4;
				k=0;  
                return;  
            }  
            s = s->next;  
        }  
       s = head;  
    }  
}  
