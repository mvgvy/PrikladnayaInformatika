#include "int_list_t.hpp"

int_list_t::int_list_t(): head(new node_t {}), tail(new node_t {}), _size(0) {
    head->next = tail;
    tail->prev = head;
}

int_list_t::int_list_t(const int_list_t &other): int_list_t() {
    push_back_from(other);
}

int_list_t::int_list_t(size_t count, int value): int_list_t() {
    for (size_t i = 0; i < count; ++i) {
        push_back(value);
    }
}

int_list_t::~int_list_t() {
    clear();

    delete head;
    delete tail;
}

int_list_t &int_list_t::operator=(const int_list_t &other) {
    if (this != &other) {
        clear();

        push_back_from(other);
    }

    return *this;
}

int &int_list_t::operator[](size_t pos) {
    return find_node(pos)->value;
}

int int_list_t::operator[](size_t pos) const {
    return find_node(pos)->value;
}

int &int_list_t::back() {
    return tail->prev->value;
}

int int_list_t::back() const {
    return tail->prev->value;
}

int &int_list_t::front() {
    return head->next->value;
}

int int_list_t::front() const {
    return head->next->value;
}

void int_list_t::clear() {
    while (_size > 0) {
        pop_back();
    }
}

size_t int_list_t::size() const {
    return _size;
}

bool int_list_t::empty() const {
    return _size == 0;
}

void int_list_t::insert(size_t pos, int new_val) {
    node_t *next = find_node(pos);

    auto *node = new node_t {new_val, next->prev, next};
    node->prev->next = node;
    next->prev = node;
    ++_size;
}

void int_list_t::push_front(int new_val) {
    insert(0, new_val);
}

void int_list_t::push_back(int new_val) {
    insert(_size, new_val);
}

void int_list_t::erase(size_t pos) {
    node_t *node = find_node(pos);

    node->next->prev = node->prev;
    node->prev->next = node->next;
    delete node;
    --_size;
}

void int_list_t::pop_front() {
    erase(0);
}

void int_list_t::pop_back() {
    erase(_size - 1);
}

int_list_t int_list_t::splice(size_t start_pos, size_t count) {
    auto *front = find_node(start_pos);
    auto *back = find_node(start_pos + count - 1);

    front->prev->next = back->next;
    back->next->prev = front->prev;
    _size -= count;

    return int_list_t(front, back, count);
}

int_list_t &int_list_t::merge(int_list_t &other) {
    tail->prev->next = other.head->next;
    other.head->next->prev = tail->prev;
    other.tail->prev->next = tail;
    tail->prev = other.tail->prev;
    _size += other._size;

    other.head->next = other.tail;
    other.tail->prev = other.head;
    other._size = 0;
    return *this;
}

void int_list_t::reverse() {
    for (node_t *node = head->next; node != nullptr; node = node->next) {
        std::swap(node->prev->next, node->prev->prev);
    }

    std::swap(tail->next, tail->prev);
    std::swap(head, tail);
}

void int_list_t::swap(int_list_t &other) {
    std::swap(head, other.head);
    std::swap(tail, other.tail);
    std::swap(_size, other._size);
}

std::istream &operator>>(std::istream &stream, int_list_t &list) {
    size_t count;

    stream >> count;
    for (size_t i = 0; i < count; ++i) {
        int a;

        stream >> a;
        list.push_back(a);
    }

    return stream;
}

std::ostream &operator<<(std::ostream &stream, const int_list_t &list) {
    stream << list._size << ' ';

    if (list._size > 0) {
        int_list_t::node_t * node = list.head->next;
        stream << node->value;

        for (node = node->next; node != list.tail; node = node->next) {
            stream << ' ' << node->value;
        }
    }

    return stream;
}

int_list_t::int_list_t(node_t *front, node_t *back, size_t size): int_list_t() {
    front->prev = head;
    back->next = tail;

    head->next = front;
    tail->prev = back;
    _size = size;
}

void int_list_t::push_back_from(const int_list_t &other) {
    for (node_t *node = other.head->next; node != other.tail; node = node->next) {
        push_back(node->value);
    }
}

int_list_t::node_t *int_list_t::find_node(size_t pos) const {
    if (pos < _size / 2) {
        node_t *node = head->next;

        for (size_t i = 0; i < pos; ++i) {
            node = node->next;
        }

        return node;
    }

    node_t *node = tail;
    for (size_t i = pos; i < _size; ++i) {
        node = node->prev;
    }

    return node;
}
