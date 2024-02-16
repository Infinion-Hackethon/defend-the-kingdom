#ifndef KINGDOM_H
#define KINGDOM_H

#include "pugixml.hpp"
#include <string>
#include <vector>

class Soldier
{
public:
    int intClassID;
    std::string name;
    std::string active;
    int skillRef;
};

class Clan
{
public:
    int intClassID;
    std::string name;
    int maxCloningPower;
    char cloningVar;
    int baseDeployCost;
    std::vector<Soldier> soldiers;
};

class Skill
{
public:
    int intClassID;
    int strength;
};

class Kingdom
{
public:
    std::string name;
    std::vector<Clan> clans;
    std::vector<Skill> skills;

    Kingdom(const std::string &filename)
    {
        pugi::xml_document doc;
        if (!doc.load_file(filename.c_str()))
        {
            throw std::runtime_error("Failed to load XML file");
        }

        // Parse XML and populate Kingdom object
        pugi::xml_node kingdomNode = doc.child("Kingdom");
        if (kingdomNode)
        {
            name = kingdomNode.child_value("Name");

            // Parse Clans
            for (pugi::xml_node clanNode = kingdomNode.child("Clan"); clanNode; clanNode = clanNode.next_sibling("Clan"))
            {
                Clan clan;
                clan.intClassID = clanNode.child("Int_Class_ID").text().as_int();
                clan.name = clanNode.child_value("Name");
                clan.maxCloningPower = clanNode.child("MaxCloningPower").text().as_int();
                clan.cloningVar = clanNode.child_value("CloningVar")[0];
                clan.baseDeployCost = clanNode.child("BaseDeployCost").text().as_int();

                // Parse Soldiers
                for (pugi::xml_node soldierNode = clanNode.child("Soldier"); soldierNode; soldierNode = soldierNode.next_sibling("Soldier"))
                {
                    Soldier soldier;
                    soldier.intClassID = soldierNode.child("Int_Class_ID").text().as_int();
                    soldier.name = soldierNode.child_value("Name");
                    soldier.active = soldierNode.child_value("Active");
                    soldier.skillRef = soldierNode.child("SkillRef").text().as_int();
                    clan.soldiers.push_back(soldier);
                }

                clans.push_back(clan);
            }


            // Function to calculate maximum strength of war with provided budget
            int getMaxStrengthForBudget(const Kingdom& kingdom, int budget) {
                int maxStrength = 0;
                for (const auto& clan : kingdom.clans) {
                    int numWarriors = std::min(budget / clan.baseDeployCost, clan.maxCloningPower);
                    for (const auto& warrior : clan.warriors) {
                        maxStrength += std::min(numWarriors, 1) * warrior.skill; // Only consider one clone
                    }
                }
                return maxStrength;
            }

            // Parse Skills
            for (pugi::xml_node skillNode = kingdomNode.child("Skill"); skillNode; skillNode = skillNode.next_sibling("Skill"))
            {
                Skill skill;
                skill.intClassID = skillNode.child("Int_Class_ID").text().as_int();
                skill.strength = skillNode.child("Strength").text().as_int();
                skills.push_back(skill);
            }
        }
    }
};

#endif // KINGDOM_H
