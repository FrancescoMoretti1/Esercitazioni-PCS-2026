
#ifndef ADAPTERS_HPP
#define ADAPTERS_HPP

#include <queue>
#include <stack>

template<typename T>
class fifo {
    std::queue<T> q;
public:
    fifo() = default;
    void put(const T& val) { q.push(val); }
    T get() { T val = q.front(); q.pop(); return val; }
    bool empty() const { return q.empty(); }
};

template<typename T>
class lifo {
    std::stack<T> s;
public:
    lifo() = default;
    void put(const T& val) { s.push(val); }
    T get() { T val = s.top(); s.pop(); return val; }
    bool empty() const { return s.empty(); }
};

#endif
