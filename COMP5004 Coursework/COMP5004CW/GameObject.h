#include <string>

using std::string;

class GameObject {
    const string keyword;

    const string description;

public:

    GameObject(const string keyword, const string description);

    void describe() const;

    string getKeyword();

    string getDescription();
};