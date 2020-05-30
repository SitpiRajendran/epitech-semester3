/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Image
*/

#include "Image.hpp"
namespace arcade
{
    Image::Image()
    {
    }

    Image::Image(std::string filename, arcade::Position beg, arcade::Position end)
    {
        _filename = filename;
        _beg = beg;
        _end = end;
    }

    Image::~Image()
    {
    }

    std::string Image::getFilename() const {
        return _filename;
    }

    arcade::Position Image::getPositionBeg() const {
        return _beg;
    }

    arcade::Position Image::getPositionEnd() const {
        return _end;
    }

    void Image::setFilename(std::string &filename) {
        _filename = filename;
    }

    void Image::setPositionBeg(arcade::Position &beg) {
        _beg = beg;
    }

    void Image::setPositionEnd(arcade::Position &end) {
        _end = end;
    }

} // namespace arcade