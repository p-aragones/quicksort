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
        int height = rand() % (800 - 1 + 1) + 1;
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
    _window.create(sf::VideoMode(800, 800), "Sort");
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

void Sort::sort()
{
}

bool Sort::isOpen()
{
    return (_window.isOpen());
}

int Sort::run()
{
    draw();
    while (isOpen()) {
        handleEvents();
        draw();
        sort();
    }
    return (0);
}