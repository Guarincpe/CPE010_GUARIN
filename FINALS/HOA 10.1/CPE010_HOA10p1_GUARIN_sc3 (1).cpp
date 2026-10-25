#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <queue>
using namespace std;

template <typename T>
class Graph;

template <typename T>
struct Edge {
    size_t src;
    size_t dest;
    T weight;

    bool operator<(const Edge<T>& e) const {
        return weight < e.weight;
    }

    bool operator>(const Edge<T>& e) const {
        return weight > e.weight;
    }
};

template <typename T>
ostream& operator<<(ostream& os, const Graph<T>& G) {
    for (size_t i = 1; i <= G.vertices(); i++) {
        os << i << ":\t";
        auto edges = G.outgoing_edges(i);
        for (auto& e : edges)
            os << "{" << e.dest << ": " << e.weight << "}, ";
        os << endl;
    }
    return os;
}

template <typename T>
class Graph {
public:
    Graph(size_t N) : V(N) {}

    auto vertices() const {
        return V;
    }

    auto& edges() const {
        return edge_list;
    }

    void add_edge(Edge<T>&& e) {
        if (e.src >= 1 && e.src <= V &&
            e.dest >= 1 && e.dest <= V) {
            edge_list.emplace_back(e);
        } else {
            cerr << "Vertex out of bounds" << endl;
        }
    }

    auto outgoing_edges(size_t v) const {
        vector<Edge<T>> edges_from_v;
        for (auto& e : edge_list) {
            if (e.src == v)
                edges_from_v.emplace_back(e);
        }
        return edges_from_v;
    }

    template <typename U>
    friend ostream& operator<<(ostream& os, const Graph<U>& G);

private:
    size_t V;
    vector<Edge<T>> edge_list;
};

template <typename T>
auto breadth_first_search(const Graph<T>& G, size_t dest) {
    queue<size_t> q;
    vector<size_t> visit_order;
    set<size_t> visited;

    q.push(1); // Start at vertex 1

    while (!q.empty()) {
        auto current_vertex = q.front();
        q.pop();

        if (visited.find(current_vertex) == visited.end()) {
            visited.insert(current_vertex);
            visit_order.push_back(current_vertex);

            for (auto e : G.outgoing_edges(current_vertex)) {
                if (visited.find(e.dest) == visited.end())
                    q.push(e.dest);
            }
        }
    }
    return visit_order;
}

template <typename T>
auto create_reference_graph() {
    Graph<T> G(9);
    map<unsigned, vector<pair<size_t, T>>> edges;

    edges[1] = {{2, 2}, {5, 3}};
    edges[2] = {{1, 2}, {5, 5}, {4, 1}};
    edges[3] = {{4, 2}, {7, 3}};
    edges[4] = {{2, 1}, {3, 2}, {5, 2}, {6, 4}, {8, 5}};
    edges[5] = {{1, 3}, {2, 5}, {4, 2}, {8, 3}};
    edges[6] = {{4, 4}, {7, 4}, {8, 1}};
    edges[7] = {{3, 3}, {6, 4}};
    edges[8] = {{4, 5}, {5, 3}, {6, 1}};

    for (auto& i : edges)
        for (auto& j : i.second)
            G.add_edge(Edge<T>{i.first, j.first, j.second});

    return G;
}

template <typename T>
void test_BFS() {
    auto G = create_reference_graph<unsigned>();
    cout << G << endl;
    cout << "BFS Order of vertices:" << endl;

    auto bfs_visit_order = breadth_first_search(G, 1);
    for (auto v : bfs_visit_order)
        cout << v << endl;
}

int main() {
    using T = unsigned;
    test_BFS<T>();
    return 0;
}
