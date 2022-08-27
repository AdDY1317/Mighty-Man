#include <iostream>
#include<ctime>
using namespace std;

void gameStory()
{
  cout<<"                  Hello Warrior"<<endl;
  cout<<"_____________________Welcome________________"<<endl;
}
//Algorithm

class Player
{
private:
int health= 100;

int maxDamage= 30;
int minDamage= 20;

int maxHealing= 15;
int minHealing= 10;

public:
int modifiedHealth=50;

void modifiedDefence()
{
  cout<<"New Defence unlocked"<<endl;
}
Player()
{
  cout<<"I am the Mighty Man"<<endl;
  cout<<"We need to save the world!"<<endl<<endl;
  cout<<"Here are stats which would be helpful"<<endl;

  cout<<"Mighty Man's Health:"<<health<<endl;
  cout<<"****************************************************"<<endl;

  cout<<"Might Man's Attack Range:"<<minDamage<<"--"<<maxDamage<<endl;
  cout<<"****************************************************"<<endl;

  cout<<"Might Man's Healing Range:"<<minHealing<<"--"<<maxHealing<<endl;
  cout<<"*****************************************************"<<endl;
  
}
int GetHealth()
{
  return health;
}

void TakeDamage(int damage)
{
  if(health<0)
  {
    cout<<"OOH NO, CRITAICAL HIT"<<endl;
    cout<<"Enemy is dealing damage of"<<damage<<"To the Mighty Man"<<endl;
    health= health- damage;
    if(health<0)
    {
     cout<<"Our Hero Died...YOU LOST"<<endl<<endl;  
    }
   else
    {
    cout<<"Might Man's Current health after receiving damage: "<<health<<endl;
    }
  }
  
  
  
}

int GiveDamage()
{
 srand(time(0));
  int randomDamage= (rand()%(maxDamage-minDamage+1)+minDamage);
  
 return randomDamage; 
}

void Heal()
{
  srand(time(0));
int randomHeal= (rand()%(maxHealing- minHealing+1)+minHealing);
  health= health+randomHeal;
  cout<<"Might Man healed with Hp:"<<randomHeal<<endl;
  cout<<"Might Man's health after healing:"<<health<<endl;
}

};

class Enemy
{
private:

int health= 100;

int maxDamage= 50;
int minDamage= 20;

public:
Enemy()
{
  cout<<"Hello Fellas, I am the Villan"<<endl;
}
int GetHealth()
{
  return health;
}

void TakeDamage(int damage)
{
  
    cout<<"OOH NO, CRITAICAL HIT to Enemy***"<<endl;
    cout<<"Player is dealing damage of"<<damage<<"To the Enemy***"<<endl;
    health= health- damage;
  if(health<0)
  {
    cout<<"Enemy Died..."<<endl<<endl; 
  }
  else
  {
    cout<<"Enmey's Current health after receiving damage: "<<health<<endl;
  }
  
} 


int GiveDamage()
{
 srand(time(0));
  int randomDamage= (rand()%(maxDamage-minDamage+1)+minDamage);

 return randomDamage; 
}
};

void gameloop(Player player, Enemy enemy)
{
  char playerChoice;
  
  do
  {
    
    cout<<"press A to attack or H to heal"<<endl;
    cin>>playerChoice;

    if(playerChoice == 'a' || playerChoice =='A')
    {
      system("clear");
      enemy.TakeDamage(player.GiveDamage());

      if(enemy.GetHealth()>0)
      {
      cout<< "hahaha... its my turn"<<endl<<endl;
        player.TakeDamage(enemy.GiveDamage());
      }
    }
    else if(playerChoice == 'h' || playerChoice =='H')
    {
          system("clear");
      player.Heal();
    }
    else
    {
          system("clear");
      cout<<"Invalid Input"<<endl;
    }
      
      
  }
    while(player.GetHealth()>0 && enemy.GetHealth() >0);
}

int main() 
{
  gameStory();
  char userInput;
  do
  {
    cout<<"Press S to start the game or any other key to exit!"<<endl;
    cin>>userInput;

    if(userInput =='S'|| userInput=='s')
    {
      Player playerObj;
      Enemy enemyObj;
      gameloop( playerObj,enemyObj);
      
    }
    else
    {
    cout<<"Thanks for playing Mighty Man"<<endl;  
    }
  }
    while(userInput =='S'|| userInput=='s');
}