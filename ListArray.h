#ifndef LISTARRAY_H
#define LISTARRAY_H

#include "List.h"
#include <ostream>
#include <stdexcept>

template <typename T>
class ListArray : public List<T> {
private:
    T* arr; // Puntero al inicio del array
    int max; // Tamaño actual del array
    int n; // Número de elementos en la lista
    static const int MINSIZE = 2; // Tamaño mínimo del array

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
            throw std::out_of_range("Posición inválida");
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
        insert(n, e); // Llama a insert() para añadir al final
    }

    void prepend(T e) override {
        insert(0, e); // Llama a insert() para añadir al principio
    }

    T remove(int pos) override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición inválida");
        }
        T removedElement = arr[pos];
        for (int i = pos; i < n - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        --n;
        if (n > 0 && n < max / 4) {
            resize(max / 2);
        }
        return removedElement;
    }

    T get(int pos) const override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición inválida");
        }
        return arr[pos];
    }

    int search(T e) const override {
        for (int i = 0; i < n; ++i) {
            if (arr[i] == e) {
                return i;
            }
        }
        return -1;
    }

    bool empty() const override {
        return n == 0;
    }

    int size() const override {
        return n;
    }

    T operator[](int pos) {
        return get(pos);
    }

    friend std::ostream& operator<<(std::ostream& out, const ListArray<T>& list) {
        for (int i = 0; i < list.n; ++i) {
            out << list.arr[i] << " ";
        }
        return out;
    }
};

#endif // LISTARRAY_H

