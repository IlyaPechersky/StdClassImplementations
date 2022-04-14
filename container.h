#ifndef UNTITLED_CONTAINER_H
#define UNTITLED_CONTAINER_H


template <typename T>
class Container {
public:
    Container() {
        m_start = m_end = nullptr;
        m_size = 0;
    }

    ~Container() { clear(); }

    void push_front(const T& data) {
        if (m_start) {
            Node *new_node = new Node();
            new_node->data = data;
            new_node->next = m_start;
            m_start->prev = new_node;
            m_start = new_node;
        } else {
            init(data);
        }

        m_size++;
    }

    void pop_front() {
        if (!m_start) return;

        if (m_start->next) {
            Node *next = m_start->next;
            next->prev = nullptr;

            delete m_start;

            m_start = next;
        } else {
            delete m_start;
            m_start = m_end = nullptr;
        }

        m_size--;
    }

    void push_back(const T& data) {
        if (m_end) {
            Node *new_node = new Node();

            new_node->data = data;
            new_node->prev = m_end;
            m_end->next = new_node;
            m_end = new_node;
        } else {
            init(data);
        }

        m_size++;
    }

    void pop_back() {
        if (!m_end) return;

        if (m_end->prev) {
            Node *prev = m_end->prev;
            prev->next = nullptr;

            delete m_end;

            m_end = prev;
        } else {
            delete m_end;
            m_start = m_end = nullptr;
        }

        m_size--;
    }

    T front() {
        return m_start->data;
    }

    T back() {
        return m_end->data;
    }

    void clear() {
        if (!m_start) return;
        if (m_start == m_end) {
            delete m_start;
        } else {
            Node *tmp = m_start;
            while (tmp != m_end) {
                Node *next = tmp->next;
                delete tmp;
                tmp = next;
            }
        }

        m_size = 0;
        m_start = m_end = nullptr;
    }

    int size() const {
        return m_size;
    }

    bool is_empty() {
        return m_size == 0;
    }

private:
    struct Node {
        Node() {
            next = nullptr;
            prev = nullptr;
        }

        ~Node() = default;

        T data;
        Node *next;
        Node *prev;
    };

    void init(const T& data) {
        m_start = new Node();
        m_start->data = data;
        m_end = m_start;
    }

    void remove_node(Node *node) {
        Node *prev = node->prev;
        Node *next = node->next;

        if (prev != nullptr) prev->next = next;
        if (next != nullptr) next->prev = prev;

        if (node == m_start) m_start = next;
        if (node == m_end) m_end = prev;

        delete node;

        m_size--;
    }

    Node *m_start;
    Node *m_end;

    int m_size;
};

#endif //UNTITLED_CONTAINER_H
