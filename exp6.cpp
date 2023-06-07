#include <iostream>
#include <list>
#include <string>


struct Edge {
    std::string source;
    std::string dest;
    int time;
    
    Edge(const std::string& src, const std::string& dst, int t) : source(src), dest(dst), time(t) {}
};

const int num = 5;

class Graph {
public:
    std::list<Edge>* conn[num];
    std::string city[num];
    
    void create();
    void displayGraph();
};

void Graph::create() {
    char ch;
    int time;
    
    for (int i = 0; i < num; i++) {
        conn[i] = new std::list<Edge>;
    }
    
    std::cout << "Enter 5 cities: ";
    for (int i = 0; i < num; i++) {
        std::cin >> city[i];
    }
    
    for (int i = 0; i < num; i++) {
        for (int j = i + 1; j < num; j++) {
            std::cout << "Is there an edge between " << city[i] << " and " << city[j] << " (y/n): ";
            std::cin >> ch;
            
            if (ch == 'y') {
                std::cout << "Enter time: ";
                std::cin >> time;
                
                Edge* temp = new Edge(city[i], city[j], time);
                conn[i]->push_back(*temp);
            }
        }
    }
}

void Graph::displayGraph() {
    std::cout << "Graph:" << std::endl;
    for (int i = 0; i < num; i++) {
        std::cout << "City " << city[i] << " -> ";

        if (conn[i] == nullptr || conn[i]->empty()) {
            std::cout << "No edges";
        } else {
            for (const Edge& edge : *(conn[i])) {
                std::cout << edge.dest << " (Time: " << edge.time << "), ";
            }
        }

        std::cout << std::endl;

        std::cout << "City " << city[i] << " <- ";
        bool hasIncomingEdges = false;
        for (int j = 0; j < num; j++) {
            for (const Edge& edge : *(conn[j])) {
                if (edge.dest == city[i]) {
                    std::cout << city[j] << " (Time: " << edge.time << "), ";
                    hasIncomingEdges = true;
                }
            }
        }

        if (!hasIncomingEdges) {
            std::cout << "No incoming edges";
        }

        std::cout << std::endl;
    }
}

int main() {
    Graph g;
    g.create();
    g.displayGraph();
    
    // Rest of your code
    
    return 0;
}




