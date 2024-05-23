#include <iostream>
#include <list>
#include <initializer_list>
#include <random>

#include "ComparableConcept.hpp"
#include "remove_second_smallest.hpp"

/* Boriss Zalovs bz23005
 * === GG =======================================
 * GG – STL list un saistītais saraksts ar izņēmumsituāciju apstrādi un vienībtestēšanu**.
 * * atrisināt uzdevumu G divos veidos:
 *   a) izmantojot dinamiskas datu struktūras (saistīto sarakstu vtml.),
 *   b) izmantojot STL::list konteineru.
 * tas pats uzdevums, kas G, bet tā risinājums (a) jāpapildina ar divām lietām:
 *   1) vismaz viena no datu pārbaudēm jārealizē, izmantojot izņēmumsituāciju apstrādes (exception handling) mehānismu,
 *   2) vismaz viena funkcija (vēlams, galvenā) ir jānotestē, izmantojot vienībtestēšanu,
 *      kur attiecīgā funkcija būtu jāpārbauda uz vismaz trīs dažādiem nosacījumiem;
 *      šim nolūkam, kā minimums, ir nepieciešams:
 * 	      (1) šo funkciju iznest ārā citā failā (nekā funkcija main),
 * 	      (2) izveidot otru projektu speciāli šīs funkcijās testēšanai (tātad, kopā būs divi projekti, parastais,
 *            kas izmantos funkciju, otrais, kas testēs).
 * Papildus norāde: šādam vienībtestēšanas projektam daļēji atbilst iepriekšējā semestra pēdējais laboratorijas darbs (ar klasēm) ar cieti iekodētu main funkciju.
 */

int main()
{
    int n{15}, min{1}, max{10};

    MyLinkedList<int> l = {1, 3, 1, 2};
    // fill_random_numbers(n, min, max);
    std::cout << "My linked list:" << std::endl;
    l.print();
    for (int i = 0; i < n + 4; ++i)
    {
        remove_second_smallest(l);
        std::cout << "Size: " << l.size() << std::endl;
        l.print();
    }

    std::list<int> list;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(min, max);
    for (unsigned int i = 0; i < n; ++i)
    {
        list.push_back(dis(gen));
    }
    std::cout << "std::list:" << std::endl;
    for (Comparable auto elem : list)
    {
        std::cout << elem << " -> ";
    }
    std::cout << "nullptr" << std::endl;
    for (int i = 0; i < n + 1; ++i)
    {
        remove_second_smallest(list);
        for (Comparable auto elem : list)
        {
            std::cout << elem << " -> ";
        }
        std::cout << "nullptr" << std::endl;
    }
}
