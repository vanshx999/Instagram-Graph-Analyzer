
#ifndef USERGRAPH_H
#define USERGRAPH_H

#include <unordered_map>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <algorithm>

class UserGraph {
public:
    void saveToFile(const std::string& filename);
    void loadFromFile(const std::string& filename);
    void removeUser(const std::string& user);
    void unfollow(const std::string& from, const std::string& to);
    void addUser(const std::string& user);
    void addFollow(const std::string& from, const std::string& to);
    std::vector<std::string> getMutuals(const std::string& a, const std::string& b);
    std::vector<std::string> suggestFriends(const std::string& user);
    std::vector<std::string> getTopInfluencers(int topN = 3);
    std::vector<std::string> getAllUsers();

private:
    std::unordered_map<std::string, std::vector<std::string>> adjList;
};

#endif // USERGRAPH_H

