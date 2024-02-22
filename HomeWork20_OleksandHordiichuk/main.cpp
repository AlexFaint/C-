#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Observer 
{
public:
    virtual void onBridgeEntered(const string& playerName) = 0;
};

class AchievementSystem : public Observer
{
public:
    void onBridgeEntered(const string& playerName) override
    {
        cout << "Achievement: Went to the bridge was obtained for the player " << playerName << endl;
    }
};

class Player
{
private:
    string name;
    vector<Observer*> observers;

public:
    Player(const string& playerName) : name(playerName) {}

    void addObserver(Observer* observer)
    {
        observers.push_back(observer);
    }

    void enterBridge()
    {
        
        notifyObservers();
    }

private:
    void notifyObservers()
    {
        for (Observer* observer : observers) {
            observer->onBridgeEntered(name);
        }
    }
};

int main()
{
    
    Player player("Player1");
   
    AchievementSystem achievementSystem;
   
    player.addObserver(&achievementSystem);
    
    player.enterBridge();

    return 0;
}
