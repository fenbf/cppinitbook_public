// ex 12 6 json like.cpp
// example for "C++ Initialization Story"
// https://leanpub.com/cppinitbook
// by Bartlomiej Filipek
// 2022
// MIT License

#include <iostream>
#include <string>
#include <vector>

struct Date { int year; int month; int day; };
struct Team { std::string name; std::string where; };
struct GameSession {
    std::string game;
    std::string localization;
    std::vector<Team> teams;
    Date date;
};

int main() {
    GameSession test {
        .game = "Pong",
        .localization = "Pacific Ocean",
        .teams  = {
    	    Team {
    	        .name = "Johny Test",
    	        .where = "Arctica",
    	    },
    	    Team {
    	        .name = "Jane Doe",
    	        .where = "Antarctic",
    	    },
        },
        .date = {
            .year = 2022,
            .month = 10,
            .day = 6
        },
    };
}

