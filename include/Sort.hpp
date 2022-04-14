/*
** EPITECH PROJECT, 2022
** sort
** File description:
** sort
*/

#ifndef SORT_HPP_
#define SORT_HPP_

#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>
#include <vector>

class Sort {
    public:
        Sort();
        ~Sort();
        
        void initWindow();
        void draw();
        void swap(sf::RectangleShape *a, sf::RectangleShape *b);
        int partition(int start, int end);
        void changePositions();
        bool isSorted(); 
        void sort(int start, int end);
        int getValue(sf::RectangleShape shape);
        int handleEvents();
        bool isOpen();
        int run();

    protected:
    private:
        sf::RenderWindow _window;
        std::vector<sf::RectangleShape> _values;
};

#endif /* !SORT_HPP_ */
