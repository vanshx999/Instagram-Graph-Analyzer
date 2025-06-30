#include "usergraph.h"
#include <sstream>
void UserGraph::addUser(const std::string& user) {
    if (adjList.find(user) == adjList.end())
        adjList[user] = {};
}

void UserGraph::addFollow(const std::string& from, const std::string& to) {
    if (adjList.count(from) && adjList.count(to))
        adjList[from].push_back(to);
}

std::vector<std::string> UserGraph::getMutuals(const std::string& a, const std::string& b) {
    std::set<std::string> setA(adjList[a].begin(), adjList[a].end());
    std::set<std::string> setB(adjList[b].begin(), adjList[b].end());
    std::vector<std::string> mutuals;
    for (const std::string& user : setA)
        if (setB.count(user)) mutuals.push_back(user);
    return mutuals;
}

std::vector<std::string> UserGraph::suggestFriends(const std::string& user) {
    std::set<std::string> direct(adjList[user].begin(), adjList[user].end());
    std::set<std::string> suggestions;
    for (const std::string& f1 : adjList[user]) {
        for (const std::string& f2 : adjList[f1]) {
            if (f2 != user && !direct.count(f2))
                suggestions.insert(f2);
        }
    }
    return std::vector<std::string>(suggestions.begin(), suggestions.end());
}

std::vector<std::string> UserGraph::getTopInfluencers(int topN) {
    std::unordered_map<std::string, int> indegree;
    for (auto& [user, follows] : adjList)
        for (const auto& f : follows)
            indegree[f]++;
    std::priority_queue<std::pair<int, std::string>> pq;
    for (auto& [user, _] : adjList)
        pq.push({ indegree[user], user });

    std::vector<std::string> top;
    while (!pq.empty() && top.size() < topN) {
        top.push_back(pq.top().second);
        pq.pop();
    }
    return top;
}

std::vector<std::string> UserGraph::getAllUsers() {
    std::vector<std::string> users;
    for (const auto& [user, _] : adjList)
        users.push_back(user);
    return users;
}
void UserGraph::removeUser(const std::string& user) {
    adjList.erase(user);
    for (auto& [u, follows] : adjList) {
        follows.erase(std::remove(follows.begin(), follows.end(), user), follows.end());
    }
}

void UserGraph::unfollow(const std::string& from, const std::string& to) {
    auto& follows = adjList[from];
    follows.erase(std::remove(follows.begin(), follows.end(), to), follows.end());
}
#include <fstream>

void UserGraph::saveToFile(const std::string& filename) {
    std::ofstream out(filename);
    for (const auto& [user, follows] : adjList) {
        out << user;
        for (const auto& f : follows)
            out << " " << f;
        out << "\n";
    }
    out.close();
}

void UserGraph::loadFromFile(const std::string& filename) {
    adjList.clear();
    std::ifstream in(filename);
    std::string line;
    while (std::getline(in, line)) {
        std::istringstream iss(line);
        std::string user;
        iss >> user;
        adjList[user] = {};
        std::string follow;
        while (iss >> follow) {
            adjList[user].push_back(follow);
        }
    }
    in.close();
}
