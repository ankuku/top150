# include <iostream>
# include <vector>
# include <unordered_map>
# include <ctime>
using namespace std;

class RandomizedSet {
private:
    unordered_map<int, int> map;
    vector<int> arr;

public:
    RandomizedSet() {
        srand(time(0));
    }

    bool insert(int val) {
        if (map.find(val) != map.end()) {
            return false;
        }
        arr.push_back(val);
        map[val] = arr.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (map.find(val) == map.end()) {
            return false;
        }
        int last = arr.back();
        int idx = map[val];

        arr[idx] = last;
        map[last] = idx;

        arr.pop_back();
        map.erase(val);
        return true;
    }

    int getRandom() {
        int randIndex = rand() % arr.size();
        return arr[randIndex];
    }
};

int main() {
    vector<string> commands = {"RandomizedSet", "remove", "remove", "insert", "getRandom", "remove", "insert"};
    vector<vector<int>> arguments = {{}, {0}, {0}, {0}, {}, {0}, {0}};

    RandomizedSet* obj = nullptr;

    for (int i = 0; i < commands.size(); i++) {
        if (commands[i] == "RandomizedSet") {
            obj = new RandomizedSet();
            cout << "null" << endl;  // Constructor does not return a value
        } else if (commands[i] == "insert") {
            bool result = obj->insert(arguments[i][0]);
            cout << (result ? "true" : "false") << endl;
        } else if (commands[i] == "remove") {
            bool result = obj->remove(arguments[i][0]);
            cout << (result ? "true" : "false") << endl;
        } else if (commands[i] == "getRandom") {
            int result = obj->getRandom();
            cout << result << endl;
        }
    }

    delete obj;  // Free the allocated memory

    return 0;
}