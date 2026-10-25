#include <iostream>
using namespace std;

const int SIZE = 6;

struct Edge {
    int from;
    int to;
    int weight;
};

struct ListNode {
    char vertex;
    int weight;
    ListNode* next;
};


// Show the vertices of the graph
void showVertices() {
    cout << "Vertices: ";

    for (char v = 'A'; v <= 'F'; v++) {
        cout << v;

        if (v != 'F') {
            cout << ", ";
        }
    }

    cout << endl;
}


// Create the adjacency matrix
void createMatrix(Edge edges[], int totalEdges, int matrix[][SIZE]) {

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            matrix[i][j] = 0;
        }
    }

    for (int i = 0; i < totalEdges; i++) {
        matrix[edges[i].from][edges[i].to] = edges[i].weight;
    }
}


// Display the adjacency matrix
void showMatrix(int matrix[][SIZE]) {

    cout << "\nAdjacency Matrix\n\n";

    cout << "  ";

    for (char v = 'A'; v <= 'F'; v++) {
        cout << v << " ";
    }

    cout << endl;

    for (int i = 0; i < SIZE; i++) {

        cout << char('A' + i) << " ";

        for (int j = 0; j < SIZE; j++) {
            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }
}


// Add an item to the adjacency list
void addNode(ListNode*& head, char vertex, int weight) {

    ListNode* newItem = new ListNode;

    newItem->vertex = vertex;
    newItem->weight = weight;
    newItem->next = NULL;

    if (head == NULL) {
        head = newItem;
    }
    else {
        ListNode* current = head;

        while (current->next != NULL) {
            current = current->next;
        }

        current->next = newItem;
    }
}


// Display the adjacency list
void showList(ListNode* graph[]) {

    cout << "\nAdjacency List\n";
    cout << "(Start Vertex, End Vertex, Weight)" << endl;

    for (int i = 0; i < SIZE; i++) {

        ListNode* current = graph[i];

        while (current != NULL) {

            cout << "("
                 << char('A' + i) << ", "
                 << current->vertex << ", "
                 << current->weight << ")"
                 << endl;

            current = current->next;
        }
    }
}


// Delete the linked lists
void clearList(ListNode* graph[]) {

    for (int i = 0; i < SIZE; i++) {

        ListNode* current = graph[i];

        while (current != NULL) {

            ListNode* remove = current;
            current = current->next;

            delete remove;
        }

        graph[i] = NULL;
    }
}


int main() {

    Edge edges[] = {
        {0, 1, 2},
        {0, 2, 4},
        {1, 4, 3},
        {2, 3, 2},
        {3, 1, 4},
        {4, 3, 3}
    };

    int edgeCount = sizeof(edges) / sizeof(edges[0]);

    // A.1
    cout << "A.1 Create a Graph" << endl;
    showVertices();


    // A.2
    int matrix[SIZE][SIZE];

    createMatrix(edges, edgeCount, matrix);

    cout << "\nA.2 Adjacency Matrix" << endl;
    showMatrix(matrix);


    // A.3
    ListNode* graph[SIZE];

    for (int i = 0; i < SIZE; i++) {
        graph[i] = NULL;
    }

    for (int i = 0; i < edgeCount; i++) {

        char destination = char('A' + edges[i].to);

        addNode(
            graph[edges[i].from],
            destination,
            edges[i].weight
        );
    }

    cout << "\nA.3 Adjacency List" << endl;
    showList(graph);


    clearList(graph);

    return 0;
}
