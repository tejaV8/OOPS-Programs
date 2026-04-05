#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

ofstream logFile; // Global log file

/* ================= DRIVER ================= */
class Driver
{
public:
    string name;
    int skill;
    int points;

    Driver() {}
    Driver(string n, int s)
    {
        name = n;
        skill = s;
        points = 0;
    }
};

/* ================= TEAM ================= */
class Team
{
public:
    string name, principal;
    Driver d1, d2;
    int carPerf;
    int budget;
    int constructorPts;

    Team() {}

    Team(string n, string p, Driver a, Driver b, int perf, int bud)
    {
        name = n;
        principal = p;
        d1 = a;
        d2 = b;
        carPerf = perf;
        budget = bud;
        constructorPts = 0;
    }
};

vector<Team> teams(11);

/* ================= INIT ================= */
void initTeams()
{
    teams[0] = Team("Red Bull", "Horner", Driver("Verstappen", 96), Driver("Hadjar", 86), 80, 100);
    teams[1] = Team("Ferrari", "Vasseur", Driver("Leclerc", 94), Driver("Hamilton", 93), 79, 100);
    teams[2] = Team("Mercedes", "Wolff", Driver("Russell", 92), Driver("Antonelli", 87), 79, 100);
    teams[3] = Team("McLaren", "Stella", Driver("Norris", 93), Driver("Piastri", 91), 78, 100);
    teams[4] = Team("Aston Martin", "Krack", Driver("Alonso", 92), Driver("Stroll", 82), 77, 100);
    teams[5] = Team("Alpine", "Famin", Driver("Gasly", 88), Driver("Colapinto", 84), 76, 100);
    teams[6] = Team("Williams", "Vowles", Driver("Sainz", 91), Driver("Albon", 88), 76, 100);
    teams[7] = Team("Audi", "Seidl", Driver("Hulkenberg", 86), Driver("Bortoleto", 84), 75, 100);
    teams[8] = Team("Haas", "Komatsu", Driver("Ocon", 87), Driver("Bearman", 86), 74, 100);
    teams[9] = Team("RB", "Mekies", Driver("Lawson", 87), Driver("Lindblad", 83), 75, 100);
    teams[10] = Team("Cadillac", "Andretti", Driver("Perez", 90), Driver("Bottas", 87), 74, 100);
}

/* ================= ENTRY ================= */
struct Entry
{
    int team;
    int driver;
    int score;
};

int pts[10] = {25, 18, 15, 12, 10, 8, 6, 4, 2, 1};

/* ================= RACE ================= */
void simulateRace(int raceNo)
{

    cout << "\n===== RACE " << raceNo << " =====\n";
    logFile << "\n===== RACE " << raceNo << " =====\n";

    vector<Entry> grid;

    for (int i = 0; i < teams.size(); i++)
    {

        int score1 = teams[i].d1.skill + teams[i].carPerf + (rand() % 11 - 5);
        if (rand() % 100 < 5)
            score1 = -1000;

        int score2 = teams[i].d2.skill + teams[i].carPerf + (rand() % 11 - 5);
        if (rand() % 100 < 5)
            score2 = -1000;

        grid.push_back({i, 1, score1});
        grid.push_back({i, 2, score2});
    }

    sort(grid.begin(), grid.end(),
         [](Entry &a, Entry &b)
         { return a.score > b.score; });

    cout << "\nTop 10 Finishers:\n";
    logFile << "\nTop 10 Finishers:\n";

    for (int i = 0; i < 10; i++)
    {

        if (grid[i].score < 0)
        {
            cout << i + 1 << ". DNF\n";
            logFile << i + 1 << ". DNF\n";
            continue;
        }

        Team &t = teams[grid[i].team];
        Driver *d = (grid[i].driver == 1 ? &t.d1 : &t.d2);

        d->points += pts[i];
        t.constructorPts += pts[i];

        cout << i + 1 << ". " << d->name << " (" << t.name << ")\n";
        logFile << i + 1 << ". " << d->name << " (" << t.name << ")\n";
    }
}

/* ================= STANDINGS ================= */
void showStandings()
{

    cout << "\n=== CONSTRUCTORS ===\n";
    logFile << "\n=== CONSTRUCTORS ===\n";

    for (auto &t : teams)
    {
        cout << t.name << " - " << t.constructorPts << " pts | Budget: " << t.budget << "\n";
        logFile << t.name << " - " << t.constructorPts << " pts | Budget: " << t.budget << "\n";
    }
}

/* ================= MAIN ================= */
int main()
{

    srand(time(0));

    logFile.open("season_log.txt");

    initTeams();

    cout << "Choose Your Team:\n";
    for (int i = 0; i < teams.size(); i++)
        cout << i << " - " << teams[i].name << "\n";

    int player;
    cin >> player;

    int races = 8;

    for (int r = 1; r <= races; r++)
    {
        simulateRace(r);
        showStandings();
    }

    string bestDriver = "";
    int maxDriver = -1;
    string bestTeam = "";
    int maxTeam = -1;

    for (auto &t : teams)
    {
        if (t.d1.points > maxDriver)
        {
            maxDriver = t.d1.points;
            bestDriver = t.d1.name;
        }
        if (t.d2.points > maxDriver)
        {
            maxDriver = t.d2.points;
            bestDriver = t.d2.name;
        }
        if (t.constructorPts > maxTeam)
        {
            maxTeam = t.constructorPts;
            bestTeam = t.name;
        }
    }

    cout << "\nDRIVER CHAMPION: " << bestDriver << "\n";
    cout << "CONSTRUCTOR CHAMPION: " << bestTeam << "\n";

    logFile << "\nDRIVER CHAMPION: " << bestDriver << "\n";
    logFile << "CONSTRUCTOR CHAMPION: " << bestTeam << "\n";

    logFile.close();

    cout << "\nAll logs saved to season_log.txt\n";

    return 0;
}