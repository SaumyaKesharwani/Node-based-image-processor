#ifndef CONNECTION_H
#define CONNECTION_H

#include <memory>
#include "node.h"

class Connection {
public:
    Connection(std::shared_ptr<Node> from, std::shared_ptr<Node> to);
    std::shared_ptr<Node> getFromNode() const;
    std::shared_ptr<Node> getToNode() const;
private:
    std::shared_ptr<Node> fromNode;
    std::shared_ptr<Node> toNode;
};

#endif // CONNECTION_H
