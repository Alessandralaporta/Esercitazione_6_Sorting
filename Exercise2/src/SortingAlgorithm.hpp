#pragma once
#ifndef SORTING_ALGORITHM_HPP
#define SORTING_ALGORITHM_HPP

#include <iostream>
#include <vector>
#include <algorithm>



namespace SortLibrary {
template<typename T>
void BubbleSort(std::vector<T>& data)
{
    size_t rem_size = data.size();
    size_t last_seen = rem_size;
    bool swapped = true;

    while (swapped) {
        swapped = false;
        for (size_t i = 1; i < rem_size; i++) {
            if (data[i-1] > data[i]) {
                std::swap(data[i-1], data[i]);
                swapped = true;
                last_seen = i;
            }
        }
//        rem_size = rem_size - 1;
        rem_size = last_seen;
    }
}
template<typename T>
void selectionSort(std::vector<T>& data) {
    size_t n = data.size();
    for (size_t i = 0; i < n - 1; i++) {
        size_t min_idx = i;
        for (size_t j = i + 1; j < n; j++) {
            if (data[j] < data[min_idx]) {
                min_idx = j;
            }
        }
        std::swap(data[i], data[min_idx]);
    }
}

template<typename T>
void insertionSort(std::vector<T>& data) {
    size_t n = data.size();
    for (size_t i = 1; i < n; i++) {
        T key = data[i];
        size_t j = i - 1;
        while (j >= 0 && data[j] > key) {
            data[j + 1] = data[j];
            if (j == 0) break;  // Previene accesso out-of-bounds
            j--;
        }
        data[j + 1] = key;
    }
}
template<typename T>
void heapify(std::vector<T>& arr, int n, int i) {
    int largest = i;       // Inizialmente il nodo più grande è la radice
    int left = 2 * i + 1;  // Figlio sinistro
    int right = 2 * i + 2; // Figlio destro

    // Se il figlio sinistro è più grande della radice
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Se il figlio destro è più grande del nodo più grande finora
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Se il nodo più grande non è la radice
    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        // Ricorsivamente heapify il sottoalbero interessato
        heapify(arr, n, largest);
    }
}
template<typename T>
void heapSort(std::vector<T>& arr) {
    int n = arr.size();

    // Costruzione dell’heap (riorganizza l’array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Estrae elementi uno alla volta dall’heap
    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]); // Sposta la radice alla fine
        heapify(arr, i, 0);        // Heapify sull’heap ridotto
    }
}

}

#endif // SORTING_ALGORITHM_HPP
