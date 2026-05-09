#include <bits/stdc++.h>
using namespace std;

int main() {
    srand(time(0)); // seed random generator

    string name;
    cout << "Enter your name: ";
    getline(cin, name);

    if (name.empty()) {
        cout << "Oops! You forgot to enter a name." << endl;
        return 0;
    }

    // Roast templates with {name} placeholder
    vector<string> roasts = {
        "{name} writes code so slow that even a turtle switched to Python.",
        "If procrastination were an Olympic sport, {name} would already have a gold medal.",
        "{name}'s debugging style is basically staring at the screen until the bug gets embarrassed and leaves.",
        "{name}'s code runs so slowly that even dial-up internet feels fast.",
        "If laziness had a brand ambassador, it would be {name}.",
        "{name} doesn’t debug code — they negotiate with bugs.",
        "{name} thinks Stack Overflow is a personality trait.",
        "When {name} compiles code, even the compiler takes a coffee break.",
        "{name} writes comments so confusing that even Google Translate gave up.",
        "If coding errors were currency, {name} would be a billionaire."
    };

    // Pick a random roast
    int idx = rand() % roasts.size();
    string roast = roasts[idx];

    // Replace {name} with actual input
    size_t pos = roast.find("{name}");
    while (pos != string::npos) {
        roast.replace(pos, 6, name);
        pos = roast.find("{name}", pos + name.length());
    }

    cout << roast << endl;

    return 0;
}
