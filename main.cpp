#include <iostream>
#include "Kingdom.h"
using namespace std;

void printSoldier(const Soldier &soldier)
{
    cout << "Int_Class_ID: " << soldier.intClassID << endl;
    cout << "Name: " << soldier.name << endl;
    cout << "Active: " << soldier.active << endl;
    cout << "SkillRef: " << soldier.skillRef << endl;
}

void printClan(const Clan &clan)
{
    cout << "Int_Class_ID: " << clan.intClassID << endl;
    cout << "Name: " << clan.name << endl;
    cout << "MaxCloningPower: " << clan.maxCloningPower << endl;
    cout << "CloningVar: " << clan.cloningVar << endl;
    cout << "BaseDeployCost: " << clan.baseDeployCost << endl;
    cout << "Soldiers: " << endl;
    for (const auto &soldier : clan.soldiers)
    {
        printSoldier(soldier);
    }
}


void printKingdom(const Kingdom &kingdom)
{
    cout << "Name: " << kingdom.name << endl;

    cout << "Clans: " << endl;
    for (const auto &clan : kingdom.clans)
    {
        printClan(clan);
    }

    cout << "Skills: " << endl;
    for (const auto &skill : kingdom.skills)
    {
        cout << "Int_Class_ID: " << skill.first << " ";
        cout << "Strength: " << skill.second << endl;
    }
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cout << "XML file path not provided.\n";
        exit(1);
    }

    string filePath = argv[1];

    try
    {
        Kingdom kingdom(filePath);
        // Now you can use the 'kingdom' object as needed
        printKingdom(kingdom);
    }
    catch (const exception &e)
    {
        cerr << "Error: " << e.what() << endl;
    }

    cout << "Press Enter to continue...";
    cin.ignore();

    return 0;
}