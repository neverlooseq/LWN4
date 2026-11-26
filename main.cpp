#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <iterator>
#include <utility>

using namespace std;

class Credit {
    string name;
    double price;
    string type;
    float percent;

public:
    Credit() {
        name = "";
        price = 0;
        type = "";
        percent = 0;
    }

    Credit(const Credit &other) {
        this->name = other.name;
        this->price = other.price;
        this->type = other.type;
        this->percent = other.percent;
    }

    Credit(Credit &&other) {
        this->name = move(other.name);
        this->price = other.price;
        this->type = move(other.type);
        this->percent = other.percent;
    }

    Credit &operator=(Credit &&other) {
        if (this != &other) {
            this->name = move(other.name);
            this->price = other.price;
            this->type = move(other.type);
            this->percent = other.percent;
        }
        return *this;
    }

    Credit &operator=(const Credit &other) {
        if (this != &other) {
            this->name = other.name;
            this->price = other.price;
            this->type = other.type;
            this->percent = other.percent;
        }
        return *this;
    }

    Credit(string name, double price, string type, float percent) {
        this->name = name;
        this->price = price;
        this->type = type;
        this->percent = percent;
    }

    friend ostream &operator<<(ostream &out, const Credit &other) {
        out << other.name << " ";
        out << other.price << " ";
        out << other.type << " ";
        out << other.percent << " ";
        return out;
    }
    bool operator<(const Credit& other) const {
        return this->percent < other.percent;
    }
};

int main() {
    ifstream fin("input.txt");
    if (!fin) {
        cout << "Ошибка открытия файла";
        return 0;
    }
    string name,type;
    double price;
    float percent;
    vector<Credit> credits;
    deque<Credit> credits_deque;
    while (fin >> name >> price >> type >> percent) {
        Credit credit(name,price,type,percent);
        credits.push_back(credit);

    }
    copy(credits.begin(), credits.end(), back_inserter(credits_deque));
    sort(credits.begin(),credits.end());
    ofstream fout("output.txt");
    if (!fout) {
        cout << "Ошибка открытия output.txt";
        return 0;
    }
    fout << "Исходные кредиты\n"<< endl;
    for (int i = 0; i < credits_deque.size();i++) {
        fout << credits_deque[i]<< endl;
    }
    fout << "\nОтсортированные кредиты\n" << endl;
    for (int i = 0; i < credits.size();i++) {
        fout << credits[i] << endl;

    }
    fout <<"\nСкопированные кредиты\n" << endl;
    for (int i = 0; i < credits_deque.size(); i++) {
        fout << credits_deque[i] << endl;
    }
    return 0;
}
