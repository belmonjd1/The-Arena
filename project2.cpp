#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <random>

using namespace std;

/*
 * =====================================================================================
 *
 *        Filename:  project2.cpp
 *
 *        Description:  EECE1080C Spring, 2019 Project 2 Final Submission
 *                      This program is a game called "The Arena", which
 *                      is a text based combat oriented game where the player
 *                      has to fight to earn their freedom. In this program, we
 *                      used three main classes and a lot of switch statements in
 *                      do while loops. It took a lot of effort to polish the
 *                      game as much as we did, so enjoy! *Note* It is very fun
 *                      to try to escape the arena in as few 'days' as possible.
 *
 *        Important Note: If you have questions about the game mechanics and how they
 *                        operate just send an email. There are many moving parts
 *                        that are especially confusing if you are unfamiliar with D&D.
 *
 *        Version:  1.0
 *        Created:  04/26/2019 03:45:06 PM
 *        Revision:  none
 *        Compiler:  MinGW
 *
 *        Author:  Jared Belmont / M12850571 / belmonjd@uc.mail.edu
 *                 Braeden Butler / M12912314 / butlerbd@uc.mail.edu
 *
 *       Organization:  EECE1080C, Spring, 2019
 *
 * =====================================================================================
 */

class Class{
public:
    Class(){                         //this first class keeps track of all the user info, like HP, gold, armor, and preferred weapon type
        HP = 0;
        AC = 0;
        maxHP = 0;
        coinpurse = 0;
        weaptype = "";
        days = 1;
        fights = 0;
    }

    Class(int inHP,int inAC,string inweaptype,string inhandedness,int incoinpurse,int inpotions,int inmaxHP,int indays,int infights){
        HP = inHP;
        AC = inAC;
        maxHP = inmaxHP;
        potions = inpotions;
        coinpurse = incoinpurse;
        weaptype = inweaptype;
        handedness = inhandedness;
        days = indays;
        fights = infights;
    }

    int getHP(){    //Below are the proper set and get functions in order to modify and access this classes data
        return HP;
    }

    int getAC(){
        return AC;
    }

    int getcoinpurse(){
        return coinpurse;
    }

    int getpotions(){
        return potions;
    }

    int getmaxHP(){
        return maxHP;
    }

    string getweaptype(){
        return weaptype;
    }

    string gethandedness(){
        return handedness;
    }

    int getdays(){
        return days;
    }

    int getfights(){
        return fights;
    }

    void setHP(int health){
        HP = health;
    }

    void setcoinpurse(int modmoney){
        coinpurse = modmoney;
    }

    void setpotions(int modpotions){
        potions = modpotions;
    }

    void setdays(int setday){
        days = setday;
    }

    void setfights(int setfight){
        fights = setfight;
    }


private:
    int AC,HP,coinpurse,potions,maxHP,days,fights; //declaration of all class data
    string weaptype,handedness;
};

class weapon{
public:
    weapon(){                           //this class keeps track of all the stats of each weapon
        damhigh = 0;
        damlow = 0;             //stats of each weapon include the max and min damage, their chance to hit and type of weapon
        modifier = 0;
        weaptype = "";
        handedness = "";
        name = "";
    }

    weapon(int indamhigh,int indamlow, int inmodifier,string inweaptype,string inhandedness,int inprice, string inname){
        damhigh = indamhigh;
        damlow = indamlow;
        modifier = inmodifier;
        price = inprice;
        weaptype = inweaptype;
        handedness = inhandedness;
        name = inname;
    }

    int getdamhigh(){       //appropriate set and get functions for weapon class
        return damhigh;
    }

    int getdamlow(){
        return damlow;
    }

    int getmod(){
        return modifier;
    }

    int getprice(){
        return price;
    }

    string getweaptype(){
        return weaptype;
    }

    string gethandedness(){
        return handedness;
    }

    string getname(){
        return name;
    }

private:
    string damtype,weaptype,handedness,name;
    int damhigh,damlow,modifier,price;
};

class enemy{
public:
    enemy(){                             //this class keeps track of all the enemy variables
        EHP = 0;
        EmaxHP = 0;
        EAC = 0;            //data stored here includes the enemies armour, weapon, and health
        Eweapon;
        Evalue = 0;
    }

    enemy(int inEHP, int inEAC, weapon inEweapon,int inEvalue, int inEmaxHP){
        EHP = inEHP;
        EAC = inEAC;
        Eweapon = inEweapon;
        Evalue = inEvalue;
        EmaxHP = inEmaxHP;
    }

    int getEHP(){
        return EHP;
    }                       //appropriate set and get functions for enemy class

    int getEAC(){
        return EAC;
    }

    int getEvalue(){
        return Evalue;
    }

    int getEmaxHP(){
        return EmaxHP;
    }

    void setEHP(int setehp){
        EHP = setehp;
    }

    void setEAC(int seteac){
        EAC = seteac;
    }

