#include <iostream>
#include <string>
using namespace std;

class Drum
{
public:
    void StartRotating() 
    {
        cout << "Drum starts rotating\n";
    }
    void StopRotating() 
    {
        cout << "Drum stops rotating\n";
    }
};

class Washing
{
public:
    void Wash()
    {
        cout << "Washing clothes\n";
    }
};

class Drying
{
public:
    void Dry()
    {
        cout << "Drying clothes\n";
    }
};

class Wringing
{
public:
    void Wring()
    {
        cout << "Wringing clothes\n";
    }
};

class WashingMachine
{
    Drum dr_rot;
    Washing wash_clt;
    Drying dry_clt;
    Wringing wring_clt;

public:
    WashingMachine(Drum dr, Washing wa, Drying dry, Wringing wr)
    {
        dr_rot = dr;
        wash_clt = wa;
        dry_clt = dry;
        wring_clt = wr;
    }

    void StartWashing()
    {
        dr_rot.StartRotating();
        wash_clt.Wash();
        dry_clt.Dry();
        wring_clt.Wring();
    }

    void StopWashing() 
    {
        dr_rot.StopRotating();
    }
};

class User
{
public:
    void UseWashingMachine(WashingMachine facade)
    {
        facade.StartWashing();
        facade.StopWashing();
    }
};

int main()
{
    User user;
    Drum drum_rotating;
    Washing wash_clothes;
    Drying dry_clothes;
    Wringing wring_clothes;

    WashingMachine washingMachine(drum_rotating, wash_clothes, dry_clothes, wring_clothes);

    user.UseWashingMachine(washingMachine);
}


