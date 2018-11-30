#include<bits/stdc++.h>
using namespace std;
int sum1,sum2,n,tot,x,money,q,dead,att;
struct solider
{
	string name;
	int attack,defence,life;
}s[4];
struct boss
{
	string name;
	int attack,defence,life,prize,rest;
}b[4];
struct thing
{
	string ch,des;
	int price,add;
}th[4];
struct blood
{
	int sum;
	int recover;
}bl;
void store()
{
	int flag;
	printf("Welcome! What do you want to buy?\n");
	for(int i=1;i<=3;i++)
	{
		printf("%d.",i);
		cout<<th[i].ch<<"  "<<th[i].des<<"         ";
		printf("price==%d Gold coins\n",th[i].price);
	}
	scanf("%d",&flag);
	if(money<th[flag].price) printf("Sorry,your money is not enough.\n");
	else
	{
		if(th[flag].des[0]=='a') s[n].attack+=th[flag].add;
		if(th[flag].des[0]=='d') s[n].defence+=th[flag].add;
		if(th[flag].des[0]=='r') bl.sum++;
		money-=th[flag].price;
		th[flag].price*=2;
	}
}
bool think()
{
	int ans;
	srand((int)time(0));
	ans=rand();
	if(ans%2==0) return 1;
	else return 0;
}
void fight()
{
	int your,enemy,rest;
	int flag;
	your=s[n].life;
	enemy=b[q].life;
	printf("You are facing the ");
	cout<<b[q].name<<"!"<<endl;
	while(your>0 && enemy>0)
	{
		printf("It is your turn!What do you want to do?\n");
		printf("1.attack  2.recover\n");
		scanf("%d",&flag);
		if(flag==1)
		{
			int hurt=s[n].attack-b[q].defence;
			if(hurt<0) hurt=0;
			if(hurt!=0)
			{
				enemy-=hurt;
				printf("The monster gets hurt!\n");
				printf("Its HP dropped by %d points.\n",hurt);

			}
			else printf("Your attack doesn't work!\n");
		}
		if(flag==2)
		{
			if(bl.sum>0)
			{
				printf("You take some medicine.\n");
				printf("Your HP has risen by %d points!\n",bl.recover);
				bl.sum--;
				your+=bl.recover;
				your=min(your,2*s[n].life);
				printf("You have %d bottles medicine left.\n",bl.sum);
				printf("Your HP are %d points now!\n",your);
			}
			else
			{
				printf("You have no medicine!\n");
				printf("You have lost the chance!\n");
			}
		}
		printf("It is the monster's turn.\n");
		printf("It is thinking......\n");
		sum1=0;
		sum2=0;
		att=b[q].attack-s[n].defence;
		if(att<0) att=0;
		sum1=think();
		if(sum1==1)
		{
			printf("Your enemy attack you!\n");
			if(att>0) printf("Your HP dropped by %d points!\n",att);
			else printf("Its attack doesn't work!\n");
			your-=att;
		}
		else
		{
			printf("Your enemy choose to have a rest!\n");
			enemy+=b[q].rest;
			enemy=min(enemy,2*b[q].life);
			printf("Its HP are %d points now!\n",enemy);
		}
	}
	if(your<=0)
	{
		printf("You are dead!\n");
		printf("Good luck next time!\n");
		dead=1;
		return;
	}
	if(enemy<=0)
	{
		printf("The monster die!\n");
		printf("you get %d gold coins for prize!\n",b[q].prize);
		money+=b[q].prize;
	}
}
int main()
{
	bl.recover=50;
	s[1].name="soilder";
	s[1].attack=25;
	s[1].defence=25;
	s[2].name="rider";
	s[2].attack=20;
	s[2].defence=30;
	s[3].name="wizard";
	s[3].attack=30;
	s[3].defence=25;
	for(int i=1;i<=3;i++) s[i].life=100;
	b[1].name="dragon";
	b[1].attack=35;
	b[1].defence=10;
	b[1].life=100;
	b[1].prize=100;
	b[1].rest=5;
	b[2].name="ghost";
	b[2].attack=40;
	b[2].defence=20;
	b[2].life=200;
	b[2].prize=200;
	b[2].rest=10;
	b[3].life=500;
	b[3].name="super dragon";
	b[3].attack=60;
	b[3].defence=50;
	b[3].prize=500;
	b[3].rest=20;
	th[1].ch="sword";
	th[1].des="attack+10";
	th[1].price=100;
	th[1].add=10;
	th[2].ch="helmet";
	th[2].des="defence+10";
	th[2].price=150;
	th[2].add=10;
	th[3].ch="blood bottle";
	th[3].des="recover your blood in the fight";
	th[3].price=50;
	printf("Welcome to the amazing world!\n");
	printf("People in this world are fighting with monsters.\n");
	printf("They need your help.\n");
	printf("Choose your fighter.\n");
	for(int i=1;i<=3;i++)
	{
		printf("%d ",i);
		cout<<s[i].name<<endl;
		printf("attack=%d   defence=%d   life=%d\n",s[i].attack,s[i].defence,s[i].life);
	}
	printf("which fighter do you want to choose?\n");
	scanf("%d",&n);
	while(1)
	{
		int t;
		printf("Take action now!\n");
		printf("1.go to the store    2.go to kill monsters    3.exit the game    4.get some information about myself\n");
		scanf("%d",&t);
		if(t==3) break;
		if(t==1) store();
		if(t==2)
		{
			printf("Choose your enemy.\n");
			for(int i=1;i<=3;i++)
			{
				printf("%d.",i);
				cout<<b[i].name<<"    ";
			}
			scanf("%d",&q);
			fight();
			if(dead==1) return 0;
		}
		if(t==4)
		{
			printf("Your attack==%d\n",s[n].attack);
			printf("Your defence==%d\n",s[n].defence);
			printf("Your money==%d Gold coins\n",money);
		}
	}
	printf("Thank for your playing!\n");
	return 0;
}
