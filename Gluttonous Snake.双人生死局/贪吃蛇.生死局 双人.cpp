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
struct food2  
{  
    int x, y;  
}F2;   
struct food1  
{  
    int x, y;  
}F1[800]; 
struct food3  
{  
    int x, y;  
}F12[800];  
int ai=0,k=0,ai2=0,k2=0,a=1,b=1;
int level; //�ȼ� 
int lengt = 4;//�߳���
int lengt2 = 4;//��2����  
int t;//���ڼ�ʱ 
int score = 0;  //��óɼ� 
int score2 = 0;  //2��óɼ� 
int l;// ���ڼ�¼��ͬ�ȼ����ٶ� 
int n = 0;//�Ե�ʳ�����
int n2 = 0;//2�Ե�ʳ�����  
snake * creat();//��ʼ���ߵ�λ�ü�����
snake * creat2();//��ʼ����2��λ�ü�����  
void showMain();//�����ն˵Ĵ�С������ ������Ϸ���棨�߿���ʾ�������ɼ�etc) 
void gotoxy(int x, int y);  //�����ƶ� 
void c(int k); //��ɫѡ�� 
int time(); //������ʱ 
void ycgb(int k); //���ع��  
void game(); //������Ϸ���� 
void draw(snake * head); //��������  
void newfood(snake * head);// //�������ʳ�ﲢ��֤ʳ�ﲻ���ߵ������غ� 
void newfood2(snake * head);// //�������ʳ�ﲢ��֤ʳ�ﲻ����2�������غ�  
void newfood1(snake * head);  //��������ϰ�����֤�ϰ������ߵ������غ�
void newfood3(snake * head);  //��������ϰ�����֤�ϰ�������2�������غ� 
int random();  //����������ֵ 
int direc(char ch);//��������� 
int direc2(char ch);//���������  
void key(snake * head,snake*head1, snake * p,char ch);  //�ı��ߵķ����ܵ�ʵ��
void key2(snake * head,snake*head1, snake * p2,char ch);  //�ı���2�ķ����ܵ�ʵ��
void pause(snake * head,snake*head1, snake * p,char ch);  //��ͣ���ܵ�ʵ��
void cls();//���� 
void cls2();//���� 2
int judge(int a,int b);//������һ��ʧ���ж� 
int main()  
{  
    ycgb(0);  
    showMain();  
    game(); 
    while (1)  
    {  
        cls();
        gotoxy(32,10);
		c(10);  
        printf("���س������¿�ʼ��Ϸ��");  
        gotoxy(34,11);  
        printf("��Esc���뿪��Ϸ��");
		cls2();
        gotoxy(114,10);  
        printf("���س������¿�ʼ��Ϸ��");  
        gotoxy(116,11);  
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
        if (ch == 119) return 1;
		if (ch == 97) return 2;   
        if (ch == 115) return 3;  
        if (ch == 100) return 4; 
        return 0;  
}
int direc2(char ch)//2���������  
{  
        ch = getch();  
        if (ch == 72) return 1;  
        if (ch == 80) return 3;  
        if (ch == 75) return 2;  
        if (ch == 77) return 4; 
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
snake * creat2() // ��ʼ����2��λ�ü����� 
{  
    snake *head2, *p, *q;  
    head2 = (snake *) malloc (sizeof(snake));  
    head2->x = 110;  
    head2->y = 10;  
    head2->direction = 4;  
    head2->next = NULL;  
    p = head2;  
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
    return head2;  
}  
    
void showMain()//�����ն˵Ĵ�С������ ������Ϸ���棨�߿���ʾ�������ɼ�etc)  
{  
    int i;  
    system("title ̰����.������˫��");  
    system("mode con cols=162 lines=35");  
    gotoxy(28, 10);  
    c(10);  
    printf("��ӭ����̰���ߵ����磡��");
	gotoxy(108, 10);  
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
	gotoxy(82, 0);  
    c(3);  
    for (i = 0; i < 40; i++)  
    {  
        printf("�~");  
        Sleep(30);  
    }  
    for (i = 1; i < 25; i++)  
    {  
        gotoxy(160, i);  
        printf("�~");  
        Sleep(30);  
    }  
    for (i = 39; i >= 0; i--)  
    {  
        gotoxy(2*i+82, 25);  
        printf("�~");  
        Sleep(30);  
    }  
    for (i = 24; i >= 1; i--)  
    {  
        gotoxy(82, i);  
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
	cls2();  
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
    c(13);  
    gotoxy(86, 26);  
    printf("�ȼ��� %d", level);  
    gotoxy(106, 26);  
    printf("������ %d", score);  
    gotoxy(86, 27);  
    printf("��ǰ���ȣ� %d", lengt);  
    gotoxy(106, 27);  
    printf("�ѳ�ʳ������� %d", n);  
    gotoxy(127, 26);  
    printf("�ƶ�����������");  
    gotoxy(127, 27);  
    printf("��ͣor�������ո�"); 
	gotoxy(64,30);
	c(10); 
	printf("������ɫ����Ϸ����!��ɫ���������С�ɰ�����!");
	gotoxy(74,31); 
	printf("������һ�����Ȼ�����Ŷ��"); 
	 gotoxy(150, 33);  
    printf("��������־");
}  
  
void key(snake * head,snake* head1, snake * p,char ch)//�ı���1�ķ����ʵ�� 
{    
    int i, j;      
    i = direc(ch);  
    j = p->direction;  
    if ((i==1&&j==3)||(i==2&&j==4)||(i==3&&j==1)||(i==4&&j==2));//�ж��Ƿ���ԭ�з������ͻ  
    else  
        p->direction = i;  
}  
void pause(snake * head,snake*head1, snake * p2,char ch)//��ͣ���ܵ�ʵ�� 
 {
 	   int i;
       if(a==1)
       {
		   	cls();  
		    gotoxy(36,10);  
		    printf("��ͣ��");
	   }
	   if(b==1)
	   {
	   	    cls2(); 
			gotoxy(118,10);  
	        printf("��ͣ��");
	   }
        while (1)  
        {  
           if (kbhit() && getch() == 32)  
            {  
               if(a==1)
               {
	               	gotoxy(36,10);  
	                printf("     ");  
	                draw(head);
	                gotoxy(F.x, F.y);  
	                c(12);  
	                printf("��");
					for(i=0;i<ai;i++)
					{
						gotoxy(F1[i].x,F1[i].y);
						c(10);
						printf("��");
					  }
			    }
			   if(b==1)
			   {
			   	
					gotoxy(118,10);  
	                printf("     ");
					draw(head1);
	                gotoxy(F2.x, F2.y); 
				    c(12); 
					printf("��");
					for(i=0;i<ai2;i++)
					{
						gotoxy(F12[i].x,F12[i].y);
						c(10);
						printf("��");
					}    
			    }
				break;
		    }   
		}  
   }  
void key2(snake * head,snake*head1, snake * p2,char ch)//�ı���2�ķ�������ͣ���ܵ�ʵ�� 
{   
    int i,j;      
    i = direc2(ch);  
    j = p2->direction;  
    if ((i==1&&j==3)||(i==2&&j==4)||(i==3&&j==1)||(i==4&&j==2));//�ж��Ƿ���ԭ�з������ͻ  
    else  
    p2->direction = i;   
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
void cls2() //����2 
{  
    gotoxy(84, 1);  
    for (int i = 1; i < 26; i++)  
    {  
        for (int j = 2; j < 78; j++)  
            printf(" ");  
        gotoxy(84, i);  
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
void newfood2(snake * head)  //�������ʳ�ﲢ��֤ʳ�ﲻ����2�������غ� 
{  
    int j; 
    snake *p;  
    p = head;  
    int f = 1;  
    F2.x = random() % 76+ 83;
	if(F2.x&1) F2.x++;  
    F2.y = random() % 24 + 1;  
    while (p)  
    {  
        if (p->x == F2.x && p->y == F2.y)  
        {  
            f = 0;  
            break;  
        }
		for(j=0;j<ai2;j++)
		{
			  if (F12[j].x  == F2.x && F12[j].y == F2.y)  
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
        gotoxy(F2.x, F2.y);  
        printf("��");  
    }  
    else newfood2(head);  
} 
void newfood1(snake * head)  //��������ϰ�����֤�ϰ������ߵ������غ� 
{  
    snake *p;  
    p = head;  
    int f = 1;  
    F1[ai].x = random() % 76 + 1;  
    if (F1[ai].x&1) 
	F1[ai].x++;  
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
void newfood3(snake * head2)  //��������ϰ�����֤�ϰ�������2�������غ� 
{  
    snake *p;  
    p = head2;  
    int f = 1;  
    F12[ai2].x = random() % 76 + 83;  
    if (F12[ai2].x&1)
	F12[ai2].x++;  
    F12[ai2].y = random() % 24 + 1;  
    while (p)  
    {  
        if (p->x == F12[ai2].x && p->y == F12[ai2].y)  
        {  
            f = 0;  
            break;  
        }  
        p = p->next;  
    }
    if (F2.x == F12[ai2].x && F2.y == F12[ai2].y)  
    {  
        f = 0;  
    }  
    if (f)  
    {  
        c(10);  
        gotoxy(F12[ai2].x, F12[ai2].y);  
        printf("��"); 
		ai2++; 
    }  
    else newfood3(head2);
} 
  
void draw(snake * head) //���� 
{  
    gotoxy(head->x, head->y);  
    c(12);  
    printf("��");  
    c(13);  
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
 int judge(int a,int b)//�ж�ʧ��һ�� 
 {
 	if(a+b==0)
 	{
 		cls();  
        gotoxy(30, 10);  
        printf("���ķ���Ϊ%d", score);
		cls2();  
        gotoxy(112, 10);  
        printf("���ķ���Ϊ%d", score2);
		if(score>score2)
		{
			gotoxy(28,11);
			printf("��ϲ���߻�ʤ��");
			gotoxy(110,11);
			printf("��ϲ���߻�ʤ��");	
		  }
		if(score<score2)
		{
			gotoxy(28,11);
			printf("��ϲ���߻�ʤ��");
			gotoxy(110,11);
			printf("��ϲ���߻�ʤ��");	
		  }
		  if(score==score2)
		  {
		  	gotoxy(34,11);   
			printf("ƽ�֣�");
			gotoxy(116,11); 
			printf("ƽ�֣�");
			
		  }    
        Sleep(2500);  
        score = 0;  
        n = 0;
		k=0;  
        lengt = 4;
        score2 = 0;  
        n2 = 0;
		k2=0;  
        lengt2 = 4;
		return 1;	 	
	 }else
	 return 0; 
}   
 void game() //������Ϸ����  
{  
    ai=0;
    ai2=0;
    a=b=1;
	int j,c1=0;
	char ch;
    snake *head, *p, *q, *s,*head2, *p2, *q2, *s2;  
    head = creat();
	head2 = creat2();   
    s=p = head;
	s2=p2 = head2;    
    while (p->next)  
        p = p->next;
	while (p2->next)  
        p2 = p2->next;  
    draw(head);
	draw(head2);   
    newfood(head);
	newfood2(head2);  
    while (1)  
    {  
       if(a==1)
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
		} 
        if(b==1)
		{
			q2 = (snake *) malloc (sizeof(snake));  
	        p2->next = q2;  
	        q2->direction = p2->direction;  
	        q2->next = NULL;
			switch(p2->direction)  
	        {  
	            case 1: q2->x = p2->x; q2->y = p2->y - 1; break;  
	            case 2: q2->x = p2->x - 2; q2->y = p2->y; break;  
	            case 3: q2->x = p2->x; q2->y = p2->y + 1; break;  
	            case 4: q2->x = p2->x + 2; q2->y = p2->y; break;  
	        } 
		 } 
         if(a==1)
         {
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
	            c(15);  
	            gotoxy(20, 26);  
	            printf("������ %d", score);  
	            gotoxy(4, 27);  
	            printf("��ǰ���ȣ� %d", lengt);  
	            gotoxy(20, 27);  
	            printf("�ѳ�ʳ������� %d", n); 
			    if(k==8-level) 
				{
					cls(); 
					c(10); 
		            gotoxy(30, 10);  
		            printf("���ķ���Ϊ%d", score);
					cls2();  
		            gotoxy(112, 10);  
		            printf("���ķ���Ϊ%d", score2);
		            gotoxy(28,11);
					printf("��ϲ���߻�ʤ��");
					gotoxy(110,11);
					printf("��ϲ���߻�ʤ��");
					Sleep(2500);
					score = 0;  
			        n = 0;
					k=0;  
			        lengt = 4;
			        score2 = 0;  
			        n2 = 0;
					k2=0;  
			        lengt2 = 4;
					return ;
				}   
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
						    a=0;
							c1=judge(a,b);
							if(c1)
							return ; 	
						}
					} 
					if(a==1)
					{
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
			}
	    }
		if(b==1)
		{
			if (q2->x == F2.x && q2->y == F2.y) //2�Ե�ʳ��߱䳤���������ݣ� 
            {  
	            gotoxy(p2->x, p2->y);  
	            c(13);  
	            printf("��");  
	            gotoxy(q2->x, q2->y);  
	            c(12);  
	            printf("��");  
	            p2 = q2;  
	            score2 = score2 +level;  
	            lengt2++;  
	            n2++;
	            k2++;
	            c(13);  
	            gotoxy(106, 26);  
	            printf("������ %d", score2);  
	            gotoxy(86, 27);  
	            printf("��ǰ���ȣ� %d", lengt2);  
	            gotoxy(106, 27);  
	            printf("�ѳ�ʳ������� %d", n2);
			    if(k2==8-level) 
				{
					cls();
					c(13);  
		            gotoxy(30, 10);	  
		            printf("���ķ���Ϊ%d", score);
					cls2();  
		            gotoxy(112, 10);  
		            printf("���ķ���Ϊ%d", score2);
		            gotoxy(28,11);
					printf("��ϲ���߻�ʤ��");
					gotoxy(110,11);
					printf("��ϲ���߻�ʤ��");
					Sleep(2500);
				    score = 0;  
			        n = 0;
					k=0;  
			        lengt = 4;
			        score2 = 0;  
			        n2 = 0;
					k2=0;  
			        lengt2 = 4; 
					return ;				
				}    
	            newfood2(head2); 
			}else
             {  
	   		    for(j=0;j<ai2;j++)//2�Ƿ�ײ�����ϰ��� 
				{
					if(F12[j].x==q2->x && F12[j].y==q2->y)
					{
					    cls2();  
			            gotoxy(112, 10);
						c(13);  
			            printf("���ķ���Ϊ%d", score2);
						b=0; 
						c1=judge(a,b);
					    if(c1==1)
					    return ;
					}
				 }
				if(b==1)
				{
					 gotoxy(head2->x, head2->y);  
		            printf(" ");  
		            head2 = head2->next;  
		            free(s2);  
		            gotoxy(head2->x, head2->y);  
		            c(12);  
		            printf("��");  
		            gotoxy(p2->x, p2->y);  
		            c(13);  
		            printf("��");  
		            gotoxy(q2->x, q2->y);  
		            c(12);  
		            printf("��");  
		            p2 = q2;
				 } 
				 
	        }
		}	
			if(a==1)
			newfood1(head);  
			if(b==1)
			newfood3(head2);  
	        Sleep(l); 
	        if(kbhit())
			{
				ch=getch();
				if(ch==-32)
				{
				     if(b==1)
		         	key2(head2,head, q2,ch);
				} 
				if(ch==115||ch==97||ch==119||ch==100)
				{    
					if(a==1)
				    key(head,head2, q,ch); 
				}
				if(ch==32)
				{
				    pause(head,head2,q,ch);
				}
			  }  
	    if(a==1)
	    {
	    	if (q->x==0||q->x==78||q->y==0||q->y==25)//��ǽ����  
	        {  
                cls();  
	            gotoxy(30, 10); 
	            printf("���ķ���Ϊ%d", score);
				a=0;
				c1=judge(a,b);
				if(c1==1)
				return ; 
	        }
		}
		if(a==1)
		{
			s=head;   
	        while (s->next)  
	        {  
	            if (q->x == s->x && q->y == s->y)//���Լ�����  
	            {  
	                cls();  
		            gotoxy(30, 10);   
		            printf("���ķ���Ϊ%d", score);
					a=0;
					c1=judge(a,b);
					if(c1==1)
					return ;  
	            }  
	            s = s->next;  
	        } 
	        s = head; 
		}    
	    if(b==1)
	    {
	    	if (q2->x==82||q2->x==160||q2->y==0||q2->y==25)//2��ǽ����  
	        {  
                cls2();  
	            gotoxy(112, 10);  
	            c(13); 
	            printf("���ķ���Ϊ%d", score2);
				b=0;
		    	c1=judge(a,b);
				if(c1==1)
				return;
	        }
		}
		if(b==1)
		{
			s2=head2;   
	        while (s2->next)  
	        {  
	            if (q2->x == s2->x && q2->y == s2->y)//2���Լ�����  
	            {  
					cls2();  
		            gotoxy(112, 10);
					c(13);   
		            printf("���ķ���Ϊ%d", score2);
					b=0;
					c1=judge(a,b);
					if(c1==1)
					return ;  
	            }  
	            s2 = s2->next;  
	        }  
	       s2 = head2;
		 } 
	}  
 }
  
 
