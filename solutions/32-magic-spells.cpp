/*
==============================================================================
Author: Michael Gene Brockus (Dreamer)
Email: michaelbrockus@gmail.com
Organization: Fossil Logic
Description: 
    This file is part of the Fossil Logic project, where innovation meets
    excellence in software development. Michael Gene Brockus, also known as
    "Dreamer," is a dedicated contributor to this project. For any inquiries,
    feel free to contact Michael at michaelbrockus@gmail.com.
==============================================================================
*/
#include <iostream>
#include <vector>
#include <string>

class Spell { 
    private:
        std::string scrollName;
    public:
        Spell(): scrollName("") { }
        Spell(std::string name): scrollName(name) { }
        virtual ~Spell() { }
        std::string revealScrollName() {
            return scrollName;
        }
};

class Fireball : public Spell { 
    private: int power;
    public:
        Fireball(int power): power(power) { }
        void revealFirepower(){
            std::cout << "Fireball: " << power << std::endl;
        }
};

class Frostbite : public Spell {
    private: int power;
    public:
        Frostbite(int power): power(power) { }
        void revealFrostpower(){
            std::cout << "Frostbite: " << power << std::endl;
        }
};

class Thunderstorm : public Spell { 
    private: int power;
    public:
        Thunderstorm(int power): power(power) { }
        void revealThunderpower() {
            std::cout << "Thunderstorm: " << power << std::endl;
        }
};

class Waterbolt : public Spell { 
    private: int power;
    public:
        Waterbolt(int power): power(power) { }
        void revealWaterpower(){
            std::cout << "Waterbolt: " << power << std::endl;
        }
};

class SpellJournal {
    public:
        static std::string journal;
        static std::string read() {
            return journal;
        }
}; 
std::string SpellJournal::journal = "";

void counterspell(Spell *spell) {
    if (Fireball *fb = dynamic_cast<Fireball *>(spell)) {
        fb->revealFirepower();
        return;
    } else if (Thunderstorm *th = dynamic_cast<Thunderstorm *>(spell)) {
        th->revealThunderpower();
        return;
    } else if (Waterbolt *wt = dynamic_cast<Waterbolt *>(spell)) {
        wt->revealWaterpower();
        return;
    } else if (Frostbite *fbt = dynamic_cast<Frostbite *>(spell)) {
        fbt->revealFrostpower();
        return;
    }

    std::string spellName = spell->revealScrollName();
    std::string journal = SpellJournal::read(); // Read the journal

    int maxCommonSubsequence = 0;
    int spellLength = spellName.length();
    int journalLength = journal.length();

    // Dynamic programming table to store the length of LCS
    std::vector<std::vector<int>> dp(spellLength + 1, std::vector<int>(journalLength + 1, 0));

    // Fill the dp table
    for (int i = 1; i <= spellLength; ++i) {
        for (int j = 1; j <= journalLength; ++j) {
            if (spellName[i - 1] == journal[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    maxCommonSubsequence = dp[spellLength][journalLength];

    std::cout << maxCommonSubsequence << std::endl;
}

class Wizard {
    public:
        Spell *cast() {
            Spell *spell;
            std::string s; std::cin >> s;
            int power; std::cin >> power;
            if(s == "fire") {
                spell = new Fireball(power);
            }
            else if(s == "frost") {
                spell = new Frostbite(power);
            }
            else if(s == "water") {
                spell = new Waterbolt(power);
            }
            else if(s == "thunder") {
                spell = new Thunderstorm(power);
            } 
            else {
                spell = new Spell(s);
                std::cin >> SpellJournal::journal;
            }
            return spell;
        }
};

int main() {
    int T;
    std::cin >> T;
    Wizard Arawn;
    while(T--) {
        Spell *spell = Arawn.cast();
        counterspell(spell);
    }
    return 0;
} // end of main
