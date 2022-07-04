#ifndef SIMPLESTACK3_H
#define SIMPLESTACK3_H

#include <cassert>
#include <vector>

template <typename T>
class SimpleStack3
{
private:
    int anzahl{0}; // Anfangswert
    std::vector<T> array; // Beh�lter f�r Elemente
public:
    // inline definierte Methoden
    bool empty() const
    {
        return anzahl == 0;
    }
    auto size() const
    {
        return anzahl;
    }
    void clear()
    {
        anzahl = 0;    // Stack leeren
    }
    // Methoden, deren Implementation unten folgt:
    const T& top() const; // letztes Element sehen
    void pop(); // Element entfernen
    // Vorbedingung f�r top und pop: Stack ist nicht leer
    void push(const T& x); // x auf den Stack legen
};

// noch fehlende Methoden-Implementierungen als Alternative zur inline-Definition
template <typename T>
const T& SimpleStack3<T>::top() const
{
    assert(!empty());
    return array[anzahl - 1];
}
template <typename T>
void SimpleStack3<T>::pop()
{
    assert(!empty());
    --anzahl;
}
template <typename T>
void SimpleStack3<T>::push(const T& x)
{
    if (anzahl < ssize(array))
        array[anzahl] = x;
    else
        array.push_back(x);
    anzahl++;
}
#endif
