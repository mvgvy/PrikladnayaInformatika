#pragma ide diagnostic ignored "cert-msc50-cpp"

#include "int_list_t.hpp"

#include <cassert>

int main() {
    size_t count = 10;
    int value = 1;

    int_list_t a(count, value);
    std::cout << a << '\n';

    assert(a.size() == count);
    for (size_t i = 0; i < count; ++i) {
        assert(a[i] == value);
    }

    const int_list_t b(a);
    std::cout << b << '\n';

    assert(a.size() == count);
    assert(b.size() == count);
    for (size_t i = 0; i < count; ++i) {
        assert(b[i] == value);
    }

    for (int i = 0; i < count; ++i) {
        a[i] += i + 1;

        assert(a[i] == value + i + 1);
    }

    a.pop_front();
    assert(a.size() == count - 1);
    assert(a.front() == value + 2);

    a.push_front(value + 1);
    assert(a.front() == value + 1);
    assert(a.back() == value + count);

    a.front() = value;
    assert(a.front() == value);
    assert(b.front() == value);

    a.back() = value;
    assert(a.back() == value);
    assert(b.back() == value);

    a.clear();
    assert(a.empty());

    a = b;
    std::cout << a << '\n';

    assert(a.size() == count);
    for (size_t i = 0; i < count; ++i) {
        assert(a[i] == value);
    }

    for (int i = 0; i < count; ++i) {
        a[i] += i;
    }

    int_list_t c = a.splice(1, count - 2);
    std::cout << c << '\n';
    std::cout << a << '\n';

    assert(c.size() == count - 2);
    for (size_t i = 0; i < count - 2; ++i) {
        assert(c[i] == value + i + 1);
    }

    assert(a.size() == 2);
    assert(a.front() == value);
    assert(a.back() == value + count - 1);

    a.merge(c);
    std::cout << a << '\n';
    std::cout << c << '\n';
    assert(a.size() == count);
    assert(c.empty());

    std::cout << a << '\n';

    a.reverse();
    std::cout << a << '\n';

    assert(a.size() == count);
    assert(a.front() == value + count - 2);
    assert(a.back() == value);

    a.swap(c);
    std::cout << a << '\n';
    std::cout << c << '\n';

    assert(a.empty());
    assert(c.size() == count);
    assert(c.front() == value + count - 2);
    assert(c.back() == value);

    std::cin >> a;
    std::cout << a;

    return 0;
}
