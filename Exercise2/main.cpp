#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "SortingAlgorithm.hpp"

void printArray(const std::vector<int>& arr) {
    for (int num : arr)
        std::cout << num << " ";
    std::cout << std::endl;
}
// Funzioni per generare tipi diversi di vettori
std::vector<int> generateRandomVector(int size) {
    std::vector<int> v(size);
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(0, 10000);
    for (auto& x : v) x = dist(rng);
    return v;
}

std::vector<int> generateSortedVector(int size) {
    std::vector<int> v = generateRandomVector(size);
    std::sort(v.begin(), v.end());
    return v;
}

std::vector<int> generateReverseSortedVector(int size) {
    std::vector<int> v = generateSortedVector(size);
    std::reverse(v.begin(), v.end());
    return v;
}

std::vector<int> generateVectorWithDuplicates(int size) {
    std::vector<int> v(size);
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(0, size / 10); // Tanti duplicati
    for (auto& x : v) x = dist(rng);
    return v;
}

// Funzione per misurare il tempo di ordinamento
template<typename SortFunction>
void benchmark(SortFunction sortFunc, std::vector<int> arr, const std::string& description) {
    auto start = std::chrono::high_resolution_clock::now();
    sortFunc(arr);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    std::cout << description << " took " << duration.count() << " ms\n";
}

int main(int argc, char* argv[])
{
    if (argc < 3) {
    std::cerr << "Uso: " << argv[0] << " <dimensione> <algoritmo: bubble|heap>\n";
    return 1;
}

int size = std::atoi(argv[1]);
std::string algo = argv[2];

// Generiamo i vari tipi di vettori
    auto randomVec = generateRandomVector(size);
    auto sortedVec = generateSortedVector(size);
    auto reverseSortedVec = generateReverseSortedVector(size);
    auto duplicateVec = generateVectorWithDuplicates(size);

    if (algo == "bubble") {
        std::cout << "\n=== BubbleSort Benchmark ===\n";
        benchmark(bubbleSort<int>, randomVec, "Vettore Random ");
        benchmark(bubbleSort<int>, sortedVec, " Vettore Sorted ");
        benchmark(bubbleSort<int>, reverseSortedVec, " Vettore Sorted inverso ");
        benchmark(bubbleSort<int>, duplicateVec, "Vettore duplicato");
    }
    else if (algo == "heap") {
        std::cout << "\n=== HeapSort Benchmark ===\n";
        benchmark(heapSort<int>, randomVec, " Vettore Random ");
        benchmark(heapSort<int>, sortedVec, " Vettore Sorted ");
        benchmark(heapSort<int>, reverseSortedVec, "Vettore Sorted inverso");
        benchmark(heapSort<int>, duplicateVec, "Vettore duplicato");
    }
    else {
        std::cerr << "Algoritmo non riconosciuto: " << algo << "\n";
        return 1;
    }

    return 0;
    
}