    weapon getEweaptype(){
        return Eweapon;
    }
private:
    int EHP,EAC,Evalue, EmaxHP;
    weapon Eweapon;
};

    static Class wizard(50,12,"spell","none",0,1,50,1,0);
    static Class fighter(80,15,"melee","variant",0,0,80,1,0);
    static Class thief(65,14,"ranged","two",0,0,65,1,0);               //these are the 6 playable classes
    static Class barbarian(100,12,"melee","two",0,0,100,1,0);
    static Class paladin(75,16,"melee","one",0,0,75,1,0);
    static Class cleric(75,14,"melee","one",0,0,75,1,0);

    static weapon rustdagger(4,1,0,"melee","one",0,"rusty dagger");
    static weapon rustlongsword(7,2,1,"melee","variant",20,"rusty longsword");      //weapons to be used by the player or the enemies
    static weapon hatchet(7,3,1,"melee","one",25,"hatchet");
    static weapon brokegreatsword(15,4,1,"melee","two",30,"broken greatsword");
    static weapon oldbow(13,4,1,"ranged","two",25,"old bow");
    static weapon icespike(24,9,1,"spell","none",50,"ice spike");
    static weapon ironlongsword(19,6,2,"melee","variant",100,"iron longsword");
    static weapon greatsword(27,8,3,"melee","two",225,"greatsword");
    static weapon steellongsword(26,8,3,"melee","variant",350,"steel longsword");
    static weapon heavycrossbow(26,8,3,"ranged","two",300,"heavy crossbow");
    static weapon mace(21,7,3,"melee","one",300,"mace");
    static weapon battleaxe(24,7,2,"melee","two",250,"battleaxe");
    static weapon lightcrossbow(19,7,2,"ranged","two",200,"light crossbow");
    static weapon ironhandaxe(17,6,2,"melee","one",150,"iron handaxe");
    static weapon fireball(34,12,2,"spell","none",300,"fireball");
    static weapon blast(45,16,3,"spell","none",500,"eldritch blast");
    static weapon dingleberry(62,42,5,"melee","variant",1500,"rudis, sword of legends");
    static weapon dangleberry(74,47,5,"ranged","two",1500,"eyebiter");
    static weapon dongleberry(80,62,5,"spell","none",1500,"magic staff");
    static weapon slime(15,6,2,"melee","two",0,"UNOBTAINABLE");
    static weapon flamingGS(32,15,3,"melee","two",0,"UNOBTAINABLE");
    static weapon bite(22,8,3,"melee","two",0,"UNOBTAINABLE");

    static enemy skeleton(15,10,rustlongsword,15,15);
    static enemy executioner(35,14,battleaxe,25,35);        //all of the enemies that the player can encounter
    static enemy champion(50,15,mace,50,50);
    static enemy archer(25,13,lightcrossbow,25,25);
    static enemy slimeboi(55,8,slime,35,55);
    static enemy mage(20,11,icespike,30,20);
    static enemy cryptking(200,16,flamingGS,200,200);
    static enemy hellhound(40,13,bite,50,40);
    static enemy gladfighter(55,15,ironlongsword,75,55);
    static enemy gladarcher(45,14,lightcrossbow,75,45);
    static enemy gladmage(35,11,fireball,75,35);
    static enemy tiger(40,13,bite,65,40);

    void space(){
        for (int i = 1; i < 100; i++){      //function to clear the terminal by adding several new lines (keeps terminal clean and easy to read
            cout << endl;
        }
    }

int rolldamage(weapon & usedweapon){        //function rolls a 20 sided die then adds the user's current weapons hit modifier to the roll
    int damage = (rand() % ((usedweapon.getdamhigh() + 1) - usedweapon.getdamlow())) + usedweapon.getdamlow();
    return damage;
}

int Erolldamage(enemy & currentenemy){      //same as the roll damage function above but this function is to be used for the enemies
    int damage = (rand() % ((currentenemy.getEweaptype().getdamhigh() + 1) - currentenemy.getEweaptype().getdamlow())) + currentenemy.getEweaptype().getdamlow();
    return damage;
}

void taketurnplayer(weapon & usedweapon,Class & usedclass,enemy & currentenemy){ //includes all that is neccesary for the player to take a turn in combat
    char doaction;
    int hitroll = rand() % 21 + 1;
    int modifier;
    int currentplayerhealth = usedclass.getHP();
    int currentenemyhealth = currentenemy.getEHP();

    cout << "HP: " << usedclass.getHP() << "/" << usedclass.getmaxHP() << endl << endl;
    cout << "What do you want to do?" << endl;
    cout << "Enter 1 to attack with " << usedweapon.getname() << endl;
    cout << "Enter 2 to take healing potion (" << usedclass.getpotions() << " in inventory)" << endl;
    cin >> doaction;

    space();

    switch(doaction){
    case '1':{
        if(usedclass.getweaptype() == usedweapon.getweaptype() && usedclass.gethandedness() == usedweapon.gethandedness()){
            modifier = usedweapon.getmod();
        }
        else{
            modifier = 0;
        }

        int totalroll = hitroll + modifier;

        if (totalroll > currentenemy.getEAC()){
            int damagedealt = rolldamage(usedweapon);
            if(hitroll == 20){
                currentenemyhealth = currentenemyhealth - (damagedealt * 2);
                currentenemy.setEHP(currentenemyhealth);
                cout << "Outstanding move! You have landed a critical blow dealing " << rolldamage(usedweapon) * 2 << " damage." << endl << endl << endl;
            }
            else{
                currentenemyhealth = currentenemyhealth - damagedealt;
                currentenemy.setEHP(currentenemyhealth);
                cout << "You hit the enemy! Dealing " << rolldamage(usedweapon) << " damage." << endl << endl << endl;
            }
        }
        else {
            if(hitroll == 1){
                currentplayerhealth = currentplayerhealth - 5;
                usedclass.setHP(currentplayerhealth);
                cout << "A critical error! The enemy has countered and dealt 5 points of damage!" << endl << endl;
            }
            else{
                cout << "You missed!" << endl << endl << endl;
            }
        }
        break;
    }
    case '2':{
        if (usedclass.getpotions() > 0) {
            cout << "You pull out a red flask and swallow its contents. You heal 20 points of health." << endl;
            usedclass.setHP(usedclass.getHP() + 20);
            if (usedclass.getHP() > usedclass.getmaxHP()) {
                usedclass.setHP(usedclass.getmaxHP());
            }
            usedclass.setpotions(usedclass.getpotions() - 1);
            cout << "You now have " << usedclass.getpotions() << " potions." << endl;
            cout << "You are at " << usedclass.getHP() << " health." <<endl;
            cout << endl << endl;
        }
        else{
            cout << "You have no healing potions!" << endl;
            cout << endl << endl;
        }
        break;
    }
    default:{
        cout << "You blank for a second" << endl;
        cout << endl << endl;
    }
    }
}

