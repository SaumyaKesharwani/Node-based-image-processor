#ifndef NODE_H
#define NODE_H

#include <string>
#include <vector>
#include <memory>

// Forward declaration of Connection
class Connection;

class Node {
public:
    Node(const std::string& name);
    virtual ~Node();

    std::string getName() const;
    virtual void process() = 0; // Pure virtual

    void addInputConnection(std::shared_ptr<Connection> connection);
    void addOutputConnection(std::shared_ptr<Connection> connection);

    const std::vector<std::shared_ptr<Connection>>& getInputConnections() const;
    const std::vector<std::shared_ptr<Connection>>& getOutputConnections() const;

protected:
    std::string name;
    std::vector<std::shared_ptr<Connection>> inputConnections;
    std::vector<std::shared_ptr<Connection>> outputConnections;
};

#endif // NODE_H
