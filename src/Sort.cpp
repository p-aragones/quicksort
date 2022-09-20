/*
** EPITECH PROJECT, 2022
** Sort
** File description:
** Sort
*/

#include "Sort.hpp"

Sort::Sort()
{
    initWindow();
    srand(time(NULL));

    int x = 0;
    for (int i = 0; i < 100; i++) {
        sf::RectangleShape rect;
        int height = rand() % (799 - 1 + 1) + 1;
        rect.setOrigin(sf::Vector2f(0, height));
        rect.setFillColor(sf::Color::White);
        rect.setOutlineColor(sf::Color::White);
        rect.setSize(sf::Vector2f(8, height));
        rect.setPosition(sf::Vector2f(x, 800));
        x += 8;
        _values.push_back(rect);
    }

}

Sort::~Sort()
{
}

void Sort::initWindow()
{
    _window.create(sf::VideoMode(792, 800), "Sort");
    _window.setFramerateLimit(144);
}

int Sort::handleEvents()
{
    sf::Event event;
    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            _window.close();
    }
    return (0);
}

void Sort::draw()
{
    _window.clear(sf::Color::Black);
    for (auto &rect : _values) {
        _window.draw(rect);
    }
    _window.display();
}

int Sort::getValue(sf::RectangleShape shape)
{
    sf::Vector2f size = shape.getSize();
    return (size.y);
}

void Sort::swap(sf::RectangleShape *a, sf::RectangleShape *b)
{
    sf::RectangleShape t = *a;
    *a = *b;
    *b = t;
    changePositions();
    draw();
}

int Sort::partition (int start, int end)
{
    int pivot = getValue(_values[end]); // pivot
    int i = (start - 1); // Index of smaller element and indicates the right position of pivot found so far
    
    for (int j = start; j <= end - 1; j++)
    {
        // If current element is smaller than the pivot
        if (getValue(_values[j]) < pivot)
        {
            i++; // increment index of smaller element
            swap(&_values[i], &_values[j]);
        }
    }
    swap(&_values[i + 1], &_values[end]);
    return (i + 1);
}

void Sort::sort(int start, int end)
{
    if (start <= end) {
        int pi = partition(start, end);
        sort(start, pi - 1);
        sort(pi + 1, end);
    }
}

bool Sort::isOpen()
{
    return (_window.isOpen());
}

void Sort::changePositions()
{
    for (int i = 0; i < _values.size(); i++) {
        _values[i].setPosition({i * 8, 800});
    }
}

bool Sort::isSorted()
{
    for (int i = 0; i < _values.size() - 1; i++) {
        if (getValue(_values[i]) > getValue(_values[i + 1])){ 
            return (false);
        }
    }
    return (true);
}

int Sort::run()
{
    draw();
    while (isOpen()) {
        handleEvents();
        if (!isSorted()) {
            sort(0, _values.size() - 1);
            changePositions();
            // for (auto &elem : _values) {
            //     std::cout << getValue(elem) << ", ";
            // }
            // std::cout << std::endl;
        }
    }
    return (0);
}