void taketurnEnemy(Class & usedclass,enemy & currentenemy){ //includes all that is neccesary for the enemy to take a turn in combat
    int hitroll = rand() % 21 + 1;
    int modifier = 3;
    int totalroll = hitroll + modifier;
    int currentplayerhealth = usedclass.getHP();
    int currentenemyhealth = currentenemy.getEHP();

    if (currentenemy.getEHP() > 0){
        if (totalroll > usedclass.getAC()){
            int damagedealt = Erolldamage(currentenemy);
            if(hitroll == 20){
                currentplayerhealth = currentplayerhealth - (damagedealt * 2);
                usedclass.setHP(currentplayerhealth);
                cout << "The enemy has landed a critical blow dealing " << damagedealt * 2 << " damage." << endl << endl;
            }
            else{
                currentplayerhealth = currentplayerhealth - damagedealt;
                usedclass.setHP(currentplayerhealth);
                cout << "The enemy has hit you! Dealing " << damagedealt << " damage." << endl << endl;
            }
        }
        else {
            if(hitroll == 1){
                currentenemyhealth = currentenemyhealth - 5;
                currentenemy.setEHP(currentenemyhealth);
                cout << "The enemy has slipped up! You have countered and dealt 5 points of damage!" << endl << endl << endl;
            }
            else {
                cout << "The enemy has missed!" << endl << endl << endl;
            }
        }
    }
    else {
        cout << endl << endl;
    }
}

void fight(weapon & usedweapon,Class & usedclass,enemy & currentenemy){ //implements the take turn functions above to facilitate combat
    usedclass.setfights(usedclass.getfights() + 1);
    do{
       taketurnplayer(usedweapon,usedclass,currentenemy);
       taketurnEnemy(usedclass,currentenemy);
    }
    while (usedclass.getHP() > 0 && currentenemy.getEHP() > 0);

    space();

    if (usedclass.getHP() <= 0){
        cout << "Your fight has ended. May your soul know peace." << endl;
        cout << endl;
        cout << "You lived for " << usedclass.getdays() << " days in the arena and "
                "participated " << usedclass.getfights() << " fights."<< endl << endl;;
        exit(1);
    }
    else{
        cout << "The battle is won!" << endl;
        cout << endl;
    }
}

