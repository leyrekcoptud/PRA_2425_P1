#ifndef LISTARRAY_H
#define LISTARRAY_H

#include <ostream>
#include "List.h"
#include <stdexcept>

template <typename T>
class ListArray : public List<T> {
private:
    T* arr;
    int max;
    int n;
    static const int MINSIZE = 2;

    void resize(int new_size) {
        T* new_arr = new T[new_size];
        for (int i = 0; i < n; ++i) {
            new_arr[i] = arr[i];
        }
        delete[] arr;
        arr = new_arr;
        max = new_size;
    }

public:
    ListArray() : arr(new T[MINSIZE]), max(MINSIZE), n(0) {}

    ~ListArray() {
        delete[] arr;
    }

    void insert(int pos, T e) override {
	if (pos < 0 || pos > n) {
            throw std::out_of_range("Position out of range");
        }
        if (n == max) {
            resize(max * 2);
        }
        for (int i = n; i > pos; --i) {
            arr[i] = arr[i - 1];
        }
        arr[pos] = e;
        ++n;
    }

    void append(T e) override {
        insert(n, e);
    }

    void prepend(T e) override {
        insert(0, e);
    }

    T remove(int pos) override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Position out of range");
        }
        T removedElement = arr[pos];
        for (int i = pos; i < n - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        --n;
        if (n > 0 && n == max / 4) {
	    resize(max / 2);
        }
        return removedElement;
    }

    T get(int pos) const override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Position out of range");
        }
        return arr[pos];
    }

    int search(T e) const override {
        for (int i = 0; i < n; ++i) {
            if (arr[i] == e) {
                return i;
            }
        }
        return -1; // Element not found
    }

    bool empty() const override {
        return n == 0;
    }

    int size() const override {
        return n;
    }

    friend std::ostream& operator<<(std::ostream& out, const ListArray<T>& list) {
            for (int i = 0; i < list.n; ++i) {
                    out << list.arr[i] << " ";
            } return out;
    }
};
#endif // LISTARRAY_H:

