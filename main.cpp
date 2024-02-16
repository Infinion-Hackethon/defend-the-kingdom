#include <iostream>
#include "Kingdom.h"
using namespace std;

void printSoldier(const Soldier &soldier)
{
    std::cout << "    Int_Class_ID: " << soldier.intClassID << std::endl;
    std::cout << "    Name: " << soldier.name << std::endl;
    std::cout << "    Active: " << soldier.active << std::endl;
    std::cout << "    SkillRef: " << soldier.skillRef << std::endl;
}

void printClan(const Clan &clan)
{
    std::cout << "  Int_Class_ID: " << clan.intClassID << std::endl;
    std::cout << "  Name: " << clan.name << std::endl;
    std::cout << "  MaxCloningPower: " << clan.maxCloningPower << std::endl;
    std::cout << "  CloningVar: " << clan.cloningVar << std::endl;
    std::cout << "  BaseDeployCost: " << clan.baseDeployCost << std::endl;
    std::cout << "  Soldiers: " << std::endl;
    for (const auto &soldier : clan.soldiers)
    {
        printSoldier(soldier);
    }
}

void printSkill(const Skill &skill)
{
    std::cout << "  Int_Class_ID: " << skill.intClassID << std::endl;
    std::cout << "  Strength: " << skill.strength << std::endl;
}

void printKingdom(const Kingdom &kingdom)
{
    std::cout << "Name: " << kingdom.name << std::endl;

    std::cout << "Clans: " << std::endl;
    for (const auto &clan : kingdom.clans)
    {
        printClan(clan);
    }

    std::cout << "Skills: " << std::endl;
    for (const auto &skill : kingdom.skills)
    {
        printSkill(skill);
    }
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << "XML file path not provided.\n";
        exit(1);
    }

    string filePath = argv[1];

    try
    {
        Kingdom kingdom(filePath);
        // Now you can use the 'kingdom' object as needed
        printKingdom(kingdom);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    cout << "Press Enter to continue...";
    cin.ignore();

    return 0;
}