void thepit(weapon & usedweapon,Class & usedclass,enemy & currentenemy){ //where majority of gameplay happens

    bool retire = false;

    cout << R"(88888888888 888                           d8888
    888     888                          d88888
    888     888                         d88P888
    888     88888b.   .d88b.           d88P 888 888d888 .d88b.  88888b.   8888b.
    888     888 "88b d8P  Y8b         d88P  888 888P"  d8P  Y8b 888 "88b     "88b
    888     888  888 88888888        d88P   888 888    88888888 888  888 .d888888
    888     888  888 Y8b.           d8888888888 888    Y8b.     888  888 888  888
    888     888  888  "Y8888       d88P     888 888     "Y8888  888  888 "Y888888)" << endl;
    cout << endl;
    cout << "A game developed by Braeden Butler and Jared Belmont" << endl;

    char playgame;

    do{
        cout << "Are you ready to fight? (y/n)" << endl;
        cin >> playgame;
        switch(playgame){
        case'y':{
            if(playgame == 'y'){
                space();
            }
            break;
        }
        case'n':{
            if(playgame == 'n') {
                space();
                cout << "Wow. You just opened the game to select to not play it. Nice." << endl;
                exit(1);
            }
            break;
        }
        default:{
            cout << "Come on. Dont make this difficult." << endl;
            cout << endl;
        }
        }
    } while(!(playgame == 'y' || playgame == 'n'));

    space();
    cout << "You wake up in dark room, bound and gagged. A rugged man with scars all over"
            " his body approachs you." << endl;
    cout << endl;
    cout << "Im the pit master! My word is law in this arena! Got it, scum?"
            " Youre my gladiator now, and only after you pay me 1000 gold will I "
            "let you leave this arena. No one has ever survived long enough to "
            "be freed!" << endl;
    cout << endl;

    string playername;
    cout << "So...whats your name, scum?" << endl << endl << "Enter name: " << endl;
    cin >> playername;

    space();
    char classchoice;
    cout << "Well, " << playername << ". I hope you know how to fight." << endl << endl;

    do{
    cout << "Enter 1 to play as a wizard" << endl;      //player selects a fighter
    cout << "Enter 2 to play as a fighter" << endl;
    cout << "Enter 3 to play as a thief" << endl;
    cout << "Enter 4 to play as a barbarian" << endl;
    cout << "Enter 5 to play as a paladin" << endl;
    cout << "Enter 6 to play as a cleric" << endl;
    cin >> classchoice;

    space();

    switch(classchoice){
    case '1':{
        usedclass = wizard;
        cout << "While small and frail, the wizard makes up for his lack of"
                " physical prowess through the practice of powerful incantations"
                " and spells." << endl;
        cout << endl;
        cout << "They prefer to weild spells over other weapons." << endl;
        break;
        }
    case '2':{
        usedclass = fighter;
        cout << "The fighter is your stereotypical paragon of strength. They "
                "are able to take some damge while still dealing out decent damage." << endl;
        cout << endl;
        cout << "They prefer to use any type of melee weapon." << endl;
        break;
        }
    case '3':{
        usedclass = thief;
        cout << "The thief prefers to stay on the edge of battle as much as possible, "
                "as they arent really well equipped for an up close battle." << endl;
        cout << endl;
        cout << "They prefer to use ranged weapons. " << endl;
        break;
        }
    case '4':{
        usedclass = barbarian;
        cout << "While lacking brain cells, the barbarian makes up for it in pure "
                "savagery. They often run into battle and swing without any regard." << endl;
        cout << endl;
        cout << "They prefer to use any type of melee weapon." << endl;
        break;
        }
    case '5':{
        usedclass = paladin;
        cout << "Clad in thick armor, the paladin shrugs off most blows that would kill others. "
                "While they do have more armor than most classes, they can only use one handed "
                "weapons." << endl;
        cout << endl;
        cout << "They can only use one handed melee weapons." << endl;
        break;
        }
    case '6':{
        usedclass = cleric;
        cout << "These guys are the opposite of paladins. They dont have as much armor, but they "
                "can heal themselves a bit in the middle of combat!" << endl;
        cout << endl;
        cout << "They can only use one handed melee weapons." << endl;
        break;
        }
    default:{
        cout << "Enter valid class" << endl << endl;
        break;
        }
    }
    } while(!(classchoice == '1' || classchoice == '2' || classchoice == '3' || classchoice == '4' || classchoice == '5' || classchoice == '6'));

    cout << endl;
    cout << "You are tossed into a circular pit filled with sand. There"        //background info displays
            " are blood stains everywhere. The pit master tosses a small, rusty"
            " dagger towards you." << endl << endl;
    cout << "A door on the opposite side of the arena opens up, and out rushes a skeleton towards you!" << endl;
    cout << endl;
    cout << "Fight...or die." << endl;
    cout << endl;

    fight(rustdagger,usedclass,skeleton);
    usedclass.setcoinpurse(skeleton.getEvalue());

    cout << "The crowd roars for your victory! You just won your first fight! "
            "The pit master tosses you a pouch filled with " << skeleton.getEvalue() << " gold coins." << endl;
    cout << endl;
    cout << "Dont get ahead of yourself rookie! Most die within a week! Good luck ever leaving the arena! "
            "Go lick your wounds in the pit! He gestures to the stairs leading downwards." << endl;
    cout << endl;
    cout << "You descend the stairs from the fighting floor down into a "
            "subterranean chamber. Its dark, dank, and smells horrible. "
            "Inside, you see other gladiators. Some are training, others are crying. " << endl;
    cout << endl;
    cout << "From what you can tell, there is the pit masters office, a shop, and a barracks"
            " in this area." << endl;
    cout << endl;
    cout << "First things first: Get a weapon." << endl;

    do{
        cout << endl;
        cout << "HP: " << usedclass.getHP() << "/" << usedclass.getmaxHP() << endl; //display stats
        cout << "Current Weapon: " << usedweapon.getname() << endl;
        cout << "Gold: " << usedclass.getcoinpurse() << endl;
        cout << "Potions: " << usedclass.getpotions() << endl;
        cout << "Day: " << usedclass.getdays() << endl;
        cout << endl;
        cout << "What do you do?" << endl;
        cout << endl;
        cout << "Press 1 to fight" << endl;
        cout << "Press 2 to rest and heal your wounds" << endl;
        cout << "Press 3 to go to the shop" << endl;
        cout << "Press 4 to buy your freedom" << endl;

        char pitchoice;
        cin >> pitchoice;

        switch(pitchoice){      //if player selects this option enemy selection is opened
        case '1':{
            char selectenemy;
            space();
            cout << "You walk into the pit masters office. There he sits at his desk. "
                    "You here for a fight? Here are the papers. Look em over real quick." << endl;
            cout << "What opponent do you wish to challenge?" << endl;
            cout << endl;
            cout << "HP: " << usedclass.getHP() << "/" << usedclass.getmaxHP() << endl;
            cout << "Current Weapon: " << usedweapon.getname() << endl;
            cout << "Gold: " << usedclass.getcoinpurse() << endl;
            cout << "Potions: " << usedclass.getpotions() << endl;
            cout << endl;
            cout << " 1 | skeleton, 15 gold" << endl;
            cout << " 2 | skeletal executioner, 35 gold" << endl;
            cout << " 3 | skeletal champion, 50 gold" << endl;
            cout << " 4 | skeletal archer, 25 gold" << endl;
            cout << " 5 | slime cube, 55 gold" << endl;
            cout << " 6 | undead mage, 20 gold" << endl;
            cout << " 7 | skeleton king, 200 gold" << endl;
            cout << " 8 | hellhound, 40 gold" << endl;
            cout << " 9 | human fighter, 75 gold" << endl;
            cout << " a | human archer, 75 gold" << endl;
            cout << " b | human mage, 75 gold" << endl;
            cout << " c | tiger, 65 gold" << endl;
            cout << "Press 0 to leave" << endl;
            cin >> selectenemy;
            space();

            switch(selectenemy){
            case '1':{
                currentenemy = skeleton;
                currentenemy.setEHP(skeleton.getEmaxHP());
                cout << "You walk up the stairs back into the arena. A door on"
                        " the opposite side opens up, and out rushes a skeleton!" << endl;
                cout << endl;
                fight(usedweapon, usedclass, currentenemy);
                usedclass.setcoinpurse(usedclass.getcoinpurse() + currentenemy.getEvalue());
                cout << "You descend back into the pit. Good fight " << playername << ", heres "
                        "your " << currentenemy.getEvalue() << " gold. Now scram!" << endl;
                break;
            }
            case '2':{
                currentenemy = executioner;
                currentenemy.setEHP(executioner.getEmaxHP());
                cout << "You walk up the stairs back into the arena. A door on"
                        " the opposite side opens up, and out rushes a skeleton!"
                        " This one looks MUCH stronger than the others and is wearing rusty armor." << endl;
                cout << endl;
                fight(usedweapon, usedclass, currentenemy);
                usedclass.setcoinpurse(usedclass.getcoinpurse() + currentenemy.getEvalue());
                cout << "You descend back into the pit. Good fight " << playername << ", heres "
                        "your " << currentenemy.getEvalue() << " gold. Now scram!" << endl;
                break;
            }
            case '3':{
                currentenemy = champion;
                currentenemy.setEHP(champion.getEmaxHP());
                cout << "You walk up the stairs back into the arena. A door on"
                        " the opposite side opens up, and out rushes a skeleton!"
                        " Unlike the others, this skeleton is wearing fine armor "
                        "and is brandishing a very sharp longsword." << endl;
                cout << endl;
                fight(usedweapon, usedclass, currentenemy);
                usedclass.setcoinpurse(usedclass.getcoinpurse() + currentenemy.getEvalue());
                cout << "You descend back into the pit. Good fight " << playername << ", heres "
                        "your " << currentenemy.getEvalue() << " gold. Now scram!" << endl;
                break;
            }
            case '4':{
                currentenemy = archer;
                currentenemy.setEHP(archer.getEmaxHP());
                cout << "You walk up the stairs back into the arena. A door on"
                        " the opposite side opens up, and out rushes a skeleton!"
                        " This one weilds a bow and sports a quiver bristling with arrows." << endl;
                cout << endl;
                fight(usedweapon, usedclass, currentenemy);
                usedclass.setcoinpurse(usedclass.getcoinpurse() + currentenemy.getEvalue());
                cout << "You descend back into the pit. Good fight " << playername << ", heres "
                        "your " << currentenemy.getEvalue() << " gold. Now scram!" << endl;
                break;
            }
            case '5':{
                currentenemy = slimeboi;
                currentenemy.setEHP(slimeboi.getEmaxHP());
                cout << "You walk up the stairs back into the arena. A door on"
                        " the opposite side opens up, and a quivering mass of"
                        " slime slithers out. This thing is huge!" << endl << endl;
                fight(usedweapon, usedclass, currentenemy);
                usedclass.setcoinpurse(usedclass.getcoinpurse() + currentenemy.getEvalue());
                cout << "You descend back into the pit. Good fight " << playername << ", heres "
                        "your " << currentenemy.getEvalue() << " gold. Now scram!" << endl;
                break;
            }
            case '6':{
                currentenemy = mage;
                currentenemy.setEHP(mage.getEmaxHP());
                cout << "You walk up the stairs back into the arena. A door on"
                        " the opposite side opens up. A decrepit zombie like figure"
                        " walks out. He mutters a few words before some arcane symbols "
                        "appear around him!" << endl << endl;
                fight(usedweapon, usedclass, currentenemy);
                usedclass.setcoinpurse(usedclass.getcoinpurse() + currentenemy.getEvalue());
                cout << "You descend back into the pit. Good fight " << playername << ", heres "
                        "your " << currentenemy.getEvalue() << " gold. Now scram!" << endl;
                break;
            }
            case '7':{
                currentenemy = cryptking;
                currentenemy.setEHP(cryptking.getEmaxHP());
                cout << "You walk up the stairs back into the arena. A door on"
                        " the opposite side opens up, and out rushes a skeleton"
                        " with three heads! It stands a good couple feet above you and is "
                        "wielding a giant flaming greatsword!" << endl << endl;
                fight(usedweapon, usedclass, currentenemy);
                usedclass.setcoinpurse(usedclass.getcoinpurse() + currentenemy.getEvalue());
                cout << "You descend back into the pit. " << endl;
                cout << "Jesus. You killed a skeleton king " << playername << ", heres "
                        "your " << currentenemy.getEvalue() << " gold." << endl;
                break;
            }
            case '8':{
                currentenemy = hellhound;
                currentenemy.setEHP(hellhound.getEmaxHP());
                cout << "You walk up the stairs back into the arena. A door on"
                        " the opposite side opens up, and out rushes a flaming"
                        " dog! This thing is at least three times as big as any normal dog!" << endl << endl;
                fight(usedweapon, usedclass, currentenemy);
                usedclass.setcoinpurse(usedclass.getcoinpurse() + currentenemy.getEvalue());
                cout << "You descend back into the pit. Good fight " << playername << ", heres "
                        "your " << currentenemy.getEvalue() << " gold. Now scram!" << endl;
                break;
            }
            case '9':{
                currentenemy = gladfighter;
                currentenemy.setEHP(gladfighter.getEmaxHP());
                cout << "You walk up the stairs back into the arena. A door on"
                        " the opposite side opens up, and out rushes a fellow"
                        " gladiator! This guy looks experienced. Only of you will"
                        " leave you alive!" << endl << endl;
                fight(usedweapon, usedclass, currentenemy);
                usedclass.setcoinpurse(usedclass.getcoinpurse() + currentenemy.getEvalue());
                cout << "You descend back into the pit. Good fight " << playername << ", heres "
                        "your " << currentenemy.getEvalue() << " gold. Now scram!" << endl;
                break;
            }
            case 'a':{
                currentenemy = gladarcher;
                currentenemy.setEHP(gladarcher.getEmaxHP());
                cout << "You walk up the stairs back into the arena. A door on"
                        " the opposite side opens up, and out rushes another human!"
                        " He looks mean. Its either you or him!" << endl << endl;
                fight(usedweapon, usedclass, currentenemy);
                usedclass.setcoinpurse(usedclass.getcoinpurse() + currentenemy.getEvalue());
                cout << "You descend back into the pit. Good fight " << playername << ", heres "
                        "your " << currentenemy.getEvalue() << " gold. Now scram!" << endl;
                break;
            }
            case 'b':{
                currentenemy = gladmage;
                currentenemy.setEHP(gladmage.getEmaxHP());
                cout << "You walk up the stairs back into the arena. A door on"
                        " the opposite side opens up, and out floats an old man clad in robes!"
                        " He mutters a few words and a gout of fire flies from his hands! Watch out!" << endl << endl;
                fight(usedweapon, usedclass, currentenemy);
                usedclass.setcoinpurse(usedclass.getcoinpurse() + currentenemy.getEvalue());
                cout << "You descend back into the pit. Good fight " << playername << ", heres "
                        "your " << currentenemy.getEvalue() << " gold. Now scram!" << endl;
                break;
            }
            case 'c':{
                currentenemy = tiger;
                currentenemy.setEHP(tiger.getEmaxHP());
                cout << "You walk up the stairs back into the arena. A door on"
                        " the opposite side opens up, and out slinks a large tiger!"
                        " It looks at you, licks its lips, and then roars! " << endl << endl;
                fight(usedweapon, usedclass, currentenemy);
                usedclass.setcoinpurse(usedclass.getcoinpurse() + currentenemy.getEvalue());
                cout << "You descend back into the pit. Good fight " << playername << ", heres "
                        "your " << currentenemy.getEvalue() << " gold. Now scram!" << endl;
                break;
            }
            case '0':{
                cout << "You walk back into the main chamber." << endl;
                break;
            }
            default:{
                cout << "If youre gonna stare into space, do it outside!" << endl;
                cout << endl;
                cout << "And with that, you are now back into the main chamber." << endl;
            }
            }
            break;
        }
        case '2':{
            usedclass.setHP(usedclass.getmaxHP());      //player selects to take a rest: a day is added to the day counter and HP is regained
            usedclass.setdays(usedclass.getdays() + 1);

            space();
            cout << "You get a bowl of soup and a piece of bread and enjoy"
                    " a meal by a small fire. After finishing your meal, you"
                    " head to your cot and fall into a deep sleep." << endl;
            cout << endl;
            cout << "You awake the next day, feeling refreshed after a long"
                    " nights rest." << endl;
            cout << endl;
            break;
        }
        case '3':{
            char selectweapon;  //player selects to enter the shop: use gold earned from the fights to purchase weapons of varying quality
            bool leaveshop = false;
            weapon weaponchoice;

            space();
            cout << "You walk into a dingy room lit by a couple candles. A portly dwarf mans"
                    " the counter. He looks up and at you expectantly. The room is filled "
                    "with different types of weapons, some better than others. "
                    "You assume this is a weapons shop. " << endl;
            cout << endl;
            cout << "A wooden sign hangs over the counter showing the prices of items." << endl;
            cout << endl;
            cout << "You should probably find a weapon youre familiar with." << endl;
            cout << endl;

            do{
                cout << endl;
                cout << "Gold: " << usedclass.getcoinpurse() << endl;
                cout << "Current Weapon: " << usedweapon.getname() << endl;
                cout << "Potions: " << usedclass.getpotions() << endl;
                cout << endl;
                cout << " 1 | rusty dagger, free" << endl;
                cout << " 2 | rusty longsword, 20 gold" << endl;
                cout << " 3 | hatchet, 25 gold" << endl;
                cout << " 4 | broken greatsword, 30 gold" << endl;
                cout << " 5 | old bow, 25 gold" << endl;
                cout << " 6 | spell tome: icespike, 50 gold" << endl;
                cout << " 7 | iron longsword, 100 gold" << endl;
                cout << " 8 | greatsword, 225 gold" << endl;
                cout << " 9 | steel longsword, 350 gold" << endl;
                cout << " a | heavy crossbow, 300 gold" << endl;
                cout << " b | mace, 300 gold" << endl;
                cout << " c | battleaxe, 250 gold" << endl;
                cout << " d | light crossbow, 200 gold" << endl;
                cout << " e | iron handaxe, 150 gold" << endl;
                cout << " f | spell tome: fireball, 300 gold" << endl;
                cout << " g | spell tome: eldritch blast, 500 gold" << endl;
                cout << " h | rudis, sword of legends, 1500 gold" << endl;
                cout << " i | eyebiter, 1500 gold" << endl;
                cout << " j | magic staff, 1500 gold" << endl;
                cout << " k | healing potion, 15 gold" << endl;
                cout << "Press 0 to leave the shop" << endl;
                cin >> selectweapon;
                space();

                switch(selectweapon){
                    case '1':{
                        weaponchoice = rustdagger;
                        if (usedclass.getcoinpurse() >= weaponchoice.getprice()) {
                            usedweapon = rustdagger;
                            usedclass.setcoinpurse(usedclass.getcoinpurse() - weaponchoice.getprice());
                            cout << "Heres your weapon. Now piss off!" << endl;
                        }
                        else {
                            cout << "Yeah? You aint havin nothin unless ya pay for it!" << endl;
                        }
                        break;
                    }
                    case '2':{
                        weaponchoice = rustlongsword;
                        if (usedclass.getcoinpurse() >= weaponchoice.getprice()) {
                            usedweapon = rustlongsword;
                            usedclass.setcoinpurse(usedclass.getcoinpurse() - weaponchoice.getprice());
                            cout << "Heres your weapon. Now piss off!" << endl;
                        }
                        else {
                            cout << "Yeah? You aint havin nothin unless ya pay for it!" << endl;
                        }
                        break;
                    }
                    case '3':{
                        weaponchoice = hatchet;
                        if (usedclass.getcoinpurse() >= weaponchoice.getprice()) {
                            usedweapon = hatchet;
                            usedclass.setcoinpurse(usedclass.getcoinpurse() - weaponchoice.getprice());
                            cout << "Heres your weapon. Now piss off!" << endl;
                        }
                        else {
                            cout << "Yeah? You aint havin nothin unless ya pay for it!" << endl;
                        }
                        break;
                    }
                    case '4':{
                        weaponchoice = brokegreatsword;
                        if (usedclass.getcoinpurse() >= weaponchoice.getprice()) {
                            usedweapon = brokegreatsword;
                            usedclass.setcoinpurse(usedclass.getcoinpurse() - weaponchoice.getprice());
                            cout << "Heres your weapon. Now piss off!" << endl;
                        }
                        else {
                            cout << "Yeah? You aint havin nothin unless ya pay for it!" << endl;
                        }
                        break;
                    }
                    case '5':{
                        weaponchoice = oldbow;
                        if (usedclass.getcoinpurse() >= weaponchoice.getprice()) {
                            usedweapon = oldbow;
                            usedclass.setcoinpurse(usedclass.getcoinpurse() - weaponchoice.getprice());
                            cout << "Heres your weapon. Now piss off!" << endl;
                        }
                        else {
                            cout << "Yeah? You aint havin nothin unless ya pay for it!" << endl;
                        }
                        break;
                    }
                    case '6':{
                        weaponchoice = icespike;
                        if (usedclass.getcoinpurse() >= weaponchoice.getprice()) {
                            usedweapon = icespike;
                            usedclass.setcoinpurse(usedclass.getcoinpurse() - weaponchoice.getprice());
                            cout << "Heres your weapon. Now piss off!" << endl;
                        }
                        else {
                            cout << "Yeah? You aint havin nothin unless ya pay for it!" << endl;
                        }
                        break;
                    }
                    case '7':{
                        weaponchoice = ironlongsword;
                        if (usedclass.getcoinpurse() >= weaponchoice.getprice()) {
                            usedweapon = ironlongsword;
                            usedclass.setcoinpurse(usedclass.getcoinpurse() - weaponchoice.getprice());
                            cout << "Heres your weapon. Now piss off!" << endl;
                        }
                        else {
                            cout << "Yeah? You aint havin nothin unless ya pay for it!" << endl;
                        }
                        break;
                    }
                    case '8':{
                        weaponchoice = greatsword;
                        if (usedclass.getcoinpurse() >= weaponchoice.getprice()) {
                            usedweapon = greatsword;
                            usedclass.setcoinpurse(usedclass.getcoinpurse() - weaponchoice.getprice());
                            cout << "Heres your weapon. Now piss off!" << endl;
                        }
                        else {
                            cout << "Yeah? You aint havin nothin unless ya pay for it!" << endl;
                        }
                        break;
                    }
                    case '9':{
                        weaponchoice = steellongsword;
                        if (usedclass.getcoinpurse() >= weaponchoice.getprice()) {
                            usedweapon = steellongsword;
                            usedclass.setcoinpurse(usedclass.getcoinpurse() - weaponchoice.getprice());
                            cout << "Heres your weapon. Now piss off!" << endl;
                        }
                        else {
                            cout << "Yeah? You aint havin nothin unless ya pay for it!" << endl;
                        }
                        break;
                    }
                    case 'a':{
                        weaponchoice = heavycrossbow;
                        if (usedclass.getcoinpurse() >= weaponchoice.getprice()) {
                            usedweapon = heavycrossbow;
                            usedclass.setcoinpurse(usedclass.getcoinpurse() - weaponchoice.getprice());
                            cout << "Heres your weapon. Now piss off!" << endl;
                        }
                        else {
                            cout << "Yeah? You aint havin nothin unless ya pay for it!" << endl;
                        }
                        break;
                    }
                    case 'b':{
                        weaponchoice = mace;
                        if (usedclass.getcoinpurse() >= weaponchoice.getprice()) {
                            usedweapon = mace;
                            usedclass.setcoinpurse(usedclass.getcoinpurse() - weaponchoice.getprice());
                            cout << "Heres your weapon. Now piss off!" << endl;
                        }
                        else {
                            cout << "Yeah? You aint havin nothin unless ya pay for it!" << endl;
                        }
                        break;
                    }
                    case 'c':{
                        weaponchoice = battleaxe;
                        if (usedclass.getcoinpurse() >= weaponchoice.getprice()) {
                            usedweapon = battleaxe;
                            usedclass.setcoinpurse(usedclass.getcoinpurse() - weaponchoice.getprice());
                            cout << "Heres your weapon. Now piss off!" << endl;
                        }
                        else {
                            cout << "Yeah? You aint havin nothin unless ya pay for it!" << endl;
                        }
                        break;
                    }
                    case 'd':{
                        weaponchoice = lightcrossbow;
                        if (usedclass.getcoinpurse() >= weaponchoice.getprice()) {
                            usedweapon = lightcrossbow;
                            usedclass.setcoinpurse(usedclass.getcoinpurse() - weaponchoice.getprice());
                            cout << "Heres your weapon. Now piss off!" << endl;
                        }
                        else {
                            cout << "Yeah? You aint havin nothin unless ya pay for it!" << endl;
                        }
                        break;
                    }
                    case 'e':{
                        weaponchoice = ironhandaxe;
                        if (usedclass.getcoinpurse() >= weaponchoice.getprice()) {
                            usedweapon = ironhandaxe;
                            usedclass.setcoinpurse(usedclass.getcoinpurse() - weaponchoice.getprice());
                            cout << "Heres your weapon. Now piss off!" << endl;
                        }
                        else {
                            cout << "Yeah? You aint havin nothin unless ya pay for it!" << endl;
                        }
                        break;
                    }
                    case 'f':{
                        weaponchoice = fireball;
                        if (usedclass.getcoinpurse() >= weaponchoice.getprice()) {
                            usedweapon = fireball;
                            usedclass.setcoinpurse(usedclass.getcoinpurse() - weaponchoice.getprice());
                            cout << "Heres your weapon. Now piss off!" << endl;
                        }
                        else {
                            cout << "Yeah? You aint havin nothin unless ya pay for it!" << endl;
                        }
                        break;
                    }
                    case 'g':{
                        weaponchoice = blast;
                        if (usedclass.getcoinpurse() >= weaponchoice.getprice()) {
                            usedweapon = blast;
                            usedclass.setcoinpurse(usedclass.getcoinpurse() - weaponchoice.getprice());
                            cout << "Heres your weapon. Now piss off!" << endl;
                        }
                        else {
                            cout << "Yeah? You aint havin nothin unless ya pay for it!" << endl;
                        }
                        break;
                    }
                    case 'h':{
                        weaponchoice = dingleberry;
                        if (usedclass.getcoinpurse() >= weaponchoice.getprice()) {
                            usedweapon = dingleberry;
                            usedclass.setcoinpurse(usedclass.getcoinpurse() - weaponchoice.getprice());
                            cout << "Heres your weapon. Now piss off!" << endl;
                        }
                        else {
                            cout << "Yeah? You aint havin nothin unless ya pay for it!" << endl;
                        }
                        break;
                    }
                    case 'i':{
                        weaponchoice = dangleberry;
                        if (usedclass.getcoinpurse() >= weaponchoice.getprice()) {
                            usedweapon = dangleberry;
                            usedclass.setcoinpurse(usedclass.getcoinpurse() - weaponchoice.getprice());
                            cout << "Heres your weapon. Now piss off!" << endl;
                        }
                        else {
                            cout << "Yeah? You aint havin nothin unless ya pay for it!" << endl;
                        }
                        break;
                    }
                    case 'j':{
                        weaponchoice = dongleberry;
                        if (usedclass.getcoinpurse() >= weaponchoice.getprice()) {
                            usedweapon = dongleberry;
                            usedclass.setcoinpurse(usedclass.getcoinpurse() - weaponchoice.getprice());
                            cout << "Heres your weapon. Now piss off!" << endl;
                        }
                        else {
                            cout << "Yeah? You aint havin nothin unless ya pay for it!" << endl;
                        }
                        break;
                    }
                    case 'k':{
                        if (usedclass.getcoinpurse() >= 15) {
                            usedclass.setcoinpurse(usedclass.getcoinpurse() - 15);
                            usedclass.setpotions(usedclass.getpotions() + 1);
                            cout << "Heres your potion, Now piss off!" << endl;
                        }
                        else {
                            cout << "Yeah? You aint havin nothin unless ya pay for it!" << endl;
                        }
                        break;
                    }
                    case '0':{
                        cout << "You walk out of the shop back into the main area." << endl;
                        leaveshop = true;
                        break;
                    }
                    default:{
                        cout << "Stop starin at me wall! Buy somethin or get the fuck outta my shop!" << endl;
                    }
                }
        } while(leaveshop == false);
            break;
        }
        case '4':{      //if player finally saves enough money to retire from the fighting pits
            space();
            if (usedclass.getcoinpurse() >= 1000){
                cout << "I cant believe it! You actually saved enough money to retire!"
                        " Youre free to go!" << endl;
                cout << endl;
                cout << "And after paying 1000 gold pieces, you are now a free man." << endl;
                usedclass.setcoinpurse(usedclass.getcoinpurse()-1000);
                retire = true;
                goto leavearena;
            }
            else{
                cout << "You dont have the money required to buy your freedom! Get back out there dog!" << endl;
                cout << endl;
                cout << "And with that, you slink back into the main entrance." << endl;
            }
            break;
        }
        default:{
            cout << "You stand there for a bit, unsure of what your next move is." << endl;
            cout << endl << endl;
            break;
        }
}
} while (retire != true);       //begin the closing screen: message displayed is based on wealth accumulated
    leavearena:
    if (usedclass.getcoinpurse() <= 50){
        cout << "After leaving the arena, you contemplate on how you got there and where you will go now"
                ". While you spent most of your gold buying your freedom, at least you can say you escaped with your life"
                ". " << endl;
    }
    if (usedclass.getcoinpurse() > 50 && usedclass.getcoinpurse() <= 500){
        cout << "You walk out of the arena with your head held high! Youve bought your freedom and have a pretty"
                " penny to show for it afterwards. With the fair amount of money you have, you could buy a house"
                " and settle down for a while. Maybe even start a family." << endl;
    }
    if (usedclass.getcoinpurse() > 500 && usedclass.getcoinpurse() <= 1500){
        cout << "Your long and profitable career in the arena have gotten you far. Now you can comfortably retire and"
                " buy a house somewhere in the countryside. You have traded the squalor of the pits for the luxury of"
                " the high life. Just try not to think of all those people you killed to get here." << endl;
    }
    if (usedclass.getcoinpurse() > 1500 && usedclass.getcoinpurse() <= 5000){
        cout << "With the massive wealth youve built up, you managed to buy the arena from the pit master himself. "
                "Now, you are the one in charge. You decide who lives and dies in the arena!" << endl;
    }
    if (usedclass.getcoinpurse() > 5000) {
        cout << "Once you leave the arena, you take a look around and see no one. There isnt a single soul in sight. "
                "You wonder where everyone went when an old man walks up to you and says " << endl << endl;
        cout << "It was you! You killed them all! They had to keep throwing competitors your way because you"
                " killed them too fast! Now look where all this bloodshed has gotten you! I hope it was worth it!" << endl << endl;
        cout << "You fall to your knees. The world you once knew is now gone, lost forever." << endl;
    }
    cout << endl << endl;
    cout << "You lived for " << usedclass.getdays() << " days in the arena and won " << usedclass.getfights() << " fights." << endl;
}

int main(){
    srand(time(NULL));
    weapon usedweapon;
    Class usedclass;
    enemy currentenemy;

    thepit(usedweapon, usedclass, currentenemy);

    return 0;
}
