#include <bits/stdc++.h>
using namespace std;

int main() {
    srand(time(0)); // seed random generator

    string name;
    cout << "Enter student name: ";
    getline(cin, name);

    if (name.empty()) {
        cout << "Oops! You forgot to enter a name." << endl;
        return 0;
    }

    // Excuse templates with {name} placeholder
    vector<string> excuses = {
        "{name} couldn’t finish the assignment because the laptop decided to install updates for six hours.",
        "{name} was about to complete the homework when the Wi-Fi mysteriously disappeared.",
        "{name} tried finishing the assignment, but the computer keyboard suddenly stopped cooperating.",
        "{name} couldn’t complete the assignment because the laptop battery died unexpectedly.",
        "{name} was ready to submit the assignment when the file mysteriously disappeared.",
        "{name} almost finished the homework, but the printer decided to jam every single page.",
        "{name} couldn’t complete the assignment because the dog thought the notes were a snack.",
        "{name} tried to finish the homework, but the power went out right when they started.",
        "{name} was halfway through the assignment when the software crashed and deleted everything.",
        "{name} couldn’t complete the homework because the alarm clock betrayed them and they overslept."
    };

    // Pick a random excuse
    int idx = rand() % excuses.size();
    string excuse = excuses[idx];

    // Replace {name} with actual input
    size_t pos = excuse.find("{name}");
    while (pos != string::npos) {
        excuse.replace(pos, 6, name);
        pos = excuse.find("{name}", pos + name.length());
    }

    cout << excuse << endl;

    return 0;
}
