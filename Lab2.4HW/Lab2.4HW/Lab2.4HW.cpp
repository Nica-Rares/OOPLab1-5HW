#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Person {
    string name;
    int age;
};

bool compareByAgeDescending(const Person& p1, const Person& p2) {
    return p1.age > p2.age;
}

bool compareByNameAscending(const Person& p1, const Person& p2) {
    return p1.name < p2.name;
}

int main() {
    vector<Person> people = {
        {"Alice", 30},
        {"Bob", 25},
        {"Charlie", 35},
        {"David", 20}
    };

    cout << "Sorted by Age (Descending):" << endl;
    sort(people.begin(), people.end(), compareByAgeDescending);
    for (const Person& person : people) {
        cout << person.name << " (" << person.age << ")" << endl;
    }

    cout << "Sorted by Name (Ascending):" << endl;
    sort(people.begin(), people.end(), compareByNameAscending);
    for (const Person& person : people) {
        cout << person.name << " (" << person.age << ")" << endl;
    }

    return 0;
}
