#include <iostream>
#include <list>
#include <initializer_list>
#include <random>

#include "ComparableConcept.hpp"
#include "remove_second_smallest.hpp"

/* Boriss Zalovs bz23005
 * === G22 =======================================
 * Izveidot divas programmas valodā C++, kas strādā ar vērtību virkni divos dažādos veidos:
 * 1) to realizējot kā vienvirziena saistīto sarakstu, izmantojot dinamiskas datu struktūras,
 * 2) izmantojot STL::list konteineru.
 *
 * Abās realizācijās ir jāizveido prasītā specifiskā vērtību virknes apstrādes funkcija un jānodemonstrē tā darbībā,
 * cita starpā parādot gan sākotnējās, gan rezultējošās vērtības.
 *
 * Abās programmās:
 *  a) jābūt iespējai ievadīt saraksta elementus (izveidot patvaļīgu sarakstu),
 *  b) jāpielieto uzrakstītā funkcija sarakstam,
 *  c) jāizdrukā saraksts pēc funkcijas darbības.
 *  d) beigās jāiznīcina saraksts - korekti jāatbrīvo izdalītā atmiņa(lietojot delete vai clear).
 *
 * Sīkākas prasības sk. Laboratorijas darbu noteikumos.
 * G22. Uzrakstīt funkciju, kas izmet no saraksta tā otro mazāko elementu, ja tāds eksistē.
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
